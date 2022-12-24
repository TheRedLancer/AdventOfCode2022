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
        while ( inputFile && !inputFile.eof()) {
            getline(inputFile, line);
            charMap.push_back(line);
        }
    } else {
        std::cout << "Fail to open file" << std::endl;
    }
    inputFile.close();
    return charMap;
}

int getPriority(char c) {
    if (islower(c)) {
        return (int)c - 96;
    } else {
        return (int)c - 64 + 26;
    }
}

int part1(string filename) {
    vector<string> lines = getInput(filename);
    bool letters[53];
    int prio_sum = 0;

    for (string backpack: lines) {
        for (int i = 0; i < 53; i++) {letters[i] = false;}

        // first compartment
        for (int i = 0; i < backpack.size() / 2; i++) {
            letters[getPriority(backpack[i])] = true;
        }
        // second compartment
        for (int i = backpack.size() / 2; i < backpack.size(); i++) {
            if (letters[getPriority(backpack[i])]) {
                //cout << "found_letter: " << backpack[i] << endl; 
                prio_sum += getPriority(backpack[i]);
                break;
            }
        }
    }
    return prio_sum;
}

int part2(string filename) {
    vector<string> lines = getInput(filename);
    bool first[53];
    bool first_and_second[53];
    int prio_sum = 0;

    for (int i = 0; i < lines.size() / 3; i++) {
        for (int i = 0; i < 53; i++) {first[i] = false;};
        for (int i = 0; i < 53; i++) {first_and_second[i] = false;};
        // first elf
        for (int j = 0; j < lines[3 * i + 0].size(); j++) {
            first[getPriority(lines[3 * i + 0][j])] = true;
        }
        // second elf
        for (int k = 0; k < lines[3 * i + 1].size(); k++) {
            if (first[getPriority(lines[3 * i + 1][k])]) {
                //cout << "found_letter: " << backpack[i] << endl;
                first_and_second[getPriority(lines[3 * i + 1][k])] = true;
            }
        }
        // third elf
        for (int l = 0; l < lines[3 * i + 2].size(); l++) {
            if (first_and_second[getPriority(lines[3 * i + 2][l])]) {
                //cout << "found_letter: " << lines[3 * i + 2][l] << endl; 
                prio_sum += getPriority(lines[3 * i + 2][l]);
                break;
            }
        }
    }
    
    return prio_sum;
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