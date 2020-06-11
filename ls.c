// Simple implementation of the ls UNIX command
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[argc+1])
{
    // parse the arguments
    char* cmd_name = argv[0];
    char* dirpath;
    if (argc > 1) {
        dirpath = argv[1];
    } else {
        dirpath = ".";
        argc++;
    }
    
    DIR* dir = opendir(dirpath);    // opens a directory stream
    if (dir == NULL) {
        fprintf(stderr, "%s: cannot access '%s'\n", cmd_name, dirpath);
        return EXIT_FAILURE;
    } else {
        struct dirent* ent;
        while ((ent = readdir(dir))) {      // keeps reading directory entries until it returns NULL
            printf("%s\n", (*ent).d_name);
        }
    }

    closedir(dir);  // close the directory stream
    return EXIT_SUCCESS;
}