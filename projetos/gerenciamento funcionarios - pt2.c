#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int NUM_FUNC;
    int NUM_DIAS;
    int QTDE_HORAS_DIARIAS;
    int qtde;
} configuracoes;
 configuracoes aux;

typedef struct{
    char nome[50];
    int matri;
    int idade;
    int horas;
} dados;
dados funcio[];

void menu();
void modo_gerente();
void cadastro_funcio();
void remocao_funcionarios();
void altera_dados();
void relatorios();
void adimplentes();
void inadiplentes();
void demitidos();
void ordena_matricula();
int cadastro_config(int n);
void ordena_frequencia();
int verifica_matricula(int matri, int n);
int verifica_idade(int idade);
char verifica_nome(char nome[]);
void modo_funcionario();
void altera_nome();
void altera_idade();
void situ_funcionarios();
void cadastra_horas();
int verifica_horas(int horas);
int remocao_auto(int pos);
void atribuicao();
void atualizacao();
void lista_geral();

int main(){
    menu();
    return 0;
}

void menu(){
    int op;
    while(1){
        atribuicao();
        printf("-_-_-_-_ Menu _-_-_-_-\n");
        printf("Gerente...............1\n");
        printf("Funcionario...........2\n");
        printf("Sair..................3\n");
        scanf("%d", &op);
        system("cls");
        if(op == 3){
            break;
        }
        switch (op){
            case 1: modo_gerente(); break;
            case 2: modo_funcionario(); break;
            default: printf("Opcao invalida\n"); break;
        }
    }
}

void modo_gerente(){
    int op;
    FILE *config;
    config = fopen("config.txt", "r");
    if(config == NULL){
        if(cadastro_config(0) == 0){
            exit(0);
        }
    }
    while(1){
        printf("-_-_-_-_-_-_ Modo gerente _-_-_-_-_-_-\n");
        printf("Cadastro de funcionarios..............1\n");
        printf("Remocao de funcionarios...............2\n");
        printf("Alterar dados do funcionario..........3\n");
        printf("Relatorios............................4\n");
        printf("Sair..................................5\n");
        scanf("%d", &op);
        system("cls");
        if(op == 5){
            exit(0);
        }
        switch (op){
            case 1: cadastro_funcio(); break;
            case 2: remocao_funcionarios(); break;
            case 3: altera_dados(); break;
            case 4: relatorios(); break;
            default: printf("Opcao invalida\n"); break;
        } 
    }       
}

void cadastro_funcio(){
    if(aux.NUM_FUNC == aux.qtde){
        printf("Lista cheia\n");
        return 0;
    }
    FILE *dados_func;
    dados_func = fopen("dados func.txt", "a");
	printf("Insira a matricula do funcionario\n");
    scanf("%d", &funcio[aux.qtde].matri);
    if(verifica_matricula(funcio[aux.qtde].matri, 0) == -1){
        printf("Insira o nome do funcionario\n");
        scanf(" %[^\n]s", funcio[aux.qtde].nome);
        if(verifica_nome(funcio[aux.qtde].nome)!= 1){
            printf("Insira a idade do funcionario\n");
            scanf("%d", &funcio[aux.qtde].idade);
            if(verifica_idade(funcio[aux.qtde].idade)!=1){
                printf("Funcionario cadastrado com sucesso\n");
                funcio[aux.qtde].horas = -1;
                fwrite(&funcio[aux.qtde], sizeof (dados), 1, dados_func);
                aux.qtde ++;
                atualizacao();
                atribuicao();
            }
        }
    }
    fclose(dados_func);
}

void remocao_funcionarios(){
    FILE *dados_func;
    dados_func = fopen("dados func.txt", "w");
    int matri, i, pos = -1;
    printf("Insira a matricula do funcionario\n");
    scanf("%d", &matri);
    if(verifica_matricula(matri, 1) > -1){
        pos = verifica_matricula(matri, 1);
        for(i = 0; i <aux.qtde; i++){
            if(pos!=i){
                fwrite(&funcio[i], sizeof(dados), 1, dados_func);
            }
        }
        printf("Funcionario removido com sucesso\n");
        aux.qtde --;
    }
    else{
        printf("Matricula invalida\n");
    }
    fclose(dados_func);
    atualizacao();
    atribuicao();

}

