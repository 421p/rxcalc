#include <iostream>
#include <string>
#include <regex>
#include <exception>

class dnoe: public std::exception
{
  virtual const char* what() const throw()
  {
    return "Delenie na nol' exception.";
  }
} dnoe;

class rxcalc{
    
private: 
        std::string expression;
        std::regex skobkiPattern; 
        std::regex firstPriorityPattern;
        std::regex secondPriorityPattern;
        std::smatch regexResult;
        std::regex simplePattern;         
        std::smatch simpleParseResult;
        
        double a, b;        
        double simpleParse(std::string);
public:
    
    rxcalc(std::string a):expression(a), skobkiPattern("(\\([^)]+\\))"), firstPriorityPattern("(\\d*[.]?\\d+)([\\*\\/])(\\d*[.]?\\d+)"), 
    secondPriorityPattern("(\\d*[.]?\\d+)([\\+\\-])(\\d*[.]?\\d+)"), simplePattern("(\\d*[.]?\\d+)([\\+\\-\\/\\*])?(\\d*[.]?\\d+)") {}
    rxcalc(const char* a):expression(a), skobkiPattern("(\\([^)]+\\))"), firstPriorityPattern("(\\d*[.]?\\d+)([\\*\\/])(\\d*[.]?\\d+)"), 
    secondPriorityPattern("(\\d*[.]?\\d+)([\\+\\-])(\\d*[.]?\\d+)"), simplePattern("(\\d*[.]?\\d+)([\\+\\-\\/\\*])?(\\d*[.]?\\d+)") {}
    rxcalc():skobkiPattern("(\\([^)]+\\))"), firstPriorityPattern("(\\d*[.]?\\d+)([\\*\\/])(\\d*[.]?\\d+)"), 
    secondPriorityPattern("(\\d*[.]?\\d+)([\\+\\-])(\\d*[.]?\\d+)"), simplePattern("(\\d*[.]?\\d+)([\\+\\-\\/\\*])?(\\d*[.]?\\d+)") {}
    
    void show();
    double calculate(bool = false);
    double calculate(const char*, bool = false);
    double calculate(std::string, bool = false);
};

 double rxcalc::simpleParse(std::string str){  // 2 numbers
             
        if(std::regex_search(str, simpleParseResult, simplePattern)){
            a = std::stod(simpleParseResult.str(1));
            b = std::stod(simpleParseResult.str(3));

            switch(simpleParseResult.str(2)[0]){
                case '+': return a + b;
                case '-': return a - b;
                case '*': return a * b;
                case '/': if(b) return a/b; 
                    else {
                        throw dnoe; 
                        return -3;
                        }
                default: throw; return -1;
            }
        }
        else{
            throw;
            return -2;
        }
    }
    
double rxcalc::calculate(const char* ex, bool debug){    
        this->expression = ex;
        try{
            while(std::regex_search(expression, regexResult, skobkiPattern)){
                expression = std::regex_replace(expression, skobkiPattern, std::to_string(simpleParse(regexResult.str(1))), std::regex_constants::format_first_only);
            }
            if(debug){
                std::cerr<<"We've done with skobka's."<<std::endl
                <<expression<<std::endl;
            }
            
        } catch(std::exception& e){
            std::cerr << e.what() << std::endl;
            return 0;
        }
                
        try{
            while(std::regex_search(expression, regexResult, firstPriorityPattern)){
            expression = std::regex_replace(expression, firstPriorityPattern, std::to_string(simpleParse(regexResult.str())), std::regex_constants::format_first_only);
        }
            if(debug){
                std::cerr<<"We've done with * and /. "<<std::endl
                <<expression<<std::endl;
            }
                
        } catch (std::exception& e){
            std::cerr << e.what() << std::endl;
            return 0;
        }

        try{
            while(std::regex_search(expression, regexResult, secondPriorityPattern)){
                expression = std::regex_replace(expression, secondPriorityPattern, std::to_string(simpleParse(regexResult.str())), std::regex_constants::format_first_only);
            }
            if(debug){
                std::cerr<<"We've done with + and - "<<std::endl
                <<expression<<std::endl;                
            }
        } catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
            return 0;
        }
        
        return stod(expression);
    }
  
double rxcalc::calculate(std::string ex, bool debug){    
        this->expression = ex;
        try{
            while(std::regex_search(expression, regexResult, skobkiPattern)){
                expression = std::regex_replace(expression, skobkiPattern, std::to_string(simpleParse(regexResult.str(1))), std::regex_constants::format_first_only);
            }
            if(debug){
                std::cerr<<"We've done with skobka's."<<std::endl
                <<expression<<std::endl;
            }
            
        } catch(std::exception& e){
            std::cerr << e.what() << std::endl;
            return 0;
        }
                
        try{
            while(std::regex_search(expression, regexResult, firstPriorityPattern)){
            expression = std::regex_replace(expression, firstPriorityPattern, std::to_string(simpleParse(regexResult.str())), std::regex_constants::format_first_only);
        }
            if(debug){
                std::cerr<<"We've done with * and /. "<<std::endl
                <<expression<<std::endl;
            }
                
        } catch (std::exception& e){
            std::cerr << e.what() << std::endl;
            return 0;
        }

        try{
            while(std::regex_search(expression, regexResult, secondPriorityPattern)){
                expression = std::regex_replace(expression, secondPriorityPattern, std::to_string(simpleParse(regexResult.str())), std::regex_constants::format_first_only);
            }
            if(debug){
                std::cerr<<"We've done with + and - "<<std::endl
                <<expression<<std::endl;                
            }
        } catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
            return 0;
        }
        
        return stod(expression);
    }
  
double rxcalc::calculate(bool debug){        
        try{
            while(std::regex_search(expression, regexResult, skobkiPattern)){
                expression = std::regex_replace(expression, skobkiPattern, std::to_string(simpleParse(regexResult.str(1))), std::regex_constants::format_first_only);
            }
            if(debug){
                std::cerr<<"We've done with skobka's."<<std::endl
                <<expression<<std::endl;
            }
            
        } catch(std::exception& e){
            std::cerr << e.what() << std::endl;
            return 0;
        }
                
        try{
            while(std::regex_search(expression, regexResult, firstPriorityPattern)){
            expression = std::regex_replace(expression, firstPriorityPattern, std::to_string(simpleParse(regexResult.str())), std::regex_constants::format_first_only);
        }
            if(debug){
                std::cerr<<"We've done with * and /. "<<std::endl
                <<expression<<std::endl;
            }
                
        } catch (std::exception& e){
            std::cerr << e.what() << std::endl;
            return 0;
        }

        try{
            while(std::regex_search(expression, regexResult, secondPriorityPattern)){
                expression = std::regex_replace(expression, secondPriorityPattern, std::to_string(simpleParse(regexResult.str())), std::regex_constants::format_first_only);
            }
            if(debug){
                std::cerr<<"We've done with + and - "<<std::endl
                <<expression<<std::endl;                
            }
        } catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
            return 0;
        }
        
        return stod(expression);
    }
    
void rxcalc::show(){
        std::cout<<expression << std::endl;
    }
