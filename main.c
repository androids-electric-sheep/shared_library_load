#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  void *handle;
  void (*print)(void);
  char *error;

  handle = dlopen("./libprinter.so", RTLD_LAZY);
  if (!handle) {
    fputs(dlerror(), stderr);
    exit(1);
  }

  print = dlsym(handle, "print");
  if ((error = dlerror()) != NULL) {
    fputs(error, stderr);
    exit(1);
  }

  (*print)();
  dlclose(handle);
}
