/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 15:11:22 by gnaida            #+#    #+#             */
/*   Updated: 2021/08/28 15:26:07 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_stack_a(t_infobox *box)
{
	if (box->imax == 2)
	{
		if (box->afirst->index > box->afirst->next->index)
			ft_sort_operation(box, sa);
	}
	else if (box->imax == 3)
		ft_sort_3_elem(box);
	else if (box->imax == 4)
		ft_sort_4_elem(box);
	else if (box->imax == 5)
		ft_sort_5_elem(box);
	else
		ft_main_sort_fanction(box);
	ft_put_operation(box->opt);
	ft_clear_stack(box->afirst);
}

void	ft_put_min_to_stacktop_a(t_infobox *box)
{
	t_st	*second;

	second = box->afirst->next;
	if (box->afirst == box->alast)
		return ;
	else if (second == box->alast)
	{
		if (box->afirst->index > box->alast->index)
			ft_sort_operation(box, sa);
	}
	else if (box->afirst->index < second->index && \
			box->afirst->index < box->alast->index)
		return ;
	else if (second->index < box->afirst->index && \
			second->index < box->alast->index)
	{
		if (box->afirst->index > box->alast->index)
			ft_sort_operation(box, ra);
		else if (box->afirst->index < box->alast->index)
			ft_sort_operation(box, sa);
	}
	else if (box->alast->index < box->afirst->index && \
			box->alast->index < second->index)
		ft_sort_operation(box, rra);
}

void	ft_sort_3_elem(t_infobox *box)
{
	t_st	*first;
	t_st	*last;
	t_st	*second;

	first = box->afirst;
	last = box->alast;
	second = first->next;
	if (second->index > last->index && first->index < last->index)
	{
		ft_sort_operation(box, sa);
		ft_sort_operation(box, ra);
	}
	else if (last->index > first->index && first->index > second->index)
		ft_sort_operation(box, sa);
	else if (second->index > first->index && first->index > last->index)
		ft_sort_operation(box, rra);
	else if (first->index > second->index && last->index > second->index)
		ft_sort_operation(box, ra);
	else if (first->index > second->index && second->index > last->index)
	{
		ft_sort_operation(box, ra);
		ft_sort_operation(box, sa);
	}
}

void	ft_sort_4_elem(t_infobox *box)
{
	if (ft_if_sorted(box->afirst))
		return ;
	ft_put_min_to_stacktop_a(box);
	if (!ft_if_sorted(box->afirst))
	{
		ft_sort_operation(box, pb);
		ft_sort_3_elem(box);
		ft_sort_operation(box, pa);
	}
	if (!ft_if_sorted(box->afirst))
		ft_sort_operation(box, sa);
}

void	ft_sort_5_elem(t_infobox *box)
{
	if (box->afirst->index == 3 || box->afirst->index == 4)
	{
		if (box->afirst->next->index == 3 || box->afirst->next->index == 4)
			ft_sort_operation(box, rra);
		else
			ft_sort_operation(box, sa);
	}
	ft_sort_operation(box, pb);
	ft_sort_4_elem(box);
	ft_sort_operation(box, pa);
	ft_put_min_to_stacktop_a(box);
}
