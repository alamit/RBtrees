/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_getters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 23:30:18 by alamit            #+#    #+#             */
/*   Updated: 2018/10/31 07:56:10 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tree_pvt.h>

t_node	*parent(t_node *node)
{
	if (node == NULL)
		return (NULL);
	return (node->parent);
}

t_node	*left(t_node *node)
{
	if (node == NULL)
		return (NULL);
	return (node->left);
}

t_node	*right(t_node *node)
{
	if (node == NULL)
		return (NULL);
	return (node->right);
}

t_color	color(t_node *node)
{
	if (node == NULL)
		return (BLACK);
	return (node->color);
}

void		*g_data(t_node *node)
{
	if (node == NULL)
		return (NULL);
	return (node->data);
}
