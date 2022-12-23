#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using std::vector;
using std::string;
using std::pair;
using std::queue;
using std::map;
using std::cout;
using std::endl;

typedef pair<int, int> point; // (y, x);
std::ostream & operator<<(std::ostream & Str, point const & p) { 
  // print something from v to str, e.g: Str << v.getX();
  return Str << "(" << p.first << "," << p.second << ")";
}

vector<string> getInput(string fileName);
void printMap(vector<string> charMap);
point getStart(vector<string> charMap);
point findChar(vector<string> charMap, char c);
vector<point> getNeighbors(point node, vector<string> charMap);


int main(int argc, char** argv) {
    vector<string> charMap = getInput("E:/Projects/AdventOfCode2022/day12/input.txt");
    //printMap(charMap);
    const int HEIGHT = charMap.size();
    const int WIDTH = charMap[0].size();
    queue<point> Q = queue<point>();
    map<point, bool> visited = map<point, bool>();
    map<point, point> parent = map<point, point>();

    point start = findChar(charMap, 'S');
    charMap[start.first][start.second] = 'a';
    point end = findChar(charMap, 'E');
    charMap[end.first][end.second] = 'z';

    cout << "Start: " << start << endl << "End: " << end << endl;

    parent[start] = point(-1, -1);
    visited[start] = true;
    Q.push(start);
    while (!Q.empty()) {
        point node = Q.front(); Q.pop();
        vector<point> possiblePoints = getNeighbors(node, charMap);
        for (const point& neighbor: possiblePoints) {
            // neighbor.height <= this.height + 1;
            if (!visited[neighbor] && ((int)charMap[neighbor.first][neighbor.second] <= (int)charMap[node.first][node.second] + 1)) {
                visited[neighbor] = true;
                parent[neighbor] = node;
                Q.push(neighbor);
            }
        }
    }
    int count = 0;
    point curr_node = end;
    while (curr_node != start) {
        //cout << curr_node << " --> ";
        curr_node = parent[curr_node];
        count++;
    }
    cout << (parent[{20, 1}] == point(20, 0)) << endl;
    cout << endl << "Total Count: " << count << endl;
    return 0;
}

vector<point> getNeighbors(point node, vector<string> charMap) {
    vector<point> neighbors = vector<point>();
    const int HEIGHT = charMap.size();
    const int WIDTH = charMap[0].size();
    //UP (y-1 >= 0, x)
    if (node.first - 1 >= 0) {
        neighbors.push_back(point(node.first - 1, node.second));
    }
    //LEFT (y, x-1 >= 0)
    if (node.second - 1 >= 0) {
        neighbors.push_back(point(node.first, node.second - 1));
    }
    //DOWN (y+1 < HEIGHT, x)
    if (node.first + 1 < HEIGHT) {
        neighbors.push_back(point(node.first + 1, node.second));
    }
    //RIGHT (y, x+1 < WIDTH)
    if (node.second + 1 < WIDTH) {
        neighbors.push_back(point(node.first, node.second + 1));
    }
    return neighbors;
}

point findChar(vector<string> charMap, char seek) {
    for (int i = 0; i < charMap.size(); i++) {
        for (int c = 0; c < charMap[i].size(); c++) {
            if (charMap[i][c] == seek) {
                return point(i, c);
            }
        }
    }
    return point(-1, -1);
}

vector<string> getInput(string fileName) {
    std::ifstream inputFile;
    string line;
    vector<string> charMap = vector<string>();

    inputFile.open(fileName);

    if ( inputFile.is_open() ) {
        while ( inputFile ) {
            getline(inputFile, line);
            charMap.push_back(line);
        }
    } else {
        std::cout << "Fail to open file" << std::endl;
    }
    inputFile.close();
    return charMap;
}

void printMap(vector<string> charMap) {
    for (const auto line: charMap) {
        std::cout << line << std::endl;
    }
}