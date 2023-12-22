#include "hash_tables.h"

/**
 * hash_table_print - it prints a hash table.
 * @ht: the hash table to print.
 *
 * Return: nothing will return.
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *node;
	unsigned long int i;
	int comma_flag = 0;

	if (ht == NULL)
		return;

	printf("{");

	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node)
		{
			if (comma_flag == 1)
				printf(", ");

			printf("'%s': '%s'", node->key, node->value);

			node = node->next;
			comma_flag = 1;
		}
	}

	printf("}\n");
}
