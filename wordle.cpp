#include <fstream>
#include "wordle.h"
#include <iostream>
#include <cctype>
#include <string> 
#include <vector>
#include <cstdlib> 
#include <algorithm> 
#include <time.h> 

using std::endl;
using std::cin;
using std::cerr;
using std::ifstream;
using std::string;
using std::getline;
using std::cout;
using std::vector;
using std::search;
ifstream inputFile("wordle-words.txt");

Wordle::Wordle()
{
    vector <string> list;
}
Wordle::~Wordle()
{
    
}
int Wordle::read()
{
    if (!inputFile.is_open()) { 
        cerr << "Error opening the file!" << endl; 
        return 1; 
    } 

    string words;
    while (inputFile >> words) { 
        this->list.push_back(words);
    } 
    inputFile.close();

    
    // for (int i = 0; i < (int) this->list.size(); i++)
    // {
    //     cout << this->list[i] << endl;
    // }
    
    return 0;
}
void Wordle::play()
{
    vector <char> test = {'_','_','_','_','_'};
    vector<int>::iterator i1;
    
    
    
    bool win = false;
    string attempt;
    srand(time(0));
    
    int num = rand() % this->list.size() ;
    string answer = this->list[num];
    // cout << "ANSWER: " << answer << endl;



   for (int i = 0; i < 5; i++)
   {
        cout << "Enter word: ";
        cin >> attempt;
        cout << endl;
        while(attempt.size() != 5 ){
        cout << "Enter 5 letter word: ";
        cin >> attempt;
        cout << endl;
        }
        if(attempt.compare(answer) == 0){
            win = true;
            cout << "YOU WON!" << endl;;
            break;
        }
        
        for (int j = 0; j < 5; j++)
        {
            std::size_t found = answer.find(attempt[j]);
            bool used = std::find(test.begin(), test.end(), attempt[j]) != test.end();
            if (found != string::npos && !used){
                test[j] = attempt[j];
            }
           
           if(attempt[j] == answer[j] && !used){
            test[j] = toupper(attempt[j]);
                
            } 
             

        }
       
        for (int k = 0; k < 5; k++)
        {
            
            cout << test[k] << " ";
            test[k] = '_';
            
            
        }
        cout << endl;
        
        
   }
    if(!win){
        cout << "Answer: " << answer << endl;
    }

   
   

   
}