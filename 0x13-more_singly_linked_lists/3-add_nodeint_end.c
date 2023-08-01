#include "lists.h"

/**
 * add_nodeint_end - adds a node at the end of a linked list
 * @head: pointer to the first element in the list
 * @n: data to insert in the new element
 *
 * Return: pointer to the new node, or NULL if it fails
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
    listint_t *newNode = (listint_t *)malloc(sizeof(listint_t));
    if (newNode == NULL) {
        return (NULL);
    }

    newNode->n = n;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        listint_t *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    return (newNode);
}
