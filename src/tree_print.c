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

static void print(t_node *root, unsigned long level, void (*f)())
{
    if (root == NULL)
        return ;
    else
    {
        print(right(root), level + 1, f);
        padding('\t', level);
        printf(color(root) ? "\x1B[31m" : "\x1B[0m");
        f(g_data(root));
        printf("\x1B[0m\n");
        print(left(root), level + 1, f);
    }
}

void        tree_print(t_tree *tree, void (*f)())
{
    print(tree->root, 0, f);
}
