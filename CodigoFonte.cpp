#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>


const int MAX = 50;
int Ordenacao = 0;


typedef struct DescProduto{
    
	long int Codigo;
	
	int Grupo;
	
	char Descricao[41];
	char Unidade[3];
	char Fornecedor[41];
	
    float Lucro;
    float Quantidade;
    float PrecoCompra;
    float PrecoVenda;
    float EstoqueMinimo;
    
} Produtos;


int Vazio(int Tamanho){
	
    if (Tamanho == 0){
    
	return 1;
    
}
    
	return 0;

}


void LerArquivo (Produtos Estoque[], int *Tamanho){
    
	FILE* Arquivo;
	
    Arquivo = fopen("Estoque.dat", "a+b");
	   
    if (!Arquivo){
  		
    printf("Erro ao abrir arquivo!");
    return;
  	
}
    
	while(!feof(Arquivo)){
    
	fread (&Estoque[*Tamanho], sizeof (Produtos) , 1, Arquivo);
    (*Tamanho)++;
    
}
	
	(*Tamanho)--;

    fclose(Arquivo);
    
	return;

}


void GravarArquivo (Produtos Estoque[], int Tamanho){
	
    FILE *Arquivo;
    
	int i;
	
    Arquivo = fopen("Estoque.dat", "w+b");
  	
	if (!Arquivo){
  		
	printf("Erro ao abrir arquivo!");
    return;
  	
	}
    
	for(i = 0; i < Tamanho; i++)  
    fwrite(&Estoque[i], sizeof(Produtos), 1, Arquivo);

    fclose(Arquivo);
	
	return;

}


void Ordena (Produtos Estoque[], int Tamanho){
	
	int i,j;
    
	Produtos p;
    
	for(i = 0; i < Tamanho - 1; i++)
    for(j = i + 1; j < Tamanho; j++)
    
    if (Estoque[i].Codigo > Estoque[j].Codigo){
    p = Estoque[i];
    Estoque[i] = Estoque[j];
    Estoque[j] = p;
    
}	
}


int PesquisaCodigo (Produtos Estoque[], int ChaveCodigo, int Tamanho){
    
	if(Vazio(Tamanho))
	
    return -1;       
    
	if (!Ordenacao){
		
    Ordena (Estoque, Tamanho);
    Ordenacao = 1;
    
	}
	
    int PontoInicial = 0, PontoFinal = Tamanho, MeioArquivo;
    while (PontoInicial <= PontoFinal){
    	
    MeioArquivo = (int)(PontoInicial + PontoFinal)/2;
        
	if (Estoque[MeioArquivo].Codigo == ChaveCodigo)
    return MeioArquivo;
    
	if (Estoque[MeioArquivo].Codigo < ChaveCodigo)
    PontoInicial = MeioArquivo + 1;
    
	else
    
	PontoFinal = MeioArquivo - 1;
    
}
	
    return -1;

}


