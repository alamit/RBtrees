#ifndef TREE_PVT_H
# define TREE_PVT_H

# include <tree.h>
# include <stdlib.h>

t_node	*node_new(void *data);
t_node	*parent(t_node *node);
t_node	*grand_parent(t_node *node);
t_node	*root(t_node *node);
t_node	*sibling(t_node *node);
t_node	*uncle(t_node *node);
t_node	*left(t_node *node);
t_node	*right(t_node *node);
t_color	color(t_node *node);
void	*g_data(t_node *node);
void	rotate_right(t_node *node);
void	rotate_left(t_node *node);
int		has_red_child(t_node *node);
t_node	*min(t_node *node);

#endif