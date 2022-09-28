/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecat <clecat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 08:01:22 by clecat            #+#    #+#             */
/*   Updated: 2022/03/29 16:10:07 by clecat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../SRC/push_swap.h"

void	sb(t_pile *stcks)
{
	t_stack	*tmp;

	if (stcks->st_b && stcks->st_b->next)
	{
		tmp = stcks->st_b->next;
		stcks->st_b->next = stcks->st_b->next->next;
		tmp->next = stcks->st_b;
		stcks->st_b = tmp;
		write(1, "sb\n", 3);
	}
}

void	pb(t_pile *stcks)
{
	t_stack	*tmp;

	if (stcks->st_a)
	{
		stcks->size_a--;
		stcks->size_b++;
		tmp = stcks->st_a->next;
		stcks->st_a->next = stcks->st_b;
		stcks->st_b = stcks->st_a;
		stcks->st_a = tmp;
		write(1, "pb\n", 3);
	}
}

void	rb(t_pile *stcks)
{
	t_stack	*tmp;
	t_stack	*first;

	if (stcks->st_b && stcks->st_b->next)
	{
		tmp = stcks->st_b;
		stcks->st_b = stcks->st_b->next;
		first = stcks->st_b;
		while (stcks->st_b->next)
			stcks->st_b = stcks->st_b->next;
		stcks->st_b->next = tmp;
		tmp->next = NULL;
		stcks->st_b = first;
		write(1, "rb\n", 3);
	}
}

void	rrb(t_pile *stcks)
{
	t_stack	*tmp;
	t_stack	*first;

	if (stcks->st_b && stcks->st_b->next)
	{
		first = stcks->st_b;
		while (stcks->st_b->next->next)
			stcks->st_b = stcks->st_b->next;
		tmp = stcks->st_b->next;
		stcks->st_b->next = NULL;
		stcks->st_b = first;
		tmp->next = stcks->st_b;
		stcks->st_b = tmp;
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_pile *stcks)
{
	rra(stcks);
	rrb(stcks);
	write(1, "rrr\n", 4);
}
