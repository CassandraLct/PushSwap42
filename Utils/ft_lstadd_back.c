/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecat <clecat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:58:30 by clecat            #+#    #+#             */
/*   Updated: 2022/05/18 09:34:56 by clecat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../SRC/push_swap.h"

void	ft_lstadd_back(t_stack **alst, t_stack *new)
{
	t_stack	*temp;

	if (*alst)
	{
		temp = ft_lstlast(*alst);
		temp->next = new;
	}
	else
	{
		*alst = new;
	}
}
