#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "common.h"

ASTNode *LOOK;
int ff=0;

ASTNode
newProgram(ASTNode CDecl, ASTNode IntDecl1, ASTNode VDecl, ASTNode IntDecl2, ASTNode Stmt)
{
	ASTNode new;
	NEW0(new);
	new->kind = KProgram;
	Pro newpro;
	NEW0(newpro);
	newpro->kids[0] = CDecl;
	newpro->kids[1] = IntDecl1;
	newpro->kids[2] = VDecl;
	newpro->kids[3] = IntDecl2;
	newpro->kids[4] = Stmt;
	if(CDecl->kind != KNULL && IntDecl1->kind != KNULL)
	newpro->alloc = CDecl->cde->alloc + IntDecl1->intde->alloc;
	else if(CDecl->kind == KNULL && IntDecl1->kind != KNULL)
	newpro->alloc = IntDecl1->intde->alloc;
	else if(CDecl->kind != KNULL && IntDecl1->kind == KNULL)
	newpro->alloc = CDecl->cde->alloc;
	else if(CDecl->kind == KNULL && IntDecl1->kind == KNULL)
	newpro->alloc = 0;
	new->pro = newpro;
	return new;
}

ASTNode
newCDecl(Table ptab,char *name, int front, int num, ASTNode CIDC, ASTNode CDecl)
{
	ASTNode new;
	NEW0(new);
	new->kind = KCDecl;
	CDe newcde;
	NEW0(newcde);
	newcde->kids[0] = CIDC;
	newcde->kids[1] = CDecl;
	newcde->front = front;
	AddSym(ptab, name);
	newcde->sym = FindSym(ptab, name);
	newcde->value = num;
	if(CIDC->kind != KNULL && CDecl->kind != KNULL)
	newcde->alloc = 1 + CIDC->cidc->alloc + CDecl->cde->alloc;
	else if(CIDC->kind == KNULL && CDecl->kind != KNULL)
	newcde->alloc = 1 + CDecl->cde->alloc;
	else if(CIDC->kind != KNULL && CDecl->kind == KNULL)
	newcde->alloc = 1 + CIDC->cidc->alloc;
	else if(CIDC->kind == KNULL && CDecl->kind == KNULL)
	newcde->alloc = 1;
	new->cde = newcde;
	return new;
}

ASTNode
newCIDC(Table ptab, char *name, int front, int num, ASTNode CIDC)
{
	ASTNode new;
	NEW0(new);
	new->kind = KCIDC;
	CIDc newcidc;
	NEW0(newcidc);
	newcidc->kids[0] = CIDC;
	newcidc->front = front;
	AddSym(ptab, name);
	newcidc->sym = FindSym(ptab, name);
	newcidc->value = num;
	if(CIDC->kind != KNULL)
	newcidc->alloc = 1 + CIDC->cidc->alloc;
	else
	newcidc->alloc = 1;
	new->cidc = newcidc;
	return new;
}

ASTNode
newIntDecl(Table ptab, char *name, ASTNode BN, ASTNode CIDI, ASTNode IntDecl)
{
	ASTNode new;
	NEW0(new);
	new->kind = KIntDecl;
	IntDe newintde;
	NEW0(newintde);
	newintde->kids[0] = BN;
	newintde->kids[1] = CIDI;
	newintde->kids[2] = IntDecl;
	AddSym(ptab, name);
	newintde->sym = FindSym(ptab, name);
	if(CIDI->kind != KNULL && IntDecl->kind != KNULL)
	newintde->alloc = 1 + CIDI->cidi->alloc + IntDecl->intde->alloc;
	if(CIDI->kind == KNULL && IntDecl->kind != KNULL)
	newintde->alloc = 1 + IntDecl->intde->alloc;
	if(CIDI->kind != KNULL && IntDecl->kind == KNULL)
	newintde->alloc = 1 + CIDI->cidi->alloc;
	if(CIDI->kind == KNULL && IntDecl->kind == KNULL)
	newintde->alloc = 1;
	new->intde = newintde;
	return new;
}

