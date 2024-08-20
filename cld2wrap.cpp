#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "public/compact_lang_det.h"
#include "internal/generated_language.h"

extern "C" {
  char *
  Lid2name(uint32_t id)
  {
    char *a = (char*)CLD2::LanguageName((CLD2::Language)id),
         *b = (char*)malloc(strlen(a));
    int i;

    for (i = 0; i < strlen(a)+1; ++i)
      b[i] = tolower(a[i]);

    return b;
  }

  uint32_t
  Ldetectl(char *s, uint32_t len)
  {
    _Bool _;
    return CLD2::DetectLanguage(s, len, 1, &_);
  }

  uint32_t
  Ldetect(char *s)
  {
    return Ldetectl(s, strlen(s));
  }

}
