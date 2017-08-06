//
// Created by paypaytr on 8/3/17.
//

#ifndef UNTITLED15_CPUPROGRAM_H
#define UNTITLED15_CPUPROGRAM_H
#define MAX 255

class CPUProgram {
 public:
    void ReadFile(string parameter);
    string getLine(int parameter);
    int size();
    CPUProgram(string argument);
    int file_line_num(string parameter);
 private:
  char a[][MAX];
};


#endif //UNTITLED15_CPUPROGRAM_H
