#include <stdio.h>

#define MAXWEIGHT 100

int n = 3; /* The number of objects */
int c[10] = {8, 6, 4}; /* c[i] is the *COST* of the ith object; i.e. what
                YOU PAY to take the object */
int v[10] = {16, 10, 7}; /* v[i] is the *VALUE* of the ith object; i.e.
                what YOU GET for taking the object */
int W = 10; /* The maximum weight you can take */

void fill_sack() {
    int a[MAXWEIGHT]; /* a[i] holds the maximum value that can be obtained
                using at most i weight */
    int last_added[MAXWEIGHT]; /* I use this to calculate which object were
                    added */
    int i, j;
    int aux;

    for (i = 0; i <= W; ++i) {
        a&#91;i&#93; = 0;
        last_added&#91;i&#93; = -1;
    }

    a&#91;0&#93; = 0;
    for (i = 1; i <= W; ++i)
        for (j = 0; j < n; ++j)
            if ((c&#91;j&#93; <= i) && (a&#91;i&#93; < a&#91;i - c&#91;j&#93;&#93; + v&#91;j&#93;)) {
                a&#91;i&#93; = a&#91;i - c&#91;j&#93;&#93; + v&#91;j&#93;;
                last_added&#91;i&#93; = j;
            }

    for (i = 0; i <= W; ++i)
        if (last_added&#91;i&#93; != -1)
            printf("Weight %d; Benefit: %d; To reach this weight I added object %d (%d$ %dKg) to weight %d.\n", i, a&#91;i&#93;, last_added&#91;i&#93; + 1, v&#91;last_added&#91;i&#93;&#93;, c&#91;last_added&#91;i&#93;&#93;, i - c&#91;last_added&#91;i&#93;&#93;);
        else
            printf("Weight %d; Benefit: 0; Can't reach this exact weight.\n", i);

    printf("---\n");

    aux = W;
    while ((aux > 0) && (last_added[aux] != -1)) {
        printf("Added object %d (%d$ %dKg). Space left: %d\n", last_added[aux] + 1, v[last_added[aux]], c[last_added[aux]], aux - c[last_added[aux]]);
        aux -= c[last_added[aux]];
    }

    printf("Total value added: %d$\n", a[W]);
}

int main(int argc, char *argv[]) {
    fill_sack();

    return 0;
}
