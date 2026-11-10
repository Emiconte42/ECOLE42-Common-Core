
# include "../Projets/07.push_swap/libs/libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_node
{		
	int				number;
	char			*content;
	struct s_node	*next;		
}					t_node;

t_node	*create_node(char *str, int values)
{
	t_node   *new_node;

	new_node = malloc(sizeof(t_node));
	new_node->number = values - 1;
	new_node->content = str;
	new_node->next = NULL;
	return(new_node);
}

t_node	*init_stack(t_node **stack, t_node *new)
{
	t_node *current;

    current = NULL;
	if (!stack)
	{
		*stack = new;
		return(new);
	}
	current = *stack;
	while (new->next)
		current = new->next;
	new->next = new;
	return(new);
}
int	main(int argc, char **argv)
{
	t_node	*head_lst;
	t_node	*current;
	int		i;

	(void)argc;
	head_lst = NULL;
	i = 0;
	while (argv[++i])	
	{
		current = head_lst = create_node(argv[i], i);
		init_stack(&head_lst, current);
		printf("Mot : %s\n", head_lst->content);
		printf("& Index: %d, %d\n",  head_lst->number, i);
	}
	return (0);
}