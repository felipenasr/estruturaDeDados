#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int * elementos;
    int capacidade;
    int quantidade;
} vetor_dinamico;

vetor_dinamico * obtem_vetor_dinamico(){
    vetor_dinamico *v;
    v = (vetor_dinamico *) malloc(sizeof(vetor_dinamico)); // a variavel v tem o endereco inicial da estrutura que foi alocada dinamicamente
    v->capacidade = 10;
    v->quantidade = 0;
    v->elementos = (int *) malloc(sizeof(int) * 10); //elementos recebeu o endereço inicial de um vetor de tamanho 10
    return v;
}

/*void aumenta(vetor_dinamico * v){
    int i, *aux;
    aux = (int *) malloc(sizeof(int) * v->capacidade * 2); //aux recebe um vetor de inteiros com o dobro da capacidade de v
    for(i = 0; i < v->quantidade; i++){
        aux[i] = v->elementos[i];
    }
    free (v->elementos);
    v->elementos = aux;
    v->capacidade = v->capacidade * 2;
}

void diminui (vetor_dinamico *v){
	 int i, *aux;
    aux = (int *) malloc(sizeof(int) * v->capacidade / 2);
    for(i = 0; i < v->quantidade; i++){
        aux[i] = v->elementos[i];
    }
    free (v->elementos);
    v->elementos = aux;
    v->capacidade = v->capacidade / 2;
}*/

void redimensiona(vetor_dinamico * v, int nova_capacidade){
    int i, *aux;
    aux = (int *) malloc(sizeof(int) * nova_capacidade); 
    for(i = 0; i < v->quantidade; i++){
        aux[i] = v->elementos[i];
    }
    free (v->elementos);
    v->elementos = aux;
    v->capacidade = nova_capacidade;
}

int esta_cheio(vetor_dinamico * v){
    return (v->quantidade >= v->capacidade);
}

int esta_vazio(vetor_dinamico * v){
    return (v->quantidade == 0);
}

int precisa_diminuir(vetor_dinamico * v){
    return (v->quantidade <= v->capacidade/4);
}
    
void insere(int i, vetor_dinamico * v){
    if(esta_cheio(v)){
        redimensiona(v, v->capacidade*2);
    }
        v->elementos [v->quantidade] = i;
        v->quantidade++; // essas 2 linhas podem ser substituidas por v->elementos [v-.quantidade++] = 1;
}
void remov (vetor_dinamico * v){
	if(!esta_vazio(v)){
		v->quantidade--;
		if(precisa_diminuir(v)){
			redimensiona(v, v->capacidade/2);
		}
	}
	else{
		printf("\nFalha na remocao, vetor vazio\n");
	}
	
}

void mostra_vetor(vetor_dinamico *v, char *msg){
	int i;
	printf("\n%s:\n",msg);
	printf("\nCapacidade = %d", v->capacidade);
	printf("\nQuantidade = %d\n\n", v->quantidade);
	for(i=0; i<v->quantidade;i++){
		printf("%d ", v->elementos[i]);
	}
	printf("\n");
}


int main(){
    vetor_dinamico *v;
    int i;
    v = obtem_vetor_dinamico(); //a função obtem_vetor_dinamico é do tipo ponteiro de vetor_dinamico
    
	remov(v);
	//remov; it works
	for(i = 1; i <= 100; i++){
        insere (i, v);
    }
    mostra_vetor (v, "Vetor depois da insercoes");
    for(i = 1; i <= 60; i++){
        remov (v);
    }
	mostra_vetor (v, "Vetor depois das remocoes");
   
    return 0;
}
