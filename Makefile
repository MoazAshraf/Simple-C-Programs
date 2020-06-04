CC = gcc
FLAGS = -Wall

merge_sort : merge_sort.c
	$(CC) $(FLAGS) -o merge_sort merge_sort.c