/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_execute_opt_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 11:45:43 by gnaida            #+#    #+#             */
/*   Updated: 2021/08/31 11:47:49 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_if_error_line(char *str)
{
	if (read(0, str, 1) <= 0)
		return (-1);
	else if (*str != '\n')
		return (ft_read_error_line(str));
	return (1);
}

int	ft_execute_s_opt(t_infobox *box, char *str)
{
	if (*str == 'a')
	{
		if (ft_check_if_error_line(str) < 0)
			return (-1);
		ft_swap(&box->afirst, &box->alast);
	}
	else if (*str == 'b')
	{
		if (ft_check_if_error_line(str) < 0)
			return (-1);
		ft_swap(&box->bfirst, &box->blast);
	}
	else if (*str == 's')
	{
		if (ft_check_if_error_line(str) < 0)
			return (-1);
		ft_swap(&box->afirst, &box->alast);
		ft_swap(&box->bfirst, &box->blast);
	}
	else
		return (ft_read_error_line(str));
	return (1);
}

int	ft_execute_p_opt(t_infobox *box, char *str)
{
	if (*str == 'a')
	{
		if (ft_check_if_error_line(str) < 0)
			return (-1);
		ft_push_elem(&box->bfirst, &box->blast, &box->afirst, &box->alast);
	}
	else if (*str == 'b')
	{
		if (ft_check_if_error_line(str) < 0)
			return (-1);
		ft_push_elem(&box->afirst, &box->alast, &box->bfirst, &box->blast);
	}
	else
		return (ft_read_error_line(str));
	return (1);
}

int	ft_execute_rr_opt(t_infobox *box, char *str)
{
	if (*str == 'a')
	{
		if (ft_check_if_error_line(str) < 0)
			return (-1);
		ft_reverse_rotate(&box->afirst, &box->alast);
	}
	else if (*str == 'b')
	{
		if (ft_check_if_error_line(str) < 0)
			return (-1);
		ft_reverse_rotate(&box->bfirst, &box->blast);
	}
	else if (*str == 'r')
	{
		if (ft_check_if_error_line(str) < 0)
			return (-1);
		ft_reverse_rotate(&box->afirst, &box->alast);
		ft_reverse_rotate(&box->bfirst, &box->blast);
	}
	else
		return (ft_read_error_line(str));
	return (1);
}

int	ft_execute_r_opt(t_infobox *box, char *str)
{
	if (*str == 'a')
	{
		if (ft_check_if_error_line(str) < 0)
			return (-1);
		ft_rotate(&box->afirst, &box->alast);
	}
	else if (*str == 'b')
	{
		if (ft_check_if_error_line(str) < 0)
			return (-1);
		ft_rotate(&box->bfirst, &box->blast);
	}
	else if (*str == 'r')
	{
		if (read(0, str, 1) <= 0)
			return (-1);
		if (*str != '\n')
			return (ft_execute_rr_opt(box, str));
		ft_rotate(&box->afirst, &box->alast);
		ft_rotate(&box->bfirst, &box->blast);
	}
	else
		return (ft_read_error_line(str));
	return (1);
}
