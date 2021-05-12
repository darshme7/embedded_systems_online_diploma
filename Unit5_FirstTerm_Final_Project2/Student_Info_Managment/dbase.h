/*
 * dbase.h
 *
 *  Created on: May 11, 2021
 *      Author: mostafa
 */

#ifndef DBASE_H_
#define DBASE_H_

#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include "queue.h"

#define DPRINTF(...) printf(__VA_ARGS__);fflush(stdin); fflush(stdout)
#define SIZE 50

struct sinfo{
	char fname[50];
	char lname[50];
	int roll;
	float gpa;
	int cid[5];
}st[SIZE];



void add_student_file();
void add_student_manually();
void find_rl();
void find_fn();
void find_c();
void tot_s();
void del_s();
void up_s();
void show_s();

#endif /* DBASE_H_ */
