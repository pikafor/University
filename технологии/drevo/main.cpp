#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>

int N = 20;

typedef struct Node {
	int key;
	struct Node *left, *right;
}NODE, *pNODE;


pNODE addNode(int x, pNODE root) {
	if (!root) {
		root = (pNODE)malloc(sizeof(NODE));
		root->key = x;
		root->left = NULL;
		root->right = NULL;
		return(root);
	}
	if (x < root->key)
		root->left = addNode(x, root->left);
	else   root->right = addNode(x, root->right);
}


void inorder(pNODE root) {
	if (root) {
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}

void preorder(pNODE root){
    if (root){
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(pNODE root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}

Node* find_tree(Node* root, int x){
    if(!root) return NULL;
    if(x==root->key) return root;
    if(x<root->key) return find_tree(root->left, x);
    else find_tree(root->right, x);
}

int rightmost(pNODE root){
    while (root->right != NULL) root=root->right;
    return root->key;
    printf("%d", root->key);
}

Node* del_tree(pNODE root, int x){
    pNODE temp;
    if(!root) return NULL;
    if(root->key==x){
        if(!root->left && !root->right){
            free(root);
            return NULL;
        }
        if(!root->right && root->left){
            temp = root->left;
            free(root);
            return temp;
        }
        if(root->right && !root->left){
            temp=root->right;
            free(root);
            return temp;
        }
        root->key=rightmost(root->left);
        root->left = del_tree(root->left, root->key);
        return root;
    }
    if(x<root->key){
        root->left=del_tree(root->left, x);
        return root;
    }
    if(x>root->key){
        root->right=del_tree(root->right, x);
        return root;
    }
    return root;
}

void del_all(Node* root){
    if(!root) return;
    del_all(root->left);
    del_all(root->right);
    free(root);
    root=NULL;
}

void Nnodes(Node* root, int& p)
{
    if (root == NULL) return;
    p++;
    Nnodes(root->left, p);
    Nnodes(root->right, p);
}
void Height(pNODE root, int p, int* h)
{
    if (root == NULL) return;
    p++;
    if (root->left == NULL && root->right == NULL)
        if (p > *h)
            *h = p;
    Height(root->left, p, h);
    Height(root->right, p, h);
}


int main(int argc, char* argv[])
 {
	pNODE p, root = NULL;
	int i, k, *h=&k;
	srand(time(NULL));
	for (i = 0; i < N; i++) root = addNode(rand() % 101, root);
	i=0;
	Nnodes(root, i);
	printf("\n in tree %d nodes \n", i);
	*h=0;
	Height(root, 0, h);
    printf("\n Height tree =%d nodes \n", *h);
	puts("INORDER");
	inorder(root);
	printf("\n");
    puts("PREORDER");
    preorder(root);
   	printf("\n");
   	puts("POSTORDER");
   	postorder(root);
   	printf("\n");
    rightmost(root);
    printf("Samoe pravoe %p", rightmost(root));

    for(i=0; i<80;i++){
        k=rand()%101;
        p=find_tree(root, k);
        if(p){
            printf("\n Value %d find = %d\n", k, p->key);
            root=del_tree(root, k);
            preorder(root);
        }
        else printf("\n Value %d not find\n", k);
    }

    del_all(root);
	return 0;
}
