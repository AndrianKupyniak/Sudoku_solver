#include <gtest/gtest.h>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "../Sudoku.cpp"

TEST(Sudoku_Constructor, Default_constructor){    
    Sudoku s;
    std::vector<std::vector<uint8_t>> vec(9, std::vector<uint8_t> (9, 0)) ;
    EXPECT_EQ(s.GetSudoku(), vec);
}

TEST(Sudoku_Constructor, SetSudoku){
    std::cout << "a";
    std::vector<std::vector<uint8_t>> vec{  {1, 0, 0,  0, 0, 0,  0, 0, 0},
                                            {0, 0, 0,  0, 0, 0,  0, 0, 0},
                                            {0, 0, 0,  0, 0, 0,  0, 0, 0},

                                            {0, 0, 0,  0, 0, 0,  0, 0, 0},
                                            {0, 0, 0,  0, 0, 0,  0, 0, 0},
                                            {0, 0, 0,  0, 0, 0,  0, 0, 0},

                                            {0, 0, 0,  0, 0, 0,  0, 0, 0},
                                            {0, 0, 0,  0, 0, 0,  0, 0, 0},
                                            {0, 0, 0,  0, 0, 0,  0, 0, 0}};
    Sudoku s;
    s.SetSudoku(vec);
    
    EXPECT_EQ(s.GetSudoku(), vec);
}

TEST(Sudoku_Valid_Check, Validation_in_column){
    std::vector<std::vector<uint8_t>> vec{{1, 0, 0,  0, 0, 0,  0, 0, 0},
                                        {1, 0, 0,  0, 0, 0,  0, 0, 0},
                                        {1, 0, 0,  0, 0, 0,  0, 0, 0},

                                        {1, 0, 0,  0, 0, 0,  0, 0, 0},
                                        {1, 0, 0,  0, 0, 0,  0, 0, 0},
                                        {1, 0, 0,  0, 0, 0,  0, 0, 0},

                                        {0, 0, 0,  0, 0, 0,  0, 0, 0},
                                        {0, 0, 0,  0, 0, 0,  0, 0, 0},
                                        {0, 0, 0,  0, 0, 0,  0, 0, 0}};
    Sudoku s(vec);
    EXPECT_EQ(s.isValid(), false);
}

TEST(Sudoku_Valid_Check, Validation_in_box){
    std::vector<std::vector<uint8_t>> vec{{1, 0, 0,  0, 0, 0,  0, 0, 0},
                                        {0, 0, 0,  0, 0, 0,  0, 0, 0},
                                        {0, 0, 1,  0, 0, 0,  0, 0, 0},

                                        {0, 0, 0,  0, 0, 0,  0, 0, 0},
                                        {0, 0, 0,  0, 0, 0,  0, 0, 0},
                                        {0, 0, 0,  0, 0, 0,  0, 0, 0},

                                        {0, 0, 0,  0, 0, 0,  0, 0, 0},
                                        {0, 0, 0,  0, 0, 0,  0, 0, 0},
                                        {0, 0, 0,  0, 0, 0,  0, 0, 0}};
    Sudoku s(vec);
    EXPECT_EQ(s.isValid(), false);
}

TEST(Sudoku_Valid_Check, Validation_in_row){
    std::vector<std::vector<uint8_t>> vec{{0, 0, 0,  0, 0, 0,  0, 0, 0},
                                        {0, 0, 0,  0, 0, 0,  0, 0, 0},
                                        {0, 0, 0,  0, 0, 0,  0, 0, 0},

                                        {0, 0, 0,  0, 0, 0,  0, 0, 0},
                                        {0, 0, 0,  0, 0, 0,  0, 0, 0},
                                        {0, 0, 0,  0, 0, 0,  0, 0, 0},

                                        {0, 0, 0,  0, 0, 0,  0, 0, 0},
                                        {0, 0, 0,  0, 0, 0,  0, 0, 0},
                                        {1, 0, 0,  1, 0, 0,  1, 0, 1}};
    Sudoku s(vec);
    EXPECT_EQ(s.isValid(), false);
}

