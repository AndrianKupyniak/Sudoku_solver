
#include <cstdint>
#include <exception>
#include <fstream>
#include <iostream>
#include <string>
#include <string.h>
#include <stdexcept>

#include "Colors.h"
#include "Sudoku.cpp"

// if we can use filesystem, use filesystem functions
// but if not use dirent.h instead

#if __cplusplus >= 201703L
    #include <filesystem>
#else
    #include <dirent.h>
#endif

// only acceptable file expresion for files in folders
const std::string input_file_extension = ".txt";

// --------------+++ Functions for handling with files +++--------------
void NoArgumentsError();
void SolveSingleSudoku(std::string& input_file, std::string& output_file);
std::vector<std::string> GetAllFilesFromPath(std::string path);
void SolveMultipleSudoku(std::vector<std::string>& input_files, std::string& output_path);
// ---------------------------------------------------------------------

int main(int argc, char *argv[]){
    if(argc == 1){
        NoArgumentsError();
        return -1;
    }    

    // if "-all" was used, solve all .txt files in folder, else solve single sudoku from file
    if(argc > 2 && strcmp(argv[argc - 1], "-all") == 0){
        std::vector<std::string> input_files = GetAllFilesFromPath(argv[1]);
        std::string output_path = argv[2];
        SolveMultipleSudoku(input_files, output_path);
    }else{ 
        std::string input_file  = argv[1];
        std::string output_file = "sudoku_output.txt";

        if(argc > 2){
            output_file = argv[2];
        }
        SolveSingleSudoku(input_file, output_file);
    }

    return 0;
}




// --------------+++ Functions for handling with files +++--------------
void NoArgumentsError(){
    colors::SetErrorColor();
    std::cout << "error: Wrong input file/folder name" << std::endl;
    std::cout << "Usage: " << std::endl;
    std::cout << "For single sudoku:    \t./sudoku_solver input_file.txt output_file.txt\n";
    std::cout << "For multiple sudokus: \t./sudoku_solver input_path output_path -all\n";
    colors::ResetColor();
}

void SolveSingleSudoku(std::string& input_file, std::string& output_file){
    Sudoku s;
    try{            
        s.ReadFromFile(input_file);
        std::cout << "Before solving:\n\n";
        s.Print();
        s.Solve();
        s.SaveToFile(output_file);
    }catch(std::exception& e){
        colors::SetErrorColor();
        std::cout << "ERROR: " << e.what() << "\n";
        colors::ResetColor();
        return;
    }

    std::cout << "Result:\n\n";

    s.Print();

    colors::SetSuccessColor();
    std::cout << "Successfully saved result to " << output_file << "\n";
    colors::ResetColor();
}

// It's better to use filesystem lib, but if it's not available use dirent.h

#if __cplusplus >= 201703L
    #include <filesystem>
    std::vector<std::string> GetAllFilesFromPath(std::string path){
        std::vector<std::string> all_files;
        for (const auto & entry : std::filesystem::directory_iterator(path)){
            std::string file = entry.path();
            if (file.find(input_file_extension) != std::string::npos) {
                all_files.push_back(file);
            }            
        }
        return all_files;
    }
#else
    #include <dirent.h>
    std::vector<std::string> GetAllFilesFromPath(std::string path){
        DIR *dir;
        struct dirent *ent;
        std::vector<std::string> all_files;
        if ((dir = opendir(path.c_str())) != NULL) {
            while ((ent = readdir (dir)) != NULL) {
                std::string file = ent->d_name;
                if (file.find(input_file_extension) != std::string::npos) {
                    all_files.push_back(file);
                }            
            }
            closedir (dir);
        }else{
            colors::SetErrorColor();
            std::cout << "Error: coudn't open folder\n";
            colors::ResetColor();
        }
        return all_files;
    }

#endif


void SolveMultipleSudoku(std::vector<std::string>& input_files, std::string& output_path){
    Sudoku s;
    for(auto file: input_files){
        try{            
            s.ReadFromFile(file);
            file.insert(file.find(input_file_extension), "_output"); 
            s.Solve();
            s.SaveToFile(output_path + "/" + file);
            
        }catch(std::exception& e){
            colors::SetErrorColor();
            std::cout << "ERROR " << "while scaning file " << file << " : " << e.what() << "\n";
            colors::ResetColor();
            break;
        }     
        colors::SetSuccessColor();
        std::cout << "Successfully saved result to " << output_path + "/" + file << "\n";
        colors::ResetColor();       
    }
}
// ---------------------------------------------------------------------
