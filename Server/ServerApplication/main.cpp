#include <QCoreApplication>
#include <serverapp.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ServerApp* server = new ServerApp();


    return a.exec();
}
