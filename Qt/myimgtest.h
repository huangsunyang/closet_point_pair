#ifndef MYIMGTEST_H
#define MYIMGTEST_H
#include <vector>
#include <QWidget>
struct point {
    int num;
    double x;
    double y;
    point();
    point(double a, double b);
    point(double c, double a, double b);
    double distance(const point& b) const;
};
struct answer {
    double dis;
    point a, b;
    answer();
    answer(double a);
    answer(double c, point d, point e);
    bool operator<(const answer& b) const;
};

std::ostream &operator << (std::ostream &out, const point &p);
std::ostream &operator << (std::ostream &out, const answer &p);
answer closest_point(std::vector<point>& vec_x, std::vector<point>& vec_y, int start, int end);
answer closest_point(std::vector<point>& vec);

class MyImgTest : public QWidget
{
    //Q_OBJECT
    std::vector<point> vec;
    answer asr;
public:
    MyImgTest(QWidget* parent = 0);
    ~MyImgTest();
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseDoubleClickEvent(QMouseEvent *);
};

#endif // MYIMGTEST_H
