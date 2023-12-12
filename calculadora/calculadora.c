#include <stdio.h>
#include <string.h>
#include <readline/readline.h>

void operação(int num, int num2,char c){

	switch(c){
		case '+':
			printf("\nSeu resultado é %d\n", num + num2);
			break;
		case '-':
			printf("\nSeu resultado é %d\n", num - num2);
			break;
		case '*':
			printf("\nSeu resultado é %d\n", num * num2);
			break;
		case '/':
			printf("\nSeu resultado é %d\n", num / num2);
			break;
	}
}

void converter(int numero, char flag) {
    if (flag == 'x') {
        printf("\nSeu resultado é %x\n", numero);
    } else if (flag == '&') {
        for (int i = 31; i >= 0; i--) {
            printf("%d", (numero >> i) & 1);
        }
	printf("\n");
    }
}

int main(){

	char c;
	int num, num2;
	char *line = "";

	while(strcmp(line, "sair")){
		num = 0;
		num2 = 0;
		printf("Bem vindo a calculadora\n\tPara sair digite 'sair'\n");
		printf("Escolha sua operação:\nSoma (+), Subtração (-), Divisão (/), Multiplicação (*), Binária(&), Hexadecimal(x): \n-> ");
		line = readline("");
		c = line[0];
		if(c == '+' || c == '-' || c == '*' || c == '/'){
			printf("\nInforme o primeiro Numero:\n-> ");
			scanf("%d",&num);
			printf("\nInforme o segundo Numero:\n-> ");
			scanf("%d", &num2);
			operação(num, num2, c);
		}
		else if(c == '&' || c == 'x'){
			printf("\nInforme o Numero a ser convertido:\n-> ");
			scanf("%d", &num2);
			converter(num2, c);
		}
		else
			printf("Input Invalido\n");
	}
}
