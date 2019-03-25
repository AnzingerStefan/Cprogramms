/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>

#include "HashHead.h"

int get_hash(DATA d) {
    return toupper(d.name(0));
}

HASHENTRY* find_hash(HASHTABLE *map, DATA d) {
    for (int i = 0; i < map->count; i++) {
        if (map->arr[i]->hashcode == d) {
            return &map->arr[i];
        }
    }
}

void add_list(NODE **start, DATA d) {
    NODE *new = calloc(1, sizeof (NODE));
    new->data = d;
    if (*start == NULL) {
        start = new;
    } 
    else {
        
        NODE helper = *start;
        while (helper->next != NULL) {
            helper = helper->next;
        }
        helper->next = new;
    }
}

void add(HASHTABLE* map, DATA d) {
    HASHENTRY new;
    NODE *insert = calloc(1, sizeof (NODE));
    insert->data = d;
    new.list = insert;
    new->hashcode = get_hash(d);
}

DATA find(HASHTABLE*map, DATA d) {

}