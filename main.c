/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamit <alamit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 08:35:24 by alamit            #+#    #+#             */
/*   Updated: 2018/11/01 14:12:19 by alamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <tree.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	putstring(void *str)
{
	printf("%ld\n", (long)(str));
}

int		scmp(void *s1, void *s2)
{
	return (s1 - s2);
}

void	destroy(void *data)
{
	data = NULL;
}

void	*sum(long data, long a, long b)
{
	return ((void *)(data + a + b));
}

void	print(long n)
{
	printf("%ld", n);
}

int		main(int ac, char **av)
{
	t_tree *tree;
	//char a[26] = "abcdefghijklmnopqrstuvwxyz";
	if (ac < 2) return 0;
	tree = tree_new(scmp, destroy);
	printf("%lu\n", tree_size(tree));
	for (long i = 0; i < atoi(av[1]); ++i)
		tree_insert(tree, (void *)(long)(rand() % 100));
	printf("%lu\n", tree_size(tree));
	printf("%ld\n", (long)tree_reduce(tree, NULL, sum));
	printf("%lu\n", tree_height(tree));
	//tree_apply_bfs(tree, print, 1);
	tree_print(tree, print);
	printf("%s\n", (tree_contains(tree, (void *)12l)) ? "true" : "false");
	printf("%s\n", (tree_contains(tree, (void *)120l)) ? "true" : "false");

/* 	tree_delete(tree, (void *)6l);
	tree_print(tree);
	tree_delete(tree, (void *)0l);
	tree_print(tree);
	tree_delete(tree, (void *)1l);
	tree_print(tree);
	tree_delete(tree, (void *)7l);
	tree_print(tree);
	tree_delete(tree, (void *)5l);
	tree_print(tree);
	tree_delete(tree, (void *)3l);
	tree_print(tree);
	tree_delete(tree, (void *)8l);
	tree_print(tree);
	tree_delete(tree, (void *)4l);
	tree_print(tree);
	tree_delete(tree, (void *)2l);
	tree_print(tree);
	tree_delete(tree, (void *)9l);
	tree_print(tree); */
}
