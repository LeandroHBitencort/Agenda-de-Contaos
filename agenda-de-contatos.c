//Leandro H Bitencort
//Tema: Agenda de contatos
//Utilizei a Biblioteca do prof. que nos foi fornecida.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pss.h"


#define MAX_CONTATO 4
#define MAX_NOME 50

typedef struct
{
	char Nome[MAX_NOME];
	char tel[15];
	char email[MAX_NOME];
}Contato;

void adicionar_contato(Contato *contatos, int *total)
{
	int i=*total;
	printf("\n*** Adicionar Contatos ***\n");
	if(i<MAX_CONTATO)
	{
		input_s("Digite o nome: ", contatos[i].Nome,MAX_NOME);
		input_s("Digite o Numero: ", contatos[i].tel,15);
		input_s("Digite o email: ", contatos[i].email,MAX_NOME);
		printf("\n** Contato Cadastrado com sucesso! **\n");
		printf("Contato: %d\n.Nome: %s \n.Telefone: %s \n.Email: %s\n\n", i+1, contatos[i].Nome, contatos[i].tel, contatos[i].email);
		(*total)++;
	}
	else
	{
		printf("Voce atingiu o limite maximo de contatos permitidos.\n\n");
	}
}
void lista_contato(Contato *contatos, int total)
{
	int i=0;
	printf("\n*** Lista de Contatos! ***\n");
	for(;i<total;i++)
	{
		printf("Contato: %d:\n.Nome: %s\n.Telefone: %s\n.E-mail: %s\n\n", i+1, contatos[i].Nome, contatos[i].tel, contatos[i].email);
	}
}
void buscar_contato(Contato *contatos, int total)
{
	char c[MAX_NOME];
	int encontrado;
	
	printf("\n*** Buscar Contato ***\n");
	do
	{
		encontrado=0;	
		input_s("Digite o nome do contato que deseja encontrar\n", c, MAX_NOME);
		for(int i=0;i< total; i++)
		{
			if (strcmp(contatos[i].Nome, c)== 0)
			{
				printf("\nContato: %d\n.Nome: %s \n.Telefone: %s \n.Email: %s\n\n", i+1, contatos[i].Nome, contatos[i].tel, contatos[i].email);
				encontrado =1;	
				break;
			}
		}
		if(!encontrado)
			{
				printf("Contato nao encontrado!\n\n");
			}
	}while (!encontrado);
}
void main ()
{
	Contato contatos [MAX_CONTATO];
	int opcao,total=0;
	
	do
	{
		printf("\n*** Menu Agenda de contatos ***\n");
		printf(".01 Adicionar Contatos\n");
		printf(".02 Lista de Contatos\n");
		printf(".03 Busca Contatos\n");
		printf(".04 Sair\n");
		opcao = input_d("\nDigite a opcao ");
		
		switch (opcao)
		{
			case 1:
				adicionar_contato(contatos,&total);
				break;
			case 2:
				lista_contato(contatos, total);
				break;
			case 3:
				buscar_contato(contatos, total);
				break;
			case 4:
				printf("Saindo...");
				break;
			default:
				printf("Opcao invalida, tente novamente!\n");
		}	
	}while (opcao!=4);
	
}
