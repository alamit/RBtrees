/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_delete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 00:09:50 by alamit            #+#    #+#             */
/*   Updated: 2018/10/31 08:37:45 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tree.h>
#include <tree_pvt.h>
#include <stdlib.h>

static t_node	*find_delete(t_node *root, void *data, int (*cmp)())
{
	t_node	*tmp;

	if (root == NULL)
		return (NULL);
	else if (cmp(data, g_data(root)) < 0)
		return (find_delete(left(root), data, cmp));
	else if (cmp(data, g_data(root)) > 0)
		return (find_delete(right(root), data, cmp));
	else if (left(root) != NULL && right(root) != NULL)
	{
		tmp = min(right(root));
		root->data = g_data(tmp);
		return (find_delete(right(root), g_data(tmp), cmp));
	}
	tmp = (left(root) == NULL) ? right(root) : left(root);
	if (tmp != NULL) 
		tmp->parent = parent(root);
	if (root == left(parent(root)))
		parent(root)->left = tmp;
	else if (root == right(parent(root)))
		parent(root)->right = tmp;
	return (root);
}

static void		rotate(t_node *node, int sibling_is_left_child, int sibling_has_left_red)
{
	if (sibling_is_left_child && sibling_has_left_red)
	{
		left(sibling(node))->color = color(sibling(node));
		sibling(node)->color = color(parent(node));
		rotate_right(parent(node));	
	}
	else if (sibling_is_left_child)
	{
		right(sibling(node))->color = color(parent(node));
		rotate_right(sibling(node));
		rotate_left(parent(node));
	}
	else if (sibling_has_left_red)
	{
		left(sibling(node))->color = color(parent(node));
		rotate_left(sibling(node));
		rotate_right(parent(node));
	}
	else
	{
		right(sibling(node))->color = color(sibling(node));
		sibling(node)->color = color(parent(node));
		rotate_left(parent(node));
	}
	parent(node)->color = BLACK;
}

static void		balance(t_node *node)
{
	if (node == root(node))
		node->color = BLACK;
	else if (sibling(node) == NULL)
		balance(parent(node));
	else if (color(sibling(node)) == BLACK)
	{
		if (has_red_child(sibling(node)))
			rotate(node, 
					sibling(node) == left(parent(node)),
					color(left(sibling(node))) == RED);
		else
		{	
			sibling(node)->color = RED;
			(color(parent(node)) == BLACK) ? balance(parent(node))
											: (parent(node)->color = BLACK);
		}
	}
	else
	{
		parent(node)->color = RED;
		sibling(node)->color = BLACK;
		(sibling(node) == left(parent(node))) ? rotate_right(parent(node))
												: rotate_left(parent(node));
		balance(node);
	}
}

void			tree_delete(t_tree *tree, void *data)
{
	t_node *deleted;
	t_node *child;

	deleted = find_delete(tree->root, data, tree->cmp);
	if (deleted == NULL)
		return ;
	child = (left(deleted) == NULL) ? right(deleted) : left(deleted);
	if (color(child) == RED)
		child->color = BLACK;
	else if (color(deleted) != RED)
		balance((child == NULL) ? deleted : child);
	tree->root = root(tree->root);
	if (tree->root == deleted)
		tree->root = NULL;
	tree->destroy(deleted);
}