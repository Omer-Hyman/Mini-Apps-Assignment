#include <iostream>
#include <time.h>
#include <array>
#include <string>
#include <cmath>

using namespace std;
void menu();
void keepCounting();			
void numberConversion();
int upcCalculation(int code, int array[]);
void upcCalc();
void upcCheck();
void decimalToHex(int decimal, string array[]);
void decimalToBinary(int decimal, int array[]);

int main()
{
	srand((int)time(NULL));// seeding time function for random functions
	menu();//menu call
	system("pause");
	return 0;
}

void menu()
{
	cout << "###################################################\n";
	cout << "Welcome to my Fop4CS mini applications assignment!\n";
	int menuChoice;

	for (int i = 0; i < 1; i++)//loop catching invalid input for menu
	{
		cout << "Menu of applications\n";
		cout << "1) Keep counting game\n";
		cout << "2) Number conversion tool\n";
		cout << "3) Universal product code (UPC) calculator\n";
		cout << "4) Universal product code (UPC) checker\n";
		cout << "9) Quit\n";
		cout << "Please select an option >  ";
		cin >> menuChoice;
		cout << "###################################################\n\n";
		switch (menuChoice)
		{
		case 1:
			keepCounting();
			break;
		case 2:
			numberConversion();
			break;
		case 3:
			upcCalc();
			break;
		case 4:
			upcCheck();
			break;
		case 9:		//Quit
			cout << "Goodbye!";
			break;
		default:
			cout << "Please input a valid option!\n\n";
			i--;
			break;
		}
	}
}

//	1
void keepCounting()
{
	int operand1, operand2, plusMinus, userAnswer, answer = 0;
	time_t start, finish;

	//random numbers for first equation
	operand1 = rand() % (11);
	operand2 = rand() % (11);

	cout << "You are about to recieve a set of 8 questions. \nAnswer them as quickly and as accurately as you can. \n";
	system("pause");
	time(&start);//timer starts
	for (int i = 1; i < 9; i++)//loop for 8 questions
	{
		plusMinus = rand() % (2);//plus or minus operator randomised 
		if (plusMinus == 0)//	+
		{
			cout << "\nQuestion " << i << ": What is " << operand1 << " + " << operand2 << "?  ";
			answer = operand1 + operand2;
		}
		else if (plusMinus == 1)//	-
		{
			cout << "\nQuestion " << i << ": What is " << operand1 << " - " << operand2 << "?  ";
			answer = operand1 - operand2;
		}
		cin >> userAnswer;
		if (userAnswer == answer)
		{
			operand1 = answer;
			operand2 = rand() % (11);
		}
		else //game lost
		{
			time(&finish);
			cout << "\nIncorrect, the answer was " << answer;
			cout << "\nGame over!\n\n";
			i = 11;//game-ending loop-exit
		}
		if (i == 8) //game won
		{
			time(&finish);//timer ends
			cout << "\nWell done, you completed all 8 questions in " << difftime(finish, start) << " seconds\n\n";
		}
	}
	time(&finish);//timer ends
	menu();//menu call to take user back to menu after task
}

void decimalToHex(int decimal, string array[])//decimal to hex calculation
{
	string remainderS, hexLetter;
	int remainder, hexLetterEquiv, i = 0;
	while (decimal != 0)
	{
		remainder = (decimal % 16);
		decimal = (decimal / 16);
		if (remainder > 9)
		{
			hexLetterEquiv = (remainder % 9);
			switch (hexLetterEquiv)
			{
			case 1:
				hexLetter = "A";
				break;
			case 2:
				hexLetter = "B";
				break;
			case 3:
				hexLetter = "C";
				break;
			case 4:
				hexLetter = "D";
				break;
			case 5:
				hexLetter = "E";
				break;
			case 6:
				hexLetter = "F";
				break;
			}
			array[i] = hexLetter;
		}
		else
		{
			remainderS = to_string(remainder);//int to string conversion
			array[i] = remainderS;
		}
		i++;
	}
	cout << "Hex: ";
	for (i; i >= 0; i--)
		cout << array[i];
	
}

void decimalToBinary(int decimal, int array[])//decimal to binary calculation
{
	int remainder = 0, x=0;
	while (decimal != 0)
	{
		remainder = decimal % 2;
		decimal = decimal / 2;
		array[x] = remainder;
		x++;
	}
	x--;
	cout << "\nBinary: ";
	for (x; x >= 0; x--)
		cout << array[x];
}

