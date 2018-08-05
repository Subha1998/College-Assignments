#define MAX 100
#include<stdio.h>
struct graph
{
	int u;
	int v;
	int w;
	int p;
	int rank;
}M[MAX],T[MAX];
void create(int x)
{
    M[x].p=x;
    M[x].rank=0;
}
int search(int x)
{
    if(x!=M[x].p)
        M[x].p=search(M[x].p);
    return(M[x].p);
}
void link(int x,int y)
{
    if(M[x].rank>M[y].rank)
        M[y].p=x;
    else
        M[x].p=y;
    if(M[x].rank==M[y].rank)
        M[y].rank=M[y].rank+1;
}
void Union(int x,int y)
{
    link(search(x),search(y));
}
void main(int argc,char *argv[])
{
	int n,m,i,j,temp,c=0,k,ctr=0,sum=0;
	FILE *fp;
	fp=fopen("input.txt","r");
	fscanf(fp,"%d%d",&n,&m);
	for(i=0;i<m;i++)
		fscanf(fp,"%d%d%d",&M[i].u,&M[i].v,&M[i].w);
	fclose(fp);
	for(i=0;i<n;i++)
	{
		create(i);
	}
	for(i=0;i<m;i++)
	{
		for(j=i+1;j<m;j++)
		{
			if(M[i].w>M[j].w)
			{
				temp=M[i].w;
				M[i].w=M[j].w;
				M[j].w=temp;

				temp=M[i].u;
				M[i].u=M[j].u;
				M[j].u=temp;

				temp=M[i].v;
				M[i].v=M[j].v;
				M[j].v=temp;
			}
		}
	}
	for(i=0;i<m;i++)
    {
        if(search(M[i].u)!=search(M[i].v))
        {
            T[ctr].u=M[i].u;
            T[ctr].v=M[i].v;
            T[ctr].w=M[i].w;
            ctr++;
            Union(M[i].u,M[i].v);
        }
    }
    for(i=0;i<ctr;i++)
        sum+=T[i].w;
    for(i=0;i<ctr;i++)
    {
        printf("%d %d %d\n",T[i].u,T[i].v,T[i].w);
    }
    printf("%d\n",sum);
}