TEST(Sudoku_Valid_Check, Valid){
    std::vector<std::vector<uint8_t>> vec  {{1, 2, 3,  4, 5, 6,  7, 8, 9},
                                            {4, 5, 6,  7, 8, 9,  1, 2, 3},
                                            {7, 8, 9,  1, 2, 3,  4, 5, 6},

                                            {2, 3, 1,  9, 7, 8,  6, 4, 5},
                                            {6, 4, 5,  2, 3, 1,  9, 7, 8},
                                            {9, 7, 8,  6, 4, 5,  2, 3, 1},

                                            {3, 1, 2,  8, 9, 7,  5, 6, 4},
                                            {5, 6, 4,  3, 1, 2,  8, 9, 7},
                                            {8, 9, 7,  5, 6, 4,  3, 1, 2}};
    Sudoku s(vec);
    EXPECT_EQ(s.isValid(), true);
}
TEST(Sudoku_Equality_Check, Equality_check){
    std::vector<std::vector<uint8_t>> vec{{0, 0, 0,  0, 0, 0,  0, 0, 0},
                                        {0, 0, 0,  0, 0, 0,  0, 0, 0},
                                        {0, 0, 0,  0, 0, 0,  0, 0, 0},

                                        {0, 0, 0,  0, 0, 0,  0, 0, 0},
                                        {0, 5, 0,  0, 2, 0,  3, 4, 0},
                                        {0, 0, 0,  0, 0, 0,  0, 0, 0},

                                        {0, 0, 0,  0, 0, 0,  0, 0, 0},
                                        {0, 0, 0,  0, 0, 0,  0, 0, 0},
                                        {1, 0, 0,  1, 0, 0,  1, 0, 1}};
    Sudoku s1(vec);

    Sudoku s2(vec);
    EXPECT_EQ(s1, s2);
}

TEST(Sudoku_Solving_Check, Solve){
    std::vector<std::vector<uint8_t>> vec{  {0, 0, 2,  0, 0, 0,  0, 0, 0},
                                            {0, 0, 0,  0, 0, 0,  0, 0, 0},
                                            {0, 0, 0,  0, 0, 0,  0, 0, 0},

                                            {0, 0, 0,  0, 0, 0,  0, 0, 0},
                                            {0, 2, 0,  0, 1, 0,  9, 8, 0},
                                            {0, 0, 0,  0, 0, 0,  0, 0, 0},

                                            {0, 0, 0,  0, 0, 0,  0, 0, 0},
                                            {0, 0, 0,  0, 0, 0,  0, 0, 0},
                                            {1, 0, 0,  4, 0, 0,  5, 0, 6}};
    Sudoku s1(vec);
    s1.Solve();
    EXPECT_EQ(s1.isValid(), true);
}

TEST(Sudoku_Solving_Check, Solve_exception_if_invalid){
    std::vector<std::vector<uint8_t>> vec{  {0, 2, 2,  0, 0, 0,  0, 0, 0},
                                            {0, 2, 0,  0, 0, 0,  0, 0, 0},
                                            {0, 0, 0,  0, 0, 0,  0, 0, 0},

                                            {0, 0, 0,  0, 0, 0,  0, 0, 0},
                                            {0, 2, 0,  0, 1, 0,  9, 8, 0},
                                            {0, 2, 0,  0, 0, 0,  0, 0, 0},

                                            {0, 0, 0,  0, 0, 0,  0, 0, 0},
                                            {0, 0, 0,  0, 0, 0,  0, 0, 0},
                                            {1, 0, 0,  4, 0, 0,  5, 0, 6}};
    Sudoku s1(vec);
    EXPECT_THROW(s1.Solve(), std::logic_error);
}

