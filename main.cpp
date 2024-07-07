#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <sstream>
#include <cstdio>

#include "wordle.h"
using namespace std;




int main()
{
    Wordle object;

    cout << endl;
    cout << "WORDLE" << endl;
    cout << endl;


    object.read();
    object.play();

    
    
    return 0;

}