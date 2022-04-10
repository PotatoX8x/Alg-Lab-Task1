#include <stdio.h>
#include <stdlib.h>
#include "List.h"

int main() {
	LIST L;
	L=MAKENULL(L);
	INSERT('a', FIRST(L), L);
	INSERT('b', FIRST(L)->next, L);
	INSERT('d', END(L), L);
	INSERT('c', NEXT(LOCATE('b', L), L), L);
	DELETE(LOCATE('a', L), L);
	printlist(L);
	printf("%c\n", RETRIEVE(END(L), L));
	printf("%c\n", RETRIEVE(NEXT(FIRST(L)->next, L), L));
	system("pause");
    return 0;
 }

LIST MAKENULL(LIST L) {
    L=newnode();
	L->next=NULL;
	return L;
} 

position END(LIST L) {         
    position q=L;
    while(q->next!=NULL)
    	q=q->next;
    return q;
}

position FIRST(LIST L) { 
    return L;
}

LIST INSERT (elementtype x, position p, LIST L) {                 
    position tmp;
    tmp=p->next;
	p->next=newnode();
    p->next->element=x;
    p->next->next=tmp;     
    return L;     
}

LIST DELETE (position p, LIST L) {         
    p->next=p->next->next;
    return L;     
}

position LOCATE (elementtype x, LIST L) {
    position p=L;
    while(p->next!=NULL){
    	if (p->next->element==x)
    		return p;
    	else p = p->next;
	}
    return END(L); 
}

elementtype RETRIEVE(position p, LIST L) {
    return p->element;  
}

position NEXT (position p, LIST L) {
	if(p->next!=NULL)
    	return p->next;
    return NONE;
}
