//
// Created by paypaytr on 8/3/17.
//

#include "CPUProgram.h"
#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>

using namespace std;

CPUProgram::CPUProgram(string argument) {
    ReadFile(argument);

}

void CPUProgram::ReadFile(string parameter) {
    fstream file;
    int b;
    string x;
    b=file_line_num(parameter);
    file.open(parameter);
    for(int i=0;i<b;i++) {
        getline(file, x);
        x.copy(a[i],MAX);

    }

    //arrayle cagiriliyo o arayi dolduruyo arguman2 /txt.txt acark ordaki satirlari
    //getline ile filestreamdan x satirina atiyo
    //x satirinida arraya atiyo ordan x.copy ile max kadar elemanini

    file.close();
}

int CPUProgram:: file_line_num(string parameter){
    int i;
    ifstream f(parameter);
    string line;
    for ( i = 0;getline(f, line); ++i)
        ;
    //satr sayisini hesapliyor textteki sonuna kadar getline ile giderek
    return i;
}

string CPUProgram::getLine(int parameter) {
    return a[parameter];
}
int CPUProgram::size() {
    return file_line_num("test.txt");
}