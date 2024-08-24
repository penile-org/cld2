#include <stdio.h>
#include <stdint.h>
#include <string.h>

uint32_t Ldetect(char *s);
uint32_t Ldetectl(char *s, uint32_t len);
char *Lid2name(uint32_t id);
char *Lid2code(uint32_t id);

int
main(void)
{
  char *pl = "krakersik z czarnuszką";
  char *en = "i hate swine";

  printf("pl?: %s\n", Lid2code(Ldetect(pl)));
  printf("en?: %s\n", Lid2code(Ldetect(en)));

  return 0;
}
