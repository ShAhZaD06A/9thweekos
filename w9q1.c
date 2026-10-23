
#include <stdio.h>

int main() {
    int pageSize, address;
    int pageNumber, offset;

    printf("Enter page size: ");
    scanf("%d", &pageSize);

    printf("Enter logical address: ");
    scanf("%d", &address);

    if (pageSize <= 0 || address < 0) {
        printf("Invalid input\n");
        return 1;
    }

    pageNumber = address / pageSize;
    offset = address % pageSize;

    printf("Page Number = %d\n", pageNumber);
    printf("Offset = %d\n", offset);

    return 0;
}
