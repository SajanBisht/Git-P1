#include <stdio.h>
#include <stdlib.h>

typedef struct single_ll {
    int data;
    struct single_ll* next;
} ll;

ll* insert(ll* top);
ll* delete(ll* t);
void display(ll* t);
ll* del_smin(ll* t);

int main() {
    ll* top = NULL, * t = NULL;
    int n;
    do {
        printf("Enter 1 - insert, 2 - delete, 3 - display, 4 - delete second minimum: ");
        scanf("%d", &n);
        switch (n) {
        case 1:
            top = insert(top);
            if (t == NULL) {
                t = top;
            }
            break;
        case 2:
            t = delete(t);
            if (t == NULL)
                top = NULL;
            break;
        case 3:
            display(t);
            break;
        case 4:
            top = t;
            t = del_smin(t);
            break;
        }
    } while (n <= 4);
    return 0;
}

ll* insert(ll* top) {
    ll* p = NULL;
    p = (ll*)malloc(sizeof(ll));
    if (p != NULL) {
        printf("Enter data: ");
        scanf("%d", &p->data);
        p->next = NULL;

        if (top == NULL) {
            top = p;  // Insert at the beginning if the list is empty
        } else {
            ll* temp = top;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = p;  // Insert at the end
        }
    } else {
        printf("Memory allocation failed\n");
    }
    return top;
}

ll* delete(ll* t) {
    if (t == NULL) {
        printf("Empty list\n");
    } else {
        ll* temp = t;
        printf("Deleted: %d\n", temp->data);
        t = t->next;
        free(temp);  // Free the memory of the deleted node
    }
    return t;
}

void display(ll* t) {
    if (t == NULL) {
        printf("Empty list\n");
    } else {
        while (t != NULL) {
            printf("%d\n", t->data);
            t = t->next;
        }
    }
}

ll* del_smin(ll* t) {
    if (t == NULL || t->next == NULL) {
        printf("List is too short to have a second minimum\n");
        return t;  // Return the list as it is if there are less than 2 elements
    }

    ll *head = t, *temp = t, *prev = NULL, *minNode = NULL;
    int min = __INT_MAX__, min2 = __INT_MAX__;

    // First pass to find the minimum and second minimum
    while (temp != NULL) {
        if (temp->data < min) {
            min2 = min;
            min = temp->data;
        } else if (temp->data < min2 && temp->data != min) {
            min2 = temp->data;
        }
        temp = temp->next;
    }

    // Second pass to find and delete the second minimum node
    temp = head;
    prev = NULL;
    while (temp != NULL) {
        if (temp->data == min2) {
            // If it's the first node
            if (temp == head) {
                head = temp->next;  // Re-link the head if the second minimum is the first node
            } else {
                prev->next = temp->next;  // Skip the second minimum node
            }
            free(temp);  // Free the memory of the deleted node
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}
