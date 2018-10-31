/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_contains.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:11:30 by alamit            #+#    #+#             */
/*   Updated: 2018/10/30 21:22:36 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tree.h>
#include <tree_pvt.h>
#include <stdlib.h>

static	int	contains(t_node *node, int (*f)())
{
	if (node == NULL)
		return (0);
	return (f(g_data(node)) ||
			contains(left(node), f) ||
			contains(right(node), f));	
}

int			tree_contains(t_tree *tree, int (*f)())
{
	return (contains(tree->root, f));
}
