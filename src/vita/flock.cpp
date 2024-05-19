#include <cstdio>

void flockfile(FILE* f) {  }
void funlockfile(FILE* f) { }
int getc_unlocked(FILE* f) { return fgetc(f); }