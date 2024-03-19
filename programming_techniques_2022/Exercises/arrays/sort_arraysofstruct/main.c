struct student{
    char name[11];
    float score};

void sortStudent(struct student el[], int n) {
    int i, j, imin;
    struct student temp;
    for (i=0; i<n-1; i++) {
/*find index of min in el[i]..el[n-1]*/
        imin = i;
        for (j = i+1; j < n; j++)
            if (el[j].score < el[imin].score) imin = j;
/*swap min with el[i]*/
        temp = el[i];
        el[i] = el[imin];
        el[imin] = temp;
    }
}