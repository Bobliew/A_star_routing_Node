#ifndef __BOBLIEW_ASTARUTILS_H__
#define __BOBLIEW_ASTARUTILS_H__


#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <object.h>

namespace bobliew {

class aStarUtils {
public: 
    aStarUtils() {}
    int distance(Point a, Point b);
    bool isInMap(Point point, int rows, int cols);
    bool isPassable(Point point, std::vector<std::vector<int>>& map);
    std::vector<Node*> findPath(Point start, Point end, std::vector<std::vector<int>>& map);
};
}
#endif
