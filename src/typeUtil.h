#ifndef TYPE_UTIL_H
#define TYPE_UTIL_H

#include "translator.h"

struct chord * atochord(const char *nptr);

struct chord * atonote(const char *nptr);          

void print_chord(struct chord * chord);

#endif