#include<stdio.h>
#include<string.h>
#define MAXTREESIZE 2000
#define MAXLEN 22
#define MAXNUM 63
struct Node
{
	int flag;
	int p[26];
};
struct Go
{
	int x;
	int y;
};
struct Node queue[MAXTREESIZE];
struct Go Pos[8] = {
{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,-1}
};
char words[MAXNUM][MAXLEN],matrix[100][100];
int numw,n,m,numnode;

int ctoint(char c)
{
	if (c >= 'a' && c<='z') return c-'a';
	if (c >= 'A' && c<='Z') return c-'A';
	return -1;
}

int newnode()
{
	int i;
	queue[numnode].flag = -1;
	for(i = 0;i<26;i++)
		queue[numnode].p[i] = -1;
	numnode += 1;
	return numnode-1;
}

int insertnode(int flag,char s[])
{
	int i,id = 0,cid;
	for(i = 0;i<strlen(s)-1;i++)
		{
		if (ctoint(s[i]) == -1)
			return -1;
		cid = queue[id].p[ctoint(s[i])];
		if (cid == -1)
			cid = newnode();
		id = cid;
		}
	queue[id].flag = flag;
	return id;
}

int searchnode( char s[])
{
	int i,id = 0,cid;
	for(i=0;i<strlen(s)-1;i++)
		{
		cid = queue[id].p[ctoint(s[i])];
		if (cid == -1)
			return -1;
		id = cid;
		if (queue[id].flag != -1)
			return queue[id].flag;
		}
}

int main(void)
{
	int i,j;
	freopen("input.txt","r",stdin);
	scanf("%d",&numw);
	newnode();
	for(i = 0; i<numw;i++)
		{
		fgets(words[i],MAXLEN,stdin);
		if ((j = insertnode(i,words[i]))==-1)
			return -1;
		//printf("%d %d\n",i,j);
		}
	while(fgets(matrix[n],100,stdin)>0)
		n += 1;
	m = strlen(matrix[0]);
	//printf("%d %d",numnode,numw);
}
