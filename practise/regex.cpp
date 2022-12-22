#include <iostream>
#include <regex>
#include <string>
using namespace std;

void printMatches(string str, regex reg){
    smatch matches;
    cout << boolalpha;
     while(regex_search(str,matches,reg)){
        cout <<"is there a matches: " << matches.ready()<<endl;
        cout <<"are there no matches: " << matches.empty()<<endl;
        cout <<"Number of matches: " << matches.size()<<endl;
        cout << matches.str(1);
        str = matches.suffix().str();
        cout << endl;
     }
}
int main(){
    string str = "The ape was at the apex";
    regex reg("(ape[^ ]?)");
      printMatches(str, reg);
}