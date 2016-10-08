#ifndef MTIMGTEST
#define MTIMGTEST
#include "MyImgTest.h"
#include <QPainter>
#include <QMouseEvent>
//#include <QPointF>
//#include <QLineF>

MyImgTest::MyImgTest(QWidget* parent) : QWidget(parent)
{
    setFixedSize(1200,800); //固定大小
    setWindowTitle("Closest Points Pair");
}

MyImgTest::~MyImgTest() {}

void MyImgTest::paintEvent(QPaintEvent *)
{
    // 画一条直线
    QPainter painter(this);             // 创建QPainter一个对象
    painter.setPen(QPen(Qt::black, 8, Qt::DashLine, Qt::RoundCap));
    for(int i = 0; i < vec.size(); i++) {
        painter.drawPoint(vec[i].x, vec[i].y);
    }
    painter.setPen(QPen(Qt::red, 4, Qt::DashLine, Qt::RoundCap));
    painter.drawLine(asr.a.x, asr.a.y, asr.b.x, asr.b.y);
}
void MyImgTest::mousePressEvent(QMouseEvent * event) {
    vec.push_back(point(event->pos().x(), event->pos().y()));
    asr = closest_point(vec);
    update();
}
void MyImgTest::mouseDoubleClickEvent(QMouseEvent *event) {

}

#endif
