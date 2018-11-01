/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_to_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 23:06:56 by alamit            #+#    #+#             */
/*   Updated: 2018/11/01 00:02:00 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tree.h>
#include <tree_pvt.h>
#include <stdlib.h>

static void	to_array(t_node *root,
						void (*cpy)(),
						void **array,
						unsigned long *index)
{
	if (root == NULL)
		return ;
	to_array(left(root), cpy, array, index);
	cpy(array[*index], g_data(root));
	++*index;
	to_array(right(root), cpy, array, index);
}

void		**tree_to_array(t_tree *tree, void (*cpy)())
{
	void			**array;
	unsigned long 	index;

	index = 0ul;
	array = malloc((tree_size(tree) + 1) * sizeof(void *));
	to_array(tree->root, cpy, array, &index);
	array[index] = NULL;
	return (array);
}
