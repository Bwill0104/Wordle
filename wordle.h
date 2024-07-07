#ifndef hang_man
#define hang_man
#include <fstream> 
#include <iostream> 
#include <string> 
#include <vector>

using std::vector;
using std::string;

class Wordle
{
protected:
    vector <string> list;

public:
    Wordle();
    virtual ~Wordle();
    int read();
    void play();
};

#endif // !hang_man

