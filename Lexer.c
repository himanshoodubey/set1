#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//(void +|int +|float +|string +|if *(|else *{|for *(|while *(|+|-|*|/|;|((v|i|f|s|e|w|a)+(A|0)*)|(0)+|(0)*.(0)+)
//enum token{ INT, VOID, STRING, IF, ELSE, FOR, ASSIGN, OPENING_PARANTHESES, CLOSING_PARANTHESES, OPEN_BRACES, CLOSING_BRACES , WHILE, IDENTIFIER, INTEGER, FLOATINGPOINT, FLOAT, SEMICOLON, OPERATOR_SUBTRACT, OPERATOR_MULTIPLY, OPERATOR_ADD, OPERATOR_DIVIDE, OPERATOR_LESSTHAN, OPERATOR_GREATERTHAN, OPERATOR_LE, OPERATOR_GE, OPERATOR_COMPARISON };
enum token{
INTEGER = 258,
    FLOATINGPOINT = 259,
    INT = 260,
    FLOAT = 261,
    STRING = 262,
    VOID = 263,
    IF = 264,
    ELSE = 265,
    FOR = 266,
    ASSIGN = 267,
    OPENING_PARANTHESES = 268,
    CLOSING_PARANTHESES = 269,
    OPEN_BRACES = 270,
    CLOSING_BRACES = 271,
    WHILE = 272,
    IDENTIFIER = 273,
    SEMICOLON = 274,
    OPERATOR_SUBTRACT = 275,
    OPERATOR_MULTIPLY = 276,
    OPERATOR_ADD = 277,
    OPERATOR_DIVIDE = 278,
    OPERATOR_LESSTHAN = 279,
    OPERATOR_GREATERTHAN = 280,
    OPERATOR_LE = 281,
    OPERATOR_GE = 282,
    OPERATOR_COMPARISON = 283,
    OPERATOR_COMMA = 284
};
int dfa(char);
void main(){
	printf("Enter string: ");
	char arr[90];
	char arr1[99999];
	scanf("%s",arr);
	FILE *fp;
	fp = fopen(arr,"r");
	char a = fgetc(fp);
	int i=0;
	while(a!= EOF){
		arr1[i]=a;
		a=fgetc(fp);
		i++;
	}
	int temp = i;
	a=arr1[0];
	i=0;
	FILE *fp1 = fopen("token","w");
	while(i < temp){
		int temp = dfa(a);
		if(temp==INT){
			fprintf(fp1, "%d\n", INT  );
			printf("Found Integer : int\n");
			i--;
		}
		else if(temp==FLOAT){
			fprintf(fp1, "%d\n", FLOAT );
			printf("Found Float: float\n");
			i--;
		}
		else if(temp==VOID){
			fprintf(fp1, "%d\n", VOID );
			printf("Found Void: void\n");
			i--;
		}
		else if(temp==STRING){
			fprintf(fp1, "%d\n", STRING );
			printf("Found String: string\n");
			i--;
		}
		else if(temp==IF){
			fprintf(fp1, "%d\n", IF );
			printf("Found IF: if\n");
			i--;
		}
		else if(temp==ELSE){
			fprintf(fp1, "%d\n", ELSE );
			printf("Found ELSE: else\n");
			i--;
		}
		else if(temp==FOR){
			fprintf(fp1, "%d\n", FOR );
			printf("Found FOR: for\n");
			i--;
		}
		else if(temp==WHILE){
			fprintf(fp1, "%d\n", WHILE );
			printf("Found While: while\n");
			i--;
		}
		else if(temp==IDENTIFIER){
			fprintf(fp1, "%d", IDENTIFIER );
			printf("Found Identifier: ");
			i--;
			int temp = i;
			char identifier[90];
			char arr2[90];
			int i1=0;
			while((arr1[temp] >= '0' && arr1[temp] <= '9') || (arr1[temp] >= 'a' && arr1[temp] <= 'z') || (arr1[temp] >= 'A' && arr1[temp] <= 'Z')){
				identifier[i1]=arr1[temp];
				temp--;
				i1++;
			}
			i1 = i1 - 1;
			temp = 0;
			while(i1>=0){
				printf("%c",identifier[i1]);
				arr2[temp]=identifier[i1];
				temp++;
				i1--;
			}
			arr2[temp]='\0';
			fprintf(fp1," %s\n",arr2);
			printf("\n");
		}
		else if(temp==INTEGER){
			fprintf(fp1, "%d", INTEGER );
			printf("Found Integer: ");
			i--;
			int temp = i;
			char identifier[90];
			char arr2[90];
			int i1=0;
			while((arr1[temp] >= '0' && arr1[temp] <= '9')){
				identifier[i1]=arr1[temp];
				temp--;
				i1++;
			}
			i1 = i1 - 1;
			temp = 0;
			while(i1>=0){
				printf("%c",identifier[i1]);
				arr2[temp]=identifier[i1];
				temp++;
				i1--;
			}
			arr2[temp]='\0';
			fprintf(fp1," %s\n",arr2);
			printf("\n");
		}
		else if(temp == SEMICOLON){
			fprintf(fp1, "%d\n", SEMICOLON );
			printf("Found Semicolon\n");
			i--;
		}
		else if(temp==FLOATINGPOINT){
			fprintf(fp1, "%d", FLOATINGPOINT );
			printf("Found FloatingPoint: ");
			i--;
			int temp = i;
			char identifier[90];
			char arr2[90];
			int i1=0;
			while((arr1[temp] >= '0' && arr1[temp] <= '9') || (arr1[temp] == '.')){
				identifier[i1]=arr1[temp];
				temp--;
				i1++;
			}
			i1 = i1 - 1;
			temp = 0;
			while(i1>=0){
				printf("%c",identifier[i1]);
				arr2[temp]=identifier[i1];
				temp++;
				i1--;
			}
			arr2[temp]='\0';
			fprintf(fp1," %s\n",arr2);
			printf("\n");
		}
		else if(temp==OPERATOR_SUBTRACT || temp == OPERATOR_DIVIDE || temp == OPERATOR_ADD || temp == OPERATOR_MULTIPLY || temp == OPERATOR_COMPARISON || temp == OPERATOR_GREATERTHAN || temp == OPERATOR_LESSTHAN || temp == OPERATOR_LE || temp == OPERATOR_GE || temp == ASSIGN || temp == OPERATOR_COMMA){
			printf("Found Operator: ");
			i--;
			if(arr1[i]=='<'){
				fprintf(fp1,"%d\n",OPERATOR_LESSTHAN);
				printf("<");
			}
			else if(arr1[i] == '>'){
				fprintf(fp1,"%d\n",OPERATOR_GREATERTHAN);
				printf(">");
			}
			else if(arr1[i] == ','){
				fprintf(fp1,"%d\n",OPERATOR_COMMA);
				printf(",");
			}
			else if(arr1[i] == '+'){
				fprintf(fp1, "%d\n", OPERATOR_ADD );
				printf("+");
			}
			else if(arr1[i] == '-'){
				fprintf(fp1, "%d\n", OPERATOR_SUBTRACT );
				printf("-");
			}
			else if(arr1[i] == '*'){
				fprintf(fp1, "%d\n", OPERATOR_MULTIPLY );
				printf("*");
			}
			else if(arr1[i] == '/'){
				fprintf(fp1, "%d\n", OPERATOR_DIVIDE );
				printf("/");
			}
			else if(arr1[i] == '=' && arr1[i-1] == '>'){
				fprintf(fp1,"%d\n",OPERATOR_GE);
				printf(">=");
			}
			else if(arr1[i] == '=' && arr1[i-1] == '<'){
				fprintf(fp1,"%d\n",OPERATOR_LE);
				printf("<=");
			}
			else if(arr1[i] == '=' && arr1[i-1] == '='){
				fprintf(fp1,"%d\n",OPERATOR_COMPARISON);
				printf("==");
			}
			else if(arr1[i] == '='){
				fprintf(fp1, "%d\n", ASSIGN );
				printf("=");
			}
			else{
				printf("Unknown Operator");
				return;
			}
			printf("\n");
		}
		else if(temp == OPENING_PARANTHESES){
			fprintf(fp1,"%d\n",OPENING_PARANTHESES);
			printf("Found Opening Parantheses (\n");
			i--;
		}
		else if(temp == CLOSING_PARANTHESES){
			fprintf(fp1,"%d\n",CLOSING_PARANTHESES);
			printf("Found Closing Parantheses )\n");
			i--;
		}
		else if(temp == OPEN_BRACES){
			fprintf(fp1,"%d\n",OPEN_BRACES);
			printf("Found Opening Braces {\n");
			i--;
		}
		else if(temp == CLOSING_BRACES){
			fprintf(fp1,"%d\n",CLOSING_BRACES);
			printf("Found Closing Braces }\n");
			i--;
		}
		else if(temp == -1){
			printf("Keyword not found \n");
			int i1=i;
			while(arr1[i1-1]!=' ' && i1 >= 1){
				i1--;
			}
			while(i1<=i){
				printf("%c",arr1[i1]);
				i1++;
			}
			return;
		}
		i++;
		a = arr1[i];
	}
}
int dfa(char c){
	static int state = 0;
	/*printf("%c ",c);
	printf("%d \n",state);*/
	if(state == 0){
		if(c == '-'){
			state = 1;
		}
		else if(c == '.'){
			state = 2;
		}
		else if(c == '/'){
			state = 3;
		}
		else if(c >= '0' && c <= '9'){
			state = 4;
		}
		else if(c == ';'){
			state = 5;
		}
		else if(c == '*'){
			state = 6;
		}
		else if(c == '<'){
			state = 67;
		}
		else if(c == '>'){
			state = 70;
		}
		else if(c == '='){
			state = 68;
		}
		else if(c == ','){
			state = 73;
		}
		else if(c == 'v'){
			state = 13;
		}
		else if(c == 'i'){
			state = 11;
		}
		else if(c == 'f'){
			state = 9;
		}
		else if(c == 's'){
			state = 12;
		}
		else if(c == 'e'){
			state = 8;
		}
		else if(c == 'w'){
			state = 14;
		}
		else if(c >= 'a' && c <= 'z'){
			state = 7;
		}
		else if(c == '+'){
			state = 10;
		}
		else if(c == ' '){
			state = 0;
		}
		else if(c == '\n'){
			state = 0;
		}
		else if(c == '{'){
			state = 76;
		}
		else if(c == '}'){
			state = 77;
		}
		else if(c == '('){
			state = 74;
		}
		else if(c == ')'){
			state = 75;
		}
		else if(c == '\t'){
			state = 0;
		}
		else{
			return -1;
		}


	}
	else if(state == 1){
		state = 0;
		return OPERATOR_SUBTRACT;
	}
	else if(state == 2){
		if(c >= '0' && c <= '9'){
			state = 15;
		}
		else{
		return -1;
		}
	}
	else if(state == 3){
		state = 0;
		return OPERATOR_DIVIDE;
	}
	else if(state == 4 ){
		if(c == '.'){
			state = 2;
		}
		else if(c >= '0' && c <= '9'){
			state = 16;
		}
		else{
			state = 0;
			return INTEGER;
		}
	}
	else if(state == 5){
		state = 0;
		return SEMICOLON;
	}
	else if(state == 6){
		state = 0;
		return OPERATOR_MULTIPLY;
	}
	else if(state == 7){
		if(c >= '0' && c <= '9'){
			state = 17;
		}
		else if(c >= 'A' && c <= 'Z'){
			state = 18;
		}
		else if(c == 'v'){
			state = 24;
		}
		else if(c == 'i'){
			state = 22;
		}
		else if(c == 'f'){
			state = 21;
		}
		else if(c == 's'){
			state = 23;
		}
		else if(c == 'e'){
			state = 20;
		}
		else if(c == 'w'){
			state = 25;
		}
		else if(c >= 'a' && c <= 'z'){
			state = 19;
		}
		else{
			state = 0;
			return IDENTIFIER;
		}
	}
	else if(state ==  8){
		if(c >= '0' && c <= '9'){
			state = 17;
		}
		else if(c >= 'A' && c <= 'Z'){
			state = 18;
		}
		else if(c == 'v'){
			state = 24;
		}
		else if(c == 'i'){
			state = 22;
		}
		else if(c == 'f'){
			state = 21;
		}
		else if(c == 's'){
			state = 23;
		}
		else if(c == 'e'){
			state = 20;
		}
		else if(c == 'w'){
			state = 25;
		}
		else if(c == 'l'){
			state = 26;
		}
		else if(c >= 'a' && c <= 'z'){
			state = 19;
		}
		else{
			state = 0;
			return IDENTIFIER;
		}
	}
	else if(state == 9){
		if(c >= '0' && c <= '9'){
			state = 17;
		}
		else if(c >= 'A' && c <= 'Z'){
			state = 18;
		}
		else if(c == 'v'){
			state = 24;
		}
		else if(c == 'i'){
			state = 22;
		}
		else if(c == 'f'){
			state = 21;
		}
		else if(c == 's'){
			state = 23;
		}
		else if(c == 'e'){
			state = 20;
		}
		else if(c == 'w'){
			state = 25;
		}
		else if(c == 'l'){
			state = 27;
		}
		else if(c == 'o'){
			state = 28;
		}
		else if(c >= 'a' && c <= 'z'){
			state = 19;
		}
		else{
			state = 0;
			return IDENTIFIER;
		}
	}
	else if(state == 10){
		state = 0;
		return OPERATOR_ADD;
	}
	else if(state == 11){
		if(c >= '0' && c <= '9'){
			state = 17;
		}
		else if(c >= 'A' && c <= 'Z'){
			state = 18;
		}
		else if(c == 'v'){
			state = 24;
		}
		else if(c == 'i'){
			state = 22;
		}
		else if(c == 'f'){
			state = 29;
		}
		else if(c == 's'){
			state = 23;
		}
		else if(c == 'e'){
			state = 20;
		}
		else if(c == 'w'){
			state = 25;
		}
		else if(c == 'n'){
			state = 30;
		}
		else if(c >= 'a' && c <= 'z'){
			state = 19;
		}
		else{
			state = 0;
			return IDENTIFIER;
		}
	}
	else if(state == 12){
		if(c >= '0' && c <= '9'){
			state = 17;
		}
		else if(c >= 'A' && c <= 'Z'){
			state = 18;
		}
		else if(c == 'v'){
			state = 24;
		}
		else if(c == 'i'){
			state = 22;
		}
		else if(c == 'f'){
			state = 21;
		}
		else if(c == 's'){
			state = 23;
		}
		else if(c == 'e'){
			state = 20;
		}
		else if(c == 'w'){
			state = 25;
		}
		else if(c == 't'){
			state = 31;
		}
		else if(c >= 'a' && c <= 'z'){
			state = 19;
		}
		else{
			state = 0;
			return IDENTIFIER;
		}
	}
	else if(state == 13){
		if(c >= '0' && c <= '9'){
			state = 17;
		}
		else if(c >= 'A' && c <= 'Z'){
			state = 18;
		}
		else if(c == 'v'){
			state = 24;
		}
		else if(c == 'i'){
			state = 22;
		}
		else if(c == 'f'){
			state = 21;
		}
		else if(c == 's'){
			state = 23;
		}
		else if(c == 'e'){
			state = 20;
		}
		else if(c == 'w'){
			state = 25;
		}
		else if(c == 'o'){
			state = 32;
		}
		else if(c >= 'a' && c <= 'z'){
			state = 19;
		}
		else{
			state = 0;
			return IDENTIFIER;
		}
	}
	else if(state == 14){
		if(c >= '0' && c <= '9'){
			state = 17;
		}
		else if(c == 'h'){
			state = 33;
		}
		else if(c >= 'A' && c <= 'Z'){
			state = 18;
		}
		else if(c == 'v'){
			state = 24;
		}
		else if(c == 'i'){
			state = 22;
		}
		else if(c == 'f'){
			state = 21;
		}
		else if(c == 's'){
			state = 23;
		}
		else if(c == 'e'){
			state = 20;
		}
		else if(c == 'w'){
			state = 25;
		}
		else if(c >= 'a' && c <= 'z'){
			state = 19;
		}
		else{
			state = 0;
			return IDENTIFIER;
		}
	}
	else if(state == 15){
		if(c >= '0' && c <= '9'){
			state = 34;
		}
		else{
			state = 0;
			return FLOATINGPOINT;
		}
	}
	else if(state == 16){
		if(c >= '0' && c <= '9'){
			state = 16;
		}
		else if(c == '.'){
			state = 2;
		}
		else{
			state = 0;
			return INTEGER;
		}
	}
	else if(state == 17){
		if(c >= '0' && c <= '9'){
			state = 17;
		}
		else if(c >= 'A' && c <='Z'){
			state = 18;
		}
		else if(c >= 'a' && c <='z'){
			state = 18;
		}
		else{
			state = 0;
			return IDENTIFIER;
		}
	}
	else if(state == 18){
		if(c >= '0' && c <= '9'){
			state = 17;
		}
		else if(c >= 'A' && c <= 'Z'){
			state = 18;
		}
		else if(c >= 'a' && c <='z'){
			state = 18;
		}
		else{
			state = 0;
			return IDENTIFIER;
		}
	}
	else if(state == 19){
		if(c >= '0' && c <= '9'){
			state = 17;
		}
		else if(c >= 'A' && c <= 'Z'){
			state = 18;
		}
		else if(c == 'v'){
			state = 24;
		}
		else if(c == 'i'){
			state = 22;
		}
		else if(c == 'f'){
			state = 21;
		}
		else if(c == 's'){
			state = 23;
		}
		else if(c == 'e'){
			state = 20;
		}
		else if(c == 'w'){
			state = 25;
		}
		else if(c >= 'a' && c <= 'z'){
			state = 19;
		}
		else{
			state = 0;
			return IDENTIFIER;
		}
	}
	else if(state == 20){
		if(c >= '0' && c <= '9'){
			state = 17;
		}
		else if(c >= 'A' && c <= 'Z'){
			state = 18;
		}
		else if(c == 'v'){
			state = 24;
		}
		else if(c == 'i'){
			state = 22;
		}
		else if(c == 'f'){
			state = 21;
		}
		else if(c == 's'){
			state = 23;
		}
		else if(c == 'e'){
			state = 20;
		}
		else if(c == 'w'){
			state = 25;
		}
		else if(c >= 'a' && c <= 'z'){
			state = 19;
		}
		else{
			state = 0;
			return IDENTIFIER;
		}
	}
	else if(state == 21){
		if(c >= '0' && c <= '9'){
			state = 17;
		}
		else if(c >= 'A' && c <= 'Z'){
			state = 18;
		}
		else if(c == 'v'){
			state = 24;
		}
		else if(c == 'i'){
			state = 22;
		}
		else if(c == 'f'){
			state = 21;
		}
		else if(c == 's'){
			state = 23;
		}
		else if(c == 'e'){
			state = 20;
		}
		else if(c == 'w'){
			state = 25;
		}
		else if(c >= 'a' && c <= 'z'){
			state = 19;
		}
		else{
			state = 0;
			return IDENTIFIER;
		}
	}
	else if(state == 22){
		if(c >= '0' && c <= '9'){
			state = 17;
		}
		else if(c >= 'A' && c <= 'Z'){
			state = 18;
		}
		else if(c == 'v'){
			state = 24;
		}
		else if(c == 'i'){
			state = 22;
		}
		else if(c == 'f'){
			state = 21;
		}
		else if(c == 's'){
			state = 23;
		}
		else if(c == 'e'){
			state = 20;
		}
		else if(c == 'w'){
			state = 25;
		}
		else if(c >= 'a' && c <= 'z'){
			state = 19;
		}
		else{
			state = 0;
			return IDENTIFIER;
		}
	}
	else if(state == 23){
		if(c >= '0' && c <= '9'){
			state = 17;
		}
		else if(c >= 'A' && c <= 'Z'){
			state = 18;
		}
		else if(c == 'v'){
			state = 24;
		}
		else if(c == 'i'){
			state = 22;
		}
		else if(c == 'f'){
			state = 21;
		}
		else if(c == 's'){
			state = 23;
		}
		else if(c == 'e'){
			state = 20;
		}
		else if(c == 'w'){
			state = 25;
		}
		else if(c >= 'a' && c <= 'z'){
			state = 19;
		}
		else{
			state = 0;
			return IDENTIFIER;
		}
	}
	else if(state == 24){
		if(c >= '0' && c <= '9'){
			state = 17;
		}
		else if(c >= 'A' && c <= 'Z'){
			state = 18;
		}
		else if(c == 'v'){
			state = 24;
		}
		else if(c == 'i'){
			state = 22;
		}
		else if(c == 'f'){
			state = 21;
		}
		else if(c == 's'){
			state = 23;
		}
		else if(c == 'e'){
			state = 20;
		}
		else if(c == 'w'){
			state = 25;
		}
		else if(c >= 'a' && c <= 'z'){
			state = 19;
		}
		else{
			state = 0;
			return IDENTIFIER;
		}
	}
	else if(state == 25){
		if(c >= '0' && c <= '9'){
			state = 17;
		}
		else if(c >= 'A' && c <= 'Z'){
			state = 18;
		}
		else if(c == 'v'){
			state = 24;
		}
		else if(c == 'i'){
			state = 22;
		}
		else if(c == 'f'){
			state = 21;
		}
		else if(c == 's'){
			state = 23;
		}
		else if(c == 'e'){
			state = 20;
		}
		else if(c == 'w'){
			state = 25;
		}
		else if(c >= 'a' && c <= 'z'){
			state = 19;
		}
		else{
			state = 0;
			return IDENTIFIER;
		}
	}
	else if(state == 26){
		if(c == 's'){
			state = 35;
		}
		else if(c >= '0' && c <='9'){
			state = 7;
		}
		else if(c >= 'a' && c <= 'z'){
			state = 7;
		}
		else if(c >= 'A' && c <= 'Z'){
			state = 7;
		}
		else{
			state = 0;
			return IDENTIFIER;
		}
	}
	else if(state == 27){
		if(c == 'o'){
			state = 36;
		}
		else if(c >= '0' && c <='9'){
			state = 7;
		}
		else if(c >= 'a' && c <= 'z'){
			state = 7;
		}
		else if(c >= 'A' && c <= 'Z'){
			state = 7;
		}
		else{
			state = 0;
			return IDENTIFIER;
		}
	}
	else if(state == 28){
		if(c == 'r'){
			state = 37;
		}
		else if(c >= '0' && c <='9'){
			state = 7;
		}
		else if(c >= 'a' && c <= 'z'){
			state = 7;
		}
		else if(c >= 'A' && c <= 'Z'){
			state = 7;
		}
		else{
			state = 0;
			return IDENTIFIER;
		}
	}
	else if(state == 29){
		if(c == ' '){
			state = 38;
		}
		else if(c >= '0' && c <= '9'){
			state = 17;
		}
		else if(c >= 'A' && c <= 'Z'){
			state = 18;
		}
		else if(c == '('){
			state = 39;
		}
		else if(c == 'v'){
			state = 24;
		}
		else if(c == 'i'){
			state = 22;
		}
		else if(c == 'f'){
			state = 21;
		}
		else if(c == 's'){
			state = 23;
		}
		else if(c == 'e'){
			state = 20;
		}
		else if(c == 'w'){
			state = 25;
		}
		else if(c >= 'a' && c <= 'z'){
			state = 19;
		}
		else{
			return -1;
		}
	}
	else if(state == 30){
		if(c == 't'){
			state = 40;
		}
		else if(c >= '0' && c <='9'){
			state = 7;
		}
		else if(c >= 'a' && c <= 'z'){
			state = 7;
		}
		else if(c >= 'A' && c <= 'Z'){
			state = 7;
		}
		else{
			state = 0;
			return IDENTIFIER;
		}
	}
	else if(state == 31){
		if(c == 'r'){
			state = 41;
		}
		else if(c >= '0' && c <='9'){
			state = 7;
		}
		else if(c >= 'a' && c <= 'z'){
			state = 7;
		}
		else if(c >= 'A' && c <= 'Z'){
			state = 7;
		}
		else{
			state = 0;
			return IDENTIFIER;
		}
	}
	else if(state == 32){
		if(c == 'i'){
		state = 42;
		}
		else if(c >= '0' && c <='9'){
			state = 7;
		}
		else if(c >= 'a' && c <= 'z'){
			state = 7;
		}
		else if(c >= 'A' && c <= 'Z'){
			state = 7;
		}
		else{
			state = 0;
			return IDENTIFIER;
		}

	}
	else if(state == 33){
		if(c == 'i'){
			state = 43;
		}
		else if(c >= '0' && c <='9'){
			state = 7;
		}
		else if(c >= 'a' && c <= 'z'){
			state = 7;
		}
		else if(c >= 'A' && c <= 'Z'){
			state = 7;
		}
		else{
			state = 0;
			return IDENTIFIER;
		}
	}
	else if(state == 34){
		if(c >= '0' && c <= '9'){
			state = 34;
		}
		else{
			state = 0;
			return FLOATINGPOINT;
		}
	}
	else if(state == 35){
		if(c == 'e'){
			state = 44;
		}
		else if(c >= '0' && c <='9'){
			state = 7;
		}
		else if(c >= 'a' && c <= 'z'){
			state = 7;
		}
		else if(c >= 'A' && c <= 'Z'){
			state = 7;
		}
		else{
			state = 0;
			return IDENTIFIER;
		}
	}
	else if(state == 36){
		if(c == 'a'){
			state = 45;
		}
		else if(c >= '0' && c <='9'){
			state = 7;
		}
		else if(c >= 'a' && c <= 'z'){
			state = 7;
		}
		else if(c >= 'A' && c <= 'Z'){
			state = 7;
		}

		else{
			state = 0;
			return IDENTIFIER;
		}
	}
	else if(state == 37){
		if(c == ' '){
			state = 46;
		}
		else if(c == '('){
			state = 47;
		}
		else{
			return -1;
		}
	}
	else if(state == 38){
		if(c == ' '){
			state = 38;
		}
		else if(c == '('){
			state = 39;
		}
		else{
			return -1;
		}
	}
	else if(state == 39){
		state = 0;
		return IF;
	}
	else if(state == 40){
		if(c == ' '){
			state = 48;
		}
		else{
			return -1;
		}
	}
	else if(state == 41){
		if(c == 'i'){
			state = 49;
		}
		else{
			state = 0;
			return IDENTIFIER;
		}
	}
	else if(state == 42){
		if(c == 'd'){
			state = 50;
		}
		else if(c >= '0' && c <='9'){
			state = 7;
		}
		else if(c >= 'a' && c <= 'z'){
			state = 7;
		}
		else if(c >= 'A' && c <= 'Z'){
			state = 7;
		}
		else{
			state = 0;
			return IDENTIFIER;
		}
	}
	else if(state == 43){
		if(c == 'l'){
			state = 51;
		}
		else if(c >= '0' && c <='9'){
			state = 7;
		}
		else if(c >= 'a' && c <= 'z'){
			state = 7;
		}
		else if(c >= 'A' && c <= 'Z'){
			state = 7;
		}
		else{
			state = 0;
			return IDENTIFIER;
		}
	}
	else if(state == 44){
		if(c == ' '){
			state = 52;
		}
		else if(c == '{'){
			state = 53;
		}
		else if(c >= '0' && c <='9'){
			state = 7;
		}
		else if(c >= 'a' && c <= 'z'){
			state = 7;
		}
		else if(c >= 'A' && c <= 'Z'){
			state = 7;
		}
		else{
			return -1;
		}
	}
	else if(state == 45){
		if(c == 't'){
			state = 54;
		}
		else if(c >= '0' && c <='9'){
			state = 7;
		}
		else if(c >= 'a' && c <= 'z'){
			state = 7;
		}
		else if(c >= 'A' && c <= 'Z'){
			state = 7;
		}
		else{
			state = 0;
			return IDENTIFIER;
		}
	}
	else if(state == 46){
		if(c == ' '){
			state = 46;
		}
		else if(c == '('){
			state = 47;
		}
		else if(c >= '0' && c <='9'){
			state = 7;
		}
		else if(c >= 'a' && c <= 'z'){
			state = 7;
		}
		else if(c >= 'A' && c <= 'Z'){
			state = 7;
		}
		else{
			return -1;
		}
	}
	else if(state == 47){
		state = 0;
		return FOR;
	}
	else if(state == 48){
		if(c == ' '){
			state = 55;
		}
		else{
			state = 0;
			return INT;
		}
	}
	else if(state == 49){
		if(c == 'n'){
			state = 56;
		}
		else if(c >= '0' && c <='9'){
			state = 7;
		}
		else if(c >= 'a' && c <= 'z'){
			state = 7;
		}
		else if(c >= 'A' && c <= 'Z'){
			state = 7;
		}
		else{
			state = 0;
			return IDENTIFIER;
		}
	}
	else if(state == 50){
		if(c == ' '){
			state = 57;
		}
		else if(c >= '0' && c <='9'){
			state = 7;
		}
		else if(c >= 'a' && c <= 'z'){
			state = 7;
		}
		else if(c >= 'A' && c <= 'Z'){
			state = 7;
		}
		else{
			return -1;
		}
	}
	else if(state == 51){
		if(c == 'e'){
			state = 58;
		}
		else if(c >= '0' && c <='9'){
			state = 7;
		}
		else if(c >= 'a' && c <= 'z'){
			state = 7;
		}
		else if(c >= 'A' && c <= 'Z'){
			state = 7;
		}
		else{
			state = 0;
			return IDENTIFIER;
		}
	}
	else if(state == 52){
		if(c == ' '){
			state = 52;
		}
		else if(c == '{'){
			state = 53;
		}
		else{
			return -1;
		}
	}
	else if(state == 53){
		state = 0;
		return ELSE;
	}
	else if(state == 54){
		if(c == ' '){
			state = 59;
		}
		else if(c >= '0' && c <='9'){
			state = 7;
		}
		else if(c >= 'a' && c <= 'z'){
			state = 7;
		}
		else if(c >= 'A' && c <= 'Z'){
			state = 7;
		}
		else{
			return -1;
		}
	}
	else if(state == 55){
		if(c == ' '){
			state = 55;
		}
		else{
			state = 0;
			return INT;
		}
	}
	else if(state == 56){
		if(c == 'g'){
			state = 60;
		}
		else if(c >= '0' && c <='9'){
			state = 7;
		}
		else if(c >= 'a' && c <= 'z'){
			state = 7;
		}
		else if(c >= 'A' && c <= 'Z'){
			state = 7;
		}
		else{
			state = 0;
			return IDENTIFIER;
		}
	}
	else if(state == 57){
		if(c == ' '){
			state = 61;
		}
		else{
			state = 0;
			return VOID;
		}
	}
	else if(state == 58){
		if(c == ' '){
			state = 62;
		}
		else if(c == '('){
			state = 63;
		}
		else if(c >= '0' && c <='9'){
			state = 7;
		}
		else if(c >= 'a' && c <= 'z'){
			state = 7;
		}
		else if(c >= 'A' && c <= 'Z'){
			state = 7;
		}
		else{
			return -1;
		}
	}
	else if(state == 59){
		if(c == ' '){
			state = 64;
		}
		else{
			state = 0;
			return FLOAT;
		}
	}
	else if(state == 60){
		if(c == ' '){
			state = 65;
		}
		else if(c >= '0' && c <='9'){
			state = 7;
		}
		else if(c >= 'a' && c <= 'z'){
			state = 7;
		}
		else if(c >= 'A' && c <= 'Z'){
			state = 7;
		}
		else{
			return -1;
		}
	}
	else if(state == 61){
		if(c == ' '){
			state = 61;
		}
		else if(c >= '0' && c <='9'){
			state = 7;
		}
		else if(c >= 'a' && c <= 'z'){
			state = 7;
		}
		else if(c >= 'A' && c <= 'Z'){
			state = 7;
		}
		else{
			state = 0;
			return VOID;
		}
	}
	else if(state == 62){
		if(c == ' '){
			state = 62;
		}
		else if(c == '('){
			state = 63;
		}
		else{
			return -1;
		}
	}
	else if(state == 63){
		state = 0;
		return WHILE;
	}
	else if(state == 64){
		if(c == ' '){
			state = 64;
		}
		else{
			state = 0;
			return FLOAT;
		}
	}
	else if(state == 65){
		if(c == ' '){
			state = 66;
		}
		else{
			state = 0;
			return STRING;
		}
	}
	else if(state == 66){
		if(c == ' '){
			state = 66;
		}
		else{
			state = 0;
			return STRING;
		}
	}
	else if(state == 67){
		if(c == '='){
			state = 69;
		}
		else {
			state = 0;
			return OPERATOR_LESSTHAN;
		}
	}
	else if(state == 68){
		if(c == '='){
			state = 72;
		}
		else {
			state = 0;
			return ASSIGN;
		}
	}
	else if(state == 69){
			state = 0;
			return OPERATOR_LE;
		
	}
	else if(state == 70){
		if(c == '='){
			state = 71;
		}
		else {
			state = 0;
			return OPERATOR_GREATERTHAN;
		}
	}
	else if(state == 71){
		state = 0;
		return OPERATOR_GE;
	}
	else if(state == 72){
		state = 0;
		return OPERATOR_COMPARISON;
	}
	else if(state == 73){
		state = 0;
		return OPERATOR_COMMA;
	}
	else if(state == 74){
		state = 0;
		return OPENING_PARANTHESES;
	}
	else if(state == 75){
		state = 0;
		return CLOSING_PARANTHESES;
	}
	else if(state == 76){
		state = 0;
		return OPEN_BRACES;
	}
	else if(state == 77){
		state = 0;
		return CLOSING_BRACES;
	}
	return 90;
}