#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[30];
    int regno;
    int t1, t2, t3;
    float avg;
};

void read(struct Student *s, int n) {
    for(int i=0;i<n;i++) {
        printf("Name RegNo T1 T2 T3: ");
        scanf("%s %d %d %d %d", s[i].name, &s[i].regno, &s[i].t1, &s[i].t2, &s[i].t3);
    }
}

void calc_avg(struct Student *s, int n) {
    for(int i=0;i<n;i++) {
        int min = s[i].t1;
        if(s[i].t2 < min) min = s[i].t2;
        if(s[i].t3 < min) min = s[i].t3;
        s[i].avg = (s[i].t1 + s[i].t2 + s[i].t3 - min) / 2.0;
    }
}

void sort(struct Student *s, int n) {
    struct Student temp;
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(s[j].regno > s[j+1].regno) {
                temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
}

void display(struct Student *s, int n) {
    printf("\nName RegNo Avg\n");
    for(int i=0;i<n;i++)
        printf("%s %d %.2f\n", s[i].name, s[i].regno, s[i].avg);
}

int main() {
    int n,ch;
    printf("Enter N: ");
    scanf("%d",&n);
    struct Student *s = malloc(n*sizeof(struct Student));

    while(1) {
        printf("\n1.Read 2.Avg 3.Sort 4.Display 5.Exit\n");
        scanf("%d",&ch);
        if(ch==1) read(s,n);
        else if(ch==2) calc_avg(s,n);
        else if(ch==3) sort(s,n);
        else if(ch==4) display(s,n);
        else break;
    }
    free(s);
    return 0;
}
