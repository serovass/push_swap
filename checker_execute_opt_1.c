/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_execute_opt_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 11:33:08 by gnaida            #+#    #+#             */
/*   Updated: 2021/08/31 11:45:03 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_read_error_line(char *str)
{
	if (*str == '\n')
		return (-1);
	while (read(0, str, 1) > 0)
	{
		if (*str == '\n')
			return (-1);
	}
	return (-1);
}

int	ft_checker_execute_opt(t_infobox *box)
{
	char	str;

	while (read(0, &str, 1) > 0)
	{
		if (str == 's')
		{
			if (read(0, &str, 1) <= 0 || ft_execute_s_opt(box, &str) < 0)
				return (ft_read_error_line(&str));
		}
		else if (str == 'r')
		{
			if (read(0, &str, 1) <= 0 || ft_execute_r_opt(box, &str) < 0)
				return (ft_read_error_line(&str));
		}
		else if (str == 'p')
		{
			if (read(0, &str, 1) <= 0 || ft_execute_p_opt(box, &str) < 0)
				return (ft_read_error_line(&str));
		}
		else
			return (ft_read_error_line(&str));
	}
	return (1);
}
