#ifndef COLORS_H
#define COLORS_H

#include <iostream>

// All colors
// !!! WORKS ONLY ON LINUX !!!
#if defined(QT_VERSION) || defined(__linux__)
    #define RESET       std::cout << "\033[0m"
    #define BLACK       std::cout << "\033[30m"             /* Black */
    #define RED         std::cout << "\033[31m"             /* Red */
    #define GREEN       std::cout << "\033[32m"             /* Green */
    #define YELLOW      std::cout << "\033[33m"             /* Yellow */
    #define BLUE        std::cout << "\033[34m"             /* Blue */
    #define MAGENTA     std::cout << "\033[35m"             /* Magenta */
    #define CYAN        std::cout << "\033[36m"             /* Cyan */
    #define WHITE       std::cout << "\033[37m"             /* White */
    #define BOLDBLACK   std::cout << "\033[1m\033[30m"      /* Bold Black */
    #define BOLDRED     std::cout << "\033[1m\033[31m"      /* Bold Red */
    #define BOLDGREEN   std::cout << "\033[1m\033[32m"      /* Bold Green */
    #define BOLDYELLOW  std::cout << "\033[1m\033[33m"      /* Bold Yellow */
    #define BOLDBLUE    std::cout << "\033[1m\033[34m"      /* Bold Blue */
    #define BOLDMAGENTA std::cout << "\033[1m\033[35m"      /* Bold Magenta */
    #define BOLDCYAN    std::cout << "\033[1m\033[36m"      /* Bold Cyan */
    #define BOLDWHITE   std::cout << "\033[1m\033[37m"      /* Bold White */
    #define COLOR       std::cout << "\033[1m\033[30;47m"   /* Bold White */
/*
#elif _WIN32
# TODO: colors on windows
*/
#else
    #define RESET       
    #define BLACK       
    #define RED         
    #define GREEN       
    #define YELLOW      
    #define BLUE        
    #define MAGENTA     
    #define CYAN        
    #define WHITE       
    #define BOLDBLACK   
    #define BOLDRED     
    #define BOLDGREEN   
    #define BOLDYELLOW  
    #define BOLDBLUE    
    #define BOLDMAGENTA 
    #define BOLDCYAN    
    #define BOLDWHITE   
    #define COLOR       
#endif

namespace colors{
    // set color depending on number
    void SetColorForNumber(short num);
    // set color back
    void ResetColor();
    // color for error messages
    void SetErrorColor();
    // color for success messages
    void SetSuccessColor();
};


#endif //end COLORS_H