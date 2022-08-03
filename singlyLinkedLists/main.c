#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listitem {
	struct listitem *next;		// Struct pointer to next item.
	int data;					// Some data "integer."
} LISTITEM;


int main() {
	LISTITEM *listhead, *temp;


	// First indicate that the list has nothing in it
	// ... this is done by setting the list to point to nothing.
	listhead = NULL;

	// Now populate the list.
	for (int i = 0; i < 3; i++) {
		temp = malloc(sizeof(LISTITEM));			// Allocate some memory for the new list item.
		temp->data = i;								// Set the list item's data to the loop count so that we can see where it is in the list
		temp->next = listhead;						// this will insert at the FRONT of the list
		listhead = temp;							// and set the list head to the newly created list item.
	}

	// Now let's see what we've got.
	temp = listhead;								// Initialize our temporary variable to the head of the list.
	while (temp != NULL) {							// Keep going until we've reached the end.
		printf("List item: \n\tCurrent is: %p\n\tNext is: %p\n\tData is: %d\n", temp, temp->next, temp->data);
		temp = temp->next;							// Move to the next item in the list.
	}

	// NOTE: You can see that a new data item is inserted at the FRONT of the list. In fact you can insert the item anywhere
	// but it becomes more compilcated (and error prone) and it is slower. If you want to do this, it's better to use a doubly linked list.
	
	return 0;
}
