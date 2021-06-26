#include <stdio.h>
#include <stdlib.h>
        
struct poly {
    int coeff;
    int expo;
    struct poly *link;
};

void insertpoly(struct poly *head, int coeff, int expo) 
{
    struct poly *ptr, *ptr2;

    ptr = head;
    
    ptr2 = malloc(sizeof(struct poly));
    ptr2->coeff = coeff;
    ptr2->expo = expo;
    ptr2->link = NULL;

    while (ptr->link != NULL)
        ptr = ptr->link;
    
    ptr->link = ptr2;
}

void createPoly(struct poly *head)
{
    int n, i = 1, coeff, expo;
    printf("Enter number of terms : ");
    scanf("%d", &n);

    while (i <= n) {
        printf("Enter coeff of term %d: ", i);
        scanf("%d", &coeff);
        printf("Enter expo of term %d: ", i);
        scanf("%d", &expo);

        insertpoly(head, coeff, expo);

        i++;
    }
}

void addSameExpo(struct poly *head)
{
    struct poly *ptr, *ptr2;

    ptr = head->link;
    ptr2 = ptr->link;

    while (ptr2 != NULL) {
        if (ptr->expo == ptr2->expo) {
            ptr->coeff = ptr->coeff + ptr2->coeff;
            
            ptr->link = ptr2->link;
            ptr2 = ptr->link;
        }
        else {
            ptr = ptr2;
            ptr2 = ptr2->link;
        }
    }
}

void sortPoly(struct poly *head) 
{
    int flag;

    struct poly *ptr, *ptr2, *ptr3;

    do {
        ptr = head;
        ptr2 = ptr->link;
        ptr3 = ptr2->link;

        flag = 0;

        while (ptr3 != NULL) {
            if (ptr2->expo < ptr3->expo) {
                ptr->link = ptr3;
                ptr2->link = ptr3->link;
                ptr3->link = ptr2;

                ptr = ptr3;
                ptr3 = ptr2->link;
                
                flag = 1;
            }
            else {
                ptr = ptr2;
                ptr2 = ptr3;
                ptr3 = ptr3->link;
            }
        }
    } while (flag != 0);

    addSameExpo(head);
}

void printPoly(struct poly *head) 
{
    struct poly *ptr;

    ptr = head->link;
    while (1) {
        if (ptr->coeff != 0) {
            printf("%dx^%d", ptr->coeff, ptr->expo);

            if (ptr->link == NULL)
                break;
            else
                printf(" + ");
        }

        ptr = ptr->link;
    }

    printf("\n\n");
}

void addPoly(struct poly *poly1, struct poly *poly2, struct poly *poly3)
{
    struct poly *p1, *p2;

    p1 = poly1->link;
    p2 = poly2->link;

    while (p1 != NULL && p2 != NULL) {
        if (p1->expo > p2->expo) {
            insertpoly(poly3, p1->coeff, p1->expo);
            p1 = p1->link;
        }
        else if (p1->expo < p2->expo) {
            insertpoly(poly3, p2->coeff, p2->expo);
            p2 = p2->link;
        }
        else {
            insertpoly(poly3, p1->coeff + p2->coeff, p1->expo);
            p1 = p1->link;
            p2 = p2->link;
        }
    }

    if (p1 == NULL) {
        while (p2 != NULL) {
            insertpoly(poly3, p2->coeff, p2->expo);
            p2 = p2->link;
        }
    }
    if (p2 == NULL) {
        while (p1 != NULL) {
            insertpoly(poly3, p1->coeff, p1->expo);
            p1 = p1->link;
        }
    }
}

void multiplyPoly(struct poly *poly1, struct poly *poly2, struct poly *poly3)
{
    struct poly *p1, *p2;

    p1 = poly1->link;

    while (p1 != NULL) {
        p2 = poly2->link;

        while (p2 != NULL) {
                insertpoly(poly3, p1->coeff * p2->coeff, p1->expo + p2->expo);

                p2 = p2->link;
        }

        p1 = p1->link;
    }

    sortPoly(poly3);
}

int main() {
    struct poly *poly1, *poly2, *poly3add, *poly3mult;

    poly1 = malloc(sizeof(struct poly));
    poly2 = malloc(sizeof(struct poly));
    poly3add = malloc(sizeof(struct poly));
    poly3mult = malloc(sizeof(struct poly));

    int choice;

    printf("Polynomial 1 :-");
    createPoly(poly1);
    sortPoly(poly1);
    printPoly(poly1);

    printf("Polynomial 2 :-");
    createPoly(poly2);
    sortPoly(poly2);
    printPoly(poly2);

    do {
        printf("\n1. Addition\n2. Multiplication\n3. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Adding polynomials :-\n");
                addPoly(poly1, poly2, poly3add);
                printf("Polynomial Sum :-");
                printPoly(poly3add);
                break;
            case 2:
                printf("Multiplying polynomials :-\n");
                multiplyPoly(poly1, poly2, poly3mult);
                printf("Polynomial Product :-");
                printPoly(poly3mult);
                break;
            case 3:
                printf("\nExiting...");
		exit(0);
                break;
            default:
                printf("\nInvalid choice");
        }
    } while (choice != 3);

    return 0;
}
