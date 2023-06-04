
    char **x = names;
    // Print the char *names[]
    printf("char *names[]:\n");
    for (int i = 0; i < 3; i++, x++) {
        printf("%s\n", *(x));
    }
