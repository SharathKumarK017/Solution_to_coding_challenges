#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LEN(arr) (sizeof(arr)/sizeof(arr[0]))

void test_func(bool (*func)(const char *str), const char *inputs[], bool v[], int s) {
    for (int i = 0; i < s; ++i) {
        bool result = func(inputs[i]);
        if (result == v[i]) {
            printf("Test %d passed.\n", i+1);
        }
        else {
            printf("Test %d failed!\n", i+1);
        }
    }
}

bool X(const char *bitstring)
{
    int bitstr_len = strlen(bitstring), ind = 0;
    char s[bitstr_len];
    for(int i = 0; i < bitstr_len; ++i) {
        if (bitstring[i] != ' ') {
            s[ind++] = bitstring[i];
        }
    }
    
    while(ind-1 > 0) {
        s[ind-2] = ((s[ind-1] - 0x30 == s[ind-2] - 0x30) ? 0 : 1) + 0x30;
        s[ind-1] = 0;
        --ind;
    }

    return (s[0] - 0x30);
}

int main(void) {
    const char *inputs[] = {
        "1 0 0 1 0",
        "1 0 1 1 1 0 0 1 0 0 0 0",
        "1 0 0 1 0",
        "1 0 1 1 1 0 0 1 0 0 0 0",
        "1 0 0 1 0 1 0 0 1 0 1 0 1 0 1 0 1 0",
        "1",
        "0",
        "0 1 0 1 0 1 0 1 0 1 0 1 0 0 0 0 1 0 1 0 1 0 1 0 1 0 0 0 0 1 1 1 1 1 1 1 1 1 0",
    };
    bool outputs[] = {
        0,
        1,
        0,
        1,
        0,
        1,
        0,
        0,
    };
    int len = LEN(inputs);

    assert(LEN(inputs) == LEN(outputs));

    test_func(X, inputs, outputs, len);

    //printf("in: 1 0 0 1 0; exp_out: 0\n");
    //printf("real_out: X(\"1 0 0 1 0\") = %d\n", X("1 0 0 1 0"));
    return 0;
}

