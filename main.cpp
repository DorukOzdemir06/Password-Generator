#include "PasswordGenerator.hpp"
using namespace std;

int main(){
    //Create PasswordGenerator object
    PasswordGenerator PG;
    //Define length and mode of the password
    unsigned long long int len = 0;
    unsigned short mode = 0;
    //Provide menu
    PG.Menu();
    //Ask for password difficulty mode
    PG.askMode(mode);
    //Ask for password length
    PG.askLength(len);
    //Generate password
    PG.generate();
    //Print password
    PG.printPassword();
    return 0;
}
