/* Atividade DIC
Arquivo: CABarreto_DIC.c
Autor: Cinthia Alves Barreto
Date: 06/03/2023 08:27
Descrição: Este programa mostra a lista de palavras de um dicionário e o comprimento de cada palavra.
*/

#include <stdio.h>
#include <string.h>

int main(){
	int n;
	unsigned char linha[32];
	FILE *entrada;
	int qtde_caracteres;
	
	
	//entrada = fopen("NOMES 2023.txt", "r"); 
	entrada = fopen("PALAVRAS original.txt", "r"); 
	//entrada = fopen("TEXTO INICIAL.txt", "r");
	
	
	if (entrada == NULL){ 
		printf("\n nao encontrado \n");
	} else {
		printf("\n arquivo de dados encontrado - fscanf vai ler os caracteres \n\n\n");
		
		while(fscanf(entrada,"%30s", linha) == 1){
			qtde_caracteres = strlen(linha);
			
			for(int i=0; i< qtde_caracteres; i++){
				if (linha[i]>=65 && linha[i]<=90){
					linha[i] = linha[i] + 32; 
				}
			}
			printf(" %s %d \n", linha, qtde_caracteres);
	}
	fclose(entrada);
}
	printf("\n fim");
	
	return 0;
	
}
