#include "lists.h"

/**
 * free_listint_safe - frees a linked list
 * @h: pointer to the first node in the linked list
 *
 * Return: number of elements in the freed list
 */
size_t free_listint_safe(listint_t **h)
{

    if (h == NULL || *h == NULL)
        return 0;

    size_t count = 0;
    listint_t *current = *h;
    listint_t *next_node;

    while (current != NULL)
    {
        count++;
        next_node = current->next;

        if (current <= next_node)
        {
            *h = NULL; 
            free(current);
            return count;
        }

        current = next_node;
    }

    current = *h;
    while (current != NULL)
    {
        next_node = current->next;
        free(current);
        current = next_node;
    }

    *h = NULL; 
    return count;
}
