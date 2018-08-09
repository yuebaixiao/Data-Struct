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
//删除节点
BOOL remove_node(BSTNode** t, T key){

}
BOOL remove_bst(BST* bst, T key){

  BSTNode* tar = search_bst(bst, key);
  //树为空或者要删除的节点不存在，返回失败
  if(bst->root == NULL || NULL == tar) return FALSE;

  //目标节点root节点
  if(bst->root == tar){
    //root节点没有右子节点
    if(tar->right == NULL){
      //root节点没有左子节点
      if(tar->left == NULL){
	free(bst->root);
	bst->root = NULL;
      }
      //root节点有做左节点
      else{
	BSTNode* p = tar->left;
	//因为root节点的左子节点没有右子节点，所以root节点的左子节点就是新的root
	if(NULL == p->right){
	  BSTNode* tmp = bst->root;
	  bst->root = bst->root->left;
	  free(tmp);
	  return TRUE;
	}
	//root节点的左子节点有右子节点
	else{
	  //因为root没有右子节点，所以要在root的左子节点中找到最大值，作为新的root
	  //以root节点的左子节点为根节点的最右的右节点，就是值最大的节点。
	  while(p->right != NULL){
	    p = p->right;
	  }
	  BSTNode* tmp = bst->root;
	  BSTNode* parent = get_parent(bst, p);
	  bst->root = p;
	  parent->right = p->left;
	  p->left = tmp->left;
	  free(tmp);
	  return TRUE;
	}
      }
    }
    //root节点有右子节点
    else{
      BSTNode* p = tar->right;
      //因为root节点的右子节点没有左子节点，所以root节点的右子节点就是新的root
      if(NULL == p->left){
	BSTNode* tmp = bst->root;
	bst->root = bst->root->right;
	bst->root->left = tmp->left;
	free(tmp);
	return TRUE;
      }
      //root节点的右子节点有左子节点
      else{
	  //因为root右子节点中有左子节点，所以要在root的右子节点中找到最小值，作为新的root
	  //以root节点的右子节点为根节点的最左的左节点，就是值最小的节点。
	  while(p->left != NULL){
	    p = p->left;
	  }
	  BSTNode* tmp = bst->root;
	  BSTNode* parent = get_parent(bst, p);
	  bst->root = p;
	  parent->left = p->right;
	  p->right = tmp->right;
	  free(tmp);
	  return TRUE;
      }
      
    }
  }
  
  //目标节点(非root)没有左子节点
  if(NULL == tar->left){
    
  }
  //目标节点(非root)有左子节点
  else{

  }
}
