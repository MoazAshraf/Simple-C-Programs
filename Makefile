CC = gcc
FLAGS = -Wall

ALL_TARGETS = 
ALL_TARGETS += merge_sort
ALL_TARGETS += quick_sort
ALL_TARGETS += union_find

all : ALL_TARGETS

merge_sort : merge_sort.c
	$(CC) $(FLAGS) -o merge_sort merge_sort.c

quick_sort : quick_sort.c
	$(CC) $(FLAGS) -o quick_sort quick_sort.c

union_find : union_find.c
	$(CC) $(FLAGS) -o union_find union_find.c

ls : ls.c
	$(CC) $(FLAGS) -o ls ls.c