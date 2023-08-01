include "lists.h"
#include <stdio.h>

size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * looped_listint_len - Counts the number of unique nodes
 * in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: If the list is not looped - 0.
 * Otherwise - the number of unique nodes in the list.
 */
size_t looped_listint_len(const listint_t *head)

{
    const listint_t *slow = head;
    const listint_t *fast = head;
    int loop = 0;
    size_t count = 0;

    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            loop = 1;
            break;
        }
    }

    slow = head;

    if (loop)
    {
        printf("-> [%p] %d\n", (void *)slow, slow->n);
        exit(98);
    }

    while (slow)
    {
        printf("[%p] %d\n", (void *)slow, slow->n);
        slow = slow->next;
        count++;
    }

    return count;
}