void IncluirProdutos (Produtos Estoque[],int *Tamanho){
	    
	int i;
	    
    if (*Tamanho==MAX){ 
        
    printf ("\n>> ---------------------------------------  Programa de inserção de produtos  --------------------------------------- <<\n\n");
    printf ("\n Erro! Arquivo cheio.\n\n");
        
	return;
        
}
        
	Produtos p;
		
    char correto = 'n';
        
    printf ("\n>> ---------------------------------------  Programa de inserção de produtos  --------------------------------------- <<\n");
    printf (" O código pode ser de 1 a 999999999 e não pode se iniciar em 0\n\n\n");
        
	do{
        
	printf (" Digite um código de referência para esse produto ..................: ");
    scanf ("%ld",&p.Codigo);
	fflush(stdin);
    system("cls");
            
}
		
	while (p.Codigo <= 0);
        
	if (PesquisaCodigo (Estoque, p.Codigo, *Tamanho) < 0){
	
	printf ("\n>> ---------------------------------------  Programa de inserção de produtos  --------------------------------------- <<\n");
    printf (" A descrição do produto não poderá passar de 40 caracteres\n\n\n");
	printf (" Cite a descrição/nome do produto ..................................: ");
	gets (p.Descricao);
	fflush(stdin);
	system("cls");
    		
    do{
    
	printf ("\n>> ---------------------------------------  Programa de inserção de produtos  --------------------------------------- <<\n");
    printf (" A quantidade do produto não poderá passar de 9999\n\n\n");
	printf (" Qual será a quantidade a ser adicionada do produto? ...............: ");
    scanf ("%f",&p.Quantidade);
	fflush(stdin);
	system("cls");
    		 
}
		
	while(p.Quantidade <= 0 || p.Quantidade >= 10000);
		
    do{
        	
    printf ("\n>> ---------------------------------------  Programa de inserção de produtos  --------------------------------------- <<\n");
    printf (" Lembrando que o preço de compra é o valor que o produto foi comprado para ser revendido\n\n\n");
	printf (" Qual é o preço de compra do produto? ..............................: ");
    scanf ("%f",&p.PrecoCompra);
	fflush(stdin);
	system("cls");
    			  
}
		
	while(p.PrecoCompra <= 0);
		
    do{
	  
	printf ("\n>> ---------------------------------------  Programa de inserção de produtos  --------------------------------------- <<\n\n\n");
    printf (" Qual será o preço de venda desse produto? .........................: ");
	scanf ("%f", &p.PrecoVenda);
	fflush(stdin); 
	system("cls");
    	
}
	    
	while (p.PrecoVenda <= 0);
		
	do{
			
	printf ("\n>> ---------------------------------------  Programa de inserção de produtos  --------------------------------------- <<\n");
    printf (" Escolha o grupo de acordo com os números: 1 - Eletrôeletrônicos, 2 - Eletrôdomésticos, 3 - Móveis, 4 - Utilidades\n\n\n");		
	printf (" Qual é o grupo desse produto? .....................................: ");
	scanf ("%i", &p.Grupo);
	fflush(stdin);
	system("cls");
    		
}
		
	while (p.Grupo <= 0 || p.Grupo >= 5);
		
	printf ("\n>> ---------------------------------------  Programa de inserção de produtos  --------------------------------------- <<\n\n\n");
    printf (" Qual o fornecedor em que foi comprado o produto? ..................: ");
    gets (p.Fornecedor);      
    fflush(stdin);
	system("cls");
    		
	printf ("\n>> ---------------------------------------  Programa de inserção de produtos  --------------------------------------- <<\n");
    printf (" Digite abaixo as siglas disponíveis para representar a unidade, de preferência em LETRAS GRANDES\n\n\n");
	printf (" Qual é o tipo de unidade do produto? (KG/UN/LT) ...................: ");
    gets (p.Unidade);
	fflush(stdin);
	system("cls");
    
	do{		
	
	printf ("\n>> ---------------------------------------  Programa de inserção de produtos  --------------------------------------- <<\n");
    printf (" O estoque mínimo do produto não poderá passar de 9999\n\n\n");
	printf (" Qual será a quantidade mínima de estoque para esse produto? .......: ");      
    scanf ("%f", &p.EstoqueMinimo);
    fflush(stdin);
    system("cls");    

}
		
	while (p.EstoqueMinimo <= 0 || p.EstoqueMinimo >= 9999);
    
	        
    printf ("\n>> ---------------------------------------  Programa de inserção de produtos  --------------------------------------- <<\n\n");
    printf ("\n========================================================================================================================\n");
    printf ("| Descrição: %-40s | Código: %-9li | Quantidade: %-4.f |  Estoque mínimo: %-4.f   |\n", p.Descricao, p.Codigo, p.Quantidade, p.EstoqueMinimo);
    printf ("========================================================================================================================\n");
    printf ("| Fornecedor: %-39s | Unidade de venda do produto: %-2s | Grupo: %i - ", p.Fornecedor, p.Unidade, p.Grupo);
	
	if (p.Grupo == 1){
            
	printf ("Eletrôeletrônicos |\n");
			
}
            
    if (p.Grupo == 2){
            	
    printf ("Eletrôdomésticos  |\n");	
            	
}
            
            
    if (p.Grupo == 3){
            	
    printf ("Móveis            |\n");	
            	
}
            
    if (p.Grupo == 4){
            	
    printf ("Utilidades        |\n");
				
}
    
    printf ("========================================================================================================================\n");
    p.Lucro = ((p.PrecoVenda - p.PrecoCompra) / p.PrecoCompra) * 100;
    printf ("| Preço de compra: R$ %-10.2f | Preço de venda: R$ %-10.2f | Lucro: %-5.f%%                                       |\n", p.PrecoCompra, p.PrecoVenda, p.Lucro);
    printf ("========================================================================================================================\n\n");
            
            
	printf (" Os dados acima estão corretos e podem ser adicionados? (S -  Sim / N - Não)\n\n");
	printf (" - ");
    correto=getchar();
	fflush(stdin);
			
			      
    if (correto == 's'||correto == 'S'){
        	
    Estoque[*Tamanho] = p;
    (*Tamanho) ++;
    Ordenacao=0;
    printf ("\n\n Seu produto foi adicionado com sucesso!\n\n");
	GravarArquivo (Estoque, *Tamanho);
	fflush(stdin);
        
}
		
}
		
	else
		 
    printf ("\n>> ---------------------------------------  Programa de inserção de produtos  --------------------------------------- <<\n\n Código já cadastrado, utilize outro na próxima!\n\n");
    printf (" Pressione 'Enter' para retornar ao menu principal... \n\n");
    fflush(stdin);
    getchar();
    system("cls");
    
	return;

}


void RelatPreco (Produtos Estoque[], int Tamanho){
    
	Ordena (Estoque, Tamanho);
	
	printf ("\n>> ---------------------------------------------  Produtos cadastrados  --------------------------------------------- <<\n\n");
	printf ("=========================================================================================\n");
    printf ("|  Código   | Descrição                              | Preço de Compra | Preço de Venda |\n");
    printf ("=========================================================================================\n");
    
    for (int i = 0; i < Tamanho; i++){
    	
    printf ("| %-9ld | %-38.38s | R$%-11.2f   | R$%-11.2f  |\n", Estoque[i].Codigo, Estoque[i].Descricao, Estoque[i].PrecoCompra, Estoque[i].PrecoVenda);

}
    
    printf ("=========================================================================================\n");
    
    fflush (stdin);
    printf ("\n\n Pressione 'Enter' para retornar ao menu principal... \n\n");
    getchar();
    system("cls");
    
}


