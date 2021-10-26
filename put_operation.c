/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 14:18:02 by gnaida            #+#    #+#             */
/*   Updated: 2021/08/28 14:18:07 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_put_operation(t_operation opt)
{
	if (opt == no)
		return ;
	else if (opt == sa)
		write(1, "sa\n", 3);
	else if (opt == sb)
		write(1, "sb\n", 3);
	else if (opt == ss)
		write (1, "ss\n", 3);
	else if (opt == pa)
		write(1, "pa\n", 3);
	else if (opt == pb)
		write (1, "pb\n", 3);
	else if (opt == ra)
		write (1, "ra\n", 3);
	else if (opt == rb)
		write (1, "rb\n", 3);
	else if (opt == rr)
		write (1, "rr\n", 3);
	else if (opt == rra)
		write (1, "rra\n", 4);
	else if (opt == rrb)
		write(1, "rrb\n", 4);
	else
		write(1, "rrr\n", 4);
}

void	ft_choose_operation(t_infobox *box, t_operation new)
{
	if (box->opt == no)
		box->opt = new;
	else if ((box->opt == sa && new == sb) || (box->opt == sb && new == sa))
	{
		ft_put_operation(ss);
		box->opt = no;
	}
	else if ((box->opt == ra && new == rb) || (box->opt == rb && new == ra))
	{
		ft_put_operation(rr);
		box->opt = no;
	}
	else if ((box->opt == rra && new == rrb) || (box->opt == rrb && new == rra))
	{
		ft_put_operation(rrr);
		box->opt = no;
	}
	else
	{
		ft_put_operation(box->opt);
		box->opt = new;
	}
}

void	ft_sort_operation(t_infobox *box, t_operation new)
{
	if (new == sa)
		ft_swap(&box->afirst, &box->alast);
	else if (new == sb)
		ft_swap(&box->bfirst, &box->blast);
	else if (new == pa)
		ft_push_elem(&box->bfirst, &box->blast, &box->afirst, &box->alast);
	else if (new == pb)
		ft_push_elem(&box->afirst, &box->alast, &box->bfirst, &box->blast);
	else if (new == ra && box->afirst != box->alast)
		ft_rotate(&box->afirst, &box->alast);
	else if (new == rb && box->bfirst != box->blast)
		ft_rotate(&box->bfirst, &box->blast);
	else if (new == rra)
		ft_reverse_rotate(&box->afirst, &box->alast);
	else if (new == rrb)
		ft_reverse_rotate(&box->bfirst, &box->blast);
	else
		return ;
	ft_choose_operation(box, new);
}
