/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_apply.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 21:43:26 by alamit            #+#    #+#             */
/*   Updated: 2018/10/31 09:37:30 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tree.h>
#include <tree_pvt.h>
#include <stdio.h>

static void	apply_io(t_node *node, void (*f)())
{
	if (node == NULL)
		return ;
	apply_io(left(node), f);
	f(g_data(node));
	apply_io(right(node), f);
}

void		tree_apply(t_tree *tree, void (*f)())
{
	apply_io(tree->root, f);
}

static void	apply_level(t_node *root, void (*f)(), unsigned long level)
{
	if (root == NULL)
		return ;
	else if (level == 0)
		f(g_data(root));
	else
	{
		apply_level(left(root), f, level - 1);
		apply_level(right(root), f, level - 1);
	}
}

void		tree_apply_bfs(t_tree *tree, void (*f)(), int order)
{
	unsigned long	height;
	unsigned long	i;

	height = tree_height(tree);
	i = order ? 0ul : height - 1;
	while (order ? (i < height) : (i >= 0))
	{
		apply_level(tree->root, f, i);
		i = (order) ? i + 1 : i - 1;
	}
}
