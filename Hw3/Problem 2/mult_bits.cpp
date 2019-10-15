#include <cstdlib>
#include <list> // i am using preimplemented lists as I did not want to implement my own ;)
#include <string>
#include <iostream>
#include <algorithm>
#include "functions.h"
using namespace std;

int main() 
{  
    //check to see the multiplication works
    cout<<mult_brute_force("11011", "10101") << endl;
    cout<<multiply("1011",  "1101") << endl;
    return 0; 
}