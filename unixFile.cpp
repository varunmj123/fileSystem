#include <stdio.h>
#include <stdlib.h>

#define MAXADDNUM 20

int main(int argc, char *argv[]) {
    unsigned int n, m, v[MAXADDNUM];
    int count = 0;
    unsigned char offset[4], page[4], virAdd[MAXADDNUM][16];
    FILE *file = fopen("part1input.txt", "r");

    printf("PROGRAM STARTING\n");

    if(file == NULL) {
        printf("File Error. Exiting!");
        exit(1);
    }

    if(fgets(offset, sizeof(offset), file) != NULL)
        n = strtoul(offset, NULL, 10);
    if(fgets(page, sizeof(page), file) != NULL)
        m = strtoul(page, NULL, 10);

    while(fgets(virAdd[count], (sizeof(virAdd[count]) + 2), file) != NULL) {
        v[count] = strtoul(virAdd[count], NULL, 2);
        count++;
    }

    for(int i = 0; i < count; i++) {
        unsigned int p = v[i] >> n;
        unsigned int d = v[i] & ~(~0U << n);

        // another way of getting the offset
        // unsigned int d = v[i] << (m + 16) >> (m + 16);

        printf("The virtual address v%d is in page number %d and offset %d\n", (i+1), p, d);
    }
    fclose(file);
    printf("GOODBYE");
    exit(0);
}