void altera_dados(){
    int matri, op;
    while(1){
        printf("-_-_-Alteracao de dados-_-_-\n");
        printf("Alterar nome...............1\n");
        printf("Alterar idade..............2\n");
        printf("Sair.......................3\n");
        scanf("%d", &op);
        system("cls");
        if(op == 3){
            break;
        }
        switch (op){
            case 1: altera_nome(); break;
            case 2: altera_idade(); break;
            default: printf("Opcao invalida\n"); break;
        }
    }
}

void altera_nome(){
    int matri, pos, i;
    char nome[50];
    printf("Digite a matricula\n");
    scanf("%d", &matri);
    if(verifica_matricula(matri, 1)>= 0){
        pos = verifica_matricula(matri, 1);
        printf("Digite o novo nome\n");
        scanf(" %[^\n]s", nome);
        if(verifica_nome(nome) == -1){
            printf("Nome alterado com sucesso\n");
            strcpy(funcio[pos].nome, nome);
            FILE *dados_func;
            dados_func = fopen("dados func.txt", "w");
            for(i = 0; i < aux.qtde; i++){
                fwrite(&funcio[i], sizeof(dados), 1, dados_func);
            }
            fclose(dados_func);
            atribuicao();

        }
    }
    else{
        printf("Matricula invalida\n");
    }
}

void altera_idade(){
    int matri, pos, i, idade;
    printf("Digite a matricula\n");
    scanf("%d", &matri);
    if(verifica_matricula(matri, 1) >= 0){
        pos = verifica_matricula(matri, 1);
        printf("Digite a nova idade\n");
        scanf("%d", &idade);
        if(verifica_idade(idade) == -1){
            printf("Idade alterada com sucesso\n");
            funcio[pos].idade = idade;
            FILE *dados_func;
            dados_func = fopen("dados func.txt", "w");
            for(i = 0; i < aux.qtde; i++){
                fwrite(&funcio[i], sizeof(dados), 1, dados_func);
            }
            fclose(dados_func);
            atribuicao();
        }
    }
    else{
        printf("Matricula invalida\n");
    }
}



int remocao_auto(int pos){
    int i;
    FILE *dados_func;
    dados_func = fopen("dados func.txt", "w");
    for(i = 0; i < aux.qtde; i++){
        if(pos!=i){
            fwrite(&funcio[i], sizeof(dados), 1, dados_func);
        }
    }
    fclose(dados_func);
}

void relatorios(){
    int op;
    while(1){
        printf("_-_-_-_-_-_-_-Relatorios-_-_-_-_-_-_-_\n");
		printf("Funcionarios adimplentes..............1\n");
		printf("Funcionarios inadiplentes.............2\n");
		printf("Funcionarios que serao demitidos......3\n");
		printf("Lista geral...........................4\n");
		printf("Voltar ao menu........................5\n");
		scanf("%d", &op);
        system("cls");
        if(op == 5){
            break;
        }
        switch (op){
            case 1: ordena_frequencia(); adimplentes(); break;
            case 2: ordena_frequencia(); inadiplentes(); break;
            case 3: ordena_frequencia(); demitidos(); break;
            case 4: ordena_matricula(); lista_geral(); break;
            default: printf("Invalido\n"); break;
        }
    }
}

int verifica_matricula(int matri, int n){
    int i, veri = -1;
    for(i = 0; i <aux.qtde; i++){
        if(matri == funcio[i].matri){
            veri = i;
            if(n == 0){
                printf("A matricula informada encontra-se indisponivel\n");
            }
        }
    }
    if(matri < 0){
        printf("Nao pode ser informado um numero negativo\n");
        veri = -2;
    }
    return veri;
}

int verifica_idade(int idade){
    int veri = -1;
    if(idade < 18 || idade > 65){
        printf("Idade informada nao esta dentro dos parametros esperados\n");
        veri = 1;
    }
    return veri;
}

