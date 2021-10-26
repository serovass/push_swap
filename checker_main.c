/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 14:14:46 by gnaida            #+#    #+#             */
/*   Updated: 2021/08/28 18:13:28 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_get_checker_result(t_infobox *box)
{
	write(1, "\r", 1);
	if (ft_if_sorted(box->afirst) && box->bfirst == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_infobox	box;

	if (argc < 2)
		return (0);
	ft_get_infobox(&box);
	ft_create_stack_a(argc, argv, &box);
	if (box.afirst == NULL)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (ft_get_indexes(box.afirst, box.imax) < 0)
	{
		write(1, "Error\n", 6);
		ft_clear_stack(box.afirst);
		return (0);
	}
	if (ft_checker_execute_opt(&box) < 0)
		write(1, "Error\n", 6);
	else
		ft_get_checker_result(&box);
	ft_clear_stack(box.afirst);
	ft_clear_stack(box.bfirst);
	return (0);
}
