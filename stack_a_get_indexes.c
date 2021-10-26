/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_get_indexes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 14:19:30 by gnaida            #+#    #+#             */
/*   Updated: 2021/08/28 14:41:51 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_elem_transfer_qsort(int piv, int end, int **arr)
{
	int	*tmp;

	tmp = arr[piv + 1];
	arr[piv + 1] = arr[end];
	arr[end] = tmp;
	tmp = arr[piv];
	arr[piv] = arr[piv + 1];
	arr[piv + 1] = tmp;
	return (piv + 1);
}

int	ft_array_qsort(int **arr, int str, int end)
{
	int	piv;
	int	end2;

	piv = str;
	end2 = end;
	while (piv != end)
	{
		if (*arr[piv] == *arr[end])
			return (-1);
		if (*arr[piv] >= *arr[end])
			piv = ft_elem_transfer_qsort(piv, end, arr);
		else
			end--;
	}
	if (str != piv)
	{
		if (ft_array_qsort(arr, str, piv - 1) < 0)
			return (-1);
	}
	if (piv != end2)
	{
		if (ft_array_qsort(arr, piv + 1, end2) < 0)
			return (-1);
	}
	return (0);
}

void	ft_fit_index_array(int **arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		*arr[i] = i + 1;
		i++;
	}
}

int	ft_clear_array(int **arr, int i)
{
	free(arr);
	return (i);
}

int	ft_get_indexes(t_st *a, int n)
{
	int	**arr;
	int	i;
	int	j;

	arr = (int **)malloc(sizeof(int *) * n);
	if (arr == NULL)
		return (-1);
	i = 0;
	j = 1;
	while (a != NULL)
	{
		if (a->prev != NULL && a->prev->index < a->index)
			j++;
		arr[i] = &a->index;
		a = a->next;
		i++;
	}
	if (i == j)
		return (ft_clear_array(arr, 0));
	if (ft_array_qsort(arr, 0, n - 1) < 0)
		return (ft_clear_array(arr, -1));
	ft_fit_index_array(arr, n);
	return (ft_clear_array(arr, 1));
}
