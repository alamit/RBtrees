/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_family.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 23:37:58 by alamit            #+#    #+#             */
/*   Updated: 2018/10/31 07:55:58 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tree_pvt.h>

t_node	*grand_parent(t_node *node)
{
	return (parent(parent(node)));
}

t_node	*sibling(t_node *node)
{
	t_node *p;
	
	p = parent(node);
	if (node == left(p))
		return (right(p));
	else if (node == right(p))
		return (left(p));
	return ((left(p) == NULL) ? right(p) : left(p));
}

t_node	*uncle(t_node *node)
{
	return (sibling(parent(node)));
}

int		has_red_child(t_node *node)
{
	return (color(left(node)) == RED || color(right(node)) == RED);
}
