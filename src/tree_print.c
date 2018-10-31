#include <tree.h>
#include <tree_pvt.h>
#include <stdio.h>

static void padding(char c, int n)
{
    int i;

    i = 0;
    while (i < n)
    {
        putchar(c);
        ++i;
    }
}

static void print(t_node *root, unsigned long level)
{
    if (root == NULL)
        return ;
    else
    {
        print(right(root), level + 1);
        padding('\t', level);
        printf("%s%ld%s\n", color(root) == RED ? "\x1B[31m" : "",
                            (long)g_data(root),
                            "\x1B[0m");
        print(left(root), level + 1);
    }
}

void        tree_print(t_tree *tree)
{
    print(tree->root, 0);
}