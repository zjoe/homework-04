#include <stdio.h>
#include <string.h>
#include <time.h>
int dx[8]={-1,-1,0,1,1,1,0,-1};
int dy[8]={0,1,1,1,0,-1,-1,-1};
int board[100][100];
char words[100][26];
int N,M;
FILE *fin;
void work(int n);
int randpos(char *word, int *posx, int *posy, int *posd);
int howgood(char *word, int x, int y, int drct);
void placeword(char *word, int x, int y, int drct);
int main(int argc,char *argv[])
{
	int n,i,j;
	fin=fopen("data.txt","r");
	fscanf(fin,"%d",&n);
	for(i=1;i<=n;i++)fscanf(fin,"%s",words[i]);
	N=atoi(argv[1]);
	M=atoi(argv[2]);
	work(n);
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=M;j++)
			printf("%c ", board[i][j]);
		printf("\n");
	}
	return 0;
}
void work(int n)
{
	int i,j,posx,posy,posd,can;
	for(i=1;i<=N;i++)for(j=1;j<=M;j++)board[i][j]=' ';
	srand((int)time(0));
	for(i=1;i<=n;i++)
	{
		can=randpos(words[i],&posx,&posy,&posd);
		if(can==-1)
		{
			printf("cannot!\n");
			getchar();
		}
		placeword(words[i],posx,posy,posd);
	}
}
int randpos(char *word, int *posx, int *posy, int *posd)
{
	int max,i,x,y,d,temp;
	max=-1;
	for(i=1;i<=100000;i++)
	{
		x=rand()%N+1;
		y=rand()%M+1;
		d=rand()%8;
		temp=howgood(word,x,y,d);
		if(temp>max)
		{
			max=temp;
			*posx=x;
			*posy=y;
			*posd=d;
		}
	}
	return max;
}
int howgood(char *word, int x, int y, int drct)
{
	int xx,yy,score,i;
	xx=x;
	yy=y;
	score=0;
	for(i=0;i<strlen(word);i++)
	{
		if((xx<1 || xx>N || yy<1 || yy>M) || (board[xx][yy]!=' ' && board[xx][yy]!=word[i]))
			return -1;
		if(board[xx][yy]==word[i])
			score++;
		xx+=dx[drct];
		yy+=dy[drct];
	}
	return score;	
}
void placeword(char *word, int x, int y, int drct)
{
	int xx,yy,i;
	xx=x;
	yy=y;
	for(i=0;i<strlen(word);i++)
	{
		board[xx][yy]=word[i];
		xx+=dx[drct];
		yy+=dy[drct];
	}
} 
