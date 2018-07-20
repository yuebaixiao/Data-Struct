#include "bintree.h"
#include "nodequeue.h"
#include "nodestack.h"

void init(BinTree* tr, ElemType val){
  tr->root = NULL;
  tr->ref = val;
}

void createRoot(BinTree* bt, BinTreeNode** t){
  ElemType item;
  scanf("%c", &item);
  if(item == bt->ref){
    *t = NULL;
  }
  else{
    *t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
    assert(*t != NULL);
    (*t)->data = item;
    createRoot(bt, &((*t)->leftChild));
    createRoot(bt, &((*t)->rightChild));
  }
}

void createBinTree(BinTree* bt){
  createRoot(bt, &(bt->root));
}

void createNode_str(BinTree* bt, BinTreeNode** t, char** str){

  if(**str == '\0'){
    return;
  }

  if(**str == bt->ref){
    *t = NULL;
    *str = *str + 1;
  }
  else{
    *t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
    (*t)->data = **str;
    *str = *str + 1;
    createNode_str(bt, &((*t)->leftChild),  str);
    createNode_str(bt, &((*t)->rightChild), str);
  }
}

void createBinTree_str(BinTree* bt, char** str){
  createNode_str(bt, &(bt->root), str);
}
//先中心，再左树，再右树
void show_node_clr(BinTreeNode* n){
  if(NULL == n)return;
  else{
    printf("%c ", n->data);
    show_node_clr(n->leftChild);
    show_node_clr(n->rightChild);
  }
}
//先中心，再左树，再右树
void show_clr(BinTree* tr){
  show_node_clr(tr->root);
}

//先左树，再中心，再右树
void show_node_lcr(BinTreeNode* n){
  if(NULL == n)return;
  else{
    show_node_lcr(n->leftChild);
    printf("%c ", n->data);    
    show_node_lcr(n->rightChild);
  }
}
//先左树，再中心，再右树
void show_lcr(BinTree* tr){
  show_node_lcr(tr->root);
}

//先左树，再右树，再中心
void show_node_lrc(BinTreeNode* n){
  if(NULL == n)return;
  else{
    show_node_lrc(n->leftChild);
    show_node_lrc(n->rightChild);
    printf("%c ", n->data);
  }
}
//先左树，再右树，再中心
void show_lrc(BinTree* tr){
  show_node_lrc(tr->root);
}

//层级遍历
void show_node_level(BinTreeNode* n){
  if(NULL == n) return;
  NodeQueue queue;
  init_queue(&queue);
  enQueue(&queue, n);

  BinTreeNode* tmp;
  while(!isQueueEmpty(&queue)){
    if(getHead(&queue) == NULL)break;
    tmp = getHead(&queue)->data;
    deQueue(&queue);
    printf("%c ", tmp->data);
    if(tmp->leftChild != NULL)
      enQueue(&queue, tmp->leftChild);
    if(tmp->rightChild != NULL)
      enQueue(&queue, tmp->rightChild);
  }
  printf("\n");
}

//层级遍历
void show_level(BinTree* tr){
  show_node_level(tr->root);
}

//--------------------分界线--------------------


