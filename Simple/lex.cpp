#include <cstdio>
#include <cctype>
#include <string>
#include <cstdlib>
#include <iostream>

#define NUM 256
#define PLUS 257
#define MINUS 258
#define ERR 1000

using namespace std;

struct token{
    int type;
    int value;
};

string input;
int pos = 0;

char get_char(){
    if(pos < input.length()){
        return input[pos++];
    }
    else{
        return EOF;
    }
}

token next_token(){
    token t;
    char peek = get_char();//le caracter de entrada
    //tratar espaços
    if(isdigit(peek)){//tratar inteiros e reais
        int v = 0;
        do{
            v = v * 10 + atoi(&peek);
            peek = get_char();
        } while(isdigit(peek));
        t.type = NUM;
        t.type = v;
        
    }
    else if(peek == '+'){
        t.type = PLUS;
    }
    else if(peek == '-'){
        t.type = MINUS;
    }
    else if(peek == EOF){
        t.type = EOF;
    }
    else{
        t.type = ERR;
    }
}

int main(){
    input = "123+321";
    token lookahead = next_token();
    while(lookahead.type!= EOF){
        cout << lookahead.type << endl;
        if(lookahead.type == NUM){
            cout << lookahead.value << endl;
        }
        cout << endl;
        lookahead = next_token();
    }
}

/*
//inputreader
int nextChar(){
    if (pos == -1)
        pos = 0;

    else if (pos == (int) input.length())
        return 0;
    return input[pos++];
}

//lexer
token scan(){
    token t;
    for (;;peek=nextChar()){
        if (peek != ' ' && peek != '\t' && peek != '\n')
            break;
    }

    if (isdigit(peek)){
        int v = 0;
        do {
            v = 10 * v + atoi(&peek);
            peek = nextChar();
        }
        while (isdigit(peek));
        t.type = NUMBER;
        t.value = v;
        return t;
    }

    t.type = SYMBOL;
    t.value = peek;
    peek = ' ';
    return t;
}


//parser
void match(token t){
    if (lookahead.type == t.type && lookahead.value == t.value){
        lookahead = scan();
    }
    else{
        printf("\n*** Syntax Error! Values do not match. *** \n");
        exit(0);
    }
}

int term(){
    if (lookahead.type == NUMBER){
        int v = lookahead.value;
        match(lookahead);
        return v;
    }
    else{
        printf("\n*** Syntax Error! '%c' it's not a number. ***\n", lookahead.value);
        exit(0);
    }
}

int expr(){
    int v = term();
    while(true){
        if (lookahead.type == SYMBOL){
            if (lookahead.value == '+'){
                match(lookahead); 
                v += term();
            }
            else if (lookahead.value == '-'){
                match(lookahead); 
                v -= term();
            }
            else{
                return v;
            }
        }
        else{
            return v;
        }
    }
}

int main(){
    printf("Expression: ");
    getline(cin, input);
    lookahead = scan();
    int x = expr();
    printf("Result: %d\n", x);
    
    return 0;
}
*/