#ifndef PASSWORD_GENERATOR_PASSWORDGENERATOR_HPP
#define PASSWORD_GENERATOR_PASSWORDGENERATOR_HPP
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;
class PasswordGenerator{
private:
	//Fields
	string password;
	unsigned long long int length;
	unsigned short mode;

	//////METHODS//////

	//generates a random ASCII character
	int randomASCIIChar(int start, int end){
		return (start + rand() % (end - start + 1));
	}

	//Getters
	string getPassword(){return this->password;}
	unsigned short getMode(){return this->mode;}
	unsigned long long int getLength(){return this->length;}

	//Setters
	void setPassword(string &passwordStr){this->password = passwordStr;}
	void setMode(unsigned short &mode){this->mode = mode;}
	void setLength(unsigned long long int &len){this->length = len;}

public:
	//Constructor
	PasswordGenerator(){
		this->password = "";
		this->mode = 0;
		this->length = 0;
	}

	//Destructor
	~PasswordGenerator(){
		this->password.clear();
		this->mode = 0;
		this->length = 0;
	}

	void Menu(){
		cout<<"******  Random Password Generator  ******"<<endl<<"------------------------------------------"<<endl;
		cout<<"Select the difficulty of the password:"<<endl;
		cout<<"1. Easy(Number based)"<<endl;
		cout<<"2. Normal(Number and letter based)"<<endl;
		cout<<"3. Hard(Number, letter and special characters based)"<<endl;
		cout<<"4. Exit the program"<<endl;
	}

	int askMode(unsigned short &input){
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

	void askLength(unsigned long long int &len){
		cout<<"Enter the length of the password(Minimum 8 is allowed and minimum 13 is advised): ";
		cin>>len;
		if (len < 8){
			cout<<"Enter a valid length!"<<endl;
			askLength(len);
		} else {
			setLength(len);
		}
	}

	void generate(){
		srand(time(NULL));
		this->password.reserve(this->length);
		char chr = NULL;
		short temp = NULL;

		if (this->mode == 1){
			for (int i = 0; i < this->length; ++i) {
				chr = randomASCIIChar(48,57);
				this->password += chr;
			}
		}
		else if (this->mode == 2){
			for (int i = 0; i < this->length; ++i) {
				temp = randomASCIIChar(48,50) - 48;
				if (temp == 0){
					chr = randomASCIIChar(48,57);
					this->password += chr;
				}
				else if (temp == 1){
					chr = randomASCIIChar(65,90);
					this->password += chr;
				}
				else if (temp == 2){
					chr = randomASCIIChar(97,122);
					this->password += chr;
				}
			}
		}
		else if (this->mode == 3){
			for (int i = 0; i < this->length; ++i) {
				temp = randomASCIIChar(48,51) - 48;
				if (temp == 0){
					chr = randomASCIIChar(48,57);
					this->password += chr;
				}
				else if (temp == 1){
					chr = randomASCIIChar(65,90);
					this->password += chr;
				}
				else if (temp == 2){
					chr = randomASCIIChar(97,122);
					this->password += chr;
				}
				else if (temp == 3){
					chr = randomASCIIChar(33,47);
					this->password += chr;
				}
			}
		}
	}

	void printPassword(){
		cout<<"Your password is: "<<this->password<<endl;
	}
};

#endif //PASSWORD_GENERATOR_PASSWORDGENERATOR_HPP