ASTNode
newCIDI(Table ptab, char *name, ASTNode BN, ASTNode CIDI)
{
	ASTNode new;
	NEW0(new);
	new->kind = KCIDI;
	CIDi newcidi;
	NEW0(newcidi);
	newcidi->kids[0] = BN;
	newcidi->kids[1] = CIDI;
	AddSym(ptab, name);
	newcidi->sym = FindSym(ptab, name);
	if(CIDI->kind != KNULL)
	newcidi->alloc = 1 + CIDI->cidi->alloc;
	else
	newcidi->alloc = 1;
	new->cidi = newcidi;
	return new;
}

ASTNode
newBN(int front, int num)
{
	ASTNode new;
	NEW0(new);
	new->kind = KBN;
	BN newbn;
	NEW0(newbn);
	newbn->front = front;
	newbn->value = num;
	new->bn = newbn;
	return new;
}

ASTNode
newVDecl(Table ptab, char *name, ASTNode CDecl, ASTNode IntDecl, ASTNode Stmt, ASTNode VDecl)
{
	ASTNode new;
	NEW0(new);
	new->kind = KVDecl;
	Vde newvde;
	NEW0(newvde);
	newvde->kids[0] = CDecl;
	newvde->kids[1] = IntDecl;
	newvde->kids[2] = Stmt;
	newvde->kids[3] = VDecl;
	AddSym(ptab, name);
	newvde->sym = FindSym(ptab, name);
	if(CDecl->kind != KNULL && IntDecl->kind != KNULL)
	newvde->alloc = CDecl->cde->alloc + IntDecl->intde->alloc;
	if(CDecl->kind == KNULL && IntDecl->kind != KNULL)
	newvde->alloc = IntDecl->intde->alloc;
	if(CDecl->kind != KNULL && IntDecl->kind == KNULL)
	newvde->alloc = CDecl->cde->alloc;
	if(CDecl->kind == KNULL && IntDecl->kind == KNULL)
	newvde->alloc = 0;		
	new->vde = newvde;
	return new;
}

ASTNode
newASGN(ASTNode Factor, ASTNode IDT, ASTNode Stmt)
{
	ASTNode new;
	NEW0(new);
	new->kind = KStmt;
	Stm newstm;
	NEW0(newstm);
	newstm->kind = ASGNSYM;
	newstm->kidsA[0] = Factor;
	newstm->kidsA[1] = IDT;
	newstm->kidsA[2] = Stmt;
	new->stm = newstm;
	return new;
}

ASTNode
newIF(ASTNode cond, ASTNode Stmt1, ASTNode Stmt2)
{
	ASTNode new;
	NEW0(new);
	new->kind = KStmt;
	Stm newstm;
	NEW0(newstm);
	newstm->kind = IFSYM;
	newstm->kidsI[0] = cond;
	newstm->kidsI[1] = Stmt1;
	newstm->kidsI[2] = Stmt2;
	new->stm = newstm;
	return new;
}

ASTNode
newWHILE(ASTNode cond, ASTNode Stmt1, ASTNode Stmt2)
{
	ASTNode new;
	NEW0(new);
	new->kind = KStmt;
	Stm newstm;
	NEW0(newstm);
	newstm->kind = WHILESYM;
	newstm->kidsW[0] = cond;
	newstm->kidsW[1] = Stmt1;
	newstm->kidsW[2] = Stmt2;
	new->stm = newstm;
	return new;
}

ASTNode
newRETURN(ASTNode Stmt)
{
	ASTNode new;
	NEW0(new);
	new->kind = KStmt;
	Stm newstm;
	NEW0(newstm);
	newstm->kind = RETURNSYM;
	newstm->kidsR[0] = Stmt;
	new->stm = newstm;
	return new;
}

ASTNode
newBE(ASTNode Exp)
{
	ASTNode new;
	NEW0(new);
	new->kind = KIDT;
	IDt newidt;
	NEW0(newidt);
	newidt->kind = BE;
	newidt->kids[0] = Exp;
	new->idt = newidt;
	return new;
}

