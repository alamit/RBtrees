/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_reduce.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 01:22:17 by alamit            #+#    #+#             */
/*   Updated: 2018/10/31 09:38:37 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tree.h>
#include <tree_pvt.h>

static void	*reduce(t_node *node, void *neutral, void *(*f)())
{
	if (node == NULL)
		return (neutral);
	return (f(g_data(node),
				reduce(left(node), neutral, f),
				reduce(right(node), neutral, f)));
}

void		*tree_reduce(t_tree *tree, void *neutral, void *(*f)())
{
	return (reduce(tree->root, neutral, f));
}
