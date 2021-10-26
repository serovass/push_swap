/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 14:17:03 by gnaida            #+#    #+#             */
/*   Updated: 2021/08/28 14:17:09 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_main_sort_fanction(t_infobox *box)
{
	ft_sort_first_half(box);
	ft_sort_second_half(box);
}

void	ft_sort_first_half(t_infobox *box)
{
	int	imid;
	int	i;

	imid = box->imax / 2 + 1;
	i = imid - 1;
	while (i > 0)
	{
		if (box->afirst->index < imid)
		{
			ft_sort_operation(box, pb);
			i--;
		}
		else
			ft_ra_plus_rb(0, box, (imid - 1) / 2 + 1);
	}
	ft_push_b_to_a(box, imid - 1);
	ft_sort_by_portion(box);
}

void	ft_sort_second_half(t_infobox *box)
{
	while (box->afirst->portion == 0)
	{
		if (box->afirst->index == box->imin)
			ft_ra_plus_rb(1, box, (box->imax - box->imin + 1) / 2 + box->imin);
		else if (box->afirst->next->index == box->imin)
		{
			ft_sort_operation(box, sa);
			ft_ra_plus_rb(1, box, (box->imax - box->imin + 1) / 2 + box->imin);
		}
		else if (box->bfirst != NULL && box->bfirst->index == box->imin)
		{
			ft_sort_operation(box, pa);
			ft_ra_plus_rb(1, box, (box->imax - box->imin + 1) / 2 + box->imin);
		}
		else if (box->bfirst != NULL && box->blast->index == box->imin)
		{
			ft_sort_operation(box, rrb);
			ft_sort_operation(box, pa);
			ft_ra_plus_rb(1, box, (box->imax - box->imin + 1) / 2 + box->imin);
		}
		else
			ft_sort_operation(box, pb);
	}
	ft_push_b_to_a(box, box->imax);
	ft_sort_by_portion(box);
}

void	ft_sort_by_portion(t_infobox *box)
{
	int	portion;

	portion = box->afirst->portion;
	while (portion > 0)
	{
		while (portion == box->afirst->portion)
		{
			if (ft_find_sorted_elem(box) < 0)
				ft_sort_operation(box, pb);
		}
		ft_push_b_to_a(box, portion);
		portion = box->afirst->portion;
	}
}
