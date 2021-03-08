#include <iostream>
#include <string>
#include "snowman.hpp"

using namespace std;
using namespace ariel;

string hat(int num);
string nose(int num);
string eye(int num);
string torso(int num);
string rharm(int num);
string lharm(int num);
string base(int num);

struct expt : public exception
{
    const char* what() const throw() {
        return "Invalid code: ";
    }
};


string ariel::snowman(int num) {

    if(num < 11111111 || num > 44444444)
    {
        throw expt();
    }
    string snow[8];
    string snowman;
    int digit;
    for(int i=7 ; i>=0 ; i--)
    {
        digit = num%10;
        num /= 10;
        switch(i)
        {
            case 0: snow[0] = hat(digit);break;
            case 1: snow[1] = nose(digit);break;
            case 2: snow[2] = eye(digit);break;
            case 3: snow[3] = eye(digit);break;
            case 4: snow[4] = lharm(digit);break;
            case 5: snow[5] = rharm(digit);break;
            case 6: snow[6] = torso(digit);break;
            case 7: snow[7] = base(digit);break;
        }
    }
    if(snow[4] == "\\" && snow[5] == "/")
    {
        snowman = "\n" + snow[0]; 
        snowman += "\n" + snow[4] + "(" + snow[2] + snow[1] + snow[3] + ")" + snow[5];
        snowman += "\n (" + snow[6] + ")\n";
        snowman += " (" + snow[7] + ")";
    }
    else if(snow[4] == "\\")
    {
        snowman += "\n" + snow[0];
        snowman += "\n" + snow[4] + "(" + snow[2] + snow[1] + snow[3] + ")";
        snowman += "\n (" + snow[6] + ")" + snow[5] + "\n";
        snowman += " (" + snow[7] + ")";
    }
    else if(snow[5] == "/")
    {
        snowman += "\n" + snow[0];
        snowman += "\n (" + snow[2] + snow[1] + snow[3] + ")" + snow[5];
        snowman += "\n" + snow[4] + "(" + snow[6] + ")\n";
        snowman += " (" + snow[7] + ")";
    }
    else
    {
        snowman += "\n" + snow[0];
        snowman += "\n (" + snow[2] + snow[1] + snow[3] + ")";
        snowman += "\n" + snow[4] + "(" + snow[6] + ")" + snow[5] + "\n";
        snowman += " (" + snow[7] + ")";
    }
    return snowman;

}

string hat(int num) {

    if(num > 4 || num < 1)
        throw expt();
    switch(num)
    {
        case 1: return " _===_";break;
        case 2: return "  ___\n .....";break;
        case 3: return "   _\n  /_\\";break;
        case 4: return "  ___\n (_*_)";break;
        default: return "";
    }

}

string nose(int num) {
    
    if(num > 4 || num < 1)
        throw expt();
    switch(num)
    {
        case 1: return ",";break;
        case 2: return ".";break;
        case 3: return "_";break;
        case 4: return " ";break;
        default: return "";
    }

}

string eye(int num) {

    if(num > 4 || num < 1)
        throw expt();
    switch(num)
    {
        case 1: return ".";break;
        case 2: return "o";break;
        case 3: return "O";break;
        case 4: return "-";break;
        default: return "";
    }

}

string lharm(int num) {

    if(num > 4 || num < 1)
        throw expt();
    switch(num)
    {
        case 1: return "<";break;
        case 2: return "\\";break;
        case 3: return "/";break;
        case 4: return " ";break;
        default: return "";
    }

}

string rharm(int num) {

    if(num > 4 || num < 1)
        throw expt();
    switch(num)
    {
        case 1: return ">";break;
        case 2: return "/";break;
        case 3: return "\\";break;
        case 4: return " ";break;
        default: return "";
    }

}

string torso(int num) {

    if(num > 4 || num < 1)
        throw expt();
    switch(num)
    {
        case 1: return " : ";break;
        case 2: return "] [";break;
        case 3: return "> <";break;
        case 4: return "   ";break;
        default: return "";
    }

}

string base(int num) {

    if(num > 4 || num < 1)
        throw expt();
    switch(num)
    {
        case 1: return " : ";break;
        case 2: return "\" \"";break;
        case 3: return "___";break;
        case 4: return "   ";break;
        default: return "";
    }

}
