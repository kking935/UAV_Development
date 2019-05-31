#include <stdio.h>
#include <inttypes.h>


int main(void) {

    short x[2];
    uint64_t i = 0;

    while(1 == fread(x, 2*sizeof(short), 1, stdin)) {
        printf("%" PRIu64 " %hd %hd\n", i++, x[0], x[1]);
        //if(i > 10000)
        //    break;
    }

    return 0;
}