char verifica_nome(char nome[]){
    int tam = strlen(nome), i, veri;
    for(i = 0; i < tam; i++){
        if(nome[i] >= 'A' && nome[i] <= 'Z' || nome[i]>= 'a' && nome[i]<='z' || nome[i] == ' '){
            veri = -1;
        }else{
            veri = 1;
        }
    }
    if(veri == 1  || nome[0] >= '1' && nome[0]<='9'){
        printf("Nome invalido\n");
        veri = 1;
    }
    return veri;
}

void atribuicao(){
    FILE *config;
    config = fopen("config.txt", "r");
    fscanf(config, "%d %d %d %d", &aux.NUM_FUNC, &aux.NUM_DIAS, &aux.QTDE_HORAS_DIARIAS, &aux.qtde);
    fclose(config);
    FILE *lista;
    lista = fopen("dados func.txt", "r");
    fread(&funcio, sizeof(dados), aux.qtde, lista);
}

int cadastro_config(int n){
    printf("Digite o numero de funcionarios\n");
    scanf("%d", &aux.NUM_FUNC);
    if(aux.NUM_FUNC <= 0){
        printf("Numero de funcionarios invalido\n");
        return 0;
    }
    printf("Digite o numero de dias\n");
    scanf("%d", &aux.NUM_DIAS);
    if(aux.NUM_DIAS <= 0){
        printf("Numero de dias invalido\n");
        return 0;
    }
    printf("Digite a quantidade de horas diarias\n");
    scanf("%d", &aux.QTDE_HORAS_DIARIAS);
    if(aux.QTDE_HORAS_DIARIAS <= 0 || aux.QTDE_HORAS_DIARIAS > 8){
        printf("Hora invalida\n");
        return 0;
    }
    else{
        aux.qtde = 0;
        printf("Configuracoes salvas com sucesso\n");
        atualizacao();
    }
    return 1;
}

void atualizacao(){
    FILE *config;
    config = fopen("config.txt", "w");
    fprintf(config, "%d %d %d %d", aux.NUM_FUNC, aux.NUM_DIAS, aux.QTDE_HORAS_DIARIAS, aux.qtde);
    fclose(config);
}

void adimplentes(){
    int i, veri = -1;
    for (i = 0; i <aux.qtde; i++){
        if(funcio[i].horas>= aux.QTDE_HORAS_DIARIAS*aux.NUM_DIAS){
            printf("______________________\n");
            printf("Matricula: %d\n", funcio[i].matri);
            printf("Nome: %s\n", funcio[i].nome);
            printf("Idade: %d\n", funcio[i].idade);
            printf("Frequencia: %.2f %%\n", (100.0*funcio[i].horas)/(aux.QTDE_HORAS_DIARIAS*aux.NUM_DIAS));
            printf("______________________\n");
            veri = 1;
        }
    }
    if(veri == -1){
        printf("Lista vazia\n");
    }
}


void inadiplentes(){
    int i, veri = -1;
    for(i = 0; i<aux.qtde; i++){
        if((1.0*funcio[i].horas)/(aux.QTDE_HORAS_DIARIAS*aux.NUM_DIAS) > 0.7 && (1.0*funcio[i].horas)/(aux.QTDE_HORAS_DIARIAS*aux.NUM_DIAS) < 1.0){
            printf("______________________\n");
            printf("Matricula: %d\n", funcio[i].matri);
            printf("Nome: %s\n", funcio[i].nome);
            printf("Idade: %d\n", funcio[i].idade);
            printf("Frequencia: %.2f %%\n", (100.0*funcio[i].horas)/(aux.QTDE_HORAS_DIARIAS*aux.NUM_DIAS));
            printf("______________________\n");
            veri = 1;
        }
    }
    if(veri == -1){
        printf("Lista vazia\n");
    }
}

