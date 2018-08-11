#include "avl_tree.h"

void init_avl_tree(AVLTree* avl){
  avl->root = NULL;
}
AVLNode* malNode(Type x){
    AVLNode* t = (AVLNode*)malloc(sizeof(AVLNode));
    assert(NULL != t);
    t->data  = x;
    t->left  = NULL;
    t->right = NULL;
    t->bf    = 0;
    return t;
}
//右旋转
void rotateR(AVLNode** t){
  AVLNode* subR = *t;
  *t = (*t)->left;
  subR->left = (*t)->right;
  (*t)->right = subR;
  (*t)->bf = 0;
  subR->bf = 0;//???tODO

}
//插入树的节点
BOOL insert_avl_node(AVLNode** t, Type x){
  AVLNode* p = *t;
  AVLNode* parent = NULL;

  nodestack st;
  init(&st);
  
  while(p != NULL){
    if(x == p->data)
      return FALSE;
    parent = p;
    push(&st, parent);
    if(x < p->data)
      p = p->left;
    else
      p = p->right;
  }
  p = malNode(x);
  //插入节点为root节点
  if(parent == NULL){
    *t = p;
    return TRUE;
  }
  //插入节点不是root节点
  if(x < parent->data)
    parent->left = p;
  else
    parent->right = p;

  //调整BF
  while(length(&st) != 0){
    parent = getTop(&st);
    pop(&st);
    if(parent->left == p){
      parent->bf--;
    }
    else{
      parent->bf++;
    }
    
    if(parent->bf == 0){
      break;
    }
    if(parent->bf == 1 || parent->bf == -1){
      p = parent;
    }
    else{
      //旋转树，让树变成平衡树
      int flag = (parent->bf < 0) ? -1 : 1;
      //符号相同，说明是一条直线，不是折线，所以单旋转
      if(p->bf == flag){
	//因为是撇/，所以右旋转
	if(flag == -1){
	  rotateR(&parent);
	}
	//因为是捺\，所以左旋转
	else{
	  //rotateL(parent);
	}
      }
      //符号不同，说明是折线，所以双旋转
      else{
	//折线的角指向右>
	if(flag == 1){
	  //rotateRL(parent);
	}
	//折线的角指向左<
	else{
	  //rotateLR(parent);
	}
      }
    }
  }
  
  
  if(length(&st) == 0){
    *t = parent;
  }
  else{
    AVLNode* q = getTop(&st);
    if(q->data > parent->data){
      q->left = parent;
    }
    else{
      q->right = parent;
    }
  }
  

  clear(&st);
  return TRUE;
}
//插入节点
BOOL insert_avl(AVLTree* avl, Type t){
  return insert_avl_node(&avl->root, t);
}
