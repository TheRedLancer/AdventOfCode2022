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
    std::ifstream inputFile;
    string line;

    inputFile.open(filename);

    int score = 0;
    int round_score = 0;

    if ( inputFile.is_open() ) {
        while ( inputFile && !inputFile.eof()) {
            getline(inputFile, line);
            if (line[0] == 'A') {
                if (line[2] == 'X') {
                    round_score += 1;
                    round_score += 3;
                } else if (line[2] == 'Y') {
                    round_score += 2;
                    round_score += 6;
                } else { //line[2] == 'Z'
                    round_score += 3;
                    round_score += 0;
                }
            } else if (line[0] == 'B') {
                if (line[2] == 'X') {
                    round_score += 1;
                    round_score += 0;
                } else if (line[2] == 'Y') {
                    round_score += 2;
                    round_score += 3;
                } else { //line[2] == 'Z'
                    round_score += 3;
                    round_score += 6;
                }
            } else { //line[0] == 'C'
                if (line[2] == 'X') {
                    round_score += 1;
                    round_score += 6;
                } else if (line[2] == 'Y') {
                    round_score += 2;
                    round_score += 0;
                } else { //line[2] == 'Z'
                    round_score += 3;
                    round_score += 3;
                }
            }  
            //cout << "round score: " << round_score << endl;
            score += round_score;
            round_score = 0;

        }
    } else {
        std::cout << "Fail to open file" << std::endl;
    }
    inputFile.close();
    return score;
}

int part2(string filename) {
        std::ifstream inputFile;
    string line;

    inputFile.open(filename);

    int score = 0;
    int round_score = 0;

    if ( inputFile.is_open() ) {
        while ( inputFile && !inputFile.eof()) {
            getline(inputFile, line);
            if (line[0] == 'A') {
                if (line[2] == 'X') {
                    // Rock beats Scissors
                    round_score += 0;
                    round_score += 3;
                } else if (line[2] == 'Y') {
                    // Rock ties Rock
                    round_score += 3;
                    round_score += 1;
                } else { //line[2] == 'Z'
                    // Rock loses Paper
                    round_score += 6;
                    round_score += 2;
                }
            } else if (line[0] == 'B') {
                if (line[2] == 'X') {
                    // Paper beats Rock
                    round_score += 0;
                    round_score += 1;
                } else if (line[2] == 'Y') {
                    // Paper ties Paper
                    round_score += 3;
                    round_score += 2;
                } else { //line[2] == 'Z'
                    // Paper loses Scissors
                    round_score += 6;
                    round_score += 3;
                }
            } else { //line[0] == 'C'
                if (line[2] == 'X') {
                    // Scissors beats Paper
                    round_score += 0;
                    round_score += 2;
                } else if (line[2] == 'Y') {
                    // Scissors ties Scissors
                    round_score += 3;
                    round_score += 3;
                } else { //line[2] == 'Z'
                    // Scissors loses Rock
                    round_score += 6;
                    round_score += 1;
                }
            }  
            //cout << "round score: " << round_score << endl;
            score += round_score;
            round_score = 0;

        }
    } else {
        std::cout << "Fail to open file" << std::endl;
    }
    inputFile.close();
    return score;
}

int main() {
    string input = "E:/Projects/AdventOfCode2022/day2/input.txt";
    string test = "E:/Projects/AdventOfCode2022/day2/test.txt";
    string all = "E:/Projects/AdventOfCode2022/day2/all_combos.txt";
    int part1_count = part1(input);
    cout << "Part1: " << part1_count << endl;

    int part2_test = part2(test);
    cout << "Part2Test: " << part2_test << endl;

    int part2_count = part2(input);
    cout << "Part2: " << part2_count << endl;
    return 0;
}