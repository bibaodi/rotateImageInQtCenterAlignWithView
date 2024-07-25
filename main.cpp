#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include"imageitem.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

     qmlRegisterType<ImageItem>("com.mycompany.Eton", 1, 0, "EtonImage");
    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/240725-image-rotate/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