void AtualizarProdutos(Produtos Estoque[], int Tamanho) {
    
	long int CodigoAtt;
    int Att;
    
    printf ("\n>> -------------------------------------------  Atualização de produtos!  ------------------------------------------- <<\n\n");
    printf (" Utilize a função '5 - Relatório geral' para saber o código do produto\n");
	printf (" Lembrando que a única alteração que não pode ser feita, é no código\n\n\n");
	printf (" Digite o código do produto que deseja atualizar: ");
    scanf ("%ld", &CodigoAtt);
    
    Att = PesquisaCodigo(Estoque, CodigoAtt, Tamanho);
    
    if (Att != -1){
    
	
	system("cls");
    
	printf ("\n>> -------------------------------------------  Atualização de produtos!  ------------------------------------------- <<\n\n");
    printf ("\n========================================================================================================================\n");
    printf ("| Descrição: %-40s | Código: %-9li | Quantidade: %-4.f |  Estoque mínimo: %-4.f   |\n", Estoque[Att].Descricao, Estoque[Att].Codigo, Estoque[Att].Quantidade, Estoque[Att].EstoqueMinimo);
    printf ("========================================================================================================================\n");
    printf ("| Fornecedor: %-39s | Unidade de venda do produto: %-2s | Grupo: %i - ", Estoque[Att].Fornecedor, Estoque[Att].Unidade, Estoque[Att].Grupo);
	
	if (Estoque[Att].Grupo == 1){
            
	printf ("Eletrôeletrônicos |\n");
			
}
            
    if (Estoque[Att].Grupo == 2){
            	
    printf ("Eletrôdomésticos  |\n");	
            	
}
            
            
    if (Estoque[Att].Grupo == 3){
            	
    printf ("Móveis            |\n");	
            	
}
            
    if (Estoque[Att].Grupo == 4){
            	
    printf ("Utilidades        |\n");
				
}
    
    printf ("========================================================================================================================\n");
    Estoque[Att].Lucro = ((Estoque[Att].PrecoVenda - Estoque[Att].PrecoCompra) / Estoque[Att].PrecoCompra) * 100;
    printf ("| Preço de compra: R$ %-10.2f | Preço de venda: R$ %-10.2f | Lucro: %-5.f%%                                       |\n", Estoque[Att].PrecoCompra, Estoque[Att].PrecoVenda, Estoque[Att].Lucro);
    printf ("========================================================================================================================\n\n");
            
    
    printf("\n\n Selecione o campo que deseja atualizar:\n\n");
    printf(" 1 - Descrição\n");
    printf(" 2 - Quantidade\n");
    printf(" 3 - Preço de compra\n");
    printf(" 4 - Preço de venda\n");
    printf(" 5 - Grupo\n");
    printf(" 6 - Fornecedor\n");
    printf(" 7 - Unidade\n");
    printf(" 8 - Quantidade mínima em estoque\n\n");
        
    int OpcaoAtt;
        
    printf(" - ");
    scanf("%d", &OpcaoAtt);
    fflush(stdin);
        
    switch (OpcaoAtt){
    
	case 1:{
    
	system("cls");
    
	printf ("\n>> -------------------------------------------  Atualização de produtos!  ------------------------------------------- <<\n\n");
    printf ("\n========================================================================================================================\n");
    printf ("| Descrição: %-40s | Código: %-9li | Quantidade: %-4.f |  Estoque mínimo: %-4.f   |\n", Estoque[Att].Descricao, Estoque[Att].Codigo, Estoque[Att].Quantidade, Estoque[Att].EstoqueMinimo);
    printf ("========================================================================================================================\n");
    printf ("| Fornecedor: %-39s | Unidade de venda do produto: %-2s | Grupo: %i - ", Estoque[Att].Fornecedor, Estoque[Att].Unidade, Estoque[Att].Grupo);
	
	if (Estoque[Att].Grupo == 1){
            
	printf ("Eletrôeletrônicos |\n");
			
}
            
    if (Estoque[Att].Grupo == 2){
            	
    printf ("Eletrôdomésticos  |\n");	
            	
}
            
            
    if (Estoque[Att].Grupo == 3){
            	
    printf ("Móveis            |\n");	
            	
}
            
    if (Estoque[Att].Grupo == 4){
            	
    printf ("Utilidades        |\n");
				
}
    
    printf ("========================================================================================================================\n");
    Estoque[Att].Lucro = ((Estoque[Att].PrecoVenda - Estoque[Att].PrecoCompra) / Estoque[Att].PrecoCompra) * 100;
    printf ("| Preço de compra: R$ %-10.2f | Preço de venda: R$ %-10.2f | Lucro: %-5.f%%                                       |\n", Estoque[Att].PrecoCompra, Estoque[Att].PrecoVenda, Estoque[Att].Lucro);
    printf ("========================================================================================================================\n\n");
    
	printf (" Lembrando que a descrição tem um limite de 40 caracteres \n\n");
	printf("\n Digite a nova descrição: ");
    gets(Estoque[Att].Descricao);
	fflush(stdin);
    
	break;
    
}
    
	case 2:{
		
	do{
	
	system("cls");
    	
	printf ("\n>> -------------------------------------------  Atualização de produtos!  ------------------------------------------- <<\n\n");
    printf ("\n========================================================================================================================\n");
    printf ("| Descrição: %-40s | Código: %-9li | Quantidade: %-4.f |  Estoque mínimo: %-4.f   |\n", Estoque[Att].Descricao, Estoque[Att].Codigo, Estoque[Att].Quantidade, Estoque[Att].EstoqueMinimo);
    printf ("========================================================================================================================\n");
    printf ("| Fornecedor: %-39s | Unidade de venda do produto: %-2s | Grupo: %i - ", Estoque[Att].Fornecedor, Estoque[Att].Unidade, Estoque[Att].Grupo);
	
	if (Estoque[Att].Grupo == 1){
            
	printf ("Eletrôeletrônicos |\n");
			
}
            
    if (Estoque[Att].Grupo == 2){
            	
    printf ("Eletrôdomésticos  |\n");	
            	
}
            
            
    if (Estoque[Att].Grupo == 3){
            	
    printf ("Móveis            |\n");	
            	
}
            
    if (Estoque[Att].Grupo == 4){
            	
    printf ("Utilidades        |\n");
				
}
    
    printf ("========================================================================================================================\n");
    Estoque[Att].Lucro = ((Estoque[Att].PrecoVenda - Estoque[Att].PrecoCompra) / Estoque[Att].PrecoCompra) * 100;
    printf ("| Preço de compra: R$ %-10.2f | Preço de venda: R$ %-10.2f | Lucro: %-5.f%%                                       |\n", Estoque[Att].PrecoCompra, Estoque[Att].PrecoVenda, Estoque[Att].Lucro);
    printf ("========================================================================================================================\n\n");
   	
	printf("\n Digite a nova quantidade: ");
    scanf("%f", &Estoque[Att].Quantidade);
    fflush(stdin);
	
}

    while (Estoque[Att].Quantidade <= 0);
    
	break;
    
}
    
	case 3:{
	
	system("cls");
    
	printf ("\n>> -------------------------------------------  Atualização de produtos!  ------------------------------------------- <<\n\n");
    printf ("\n========================================================================================================================\n");
    printf ("| Descrição: %-40s | Código: %-9li | Quantidade: %-4.f |  Estoque mínimo: %-4.f   |\n", Estoque[Att].Descricao, Estoque[Att].Codigo, Estoque[Att].Quantidade, Estoque[Att].EstoqueMinimo);
    printf ("========================================================================================================================\n");
    printf ("| Fornecedor: %-39s | Unidade de venda do produto: %-2s | Grupo: %i - ", Estoque[Att].Fornecedor, Estoque[Att].Unidade, Estoque[Att].Grupo);
	
	if (Estoque[Att].Grupo == 1){
            
	printf ("Eletrôeletrônicos |\n");
			
}
            
    if (Estoque[Att].Grupo == 2){
            	
    printf ("Eletrôdomésticos  |\n");	
            	
}
            
            
    if (Estoque[Att].Grupo == 3){
            	
    printf ("Móveis            |\n");	
            	
}
            
    if (Estoque[Att].Grupo == 4){
            	
    printf ("Utilidades        |\n");
				
}
    
    printf ("========================================================================================================================\n");
    Estoque[Att].Lucro = ((Estoque[Att].PrecoVenda - Estoque[Att].PrecoCompra) / Estoque[Att].PrecoCompra) * 100;
    printf ("| Preço de compra: R$ %-10.2f | Preço de venda: R$ %-10.2f | Lucro: %-5.f%%                                       |\n", Estoque[Att].PrecoCompra, Estoque[Att].PrecoVenda, Estoque[Att].Lucro);
    printf ("========================================================================================================================\n\n");
   
	printf("\n Digite o novo preço de compra: ");
    scanf("%f", &Estoque[Att].PrecoCompra);
    fflush(stdin);
    
	break;
  
}
    
	case 4:{
    
	system("cls");
    
	printf ("\n>> -------------------------------------------  Atualização de produtos!  ------------------------------------------- <<\n\n");
    printf ("\n========================================================================================================================\n");
    printf ("| Descrição: %-40s | Código: %-9li | Quantidade: %-4.f |  Estoque mínimo: %-4.f   |\n", Estoque[Att].Descricao, Estoque[Att].Codigo, Estoque[Att].Quantidade, Estoque[Att].EstoqueMinimo);
    printf ("========================================================================================================================\n");
    printf ("| Fornecedor: %-39s | Unidade de venda do produto: %-2s | Grupo: %i - ", Estoque[Att].Fornecedor, Estoque[Att].Unidade, Estoque[Att].Grupo);
	
	if (Estoque[Att].Grupo == 1){
            
	printf ("Eletrôeletrônicos |\n");
			
}
            
    if (Estoque[Att].Grupo == 2){
            	
    printf ("Eletrôdomésticos  |\n");	
            	
}
            
            
    if (Estoque[Att].Grupo == 3){
            	
    printf ("Móveis            |\n");	
            	
}
            
    if (Estoque[Att].Grupo == 4){
            	
    printf ("Utilidades        |\n");
				
}
    
    printf ("========================================================================================================================\n");
    Estoque[Att].Lucro = ((Estoque[Att].PrecoVenda - Estoque[Att].PrecoCompra) / Estoque[Att].PrecoCompra) * 100;
    printf ("| Preço de compra: R$ %-10.2f | Preço de venda: R$ %-10.2f | Lucro: %-5.f%%                                       |\n", Estoque[Att].PrecoCompra, Estoque[Att].PrecoVenda, Estoque[Att].Lucro);
    printf ("========================================================================================================================\n\n");
   
	printf("\n Digite o novo preço de venda: ");
    scanf("%f", &Estoque[Att].PrecoVenda);
    fflush(stdin);
    
	break;
    
}
    
	case 5:{

    do{
    	
	system("cls");
    
	printf ("\n>> -------------------------------------------  Atualização de produtos!  ------------------------------------------- <<\n\n");
    printf ("\n========================================================================================================================\n");
    printf ("| Descrição: %-40s | Código: %-9li | Quantidade: %-4.f |  Estoque mínimo: %-4.f   |\n", Estoque[Att].Descricao, Estoque[Att].Codigo, Estoque[Att].Quantidade, Estoque[Att].EstoqueMinimo);
    printf ("========================================================================================================================\n");
    printf ("| Fornecedor: %-39s | Unidade de venda do produto: %-2s | Grupo: %i - ", Estoque[Att].Fornecedor, Estoque[Att].Unidade, Estoque[Att].Grupo);
	
	if (Estoque[Att].Grupo == 1){
            
	printf ("Eletrôeletrônicos |\n");
			
}
            
    if (Estoque[Att].Grupo == 2){
            	
    printf ("Eletrôdomésticos  |\n");	
            	
}
            
            
    if (Estoque[Att].Grupo == 3){
            	
    printf ("Móveis            |\n");	
            	
}
            
    if (Estoque[Att].Grupo == 4){
            	
    printf ("Utilidades        |\n");
				
}
    
    printf ("========================================================================================================================\n");
    Estoque[Att].Lucro = ((Estoque[Att].PrecoVenda - Estoque[Att].PrecoCompra) / Estoque[Att].PrecoCompra) * 100;
    printf ("| Preço de compra: R$ %-10.2f | Preço de venda: R$ %-10.2f | Lucro: %-5.f%%                                       |\n", Estoque[Att].PrecoCompra, Estoque[Att].PrecoVenda, Estoque[Att].Lucro);
    printf ("========================================================================================================================\n\n");
   
	printf("\n Digite o novo grupo: ");
    scanf("%i", &Estoque[Att].Grupo);
    fflush(stdin);

}

    while (Estoque[Att].Grupo <= 0 || Estoque[Att].Grupo >= 5);
	break;

}
    
	case 6:{
	
	system("cls");
    
	printf ("\n>> -------------------------------------------  Atualização de produtos!  ------------------------------------------- <<\n\n");
    printf ("\n========================================================================================================================\n");
    printf ("| Descrição: %-40s | Código: %-9li | Quantidade: %-4.f |  Estoque mínimo: %-4.f   |\n", Estoque[Att].Descricao, Estoque[Att].Codigo, Estoque[Att].Quantidade, Estoque[Att].EstoqueMinimo);
    printf ("========================================================================================================================\n");
    printf ("| Fornecedor: %-39s | Unidade de venda do produto: %-2s | Grupo: %i - ", Estoque[Att].Fornecedor, Estoque[Att].Unidade, Estoque[Att].Grupo);
	
	if (Estoque[Att].Grupo == 1){
            
	printf ("Eletrôeletrônicos |\n");
			
}
            
    if (Estoque[Att].Grupo == 2){
            	
    printf ("Eletrôdomésticos  |\n");	
            	
}
            
            
    if (Estoque[Att].Grupo == 3){
            	
    printf ("Móveis            |\n");	
            	
}
            
    if (Estoque[Att].Grupo == 4){
            	
    printf ("Utilidades        |\n");
				
}
    
    printf ("========================================================================================================================\n");
    Estoque[Att].Lucro = ((Estoque[Att].PrecoVenda - Estoque[Att].PrecoCompra) / Estoque[Att].PrecoCompra) * 100;
    printf ("| Preço de compra: R$ %-10.2f | Preço de venda: R$ %-10.2f | Lucro: %-5.f%%                                       |\n", Estoque[Att].PrecoCompra, Estoque[Att].PrecoVenda, Estoque[Att].Lucro);
    printf ("========================================================================================================================\n\n");
   
	printf("\n Digite o novo fornecedor: ");
    gets(Estoque[Att].Fornecedor);
	fflush(stdin);
    
	break;
 
}
    
	case 7:{
	
	system("cls");
    
	printf ("\n>> -------------------------------------------  Atualização de produtos!  ------------------------------------------- <<\n\n");
    printf ("\n========================================================================================================================\n");
    printf ("| Descrição: %-40s | Código: %-9li | Quantidade: %-4.f |  Estoque mínimo: %-4.f   |\n", Estoque[Att].Descricao, Estoque[Att].Codigo, Estoque[Att].Quantidade, Estoque[Att].EstoqueMinimo);
    printf ("========================================================================================================================\n");
    printf ("| Fornecedor: %-39s | Unidade de venda do produto: %-2s | Grupo: %i - ", Estoque[Att].Fornecedor, Estoque[Att].Unidade, Estoque[Att].Grupo);
	
	if (Estoque[Att].Grupo == 1){
            
	printf ("Eletrôeletrônicos |\n");
			
}
            
    if (Estoque[Att].Grupo == 2){
            	
    printf ("Eletrôdomésticos  |\n");	
            	
}
            
            
    if (Estoque[Att].Grupo == 3){
            	
    printf ("Móveis            |\n");	
            	
}
            
    if (Estoque[Att].Grupo == 4){
            	
    printf ("Utilidades        |\n");
				
}
    
    printf ("========================================================================================================================\n");
    Estoque[Att].Lucro = ((Estoque[Att].PrecoVenda - Estoque[Att].PrecoCompra) / Estoque[Att].PrecoCompra) * 100;
    printf ("| Preço de compra: R$ %-10.2f | Preço de venda: R$ %-10.2f | Lucro: %-5.f%%                                       |\n", Estoque[Att].PrecoCompra, Estoque[Att].PrecoVenda, Estoque[Att].Lucro);
    printf ("========================================================================================================================\n\n");
   
	printf("\n Digite a nova unidade: ");
    gets(Estoque[Att].Unidade);
	fflush(stdin);
    
	break;

}
    
	case 8:{
    
	do{
    	
	system("cls");
    
	printf ("\n>> -------------------------------------------  Atualização de produtos!  ------------------------------------------- <<\n\n");
    printf ("\n========================================================================================================================\n");
    printf ("| Descrição: %-40s | Código: %-9li | Quantidade: %-4.f |  Estoque mínimo: %-4.f   |\n", Estoque[Att].Descricao, Estoque[Att].Codigo, Estoque[Att].Quantidade, Estoque[Att].EstoqueMinimo);
    printf ("========================================================================================================================\n");
    printf ("| Fornecedor: %-39s | Unidade de venda do produto: %-2s | Grupo: %i - ", Estoque[Att].Fornecedor, Estoque[Att].Unidade, Estoque[Att].Grupo);
	
	if (Estoque[Att].Grupo == 1){
            
	printf ("Eletrôeletrônicos |\n");
			
}
            
    if (Estoque[Att].Grupo == 2){
            	
    printf ("Eletrôdomésticos  |\n");	
            	
}
            
            
    if (Estoque[Att].Grupo == 3){
            	
    printf ("Móveis            |\n");	
            	
}
            
    if (Estoque[Att].Grupo == 4){
            	
    printf ("Utilidades        |\n");
				
}
    
    printf ("========================================================================================================================\n");
    Estoque[Att].Lucro = ((Estoque[Att].PrecoVenda - Estoque[Att].PrecoCompra) / Estoque[Att].PrecoCompra) * 100;
    printf ("| Preço de compra: R$ %-10.2f | Preço de venda: R$ %-10.2f | Lucro: %-5.f%%                                       |\n", Estoque[Att].PrecoCompra, Estoque[Att].PrecoVenda, Estoque[Att].Lucro);
    printf ("========================================================================================================================\n\n");
   
	printf("\n Digite a nova quantidade mínima em estoque: ");
    scanf("%f", &Estoque[Att].EstoqueMinimo);
    fflush(stdin);
    
}

    while (Estoque[Att].EstoqueMinimo <= 0 || Estoque[Att].EstoqueMinimo >= 10000);
    break;
 
}
    
	default:{

	printf("\n Opção inválida.\n");   
    
	break;

}

}
        
    system("cls");
    
	printf ("\n>> -------------------------------------------  Atualização de produtos!  ------------------------------------------- <<\n\n");
    printf (" Produto atualizado com sucesso!\n\n");
	printf ("\n========================================================================================================================\n");
    printf ("| Descrição: %-40s | Código: %-9li | Quantidade: %-4.f |  Estoque mínimo: %-4.f   |\n", Estoque[Att].Descricao, Estoque[Att].Codigo, Estoque[Att].Quantidade, Estoque[Att].EstoqueMinimo);
    printf ("========================================================================================================================\n");
    printf ("| Fornecedor: %-39s | Unidade de venda do produto: %-2s | Grupo: %i - ", Estoque[Att].Fornecedor, Estoque[Att].Unidade, Estoque[Att].Grupo);
	
	if (Estoque[Att].Grupo == 1){
            
	printf ("Eletrôeletrônicos |\n");
			
}
            
    if (Estoque[Att].Grupo == 2){
            	
    printf ("Eletrôdomésticos  |\n");	
            	
}
            
            
    if (Estoque[Att].Grupo == 3){
            	
    printf ("Móveis            |\n");	
            	
}
            
    if (Estoque[Att].Grupo == 4){
            	
    printf ("Utilidades        |\n");
				
}
    
    printf ("========================================================================================================================\n");
    Estoque[Att].Lucro = ((Estoque[Att].PrecoVenda - Estoque[Att].PrecoCompra) / Estoque[Att].PrecoCompra) * 100;
    printf ("| Preço de compra: R$ %-10.2f | Preço de venda: R$ %-10.2f | Lucro: %-5.f%%                                       |\n", Estoque[Att].PrecoCompra, Estoque[Att].PrecoVenda, Estoque[Att].Lucro);
    printf ("========================================================================================================================\n\n");
    GravarArquivo(Estoque, Tamanho);
	
} 

    else 

{
    
	printf("\n Produto não encontrado.\n");

}
    
    printf("\n Pressione 'Enter' para retornar ao menu principal... \n\n");
    fflush(stdin);
    getchar();
    system("cls");
    
}


