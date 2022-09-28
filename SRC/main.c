/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecat <clecat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 08:45:11 by clecat            #+#    #+#             */
/*   Updated: 2022/05/23 14:21:19 by clecat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ARG="4 67 3 87 23"
//ARG="`ruby -e "puts (-200..200).to_a.shuffle.join(' ')"`"
//./push_swap $ARG
//visulizer:python3 pyviz.py `ruby -e "puts (-200..200).to_a.shuffle.join(' ')"`

void	print_stack(t_stack *t)
{
	t_stack	*tmp;

	tmp = t;
	while (tmp)
	{
		printf("stack content = %d\n", tmp->content);
		tmp = tmp->next;
	}
}

int	size_stack(t_stack *stk)
{
	t_stack	*tmp;
	int		i;

	tmp = stk;
	i = 0;
	while (tmp && tmp->next != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	getchunk(t_pile *stk)
{
	stk->nbchunk = 0;
	if (stk->size_a <= 100)
		stk->nbchunk = 5;
	else if (stk->size_a >= 100 && stk->size_a <= 500)
		stk->nbchunk = 12;
}

int	ft_lstsize(t_stack *lst)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = lst;
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	t_pile	stcks;

	if (argc <= 1)
		ft_error("Error\n->only 1 arg\n");
	if (ft_chklist(argc, argv) == 0)
		return (0);
	stcks.st_a = NULL;
	stcks.st_b = NULL;
	if (ft_mklist(&stcks, argc, argv) == 0)
		return (0);
	if (argv[1][0] == '\0')
		return (0);
	if (verif(stcks) == 0)
		return (0);
	if (checktrie(stcks) == 0)
		return (0);
	stcks.size_a = size_stack(stcks.st_a) + 1;
	stcks.max = size_stack(stcks.st_a) + 1;
	changevalue(&stcks);
	getchunk(&stcks);
	stcks.limit = (stcks.max + 1) / stcks.nbchunk;
	choosecase(&stcks);
}
