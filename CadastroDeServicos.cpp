// 6 - Fazer um programa que cadastre o número de dez portas de redes 
//(não permite entrada de portas repetidas) e o seu respectivo serviço 
//em dois vetores distintos. Depois permita ao usuário digitar o número 
//da porta, verifica se o número existe ou não. Caso exista emita na tela 
//o serviço disponibilizado pela porta. Comentar o código de acordo com 
//as regras de algoritmo estudadas em sala de aula.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string>

int main()
{	
	int porta[10];
	
	for ( int i = 0; i<=9; i++)
	{
		porta[i] = 0;	
	}
	
	std::string serv[10];
	int cadastrando = 0;
	int cadastro = 0;
	int i = 0;	
	int valor = 0;
	char nome[50];
	
	while(cadastrando == 0)
	{			
			int valida = 0;
			system("cls");
			printf(" Digite \"1\" para cadastrar um servico ou digite \"0\" para listar os servicos cadastrados: ");
			scanf("%d", &valida);
			system("cls");
				
			if(valida == 1)
			{
				system("cls");
				printf("###################################################################");
				printf("\n##"); printf(" Digite o nome do servico que deseja cadastrar: ");  
				scanf("%s", nome);
				serv[cadastro] = nome;
				printf("###################################################################");
				printf("\n##"); printf(" Digite a porta no servido %s cadastrado: ", nome);
				scanf("%d", &valor);
			
				while(valor == 0 || valor > 65535) 
				{
					system("cls");
					printf("###################################################################");
					printf("\n##");  printf(" Nao e possivel cadastrar uma porta \"nula\" ou maior \"65535\"! ");
					printf("\n##");  printf(" Digite uma porta maior que \"0\" e menor que \"65535\": ");
					scanf("%d", &valor);
				}
			
				int cont = 0;				
				
				while(i < 9)
				{				
					if(porta[i] == valor)
					{
						while(porta[i] == valor)
						{						
							system("cls");
							printf("###################################################################");
							printf("\n##");  printf(" Essa porta ja foi cadastrada: ");
							printf("\n##");  printf(" Digite uma porta para o servico \"%s\" que ainda nao foi cadastrado: ", nome);
							scanf("%d", &valor);
							cont++;
							if(cont > 1)
							{
								int v_laco;
								system("cls");
								printf("###################################################################");
								printf("\n##");  printf(" Percebi que voce esta com dificuldade para cadastrar uma porta livre!");
								printf("\n##");  printf(" Voce pode teclar \"1\" para acessar o banco de dados ou \"0\" para continuar cadastrando :");
								scanf("%d", &v_laco);
							
								if(v_laco == 1)
								{
									for(int j=0; j<=9; j++)
									{
										printf("\n Servico: %s Porta: %d ", serv[j].c_str(), porta[j]);
									}
									
									printf("\n");
									system("pause");
									cont = 0;
								
									system("cls");
									printf("###################################################################");
									printf("\n##");  printf(" Digite uma porta para o servico \"%s\" que ainda nao foi cadastrado: ", nome);
									scanf("%d", &valor);
								}
								
								if(v_laco == 0)
								{
									printf("###################################################################");
									printf("\n##");  printf(" Digite uma porta para o servico \"%s\" que ainda nao foi cadastrado: ", nome);
									scanf("%d", &valor);
									cont = 0;
								}			
							}
						}	
						i = 0;					
					}
					i++;
				}			
				i = 0;			
				porta[cadastro] = valor;
				cadastro++;				
				porta[cadastro] = 0;
			}	
									
			if(valida == 0)
			{
				cadastrando = 1;
			}	
	}
	
		printf("###################################################################");
		printf("\n##");  printf(" Os servicos e portas cadastrados sao: ");
		
		for(i=0; i<=9; i++)
		{
			printf("\n Servico: %s Porta: %d ", serv[i].c_str(), porta[i]);
		}
}

