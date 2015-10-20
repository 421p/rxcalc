#include <iostream>
#include "rxcalc.hpp"

using namespace std;

int main(int argc, char **argv){
    /*
    string inputString = "200+20*20+2*(3+4)+(25+3)*2+3.5"; //673.5
    rxcalc calc(inputString);
    cout << calc.calculate() << endl; // так тоже можно
     */
     
     rxcalc calculator;
     string userInput;;
     
     cout << "Welcome to the rxcalc v0.00043alpha.\n Use \"quit\" or \"exit\" for exiting.\nEnter your expression:\n> ";
     while(true){
         getline(cin, userInput);
         if(userInput == "exit" || userInput == "quit") { cout << "bye!\n"; return 0; }
                try{
                    cout << "Result: " << calculator.calculate(userInput) << "\n> ";  
                } catch(std::invalid_argument &e){
                    cout << "Invalid expression or command!\n> ";
                }
         }
    
    return 0;
}
