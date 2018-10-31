/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 23:28:38 by alamit            #+#    #+#             */
/*   Updated: 2018/10/31 07:56:16 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tree_pvt.h>

t_node	*node_new(void *data)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	new->data = data;
	new->color = BLACK;
	new->parent = NULL;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

t_node	*root(t_node *node)
{
	while (parent(node) != NULL)
		node = parent(node);
	return (node);
}

t_node	*min(t_node *node)
{
	if (node == NULL)
		return (NULL);
	while (left(node) != NULL)
		node = left(node);
	return (node);
}