//取得树中节点个数
void get_node_size1(BinTreeNode* n, int* p){
  if (NULL == n)return;
  else{
    *p = *p + 1;
    get_node_size1(n->leftChild, p);
    get_node_size1(n->rightChild, p);
  }
}
//取得树中节点个数
int get_size1(BinTree* tr){
  int size = 0;
  get_node_size1(tr->root, &size);
  return size;
}
int get_node_size2(BinTreeNode* p){
  if(NULL == p) return 0;
  else{
    return get_node_size2(p->leftChild) + get_node_size2(p->rightChild) + 1;
  }
}
int get_size2(BinTree* tr){
  return get_node_size2(tr->root);
}
void get_node_height(BinTreeNode* n, int* p){
  if(NULL == n) return;
  *p = *p + 1;

  int t1 = 0, t2 = 0;

  get_node_height(n->leftChild, &t1);
  get_node_height(n->rightChild,&t2);
  if(t1 > t2)
    *p = *p + t1;
  else
    *p = *p + t2;
}
int get_height(BinTree* tr){
  int size = 0;
  if(tr->root != NULL) size++;
  int t1 = 0, t2 = 0;
  get_node_height(tr->root->leftChild, &t1);
  get_node_height(tr->root->rightChild, &t2);
  return t1 > t2 ? t1 + size : t2 + size;
}
BinTreeNode* search_node(BinTreeNode* n, ElemType key){
  if (NULL == n || n->data == key){
    return n;
  }else{
    BinTreeNode* tmp;
    tmp = search_node(n->leftChild, key);
    if(NULL == tmp){
      tmp = search_node(n->rightChild, key);
    }
    return tmp;
  }
}
BinTreeNode* search(BinTree* tr, ElemType key){
  BinTreeNode* n = NULL;
  n = search_node(tr->root, key);
  return n;
}
BinTreeNode* get_node_parent(BinTreeNode* n, BinTreeNode* target){
  if(NULL == n || NULL == target) return NULL;
  if(n->leftChild == target || n->rightChild == target){
    return n;
  }
  else{
    BinTreeNode* tmp = NULL;
    tmp = get_node_parent(n->leftChild, target);
    if(NULL == tmp){
      tmp = get_node_parent(n->rightChild, target);
    }
    return tmp;
  }
}
BinTreeNode* get_parent(BinTree* tr, BinTreeNode* target){
  get_node_parent(tr->root, target);
}
bool isBintreeEmpty(BinTree* tr){
  return NULL == tr->root;
}
void copy_node(BinTreeNode** n1, BinTreeNode* n2){
  if(NULL == n2){
    *n1 = NULL;
    return;
  }else{
    BinTreeNode* p = (BinTreeNode*)malloc(sizeof(BinTreeNode*));
    p->data = n2->data;
    *n1 = p;
    copy_node(&((*n1)->leftChild), n2->leftChild);
    copy_node(&((*n1)->rightChild), n2->rightChild);
  }

}
void copy(BinTree* tr1, BinTree* tr2){
  copy_node(&(tr1->root), tr2->root);
}
void bintree_node_clear(BinTreeNode** n){
  if(NULL == *n)return;
  bintree_node_clear(&((*n)->leftChild));
  bintree_node_clear(&((*n)->rightChild));
  free(*n);
  *n = NULL;
}
void bintree_clear(BinTree* tr){
  bintree_node_clear(&(tr->root));
  //  init(tr, '#');  
}

//非递归 先中心，再左树，再右树
void display_node_clr(BinTreeNode* n){
  if(NULL == n){
    printf("是空树\n");
    return;
  }
  nodestack stack;
  init(&stack);
  push(&stack, n);
  Node* tmp = NULL;
  while(0 != stack.size){
    tmp = pop(&stack);
    if(NULL == tmp) continue;

    printf("%c ", tmp->data->data);

    if(tmp->data->rightChild != NULL)
      push(&stack, tmp->data->rightChild);
    if(tmp->data->leftChild != NULL)
      push(&stack, tmp->data->leftChild);
  }
}
//非递归 先中心，再左树，再右树
void display_clr(BinTree* tr){
  display_node_clr(tr->root);
}
//非递归 先左树，再中心，再右树
void display_node_lcr(BinTreeNode* n){
  if(NULL == n){
    printf("是空树\n");
    return;
  }
  nodestack stack;
  init(&stack);
  push(&stack, n);
  Node* tmp = NULL;
  while(0 != stack.size){
    tmp = pop(&stack);
    if(NULL != tmp->data->leftChild){
      if(NULL != tmp->data->rightChild){
	push(&stack, tmp->data->rightChild);
      }
      //中心节点
      push(&stack, tmp->data);
      push(&stack, tmp->data->leftChild);
    }
    else{
      if(NULL == tmp->data->rightChild){
	printf("%c ", tmp->data->data);
	tmp = pop(&stack);
	if(NULL == tmp)continue;
	printf("%c ", tmp->data->data);
      }
      else{
	printf("%c ", tmp->data->data);
	push(&stack, tmp->data->rightChild);
      }
    }
  }
}
//非递归 先左树，再中心，再右树
void display_lcr(BinTree* tr){
  display_node_lcr(tr->root);
}
//非递归 先左树，再右树，再中心(虽然实现了遍历，但是破坏了树的结构)
void display_node_lrc(BinTreeNode* n){

  if(NULL == n){
    printf("是空树\n");
    return;
  }
  nodestack stack;
  init(&stack);
  push(&stack, n);
  Node* tmp = NULL;
  while(0 != stack.size){
    tmp = pop(&stack);

    if(NULL != tmp->data->leftChild){
      //中心节点
      push(&stack, tmp->data);
      if(NULL != tmp->data->rightChild){
	push(&stack, tmp->data->rightChild);
      }
      push(&stack, tmp->data->leftChild);

      //把中心节点的左右节点的指针设置成NULL
      tmp->data->rightChild = tmp->data->leftChild = NULL;
    }
    else{
      if(NULL == tmp->data->rightChild){
	printf("%c ", tmp->data->data);
      }
      else{
	//中心节点
	push(&stack, tmp->data);
	push(&stack, tmp->data->rightChild);
	//把中心节点的左右节点的指针设置成NULL
	tmp->data->rightChild = tmp->data->leftChild = NULL;
      }
    }
  }
}
//非递归 先左树，再右树，再中心(虽然实现了遍历，但是破坏了树的结构)
void display_lrc(BinTree* tr){
  display_node_lrc(tr->root);
}
