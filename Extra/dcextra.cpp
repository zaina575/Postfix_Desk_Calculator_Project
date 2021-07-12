#include <iostream>
#include <cstring>
#include <cctype>
#include "stack.h"
#include <stdio.h>
#include <stdlib.h> 
#include <string>
//#include <sstream>
//#include <vector>
#include "dsexceptions.h"
using namespace std;

void commandP(Stack <int> a); //commandP prototype
void commandN(Stack <int> &a); //commandN prototype
void commandF(Stack <int> a); //commandF prototype
void commandC(Stack <int> &a); //commandC prototype
void commandD(Stack <int> &a); //commandD prototype
void commandR(Stack <int> &a); //commandR prototype
void add(Stack <int> &a); //add prototype
void subtract(Stack<int> &a); //subtract prototype
void multiply(Stack<int> &a); //multiply prototype
void divide(Stack <int> &a); //divide prototype
void mod(Stack <int> &a); //mod prototype
bool isOperator(char ch); //isOperator prototype
bool isCommand(char ch); //isCommand prototype
bool isUnderscore(char ch); //isUnderscore prototype
void runOperator(Stack <int> &a,char ch); //runOperator prototype
void runCommand(Stack <int> &a, char ch); //runCommand prototype
void inputLine(Stack <int> &a); //inputLine prototype
void processLine(Stack <int> &a, char line[]); //processLine prototype
bool isValidOperation(char ch); //isValidOperation prototype
bool isValidExpression(char a[]); //isValidExpression prototype

int main(){
//	 cout << "\033[1;31mbold red text\033[0m\n";
	Stack <int> stack1; //stack integer declared
	inputLine(stack1); //call to inputLine method
return 0;}


//Pre: An empty stack of integers will be passed in.
////Post: All input will be taken in and processed till the user hits control D.
void inputLine(Stack<int> &a){
	string input;


	char line[100];
	while(getline(cin,input)){



	strcpy(line,input.c_str());
	try{

	processLine(a,line);
        if(!isValidExpression(line)){
                throw InvalidExpression();

        }}


catch(Overflow obj) {


             cout << "\033[1;31mIllegal Push -- Stack is Full.\033[0m" << endl;}

catch(InvalidExpression obj){

   cout << "\033[1;31mException -- You have entered an invalid expression.  Please re-enter.\033[0m" << endl;
}

memset(line,0,100);

}}


//Pre: A stack of valid integers will be passed in and a valid character array will be passed in.
//////Post: All input will be taken in and processed till the user hits control D.

void processLine(Stack <int> &a,char line[]){

try{
	for(int i = 0; i<strlen(line); i++){

           if(!(isValidOperation(line[i]))){
               int space = i;

                        for(int j = space; j < strlen(line); j++){

                        if(isspace(line[j])){
                        i = j;
			break;
                       }

	
			i = strlen(line);
				continue;
		}
                }

			if(isUnderscore(line[i])){
					
				if(i+1 != strlen(line)){
					
					if(isdigit(line[i+1])){

						string newneg = "-";


						while(isdigit(line[i+1])){

							newneg += line[i+1];
							i++;}


						int negone = atoi(newneg.c_str());		
						a.push(negone);

				}}


			else{
				a.push(0);
			
			}


				}
			
		else{

			if(isdigit(line[i])){


				string newnum;

			while(isdigit(line[i])){


			
				newnum+=line[i];
				i++;}
			int newone = atoi(newnum.c_str());
			a.push(newone);	

		}}


		if(isOperator(line[i])){

			runOperator(a, line[i]);
			}


			
	
		if(isalpha(line[i])){

			if(isCommand(line[i])){
			
			runCommand(a,line[i]);
	

		}}
		}


}

catch(Overflow obj) {

	      cout << "\033[1;31mIllegal Push -- Stack is Full.\033[0m" << endl;}
//             cout << "Illegal Push -- Stack is Full." << endl;}

catch(InvalidExpression obj){

	 cout << "\033[1;31mException -- You have entered an invalid expression.  Please re-enter.\033[0m" << endl;

//   cout << "Exception -- You have entered an invalid expression.  Please re-enter." << endl;
	}

}



