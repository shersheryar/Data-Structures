#include <iostream>
#include <regex>
#include <string>
using namespace std;

void checkPassword(string str, regex password){
smatch matches;
cout << boolalpha;
while(regex_search(str, matches,password)){
   
}
}
int main(){
string str = " sfdsfdsf";
regex password  ("(?=.*[a-z])(?=.*[0-9])(?=.*[A-Z])(?=.*[*.!@#$%^&(){}[]:;<>,.?/~_+-=|\\])[a-zA-Z0-9!?].{5,11}");
 
}