void ExcluirProduto(Produtos Estoque[], int *Tamanho, long int CodigoExc) {
    
	int Exc = PesquisaCodigo(Estoque, CodigoExc, *Tamanho);
    
    if (Exc != -1){
    
	system("cls");
    printf ("\n>> ---------------------------------------------  Exclusão de produtos  --------------------------------------------- <<\n\n");
    printf ("\n========================================================================================================================\n");
    printf ("| Descrição: %-40s | Código: %-9li | Quantidade: %-4.f |  Estoque mínimo: %-4.f   |\n", Estoque[Exc].Descricao, Estoque[Exc].Codigo, Estoque[Exc].Quantidade, Estoque[Exc].EstoqueMinimo);
    printf ("========================================================================================================================\n");
    printf ("| Fornecedor: %-39s | Unidade de venda do produto: %-2s | Grupo: %i - ", Estoque[Exc].Fornecedor, Estoque[Exc].Unidade, Estoque[Exc].Grupo);
	
	if (Estoque[Exc].Grupo == 1){
            
	printf ("Eletrôeletrônicos |\n");
			
}
            
    if (Estoque[Exc].Grupo == 2){
            	
    printf ("Eletrôdomésticos  |\n");	
            	
}
            
            
    if (Estoque[Exc].Grupo == 3){
            	
    printf ("Móveis            |\n");	
            	
}
            
    if (Estoque[Exc].Grupo == 4){
            	
    printf ("Utilidades        |\n");
				
}
    
    printf ("========================================================================================================================\n");
    Estoque[Exc].Lucro = ((Estoque[Exc].PrecoVenda - Estoque[Exc].PrecoCompra) / Estoque[Exc].PrecoCompra) * 100;
    printf ("| Preço de compra: R$ %-10.2f | Preço de venda: R$ %-10.2f | Lucro: %-5.f%%                                       |\n", Estoque[Exc].PrecoCompra, Estoque[Exc].PrecoVenda, Estoque[Exc].Lucro);
    printf ("========================================================================================================================\n\n");
    
    
	printf(" Deseja excluir este produto? (S/N): ");
    char OpcExc;
    scanf (" %c", &OpcExc);
    
	if (OpcExc == 'S' || OpcExc == 's') {
	    
	for (int i = Exc; i < *Tamanho - 1; i++){
    Estoque[i] = Estoque[i + 1];
    
}
        
    (*Tamanho)--;
    GravarArquivo(Estoque, *Tamanho);
    
    printf("\n Produto excluído com sucesso.\n");

}   

    else 
	
{
	
    printf("\n Exclusão cancelada.\n");
    
}
} 

    else 
	
{
 
    printf("\n Produto não encontrado.\n");
 
}
    
    
    printf("\n Pressione 'Enter' para retornar ao menu principal... \n\n");
    fflush(stdin);
    getchar();
    system("cls");

}


