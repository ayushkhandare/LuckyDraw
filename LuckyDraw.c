#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int printRandoms()
{
	int lower = 1, upper = 10, count = 1;
	srand(time(0));
	int num = (rand() %(upper - lower + 1)) + lower;
	return num;
}

struct Node{
    int data;
    struct Node* next;
};

void traverse(struct Node* head){
    struct Node* ptr = head;
    do
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr!=head);
}

struct Node* deleteAtIndex(struct Node* head,int value)
{
	printf("Random Number is: %d\n", value);
    printf("Persons in the lucky draws are: \n");
    struct Node* p = head;
    struct Node* q = head->next;
    for (int i = 0; i < value - 2; i++)
    {
        p = p->next;
        q = q->next;
    }
    
    p->next = q->next;
    free(q);
    
    return p->next;
}

int main()
{
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;
    struct Node* fifth;
    struct Node* sixth;
    struct Node* seventh;
    struct Node* eighth;
    struct Node* ninth;
    struct Node* tenth;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));
    fifth = (struct Node*)malloc(sizeof(struct Node));
    sixth = (struct Node*)malloc(sizeof(struct Node));
    seventh = (struct Node*)malloc(sizeof(struct Node));
    eighth = (struct Node*)malloc(sizeof(struct Node));
    ninth = (struct Node*)malloc(sizeof(struct Node));
    tenth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data= 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = fifth;

    fifth->data = 5;
    fifth->next = sixth;

    sixth->data = 6;
    sixth->next = seventh;

    seventh->data = 7;
    seventh->next = eighth;

    eighth->data = 8;
    eighth->next = ninth;

    ninth->data = 9;
    ninth->next = tenth;

    tenth->data = 10;
    tenth->next = head;

	int choice;
	while(1)
	{
		printf("\nDo you want to continue draw process ? \nPress 1 to continue \nPress 2 for declaration of winner \nPress any number to EXIT.\n");
		scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            head = deleteAtIndex(head, printRandoms());
            traverse(head);
            break;
        
        case 2:
            printf("\n\n!!!Winner of lucky draw is: ");
            traverse(head);
            printf("Heartiest Congratulations to the winner\n\n");
            break;

        default:
            printf("Thank you for choosing us :)\n");
            return 0;
            break;
        }        
	}
	
    return 0;
}
