#ifndef _COMMON_H_
#define _COMMON_H_
#include "util.h"

typedef struct {
	struct astnode *kids[5];
} *Pro;

typedef struct {
	struct astnode *kids[2];
	char *name;
	int front;
	int value;
} *CDe;

typedef struct {
	struct astnode *kids[0];
	char *name;
	int front;
	int value;
} *CIDc;

typedef struct {
	struct astnode *kids[3];
	char *name;
} *IntDe;

typedef struct {
	struct astnode *kids[2];
	char *name;
} *CIDi;

typedef struct {
	int value;
	int front;
} *BN;

typedef struct {
	struct astnode *kids[4];
	char *name;
} *Vde;

typedef struct {
	enum {
		ASGNSYM,
		IFSYM,
		WHILESYM,
		RETURNSYM
	} kind;
	union {
		struct astnode *kidsA[3];
		struct astnode *kidsI[4];
		struct astnode *kidsW[3];
		struct astnode *kidsR[1];
	};
} *Stm;

typedef struct {
	enum {
		BE,
		LR
	} kind;
	struct astnode *kids[0];
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
		NUM,
		EXP
	} kind;
	union {
		char *name;
		int value;
		struct astnode *kids[0];
	};
} *Factor;

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
		KVDecl,
		KStmt,
		KIDT,
		Kcond,
		KExp,
		KTM,
		KTerm,
		KFT,
		KFactor,
		KNULL,
	} kind;
	union	{
		Pro pro;
		CDe cde;
		IntDe intde;
		CIDc cidc;
		CIDi cidi;
		BN bn;
		Vde vde;
		Stm stm;
		IDt idt;
		Cond condi;
		Ex exp;
		Tm tm;
		Ter term;
		Ft ft;
		Factor factor;
	};
	Loc	loc;
} *ASTNode;

typedef struct ASTtree {
	ASTNode root;
} *ASTTree;

ASTNode newProgram(ASTNode CDecl, ASTNode IntDecl1, ASTNode VDecl, ASTNode IntDecl2, ASTNode Stmt);
ASTNode newCDecl(char *name, int front, int num, ASTNode CIDC, ASTNode CDecl);
ASTNode newCIDC(char *name, int front, int num, ASTNode CIDC);
ASTNode newIntDecl(char *name, ASTNode BN, ASTNode CID, ASTNode IntDecl);
ASTNode newCIDI(char *name, ASTNode BN, ASTNode CIDI);
ASTNode newBN(int front, int num);
ASTNode newVDecl(char *name, ASTNode CDecl, ASTNode IntDecl, ASTNode Stmt, ASTNode VDecl);
ASTNode newASGN(ASTNode Factor, ASTNode IDT, ASTNode Stmt);
ASTNode newIF(ASTNode cond, ASTNode Stmt1, ASTNode Stmt2, ASTNode Stmt3);
ASTNode newWHILE(ASTNode cond, ASTNode Stmt1, ASTNode Stmt2);
ASTNode newRETURN(ASTNode Stmt);
ASTNode newBE(ASTNode Exp);
ASTNode newLR();
ASTNode newcond(ASTNode Exp1, int RelOp, ASTNode Exp2);
ASTNode newExp(int front1, ASTNode Term, ASTNode TM);
ASTNode newTM(int front, ASTNode Term, ASTNode TM);
ASTNode newTerm(ASTNode Factor, ASTNode FT);
ASTNode newFT(int frontF, ASTNode Factor, ASTNode FT);
ASTNode newFactori(char *name);
ASTNode newFactorn(int num);
ASTNode newFactorE(ASTNode Exp);
ASTNode newnull();
ASTTree newAST();
void dumpAST(ASTNode node);
Loc	setLoc(ASTNode node, Loc loc);

#endif // !def(_COMMON_H_)
