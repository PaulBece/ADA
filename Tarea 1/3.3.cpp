#include <iostream>

// Class CVector definition
class CVector
{
private:
int *m_pVect, // Pointer to the buffer
m_nCount, // Control how many elements are actually used
m_nMax, // Control how many are allocated as maximum
m_nDelta; // To control the growing
void Resize(); // Resize the vector when occurs an overflow
public:
CVector(int delta = 2){
    m_nDelta=delta;
    m_nMax=m_nDelta;
    m_nCount=0;
    m_pVect= new int[m_nMax];
} // Constructor
void Insert(int elem); // Insert a new element
// More methods go here
void Print(){
    for (int i=0;i<m_nCount;i++){
        printf("%d\n",*(m_pVect+i));
    }
}
};

void CVector::Insert(int elem)
{
if( m_nCount == m_nMax ) // Verify the overflow
Resize(); // Resize the vector before inserting elem
m_pVect[m_nCount++] = elem; // Insert the element at the end
}

void CVector::Resize()
{
int* tmp=m_pVect;
m_pVect=new int[m_nMax+m_nDelta];
for (int i=0;i<m_nCount;i++){
        m_pVect[i] = tmp[i];
    }
delete tmp;
m_nMax+=m_nDelta;
std::cout<<"vect crece\n";
}

int main(){
    CVector v1(2);
    v1.Insert(5);
    v1.Insert(5);
    v1.Insert(5);
    v1.Insert(5);
    v1.Insert(5);

    v1.Print();

    return 0;

}