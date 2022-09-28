/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_trie.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecat <clecat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:47:10 by clecat            #+#    #+#             */
/*   Updated: 2022/05/18 11:11:21 by clecat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mvlower5(t_pile *stck)
{
	if (stck->posmin == 0)
		pb(stck);
	if (stck->posmin == 1)
	{
		sa(stck);
		pb(stck);
	}
	if (stck->posmin == 2)
	{
		ra(stck);
		ra(stck);
		pb(stck);
	}
	if (stck->posmin == 3)
	{
		rra(stck);
		rra(stck);
		pb(stck);
	}
	if (stck->posmin == 4)
	{
		rra(stck);
		pb(stck);
	}
}

void	mvlower4(t_pile *stk)
{
	if (stk->posmin == 0)
		pb(stk);
	if (stk->posmin == 1)
	{
		sa(stk);
		pb(stk);
	}
	if (stk->posmin == 2)
	{
		ra(stk);
		ra(stk);
		pb(stk);
	}
	if (stk->posmin == 3)
	{
		rra(stk);
		pb(stk);
	}
}

void	getlower(t_pile *stk)
{
	t_stack	*tmp;
	int		x;

	tmp = stk->st_a;
	stk->minst_a = 2147483647;
	x = 0;
	while (tmp)
	{
		if (stk->minst_a > tmp->content)
		{
			stk->minst_a = tmp->content;
			stk->posmin = x;
		}
		tmp = tmp->next;
		x++;
	}
}

void	trie100(t_pile *stk)
{
	stk->median = stk->size_a / 2;
	while (stk->size_a > -1)
	{
		getlower(stk);
		if (stk->posmin <= stk->median)
		{
			stk->posmin++;
			while (--(stk->posmin))
				ra(stk);
		}
		else if (stk->posmin > stk->median)
		{
			stk->posmin--;
			while (++(stk->posmin) < stk->size_a + 1)
				rra(stk);
		}
		pb(stk);
	}
	stk->size_b = size_stack(stk->st_b);
	while (stk->size_b > -1)
		pa(stk);
}

int	getlower2(t_pile *stk)
{
	t_stack	*tmp;
	int		x;
	int		i;

	tmp = stk->st_a;
	stk->minst_a = 2147483647;
	x = 0;
	while (tmp)
	{
		if (stk->minst_a > tmp->content)
		{
			stk->minst_a = tmp->content;
			i = x;
		}
		tmp = tmp->next;
		x++;
	}
	return (i);
}
