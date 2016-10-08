//
//  main.cpp
//  closest_point_pair
//
//  Created by huangsunyang on 10/6/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//
#ifndef CLOSEST
#define CLOSEST
#define DUG
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <float.h>
#include <random>
#include <ctime>
#include "myimgtest.h"
using namespace std;


point::point(){}
point::point(double a, double b): x(a), y(b){}
point::point(double c, double a, double b): num(c), x(a), y(b){}
double point::distance(const point& b) const {
    return sqrt((b.y - y) * (b.y - y) + (b.x - x) * (b.x - x));
}

ostream &operator << (ostream &out, const point &p) {
    out<<p.x<<" "<<p.y;
    return out;
}

answer::answer(){}
answer::answer(double a): dis(a){}
answer::answer(double c, point d, point e): dis(c), a(d), b(e){}
bool answer::operator<(const answer& b) const {
    return dis < b.dis;
}

ostream &operator << (ostream &out, const answer &p) {
    out<<p.a<<" "<<p.b<<endl<<p.dis;
    return out;
}

struct compare_point_x {
    bool operator()(const point& a, const point& b) {
        return a.x < b.x;
    }
};

struct compare_point_y {
    bool operator()(const point& a, const point& b) {
        return a.y < b.y;
    }
};

answer closest_point(vector<point>& vec_x, vector<point>& vec_y, int start, int end) {
    if (end == start) { return answer(DBL_MAX); }
    vector<point> near_mid;         //靠近分割线的点
    vector<point> y1, y2;
    int mid = (start + end) / 2;
    for (int i = 0; i < vec_y.size(); i++) {
        if (vec_y[i].num <= mid) {
            y1.push_back(vec_y[i]);
        } else y2.push_back(vec_y[i]);
    }
    double mid_x = (vec_x[mid].x + vec_x[mid + 1].x) / 2;
    answer d = answer(DBL_MAX), temp;
    temp = closest_point(vec_x, y1, start, mid);
    d = d < temp ? d : temp;
    temp = closest_point(vec_x, y2, mid + 1, end);
    d = d < temp ? d : temp;
    answer min = d;
    for (int i = 0; i < vec_y.size(); i++) {
        if (fabs(vec_y[i].x - mid_x) < d.dis) {
            near_mid.push_back(vec_y[i]);
        }
    }
    for (int i = 0; i < near_mid.size(); i++) {
        for (int j = i + 1; j < i + 6 && j < near_mid.size(); j++) {
            answer temp_dis(near_mid[i].distance(near_mid[j]), near_mid[i], near_mid[j]);
            min = temp_dis < min ? temp_dis : min;
        }
    }
    return min;
}

answer closest_point(vector<point>& vec) {
    sort(vec.begin(), vec.end(), compare_point_x());
    for (int i = 0; i < vec.size(); i++) {
        vec[i].num = i;
    }
    sort(vec.begin(), vec.end(), compare_point_y());
    vector<point> vec_y(vec);
    sort(vec.begin(), vec.end(), compare_point_x());
    return closest_point(vec, vec_y, 0, int(vec.size() - 1));
}

answer closest_point(istream& in) {
    vector<point> vec;
    double a, b;
    while (in>>a>>b) {
        vec.push_back(point(a, b));
    }
    return closest_point(vec);
}

answer closest_point(fstream& in) {
    vector<point> vec;
    double a, b;
    while (in>>a>>b) {
        vec.push_back(point(a, b));
    }
    return closest_point(vec);
}

void generate_points(int n, vector<point> &vec) {
    srand(unsigned(time(NULL)));
    for (int i = 0; i < n; i++) {
        vec.push_back(point(rand()/double(RAND_MAX  / n), rand()/double(RAND_MAX  / n)));
    }
}
#endif
