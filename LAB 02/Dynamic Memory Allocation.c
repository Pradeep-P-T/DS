int main()
{
int* ptr;
int n;
printf("Enter number of elements:");
scanf("%d",&n);
ptr = (int*)malloc(n * sizeof(int));
if (ptr == NULL) {
printf("Memory not allocated.\n");
exit(0);
}
else {
printf("Memory successfully allocated using malloc.\n");
printf("Enter elements of array\n");
for (int i = 0; i < n; i++) {
scanf("%d", &ptr[i]);
}
printf("The elements of the array are: ");
for (int i = 0; i < n; i++) {
printf("%d, ", ptr[i]);
}
}
free(ptr);
printf("Memory Freed\n");
ptr = (int*)calloc(n, sizeof(int));
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {
        printf("Memory successfully allocated using calloc.\n");
        printf("Enter elements of array\n");
        for (int i = 0; i < n; i++) {
            scanf("%d", &ptr[i]);
        }
        printf("The elements of the array are: ");
        for (int i = 0; i < n; i++) {
            printf("%d, ", ptr[i]);
        }
        int n1;
        printf("Enter new size for realloc\n");
        scanf("%d", &n1);
        ptr = (int*)realloc(ptr, n1 * sizeof(int));
        printf("Memory successfully re-allocated using realloc.\n");
        printf("Enter more variables: \n");
        for (int i = n; i < n1; ++i) {
            scanf("%d", &ptr[i]);
        }
        printf("The elements of the array are: ");
        for (int i = 0; i < n1; ++i) {
            printf("%d, ", ptr[i]);
        }
        free(ptr);
        printf("Memory Freed\n");
    }
}
