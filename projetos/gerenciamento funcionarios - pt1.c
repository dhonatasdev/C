#include <stdio.h>
#include <stdlib.h>
#define qtde_fixa 10
#define NUM_FUNC 10
#define NUM_DIAS 10
#define QTD_HORAS_DIARIAS 8


int main(){
    int op, count = 0, posicao = -1, i, temp, veri = -1, matri, aux;
    int funcio_ativos[NUM_FUNC], aux_count = 0;
    float funcio_horas[NUM_FUNC] , horas, aux_horas;
    
    int funcio_remo[NUM_FUNC], count_remo = 0, j;
    for(i = 0; i< NUM_FUNC; i++){
		funcio_horas[i] = -1;    // ta atribuindo um valor que considero invalido para o vetor funcio_horas
	}
    while(1){
        printf("-_-_-_-_-_-_Menu de opcoes-_-_-_-_-_-_-\n");
        printf("Cadastro de funcionarios..............1\n");
        printf("Remocao de funcionarios...............2\n");
        printf("Cadastro de horas diarias.............3\n");
        printf("Relatorios............................4\n");
        printf("Sair..................................5\n");
        scanf("%d", &op);
        system("cls");
        if(op == 5){
            break;
        }
        switch (op){
            case 1:
				while(1){
					if(count == NUM_FUNC){
					printf("Lista cheia\n");
					break;
					}
					printf("Insira a matricula do funcionario\n");
					scanf("%d", &matri);
					for (i = 0; i < count_remo; i++){
						if(funcio_remo[i] == matri){    // verifica se o codigo ja foi removido ou nao
							veri = 1;
						}
					}
					for(i = 0; i < count; i++){
						if(funcio_ativos[i] == matri){
							veri = 2;                   // verifica se o codigo ta duplicado
						}
					}
					if(veri == 1){
					printf("A matricula informada nao esta disponivel\n");
					break;
					}
					else if(veri == 2){
					printf("A matricula informada encontra-se em uso\n");
					break;
					}
					else if(matri < 0){
					printf("Matricula invalida, nao pode ser informado um numero negativo\n");
					break;
					}
					else{
					funcio_ativos[count] = matri;
					printf("Cadastrado com sucesso\n");
					printf("Adicionar mais um funcionario? 1 para *sim e qualquer outro numero para *nao\n");
					scanf("%d", &temp);
					count ++;
					for (i = 0; i < count; i++) {
                        for (j = i+1; j < count; j++) {
                            if (funcio_ativos[i] > funcio_ativos[j]) {
                                aux = funcio_ativos[i];
                                funcio_ativos[i] = funcio_ativos[j];
                                funcio_ativos[j] = aux;
                                // ordena os funcionarios que foram cadastrados e move juntamente com as horas trabalhadas
                                aux_horas = funcio_horas[i];
                                funcio_horas[i] = funcio_horas[j];
                                funcio_horas[j] = aux_horas;
                         
                            }
                        }
                    }
					}
					if(temp != 1){
						printf("Voltando ao menu\n");
					    break;
					}
            
				}
			veri = -1;
				
            break;
            
            case 2:
            printf("Digite a matricula do funcionario\n");
            scanf("%d", &matri);
            for(i = 0; i < count; i++){
                if(funcio_ativos[i] == matri){   // encontra a posicao do funcinario
                    posicao = i; 
                }
            }

            for(i = 0; i < count; i++){       // remove funcionario da lista de funcionarios ativos
                if(i >posicao){
                funcio_ativos[i-1] = funcio_ativos[i];  // ta puxando os valores para a esquerda
                funcio_horas[i-1] = funcio_horas[i];
                }
            }

            
            
            if(posicao == -1){
                printf("Matricula invalida\n");
            }
            if(posicao != -1){
                count = count - 1;
                funcio_remo[count_remo] = matri;    // adiciona o funcionario que foi removido na lista dos funcionarios removidos
                count_remo ++;
                if(count_remo == qtde_fixa){
					count_remo = 0;
				}
                printf("Funcionario removido com sucesso\n");
            }
            posicao = -1;
            
            break;
            
            case 3:
            if(count == 0){
                printf("Lista vazia, insira um funcionario para desbloquear esta funcionalidade\n");
                break;
            }
            printf("Insira a matricula\n");
            scanf("%d", &aux);
            for(i = 0; i < count; i++){
                if(funcio_ativos[i] == aux){
                    posicao = i;                    // encontra a posicao do funcionario 
                }
            }
            if(posicao == -1){
                printf("Funcionario invalido\n");
                posicao = -1;
                break;
            }
            else{
                for(i = 0; i < NUM_DIAS; i++){
                    printf("Insira a quantidade de horas trabalhada no dia %d\n", i+1);
                    scanf("%f", &horas);
                    if(horas < 0){
						printf("A hora informada nao pode ser negativa\n");
						 funcio_horas[posicao] = -1;
						break;
					}
                    funcio_horas[posicao] += horas;  // guarda a soma de horas trabalhadas pelo funcionario no vetor de horas com a mesmo posicao do funcionario
                }
                if(horas >= 0){
					printf("Dados salvos com sucesso\n");
					funcio_horas[posicao] = funcio_horas[posicao]+1;    // eu coloquei +1 porque o vetor ja vem com o valor padrao de -1, dai preciso remover de algum modo esse valor
				}
            }
            
            posicao = -1;
            break;
            
            case 4:
            while(1){
				printf("-_-_-_-Relatorios-_-_-_-_-\n");
				printf("Funcioarios adimplentes............1\n");
				printf("Funcionarios inadiplementes........2\n");
				printf("Funcionarios que serao demitidos...3\n");
				printf("Lista geral........................4\n");
				printf("Voltar ao menu.....................5\n");
				scanf("%d", &op);
				system("cls");
				if(op == 5){
				    break;
				}
				switch (op){
                    case 1:
				    for(i = 0; i<count; i++){
				        if(funcio_horas[i] >= QTD_HORAS_DIARIAS*NUM_DIAS){
							veri = 1;
				            printf("____________________\n");
				            printf("Matricula: %d\n", funcio_ativos[i]);
				            printf("Frequencia: %.2f %%\n", (100*funcio_horas[i])/(QTD_HORAS_DIARIAS*NUM_DIAS));  
				            printf("--------------------\n");
				        }
				    }
				    if(veri != 1){
						printf("Lista vazia\n");
					}
					veri = -1;
				    
				    break;
				    case 2:
				    for(i = 0; i< count; i++){
				        if((funcio_horas[i])/(QTD_HORAS_DIARIAS*NUM_DIAS) > 0.7 && (funcio_horas[i])/(QTD_HORAS_DIARIAS*NUM_DIAS) < 1.0){
				            printf("____________________\n");
				            printf("Matricula: %d\n", funcio_ativos[i]);
				            printf("Frequencia: %.2f %%\n", (100*funcio_horas[i])/(QTD_HORAS_DIARIAS*NUM_DIAS));
				            printf("--------------------\n");
				            veri = 1;
				            
				        }
				    }
				    if(veri != 1){
				        printf("Lista vazia\n");
				    }
				    
				    veri = -1;
				    break;
				    
				    case 3:
					aux_count = count;
				    for(i = 0; i<count; i++){
						
				        if(funcio_horas[i]/(QTD_HORAS_DIARIAS*NUM_DIAS) <= 0.7 && funcio_horas[i]>=0){
							veri = 1;
				            printf("____________________\n");
				            printf("Matricula: %d\n", funcio_ativos[i]);
				            printf("Frequencia: %.2f %%\n", (100*funcio_horas[i])/(QTD_HORAS_DIARIAS*NUM_DIAS));
							printf("--------------------\n");
							posicao = i;
							for(j = 0; j < aux_count; j++){       // remove funcionario da lista de funcionarios ativos
                			if(j > posicao){
                				funcio_ativos[j-1] = funcio_ativos[j];  
                				funcio_horas[j-1] = funcio_horas[j];
                			}
            				}
							aux_count = aux_count -1;
							funcio_remo[count_remo] = funcio_ativos[i];
                			count_remo ++;
                			if(count_remo == qtde_fixa){
								count_remo = 0;
							}

				        }
				    }
					count = aux_count;
					posicao = -1;
				    if(veri != 1){
				        printf("Lista vazia\n");
				    }
				    veri = -1;
				    break;
				    case 4: 
				    for(i = 0; i < count; i++){
						printf("____________________\n");
						printf("Matricula: %d\n", funcio_ativos[i]);
						if(funcio_horas[i] >= 0){
							printf("Frequencia: %.2f %% \n", (100*funcio_horas[i])/(QTD_HORAS_DIARIAS*NUM_DIAS));
						}
						else{
							printf("Frequencia: sem dados\n");
						}
						printf("--------------------\n");
						veri = 1;
					}
					if(veri != 1){
						printf("Lista vazia\n");
					}
					veri = -1;
					break;
				    
				    default:
				    printf("Opcao invalida\n");
				    break;
				}
            }
            break;
            
            default:
            printf("Opcao invalida\n");
            break;
        }

    }

}

