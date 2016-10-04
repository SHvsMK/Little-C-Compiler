#ifndef _COMMON_H_
#define _COMMON_H_
#include "util.h"

#define txmax      100
#define cxmax      2000           // size of code array

#define stacksize 50000
long s[stacksize];	// datastore

int error_flag;

FILE *file;

int cx;

enum fct {
    lit, opr, lod, sto, cal, Int, jmp, jpc, end, str, giv, ldr, lda, sta, sav, get, rea, wri         // functions
};

enum object {
    constant, variable, proc, func, array
};

typedef struct{
    enum fct f;		// function code
    long l; 		// level
    long a; 		// displacement address
} instruction;

instruction code[cxmax+1];

struct{
    char *name;
    enum object kind;
    long val;
    long level;
    long addr;
    long num;
    long dimension;
    int d[10];
}Symtable[txmax+1];

long dx;		// data allocation index
long lev;		// current depth of block nesting
long tx;

typedef struct Symbol {
	char *name;
	int type;
	int layer;
	int val;
} *Symbol;

typedef struct table {
	struct Symbol sym;
	struct table *next;
} *Table;

Table newTable();
Symbol FindSym(Table ptab, const char *name);
int GetVal(Table ptab, const char *name);
void SetVal(Table ptab, const char *name, int val);
void AddSym(Table ptab, const char *name);

typedef struct {
	struct astnode *kids[7];
	int alloc;
} *Pro;

typedef struct {
	struct astnode *kids[2];
	Symbol sym;
	int front;
	int value;
	int alloc;
} *CDe;

typedef struct {
	struct astnode *kids;
	Symbol sym;
	int front;
	int value;
	int alloc;
	int empty;
} *CIDc;

typedef struct {
	struct astnode *kids[3];
	Symbol sym;
	int alloc;
} *IntDe;

typedef struct {
	struct astnode *kids[2];
	Symbol sym;
	int alloc;
} *CIDi;

typedef struct {
	struct astnode *kids[2];
	Symbol sym;
	int space;
	int alloc;
} *ArDe;

typedef struct {
	struct astnode *kids[1];
	int space;
	int alloc;
} *AIDi;

typedef struct {
	int value;
	int front;
} *BN;

typedef struct {
	struct astnode *kids[2];
} *Func;

typedef struct {
	struct astnode *kids[5];
	Symbol sym;
	int alloc;
} *Vde;

typedef struct {
	struct astnode *kids[5];
	Symbol sym;
	int alloc;
} *Ide;

typedef struct {
	struct astnode *kids;
	Symbol sym;
	int alloc;
} *arg;

typedef struct {
	struct astnode *kids;
	Symbol sym;
	int alloc;
} *argb;

typedef struct {
	enum {
		ASGNSYM,
		IFSYM,
		WHILESYM,
		FORSYM,
		RETURNSYM,
		PUTSYM
	} kind;
	union {
		struct astnode *kidsA[3];
		struct astnode *kidsI[3];
		struct astnode *kidsW[3];
		struct astnode *kidsF[5];
		struct astnode *kidsR[2];
		struct astnode *kidsP[1];
	};
} *Stm;

typedef struct {
	struct astnode *kids[1];
} *Expx;

typedef struct {
	struct astnode *kids[2];
} *FStm;

typedef struct {
	struct astnode *kids[1];
} *IDt;

typedef struct {
	struct astnode *kids[2];
	int op;
} *Cond;

typedef struct {
	struct astnode *kids[2];
	int front;
} *Ex;

typedef struct {
	struct astnode *kids[2];
	int front;
} *Tm;

typedef struct {
	struct astnode *kids[2];
} *Ter;

typedef struct {
	struct astnode *kids[2];
	int frontF;
} *Ft;

typedef struct {
	enum {
		IDENT,
		FUNC,
		ARRAY,
		NUM,
		EXP,
		READ
	} kind;
	union {
		Symbol sym;
		int value;
	};
	int space;
	int addr;
	int level;
	struct astnode *kids[2];
} *Factor;

typedef struct {
	struct astnode *kids[2];
	int alloc;
} *Arga;

typedef struct {
	struct astnode *kids[2];
	int alloc;
} *Argab;

typedef struct {
	struct astnode *kids[2];
	int space;
	int total;
	Symbol sym;
	int level;
} *Arbb;

typedef struct location {
	int first_line;
	int first_column;
	int last_line;
	int last_column;
} *Loc;

