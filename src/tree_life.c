/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_life.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 08:35:19 by alamit            #+#    #+#             */
/*   Updated: 2018/10/31 08:39:19 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tree.h>
#include <tree_pvt.h>
#include <stdlib.h>

t_tree			*tree_new(int (*cmp)(), void (*destroy)())
{
	t_tree	*new;

	new = malloc(sizeof(t_tree));
	new->root = NULL;
	new->cmp = cmp;
	new->destroy = destroy;
	return (new);
}

static void		destroy_level(t_node *node,
								unsigned long level,
								void (*destroy)())
{
	if (node == NULL)
		return;
	else if (level == 0)
	{
		destroy(g_data(node));
		free(node);
	}
	destroy_level(left(node), level - 1, destroy);
	destroy_level(right(node), level - 1, destroy);
}

void	tree_destroy(t_tree **tree)
{
	unsigned long height;

	height = tree_height(*tree);
	while (height >= 0)
	{
		destroy_level((*tree)->root, height, (*tree)->destroy);
		--height;
	}
	free(*tree);
	*tree = NULL;
}

static void		root_dup(t_tree *dst, t_node *src)
{
	if (src == NULL)
		return ;
	root_dup(dst, left(src));
	tree_insert(dst, g_data(src));
	root_dup(dst, right(src));
}

t_tree			*tree_dup(t_tree *tree)
{
	t_tree	*new;

	new = tree_new(tree->cmp, tree->destroy);
	root_dup(new, tree->root);
	return (new);
}
