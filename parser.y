%{


#include "ast.h"

int yylex();
extern int yyparse();
 FILE* yyin;
char identifier[90];
int value;
float value1;
void yyerror(const char *s);	


%}

%union {
	int ival;
	float fval;
	struct integer_float_values integer_float_values1;
	struct function_args_list function_args_list1;
	struct function_linked_list function_linked_list1;
}

%token <ival> INTEGER
%token <fval> FLOATINGPOINT
%token <ival> INT
%token <ival> FLOAT
%token <ival> STRING
%token VOID IF ELSE FOR ASSIGN OPENING_PARANTHESES CLOSING_PARANTHESES OPEN_BRACES CLOSING_BRACES WHILE IDENTIFIER SEMICOLON OPERATOR_SUBTRACT OPERATOR_MULTIPLY OPERATOR_ADD OPERATOR_DIVIDE OPERATOR_LESSTHAN OPERATOR_GREATERTHAN OPERATOR_LE OPERATOR_GE OPERATOR_COMPARISON OPERATOR_COMMA
%left OPERATOR_SUBTRACT OPERATOR_ADD
%left OPERATOR_DIVIDE OPERATOR_MULTIPLY
%left OPENING_PARANTHESES CLOSING_PARANTHESES

%type <integer_float_values1> expr
%type <ival> var_decl1
%type <integer_float_values1> ident
%type <function_args_list1> args noargs args1
%type <function_linked_list1> func_decl_ident
%%

stmts : 
	|	decl_stmts  stmts
		;

decl_stmts: SEMICOLON
	|		var_decl 
	| 	fun_decl
	;

var_decl: var_decl1 IDENTIFIER SEMICOLON { printf("Found variable declaration\n"); variable_declare($1,identifier);}
		;

fun_decl: fun_decl1 OPEN_BRACES function_definition CLOSING_BRACES { }
		;

fun_decl1: var_decl1 func_decl_ident OPENING_PARANTHESES args CLOSING_PARANTHESES { addtofunctions($1,$2,$4); addfunctions($1,$2,$4); }
		;

args: noargs
	| args1
	;
noargs: { integer_float_values a; $$ = addtofunctionargs1(9,a); }
	;

args1: var_decl1 ident { $$ = addtofunctionargs1($1,$2); }
	| var_decl1 ident OPERATOR_COMMA args1 { $$ = addtofunctionargs($1,$2,$4); }  

function_definition: 
	|	var_decl function_definition
	|	expr SEMICOLON function_definition { printf("%d ",$1); expression($1);  }
	|   expr1 SEMICOLON function_definition
	;

expr1: ident ASSIGN expr { identifier_value_expression($1,$3); }

expr: INTEGER { $$ = integer_parse_tree(value); }
	| FLOATINGPOINT { $$ = float_parse_tree(value1); }
	| IDENTIFIER { $$ = integer_float_values_identifier(identifier); }
	| expr OPERATOR_ADD expr  { $$ = expression_parse_tree_addition($1,$3); }
	| expr OPERATOR_SUBTRACT expr { $$ = expression_parse_tree_subtraction($1,$3); }
	| expr OPERATOR_MULTIPLY expr { $$ = expression_parse_tree_multiplication($1,$3); }
	| expr OPERATOR_DIVIDE expr { $$ = expression_parse_tree_division($1,$3); }  
	| OPENING_PARANTHESES expr CLOSING_PARANTHESES { $$ = $2; }
	;

ident: IDENTIFIER { $$ = integer_float_values_identifier(identifier); }

func_decl_ident: IDENTIFIER { $$ = addtofunctions1(identifier); }

var_decl1 :  INT { $$ = 0; }
	  | FLOAT { $$ = 1; }
 	  | STRING { $$ = 2; }



%%



int main(){
	yyin = fopen("token","r");
	start();
	while(yyin!=NULL){
		yyparse();
	}
	
    char *error = NULL;
    LLVMVerifyModule(mod, LLVMAbortProcessAction, &error);
    LLVMDisposeMessage(error);


    LLVMExecutionEngineRef engine;
    error = NULL;
    LLVMInitializeNativeAsmPrinter();
    LLVMLinkInMCJIT();
    LLVMInitializeNativeTarget();
    if (LLVMCreateExecutionEngineForModule(&engine, mod, &error) != 0) {
        fprintf(stderr, "failed to create execution engine\n");
        abort();
    }
    if (error) {
        fprintf(stderr, "error: %s\n", error);
        LLVMDisposeMessage(error);
        exit(EXIT_FAILURE);
    }

    int (*sum_func)() = (int (*)())LLVMGetFunctionAddress(engine, "main");
    printf("%d\n", sum_func());
    // Write out bitcode to file
    if (LLVMWriteBitcodeToFile(mod, "sum.bc") != 0) {
        fprintf(stderr, "error writing bitcode to file, skipping\n");
    }
    LLVMDisposeBuilder(builder);
    LLVMDisposeExecutionEngine(engine);
	return 0;
}

void yyerror(const char* s){
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}

int yylex(){
	int temp;
	if(fscanf(yyin,"%d",&temp) == -1){
		yyin = NULL;
		return -1;
	}
	if(temp == IDENTIFIER ){
		fscanf(yyin,"%s",identifier);
	}
	else if(temp == INTEGER){
		fscanf(yyin,"%d",&value);
	}
	else if(temp == FLOATINGPOINT){
		fscanf(yyin,"%f",&value1);
	}
	printf("%d ",temp);
	return temp;
}
