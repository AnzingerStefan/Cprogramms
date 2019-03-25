/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HashHead.h
 * Author: if170004
 *
 * Created on February 25, 2019, 9:16 AM
 */

#ifndef HASHHEAD_H
#define HASHHEAD_H

#define STR_LEN 50
#define TABLE_LEN 26

typedef struct {
    char personalnr [12];
    char name[STR_LEN];
    char firstname[STR_LEN];
} DATA;

typedef struct _NODE {
    DATA data;
    struct _NODE *next;
} NODE;

typedef struct {
    int hashcode;
    NODE *list;
} HASHENTRY;

typedef struct {
    HASHENTRY arr[TABLE_LEN];
    int count;
} HASHTABLE;

int get_hash(DATA d);
HASHENTRY* find_hash(HASHTABLE *map, DATA d);
void add_list(NODE **start,DATA d);
void add(HASHTABLE* map,DATA d);
DATA find(HASHTABLE*map, DATA d);
#endif /* HASHHEAD_H */

