/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_initialize_cheack_clear.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 15:01:49 by gnaida            #+#    #+#             */
/*   Updated: 2021/08/28 15:10:52 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_if_sorted(t_st *s)
{
	t_st	*tmp;

	if (s == NULL)
		return (1);
	tmp = s->next;
	while (tmp != NULL)
	{
		if (tmp->index < s->index)
			return (0);
		tmp = tmp->next;
		s = s->next;
	}
	return (1);
}

void	ft_clear_stack(t_st *a)
{
	t_st	*tmp;

	while (a != NULL)
	{
		tmp = a;
		a = a->next;
		free(tmp);
	}
}

void	ft_get_infobox(t_infobox *box)
{
	box->afirst = NULL;
	box->alast = NULL;
	box->bfirst = NULL;
	box->blast = NULL;
	box->opt = no;
	box->imax = 0;
	box->imin = 1;
}
