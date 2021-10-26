/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 14:17:35 by gnaida            #+#    #+#             */
/*   Updated: 2021/08/28 14:17:43 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
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
	i = ft_get_indexes(box.afirst, box.imax);
	if (i != 1)
	{
		if (i < 0)
			write(1, "Error\n", 6);
		ft_clear_stack(box.afirst);
		return (0);
	}
	ft_sort_stack_a(&box);
	return (0);
}
