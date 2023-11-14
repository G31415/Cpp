#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main(int argc, char* argv[ ]){
    ifstream f1;
    ofstream f2;
    char ch;
    cout << "Usage: Merge -s <file1> <file2> ... <fileN> -o <ofile>\n";
    if (argc<5) {
        cout<< "Parameters error: this program needs at least 5 parameters!\n";
        return 1;
    }
    if (strcmp(argv[1], "-s") != 0 || strcmp(argv[argc - 2], "-o") != 0) {
        cout<< "Parameters error: the second parameter must be \"-s\"";
        cout<< ", and the one before last parameter must be \"-o\"!\n";
        return 2;
    }
    f2.open(argv[argc-1], ios::in + ios::ate);
    if (f2) { //若文件存在则退出
        cout << "The object file "<< argv[argc - 1]<<" already exist!\n";
        f2.close( );
        return 3;
    }
    f2.close( );
    f2.open(argv[argc-1], ios::out + ios::binary+ios::trunc);
    for (int c = 2; c < argc - 2; c++) {
        f1.open(argv[c], ios::in + ios::binary);
        if ((!f1)) { //若文件不存在
            cout << "The source file "<<argv[c]<<" open error!\n";
            f2.close( );
            return 4;
        }
        while (f1.get(ch))  f2.put(ch);
        f1.close( );
    }
    f2.close( );
    return 0;
}
