/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecat <clecat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:17:57 by clecat            #+#    #+#             */
/*   Updated: 2022/05/18 09:17:51 by clecat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	scan_up(t_pile *stk, int limit)
{
	t_stack	*tmp;
	int		index;

	tmp = stk->st_a;
	index = 0;
	while (tmp)
	{
		if (tmp->content <= limit - 1)
			return (index);
		index++;
		tmp = tmp->next;
	}
	return (index);
}

int	scan_down(t_pile *stk, int limit)
{
	t_stack	*tmp;
	int		index;
	int		index_save;

	tmp = stk->st_a;
	index = 0;
	index_save = 0;
	while (tmp)
	{
		if (tmp->content <= limit - 1)
			index_save = index;
		index++;
		tmp = tmp->next;
	}
	return (index_save);
}

int	getindexmax(t_stack *stack)
{
	t_stack	*s;
	t_stack	*max;
	int		x;
	int		index;

	index = 0;
	s = stack;
	max = s;
	x = 0;
	while (s)
	{
		if (max->content < s->content)
		{
			max = s;
			index = x;
		}
		s = s->next;
		x++;
	}
	return (index);
}

void	moveb(t_pile *stk, int index)
{
	if (index < stk->size_b / 2)
	{
		while (index != 0)
		{
			rb(stk);
			index--;
		}
	}
	else
	{
		while (index < stk->size_b)
		{
			rrb(stk);
			index++;
		}
	}
}

void	check_b(t_pile *stk)
{
	while (stk->size_b != 0)
	{
		moveb(stk, getindexmax(stk->st_b));
		pa(stk);
	}
}
