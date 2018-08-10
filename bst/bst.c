#include "bst.h"

//初始化二叉排序树
void init_bst(BST* bst){
  bst->root = NULL;
}

//插入树的节点
BOOL insert_bst_node(BSTNode** t, T x){
  if(*t == NULL){
    *t = (BSTNode*)malloc(sizeof(BSTNode));
    assert(NULL != *t);
    (*t)->data  = x;
    (*t)->left  = NULL;
    (*t)->right = NULL;
    return TRUE;
  }
  else if(x < (*t)->data){
    insert_bst_node(&((*t)->left), x);
  }
  else if(x > (*t)->data){
    insert_bst_node(&((*t)->right), x);
  }
  return FALSE;
}
BOOL insert_bst_tree(BST* bst, T x){
  return insert_bst_node(&(bst->root), x);
}

//求树中最小节点
T min_node(BSTNode* t){
  while(t->left != NULL)
    t = t->left;
  return t->data;
}
T min(BST* bst){
  assert(bst->root != NULL);
  return min_node(bst->root);
}
//求树中最大节点
T max_node(BSTNode* t){
  while(t->right != NULL){
    t = t->right;
  }
  return t->data;
}
T max(BST* bst){
  assert(bst->root != NULL);
  return max_node(bst->root);
}
//二叉树中序排序
void sort_node(BSTNode* t){
  if(NULL == t){
    return;
  }else{
    sort_node(t->left);
    printf("%d ", t->data);
    sort_node(t->right);
  }
}
void sort(BST* bst){
  assert(NULL != bst->root);
  sort_node(bst->root);
}
//搜索节点
BSTNode* search_node(BSTNode* t, T key){
  if(NULL == t || t->data == key){
    return t;
  }
  else{
    BSTNode* p;
    p = search_node(t->left, key);
    if(NULL == p){
      p = search_node(t->right, key);
    }
    return p;
  }
}
BSTNode* search_bst(BST* bst, T key){
  return search_node(bst->root, key);
}
BSTNode* search_node1(BSTNode* t, T key){
  if(NULL == t || t->data == key){
    return t;
  }
  else{
    if(key < t->data){
      search_node1(t->left, key);
    }
    else{
      search_node1(t->right, key);
    }
  }
}
BSTNode* search_bst1(BST* bst, T key){
  return search_node1(bst->root, key);
}
//清空树
void clear_node(BSTNode** t){
  if(NULL != *t){
    clear_node(&((*t)->left));
    clear_node(&((*t)->right));
    free(*t);
    *t = NULL;
  }
}
void clear_bst(BST* bst){
  clear_node(&bst->root);
}

//查找父节点
BSTNode* get_parent_node(BSTNode* t, BSTNode* tar){
  if(NULL == t || NULL == tar)return NULL;
  if(t->left == tar || t->right == tar){
    return t;
  }
  else{
    BSTNode* p = NULL;
    p = get_parent_node(t->left, tar);
    if(NULL == p){
      p = get_parent_node(t->right, tar);
    }
    return p;
  }
}
BSTNode* get_parent(BST* bst, BSTNode* tar){
  return get_parent_node(bst->root, tar);
}
BOOL remove_bst(BST* bst, T key){

  BSTNode* tar = search_bst(bst, key);
  //树为空或者要删除的节点不存在，返回失败
  if(bst->root == NULL || NULL == tar) return FALSE;

  BSTNode* parent = get_parent(bst, tar);
  //因为要被删除的顶点有左子节点，所以要找到以左子节点为根的右子节点中值最大的
  BSTNode* X = NULL;
  if(NULL != tar->left){
    X = tar->left;
    while(X->right != NULL){
      X = X->right;
    }
      
    //因为要被删除的顶点的左子节点,有右子节点，所以要找到最大的
    if(X != tar->left){
      //找到最大节点的父节点
      BSTNode* X1 = get_parent(bst, X);
      //最大节点的父节点的右边指向最大节点的左边
      X1->right = X->left;
	
      //最大节点的左边代替被删除节点的左边，右边代替右边
      X->left = tar->left;
      X->right = tar->right;
    }
    //因为要被删除的顶点的左子节点,没有右子节点，所以它就是最大的
    else{
      X->right = tar->right;
    }
  }
  //因为要被删除的顶点没有左子节点，所以要找到以右子节点为根的左子节点中值最小的
  else{
    X = tar->right;
    //要被删除的节点既没有左节点，也没有右节点
    if(NULL == X){
      //找到父节点
      BSTNode* X2 = get_parent(bst, X);
      //要被删除的节点不是根节点
      if(parent != NULL){
	//要被删除的顶点在父节点的左边
	if(tar->data < parent->data){
	  parent->left = X;
	}
	//要被删除的顶点在父节点的右边
	else{
	  parent->right = X;
	}
      }
      else{
	bst->root = NULL;
      }
      free(tar);
      return TRUE;
    }
    while(X->left != NULL){
      X = X->left;
    }
    //因为要被删除的顶点的右子节点,有左子节点，所以要找到最小的
    if(X != tar->right){
      //找到最小节点的父节点
      BSTNode* X1 = get_parent(bst, X);
      //最小节点的父节点的左边指向最小节点的右边
      X1->left = X->right;

      //最小节点的左边代替被删除节点的左边，右边代替右边
      X->right = tar->right;
      X->left = tar->left;
    }
  }
  //要被删除的节点不是根节点
  if(parent != NULL){
    //要被删除的顶点在父节点的左边
    if(tar->data < parent->data){
      parent->left = X;
    }
    //要被删除的顶点在父节点的右边
    else{
      parent->right = X;
    }
  }
  else{
    bst->root = X;
  }
  free(tar);
}
