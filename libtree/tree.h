/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 21:20:01 by alamit            #+#    #+#             */
/*   Updated: 2018/11/01 00:17:30 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

/*
**	TODO LIST
**	void			tree_filter(t_tree *tree, void *min, void *max);
*/

typedef enum	e_color {BLACK, RED}
				t_color;

typedef struct	s_node
{
	void			*data;
	t_color			color;
	struct s_node	*parent;
	struct s_node	*left;
	struct s_node	*right;
}				t_node;

typedef struct	s_tree
{
	t_node		*root;
	int			(*cmp)();
	void		(*destroy)();
}				t_tree;

t_tree			*tree_new(int (*cmp)(), void (*destroy)());
void			tree_destroy(t_tree **tree);
t_tree			*tree_dup(t_tree *tree);

void			tree_insert(t_tree *tree, void *data);
void			tree_delete(t_tree *tree, void *data);
void			tree_apply_io(t_tree *tree, void (*f)());
void			tree_apply_bfs(t_tree *tree, void (*f)(), int order);

void			*tree_reduce(t_tree *tree, void *init, void *(*f)());
unsigned long	tree_size(t_tree *tree);
int				tree_is_empty(t_tree *tree);
unsigned long	tree_height(t_tree *tree);
int 			tree_contains(t_tree *tree, void *data);
void			*tree_find(t_tree *tree, void *base);
void			**tree_to_array(t_tree *tree, void (*cpy)());
/*
**	NOTE: Change to take print function as param.
*/
void			tree_print(t_tree *tree);

#endif
