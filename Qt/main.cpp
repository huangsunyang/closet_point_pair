#include <QApplication>
#include "MyImgTest.h"
#include <QBoxLayout>
#include <QLayout>

int main(int argc,char *argv[])
{
    QApplication app(argc,argv);
    QWidget* widget = new MyImgTest();
    widget->show();
    return app.exec();
}
