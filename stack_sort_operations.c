/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 15:26:42 by gnaida            #+#    #+#             */
/*   Updated: 2021/08/28 15:44:54 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_st **spfirst, t_st **splast)
{
	t_st	*tmp;
	t_st	*s;

	if (*spfirst == NULL || *spfirst == *splast)
		return ;
	s = *spfirst;
	tmp = s->next;
	if (tmp->next == NULL)
		*splast = s;
	s->next = tmp->next;
	s->prev = tmp;
	tmp->next = s;
	tmp->prev = NULL;
	*spfirst = tmp;
}

void	ft_rotate(t_st **spfirst, t_st **splast)
{
	t_st	*tmp;
	t_st	*sfirst;
	t_st	*slast;

	if (*spfirst == NULL || *spfirst == *splast)
		return ;
	sfirst = *spfirst;
	slast = *splast;
	tmp = sfirst;
	sfirst = sfirst->next;
	sfirst->prev = NULL;
	tmp->next = NULL;
	tmp->prev = sfirst;
	slast->next = tmp;
	tmp->prev = slast;
	*splast = tmp;
	*spfirst = sfirst;
}

void	ft_reverse_rotate(t_st **spfirst, t_st **splast)
{
	t_st	*tmp;
	t_st	*sfirst;
	t_st	*slast;

	if (*spfirst == NULL || *spfirst == *splast)
		return ;
	sfirst = *spfirst;
	slast = *splast;
	tmp = slast;
	slast = slast->prev;
	slast->next = NULL;
	sfirst->prev = tmp;
	tmp->next = sfirst;
	tmp->prev = NULL;
	*spfirst = tmp;
	*splast = slast;
}

void	ft_push_elem(t_st **from, t_st **fromlast, t_st **to, t_st **tolast)
{
	t_st	*tmp;
	t_st	*sfrom;
	t_st	*sto;

	if (*from == NULL)
		return ;
	sfrom = *from;
	sto = *to;
	tmp = sfrom;
	sfrom = sfrom->next;
	if (sfrom != NULL)
		sfrom->prev = NULL;
	else
		*fromlast = NULL;
	tmp->next = sto;
	if (sto != NULL)
		sto->prev = tmp;
	else
		*tolast = tmp;
	*to = tmp;
	*from = sfrom;
}
