/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TreeThree.h
 * Author: if170004
 *
 * Created on March 18, 2019, 8:57 AM
 */


#ifndef TREETHREE_H
#define TREETHREE_H

typedef int DATA;
int depth;
typedef struct _TREENODE{
    struct _TREENODE *left, *right;
    int key;
    DATA data;
    int depth;
}TREENODE;

typedef struct _NODE{
    int data;
    struct _NODE *next;
}NODE;
typedef struct{
    NODE *start;
}STACK;
typedef struct{
    NODE *node;
    int indent;
}NODEINFO;

DATA pop(STACK *st);
void push(STACK *st, DATA d);
DATA peek (STACK *st);
int count(STACK *st);
TREENODE *tree = NULL;

void add(TREENODE **current,int key, DATA data);
DATA find(TREENODE *root,int key);
void generate_tree (TREENODE **node,int array[],int start,int end);
void find_depth(TREENODE *root,TREENODE **enode ,int key);
void print_tree(TREENODE *root);
#endif