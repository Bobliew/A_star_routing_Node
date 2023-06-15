
#include <object.h>
#include <iostream>


int main() {
// 一个难题在于，如果要使用A_star，就要画地图，但现在公司感觉没这个能力自动
// 生成地图；
    vector<vector<int>> map = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };
    Point start(0, 0);
    Point end(4, 4);
    vector<Node*> path = findPath(start, end, map);
    for (Node* node : path) {
        cout << "(" << node->point.x << ", " << node->point.y << ")" << endl;
    }
    return 0;
}
