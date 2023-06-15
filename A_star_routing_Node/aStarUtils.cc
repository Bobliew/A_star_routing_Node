#include <aStarUtils.h>

namespace bobliew {
int aStarUtils::distance(Point a, Point b) {
    return std::sqrt(std::pow(a.getX() - b.getX(), 2) + pow(a.getY() - b.getY(), 2));
}

bool aStarUtils::isInMap(Point point, int rows, int cols) {
    return point.getX() >= 0 && point.getX() < rows && point.getY() >= 0 && point.getY() < cols; 
}

bool isPassable(Point point, std::vector<std::vector<int>>& map) {
    return map[point.getX()][point.getY()] == 0;
}

std::vector<Node*> findPath(Point start, Point end,
    std::vector<std::vector<int>>& map) {
    std::vector<Node*> path;
    int rows = map.size();
    int cols = map[0].size();
    std::priority_queue<std::pair<int, Node*>, std::vector<std::pair<int, Node*>>, std::greater<std::pair<int, Node*>>> openSet; // open集合，按f值从小到大排序
    std::vector<std::vector<bool>> closedSet(rows, std::vector<bool>(cols, false)); // closed集合，记录已经访问过的节点
    Node* startNode = new Node(start, 0, aStarUtils::distance(start, end), nullptr);
    openSet.push(std::make_pair(startNode->g + startNode->h, startNode));
    while (!openSet.empty()) {
        Node* current = openSet.top().second;
        openSet.pop();
        if (current->point.getX() == end.getX() && current->point.getY() == end.getY()) { // 找到终点，回溯路径
            while (current != nullptr) {
                path.insert(path.begin(), current);
                current = current->parent;
            }
            break;
        }
        closedSet[current->point.getX()][current->point.getY()] = true;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                Point neighbor(current->point.getX() + i, current->point.getY() + j);
                if (isInMap(neighbor, rows, cols) && isPassable(neighbor, map) && !closedSet[neighbor.x][neighbor.y]) {
                    int g = current->g + distance(current->point, neighbor);
                    int h = distance(neighbor, end);
                    Node* neighborNode = new Node(neighbor, g, h, current);
                    openSet.push(make_pair(neighborNode->g + neighborNode->h, neighborNode));
                }
            }
        }
    }
    return path;
}


}
