#include <stdlib.h>
#include <stdio.h>

const int delta=2;

// void Resize(int ** rpVect, int* rnMax);

// void Insert(int ** rpVect, int* rnCount, int* rnMax, int elem)
// {
// if( (*rnCount) == (*rnMax) ) // Verify the overflow
// Resize(rpVect, rnMax); // Resize the vector before inserting elem
// (*rpVect)[(*rnCount)] = elem; // Insert the element at the end of the sequence
// (*rnCount)++;
// }

// void Resize(int ** rpVect, int* rnMax)
// {
// *rpVect = realloc(*rpVect, sizeof(int) * ((*rnMax) + delta));
// (*rnMax) += delta; // The Max has to be increased by delta
// printf("vect crece\n");
// }



struct Vector
{
int*m_pVect, // Pointer to the buffer
m_nCount, // Control how many elements are actually used
m_nMax, // Control how many are allocated as maximum
m_nDelta; // To control the growing
};

void Resize(struct Vector *pThis);

void Insert(struct Vector *pThis, int elem)
{
if( pThis->m_nCount == pThis->m_nMax ) // Verify the overflow
Resize(pThis); // Resize the vector before inserting elem
// Insert the element at the end of the sequence
pThis->m_pVect[pThis->m_nCount++] = elem;
}
void Resize(struct Vector *pThis)
{
pThis->m_pVect = realloc(pThis->m_pVect, sizeof(int) *
(pThis->m_nMax + pThis->m_nDelta));
// The Max has to be increased by delta
pThis->m_nMax += pThis->m_nDelta;
printf("vect crece\n");
}


int main(){
   
    // int* Vect1=malloc(sizeof(int) * delta);
    // int Count1=0;
    // int Max1=delta;

    struct Vector v1;
    v1.m_nDelta=2;
    v1.m_nCount=0;
    v1.m_nMax=v1.m_nDelta;
    v1.m_pVect=malloc(sizeof(int) * v1.m_nDelta);

    // Insert(&Vect1,&Count1,&Max1,5);
    // Insert(&Vect1,&Count1,&Max1,5);
    // Insert(&Vect1,&Count1,&Max1,5);
    // Insert(&Vect1,&Count1,&Max1,5);
    // Insert(&Vect1,&Count1,&Max1,5);

    Insert(&v1,5);
    Insert(&v1,5);
    Insert(&v1,5);
    Insert(&v1,5);
    Insert(&v1,5);

    for (int i=0;i<v1.m_nCount;i++){
        printf("%d\n",*(v1.m_pVect+i));
    }

    // for (int i=0;i<Count1;i++){
    //     printf("%d\n",*(Vect1+i));
    // }

    // free(Vect1);

    return 0;
}

