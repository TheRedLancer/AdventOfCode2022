#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::cout;
using std::endl;

vector<vector<int>> getInput(string fileName) {
    std::ifstream inputFile;
    string line;
    vector<vector<int>> elves = vector<vector<int>>();

    inputFile.open(fileName);
    int elf = 0;
    elves.push_back(vector<int>());

    if ( inputFile.is_open() ) {
        while ( inputFile ) {
            getline(inputFile, line);
            if (line.length() > 0) {
                elves[elf].push_back(stoi(line));
            } else {
                elves.push_back(vector<int>());
                elf++;
            }
        }
    } else {
        std::cout << "Fail to open file" << std::endl;
    }
    inputFile.close();
    return elves;
}

int part1(string filename) {
    int max_elf_food = 0;
    for (vector<int> elf: getInput(filename)) {
        int elf_food_total = 0;
        for (int food: elf) {
            elf_food_total += food;
        }
        if (elf_food_total > max_elf_food) {
            max_elf_food = elf_food_total;
        }
    }
    return max_elf_food;
}

int part2(string filename) {
    int first_elf = 0;
    int second_elf = 0;
    int third_elf = 0;
    for (vector<int> elf: getInput(filename)) {
        int elf_food_total = 0;
        for (int food: elf) {
            elf_food_total += food;
        }
        if (elf_food_total > first_elf) {
            third_elf = second_elf;
            second_elf = first_elf;
            first_elf = elf_food_total;
        } else if (elf_food_total > second_elf) {
            third_elf = second_elf;
            second_elf = elf_food_total;
        } else if (elf_food_total > third_elf) {
            third_elf = elf_food_total;
        }
    }
    return first_elf + second_elf + third_elf;
}

int main() {
    string input = "E:/Projects/AdventOfCode2022/day1/input.txt";
    string test = "E:/Projects/AdventOfCode2022/day1/test.txt";
    int part1_count = part1(input);
    cout << "Part1: " << part1_count << endl;

    int part2_count = part2(input);
    cout << "Part2: " << part2_count << endl;
    return 0;
}