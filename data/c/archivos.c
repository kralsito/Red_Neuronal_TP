#include <stdio.h>

int main() {
    FILE *fp;
    char buffer[255];

    fp = fopen("test.txt", "w+");
    fprintf(fp, "This is testing for fprintf...\n");
    fputs("This is testing for fputs...\n", fp);
    fclose(fp);

    fp = fopen("test.txt", "r");
    while (fgets(buffer, 255, fp)) {
        printf("%s", buffer);
    }
    fclose(fp);
    return 0;
}
