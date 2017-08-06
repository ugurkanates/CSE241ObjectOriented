//
// Created by paypaytr on 8/3/17.
//

#ifndef UNTITLED15_CPU_H
#define UNTITLED15_CPU_H


class CPU {
 private:
    int registe[5];
    int PC; //program line it executes
 public:
    void set_register(int hangi,int kac);
    int* get_register();
    void set_PC(int kac);
    int get_PC();
    void print();
    bool halted();
    void execute(string instruction);
    CPU();

};


#endif //UNTITLED15_CPU_H
