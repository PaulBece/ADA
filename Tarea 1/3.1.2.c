#include <stdlib.h>
#include <stdio.h>

int* gpVect = NULL; // Dynamic buffer to save the elements int
int gnCount = 0; // Counter to know the number of used elements int
int gnMax = 0; // Variable containing the size of the allocated
// memory

void Resize();

void Insert(int elem)
{
	if (gnCount == gnMax) // There is no space at this moment for elem
		Resize(); // Resize the vector before inserting elem
	gpVect[gnCount++] = elem; // Insert the element at the end of the sequence
}

void Resize()
{
	const int delta = 2; // Used to increase the vector size
    if (!gpVect){
        gpVect = malloc(sizeof(int) * delta);
        printf("inicio de vect\n");
    }
	else {
        gpVect = realloc(gpVect, sizeof(int) * (gnMax + delta));
        printf("vect crece\n");
    }
	// You can also use the following code:
	// int *pTemp, i;
	// pTemp = new int[gnMax + delta]; // Alloc a new vector
	// for(i = 0 ; i < gnMax ; i++) // Transfer the elements
	// pTemp[i] = gpVect[i]; // we can also use the function memcpy
	// delete [ ] gpVect; // delete the old vector
	// gpVect = pTemp; // Update the pointer
	gnMax += delta; // The Max has to be increased by delta
}

int main(){



    Insert(5);
    Insert(5);
    Insert(5);
    Insert(5);
    Insert(5);


    for (int i=0;i<gnCount;i++){
        printf("%d\n",*(gpVect+i));
    }

    free(gpVect);

    return 0;
}