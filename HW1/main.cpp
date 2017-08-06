#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>

#define MAX 255

using namespace std;

int file_line_num(){
    int i;
    ifstream f("text.txt");
    string line;
    for ( i = 0;getline(f, line); ++i)
        ;
    //satr sayisini hesapliyor textteki sonuna kadar getline ile giderek
    return i;
}

void text_to_array(char a[][MAX]){
    fstream file;
    int b;
    string x;
    b=file_line_num();
    file.open("text.txt");
    for(int i=0;i<b;i++) {
        getline(file, x);
        x.copy(a[i],MAX);

    }

    //arrayle cagiriliyo o arayi dolduruyo arguman2 /txt.txt acark ordaki satirlari
    //getline ile filestreamdan x satirina atiyo
    //x satirinida arraya atiyo ordan x.copy ile max kadar elemanini

    file.close();

}
void main_test(char a[][MAX]){
    string sub;
    string top;
    int array[5];
    for(int o=0;o<5;o++)
        array[o]=0;

    int b=file_line_num();

    for(int i=0;i<b;i++){
        //top= nullptr;
        top.clear();
        sub=a[i];
        //a[i] mainde doldurup textteki her seyi atanmis ikili matrix onu tekli index cagiriyo yani string
        //simdi isstreamda onu stream gibi aliyo yani aticak
        //yani cumleyi kelimelere boluyo kapis bosluga gore
        istringstream iss(sub);
        do
        {
            string sus;
            iss >> sus;
            top+=sus;
        } while (iss);


          if(top.compare(0,3,"mov",3)==0) {
              string sayi;
              if (top.compare(6, 1, "r", 1) == 0) {
                  array[(int) top[7] - '0' - 1] = array[(int) top[4] - '0' - 1];
              } else if (top.compare(3, 1, "r", 1) == 0) { // mov r1 10
                  sayi = top.substr(6);
                  array[(int) top[4] - '0' - 1] = stoi(sayi);
                  //cout <<stoi(sayi)+<< "sayi" << endl;
              }
          }

            if(top.compare(0,3,"add",3)==0){
                string sayi;
                if(top.compare(6,1,"r",1)==0){
                   array[(int)top[4]-'0'-1]+=array[(int)top[7]-'0'-1];
                }
                else if(top.compare(3,1,"r",1)==0){ // mov r1 10
                    sayi=top.substr(6);
                    array[(int)top[4]-'0'-1]+=stoi(sayi);
                    //cout <<stoi(sayi)+<< "sayi" << endl;
                }

        }
              if(top.compare(0,3,"sub",3)==0){
                  string sayi;
                  if(top.compare(6,1,"r",1)==0){
                      array[(int)top[4]-'0'-1]-=array[(int)top[7]-'0'-1];
                  }
                  else if(top.compare(3,1,"r",1)==0){ // mov r1 10
                      sayi=top.substr(6);
                      array[(int)top[4]-'0'-1]-=stoi(sayi);
                      //cout <<stoi(sayi)+<< "sayi" << endl;
                  }

              }
        if(top.compare(0,3,"jmp",3)==0) {
            string sayi;
            if(top.compare(3,1,"r",1)==0){
                if(array[(int)top[4]-'0'-1]==0){
                    cout << "Register" << top[4] << ":0 so jumping"<<endl;
                    sayi=top.substr(5);
                    i=stoi(sayi)-1;
                }
            }
            else{
                sayi=top.substr(3);
                i=stoi(sayi)-1;//for i++ i guess
            }
        }
        if(top.compare(0,3,"hlt",3)==0) {
            cout << "Halting program \n";
            cout << "REG 1 :" << array[0] << endl;
            cout << "REG 2 :" << array[1] << endl;
            cout << "REG 3 :" << array[2] << endl;
            cout << "REG 4 :" << array[3] << endl;
            cout << "REG 5 :" << array[4] << endl;
        }


        if(top.compare(0,3,"prn",3)==0) {
            string sayi;
            if(top.compare(3,1,"r",1)==0){
                cout << "Printing R" << top[4] << ":" << array[((int) top[4] - '0'-1)] << endl;
                    }
            else{
                sayi=top.substr(3);
                cout << "Printing Constant :" <<sayi<<endl; //though we should change sayi-to (int)-'0'-?
            }
        }

    }


}

int main() {
    char text[MAX][MAX];
    text_to_array(text);
    main_test(text);
    return 0;
}

//this program is basic ass coded no error check or good coding in 1.5 hours
//23.42 06 july 2017  gonna do good checks for github share later
