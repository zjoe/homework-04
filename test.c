#include<stdio.h>
#include<string.h>
#define MAXTREESIZE 2000
#define MAXLEN 22
#define MAXNUM 63
#define MAXMAT 100

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
struct Go pos[8] = {
{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}
};
/* note for *pos*
 * 0 is right
 * 1 is right down
 * 2 is down
 * 3 is ... you know
 * it is deasil(顺时针)
 */
char words[MAXNUM][MAXLEN],matrix[MAXMAT][MAXMAT];
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
			{
			cid = newnode();
			queue[id].p[ctoint(s[i])] = cid;
			}
		id = cid;
		}
	queue[id].flag = flag;
	return id;
}

int searchnode(int x,int y, int p)
{
	int id = 0,cid;
	for(;x>=0&&y>=0&&x<n&&y<m; x+=pos[p].x,y+=pos[p].y)
		{
		cid = queue[id].p[ctoint(matrix[x][y])];
		if (cid == -1)
			return -1;
		id = cid;
		if (queue[id].flag != -1)
			return queue[id].flag;
		}
	return -1;
}

int testallword()
{
	int i,j,p,count = 0,k,boo[MAXNUM]={0};
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)	
			for(p=0;p<8;p++)
			{
				k = searchnode(i,j,p);
				if (k != -1)
					{
					//printf("%d %d %c %d %s",i,j,matrix[i][j],p,words[k]);
					if (boo[k] == 0)
						{
						boo[k] = 1;
						count +=1;
						}
					else
						return -1;
					}
			}
	if (count != numw)
		return -1;
	return 0;
}


int main(void)
{
	int i,j;
	freopen("input.txt","r",stdin);
	scanf("%d\n",&numw);
	newnode();
	for(i = 0; i<numw;i++)
		{
		fgets(words[i],MAXLEN,stdin);
		if ((j = insertnode(i,words[i]))==-1)
			return -1;
		}
	while(fgets(matrix[n],100,stdin)>0)
		n += 1; 
	m = strlen(matrix[0])-1;

	if(testallword()==0)
		printf("STATE1: is good!\n");
	else
		printf("STATE1: bad!\n");
	if(n==m)
		printf("STATE2: is good\n");
	else 
		printf("STATE2: bad!\n");
	return 0;
}


