#include <dirent.h>
#include <stdio.h>
#include <pwd.h>

int main(int argc, char * argv[]) {
    DIR * dir;
    struct dirent * entry;
    char * directory = ".";

    if (argc > 1) {
        directory = argv[1];
    }

    dir = opendir(directory);
    
    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.' && argc < 2) {
            continue;
        }

        char path_to_file[256];
        printf("%s/%s\n", directory, entry->d_name);
    }

    closedir(dir);
    return 0;
}