ASTNode
newLR()
{
	ASTNode new;
	NEW0(new);
	new->kind = KIDT;
	IDt newidt;
	NEW0(newidt);
	newidt->kind = LR;
	new->idt = newidt;
	return new;
}

ASTNode
newcond(ASTNode Exp1, int RelOp, ASTNode Exp2)
{
	ASTNode new;
	NEW0(new);
	new->kind = Kcond;
	Cond newcondi;
	NEW0(newcondi);
	newcondi->kids[0] = Exp1;
	newcondi->kids[1] = Exp2;
	newcondi->op = RelOp;
	new->condi = newcondi;
	return new;
}

ASTNode
newExp(int front, ASTNode Term, ASTNode TM)
{
	ASTNode new;
	NEW0(new);
	new->kind = KExp;
	Ex newexp;
	NEW0(newexp);
	newexp->kids[0] = Term;
	newexp->kids[1] = TM;
	newexp->front = front;
	new->exp = newexp;
	return new;
}

ASTNode
newTM(int front, ASTNode Term, ASTNode TM)
{
	ASTNode new;
	NEW0(new);
	new->kind = KTM;
	Tm newtm;
	NEW0(newtm);
	newtm->kids[0] = Term;
	newtm->kids[1] = TM;
	newtm->front = front;
	new->tm = newtm;
	return new;
}

ASTNode
newTerm(ASTNode Factor, ASTNode FT)
{
	ASTNode new;
	NEW0(new);
	new->kind = KTerm;
	Ter newterm;
	NEW0(newterm);
	newterm->kids[0] = Factor;
	newterm->kids[1] = FT;
	new->term = newterm;
	return new;
}

ASTNode
newFT(int frontF, ASTNode Factor, ASTNode FT)
{
	ASTNode new;
	NEW0(new);
	new->kind = KFT;
	Ft newft;
	NEW0(newft);
	newft->kids[0] = Factor;
	newft->kids[1] = FT;
	newft->frontF = frontF;
	new->ft = newft;
	return new;
}

ASTNode
newFactori(Table ptab, char *name)
{
	ASTNode new;
	NEW0(new);
	new->kind = KFactor;
	Factor newfactor;
	NEW0(newfactor);
	newfactor->kind = IDENT;
	AddSym(ptab, name);
	newfactor->sym = FindSym(ptab, name);
	new->factor = newfactor;
	return new;
}

ASTNode
newFactorn(int num)
{
	ASTNode new;
	NEW0(new);
	new->kind = KFactor;
	Factor newfactor;
	NEW0(newfactor);
	newfactor->kind = NUM;
	newfactor->value = num;
	new->factor = newfactor;
	return new;
}

ASTNode
newFactorE(ASTNode Exp)
{
	ASTNode new;
	NEW0(new);
	new->kind = KFactor;
	Factor newfactor;
	NEW0(newfactor);
	newfactor->kind = EXP;
	newfactor->kids[0] = Exp;
	new->factor = newfactor;
	return new;
}

ASTNode
newnull()
{
	ASTNode new;
	NEW0(new);
	new->kind = KNULL;
	return new;
}

ASTTree
newAST()
{
	ASTTree new;
	NEW0(new);
	return new;
}

