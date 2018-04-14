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