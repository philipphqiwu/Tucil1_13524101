#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QIcon>
#include "backend/queenscontroller.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/qt/qml/queenss/Resources/images/icons/logo.png"));

    QQmlApplicationEngine engine;

    static QueensController controller;
    qmlRegisterSingletonInstance("queenss", 1, 0, "QueensController", &controller);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("queenss", "Main");

    return app.exec();
}
