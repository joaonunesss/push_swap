/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinho <jmarinho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 10:07:19 by rumachad          #+#    #+#             */
/*   Updated: 2023/08/01 14:57:06 by jmarinho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	check_args(char *argv[], int flag)
{
	int	i;
	int	k;

	i = 1;
	k = 0;
	if (flag == 0)
		i = 0;
	while (argv[i])
	{
		k = 0;
		if (argv[i][k] == '-' && argv[i][k + 1])
			k++;
		while (argv[i][k])
		{
			if (argv[i][k] >= '0' && argv[i][k] <= '9')
				k++;
			else
			{
				if (flag == 0)
					free_array_ps(argv, 0);
				error();
			}
		}
		i++;
	}
}

void	check_dup(t_node *a)
{
	t_node	*head_a;
	t_node	*temp_a;

	head_a = a;
	while (a != NULL)
	{
		temp_a = a->next;
		while (temp_a != NULL)
		{
			if (temp_a->data == a->data)
				free_list(&head_a, 1);
			temp_a = temp_a->next;
		}
		a = a->next;
	}
}

void	check_int_max_min(t_node *a)
{
	t_node	*temp_a;

	temp_a = a;
	while (temp_a != NULL)
	{
		if ((temp_a->data > 2147483647 || temp_a->data < -2147483648))
			free_list(&a, 1);
		temp_a = temp_a->next;
	}
}