//Pre: A stack of valid integers will be passed in.
////////Post: It will print the top value of the stack if there is one without altering the stack.
void commandP(Stack <int> a){
	try{
		 cout <<"\033[1m\033[34m";
		cout << a.top() << endl; 
		cout << "\033[0m";

	}
catch(Underflow obj) {
                cout << "\033[1;31mIllegal Pop -- Stack is Empty.\033[0m" << endl;

        }
}



//Pre: A stack of valid integers will be passed in.
//////////Post: It will pop off the top value of the stack if there is and  alter the stack.

void commandN(Stack <int> &a){
	try{
		cout << "\033[1m\033[35m";
		cout << a.top();
		 cout << "\033[0m";

		a.pop();	}
catch(Underflow obj) {

		 cout << "\033[1;31mIllegal Pop -- Stack is Empty.\033[0m" << endl;


         //       cout << "Illegal Pop -- Stack is Empty." << endl;

        }
}
//Pre: A stack of valid integers will be passed in.
////////////Post: It will print the entire contents of the stack if the stack is not empty.

void commandF(Stack <int> a){

	while(!a.isEmpty()){

		cout << "\033[1m\033[32m";
		cout<< a.top() << endl;
		cout << "\033[0m";
		a.pop();
	}
}
//Pre: A stack of valid integers will be passed in.
//////////////Post: It will clear the contents of the stack.
void commandC(Stack <int> &a){

	a.makeEmpty();

}

//Pre: A stack of valid integers will be passed in.
//////////////Post: It will duplicate the top of value of the stack if there is one and will duplicate only if there is space to.

void commandD(Stack <int> &a){
	
	try{
	a.push(a.top());

}
  catch(Overflow obj) {


                cout << "\033[1;31mIllegal Push -- Stack is Full.\033[0m" << endl;

}
catch(Underflow obj) {

		 cout << "\033[1;31mIllegal Pop -- Stack is Empty.\033[0m" << endl;

//                cout << "Illegal Pop -- Stack is Empty." << endl;

        }
}
//Pre: A stack of valid integers will be passed in.
//////////////Post: It will reverse the top two values on the stack if the stack is not empty.
void commandR(Stack <int> &a){
	int oldtop = 0;
	int newtop = 0;

	try{


		oldtop = a.top();
		a.pop();
		newtop = a.top();
		a.pop();
		a.push(oldtop);
		a.push(newtop);

	}
catch(Underflow obj) {
 

 cout << "\033[1;31mIllegal Pop -- Stack is Empty.\033[0m" << endl;

//               cout << "Illegal Pop -- Stack is Empty." << endl;

        }

}
//Pre: A stack of valid integers will be passed in.
//////////////Post: It will pop off the the top two values on the stack and push the sum if there are two values.
void add(Stack <int> &a){

	try{

	int first = 0;
	int second = 0;
	int sum = 0;



		first = a.top();
		a.pop();
		second = a.top();
		a.pop();
		sum = second+first;


		a.push(sum);

}
catch(Underflow obj) {

	 cout << "\033[1;31mIllegal Pop -- Stack is Empty.\033[0m" << endl;

//		cout << "Illegal Pop -- Stack is Empty." << endl;

	}


}