void RelatGeral (Produtos Estoque[], int Tamanho){
    
	Ordena (Estoque, Tamanho);
	
	int Pagina = 1;
    int ProdutosPorPagina = 2;
    int TotalPaginas = (Tamanho + ProdutosPorPagina - 1) / ProdutosPorPagina;

    while (Pagina <= TotalPaginas){
    system("cls");
    printf ("\n>> -----------------------------------------------  Relatório geral!  ----------------------------------------------- <<\n\n");
    printf ("                                                     Página %i de %i                                                   \n\n", Pagina, TotalPaginas);
    
    int Inicio = (Pagina - 1) * ProdutosPorPagina;
    int Fim = Inicio + ProdutosPorPagina;

    for (int i = Inicio; i < Fim && i < Tamanho; i++){
    
	Produtos p = Estoque[i];
    
	printf ("========================================================================================================================\n");
    printf(" Código: %-9ld\t\t\t\t\t\t\t\t\t   Grupo: %i ", p.Codigo, p.Grupo);
	
	if (p.Grupo == 1){
            
	printf ("Eletrôeletrônicos  \n");
			
}
            
    if (p.Grupo == 2){
            	
    printf ("Eletrôdomésticos   \n");	
            	
}
            
            
    if (p.Grupo == 3){
            	
    printf ("Móveis             \n");	
            	
}
            
    if (p.Grupo == 4){
            	
    printf ("Utilidades         \n");
				
}

    printf(" Descrição: %-78s Unidade: %-18s \n", p.Descricao, p.Unidade);
    printf(" Fornecedor: %-105s \n", p.Fornecedor);
    p.Lucro = ((p.PrecoVenda - p.PrecoCompra) / p.PrecoCompra) * 100;
    printf(" Preço de Compra: R$%-10.2f                 Preço de Venda: R$%-10.2f                Lucro: %.f%%    \n", p.PrecoCompra, p.PrecoVenda, p.Lucro);
    printf(" Quantidade em Estoque: %-20.f                                               Estoque Mínimo: %.f\n", p.Quantidade, p.EstoqueMinimo);
    printf ("========================================================================================================================\n\n\n");
    
}
    printf ("\n Utilize as seguintes teclas para navegar pelas páginas:\n");    
    printf(" (A - Voltar) | (D - Avançar) | (M - Voltar ao menu principal)\n\n");

    char Tecla = getch();

    if (Tecla == 'd' || Tecla == 'D') {
    Pagina++;

}   

    else
	 
    if (Tecla == 'a' || Tecla == 'A') {
    if (Pagina > 1) {
    Pagina--;

}

}   

    else 
    
	if (Tecla == 'm' || Tecla == 'M') {
    system("cls");
 
	return;

}
}

    printf(" Fim da listagem de produtos.\n");
    printf(" Pressione 'Enter' para retornar ao menu principal... \n\n");
	fflush(stdin);
    getchar();
    system("cls");

}


