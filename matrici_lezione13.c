#include <stdio.h>
#include <windows.h>
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING  0x0004
#endif
void stampa(int m[10][10],int _n,int _m);
int minimo(int m[10][10],int _n,int _m);
int massimo(int m[10][10],int _n,int _m);
int somma(int m[10][10],int _n,int _m);
float media(int s, int _n, int _m);
void main()
{
	int n,m;
	int i,j,s=0;
	float med=0;
	int mat[10][10];
	printf("\n Numero di righe e di colonne:");
	scanf("%d",&n);
	getchar();
	scanf("%d",&m);
	for (i=0;i<n;i++)
		for (j=0;j<m;j++)
			{
				printf("\n Inserisci elemento di riga: %d, colonna %d:",i+1,j+1);
				scanf("%d",&mat[i][j]);
			}
	/*for (i=0;i<n;i++)
		for (j=0;j<m;j++)
			{
				printf("\n Elemento di riga: %d, colonna %d:",i+1,j+1);
				printf(":%d",mat[i][j]);
			}*/
		stampa(mat,n,m);
		printf("\x1b[36m");
		printf("Stampa del massimo valore della matrice:-> %d\n",massimo(mat,n,m));
		printf("Stampa del mimimo valore della matrice:-> %d\n",minimo(mat,n,m));
		s=somma(mat,n,m);
		printf("Somma degli elementi di matrice: %d\n",s);
		med=media(s,n,m);
		printf("Media degli elementi di matrice: %f\n",med);
		return;
}
void stampa(int m[10][10],int _n,int _m)
{
	int i,j,k;
    // definisce il canle standard di output
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    // usa il canale handler per capire in quale modalità è settata la console
	DWORD dwMode = GetConsoleMode(hOut, &dwMode);
	// imposta il buffer della conole a virtual temrinal
    dwMode = dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	// imposta la nuova modalità di output per la console *nix based
	SetConsoleMode(hOut, dwMode);
	printf("\n");
	printf("\x1b[32m");
	for (k=0;k<_m;k++)
			printf("----------");
	for (i=0;i<_n;i++)
		{	printf("\n");
			for (j=0;j<_m;j++)
			{	printf("|");
				printf("\x1b[31m");
				printf("%8d",m[i][j]);
				printf("\x1b[32m");
				printf("|");
				
			}
		}
		printf("\n");
		for (k=0;k<_m;k++)
			printf("----------");
		printf("\n");
}
int minimo(int m[10][10],int _n,int _m)
{
	int i,j;
	int mx=m[0][0];
	for (i=0;i<_n;i++)
		for (j=0;j<_m;j++)
		{
			if (mx > m[i][j])
				mx=m[i][j];
		}
	return mx;
}
int massimo(int m[10][10],int _n,int _m)
{
	{
	int i,j;
	int mx=m[0][0];
	for (i=0;i<_n;i++)
		for (j=0;j<_m;j++)
		{
			if (mx < m[i][j])
				mx=m[i][j];
		}
	return mx;
}

}
int somma(int m[10][10],int _n,int _m)
{
	int s=0;
	int i,j;
	for (i=0;i<_n;i++)
		for (j=0;j<_m;j++)
			s+=m[i][j];
	return s;
	
}
float media(int s, int _n, int _m)
{
	float m=0;
	m=((float)s)/(_n*_m);
	return m;
}
