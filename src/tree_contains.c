/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_contains.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:11:30 by alamit            #+#    #+#             */
/*   Updated: 2018/10/31 20:41:44 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tree.h>
#include <tree_pvt.h>
#include <stdlib.h>

static	int	contains(t_node *node, void *data, int (*cmp)())
{
	if (node == NULL)
		return (0);
	return (cmp(g_data(node), data) == 0 ||
			contains(left(node), data, cmp) ||
			contains(right(node), data, cmp));
}

int			tree_contains(t_tree *tree, void *data)
{
	return (contains(tree->root, data, tree->cmp));
}
