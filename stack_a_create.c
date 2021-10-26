/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 14:02:36 by gnaida            #+#    #+#             */
/*   Updated: 2021/08/28 14:18:45 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_st	*ft_fit_new_elem_a(long long int number)
{
	t_st	*new;

	if (number > 2147483647 || number < -2147483648)
		return (NULL);
	new = (t_st *)malloc(sizeof(t_st));
	if (new == NULL)
		return (NULL);
	new->portion = 0;
	new->index = number;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

int	ft_place_new_elem_a(t_infobox *box, t_st *new)
{
	if (new == NULL)
		return (-1);
	if (box->afirst == NULL)
	{
		box->afirst = new;
		box->alast = new;
	}
	else
	{
		new->prev = box->alast;
		box->alast->next = new;
		box->alast = new;
	}
	box->imax++;
	return (1);
}

int	ft_get_new_elem_a(char *str, t_infobox *box, int i, int sign)
{
	long long int	number;

	number = 0;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9' \
			&& number < 2147483649)
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	if (ft_place_new_elem_a(box, ft_fit_new_elem_a(number * sign)) < 0)
		return (-1);
	return (i);
}

int	ft_parse_arg(char *str, t_infobox *box)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			i++;
		else if (str[i] >= '0' && str[i] <= '9')
			i = ft_get_new_elem_a(str, box, i, 1);
		else if (str[i] == '-' && str[i + 1] != '\0')
			i = ft_get_new_elem_a(str, box, i + 1, -1);
		else if (str[i] == '+' && str[i + 1] != '\0')
			i = ft_get_new_elem_a(str, box, i + 1, 1);
		else
			return (-1);
		if (i < 0)
			return (-1);
	}
	return (1);
}

void	ft_create_stack_a(int argc, char **argv, t_infobox *box)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_parse_arg(argv[i], box) > 0)
			i++;
		else
		{
			ft_clear_stack(box->afirst);
			box->afirst = NULL;
			return ;
		}
	}
}
