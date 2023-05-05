//
// Created by Administrator on 2023/4/5.
//
#include <stdio.h>
#include <stdlib.h>

typedef int Type;

typedef struct BSTreeNode
{
    Type key;
    struct BSTreeNode *left;
    struct BSTreeNode * right;
    struct BSTreeNode * parent;
} Node, *BSTree;

static Node* create_bstree_node(Type key, Node *parent, Node *left, Node * right) {
    Node *p;
    if ((p = (Node *)malloc(sizeof(Node))) == NULL)
        return NULL;
    p->key = key;
    p->left = left;
    p->right = right;
    p->key = key;

    return p;
}

// 前序遍历
void preorder_bstree(BSTree tree) {
    if (tree != NULL) {
        printf("%d", tree->key);
        preorder_bstree(tree->left);
        preorder_bstree(tree->right);
    }
}
// 中序遍历
void inorder_bstree(BSTree tree) {
    if (tree != NULL) {
        inorder_bstree(tree->left);
        printf("%d", tree->key);
        inorder_bstree(tree->right);
    }
}
// 后序遍历
void postorder_bstree(BSTree tree) {
    if (tree != NULL) {
        postorder_bstree(tree->left);
        postorder_bstree(tree->right);
        printf("%d", tree->key);
    }
}

// 最大值
Node* bstree_min(BSTree tree) {
    if (tree == NULL) return NULL;

    while (tree->left != NULL)
        tree = tree->left;
    return tree;
}

// 最大值
Node* bstree_max(BSTree tree) {
    if (tree == NULL) return NULL;

    while (tree->right != NULL)
        tree = tree->right;
    return tree;
}
//  节点的前驱, 左子树中最大的节点
//  节点的后继, 右子树中最小的节点


Node* bstree_pre(Node *x) {
    // 当前节点有左子树, 查找左子树最大值
    if (x->left != NULL) return  bstree_max(x->left);
    

    Node* y = x->parent;
    // 当前节点是右节点, 前驱节点是父
    // 是左节点的话, 上级找最低的父节点 也就是最大的父节点
    while ((y!=NULL) && (x==y->left))
    {
        x = y;
        y = y->parent;
    }

    return y;

}

// 后继右子树 最小
Node* bstree_next(Node *x) {
    // 当前节点有右子树, 查找右子树最小值
    if (x->right != NULL) return  bstree_min(x->right);
    

    Node* y = x->parent;
    // 当前节点是左节点, 后继节点是父
    // x是右节点的话, 上级找最低的父节点 也就是最大的父节点 
    while ((y!=NULL) && (x==y->right))
    {
        x = y;
        y = y->parent;
    }

    return y;

}

static Node* bstree_insert(BSTree tree, Node *z) {
    Node *x = tree;
    Node *y = NULL;

    while (x != NULL)
    {
        y = x;
        if (x->key > z->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    
    z->parent = y;
    if (y == NULL) {
        tree = z;
    } else if (z->key < y->key) {
        y->left = z;
    } else {
        y->right = z;
    }
    return tree;
}

int main(int argc, char const *argv[])
{
        char edges[][2] = {
        {'A', 'B'}, 
        {'B', 'C'}, 
        {'B', 'E'}, 
        {'B', 'F'}, 
        {'C', 'E'}, 
        {'D', 'C'}, 
        {'E', 'B'}, 
        {'E', 'D'}, 
        {'F', 'G'}};
        int s = sizeof(edges)/ sizeof(char);
        printf("%d",s);
    return 0;
}

typedef int Type;
// 生成
typedef struct _Huff {
    Type key;
    struct _HUff *left;
    struct _HUff *right;
    struct _HUff *parent;
} Huff, *HuffTree;

