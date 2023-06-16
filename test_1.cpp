#include <object.h>
#include <aStarUtils.h>
#include <iostream>
#include <stdio.h>

namespace bobliew{

int run() {
// 一个难题在于，如果要使用A_star，就要画地图，但现在公司感觉没这个能力自动
// 生成地图，需要通过gis写一个脚本？ 或者后续结合pgSQL；
  std::vector<std::vector<int>> map = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    aStarUtils * ast = new aStarUtils();
    Point start(0, 0);
    Point end(4, 10);
    std::vector<Node*> path = ast->findPath(start, end, map);
    for (Node* node : path) {
        std::cout << "(" << node->getPoint().getX() << ", " << node->getPoint().getY() << ")" << std::endl;
    }
    delete ast;
    return 0;
}
}

int main(int argc, char* argv[]) {
    bobliew::run();
    return 0;
}
