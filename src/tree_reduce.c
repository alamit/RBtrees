/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_reduce.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 01:22:17 by alamit            #+#    #+#             */
/*   Updated: 2018/10/30 18:22:59 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tree.h>
#include <tree_pvt.h>

static void	*_reduce(t_node *node, void *neutral, void *(*f)())
{
	if (node == NULL)
		return (neutral);
	return (f(g_data(node),
				_reduce(left(node), neutral, f),
				_reduce(right(node), neutral, f)));
}

void		*tree_reduce(t_tree *tree, void *neutral, void *(*f)())
{
	return (_reduce(tree->root, neutral, f));
}