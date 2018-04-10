#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include "lex.cpp"
using namespace std;

void list();
void term();
void x();
void match(char);
void print(char);

token lookahead;

void print_char(char c){
    print("%c",)
}
// string input;
// int pos = 0;

//char next peek ou next char

// char nextToken(){
//     if(pos < input.length()){
//         return input[pos++];
//     }
//     else{
//         return EOF;
//     }
// }

void list(){
    term();
    x();
}

void x(){
      if (lookahead.type == 'PLUS') {
        match(PLUS); term(); print('+'); x();
    }
    else if (lookahead.type == MINUS){
        match(MINUS); term(); print('-'); x();
    }
    else if (lookahead.type == EOF){
        printf("\nSuccesso.\n");
    }
    else {
        printf("Syntax error on x\n");
        exit(1);
    }
}

void term(){
    // if (isalpha(lookahead)){ //var
    //     match(lookahead);
    // } else
    
    if (isdigit(lookahead.type == NUM)) {
        print(lookahead.value);
        match(NUM);
    }
    else {
        printf("Syntax error on term\n");
        exit(1);
    }
}

void match(int type){
    //printf("match %c\n", s);
    if(lookahead.type == type){
        lookahead = next_token();
    }
    else{
        printf("Match Error");
    }
}

int main(){
    input = "123-321+111";
    lookahead = nextToken();
    list();
}