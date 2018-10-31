/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_rotations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 23:31:26 by alamit            #+#    #+#             */
/*   Updated: 2018/10/31 08:36:33 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tree_pvt.h>

void	rotate_left(t_node *node)
{
	t_node	*new;
	
	new = right(node); // check NULL ?
	node->right = left(new);
	new->left = node;
	if (right(node) != NULL)
		right(node)->parent = node;
	if (parent(node) != NULL)
	{
		if (node == left(parent(node)))
			parent(node)->left = new;
		else if (node == right(parent(node)))
			parent(node)->right = new;
	}
	new->parent = parent(node);
	node->parent = new;
}

void	rotate_right(t_node *node)
{
	t_node	*new;
	
	new = left(node); // check NULL ?
	node->left = right(new);
	new->right = node;
	if (left(node) != NULL)
		left(node)->parent = node;
	if (parent(node) != NULL)
	{
		if (node == left(parent(node)))
			parent(node)->left = new;
		else if (node == right(parent(node)))
			parent(node)->right = new;
	}
	new->parent = parent(node);
	node->parent = new;
}
