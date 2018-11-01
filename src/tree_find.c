/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 22:24:33 by alamit            #+#    #+#             */
/*   Updated: 2018/11/01 00:15:31 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tree.h>
#include <tree_pvt.h>
#include <stdlib.h>

static void	*find(t_node *node, void *base, int (*cmp)())
{
	if (node == NULL)
		return (NULL);
	else if (cmp(base, g_data(node)) == 0)
		return (g_data(node));
	else if (cmp(base, g_data(node)) < 0)
		return (find(left(node), base, cmp));
	else
		return (find(right(node), base, cmp));
}

void		*tree_find(t_tree *tree, void *base)
{
	return (find(tree->root, base, tree->cmp));
}
