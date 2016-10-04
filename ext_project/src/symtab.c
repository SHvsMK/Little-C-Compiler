#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "common.h"

Table
newTable()
{
	Table new;
	NEW0(new);
	return new;
}

Symbol
FindSym(Table ptab, const char *name)
{
	Table pent;
	NEW0(pent);
	for(pent = ptab->next; pent != NULL; pent = pent->next)
		if(strcmp(name, pent->sym.name) == 0)
			return &pent->sym;
}

int
GetVal(Table ptab, const char *name)
{
	Table pent;
	NEW0(pent);
	if(ptab->next == NULL)
	return 0;
	for(pent = ptab->next; pent != NULL; pent = pent->next)
		if(strcmp(name, pent->sym.name) == 0)
			return pent->sym.val;
	return 0;
}

void
SetVal(Table ptab, const char *name, int val)
{
	Table pent;
	NEW0(pent);
	for(pent = ptab->next; pent !=NULL; pent = pent->next)
		if(strcmp(name , pent->sym.name) == 0)
		{
			pent->sym.val = val;
			return;
		}
	return;
}

void
AddSym(Table ptab, const char *name)
{
	Table pent;
	NEW0(pent);
	for(pent = ptab; pent->next != NULL; pent = pent->next);
	Table tmp;
	NEW0(tmp);
	tmp->sym.name = (char *)name;
	pent->next = tmp;
	tmp->next = NULL;
	return;
}
