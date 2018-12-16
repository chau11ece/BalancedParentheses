/*
    author: vanchautran11ece@gmail.com
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

///Functions to check whether two characters are OPENING and CLOSING of same type.
/// e.g. [] -> balanced string
///         }{ -> unbalanced string

bool ArePair(char opening, char closing)
{
    if (opening == '(' && closing == ')')
        return true;
    else if (opening == '{' && closing == '}')
        return true;
    else if (opening == '[' && closing == ']')
        return true;
    else
        return false;
}

bool AreParenBalanced(string exp)
{
    stack<char> S;

    /// If string length is odd, -> unbalanced string.
    if (exp.length() % 2 != 0)
        return false;

    for (unsigned int i = 0; i < exp.length(); ++i)
    {
        if (exp[i]  == '(' || exp[i] == '{' || exp[i] == '[')
            S.push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (S.empty() || !ArePair(S.top(), exp[i]))
                return false;
            else
                S.pop();    /// Remove the latest matched parentheis
        }
    }

    /// true if stack is empty; otherwise false.
    return S.empty()? true:false;
}

int main()
{
    //Testing function AreParenBalanced
    string expression;
    cout << "Enter an expression: ";
    cin >> expression;

    if (AreParenBalanced(expression))
        cout << "Balanced!\n";
    else
        cout << "Unbalanced!\n";
}
