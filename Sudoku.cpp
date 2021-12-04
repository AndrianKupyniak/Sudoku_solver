#include "Sudoku.h"
#include <cstdint>
#include <string>
#include <utility>


bool Sudoku::isValid(){
    for(uint8_t i = 0; i < size; ++i){
        for(uint8_t j = 0; j < size; ++j){
            if((short)sudoku[i][j] != 0){
                if(!isPossible(i, j, (short)sudoku[i][j]) || sudoku[i][j] > size){  
                    return false;
                }
            }
        }
    }
    return true;
}

void Sudoku::SetToZero(){
    for(uint8_t i = 0; i < sudoku.size(); ++i){
        for(uint8_t j = 0; j < sudoku[i].size(); ++j){
            sudoku[i][j] = 0;
        }
    }
}

bool Sudoku::is_possible_in_square(uint8_t& pos_row, uint8_t& pos_col, short guessed_property){
    auto row = get_cooridates_of_sector(pos_row); 
    auto col = get_cooridates_of_sector(pos_col); 
    for(uint8_t i = row.first; i < row.second; ++i){
        for(uint8_t j = col.first; j < col.second; ++j){
            if(sudoku[i][j] == guessed_property && i != pos_row && j != pos_col){
                return false;
            }
        }
    }
    return true;
}

bool Sudoku::is_possible_in_row(uint8_t& pos_row, uint8_t& pos_col, short guessed_property){
    for(uint8_t i = 0; i<size; i++){
        if(sudoku[pos_row][i] == guessed_property && i != pos_col){
            return false;
        }
    }
    return true;
}

bool Sudoku::is_possible_in_col(uint8_t& pos_row, uint8_t& pos_col, short guessed_property){
    for(uint8_t i = 0; i < size; i++){
        if(sudoku[i][pos_col] == guessed_property && i != pos_row){
            return false;
        }
    }
    return true;
}

std::pair<uint8_t, uint8_t> Sudoku::get_indexes_of_first_empty(){
    for (uint8_t row = 0; row < size; row++){
        for (uint8_t col = 0; col < size; col++){
            if (sudoku[row][col] == 0){
                return std::make_pair(row, col);
            }                       
        }
    }
    return std::make_pair(size, size);
}

std::pair<uint8_t, uint8_t> Sudoku::get_cooridates_of_sector(uint8_t& pos){
    uint8_t start_of_sector = (pos/size_of_box)*size_of_box;
    uint8_t end_of_sector = (pos/size_of_box)*size_of_box + size_of_box;
    return std::make_pair(start_of_sector, end_of_sector);
}

bool Sudoku::isPerfectSquare(unsigned short num){
    if (num > 3) {
        short sr = sqrt(num);
        return (sr * sr == num);
    }
    return false;
}

short Sudoku::AmountOfNotEmptyChars(std::string line){
    return line.size() - count(line.begin(), line.end(), ' ');
}

Sudoku::Sudoku(short size_in){
    SetSize(size_in);
    sudoku = std::vector<std::vector<uint8_t>>(size, std::vector<uint8_t> (size, 0));
};

Sudoku::Sudoku(std::vector<std::vector<uint8_t>>& s):sudoku(s){
    if(isPerfectSquare(s.size())){
        size = s.size();
        size_of_box = sqrt(size);
    }else{
        throw std::invalid_argument("Cant set that vector as sudoku. Size must to be a perfect square!");
    }
};

void Sudoku::Print(){
    for(uint8_t i = 0; i < size; ++i){
        for(uint8_t j = 0; j < size; ++j){
            colors::SetColorForNumber(sudoku[i][j]);

            // if numbers in sudoku can be bigger than 10 
            // set 0 before single char numbers
            if(size >= 10 && sudoku[i][j] < 10){
                std::cout << "0";
            }
            std::cout << (short)sudoku[i][j];
            
            colors::ResetColor();
            std::cout << "  ";
            if(j % size_of_box == size_of_box - 1 && j != size - 1){
                std::cout << "\t|\t";
            }
        }
        std::cout << "\n";
        if(i % size_of_box == size_of_box - 1 && i != size - 1){
            std::string line(size * 6, '-');
            std::cout << line << "\n";
        }
    }
}

