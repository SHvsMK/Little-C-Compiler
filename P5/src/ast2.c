#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "common2.h"

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
	new->cidc = newcidc;
	return new;
}

ASTNode
newIntDecl(Table ptab, char *name, ASTNode BN, ASTNode CID, ASTNode IntDecl)
{
	ASTNode new;
	NEW0(new);
	new->kind = KIntDecl;
	IntDe newintde;
	NEW0(newintde);
	newintde->kids[0] = BN;
	newintde->kids[1] = CID;
	newintde->kids[2] = IntDecl;
	AddSym(ptab, name);
	newintde->sym = FindSym(ptab, name);;
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
	newcidi->sym = FindSym(ptab, name);;
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
newIF(ASTNode cond, ASTNode Stmt1, ASTNode Stmt2, ASTNode Stmt3)
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
	newstm->kidsI[3] = Stmt3;
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
					printf("Unhandled ASTNode kind!\n");
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
					printf("Unhandled ASTNode kind!\n");
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
					printf("Unhandled ASTNode kind!\n");
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
					printf("}\nelse\n{\n");
					dumpAST(node->stm->kidsI[2]);
					printf("}\n");
					dumpAST(node->stm->kidsI[3]);
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
					printf("Unhandled ASTNode kind!\n");
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
					printf("Unhandled ASTNode kind!\n");
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
					printf("Unhandled ASTNode kind!\n");
					break;
				}
			}
			dumpAST(node->exp->kids[0]);
			dumpAST(node->exp->kids[1]);
			break;
		}
		case(KTM):
		{
			dumpAST(node->tm->kids[0]);
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
					printf("Unhandled ASTNode kind!\n");
					break;
				}
			}
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
					printf("Unhandled ASTNode kind!\n");
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
					printf("Unhandled ASTNode kind!\n");
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
			printf("Unhandled ASTNode kind!\n");
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