void dumpAST(ASTNode node)
{
	int kind = node->kind;
	switch(kind){
		case(KProgram):
		{
			dumpAST(node->pro->kids[0]);
			dumpAST(node->pro->kids[1]);
			dumpAST(node->pro->kids[2]);
			printf("main()\n");
			printf("{\n");
			dumpAST(node->pro->kids[3]);
			dumpAST(node->pro->kids[4]);
			printf("}\n");
			break;
		}
		case(KCDecl):
		{
			printf("const ");
			printf("%s = ", node->cde->sym->name);
			switch(node->cde->front){
				case(0): break;
				case(1):
				{
					printf("+");
					break;
				}
				case(2):
				{
					printf("-");
					break;
				}
				default:
				{
					printf("Unhandled ASTNode kind(KCDecl)!\n");
					break;
				}
			}
			printf("%d", node->cde->value);
			dumpAST(node->cde->kids[0]);
			printf(";\n");
			dumpAST(node->cde->kids[1]);
			break;
		}
		case(KIntDecl):
		{
			printf("int ");
			printf("%s", node->intde->sym->name);
			dumpAST(node->intde->kids[0]);
			dumpAST(node->intde->kids[1]);
			printf(";\n");
			dumpAST(node->intde->kids[2]);
			break;
		}
		case(KCIDC):
		{
			printf(", %s = ", node->cidc->sym->name);
			switch(node->cidc->front){
				case(0): break;
				case(1):
				{
					printf("+");
					break;
				}
				case(2):
				{
					printf("-");
					break;
				}
				default:
				{
					printf("Unhandled ASTNode kind(KCIDC)!\n");
					break;
				}
			}
			printf("%d", node->cidc->value);
			dumpAST(node->cidc->kids[0]);
			break;
		}
		case(KCIDI):
		{
			printf(", %s ", node->cidi->sym->name);
			dumpAST(node->cidi->kids[0]);
			dumpAST(node->cidi->kids[1]);
			break;
		}
		case(KBN):
		{
			printf(" = ");
			switch(node->bn->front){
				case(0): break;
				case(1):
				{
					printf("+");
					break;
				}
				case(2):
				{
					printf("-");
					break;
				}
				default:
				{
					printf("Unhandled ASTNode kind(KBN)!\n");
					break;
				}
			}
			printf("%d", node->bn->value);
			break;
		}
		case(KVDecl):
		{
			printf("void %s()\n{\n", node->vde->sym->name);
			dumpAST(node->vde->kids[0]);
			dumpAST(node->vde->kids[1]);
			dumpAST(node->vde->kids[2]);
			printf("}\n");
			dumpAST(node->vde->kids[3]);
			break;
		}
		case(KStmt):
		{
			switch(node->stm->kind){
				case(ASGNSYM):
				{
					dumpAST(node->stm->kidsA[0]);
					dumpAST(node->stm->kidsA[1]);
					printf(";\n");
					dumpAST(node->stm->kidsA[2]);
					break;
				}
				case(IFSYM):
				{
					printf("if(");
					dumpAST(node->stm->kidsI[0]);
					printf(")\n{\n");
					dumpAST(node->stm->kidsI[1]);
					printf("}\n");
					dumpAST(node->stm->kidsI[2]);
					break;
				}
				case(WHILESYM):
				{
					printf("while(");
					dumpAST(node->stm->kidsW[0]);
					printf(")\n{\n");
					dumpAST(node->stm->kidsW[1]);
					printf("}\n");
					dumpAST(node->stm->kidsW[2]);
					break;
				}
				case(RETURNSYM):
				{
					printf("return;\n");
					dumpAST(node->stm->kidsR[0]);
					break;
				}
				default:
				{
					printf("Unhandled ASTNode kind(KStmt)!\n");
					break;
				}
			}
			break;
		}
		case(KIDT):
		{
			if(node->idt->kind == BE)
			{
				printf(" = ");
				dumpAST(node->idt->kids[0]);
			}
			else
			{
				printf("()");
			}
			break;
		}
		case(Kcond):
		{
			dumpAST(node->condi->kids[0]);
			printf(" ");
			switch(node->condi->op){
				case(1):
				{
					printf("== ");
					break;
				}
				case(2):
				{
					printf("<= ");
					break;
				}
				case(3):
				{
					printf(">= ");
					break;
				}
				case(4):
				{
					printf("< ");
					break;
				}
				case(5):
				{
					printf("> ");
					break;
				}
				case(6):
				{
					printf("!= ");
					break;
				}
				default:
				{
					printf("Unhandled ASTNode kind(Kcond)!\n");
					break;
				}
			}
			dumpAST(node->condi->kids[1]);
			break;
		}
		case(KExp):
		{
			switch(node->exp->front){
				case(0): break;
				case(1):
				{
					printf("+");
					break;
				}
				case(2):
				{
					printf("-");
					break;
				}
				default:
				{
					printf("Unhandled ASTNode kind(KExp)!\n");
					break;
				}
			}
			dumpAST(node->exp->kids[0]);
			dumpAST(node->exp->kids[1]);
			break;
		}
		case(KTM):
		{
			switch(node->tm->front){
				case(1):
				{
					printf("+");
					break;
				}
				case(2):
				{
					printf("-");
					break;
				}
				default:
				{
					printf("Unhandled ASTNode kind(KTM)!\n");
					break;
				}
			}
			dumpAST(node->tm->kids[0]);
			dumpAST(node->tm->kids[1]);
			break;
		}
		case(KTerm):
		{
			dumpAST(node->term->kids[0]);
			dumpAST(node->term->kids[1]);
			break;
		}
		case(KFT):
		{
			switch(node->ft->frontF){
				case(1):
				{
					printf("*");
					break;
				}
				case(2):
				{
					printf("/");
					break;
				}
				case(3):
				{
					printf("%%");
					break;
				}
				default:
				{
					printf("Unhandled ASTNode kind(KFT)!\n");
					break;
				}
			}
			dumpAST(node->ft->kids[0]);
			dumpAST(node->ft->kids[1]);
			break;
		}
		case(KFactor):
		{
			switch(node->factor->kind){
				case(IDENT):
				{
					printf("%s", node->factor->sym->name);
					break;
				}
				case(NUM):
				{
					printf("%d", node->factor->value);
					break;
				}
				case(EXP):
				{
					printf("(");
					dumpAST(node->factor->kids[0]);
					printf(")");
					break;
				}
				default:
				{
					printf("Unhandled ASTNode kind(KFactor)!\n");
					break;
				}
			}
			break;
		}
		case(KNULL):
		{
			break;
		}
		default:
		{
			printf("Unhandled ASTNode kind(default)!\n");
			break;
		}
	}
}

