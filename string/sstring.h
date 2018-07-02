#ifndef __SSTRING_H__
#define __SSTRING_H__

#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<malloc.h>

#define MAX_SIZE 20
#define u_char unsigned char

typedef u_char SString[MAX_SIZE + 1];

void init(SString);
void assign(SString, char*);
void copy(SString, SString);
bool isEmpty(SString);
int compare(SString, SString);
int getLength(SString);
void concat(SString*, SString);
void substring(SString, SString, int, int);
void replace(SString target, SString be, SString af);
void insert(SString des, int pos, SString t);
void delete(SString des, int pos, int len);
void clear(SString des);

#endif
