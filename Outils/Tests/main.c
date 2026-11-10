#include <stdio.h>
#include <stdlib.h> 

typedef struct s_node
{
	char	*content;
	int		index;
	struct s_node *next;
}			t_node;

t_node *ft_node_create(char *str, int i)
{
	t_node *new;

	new = calloc(1, sizeof(t_node));
	if (!new)
		return (NULL);
	new->content = str;
	new->index = i - 1;
	new->next = NULL;
	return (new);
}

void	ft_node_add_back(t_node **head, t_node *new)
{
	t_node *current;

	if (*head == NULL) 
		*head = new;
	else
	{
		current = *head;
		while(current->next)
			current = current->next;
		current->next = new;
	}
}

void	ft_node_print(t_node *head, int i)
{
	printf("ITERATION NUMERO : %d\n", i - 1);
	while (head)
	{
		printf("NODE CONTENT = %s\n", head->content);
		printf("NODE INDEX = %d\n", head->index);
		head = head->next;
	}
}


int main (int argc, char **argv)
{
	int i;
	t_node *head_lst = NULL;
	t_node *current;

	(void)argc;
	i = 0;
	// 	printf("%s\n", argv[i]);
	// TANT QUE ARGV[i]
	while (argv[++i])
	{
		// 1 ERE ETAPE : JE CREE UN NOEUD, ET JE LUI ASSIGNE ARGv[i]
		current =  ft_node_create(argv[i], i);
		// 2 EME ETAPE : JE RAJOUTE A MA CHAINE
		ft_node_add_back(&head_lst, current);
	}
	ft_node_print(head_lst, i);
	return (0);
}