typedef struct astnode {
	enum {
		KProgram,
		KCDecl,
		KIntDecl,
		KCIDC,
		KCIDI,
		KBN,
		KArDecl,
		KAIDI,
		KFunc,
		KVDecl,
		KIDecl,
		KArgu,
		KArgub,
		KStmt,
		KExpx,
		KFStmt,
		KIDT,
		Kcond,
		KExp,
		KTM,
		KTerm,
		KFT,
		KFactor,
		KArgca,
		KArgcab,
		KArb,
		KNULL,
	} kind;
	union	{
		Pro pro;
		CDe cde;
		IntDe intde;
		CIDc cidc;
		CIDi cidi;
		BN bn;
		ArDe arde;
		AIDi aidi;
		Func func;
		Vde vde;
		Ide ide;
		arg argu;
		argb argub;
		Stm stm;
		Expx expx;
		FStm fstm;
		IDt idt;
		Cond condi;
		Ex exp;
		Tm tm;
		Ter term;
		Ft ft;
		Factor factor;
		Arga argca;
		Argab argcab;
		Arbb arb;
	};
	Loc	loc;
} *ASTNode;

typedef struct ASTtree {
	ASTNode root;
} *ASTTree;

ASTNode newProgram(ASTNode CDecl, ASTNode IntDecl1, ASTNode ArDecl1, ASTNode FuncDecl, ASTNode IntDecl2, ASTNode ArDecl2, ASTNode Stmt);
ASTNode newCDecl(Table ptab, char *name, int front, int num, ASTNode CIDC, ASTNode CDecl);
ASTNode newCIDC(Table ptab, char *name, int front, int num, ASTNode CIDC);
ASTNode newIntDecl(Table ptab, char *name, ASTNode BN, ASTNode CID, ASTNode IntDecl);
ASTNode newCIDI(Table ptab, char *name, ASTNode BN, ASTNode CIDI);
ASTNode newBN(int front, int num);
ASTNode newArDecl(Table ptab, char *name, int num, ASTNode AIDI, ASTNode ArDecl);
ASTNode newAIDI(int num, ASTNode AIDI);
ASTNode newFuncDecl(ASTNode FDecl, ASTNode FuncDecl);
ASTNode newVDecl(Table ptab, char *name, ASTNode Argu, ASTNode CDecl, ASTNode IntDecl, ASTNode ArDecl, ASTNode Stmt);
ASTNode newIDecl(Table ptab, char *name, ASTNode Argu, ASTNode CDecl, ASTNode IntDecl, ASTNode ArDecl, ASTNode Stmt);
ASTNode newArgu(Table ptab, char *name, ASTNode Argub);
ASTNode newArgub(Table ptab, char *name, ASTNode Argub);
ASTNode newASGN(ASTNode Factor, ASTNode IDT, ASTNode Stmt);
ASTNode newIF(ASTNode cond, ASTNode Stmt1, ASTNode Stmt2);
ASTNode newWHILE(ASTNode cond, ASTNode Stmt1, ASTNode Stmt2);
ASTNode newFOR(ASTNode FStmt1, ASTNode cond, ASTNode FStmt2, ASTNode Stmt1, ASTNode Stmt2);
ASTNode newFStmt(ASTNode Factor, ASTNode IDT);
ASTNode newRETURN(ASTNode Expx, ASTNode Stmt);
ASTNode newPUT(ASTNode Exp, ASTNode Stmt);
ASTNode newExpx(ASTNode Exp);
ASTNode newBE(ASTNode Exp);
ASTNode newcond(ASTNode Exp1, int RelOp, ASTNode Exp2);
ASTNode newExp(int front1, ASTNode Term, ASTNode TM);
ASTNode newTM(int front, ASTNode Term, ASTNode TM);
ASTNode newTerm(ASTNode Factor, ASTNode FT);
ASTNode newFT(int frontF, ASTNode Factor, ASTNode FT);
ASTNode newFactori(Table ptab, char *name);
ASTNode newFactorf(Table ptab, char *name, ASTNode Argca);
ASTNode newFactorA(Table ptab, char *name, ASTNode Exp, ASTNode Arb);
ASTNode newFactorn(int num);
ASTNode newFactorE(ASTNode Exp);
ASTNode newFactorG();
ASTNode newArgca(ASTNode Exp, ASTNode Argcab);
ASTNode newArgcab(ASTNode Exp, ASTNode Argcab);
ASTNode newArb(ASTNode Exp, ASTNode Arb);
ASTNode newnull();
ASTTree newAST();
void dumpAST(ASTNode node);
Loc	setLoc(ASTNode node, Loc loc);

#endif // !def(_COMMON_H_)
