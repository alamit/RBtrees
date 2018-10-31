/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treeinsert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 02:37:34 by alamit            #+#    #+#             */
/*   Updated: 2018/10/29 23:06:46 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tree.h>
#include <tree_pvt.h>
#include <stdlib.h>

static void	insert(t_node	*root, t_node *new, int (*cmp)())
{
	if (cmp(g_data(new), g_data(root)) < 0)
	{
		if (left(root) != NULL)
			insert(left(root), new, cmp);
		else
		{
			new->parent = root;
			root->left = new;
		}
	}
	else
	{
		if (right(root) != NULL)
			insert(right(root), new, cmp);
		else
		{
			new->parent = root;
			root->right = new;
		}
	}
}

static void	balance(t_node *node)
{
	if(parent(node) == NULL)
		node->color = BLACK;
	else if (color(parent(node)) == RED)
	{
		parent(node)->color = BLACK;
		grand_parent(node)->color = RED;
		if (color(uncle(node)) == RED)
		{
			uncle(node)->color = BLACK;
			balance(grand_parent(node));
			return ;
		}
		if (node == right(left(grand_parent(node))))
		{
			rotate_left(parent(node));
			node = left(node);
		}
		else if (node == left(right(grand_parent(node))))
		{
			rotate_right(parent(node));
			node = right(node);
		}
		(node == left(parent(node))) ? rotate_right(grand_parent(node)) 
										: rotate_left(grand_parent(node));
	}
}

void		tree_insert(t_tree *tree, void *data)
{
	t_node	*new;

	new = node_new(data);
	if (tree_is_empty(tree))
		tree->root = new;
	else
	{
		new->color = RED;
		insert(tree->root, new, tree->cmp);
		balance(new);
		tree->root = root(tree->root);
	}
}