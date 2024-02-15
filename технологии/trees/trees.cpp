#include <stdio.h>
#include <conio.h>
#include <ctime>
#include <stdlib.h>
int main()
{
    pNODE p, root = NULL;
    int i, k, *h = &k;
    srand(time(NULL));
    root = addnode(rand() % 101, root);
    for (i=0; i<10; i++)
        root = addnode(rand() % 101, root);
    i = 0;
    Nnodes(root, &i);
    printf("\n in tree %d nodes \n", i);
    *h = 0;
    Height(root, 0, h);
    printf("\n Height tree =%d nodes \n", h);
    printf("preorder : ");
    preorder(root);
    printf("\n postorder : ");
    postorder(root);
    printf("\n inorder : ");
    inorder(root);
    printf("\n");
    for (i = 0; i < 80; i++)
    {
        k = rand ()% 101;
        p = find_tree(root, k);
    }
    if (p) {
        printf("\n value %d find =%d\n", k, p->key);
    }
    root = del_tree(root, k);
    preorder(root);
}

typedef struct node {
    int key;
    float data;
    struct node* left, * right;
}NODE, * pNODE;

pNODE addnode(int x, pNODE root) {
    if (!root) { // Если дерева (или листа) нет, то формируем корень (лист)
        root = (pNODE)malloc(sizeof(NODE)); // память под узел
        root->key = x;   // поле данных
        root->left = NULL;
        root->right = NULL; // ветви инициализируем пустотой
        return(root);
    }
    if (x < root->key)   // условие добавление левого потомка
        root->left = addnode(x, root->left);
    else   root->right = addnode(x, root->right); // усл-е добав.прав. листа
}
void preorder(node* root)
{
    if (root != NULL) { //Пока не встретится пустой узел
        printf("%d", root->key); //Отображаем корень дерева
        preorder(root->left); //Рекурсивная функция для левого поддерева
        preorder(root->right); //Рекурсивная функция для правого поддерева
    }
}
void postorder(node* root)
{
    if (root != NULL) { //Пока не встретится пустой узел
        postorder(root->left); //Рекурсивная функция для левого поддерева
        postorder(root->right); //Рекурсивная функция для правого поддерева
        printf("%d", root->key); //Отображаем корень дерева
    }
}
void inorder(node* root)
{
    if (root != NULL) { //Пока не встретится пустой узел
        inorder(root->left); //Рекурсивная функция для левого поддерева
        printf("%d", root->key); //Отображаем корень дерева
        inorder(root->right); //Рекурсивная функция для правого поддерева
    }
}
node* find_tree(node* root, int val)
{
    if (!root)
        return NULL;
    if (val == root->key)
        return root;
    if (val < root->key)
        return find_tree(root->left, val);
    else
        return find_tree(root->right, val);
}
int rightmost(pNODE root) {
    while (root->right != NULL)
        root = root->right;
    return root->key;
}
node* del_tree(pNODE root, int val)
{
    pNODE temp;
    if (!root) return NULL;
    if (root->key == val) {
        if (!root->left && !root->right) {
            free(root);
            return NULL;
        }
        if (!root->right && root->left) {
            temp = root->left;
            free(root);
            return temp;
        }
        if (!root->left && root->right) {
            temp = root->right;
            free(root);
            return temp;
        }
        root->key = rightmost(root->left);
        root->left = del_tree(root->left, root->key);
        return root;
        }
    if (val < root->key) {
        root->left = del_tree(root->left, val);
        return root;
    }
    if (val > root->key) {
        root->right = del_tree(root->right, val);
        return root;
    }
    return root;
}
void del_all(node* root)
{
    if (!root) return;
    del_all(root->left);
    del_all(root->right);
    free(root);
    root = NULL;
}
void Nnodes(node* root, int& p)
{
    if (root == NULL) return;
    p++;
    Nnodes(root->left, p);
    Nnodes(root->right, p);
}
void Height(node* root, int p, int& h)
{
    if (root == NULL) return;
    p++;
    if (root->left == NULL && root->right == NULL) // Проверка на достижение терминального узла
        if (p > h)
            h = p;
    Height(root->left, p, h);
    Height(root->right, p, h);
}