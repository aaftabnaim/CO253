int main() {
    int num = 10;
    float *floatPtr;
    void *voidPtr;

    // Assigning an int pointer to a void pointer without a cast
    voidPtr = &num;

    printf("%p\n", voidPtr++);
    printf("%p", voidPtr);


    // Assigning a void pointer to a float pointer requires a cast
    floatPtr = (float *)voidPtr;

    return 0;
}