//	2
void numberConversion()
{
	int userChoice, decimal, binaryArray[100], binaryInputInt, i = 0;
	string hexNumber, hexArray[100], binaryInput, binaryInputIndex;
	cout << "Would you like to input a number in base 2(Binary), 10(Decimal) or 16(Hexadecimal)?  ";
	cin >> userChoice;
	
	switch (userChoice)
	{
	case 2://Binary
	{
		//TO DECIMAL
		decimal = 0;
		cout << "Please input binary number >  ";
		cin >> binaryInput;
		cout << "Decimal: ";
		int x = (binaryInput.length() - 1);

		//binary to decimal loop 
		for (i = 0; i < binaryInput.length(); i++)
		{
			binaryInputIndex = (binaryInput.at(x));//Setting index variable to index of binary input.
			binaryInputInt = stoi(binaryInputIndex);//String to int conversion.
			if (binaryInputInt == 1)
				decimal = decimal + (pow(2, i) * (binaryInputInt));//Binary to decimal conversion.
			x--;
		}
		cout << decimal << "\n";

		//TO HEXADECIMAL
		decimalToHex(decimal, hexArray);
		cout << "\n\n";
		
		menu();
		break;
	}
	case 10://Decimal
	{
		//TO HEXADECIMAL
		cout << "Please input a valid decimal number >  ";
		cin >> userChoice;
		decimal = userChoice;
		decimalToHex(decimal, hexArray);

		//TO BINARY
		decimal = userChoice;
		decimalToBinary(decimal, binaryArray);
		cout << "\n\n";

		menu();
		break;
	}
	case 16://Hexadecimal
	{
		//TO DECIMAL
		string hex, hexIndex;
		decimal = 0;
		cout << "Please input a valid hexadecimal value >  ";
		cin >> hex;
		int x = (hex.length() - 1);//descending increment from left to right.(index of letters from user input)
		for (i = 0; i < hex.length(); i++)
		{							//hexadecimal to decimal calculation
			hexIndex = hex.at(i);
			if (hexIndex == "A" || hexIndex == "a")
				decimal = decimal + (10 * pow(16, x));
			else if (hexIndex == "B" || hexIndex == "b")
				decimal = decimal + (11 * pow(16, x));
			else if (hexIndex == "C" || hexIndex == "c")
				decimal = decimal + (12 * pow(16, x));
			else if (hexIndex == "D" || hexIndex == "d")
				decimal = decimal + (13 * pow(16, x));
			else if (hexIndex == "E" || hexIndex == "e")
				decimal = decimal + (14 * pow(16, x));
			else if (hexIndex == "F" || hexIndex == "f")
				decimal = decimal + (15 * pow(16, x));
			else					//stoi is string to int conversion, pow is 'to the power of' function.
				decimal = decimal + ((stoi(hexIndex) * pow(16, x)));
			x--;
		}
		cout << "Decimal: " << decimal;

		//TO BINARY
		decimalToBinary(decimal, binaryArray);
		cout << "\n\n";

		menu();
		break;
	}
	default:
	{
		cout << "\nERROR: you entered an invalid input, please input 2, 10 or 16. \n\n";
		numberConversion();
		break;
	}
	}
}

//	3
int upcCalculation(int code, int array[])
{
	//number seperation
	int checkDigit;
	array[0] = code / 100000 % 10;//1
	array[1] = code / 10000 % 10;//2
	array[2] = code / 1000 % 10;//3
	array[3] = code / 100 % 10;//4
	array[4] = code / 10 % 10;//5
	array[5] = code % 10;//6

	//check digit calculation	//7
	array[6] = ((array[0] + array[2] + array[4]) * 3) + (array[1] + array[3] + array[5]);
	array[6] = (array[6] % 10);

	if (array[6] != 0)
		array[6] = (10 - array[6]);

	checkDigit = array[6];
	return checkDigit;
}

//	4
void upcCalc()
{
	int userCode;
	int upc[7] = { };//array initialisation
	do
	{
		cout << "Please enter a 6 digit product code >  ";
		cin >> userCode;
		if (userCode > 999999)//check for only 6 digits
		{
			cout << "\nERROR: Please input a 6 DIGIT code\n";
		}
	} while (userCode > 999999);
	upcCalculation(userCode, upc);

	cout << "Your 7 digit UPC code is: ";
	for (int i = 0; i < 7; i++)
		cout << upc[i];
	cout << "\n\n";
	menu();
}

//	5
void upcCheck()
{
	int userCode;
	int checkDigit;
	int upc[7] = { };//0 in brackets if error
	do
	{
		cout << "Please input a 7 digit upc code to check >  ";
		cin >> userCode; 
		if (userCode > 9999999)//number of digits check
		{
			cout << "\nERROR: Please input a 7 DIGIT code\n";
		}
	} while (userCode > 9999999);
	
	checkDigit = userCode % 10;//seperating check digit and assigning it to a variable
	userCode = userCode / 10;

	upcCalculation(userCode, upc);
	if (checkDigit == upcCalculation(userCode, upc))
		cout << "Correct 7 digit code \n\n";
	else
		cout << "Incorrect upc\n\n";
	menu();
}

