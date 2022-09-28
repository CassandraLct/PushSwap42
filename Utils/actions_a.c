/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecat <clecat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 09:08:32 by clecat            #+#    #+#             */
/*   Updated: 2022/05/18 11:11:42 by clecat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../SRC/push_swap.h"
//pa, pb, sa, sb, ra, rb, rra, rrb

void	sa(t_pile *stcks)
{
	t_stack	*tmp;

	if (stcks->st_a && stcks->st_a->next)
	{
		tmp = stcks->st_a->next;
		stcks->st_a->next = stcks->st_a->next->next;
		tmp->next = stcks->st_a;
		stcks->st_a = tmp;
		write(1, "sa\n", 3);
	}
}

void	pa(t_pile *stcks)
{
	t_stack	*tmp;

	if (stcks->st_b)
	{
		stcks->size_a++;
		stcks->size_b--;
		tmp = stcks->st_b->next;
		stcks->st_b->next = stcks->st_a;
		stcks->st_a = stcks->st_b;
		stcks->st_b = tmp;
		write(1, "pa\n", 3);
	}
}

void	ra(t_pile *stcks)
{
	t_stack	*tmp;
	t_stack	*first;

	if (stcks->st_a && stcks->st_a->next)
	{
		tmp = stcks->st_a;
		stcks->st_a = stcks->st_a->next;
		first = stcks->st_a;
		while (stcks->st_a->next)
			stcks->st_a = stcks->st_a->next;
		stcks->st_a->next = tmp;
		tmp->next = NULL;
		stcks->st_a = first;
		write(1, "ra\n", 3);
	}
}

void	rra(t_pile *stcks)
{
	t_stack	*tmp;
	t_stack	*first;

	if (stcks->st_a && stcks->st_a->next)
	{
		first = stcks->st_a;
		while (stcks->st_a->next->next)
			stcks->st_a = stcks->st_a->next;
		tmp = stcks->st_a->next;
		stcks->st_a->next = NULL;
		stcks->st_a = first;
		tmp->next = stcks->st_a;
		stcks->st_a = tmp;
		write(1, "rra\n", 4);
	}
}

void	ss(t_pile *stcks)
{
	sa(stcks);
	sb(stcks);
	write(1, "ss\n", 3);
}
