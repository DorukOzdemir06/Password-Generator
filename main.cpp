#include "PasswordGenerator.hpp"
using namespace std;

int main(){
    //Create PasswordGenerator object
    PasswordGenerator PG;
    //Provide menu
    PG.Menu();
    //Ask for password difficulty mode
    PG.askMode();
    //Ask for password length
    PG.askLength();
    //Generate password
    PG.generate();
    //Print password
    PG.printPassword();
    return 0;
}