TEST(Sudoku_Solving_Check, Size_change_to_smaller){
    std::vector<std::vector<uint8_t>> vec{  {1, 2, 2,  3, 0, 0,  0, 0, 0},
                                            {1, 2, 1,  3, 0, 0,  0, 0, 0},
                                            {0, 0, 0,  4, 0, 0,  0, 0, 0},

                                            {7, 6, 6,  5, 0, 0,  0, 0, 0},
                                            {0, 2, 0,  0, 1, 0,  9, 8, 0},
                                            {0, 2, 0,  0, 0, 0,  0, 0, 0},

                                            {0, 0, 0,  0, 0, 0,  0, 0, 0},
                                            {0, 0, 0,  0, 0, 0,  0, 0, 0},
                                            {1, 0, 0,  4, 0, 0,  5, 0, 6}};
    Sudoku s1(vec);
    s1.SetSize(4);
    std::vector<std::vector<uint8_t>> vec2{  {1, 2, 2, 3},
                                            {1, 2, 1, 3},
                                            {0, 0, 0, 4},
                                            {7, 6, 6, 5}};
    EXPECT_EQ(s1.GetSudoku(), vec2);
}

TEST(Sudoku_Solving_Check, Size_change_to_bigger){
    std::vector<std::vector<uint8_t>> vec1{ {1, 2, 2, 3},
                                            {1, 2, 1, 3},
                                            {0, 0, 0, 4},
                                            {7, 6, 6, 5}};   

    std::vector<std::vector<uint8_t>> vec2{  {1, 2, 2,  3, 0, 0,  0, 0, 0},
                                            {1, 2, 1,  3, 0, 0,  0, 0, 0},
                                            {0, 0, 0,  4, 0, 0,  0, 0, 0},

                                            {7, 6, 6,  5, 0, 0,  0, 0, 0},
                                            {0, 0, 0,  0, 0, 0,  0, 0, 0},
                                            {0, 0, 0,  0, 0, 0,  0, 0, 0},

                                            {0, 0, 0,  0, 0, 0,  0, 0, 0},
                                            {0, 0, 0,  0, 0, 0,  0, 0, 0},
                                            {0, 0, 0,  0, 0, 0,  0, 0, 0}};
    Sudoku s1(vec1);
    s1.SetSize(9);

    EXPECT_EQ(s1.GetSudoku(), vec2);
}

TEST(Read_From_File, Error_file){
    Sudoku s1;
    EXPECT_THROW(s1.ReadFromFile("input/error.txt"), std::logic_error);
}

TEST(Read_From_File, 9_size_file){
    std::vector<std::vector<uint8_t>> vec{  {0, 0, 2,  0, 0, 0,  0, 0, 0},
                                            {0, 0, 0,  0, 0, 0,  0, 0, 0},
                                            {0, 0, 0,  0, 0, 0,  0, 0, 0},

                                            {0, 0, 0,  0, 0, 0,  0, 0, 0},
                                            {0, 2, 0,  0, 1, 0,  9, 8, 0},
                                            {0, 0, 0,  0, 0, 0,  0, 0, 0},

                                            {0, 0, 0,  0, 0, 0,  0, 0, 0},
                                            {0, 0, 0,  0, 0, 0,  0, 0, 0},
                                            {1, 0, 0,  4, 0, 0,  5, 0, 6}};
    Sudoku s1;
    s1.ReadFromFile("input/9_sudoku.txt");

    EXPECT_EQ(s1.GetSudoku(), vec);
}

TEST(Read_From_File, 4_size_file){
    std::vector<std::vector<uint8_t>> vec{  {1, 2,   3, 4},
                                            {0, 0,   0,  0},

                                            {0, 0,   0,  0},
                                            {0, 0,   0,  0}};
    Sudoku s1;
    s1.ReadFromFile("input/4_sudoku.txt");

    EXPECT_EQ(s1.GetSudoku(), vec);
}
TEST(Read_From_File, 16_size_file){
    std::vector<std::vector<uint8_t>> vec{  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
                                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                                            {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3}};
    Sudoku s1;
    s1.ReadFromFile("input/16_sudoku.txt");

    EXPECT_EQ(s1.GetSudoku(), vec);
}

int main(){
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}