CC = gcc
FLAGS = -Wall

all : merge_sort quick_sort

merge_sort : merge_sort.c
	$(CC) $(FLAGS) -o merge_sort merge_sort.c

quick_sort : quick_sort.c
	$(CC) $(FLAGS) -o quick_sort quick_sort.c