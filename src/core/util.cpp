#include "util.h"
#include <iostream>
using namespace std;

// Primitive helper utilities, clamping, and screen control

int clampInt(int val, int minVal, int maxVal)
{
    if (val < minVal){return minVal;}
    if (val > maxVal){return maxVal;}
    return val;
}

void trimWhitespace(char* str)
{
    if (str==nullptr){return;}

    int len = 0;
    while (str[len] != '\0'){len++;}
    while (len > 0 && (str[len - 1] == ' ' || str[len - 1] == '\t' || str[len - 1] == '\n' || str[len - 1] == '\r'))//removes all kinds of whitespaces
    {
        str[len - 1] = '\0';
        len--;
    }

    int start = 0;
    while (str[start] == ' ' || str[start] == '\t')
    {
        start++;
    }


    if (start > 0)//shifts characters to do the left until all leading whitespaces are gone (start counts a ll leading whitespaces)
    {
        int j = 0;
        for (int i = start; i <= len; i++)
        {
            str[j] = str[i];
            j++;
        }
    }
}

bool stringEquals(const char* a, const char* b)
{
    if (a ==nullptr ||b==nullptr){return false;}

    int i=0;
    while (a[i]!='\0' && b[i]!= '\0'){
        if (a[i] != b[i]){return false;}
        i++;
    }

    if (a[i] == '\0' && b[i] == '\0'){return true;}
    return false;
}

void printHeader(const char* title)
{
    cout << endl;
    cout << "**************************************************" << endl;
    cout << "   " << title << endl;
    cout << "**************************************************" << endl;
}

void clearScreen()
{   cout << endl << endl;}

int readNumber(){
    int num;
    while (true){
        cin >> num;
        if (cin.eof()){
            return -1;
        }
        if (cin.fail()){
            cin.clear();
            cin.ignore(1000,'\n');
            cout<<"Invalid input. Please enter a number: ";}
        else{return num;}
    }
}

char readSymbol()
{
    char c;
    cin >> c;
    if (cin.eof()){return '\0';}
    cin.ignore(1000, '\n');
    return c;
}
