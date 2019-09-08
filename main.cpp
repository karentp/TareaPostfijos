#include <cstdlib>
#include <iostream>
#include "Stack.h"
#include <math.h>

using namespace std;

int opcion;
void menu();
int getOperatorPriority(char);
string conversionPostfixes(string);
bool isOperator(char);
double evaluatePostfix(string);
double performOperation(char,double,double);
bool validateExpression(string);


int main()
{
    cout <<"Programa de expresiones Postfijas\n"<<endl;

    do{

        menu();
        switch(opcion){
            case 1:
            {
                cout<<"Ingrese la expresion a convertir:";
                string expression;
                cin.ignore();
                getline(cin,expression);
                cout<<"\n";
                if (validateExpression(expression)==true)
                    cout<<conversionPostfixes(expression)<<endl;
                else cout<<"Error de sintaxis en la expresión"<<endl;
                break;
            }
            case 2:{
                cout<<"Ingrese la expresion a evaluar:";
                string expression;
                cin.ignore();
                getline(cin,expression);
                cout<<"\n";
                cout<<evaluatePostfix(expression)<<endl;;
                break;
            }
            case 3:
                break;
            default:
                cout<<"Opcion invalida"<<endl;
                break;

        }
    } while(opcion!=3);


    return 0;
}
int getOperatorPriority(char charToEvaluate)
{
    switch(charToEvaluate){
        case '^':
            return 7;
            break;

        case '*':
            return 6;
            break;

        case '/':
            return 5;
            break;

        case '+':
            return 4;
            break;

        case '-':
            return 3;
            break;

        default:
            return 0;
            break;

    }
}


//Algoritmo de conversión
string conversionPostfixes(string expression)
{
    Node * deleted;
    string postfixResult="";
    //incicializar la pila
    Stack *pile= new Stack();

    //obtener caracter por caracter  para validar
    //la expresión
    unsigned int i=0;
    while(i<expression.size()){

        char charOfExpression=expression[i];

        if (charOfExpression == '(')
            pile->push(charOfExpression);

        else if(charOfExpression== ')')
        {
            while (pile->top->data!='(')
            {
                deleted= pile->pop();
                postfixResult +=deleted->data;
            }
            pile->pop();

        }
        else if (isOperator(charOfExpression))
        {
            int topPriority=0;
            int charPriority=0;

            if (!pile->isEmpty()){
                topPriority= getOperatorPriority(pile->top->data);
                charPriority= getOperatorPriority(charOfExpression);
            }

            if(pile->isEmpty()|| charPriority>topPriority)
                pile->push(charOfExpression);

            else
            {
                while(topPriority>=charPriority)
                {
                    deleted=pile->pop();
                    postfixResult +=deleted->data;
                    if(pile->top !=nullptr)
                        topPriority= getOperatorPriority(pile->top->data);
                    else break;
                }
                pile->push(charOfExpression);
            }
        }
        else if (isdigit(charOfExpression)){
            int operand = 0;
			while(i<expression.length()
                    && isdigit(expression[i])) {
				operand = (operand*10) + (expression[i]-'0');
				i++;
			}
			i--;
            postfixResult +=to_string(operand);
            postfixResult += " ";
        }
        else if(charOfExpression==' '){
            i++;
            continue;
        }
        else{
            cout<<"Hay un error en la expresión solo números y operandos son permitidos"<<endl;
            break;
            menu();
        }
        i++;

    }

while(!pile->isEmpty()){
    deleted=pile->pop();
    postfixResult +=deleted->data;
}

return postfixResult;
}

bool isOperator(char operatorExp)
{
	if(operatorExp == '+' || operatorExp == '-'
        || operatorExp == '*' || operatorExp == '/'
        || operatorExp == '^')
		return true;

	return false;
}

double evaluatePostfix(string postfixEpression){
    Stack * evalStack= new Stack;
    //for (int i=0; i<postfixEpression.size(); i++)
    int i=0;
    while(i<postfixEpression.size())
    {
        char charExpression= postfixEpression[i];

        if (charExpression ==' '){
            i++;
            continue;
        }

        else if (isOperator(charExpression))
        {
            double operand2= double(evalStack->popInt()->data);
            double operand1= double(evalStack->popInt()->data);
            double result = performOperation(charExpression,
                            operand1,operand2);
            evalStack->pushInt(double(result));
        }
        else if(isdigit(charExpression)){
            int operand = 0;

			while(i<postfixEpression.length()
                    && isdigit(postfixEpression[i])) {

				operand = (operand*10) + (postfixEpression[i]-'0');
				i++;
			}
			i--;
			evalStack->pushInt(operand*1.0);
        }
        i++;

    }

return double(evalStack->topInt->data);

}
double performOperation(char charOperator,
                        double operand1, double operand2){

    if(charOperator == '+') return operand1 +operand2;
	else if(charOperator == '-') return operand1 - operand2;
	else if(charOperator == '*') return operand1 * operand2;
	else if(charOperator == '/') return operand1 / operand2;
	else if(charOperator == '^') return pow(operand1,operand2);

	else cout<<"Unexpected Error \n";
}

bool pairParenthesis(char opening,char closing)
{
    if(opening == '(' && closing == ')')return true;
	else if(opening == '{' && closing == '}') return true;
	else if(opening == '[' && closing == ']') return true;
	return false;
}
bool checkParenthesesBalanced(string expression)
{
	Stack *parenthesesStack= new Stack();
	for(int i =0;i<expression.length();i++)
	{
	    char charExp= expression[i];
		if(charExp == '(' || charExp == '['
            || charExp == '{')
            parenthesesStack->push(charExp);

		else if(charExp == ')' || charExp == ']'
            || charExp == '}')
		{
			if(parenthesesStack->isEmpty()
            || !pairParenthesis(parenthesesStack->top->data,charExp))
				return false;

			else parenthesesStack->pop();
		}
	}
	if(parenthesesStack->isEmpty()) return true;
	else return false;
}


bool checkOperators(string expression){
    int i=0;

    while(i<expression.length())
	{
	    if (isOperator(expression[i]))
        {
            if(i==0 || i==(expression.length())-1)
                return false;
            else if(i+1 <=expression.length() -1)
            {
                if (isOperator(expression[i+1]))
                    return false;
            }
        }
        else if(!isOperator(expression[i])
                && !isdigit(expression[i]) && expression[i]!=' '
                && expression[i]!='('&& expression[i]!=')'){
            return false;
        }
        i++;
    }
    return true;
}
bool validateExpression(string expression){

    if(checkParenthesesBalanced(expression)==true
       && checkOperators(expression)==true){
           return true;
    }
    else {
        return false;
    }
}
void menu(){
    cout<<"\nOpciones:\n\n 1. Conversion\n2. Evaluacion\n3. Salir"<<endl;
    cout<<"Ingrese el numero de la opcion:";
    cin >>opcion;
}

