#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

#define PAGES 8

int
main() {
  char *buffer = malloc(PAGES * 4096);
  if (buffer == 0) {
    printf("malloc failed\n");
    exit(1);
  }
  //page size is 4096
  buffer[0] = 1;
  buffer[2 * 4096] = 1;
  buffer[3 * 4096] = 1;

  uint64 accessed = 0;

  if (pgaccess(buffer, PAGES, &accessed) < 0) {
    printf("pgaccess syscall failed\n");
    exit(1);
  }

  printf("Accessed mask: %lx\n", accessed);
  for (int i = 0; i < PAGES; i++) {
    if (accessed & (1 << i)) {
      printf("Page %d was accessed\n", i);
    }
  }

  free(buffer);
  exit(0);
}
