/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecat <clecat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 08:40:34 by clecat            #+#    #+#             */
/*   Updated: 2022/05/20 15:17:18 by clecat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_pile
{
	t_stack	*st_a;
	int		size_a;
	t_stack	*st_b;
	int		size_b;
	int		minst_a;
	int		posmin;
	int		median;
	int		limit;
	int		nbchunk;
	int		max;
}	t_pile;

int		check_sign(const char *str, int sign);
int		ft_strlen(const char *s);
int		ft_lstsize(t_stack *lst);
void	ft_error(char *str);
int		check_int(char **full);
int		ft_atoi(const char *str);
void	free_split(char	**str);
char	**ft_split(char const *s, char c);
int		ft_mklist(t_pile *stcks, int argc, char **argv);
void	ft_lstadd_back(t_stack **alst, t_stack *new);
t_stack	*ft_lstnew(int content);
t_stack	*ft_lstlast(t_stack *lst);
int		ft_chklist(int argc, char **argv);
int		ft_chkdigit(char *str);
int		verif(t_pile stcks);
int		checktrie(t_pile stcks);
void	sa(t_pile *stcks);
void	pa(t_pile *stcks);
void	ra(t_pile *stcks);
void	rra(t_pile *stcks);
void	print_stack(t_stack *t);
void	ss(t_pile *stcks);
void	sb(t_pile *stcks);
void	pb(t_pile *stcks);
void	rb(t_pile *stcks);
int		check_doublecot(const char *str);
void	rrb(t_pile *stcks);
void	rrr(t_pile *stcks);
int		size_stack(t_stack *stk);
void	trie3(t_pile *stk);
void	choosecase(t_pile *stk);
void	trie4(t_pile *stk);
void	trie5(t_pile *stk);
void	getbiger(t_pile *stk);
void	mvlower5(t_pile *stck);
void	getlower(t_pile *stk);
void	mvlower4(t_pile *stk);
void	trie100(t_pile *stk);
int		getlower2(t_pile *stk);
int		scan_up(t_pile *stk, int limit);
int		scan_down(t_pile *stk, int limit);
void	changevalue(t_pile *stk);
void	find_chunk(t_pile *stk, int nb);
void	check_b(t_pile *stk);
void	ft_usechunk(t_pile *stk);

#endif
