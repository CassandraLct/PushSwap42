/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecat <clecat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:28:18 by clecat            #+#    #+#             */
/*   Updated: 2022/05/23 13:47:22 by clecat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verif(t_pile stcks)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (stcks.st_a == NULL)
		return (write(1, "Error\nstack null\n", 17));
	tmp = stcks.st_a;
	tmp2 = tmp->next;
	while (tmp && tmp2)
	{
		while (tmp2 && tmp->content != tmp2->content)
		{
			tmp2 = tmp2->next;
		}
		if (tmp2 != NULL)
		{
			ft_error("Error\ndoublon\n");
			return (0);
		}
		tmp = tmp->next;
		tmp2 = tmp->next;
	}
	return (1);
}

int	ft_chklist(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc <= 1)
		return (0);
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
		{
			ft_error("Error\n-> digit\n");
			return (0);
		}
		if (ft_chkdigit(argv[i]) == 0)
		{
			ft_error("Error\n-> digit\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_chkdigit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
			i++;
	while (str[i] && ((str[i] >= '0' && str[i] <= '9') || str[i] == 32))
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

int	ft_mklist(t_pile *stcks, int argc, char **argv)
{
	int		i;
	int		y;
	char	**full;

	argc = 0;
	i = 1;
	while (argv[i])
	{
		y = 0;
		full = ft_split(argv[i], ' ');
		while (full[y])
		{
			if (check_int(full) == 0)
				return (0);
			if (full[y][0] != '0' && ft_atoi(full[y]) == 0)
				return (write(1, "Error\natoi\n", 13));
			ft_lstadd_back(&stcks->st_a, ft_lstnew(ft_atoi(full[y])));
			y++;
		}
		i++;
		y = 0;
		free_split(full);
	}
	return (1);
}

int	checktrie(t_pile stcks)
{
	t_stack	*tmp;
	int		i;

	tmp = stcks.st_a;
	i = 0;
	while (tmp)
	{
		if (tmp->next && tmp->content > tmp->next->content)
			i = 1;
		tmp = tmp->next;
	}
	return (i);
}