void RelatEspecial(Produtos Estoque[], int Tamanho) {
    
	Ordena (Estoque, Tamanho);
	
	float LucroMinimo;

    printf ("\n>> ---------------------------  Relatório especial - Produtos abaixo da margem de lucro!  --------------------------- <<\n\n");
    printf(" Digite o lucro mínimo desejado: ");
    scanf("%f", &LucroMinimo);

    int EncontrouProduto = 0;
    int ProdutosEncontrados = 0;

    for (int i = 0; i < Tamanho; i++) {
    Produtos p = Estoque[i];
    float MargemLucro = ((p.PrecoVenda - p.PrecoCompra) / p.PrecoCompra) * 100;

    if (MargemLucro < LucroMinimo) {
    if (!EncontrouProduto) {
    
}

    EncontrouProduto = 1;
    ProdutosEncontrados++;

    system("cls");

    printf ("\n>> ---------------------------  Relatório especial - Produtos abaixo da margem de lucro!  --------------------------- <<\n\n");
    printf ("                                                   Produto %i de %i                                                   \n\n", ProdutosEncontrados, Tamanho);
    printf ("========================================================================================================================\n");
    printf(" Código: %-9ld\t\t\t\t\t\t\t\t\t   Grupo: %i ", p.Codigo, p.Grupo);
	
	if (p.Grupo == 1){
            
	printf ("Eletrôeletrônicos  \n");
			
}
            
    if (p.Grupo == 2){
            	
    printf ("Eletrôdomésticos   \n");	
            	
}
            
            
    if (p.Grupo == 3){
            	
    printf ("Móveis             \n");	
            	
}
            
    if (p.Grupo == 4){
            	
    printf ("Utilidades         \n");
				
}

    printf(" Descrição: %-78s Unidade: %-18s \n", p.Descricao, p.Unidade);
    printf(" Fornecedor: %-105s \n", p.Fornecedor);
    p.Lucro = ((p.PrecoVenda - p.PrecoCompra) / p.PrecoCompra) * 100;
    printf(" Preço de Compra: R$%-10.2f                 Preço de Venda: R$%-10.2f                Lucro: %.f%%    \n", p.PrecoCompra, p.PrecoVenda, p.Lucro);
    printf(" Quantidade em Estoque: %-20.f                                               Estoque Mínima: %.f\n", p.Quantidade, p.EstoqueMinimo);
    printf ("========================================================================================================================\n\n\n");
    
    printf(" Deseja atualizar o preço para a margem correta? (Digite 'S' para Sim e 'N' para Não): ");
    char Resp;
    scanf(" %c", &Resp);
    printf("\n");
    
    if (Resp == 's' || Resp == 'S'){
    
	float PCompraNovo = p.PrecoCompra;
    float MargemCorreta = (LucroMinimo / 100 + 1) * PCompraNovo;
    Estoque[i].PrecoVenda = MargemCorreta;
    printf(" Preço de venda atualizado para a margem correta: R$%.2f\n", Estoque[i].PrecoVenda);
    printf("\n");
    
    GravarArquivo(Estoque, Tamanho);

	printf(" Pressione 'Enter' para ir para o próximo produto... \n\n");
	fflush(stdin);
    getchar();
    system("cls");

}
}
}

    if (!EncontrouProduto) {
    	
    printf(" Nenhum produto encontrado abaixo da margem de lucro mínima.\n");
    
}

    system("cls");
    printf ("\n>> ---------------------------  Relatório especial - Produtos abaixo da margem de lucro!  --------------------------- <<\n\n");
    printf (" Não há mais produtos...\n\n");
	printf (" Pressione 'Enter' para retornar ao menu principal... \n\n");
	fflush(stdin);
    getchar();
    system("cls");

}


