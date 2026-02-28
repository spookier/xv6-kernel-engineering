#include "kernel/types.h"
#include "kernel/fcntl.h"
#include "user/user.h"
#include "kernel/riscv.h"

static int is_alnum(char c) {
    if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
      return 1;
    else
      return 0;
}

int main(int argc, char *argv[])
{
  int N = 4096 * 8;
  int ok;

  char *p = sbrk(N);

  char marker[] = "This may help.";
  int len = sizeof(marker) - 1;   // excludes '\0'

  for (int i = 0; i <= N - len; ++i)
  {
    ok = 1;
    for (int j = 0; j < len; ++j)
    {
      if (p[i + j] != marker[j])
      {
        ok = 0;
        break ; 
      }
    }

    if (ok == 1)
    {
      int k = i + len;

      // skip space/newline/0/etc...
      while (k < N && !is_alnum(p[k]))
        k++;

      // print the secret token
      int printed = 0;
      while (k < N && is_alnum(p[k]))
      {
        write(1, &p[k], 1);
        k++;
        printed = 1;
      }

      if (printed)
        write(1, "\n", 1);

      exit(0);
    }
  }

  exit(1);
}
