/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecat <clecat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 09:46:09 by clecat            #+#    #+#             */
/*   Updated: 2022/05/23 14:22:03 by clecat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//return la valeur max de la stack
static t_stack	*getbig(t_stack	*stack)
{
	t_stack	*s;
	t_stack	*max;

	s = stack;
	max = s;
	while (s)
	{
		if (max->content < s->content)
			max = s;
		s = s->next;
	}
	return (max);
}

//change valeur en la valeur de leur position
void	changevalue(t_pile *stk)
{
	t_stack	*tmp;
	int		i;
	t_stack	*min;

	i = 0;
	while (i < stk->size_a + 1)
	{
		tmp = stk->st_a;
		min = getbig(tmp);
		while (tmp)
		{
			if (tmp->content <= min->content && tmp->index == -1)
				min = tmp;
			tmp = tmp->next;
		}
		min->index = i;
		min->content = i;
		i++;
	}
}

void	move(t_pile *stk, int index)
{
	if (index < stk->size_a / 2)
	{
		while (index != 0)
		{
			ra(stk);
			index--;
		}
	}
	else
	{
		while (index < stk->size_a)
		{
			rra(stk);
			index++;
		}
	}
}

void	find_chunk(t_pile *stk, int nb_chunk)
{
	int	size_chunk;
	int	index_up;
	int	index_down;

	size_chunk = 0;
	while (size_chunk < stk->limit && stk->size_a != 0)
	{
		index_up = scan_up(stk, stk->limit * nb_chunk);
		index_down = scan_down(stk, stk->limit * nb_chunk);
		if ((stk->size_a - index_down) < index_up)
			move(stk, index_down);
		else
			move(stk, index_up);
		pb(stk);
		size_chunk++;
	}
}

void	ft_usechunk(t_pile *stk)
{
	int	nb_chunk;

	nb_chunk = 1;
	while (stk->size_a != 0)
	{
		find_chunk(stk, nb_chunk);
		nb_chunk++;
	}
	check_b(stk);
}
