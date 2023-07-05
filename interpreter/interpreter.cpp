/**
 * @author: hong
 * @date: 2023/7/4 07:39
 * @description:
 */

#include <map>
#include <utility>
#include <vector>
#include <iostream>

class Expression {
public:
    virtual int interpret(std::map<char, int>) = 0;
    virtual ~Expression()= default;
};

class TerminalExpression: public Expression{
private:
    char _key;
public:
    TerminalExpression(char key): _key(key){}

    int interpret(std::map<char, int> var) override{
        return var[_key];
    }
};

class AddExpression: public Expression{
private:
    Expression* _left;
    Expression* _right;
public:
    AddExpression(Expression* left, Expression* right): _left(left), _right(right){}

    int interpret(std::map<char, int> var) override{
        return _left->interpret(var) + _right->interpret(var);
    }
};

class SubExpression: public Expression{
private:
    Expression* _left;
    Expression* _right;
public:
    SubExpression(Expression* left, Expression* right): _left(left), _right(right){}

    int interpret(std::map<char, int> var) override{
        return _left->interpret(var) - _right->interpret(var);
    }
};

void release(std::vector<Expression*>& vec){
    for (std::vector<Expression*>::iterator it = vec.begin(); it != vec.end(); it++){
        delete *it;
        *it = nullptr;
    }
    vec.clear();
}

int analysis(char expr[], std::map<char, int> var){
    std::vector<Expression*> vec;
    int index = -1;

    Expression* left = nullptr;
    Expression* right = nullptr;

    for (int i=0; i< strlen(expr); i++){
        switch (expr[i]) {
            case '+':
                left = vec[index];
                right = new TerminalExpression(expr[++i]);
                vec.push_back(right);
                vec.push_back(new AddExpression(left, right));
                index += 2;
                break;
            case '-':
                left = vec[index];
                right = new TerminalExpression(expr[++i]);
                vec.push_back(right);
                vec.push_back(new SubExpression(left, right));
                index += 2;
                break;
            default:
                vec.push_back(new TerminalExpression(expr[i]));
                index++;
        }
    }

    int result = vec[index]->interpret(std::move(var));

    release(vec);

    return result;
}


int main(){
    const char expr[] = "a-b+c";
    std::map<char, int> var;
    var.insert(std::make_pair('a', 9));
    var.insert(std::make_pair('b', 2));
    var.insert(std::make_pair('c', 10));

    int result = analysis(const_cast<char *>(expr), var);
    std::cout << result << std::endl;
}