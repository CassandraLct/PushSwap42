/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecat <clecat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:41:59 by clecat            #+#    #+#             */
/*   Updated: 2022/05/20 15:20:54 by clecat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../SRC/push_swap.h"

//soit faire fonction pour check "" ou faire dans check sign
int	check_sign(const char *str, int sign)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	return (sign);
}

void	free_split(char	**str)
{
	char	**tmp;

	tmp = str;
	while (*tmp)
		free(*tmp++);
	free(str);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	check_int(char **full)
{
	int	y;

	y = 0;
	if (ft_strlen(full[y]) >= 11 || ft_strlen(full[y]) >= 10)
	{
		if (!(ft_atoi(full[y]) == 2147483647))
		{
			ft_error("Error\nnot int\n");
			return (0);
		}
		else if (!(ft_atoi(full[y]) == -2147483648))
		{
			ft_error("Error\nnot int\n");
			return (0);
		}
	}
	return (1);
}

void	ft_error(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}
