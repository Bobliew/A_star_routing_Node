#ifndef __BOBLIEW_OBJECT_H__
#define __BOBLIEW_OBJECT_H__


#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

namespace bobliew {


class Point {
public:
    Point(int x, int y);
    // 接受 Point 对象作为参数的构造函数
    Point(const Point& other);
    int getX() const { return x;}
    int getY() const { return y;}
private:
    int x;
    int y;
};

class Node {
public:
    Node(Point point, int g, int h, Node* parent);
    ~Node();
    
private:
    int g;
    int h;
    Point point;
    Node * parent;
};
}

#endif