//Pre: A stack of valid integers will be passed in.
////////////////Post: It will pop off the the top two values on the stack and subtract them and push the answer if there are two values.
void subtract(Stack <int> &a){
try{
        int first = 0;
        int second = 0;
	int answer = 0;

		first = a.top();
                a.pop();
                second = a.top();
               	a.pop();
		answer = second-first;

                a.push(answer);
 
       }
catch(Underflow obj) {

	 cout << "\033[1;31mIllegal Pop -- Stack is Empty.\033[0m" << endl;

//                cout << "Illegal Pop -- Stack is Empty." << endl;

        }


}
//Pre: A stack of valid integers will be passed in.
//////////////////Post: It will pop off the the top two values on the stack and multiply them and push the answer if there are two values.
void multiply(Stack <int> &a){

try{
        int first = 0;
        int second = 0;
	int answer = 0;
                first = a.top();
                a.pop();
                second = a.top();
                a.pop();
		answer = second * first;

                a.push(answer);

  
   }
catch(Underflow obj) {
 
 cout << "\033[1;31mIllegal Pop -- Stack is Empty.\033[0m" << endl;

//               cout << "Illegal Pop -- Stack is Empty." << endl;

        }
}
//Pre: A stack of valid integers will be passed in.
//////////////////Post: It will pop off the the top two values on the stack and divide them and push the answer if there are two values.
void divide(Stack <int> &a){

try{
        int first = 0;
        int second = 0;
        int answer = 0;
		first = a.top();
		if(first==0){
			throw DivisionByZero();
		}
                a.pop();
        	second = a.top();
                a.pop();
                answer = second / first;

                a.push(answer);

     }
catch(Underflow obj) {

 cout << "\033[1;31mIllegal Pop -- Stack is Empty.\033[0m" << endl;


//                cout << "Illegal Pop -- Stack is Empty." << endl;

        }
catch(DivisionByZero obj){
		cout<< "\033[1;31mDivision By Zero Exception -- Stack Unchanged.\033[0m" << endl;
	}
}
//Pre: A stack of valid integers will be passed in.
//////////////////Post: It will pop off the the top two values on the stack and find the remainder of them and push the answer 
//if there are two values.
void mod(Stack <int> &a){
 try{
	int first = 0;
        int second = 0;
        int answer = 0;
        string answer1 = "";
                first = a.top();
                a.pop();
                second = a.top();
                a.pop();
                answer = second % first;

          

                a.push(answer);

 		}
catch(Underflow obj) {
//                cout << "Illegal Pop -- Stack is Empty." << endl;

	 cout << "\033[1;31mIllegal Pop -- Stack is Empty.\033[0m" << endl;



        }
}
//Pre: A valid character will be passed in.
////////////////////Post: It will return a boolean if it matches one of the operators.
bool isOperator(char ch){
	if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%'){

		return true;
}
	else
		return false;
}

//Pre: A valid character will be passed in.
//////////////////////Post: It will return a boolean if it matches one of the commands.

bool isCommand(char ch){
	if(ch == 'p' || ch == 'n' || ch == 'f' || ch == 'c' || ch == 'd' || ch == 'r'){
		return true;
	}	

	else
		return false;

}

//Pre: A valid character will be passed in.
//////////////////////Post: It will return a boolean if it an underscore.
//
bool isUnderscore(char ch){
	if(ch == '_'){

		return true;
	}

	else 
		return false;
}

//Pre: A stack of integers and a valid character will be passed in.
//////////////////////Post: It will run the operator.
void runOperator(Stack <int> &a, char ch){


			switch((ch)) //switch statement for each operator
                        {

                                case '+':{ 
                                add(a);

				break;}

                                case '-' : 
                                {
                                subtract(a);  break;} 

                                case '*' : 
                                {
                                multiply(a);  break;} 

                                case '/' : 
                                {
                                divide(a); break;}

                                case '%' : 
                                {
                                mod(a);  break;} 
                        }
}
//Pre: A stack of integers and a valid character will be passed in.
////////////////////////Post: It will run the command.
void runCommand(Stack <int> &a, char ch){
                        switch((ch)) //switch statement for each command
                        {

                                case 'p':{
				 commandP(a);  break;}

                                case 'n' :
                                {
                                commandN(a);  break;}

                                case 'f' :
                                {
                                commandF(a);  break;}

                                case 'c' :
                                {
                                commandC(a); break;}

                                case 'd' :
                                {
                                commandD(a);  break;}

				case 'r' :
				{
				commandR(a); break;}
                        }




}
//Pre: A valid character will be passed in.
////////////////////////Post: It will return a boolean if it is a valid operation.
//
bool isValidOperation (char ch){


bool isvalid = false;

if(isOperator(ch)){
	isvalid = true;
}

if(isCommand(ch)){
	isvalid = true;

}
if(isUnderscore(ch)){
       isvalid = true;
}

if(isdigit(ch)){

	isvalid = true;

}

if(isspace(ch)){
	isvalid = true;
}
return isvalid;}

//Pre: A valid character array  will be passed in.
//////////////////////////Post: It will return a boolean if it is a valid expression.
///
bool isValidExpression(char a[]){

	int val = 0;

	for(int i = 0; i< strlen(a); i++){

		if((!isOperator(a[i])) && (!isCommand(a[i])) & (!isdigit(a[i])) && (!isUnderscore(a[i])) && (!isspace(a[i]))){			
			val++;	
					
	}}
		if(val > 0){
			return false;

	}
		if(val == 0){
		return true;
	}

	}







