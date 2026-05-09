#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <cctype>

using namespace std;

//Node struct
struct Node {
    string data;
    Node* left;
    Node* right;

    Node(string val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

//Prototypes
string shuntingYard(string eqn);
bool isOperator(char c);
Node* buildBinaryTree(string postfix);
int evaluateTree(Node* root);

//Main
int main(){
    
    vector<string> TestEqns = {
        "(16+2)*5-28/4",
        "(16+2)/3-(3*(5-2))",
        "15 - 5*2  - (5*(7-5))",
        "(1+1+1+1+1)*10"
    };

    for(int i = 0; i < TestEqns.size(); i++){
        cout << "Infix:   " << TestEqns[i] << endl;
        
        string postfix = shuntingYard(TestEqns[i]);
        cout << "Postfix: " << postfix << "\n";
        
        Node* root = buildBinaryTree(postfix);
        if (root != nullptr) {
            cout << "The value of the expression is is: " << evaluateTree(root) << "\n\n"; 
        }
    }

    return 0;
}

//Function definitions
string shuntingYard(string eqn){
    stack<char> ops;
    string postfix = "";

    for(int i = 0; i < eqn.size(); i++) {
        char c = eqn[i];

        if (isspace(c)) continue;
        
        if (isdigit(c)){
            while (i < eqn.size() && isdigit(eqn[i])) {
                postfix += eqn[i]; 
                i++;               
            }
            postfix += " ";
            i--;
        }
        
        if (c == '*' || c == '/'){
            while(!ops.empty() && (ops.top() == '*' || ops.top() == '/')){
                postfix += ops.top();
                postfix += " ";
                ops.pop();
            }
            ops.push(c);
        }
        
        if (c == '+' || c == '-'){
            while(!ops.empty() && isOperator(ops.top())){
                postfix += ops.top();
                postfix += " ";
                ops.pop();
            }
            ops.push(c);
        }

        if (c == '(') ops.push(c);

        if (c == ')'){
            while(!ops.empty() && ops.top() != '('){
                postfix += ops.top();
                postfix += " ";
                ops.pop();
            }
            if(!ops.empty() && ops.top() == '(') ops.pop(); 
        }
    }

    while(!ops.empty()){
        postfix += ops.top();
        postfix += " ";
        ops.pop();
    }

    return postfix;
}

bool isOperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

Node* buildBinaryTree(string postfix){
    stack<Node*> expressions;
    string token = "";

    for(int i = 0; i < postfix.size(); i++) {
        char c = postfix[i];

        if(!isspace(c)){
            token += c;
            continue;
        }
        
        if (token == "") {
            continue;
        }

        if(!isOperator(token[0])){ 
            expressions.push(new Node(token)); 
            token = "";
            continue;
        }

        Node* newExp = new Node(token);

        newExp->right = expressions.top();
        expressions.pop();

        newExp->left = expressions.top();
        expressions.pop();

        expressions.push(newExp);
        
        token = ""; 
    }
    
    return expressions.top();
}

int evaluateTree(Node* root) {
    stack<Node*> s1;
    stack<Node*> s2;
    
    s1.push(root);
    
    while(!s1.empty()){
        Node* top = s1.top();
        s1.pop();
        s2.push(top);
        
        if(top->left) {
            s1.push(top->left);
        }
        if(top->right) {
            s1.push(top->right);
        }
    }

    stack<int> math;

    while(!s2.empty()) {
        Node* top = s2.top();
        s2.pop();
        
        if(!isOperator(top->data[0])){
           math.push(stoi(top->data));
        }
        if(top->data[0] == '+'){
            int n1 = math.top();
            math.pop();
            int n2 = math.top();
            math.pop();
            math.push(n1+n2);
        }
        if(top->data[0] == '-'){
            int n1 = math.top();
            math.pop();
            int n2 = math.top();
            math.pop();
            math.push(n2-n1);
        }
        if(top->data[0] == '*'){
            int n1 = math.top();
            math.pop();
            int n2 = math.top();
            math.pop();
            math.push(n1*n2);
        }
        if(top->data[0] == '/'){
            int n1 = math.top();
            math.pop();
            int n2 = math.top();
            math.pop();
            math.push(n2/n1);
        }
    }
    return math.top();
}