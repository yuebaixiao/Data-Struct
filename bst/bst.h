#ifndef __BST__
#define __BST__

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#define T int
#define FALSE 0
#define TRUE 1
#define BOOL int

typedef struct BSTNode{
  T data;
  struct BSTNode* left;
  struct BSTNode* right;
}BSTNode;

typedef struct BST{
  BSTNode* root;
}BST;

//初始化二叉排序树
void init_bst(BST* bst);
//插入树的节点
BOOL insert_bst_node(BSTNode** t, T x);
BOOL insert_bst_tree(BST* bst, T x);
//求树中最小节点
T min(BST* bst);
//求树中最大节点
T max(BST* bst);
//排序
void sort(BST* bst);
//查找父节点
BSTNode* get_parent(BST* bst, BSTNode* tar);
//删除节点
BOOL remove_bst(BST* bst, T key);
//搜索节点
BSTNode* search_bst(BST* bst, T key);
//搜索节点
BSTNode* search_bst1(BST* bst, T key);
//清空树
void clear_bst(BST* bst);

#endif