Loc
setLoc(ASTNode node, Loc loc)//fline, int fcol, int lline, int lcol)
{
	if (node->loc == NULL )
		NEW0(node->loc);
	node->loc->first_line = loc->first_line;
	node->loc->first_column = loc->first_column;
	node->loc->last_line = loc->last_line;
	node->loc->last_column = loc->last_column;
	return node->loc;
}

void gen(enum fct x, long y, long z){
    if(cx>cxmax){
	printf("program too long\n");
	exit(1);
    }
    code[cx].f=x; code[cx].l=y; code[cx].a=z;
    cx=cx+1;
}

void Gen_P_Code(ASTNode node)
{
	int kind = node->kind;
	switch(kind){
		case(KProgram):
		{
			int cx1;
			gen(Int, 0, node->pro->alloc + 3);
			lev = 0;
			dx = 0;
			Gen_P_Code(node->pro->kids[0]);
			Gen_P_Code(node->pro->kids[1]);
			dx = 0;
			Gen_P_Code(node->pro->kids[2]);
			lev = 1;
			gen(cal, 0, cx + 2);
			gen(jmp, 0, 0);
			if(node->pro->kids[3]->kind != KNULL)
			gen(Int, 0, node->pro->kids[3]->intde->alloc + 3);
			else
			gen(Int, 0, 3);
			dx = 0;
			Gen_P_Code(node->pro->kids[3]);
			Gen_P_Code(node->pro->kids[4]);
			gen(jmp, 0, 0);
			gen(end, 0, 0);
			break;
		}
		case(KCDecl):
		{
			int i;
			dx = dx + 1;
			tx = tx + 1;
			Symtable[tx].name = node->cde->sym->name;
			Symtable[tx].level = lev;
			Symtable[tx].addr = dx;
			i = dx;
			if(node->cde->front == 0 || node->cde->front == 1)
			Symtable[tx].val = node->cde->value;
			else
			Symtable[tx].val = -node->cde->value;
			Symtable[tx].kind = constant;
			gen(lit, 0, Symtable[tx].val);
			gen(sto, lev - Symtable[i].level, i);
			Gen_P_Code(node->cde->kids[0]);
			Gen_P_Code(node->cde->kids[1]);
			break;
		}
		case(KIntDecl):
		{
			int i;
			tx = tx + 1;
			dx = dx + 1;
			Symtable[tx].name = node->intde->sym->name;
			Symtable[tx].level = lev;
			Symtable[tx].addr = dx;
			Symtable[tx].kind = variable;
			i = dx;
			if(node->intde->kids[0]->kind == KBN)
			{
				if(node->intde->kids[0]->bn->front == 0 || node->intde->kids[0]->bn->front == 1)
				gen(lit, 0, node->intde->kids[0]->bn->value);
				else
				gen(lit, 0, -node->intde->kids[0]->bn->value);
				gen(sto, lev - Symtable[i].level, i);
			}
			Gen_P_Code(node->intde->kids[1]);
			Gen_P_Code(node->intde->kids[2]);
			break;
		}
		case(KCIDC):
		{
			int i;
			dx = dx + 1;
			tx = tx + 1;
			Symtable[tx].name = node->cidc->sym->name;
			Symtable[tx].level = lev;
			Symtable[tx].addr = dx;
			Symtable[tx].kind = constant;
			i = dx;
			if(node->cidc->front == 0 || node->cidc->front == 1)
			Symtable[tx].val = node->cidc->value;
			else
			Symtable[tx].val = -node->cidc->value;
			gen(lit, 0, Symtable[tx].val);
			gen(sto, lev - Symtable[i].level, i);
			Gen_P_Code(node->cidc->kids[0]);
			break;
		}
		case(KCIDI):
		{
			int i;
			dx = dx + 1;
			tx = tx + 1;
			Symtable[tx].name = node->cidi->sym->name;
			Symtable[tx].level = lev;
			Symtable[tx].addr = dx;
			Symtable[tx].kind = variable;
			i = dx;
			if(node->cidi->kids[0]->kind != KNULL)
			{
				if(node->cidi->kids[0]->bn->front == 0 || node->cidi->kids[0]->bn->front == 1)
				gen(lit, 0, node->cidi->kids[0]->bn->value);
				else
				gen(lit, 0, -node->cidi->kids[0]->bn->value);
				gen(sto, lev - Symtable[i].level, i);
			}
			Gen_P_Code(node->intde->kids[1]);
			break;
		}
		case(KVDecl):
		{
			int tx1, cx1;
			int i;
			tx = tx + 1;
			dx = 0;
			cx1 = cx;
			gen(jmp, 0, 0);
			Symtable[tx].name = node->vde->sym->name;
			Symtable[tx].level = lev;
			Symtable[tx].addr = cx;
			Symtable[tx].kind = proc;
			lev = lev + 1;
			gen(Int, 0, node->vde->alloc + 3);
			tx1 = tx;
			Gen_P_Code(node->vde->kids[0]);
			Gen_P_Code(node->vde->kids[1]);
			Gen_P_Code(node->vde->kids[2]);
			gen(opr, 0, 0);
			code[cx1].f=jmp; code[cx1].l=0; code[cx1].a=cx;
			lev = lev - 1;
			tx = tx1;
			Gen_P_Code(node->vde->kids[3]);
			break;
		}
		case(KStmt):
		{
			switch(node->stm->kind){
				case(ASGNSYM):
				{
					int i;
					char *Name= node->stm->kidsA[0]->factor->sym->name;
					for(i = tx; i >= 0; i--)
					{
						if(Symtable[i].name == Name)
						break;
					}
					if(node->stm->kidsA[1]->idt->kind == BE)
					{
						Gen_P_Code(node->stm->kidsA[1]);
						gen(sto, lev - Symtable[i].level, Symtable[i].addr);
					}
					else if(node->stm->kidsA[1]->idt->kind == LR)
					gen(cal, lev - Symtable[i].level, Symtable[i].addr);
					Gen_P_Code(node->stm->kidsA[2]);
					break;
				}
				case(IFSYM):
				{
					int cx1;
					Gen_P_Code(node->stm->kidsI[0]);
					cx1 = cx;
					gen(jpc, 0, 0);
					Gen_P_Code(node->stm->kidsI[1]);
					code[cx1].f=jpc; code[cx1].l=0; code[cx1].a=cx;
					Gen_P_Code(node->stm->kidsI[2]);
					break;
				}
				case(WHILESYM):
				{
					int cx1, cx2;
					cx1 = cx;
					Gen_P_Code(node->stm->kidsW[0]);
					cx2 = cx;
					gen(jpc, 0, 0);
					Gen_P_Code(node->stm->kidsW[1]);
					gen(jmp, 0, cx1);
					code[cx2].f=jpc; code[cx2].l=0; code[cx2].a=cx;
					Gen_P_Code(node->stm->kidsW[2]);
					break;
				}
				case(RETURNSYM):
				{
					gen(opr, 0, 0);
					Gen_P_Code(node->stm->kidsR[0]);
					break;
				}
			}
			break;
		}
		case(KIDT):
		{
			Gen_P_Code(node->idt->kids[0]);
			break;
		}
		case(Kcond):
		{
			switch(node->condi->op){
				case(1):
				{
					Gen_P_Code(node->condi->kids[0]);
					Gen_P_Code(node->condi->kids[1]);
					gen(opr, 0 , 8);
					break;
				}
				case(2):
				{
					Gen_P_Code(node->condi->kids[0]);
					Gen_P_Code(node->condi->kids[1]);
					gen(opr, 0 , 13);
					break;
				}
				case(3):
				{
					Gen_P_Code(node->condi->kids[0]);
					Gen_P_Code(node->condi->kids[1]);
					gen(opr, 0 , 11);
					break;
				}
				case(4):
				{
					Gen_P_Code(node->condi->kids[0]);
					Gen_P_Code(node->condi->kids[1]);
					gen(opr, 0 , 10);
					break;
				}
				case(5):
				{
					Gen_P_Code(node->condi->kids[0]);
					Gen_P_Code(node->condi->kids[1]);
					gen(opr, 0 , 12);
					break;
				}
				case(6):
				{
					Gen_P_Code(node->condi->kids[0]);
					Gen_P_Code(node->condi->kids[1]);
					gen(opr, 0 , 9);
					break;
				}
			}
			break;
		}
		case(KExp):
		{
			if(node->exp->front == 2)
			gen(opr, 0 , 1);
			Gen_P_Code(node->exp->kids[0]);
			if(node->exp->kids[1]->kind != KNULL)
			{
				Gen_P_Code(node->exp->kids[1]);
				if(node->exp->kids[1]->tm->front == 1)
				gen(opr, 0, 2);
				else if(node->exp->kids[1]->tm->front == 2)
				gen(opr, 0, 3);
			}
			break;
		}
		case(KTM):
		{
			Gen_P_Code(node->tm->kids[0]);
			if(node->tm->kids[1]->kind != KNULL)
			{
				Gen_P_Code(node->tm->kids[1]);
				if(node->tm->kids[1]->tm->front == 1)
				gen(opr, 0, 2);
				else if(node->tm->kids[1]->tm->front == 2)
				gen(opr, 0, 3);
			}
			break;
		}
		case(KTerm):
		{
			Gen_P_Code(node->term->kids[0]);
			if(node->term->kids[1]->kind != KNULL)
			{
				Gen_P_Code(node->term->kids[1]);
				if(node->term->kids[1]->ft->frontF == 1)
				gen(opr, 0, 4);
				else if(node->term->kids[1]->ft->frontF == 2)
				gen(opr, 0, 5);
				else if(node->term->kids[1]->ft->frontF == 3)
				gen(opr, 0, 6);
			}
			break;
		}
		case(KFT):
		{	
			Gen_P_Code(node->ft->kids[0]);
			if(node->ft->kids[1]->kind != KNULL)
			{
				Gen_P_Code(node->ft->kids[1]);
				if(node->ft->kids[1]->ft->frontF == 1)
				gen(opr, 0, 4);
				else if(node->ft->kids[1]->ft->frontF == 2)
				gen(opr, 0, 5);
				else if(node->ft->kids[1]->ft->frontF == 3)
				gen(opr, 0, 6);
			}
			break;
		}
		case(KFactor):
		{
			switch(node->factor->kind){
				case(IDENT):
				{
					int i;
					char *Name= node->factor->sym->name;
					for(i = tx; i >= 0; i--)
					{
						if(Symtable[i].name == Name)
						break;
					}
					gen(lod, lev - Symtable[i].level, Symtable[i].addr);
					break;
				}
				case(NUM):
				{
					gen(lit, 0, node->factor->value);
					break;
				}
				case(EXP):
				{
					Gen_P_Code(node->factor->kids[0]);
					break;
				}
			}
			break;
		}
		case(KNULL):
		{
			break;
		}
	}
}

