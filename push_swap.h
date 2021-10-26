/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 16:07:35 by gnaida            #+#    #+#             */
/*   Updated: 2021/08/28 16:50:57 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef enum s_operation
{
	no,
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
}	t_operation;

typedef struct s_st
{
	int			portion;
	int			index;
	struct s_st	*next;
	struct s_st	*prev;
}	t_st;

typedef struct s_infobox
{
	t_st		*afirst;
	t_st		*alast;
	t_st		*bfirst;
	t_st		*blast;
	t_operation	opt;
	int			imin;
	int			imax;
}	t_infobox;

int		ft_if_sorted(t_st *s);
void	ft_clear_stack(t_st *a);
void	ft_get_infobox(t_infobox *box);
t_st	*ft_fit_new_elem_a(long long int number);
int		ft_place_new_elem_a(t_infobox *box, t_st *new);
int		ft_get_new_elem_a(char *str, t_infobox *box, int i, int sign);
int		ft_parse_arg(char *str, t_infobox *box);
void	ft_create_stack_a(int argc, char **argv, t_infobox *box);
int		ft_elem_transfer_qsort(int piv, int end, int **arr);
int		ft_array_qsort(int **arr, int str, int end);
void	ft_fit_index_array(int **arr, int n);
int		ft_clear_array(int **arr, int i);
int		ft_get_indexes(t_st *a, int n);
void	ft_sort_stack_a(t_infobox *box);
void	ft_put_min_to_stacktop_a(t_infobox *box);
void	ft_sort_3_elem(t_infobox *box);
void	ft_sort_4_elem(t_infobox *box);
void	ft_sort_5_elem(t_infobox *box);
void	ft_swap(t_st **spfirst, t_st **splast);
void	ft_rotate(t_st **spfirst, t_st **splast);
void	ft_reverse_rotate(t_st **spfirst, t_st **splast);
void	ft_push_elem(t_st **from, t_st **fromlast, t_st **to, t_st **tolast);
void	ft_main_sort_fanction(t_infobox *box);
void	ft_sort_first_half(t_infobox *box);
void	ft_sort_second_half(t_infobox *box);
void	ft_sort_by_portion(t_infobox *box);
void	ft_place_sorted_elem(t_infobox *box);
void	ft_ra_plus_rb(int f, t_infobox *box, int bimid);
int		ft_find_sorted_elem(t_infobox *box);
void	ft_push_last_b_to_a(t_infobox *box, int imax);
void	ft_push_b_to_a(t_infobox *box, int imax);
void	ft_put_operation(t_operation opt);
void	ft_choose_operation(t_infobox *box, t_operation new);
void	ft_sort_operation(t_infobox *box, t_operation new);
int		ft_checker_execute_opt(t_infobox *box);
int		ft_execute_s_opt(t_infobox *box, char *str);
int		ft_execute_p_opt(t_infobox *box, char *str);
int		ft_execute_rr_opt(t_infobox *box, char *str);
int		ft_execute_r_opt(t_infobox *box, char *str);
int		ft_read_error_line(char *str);

#endif
