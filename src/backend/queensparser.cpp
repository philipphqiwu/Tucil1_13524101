#include "queensparser.h"
#include <QFile>
#include <QTextStream>
#include <QSet>

static const QVector<QColor> s_palette = {
    QColor(0xE6, 0x19, 0x4B), QColor(0x3C, 0xB4, 0x4B), QColor(0xFF, 0xE1, 0x19), QColor(0x43, 0x63, 0xD8),
    QColor(0xF5, 0x82, 0x31), QColor(0x91, 0x1E, 0xB4), QColor(0x42, 0xD4, 0xF4), QColor(0xF0, 0x32, 0xE6),
    QColor(0xBF, 0xEF, 0x45), QColor(0xFA, 0xBE, 0xD4), QColor(0x46, 0x99, 0x90), QColor(0xDC, 0xBE, 0xFF),
    QColor(0x9A, 0x63, 0x24), QColor(0xFF, 0xFA, 0xC8), QColor(0x80, 0x00, 0x00), QColor(0xAA, 0xFF, 0xC3),
};

QColor QueensParser::colorForId(int colorId) {
    return s_palette[colorId % s_palette.size()];
}

ParseResult QueensParser::fromTxtFile(const QString &filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return { false, "Cannot open file: " + filePath, 0, {}, {}};
    }
    QTextStream in(&file);
    QString content = in.readAll();
    file.close();

    QStringList lines = content.trimmed().split('\n', Qt::SkipEmptyParts);
    return parseTxt(lines);
}

ParseResult QueensParser::parseTxt(const QStringList &lines) {
    ParseResult result;
    result.success = false;
    result.size = lines.size();

    if (result.size == 0) {
        result.error = "Empty input";
        return result;
    }

    if (result.size > 26) {
        result.error = QString("Board size %1 exceeds maximum of 26 (A-Z)").arg(result.size);
        return result;
    }

    result.colors.resize(result.size);
    QSet<QChar> uniqueChars;
    int nextColorIdx = 0;
    QMap<QChar, int> charColorIdx;

    for (int r = 0; r < result.size; r++) {
        QString line = lines[r].trimmed();

        if (line.size() != result.size) {
            result.error = QString("Row %1: expected %2 characters, got %3")
                               .arg(r + 1).arg(result.size).arg(line.size());
            return result;
        }

        result.colors[r].resize(result.size);
        for (int c = 0; c < result.size; c++) {
            QChar ch = line[c];
            result.colors[r][c] = ch;

            if (!uniqueChars.contains(ch)) {
                uniqueChars.insert(ch);
                charColorIdx[ch] = nextColorIdx++;
            }
        }
    }

    if (uniqueChars.size() != result.size) {
        result.error = QString("Expected %1 colors, found %2")
                           .arg(result.size).arg(uniqueChars.size());
        return result;
    }

    for (auto it = charColorIdx.constBegin(); it != charColorIdx.constEnd(); ++it) {
        result.colorMap[it.key()] = colorForId(it.value());
    }

    result.success = true;
    return result;
}