void Print_P_Code()
{
	int i;
	file = fopen("test/wyc.Pcode", "w+");
	for(i = 0; i < cx; i++)
	{
		switch(code[i].f){
			case(lit):
			{
				fprintf(file, "%d lit %ld %ld\n", i, code[i].l, code[i].a);
				break;
			}
			case(opr):
			{
				fprintf(file, "%d opr %ld %ld\n", i, code[i].l, code[i].a);
				break;
			}
			case(lod):
			{
				fprintf(file, "%d lod %ld %ld\n", i, code[i].l, code[i].a);
				break;
			}
			case(sto):
			{
				fprintf(file, "%d sto %ld %ld\n", i, code[i].l, code[i].a);
				break;
			}
			case(cal):
			{
				fprintf(file, "%d cal %ld %ld\n", i, code[i].l, code[i].a);
				break;
			}
			case(Int):
			{
				fprintf(file, "%d int %ld %ld\n", i, code[i].l, code[i].a);
				break;
			}
			case(jmp):
			{
				fprintf(file, "%d jmp %ld %ld\n", i, code[i].l, code[i].a);
				break;
			}
			case(jpc):
			{
				fprintf(file, "%d jpc %ld %ld\n", i, code[i].l, code[i].a);
				break;
			}
			case(end):
			{
				fprintf(file, "%d end %ld %ld\n", i, code[i].l, code[i].a);
				break;
			}
		}
	}
	fclose(file);
}

