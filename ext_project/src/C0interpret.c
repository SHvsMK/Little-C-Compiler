#include <stdio.h>

#define txmax      100
#define cxmax      2000 
#define stacksize 50000

long s[stacksize];	// datastore

enum fct {
    lit, opr, lod, sto, cal, Int, jmp, jpc, end, str, giv, ldr, lda, sta, sav, get, rea, wri        // functions
};


int reg;
int reglist[100];
int listpointer = 0;

typedef struct{
    enum fct f;		// function code
    long l; 		// level
    long a; 		// displacement address
} instruction;

instruction code[cxmax+1];

long base(long b, long l){
    long b1;

    b1=b;
    while (l>0){	// find base l levels down
	b1=s[b1]; l=l-1;
    }
    return b1;
}

void interpret(){printf("begin interpret!\n");
    long p,b,t;		// program-, base-, topstack-registers
    instruction i;	// instruction register
int x = 0, cc = 0;
int val;
int wyc = 0;
    printf("start PL/0\n");
    t=0; b=2; p=0;
    s[1]=0; s[2]=0; s[3]=0; s[4] = 0;
    do{cc++;
/*if(cc > 20)
break;*/
//printf("Step %d:(b=%d t=%d)\n",p,b,t);
	i=code[p]; p=p+1;
	switch(i.f){
	    case lit:
		t=t+1; s[t]=i.a;
		break;
	    case opr:
		switch(i.a){ 	// operator
		    case -1:	// return
			t=b-1; p=s[t+3]; b=s[t+2];
			break;
		    case 0:	// return
			t=b-2; p=s[t+4]; b=s[t+3];
			break;
		    case 1:
			s[t]=-s[t];
			break;
		    case 2:
			t=t-1; s[t]=s[t]+s[t+1];
			break;
		    case 3:
			t=t-1; s[t]=s[t]-s[t+1];
			break;
		    case 4:
			t=t-1; s[t]=s[t]*s[t+1];
			break;
		    case 5:
			t=t-1; s[t]=s[t]/s[t+1];
			break;
		    case 6:
			t=t-1; s[t]=s[t]%s[t+1];
			break;
		    case 8:
			t=t-1; s[t]=(s[t]==s[t+1]);
			break;
		    case 9:
			t=t-1; s[t]=(s[t]!=s[t+1]);
			break;
		    case 10:
			t=t-1; s[t]=(s[t]<s[t+1]);
			break;
		    case 11:
			t=t-1; s[t]=(s[t]>=s[t+1]);
			break;
		    case 12:
			t=t-1; s[t]=(s[t]>s[t+1]);
			break;
		    case 13:
			t=t-1; s[t]=(s[t]<=s[t+1]);
		}
		break;
	    case lod:
		t=t+1;
		s[t]=s[base(b,i.l)+i.a + 2];
		break;
	    case sto:
		s[base(b,i.l)+i.a + 2]=s[t];
		//printf("%10ld\n", s[t]);
		t=t-1;
		break;
	    case cal:		// generate new block mark
		s[t+2]=base(b,i.l); s[t+3]=b; s[t+4]=p;
		b=t+2; p=i.a;
		break;
	    case Int:
		t=t+i.a;
		break;
	    case jmp:
		p=i.a;
		break;
	    case end:
		break;
	    case str:
		if(i.a == 1)
		{
			reg = s[t];
			t = t - 1;
		}
		else if(i.a == 2)
		{
			wyc = s[t];
			s[b - 1] = wyc;
		}
		break;
	    case giv:
		s[t + i.a + 1] = reg;
		break;
	    case ldr:
		t = t + 1;
		s[t] = reg;
		break;
	    case lda:
		t = t + 1;
		s[t]=s[base(b,i.l)+ reg + 2];
		break;
	    case sta:
		s[base(b,i.l)+ reg + 2]=s[t];
		//printf("%10ld\n", s[t]);
		t=t-1;
		break;
	    case sav:
		listpointer++;
		reglist[listpointer] = reg;
		break;
	    case get:
		reg = reglist[listpointer];
		listpointer--;
		break;
	    case rea:
		scanf("%d", &val);
		t = t + 1;
		s[t] = val;
		break;
	    case wri:
		printf("%ld ", s[t]);
		t = t - 1;
		break;
	    case jpc:
		if(s[t]==0){
		    p=i.a;
		}
		t=t-1;
	}//printf("(b=%d t=%d)\n",b,t);
/*for(x = t+5; x >= 1; x--)
printf("%d %ld\n",x, s[x]);*/
    }while(p!=0);
    printf("\nend PL/0\n");
}

int main(int argc, char*argv[])
{
	FILE * file;
	int i;
	char c[4];
	long l1, a1;
	file = fopen(argv[1], "r");
	while(fscanf(file, "%d%s%ld%ld", &i, c, &l1, &a1)!=NULL)
	{
		code[i].l = l1;
		code[i].a = a1;
		if(strcmp(c, "lit") == 0)
		{
			code[i].f = lit;
		}
		else if(strcmp(c, "lod") == 0)
		{
			code[i].f = lod;
		}
		else if(strcmp(c, "sto") == 0)
		{
			code[i].f = sto;
		}
		else if(strcmp(c, "cal") == 0)
		{
			code[i].f = cal;
		}
		else if(strcmp(c, "int") == 0)
		{
			code[i].f = Int;
		}
		else if(strcmp(c, "jmp") == 0)
		{
			code[i].f = jmp;
		}
		else if(strcmp(c, "jpc") == 0)
		{
			code[i].f = jpc;
		}
		else if(strcmp(c, "opr") == 0)
		{
			code[i].f = opr;
		}
		else if(strcmp(c, "end") == 0)
		{
			code[i].f = end;
			break;
		}
		else if(strcmp(c, "str") == 0)
		{
			code[i].f = str;
		}
		else if(strcmp(c, "giv") == 0)
		{
			code[i].f = giv;
		}
		else if(strcmp(c, "ldr") == 0)
		{
			code[i].f = ldr;
		}
		else if(strcmp(c, "lda") == 0)
		{
			code[i].f = lda;
		}
		else if(strcmp(c, "sta") == 0)
		{
			code[i].f = sta;
		}
		else if(strcmp(c, "sav") == 0)
		{
			code[i].f = sav;
		}
		else if(strcmp(c, "get") == 0)
		{
			code[i].f = get;
		}
		else if(strcmp(c, "rea") == 0)
		{
			code[i].f = rea;
		}
		else if(strcmp(c, "wri") == 0)
		{
			code[i].f = wri;
		}
	}
	interpret();
	fclose(file);
	return 0;
}
