#include "Colors.h"

void colors::SetColorForNumber(short num){
    if(num == 0){
        BLACK;
        return;
    }
    switch (num % 9) {
        case 0: COLOR;          return;
        case 1: BOLDBLUE;       return;
        case 2: BOLDBLACK;      return;
        case 3: BOLDRED;        return;
        case 4: BOLDYELLOW;     return;
        case 5: BOLDWHITE;      return;
        case 6: BOLDMAGENTA;    return;
        case 7: BOLDCYAN;       return;
        case 8: BOLDGREEN;      return;
    }
    BLACK;
}

void colors::ResetColor(){
    RESET;
}

void colors::SetErrorColor(){
    BOLDRED;
}

void colors::SetSuccessColor(){
    BOLDGREEN;
}