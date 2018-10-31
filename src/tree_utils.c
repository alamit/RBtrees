/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 00:28:47 by alamit            #+#    #+#             */
/*   Updated: 2018/10/30 20:07:51 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tree.h>
#include <tree_pvt.h>
#include <stdlib.h>

static void	*size(unsigned long data, unsigned long a, unsigned long b)
{
	data = (unsigned long)1l;
	return ((void *)(data + a + b));
}	

unsigned long	tree_size(t_tree *tree)
{
	return ((unsigned long)tree_reduce(tree, 0l, size));
}

int				tree_is_empty(t_tree *tree)
{
	return (tree_size(tree) == 0);
}

static void		*height(unsigned long data, unsigned long a, unsigned long b)
{
	data = (unsigned long)1l;
	return ((void *)(data + (a > b ? a : b)));
}

unsigned long	tree_height(t_tree *tree)
{
	return ((unsigned long)tree_reduce(tree, 0l, height));
}