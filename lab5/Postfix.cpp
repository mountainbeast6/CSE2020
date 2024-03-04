#include "Postfix.h"
#include "Vector.h"
#include "Stack.h"
#include <sstream>
#include <cassert>
#include <cctype>

using namespace std;

// returns integer result of evaluation
// of string postfix expression

int eval_postfix(string postfix)
{
	Stack<Vector<int> > stack;
	string next;
	int num;
	int result;

	istringstream istrm(postfix);
	istrm >> next;

	while (!istrm.fail())
	{
		if (isalnum(next[0]))
		{
			num = string_to_integer(next);
			stack.push(num);
			cout << "push onto stack" << endl << endl;
		}
		else
		{
			assert(is_operator(next));
			cout << "operator " << next << " to be applied ..." << endl << endl;
			int x2 = stack.top();
			stack.pop();
			cout << "... pop " << x2 << endl << endl;

			int x1 = stack.top();
			stack.pop();
			cout << "... pop " << x1 << endl << endl;

			result = apply_op(next, x1, x2);
			stack.push(result);
			cout << " --> push " << result << " onto stack" << endl << endl;
		}
		istrm >> next;
	}
	assert(stack.size() == 1);
	result = stack.top();
	stack.pop();

	return result;
}

// converts string of digits to integer value
int string_to_integer(string x)
{
	istringstream istrm(x);
	int num;
	istrm >> num;
	return num;
}

// true when string is an operator symbol
bool is_operator(string x){
	if((x=="*")||(x=="%")||(x=="/")||(x=="^")||(x=="+")||(x=="-")){
		return true;
	}
	return false;
}

// returns value after operator op applied to
// int operands x and y
int apply_op(string op, int x, int y)
{
	if (op=="*") {
		return(y*x);
	}
	else if(op=="%"){
		return(y%x);
	}
	else if(op=="/"){
		return(y/x);
	}
	else if(op=="^"){
		int temp =y;
		for(int i=0; i<x; i++){
			y*=temp;
		}
		return y;
	}
	else if(op=="+"){
		return(y+x);
	}
	return(y-x);
}
