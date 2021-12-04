#ifndef SUDOKU_H
#define SUDOKU_H

#include <cmath>
#include <cstdint>
#include <exception>
#include <fstream>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

#include "Colors.cpp"
#include "Colors.h"

class Sudoku{
    // size of all sudoku
    uint8_t size = 9;
    // size of smaller square inside of sudoku
    uint8_t size_of_box = 3;

    std::vector<std::vector<uint8_t>>  sudoku;

    // Sets to zero each cell
    void SetToZero();

    // check if it is possible to set guessed_number in specific position
    bool isPossible(uint8_t& pos_row, uint8_t& pos_col, short guessed_property);
    // check if specific rule wont be broken by placing guessed_num in this position
    bool is_possible_in_square(uint8_t& pos_row, uint8_t& pos_col, short guessed_property);
    bool is_possible_in_row(uint8_t& pos_row, uint8_t& pos_col, short guessed_property);
    bool is_possible_in_col(uint8_t& pos_row, uint8_t& pos_col, short guessed_property);

    // returns row and col of first zero cell
    std::pair<uint8_t, uint8_t> get_indexes_of_first_empty(); 
    // returns coordinates of sector in which cell is contained
    std::pair<uint8_t, uint8_t> get_cooridates_of_sector(uint8_t& pos);
    
    // check if number is "perfect square" (ex: 4, 9, 16, 25, 36, 81 ...)
    // needed for setting size of the boxes
    bool isPerfectSquare(unsigned short num);

    // check how many chars (except emptychar" ") are in line
    // needed for setting the size of sudoku, when reading it from file
    short AmountOfNotEmptyChars(std::string line);

    // recursive function that solves sudoku
    bool SolveSudoku();
public:
    // Constructors
    Sudoku(short size_in = 9);
    Sudoku(std::vector<std::vector<uint8_t>>& s);

    void Print();
    void Solve();
    // Check if sudoku is correct
    bool isValid();

    // Reading and Saving to file
    void ReadFromFile(std::string filename);
    void SaveToFile(std::string filename = "sudoku_output.txt");

    void SetSudoku(std::vector<std::vector<uint8_t>> new_sudoku);
    std::vector<std::vector<uint8_t>> GetSudoku()const;

    // change size of sudoku
    void SetSize(short new_size);

    friend std::istream& operator>>(std::istream& in, Sudoku& s);
    friend std::ostream& operator<<(std::ostream& out, Sudoku& s);
    friend bool operator==(const Sudoku& first, const Sudoku& second);
};

#endif