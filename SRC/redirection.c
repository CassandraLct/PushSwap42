/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecat <clecat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:53:48 by clecat            #+#    #+#             */
/*   Updated: 2022/05/23 10:13:32 by clecat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choosecase(t_pile *stk)
{
	if (stk->size_a == 2)
		sa(stk);
	else if (stk->size_a == 3)
		trie3(stk);
	else if (stk->size_a == 4)
		trie4(stk);
	else if (stk->size_a == 5)
		trie5(stk);
	else if (stk->size_a >= 6)
		ft_usechunk(stk);
}

void	trie3(t_pile *stk)
{
	if (stk->st_a->content < stk->st_a->next->content
		&& stk->st_a->next->content > stk->st_a->next->next->content
		&& stk->st_a->content > stk->st_a->next->next->content)
		rra(stk);
	else if (stk->st_a->content > stk->st_a->next->content
		&& stk->st_a->next->content < stk->st_a->next->next->content
		&& stk->st_a->content < stk->st_a->next->next->content)
		sa(stk);
	else if (stk->st_a->content > stk->st_a->next->content
		&& stk->st_a->next->content > stk->st_a->next->next->content)
	{
		sa(stk);
		rra(stk);
	}
	else if (stk->st_a->content > stk->st_a->next->content
		&& stk->st_a->next->content < stk->st_a->next->next->content
		&& stk->st_a->content > stk->st_a->next->next->content)
		ra(stk);
	else if (stk->st_a->content < stk->st_a->next->content
		&& stk->st_a->next->content > stk->st_a->next->next->content
		&& stk->st_a->content < stk->st_a->next->next->content)
	{
		sa(stk);
		ra(stk);
	}
}

void	trie4(t_pile *stk)
{
	getlower(stk);
	mvlower4(stk);
	trie3(stk);
	pa(stk);
}

void	trie5(t_pile *stk)
{
	getlower(stk);
	mvlower5(stk);
	trie4(stk);
	pa(stk);
}
