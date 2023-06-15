#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

// 定义一个结构体表示一个坐标点
struct Point {
    int x;
    int y;
    Point(int x, int y) : x(x), y(y) {}
};

// 定义一个结构体表示一个节点
struct Node {
    Point point; // 当前节点对应的坐标点
    int g; // 从起点到当前节点的距离
    int h; // 当前节点到终点的估计距离
    Node* parent; // 父节点指针
    Node(Point point, int g, int h, Node* parent) : point(point), g(g), h(h), parent(parent) {}
};

// 定义一个函数计算两个坐标点之间的距离
int distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// 定义一个函数判断一个坐标点是否在地图内
bool isInMap(Point point, int rows, int cols) {
    return point.x >= 0 && point.x < rows && point.y >= 0 && point.y < cols;
}

// 定义一个函数判断一个坐标点是否可以通过
bool isPassable(Point point, vector<vector<int>>& map) {
    return map[point.x][point.y] == 0;
}

// 定义一个函数寻找起点到终点的最短路径，并返回路径上的节点列表
vector<Node*> findPath(Point start, Point end, vector<vector<int>>& map) {
    vector<Node*> path;
    int rows = map.size();
    int cols = map[0].size();
    priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>> openSet; // open集合，按f值从小到大排序
    vector<vector<bool>> closedSet(rows, vector<bool>(cols, false)); // closed集合，记录已经访问过的节点
    Node* startNode = new Node(start, 0, distance(start, end), nullptr);
    openSet.push(make_pair(startNode->g + startNode->h, startNode));
    while (!openSet.empty()) {
        Node* current = openSet.top().second;
        openSet.pop();
        if (current->point.x == end.x && current->point.y == end.y) { // 找到终点，回溯路径
            while (current != nullptr) {
                path.insert(path.begin(), current);
                current = current->parent;
            }
            break;
        }
        closedSet[current->point.x][current->point.y] = true;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                Point neighbor(current->point.x + i, current->point.y + j);
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

// 测试函数
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
