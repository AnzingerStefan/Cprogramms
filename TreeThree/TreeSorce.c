/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include "TreeThree.h"
void add(TREENODE **current,int key, DATA data){
    if ( *current == NULL ) {
        *current = calloc(1, sizeof(TREENODE));
        (*current)->data = data;
        (*current)->key = key;
    }
    else if( key < (*current)->key){
        add(&(*current)->left,key, data);
    }
    else {
        add(&(*current)->right,key, data);
    }
}
DATA find(TREENODE *root,int key){
    if(root){
        if(root->key == key)
            return root->data;
        if ( key < root->key)
            find((root)->left,key);
        else
            find((root)->right,key);
    }
    return NULL;
}
void generate_tree (TREENODE **node,int array[],int start,int end){
    if(start <= end){
        int mid = (start+end)/2;
        *node = calloc(1,sizeof(TREENODE));
        (*node)->key = array[mid];
        generate_tree(&(*node)->left,array,start,mid-1);
        generate_tree(&(*node)->right,array,mid+1,end);
    }
    
}
void find_depth(TREENODE *root,TREENODE **enode ,int key){
    TREENODE *node = root;
    int depth = 1;
    while (node->left != NULL && node->right != NULL){
        if(node->left->key < key){
            node = node->left;
            depth++;
        }
        else if(node->left->key == key){
            node->depth = depth;
        }
        else if(node->left->key > key){
            node = node->right;
            depth++;
        }
        
    }  
}
void print_tree(TREENODE *root)
{
    if(root){
        print_tree(root->left);
        int space = root->depth * 3;
        for(int i = 0;i < space ;i++){
            printf("   ");
        }
        printf("%d\n ", root->key);
        print_tree(root);
        
    }
}
void free_tree(TREENODE *root){

       if (root != NULL) {
        free_tree(root->right);
        free(root->data);
        free(root->depth); 
        free_tree(root->left);
        free(root);
     }
}
