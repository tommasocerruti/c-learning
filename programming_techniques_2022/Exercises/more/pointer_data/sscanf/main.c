#include <stdio.h>
#define MAX 30

int main() {
    int i, x, cnt = 0;
    float sum = 0.0;
    char line[MAX], *s;
    fgets(line,MAX,stdin);
    s=line;
    while (sscanf(s, "%d%n", &x, &i)>0) {
        //1. s points to the start of the portion of the string
        //2. i says how many characters were read (thanks to %n)
        //3. i is used to update s
        s = s+i; // or s = &s[i];
        sum += x;
        cnt++;
    }
    printf("The average is %f\n", sum/cnt);
}
