//#include <iostream>
//#include <cmath>
//#include <string>
//#include <iomanip>
//using namespace std;
//
//static int precedency(char op)
//{
//    if (op == '!')
//        return 3;
//    if (op == '&' || op == '|')
//        return 2;
//    if (op == '>')
//        return 1;
//    if (op == '^')
//        return 0;
//    return -1;
//}
//
//static bool cheeck_operator(char c)
//{
//    return c == '!' || c == '&' || c == '|' || c == '>' || c == '^';
//}
//
//static string infix_to_postfix(string expr)
//{
//    char stack[100]{};
//    int top = -1;
//    string postfix = "";
//
//    for (char c : expr)
//    {
//        if (isalnum(c))
//        {
//            postfix += c;
//        }
//        else if (c == '(')
//        {
//            stack[++top] = c;
//        }
//        else if (c == ')')
//        {
//            while (top != -1 && stack[top] != '(')
//            {
//                postfix += stack[top--];
//            }
//            if (top != -1 && stack[top] == '(')
//            {
//                top--;
//            }
//        }
//        else if (cheeck_operator(c))
//        {
//            while (top != -1 && precedency(stack[top]) >= precedency(c))
//            {
//                postfix += stack[top--];
//            }
//            stack[++top] = c;
//        }
//    }
//
//    while (top != -1)
//    {
//        postfix += stack[top--];
//    }
//    return postfix;
//}
//
//void truth_table_generator(int numVariables, int truthTable[][10])
//{
//    int rows = pow(2, numVariables);
//    for (int i = 0; i < rows; i++)
//    {
//        for (int j = 0; j < numVariables; j++)
//        {
//            truthTable[i][j] = (i / (int)pow(2, numVariables - j - 1)) % 2;
//        }
//    }
//}
//
//static string change_variables(string expr, int values[], char varNames[], int numVariables)
//{
//    for (int i = 0; i < numVariables; i++)
//    {
//        for (size_t j = 0; j < expr.size(); j++)
//        {
//            if (expr[j] == varNames[i])
//            {
//                expr[j] = values[i] + '0';
//            }
//        }
//    }
//    return expr;
//}
//
//int postfix_evaluation(string expr)
//{
//    int stack[100];
//    int top = -1;
//    for (char c : expr)
//    {
//        if (c == '0' || c == '1')
//        {
//            stack[++top] = c - '0';
//        }
//        else if (c == '!')
//        {
//            int a = stack[top--];
//            stack[++top] = !a;
//        }
//        else
//        {
//            int b = stack[top--];
//            int a = stack[top--];
//
//            if (c == '&') 
//                stack[++top] = a & b;
//            else if (c == '|') 
//                stack[++top] = a | b;
//            else if (c == '>') 
//                stack[++top] = (!a) | b;
//            else if (c == '^')
//                stack[++top] = (a == b);
//        }
//    }
//    return stack[top];
//}
//
//void instructions()
//{
//    cout << "Instructions:\n";
//    cout << "Use ! for NOT operations\n";
//    cout << "Use & for AND operations\n";
//    cout << "Use | for OR operations\n";
//    cout << "Use > for Implies operations\n";
//    cout << "Use ^ for Biconditional operations\n";
//    cout << "Use only () parenthesis :\n";
//    cout << endl;
//}
//
//int main()
//{
//    int numVariables, rows;
//    char varNames[10]{};
//    string exprA, exprB;
//
//    instructions();
//    cout << "Enter number of variables: ";
//    cin >> numVariables; cout << endl;
//    rows = pow(2, numVariables);
//
//    cout << "Enter the variables names (e.g: p,q,r): \n";
//    for (int i = 0; i < numVariables; i++)
//    {
//        cout << "Enter " << i + 1 << " varible: "; cin >> varNames[i];
//    }
//    cout << endl;
//
//    cout << "Enter Expression 1: "; cin >> exprA;
//    cout << "Enter Expression 2: "; cin >> exprB;
//    exprA = infix_to_postfix(exprA);
//    exprB = infix_to_postfix(exprB);
//
//    int truthTable[1024][10];
//    truth_table_generator(numVariables, truthTable);
//    bool equivalent = true;
//
//    cout << "\nTruth Table:\n";
//    for (int i = 0; i < numVariables; i++)
//    {
//        cout << setw(3) << varNames[i] << " | ";
//    }
//    cout << setw(10) << "Expr1" << " | " << setw(10) << "Expr2" << " |\n";
//    cout << string(numVariables * 5 + 25, '-') << endl;
//
//    for (int i = 0; i < rows; i++)
//    {
//        string exprAReplaced = change_variables(exprA, truthTable[i], varNames, numVariables);
//        string exprBReplaced = change_variables(exprB, truthTable[i], varNames, numVariables);
//        int result1 = postfix_evaluation(exprAReplaced);
//        int result2 = postfix_evaluation(exprBReplaced);
//
//        for (int j = 0; j < numVariables; j++)
//        {
//            cout << setw(3) << truthTable[i][j] << " | ";
//        }
//        cout << setw(10) << result1 << " | " << setw(10) << result2 << " |\n";
//
//        if (result1 != result2)
//        {
//            equivalent = false;
//        }
//    }
//
//    cout << endl;
//    if (equivalent)
//        cout << "Both expressions are logically equivalent." << endl;
//    else
//        cout << "Expressions are NOT logically equivalent." << endl;
//
//    cout << endl << endl;
//    system("pause");
//    return 0;
//}
