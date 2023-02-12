#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

int generateRandNum(int start, int end){
    return (start + rand() % (end - start + 1));
}

string generateRandString(unsigned long long int len, unsigned short mode){
    if (mode < 0 || mode > 2){
        cerr << "wrong mode input! 0, 1 or 2"<<endl;
    }

    srand(time(NULL));
    string result;
    result.reserve(len);
    char chr;
    short temp;

    if (mode == 0){
        for (int i = 0; i < len; ++i) {
            chr = generateRandNum(48,57);
            result += chr;
        }
    }
    else if (mode == 1){
        for (int i = 0; i < len; ++i) {
            temp = generateRandNum(0,2);
            if (temp == 0){
                chr = generateRandNum(48,57);
                result += chr;
            }
            else if (temp == 1){
                chr = generateRandNum(65,90);
                result += chr;
            }
            else if (temp == 2){
                chr = generateRandNum(97,122);
                result += chr;
            }
        }
    }
    else if (mode == 2){
        for (int i = 0; i < len; ++i) {
            temp = generateRandNum(0,3);
            if (temp == 0){
                chr = generateRandNum(48,57);
                result += chr;
            }
            else if (temp == 1){
                chr = generateRandNum(65,90);
                result += chr;
            }
            else if (temp == 2){
                chr = generateRandNum(97,122);
                result += chr;
            }
            else if (temp == 3){
                chr = generateRandNum(33,47);
                result += chr;
            }
        }
    }
    return result;
}



int main()
{
    cout <<"Random Password Generator"<<endl<<"-------------------------"<<endl;
    auto *diff = new string;
    auto *len = new unsigned long long int;


    while (true) {

        cout << "Difficulty (hard, normal or easy): ";
        cin>>*diff;
        cout << "Char count (min 8): ";
        cin >> *len;

        if (*len < 8 ) {
            cout << "Char count is not valid!"<<endl;
            continue;
        }
        else if (*diff != "hard" && *diff != "normal" && *diff != "easy" ){
            cout << "Select a valid difficulty!"<<endl;
            continue;
        }
        else{
            cout << "Password: ";
            if (*diff == "hard"){
                cout << generateRandString(*len,2)<<endl;
            }
            else if (*diff == "normal"){
                cout << generateRandString(*len,1)<<endl;
            }
            else if (*diff == "easy") {
                cout << generateRandString(*len, 0) << endl;
            }
            break;
        }

    }
    delete diff;
    delete len;


    return 0;
}
