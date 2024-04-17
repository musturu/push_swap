/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoricon <lmoricon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:48:19 by lmoricon          #+#    #+#             */
/*   Updated: 2024/04/15 18:05:31 by lmoricon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(int))
{
	t_list	*current;

	if (lst == NULL || f == NULL)
		return ;
	current = lst;
	while (current != NULL)
	{
		(*f)(current -> content);
		current = current -> next;
	}
}