int Vazio(int Tamanho);
int PesquisaCodigo (Produtos Estoque[], int ChaveCodigo, int Tamanho);

void LerArquivo (Produtos Estoque[], int *Tamanho);
void GravarArquivo (Produtos Estoque[], int Tamanho);
void Ordena (Produtos Estoque[], int Tamanho);
void IncluirProdutos (Produtos Estoque[],int *Tamanho);
void RelatPreco (Produtos Estoque[], int Tamanho);
void AtualizarProdutos(Produtos Estoque[], int Tamanho);
void RelatGeral (Produtos Estoque[], int Tamanho);
void RelatEspecial(Produtos Estoque[], int Tamanho);


int main(){
	
    setlocale(LC_ALL, "Portuguese");
	
	Produtos Estoque[MAX];
	
    int Tamanho=0, Escolha;
    
	LerArquivo (Estoque, &Tamanho);
    
	do{
	
	printf ("\n>> -------------------------  Seja bem vindo ao sistema de controle de estoque da FourTech  ------------------------- <<\n");	
    printf ("  Acesse as opções abaixo digitando o número que deseja e apertando a tecla 'Enter' \n\n");
	printf (" 1 - Cadastro de produtos\n");
	printf (" 2 - Atualização dos dados\n");
    printf (" 3 - Exclusão de produtos\n");
    printf (" 4 - Relatório dos produtos por preço\n");
    printf (" 5 - Relatório geral dos produtos\n");
    printf (" 6 - Relatório especial - Produtos com margem de lucro abaixo da mínima\n\n");
    printf (" 0 - Sair do sistema\n\n");
    printf (" - ");
	scanf ("%d",&Escolha);
    system("cls");
    
	switch (Escolha){
            
	case 1:{
				
    IncluirProdutos (Estoque, &Tamanho);
    			
	break;
	
}
	
	case 2:{
	        	
	AtualizarProdutos (Estoque, Tamanho);
        	
	break;
}
	        	
    case 3:{
            	
    long int CodigoExc;
    
	printf ("\n>> ---------------------------------------------  Exclusão de produtos  --------------------------------------------- <<\n\n");
	printf (" Utilize a função '5 - Relatório geral' para saber o código do produto\n\n\n");
	printf (" Digite o código do produto que deseja excluir: ");
    scanf ("%ld", &CodigoExc);
    fflush(stdin);
    
    ExcluirProduto(Estoque, &Tamanho, CodigoExc);
				         		
	break;
	
}	
	
    case 4:{
                
	RelatPreco (Estoque, Tamanho);
	         	
	break;

} 	    
	
    case 5:{
            	
    RelatGeral(Estoque, Tamanho);
            	
	break;

}	
			
	case 6:{
				
    RelatEspecial (Estoque, Tamanho);
				
	break;
	
}
			
    case 0: 
            
	printf(">> ------------------------------  Obrigado por utilizar nosso sistema, volte sempre!  ------------------------------ <<\n\n");
	system("pause");
	exit(0);
			
	break;
            
	default: 
			    
	printf (">> -----------------------  A opção digitada não condiz com as disponíveis, tente novamente!  ----------------------- <<\n\n");
    system("pause");
    system("cls");
            	
    break;
                
}
	
}
	
	while (Escolha != 0);
	
	return 0;

}
