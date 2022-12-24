#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::cout;
using std::endl;

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

int part1(string filename) {
    return 0;
}

int part2(string filename) {
    return 0;
}

int main() {
    string input = "E:/Projects/AdventOfCode2022/day3/input.txt";
    string test = "E:/Projects/AdventOfCode2022/day3/test.txt";
    int part1_test = part1(test);
    cout << "Part1Test: " << part1_test << endl;
    
    int part1_count = part1(input);
    cout << "Part1: " << part1_count << endl;

    int part2_test = part2(test);
    cout << "Part2Test: " << part2_test << endl;

    int part2_count = part2(input);
    cout << "Part2: " << part2_count << endl;
    return 0;
}