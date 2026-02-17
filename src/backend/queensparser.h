#ifndef QUEENSPARSER_H
#define QUEENSPARSER_H

#include <QString>
#include <QStringList>
#include <QVector>
#include <QMap>
#include <QColor>

struct ParseResult {
    bool success;
    QString error;
    int size;
    QVector<QVector<QChar>> colors;
    QMap<QChar, QColor> colorMap;
};

class QueensParser {
public:
    static ParseResult fromTxtFile(const QString &filePath);

private:
    static ParseResult parseTxt(const QStringList &lines);
    static QColor colorForId(int colorId);
};
#endif // QUEENSPARSER_H
