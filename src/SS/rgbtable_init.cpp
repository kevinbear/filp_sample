#include "define.h"
void init_table(Table* ctran)
{
	for(int i=0;i<256;i++)
	{
		ctran->y.c1[i]=0.299*i, ctran->y.c2[i]=0.587*i, ctran->y.c3[i]=0.114*i;
		ctran->u.c1[i]=-0.169*i, ctran->u.c2[i]=-0.331*i, ctran->u.c3[i]=0.5*i;
		ctran->v.c1[i]=0.5*i, ctran->v.c2[i]=-0.419*i, ctran->v.c3[i]=-0.081*i;
		ctran->r.c1[i]=i, ctran->r.c2[i]=1.13983*(i-128), ctran->r.c3[i]=0;
		ctran->g.c1[i]=i, ctran->g.c2[i]=-0.39465*(i-128), ctran->g.c3[i]=-0.58060*(i-128);
		ctran->b.c1[i]=i, ctran->b.c2[i]=2.03211*(i-128), ctran->b.c3[i]=0;
	}
}
