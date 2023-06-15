#include <./object.h>


namespace bobliew {
Node::Node(Point point, int g, int h, Node* parent)
    : g(g), 
      h(h), 
      parent(parent) {
        this->point = new Point(point)
    };
// 避免在后续代码中再用到相同位置已经被释放的内存

Node::~Node() {
    delete point;
    point = nullptr;
};


Point::Point(int x, int y) 
    : x(x), 
      y(y) {};

Point::Point(const Point& other) 
    : x(other.x), 
      y(other.y) {};
}
