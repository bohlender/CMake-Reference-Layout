#include <mylib/MyLib.h>
#include <iostream>

int main(){
    std::cout << "Running MyApplication (mylib " << MyLib::getVersionString() << ")" << std::endl;
}