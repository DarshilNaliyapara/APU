#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int errno;

int main(int argc, char *argv[]) {

  const char *dir_path = (argc > 1) ? argv[1] : ".";
  DIR *dir;
  struct dirent *entry;

  if ((dir = opendir(dir_path)) == NULL) {
    printf("\n Error code %d", errno);
    printf("can't open %s. Error Msg: %s", argv[1], strerror(errno));
    exit(EXIT_FAILURE);
  }
  while ((entry = readdir(dir)) != NULL) {
    printf("%s\n", entry->d_name);
  }
  closedir(dir);
  exit(EXIT_SUCCESS);
}