long base(long b, long l){
    long b1;

    b1=b;
    while (l>0){	// find base l levels down
	b1=s[b1]; l=l-1;
    }
    return b1;
}

void interpret(){
    long p,b,t;		// program-, base-, topstack-registers
    instruction i;	// instruction register
int x = 0, cc = 0;
    printf("start PL/0\n");
    t=0; b=1; p=0;
    s[1]=0; s[2]=0; s[3]=0;
    do{cc++;
//if(cc > 20)
//break;
//printf("Step %d:(b=%d t=%d)\n",p,b,t);
	i=code[p]; p=p+1;
	switch(i.f){
	    case lit:
		t=t+1; s[t]=i.a;
		break;
	    case opr:
		switch(i.a){ 	// operator
		    case 0:	// return
			t=b-1; p=s[t+3]; b=s[t+2];
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
		t=t+1; s[t]=s[base(b,i.l)+i.a + 2];
		break;
	    case sto:
		s[base(b,i.l)+i.a + 2]=s[t]; printf("%10ld\n", s[t]); t=t-1;
		break;
	    case cal:		// generate new block mark
		s[t+1]=base(b,i.l); s[t+2]=b; s[t+3]=p;
		b=t+1; p=i.a;
		break;
	    case Int:
		t=t+i.a;
		break;
	    case jmp:
		p=i.a;
		break;
	    case end:
		break;
	    case jpc:
		if(s[t]==0){
		    p=i.a;
		}
		t=t-1;
	}//printf("(b=%d t=%d)\n",b,t);
//for(x = t+5; x >= 1; x--)
//printf("%d %ld\n",x, s[x]);
    }while(p!=0);
    printf("end PL/0\n");
}