void demitidos(){
    int i, veri = -1, temp;
    temp = aux.qtde;
    for(i = 0; i<aux.qtde; i++){
        if((1.0*funcio[i].horas)/(aux.QTDE_HORAS_DIARIAS*aux.NUM_DIAS) <= 0.7 && funcio[i].horas>=0){
            printf("______________________\n");
            printf("Matricula: %d\n", funcio[i].matri);
            printf("Nome: %s\n", funcio[i].nome);
            printf("Idade: %d\n", funcio[i].idade);
            printf("Frequencia: %.2f\n", (100.0*funcio[i].horas)/(aux.QTDE_HORAS_DIARIAS*aux.NUM_DIAS));
            printf("______________________\n");
            veri = 1;
            temp --;
            remocao_auto(i);
        }
    }
    aux.qtde = temp;
    atualizacao();
    atribuicao();
    if(veri == -1){
        printf("Lista vazia\n");
    }
    else{
        printf("Removido(s) com sucesso\n");
    } 

}

void lista_geral(){
    int i;
    char status[15];
    if(aux.qtde == 0){
        printf("Lista vazia\n");
    }
    for(i = 0; i<aux.qtde; i++){
        if(funcio[i].horas>= aux.QTDE_HORAS_DIARIAS*aux.NUM_DIAS){
            strcpy(status, "Adimplente");
        }
        else if((1.0*funcio[i].horas)/(aux.QTDE_HORAS_DIARIAS*aux.NUM_DIAS) >= 0.7 && (1.0*funcio[i].horas)/(aux.QTDE_HORAS_DIARIAS*aux.NUM_DIAS) < 1.0){
            strcpy(status, "Inadimplente");
        }
        else if(funcio[i].horas == -1){
            strcpy(status, "Indefinido");
        }
        else{
            strcpy(status,"Demitido");
        }
        printf("______________________\n");
        printf("Matricula: %d\n", funcio[i].matri);
        printf("Nome: %s\n", funcio[i].nome);
        printf("Idade: %d\n", funcio[i].idade);
        if(funcio[i].horas > -1){
            printf("Frequencia: %.2f %%\n", (100.0*funcio[i].horas)/(aux.QTDE_HORAS_DIARIAS*aux.NUM_DIAS));
        } else{
            printf("Frequencia: Sem dados\n");
        }
        printf("Status: %s\n", status);
        printf("______________________\n");
    }
}

void ordena_matricula(){
    int i, j;
    int temp_matri, temp_idade, temp_horas;
    char temp_nome[50];
    FILE *dados_func;
    dados_func = fopen("dados func.txt", "w");
    for (i = 0; i < aux.qtde; i++) {
        for (j = i+1; j < aux.qtde; j++) {
            if (funcio[i].matri > funcio[j].matri) {
                temp_matri = funcio[i].matri;
                strcpy(temp_nome, funcio[i].nome);
                temp_idade = funcio[i].idade;
                temp_horas = funcio[i].horas;

                funcio[i].matri = funcio[j].matri;
                funcio[i].idade = funcio[j].idade;
                funcio[i].horas = funcio[j].horas;
                strcpy(funcio[i].nome, funcio[j].nome);

                funcio[j].matri = temp_matri; 
                funcio[j].idade = temp_idade;
                funcio[j].horas = temp_horas;
                strcpy(funcio[j].nome, temp_nome);            
            }
        }
    }
    for(i = 0; i <aux.qtde; i++){
        fwrite(&funcio[i], sizeof(dados), 1, dados_func);
    }
    fclose(dados_func);
    atribuicao();
}

void ordena_frequencia(){
    int i, j;
    int temp_matri, temp_idade, temp_horas;
    char temp_nome[50];
    FILE *dados_func;
    dados_func = fopen("dados func.txt", "w");
    for (i = 0; i < aux.qtde; i++) {
        for (j = i+1; j < aux.qtde; j++) {
            if (funcio[i].horas <= funcio[j].horas) {
                temp_matri = funcio[i].matri;
                strcpy(temp_nome, funcio[i].nome);
                temp_idade = funcio[i].idade;
                temp_horas = funcio[i].horas;

                funcio[i].matri = funcio[j].matri;
                funcio[i].idade = funcio[j].idade;
                funcio[i].horas = funcio[j].horas;
                strcpy(funcio[i].nome, funcio[j].nome);

                funcio[j].matri = temp_matri; 
                funcio[j].idade = temp_idade;
                funcio[j].horas = temp_horas;
                strcpy(funcio[j].nome, temp_nome);            
            }
        }
    }
    for(i = 0; i <aux.qtde; i++){
        fwrite(&funcio[i], sizeof(dados), 1, dados_func);
    }
    fclose(dados_func);
    atribuicao();
}

