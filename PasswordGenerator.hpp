#ifndef PASSWORD_GENERATOR_PASSWORDGENERATOR_HPP
#define PASSWORD_GENERATOR_PASSWORDGENERATOR_HPP
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;
class PasswordGenerator{
private:
	//FIELDS
	string password;
	unsigned long long int length;
	unsigned short mode;

	///////PRIVATE METHODS//////

	//Generates a random ASCII character
	int randomASCIIChar(int start, int end){
		return (start + rand() % (end - start + 1));
	}

	//Generates a random even number
	int randomEvenNumber(int start, int end){
		return (start + rand() % (end - start + 1) / 2) * 2;
	}

	//This function recursively works for every digit of the password
	void generateNthDigit(int digit, vector<int> &interval, int &temp){
		//Be sure that the digit is not the end of the password
		if(digit < this->length){
			//Mode 1 means there are only numbers in the password
			if(this->mode == 1){
				//ASCII interval for numbers, think it is like they are grouped by every 2 numbers
				interval={48,57};
				this->password += randomASCIIChar(interval[0],interval[1]);
			}
			//Mode 2 means there are numbers, uppercase and lowercase letters
			else if(this->mode == 2){
				//ASCII interval for numbers, uppercase and lowercase letters, think it is like they are grouped by every 2 numbers
				interval={48,57,65,90,97,122};
				//There are 6 number in interval so randomly choose an even number from 0 to 4 which will be the starting index of the interval
				temp = randomEvenNumber(0,4);
				//Accept temp as the starting index of the interval and add 1 to it to get the ending index of the interval
				this->password += randomASCIIChar(interval[temp],interval[temp+1]);
			}
			//Mode 3 means there are numbers, uppercase and lowercase letters and special characters
			else if(this->mode == 3){
				//ASCII interval for numbers, uppercase and lowercase letters and special characters, think it is like they are grouped by every 2 numbers
				interval={48,57,65,90,97,122,33,47};
				//There are 8 numbers in interval so randomly choose an even number from 0 to 6 which will be the starting index of the interval
				temp = randomEvenNumber(0,6);
				//Accept temp as the starting index of the interval and add 1 to it to get the ending index of the interval
				this->password += randomASCIIChar(interval[temp],interval[temp+1]);
			}
			//Call the function again to generate the next digit
			generateNthDigit(digit+1, interval, temp);
		}
	}
public:
	//CONSTRUCTORS
	PasswordGenerator(){
		this->password = "";
		this->length = 0;
		this->mode = 0;
	}

	PasswordGenerator(unsigned long long int length, unsigned short mode){
		this->password = "";
		this->length = length;
		this->mode = mode;
	}

	//DESTRUCTOR
	~PasswordGenerator(){
		this->password.clear();
		this->length = 0;
		this->mode = 0;
	}

	///////PUBLIC METHODS//////

	//GETTERS
	string getPassword(){return this->password;}
	unsigned short getMode(){return this->mode;}
	unsigned long long int getLength(){return this->length;}

	//SETTERS
	void setPassword(string &passwordAlias){this->password = passwordAlias;}
	void setMode(unsigned short &modeAlias){this->mode = modeAlias;}
	void setLength(unsigned long long int &lengthAlias){this->length = lengthAlias;}

	//Prints the menu
	void Menu(){
		cout<<"******  Random Password Generator  ******"<<endl<<"------------------------------------------"<<endl;
		cout<<"Select the difficulty of the password:"<<endl;
		cout<<"1. Easy(Number based)"<<endl;
		cout<<"2. Normal(Number and letter based)"<<endl;
		cout<<"3. Hard(Number, letter and special characters based)"<<endl;
		cout<<"4. Exit the program"<<endl;
	}

	//Asks the user for the mode of the password, recursively
	int askMode(unsigned short input=0){
		cin>>input;
		if (input < 1 || input > 4){
			cout<<"Select a valid option!"<<endl;
			askMode(input);
		} else if (input == 4){
			exit(0);
		} else{
			setMode(input);
			return input;
		}
	}

	//Asks the user for the length of the password, recursively
	void askLength(unsigned long long int len=0){
		cout<<"Enter the length of the password(Minimum 8 is allowed and minimum 13 is advised): ";
		cin>>len;
		if (len < 8){
			cout<<"Enter a valid length!"<<endl;
			askLength(len);
		} else {
			setLength(len);
		}
	}

	//Generates the password
	void generate(){
		srand(time(NULL));
		this->password.reserve(this->length);
		//Vector that holds the ASCII interval
		vector<int> interval={0,0};
		int temp = 0;
		generateNthDigit(0, interval,temp);
	}

	//Prints the password
	void printPassword(){
		cout<<"Your password is: "<<this->password<<endl;
	}
};

#endif //PASSWORD_GENERATOR_PASSWORDGENERATOR_HPP