bool Sudoku::isPossible(uint8_t& pos_row, uint8_t& pos_col, short guessed_property){
    if(!is_possible_in_col(pos_row, pos_col, guessed_property)){
        return false;
    }
    if(!is_possible_in_row(pos_row, pos_col, guessed_property)){
        return false;
    }
    if(!is_possible_in_square(pos_row, pos_col, guessed_property)){
        return false;
    } 
    return true;
}
void Sudoku::Solve(){
    if(isValid()){
        if(SolveSudoku() == false){
            throw std::logic_error("Something went wrong, while solving sudoku");
        }
    }else{
        throw std::logic_error("cant solve invalid sudoku(");
    }
}

void Sudoku::ReadFromFile(std::string filename){
    std::fstream file(filename);
    std::string line;
    getline(file, line);
    SetSize(AmountOfNotEmptyChars(line));
    file.clear();
    file.seekg(0);
    file >> *this;
    file.close();
}   

bool Sudoku::SolveSudoku(){
    std::pair<uint8_t, uint8_t> row_and_col = get_indexes_of_first_empty();
    uint8_t row = row_and_col.first;
    uint8_t col = row_and_col.second;
    if(col == size && row == size){
        return true; 
    }

    for(short num = 1; num <= size; ++num){
        if(isPossible(row, col, num)){
            sudoku[row][col] = num;
            if(SolveSudoku()){
                return true;
            }
            sudoku[row][col] = 0;
        }
    }
    return false; 
}

void Sudoku::SetSudoku(std::vector<std::vector<uint8_t>> new_sudoku){
    SetSize(new_sudoku.size());
    sudoku = new_sudoku;
}

std::vector<std::vector<uint8_t>> Sudoku::GetSudoku()const{
    return sudoku;
}

std::istream& operator>>(std::istream& in, Sudoku& s){
    s.SetToZero();
    for(uint8_t i=0; i < s.size; ++i){
        for(uint8_t j=0; j < s.size; ++j){
            short temp_num;
            in >> temp_num;
            if(temp_num != 0){
                if(s.isPossible(i, j, temp_num)){
                    s.sudoku[i][j] = (uint8_t) temp_num;
                }else{
                    throw std::invalid_argument("Invalid sudoku");
                }
            }
        }
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, Sudoku& s){
    for(uint8_t i = 0; i < s.size; ++i){
        for(uint8_t j = 0; j < s.size; ++j){

            // if numbers in sudoku can be bigger than 10 
            // set 0 before single char numbers
            if(s.size >= 10 && s.sudoku[i][j] < 10){
                out << "0";
            }
            out << (short)s.sudoku[i][j];
            
            out << "  ";
            if(j % s.size_of_box == s.size_of_box - 1 && j != s.size - 1){
                out << "\t|\t";
            }
        }
        out << "\n";
        if(i % s.size_of_box == s.size_of_box - 1 && i != s.size - 1){
            std::string line(s.size * 6, '-');
            out << line << "\n";
        }
    }    
    out << "\n";
    return out;
}

bool operator==(const Sudoku& first, const Sudoku& second){
    if(first.GetSudoku() != first.GetSudoku()){
        return false;
    }
    return true;
}

void Sudoku::SaveToFile(std::string filename){
    std::ofstream out(filename);
    out << *this;
    out.close();
}

void Sudoku::SetSize(short new_size){
    if(isPerfectSquare(new_size)){
        size = new_size;
        size_of_box = sqrt(size);
    }else{
        throw std::invalid_argument("size needs to be a perfect square!");
    }
    auto new_sudoku = std::vector<std::vector<uint8_t>>(size, std::vector<uint8_t> (size, 0));
    for(uint8_t i = 0; i < size; ++i){
        for(uint8_t j = 0; j < size; ++j){
            if(i < sudoku.size() && j < sudoku.size()){
                new_sudoku[i][j] = sudoku[i][j];
            }else{
                new_sudoku[i][j] = 0;
            }
        }
    }
    sudoku = new_sudoku;
}