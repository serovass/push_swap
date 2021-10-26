/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort_additional_functions.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 14:15:52 by gnaida            #+#    #+#             */
/*   Updated: 2021/08/28 14:16:01 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_place_sorted_elem(t_infobox *box)
{
	box->afirst->portion = -1;
	ft_sort_operation(box, ra);
	box->imin++;
}

void	ft_ra_plus_rb(int f, t_infobox *box, int bimid)
{
	if (f == 0)
		ft_sort_operation(box, ra);
	else
		ft_place_sorted_elem(box);
	if (box->bfirst != NULL && box->bfirst->index < bimid)
		ft_sort_operation(box, rb);
}

int	ft_find_sorted_elem(t_infobox *box)
{
	if (box->afirst->index == box->imin)
		ft_place_sorted_elem(box);
	else if (box->afirst->next->index == box->imin)
	{
		ft_sort_operation(box, sa);
		ft_place_sorted_elem(box);
	}
	else if (box->bfirst != NULL && box->bfirst->index == box->imin)
	{
		ft_sort_operation(box, pa);
		ft_place_sorted_elem(box);
	}
	else if (box->bfirst != box->blast && box->blast->index == box->imin)
	{
		ft_sort_operation(box, rrb);
		ft_sort_operation(box, pa);
		ft_place_sorted_elem(box);
	}
	else
		return (-1);
	return (1);
}

void	ft_push_last_b_to_a(t_infobox *box, int imax)
{
	if (box->afirst->index == box->imin)
		ft_place_sorted_elem(box);
	else if (box->afirst->next->index == box->imin)
	{
		ft_sort_operation(box, sa);
		ft_place_sorted_elem(box);
	}
	else
	{
		box->bfirst->portion = imax;
		ft_sort_operation(box, pa);
	}
}

void	ft_push_b_to_a(t_infobox *box, int imax)
{
	int	imid;
	int	i;

	while (box->bfirst != NULL)
	{
		imid = (imax - box->imin + 1) / 2 + box->imin;
		i = imax - imid;
		if (i < 1 || box->bfirst == box->blast)
			ft_push_last_b_to_a(box, imax);
		while (box->bfirst != NULL && i > 0)
		{
			if (ft_find_sorted_elem(box) < 0)
			{
				if (box->bfirst != NULL && box->bfirst->index > imid)
				{
					box->bfirst->portion = imax;
					ft_sort_operation(box, pa);
					i--;
				}
				else
					ft_sort_operation(box, rb);
			}
		}
		imax = imid;
	}
}