void modo_funcionario(){
    int op;
    while(1){
        printf("-_-_-_-_Modo Funcionario-_-_-_-_-_\n");
        printf("Cadastro de horas................1\n");
        printf("Situacao cadastral...............2\n");
        printf("Sair.............................3\n");
        scanf("%d", &op);
        system("cls");
        if(op == 3){
            exit(0);
        }
        switch(op){
            case 1: cadastra_horas(); break;
            case 2: situ_funcionarios(); break;
            default: printf("Opcao invalida\n"); break;
        }
    }

}

void cadastra_horas(){
    FILE *dados_func;
    int i, matri, horas, pos;
    dados_func = fopen("dados func.txt", "w"); 
    printf("Digite a sua matricula\n");
    scanf("%d", &matri);
    if(verifica_matricula(matri, 1) >= 0){
        pos = verifica_matricula(matri, 1);
        if(funcio[pos].horas > -1){
            printf("As horas ja foram cadastradas\n");
        }
        else{
            funcio[pos].horas += 1;
            for(i = 0; i<aux.NUM_DIAS; i++){
                printf("Digite a quantidade de horas trabalhadas no dia %d\n", i+1);
                scanf("%d", &horas);
                system("cls");
                if(verifica_horas(horas) == -1){
                    funcio[pos].horas += horas;
                    if(i == aux.NUM_DIAS-1){
                        printf("Horas armazenadas com sucesso\n");
                    }
                }
                else{
                    funcio[pos].horas = -1;
                    break;
                }
            }
        }
    }
    else{
        printf("Matricula invalida\n");
    }
    for(i = 0; i <aux.qtde; i++){
        fwrite(&funcio[i], sizeof(dados), 1, dados_func);
    }
    fclose(dados_func);
    atribuicao();

}

int verifica_horas(int horas){
    int veri = -1;
    if(horas < 0){
        printf("Nao pode ser informado uma hora negativa\n");
        veri = 1;
    }
    if(horas > 8){
        printf("Limite maximo de horas trabalhadas excedida\n");
        veri = 1;
    }
    return veri;
}

void situ_funcionarios(){
    int matri, pos;
    char status[15];
    printf("Digite a sua matricula\n");
    scanf("%d", &matri);
    if(verifica_matricula(matri, 1) >= 0){
        pos = verifica_matricula(matri, 1);
        if(funcio[pos].horas>= aux.QTDE_HORAS_DIARIAS*aux.NUM_DIAS){
            strcpy(status, "Adimplente");
        }
        else if((1.0*funcio[pos].horas)/(aux.QTDE_HORAS_DIARIAS*aux.NUM_DIAS) >= 0.7 && (1.0*funcio[pos].horas)/(aux.QTDE_HORAS_DIARIAS*aux.NUM_DIAS) <= 1.0){
            strcpy(status, "Inadimplente");
        }
        else if(funcio[pos].horas == -1){
            strcpy(status, "Indefinido");
        }
        else{
            strcpy(status,"Demitido");
        }
        printf("______________________\n");
        printf("Matricula: %d\n", funcio[pos].matri);
        printf("Nome: %s\n", funcio[pos].nome);
        printf("Idade: %d\n", funcio[pos].idade);
        if(funcio[pos].horas > -1){
            printf("Frequencia: %.2f %%\n", (100.0*funcio[pos].horas)/(aux.QTDE_HORAS_DIARIAS*aux.NUM_DIAS));
        } else{
            printf("Frequencia: Sem dados\n");
        }
        printf("Status: %s\n", status);
        printf("______________________\n")
        ;
    }
    else{
        printf("Matricula invalida\n");
    }
}

