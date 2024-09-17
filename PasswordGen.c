#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOWERCASE "abcdefghijklmnopqrstuvwxyz"
#define UPPERCASE "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define DIGITS "0123456789"
#define SPECIAL "!@#$%^&*()-_=+[]{}|;:',.<>?/\\"

void generate_password(int length) {
    // Define all the characters that can be used in the password
    char all_characters[] = LOWERCASE UPPERCASE DIGITS SPECIAL;
    int total_characters = sizeof(all_characters) - 1;

    // Seed the random number generator
    srand(time(0));

    char password[length + 1]; // Password array +1 for the null terminator

    // Ensure the password has at least one lowercase, uppercase, digit, and special character
    password[0] = LOWERCASE[rand() % 26];
    password[1] = UPPERCASE[rand() % 26];
    password[2] = DIGITS[rand() % 10];
    password[3] = SPECIAL[rand() % 29];

    // Generate the rest of the password randomly from all characters
    for (int i = 4; i < length; i++) {
        password[i] = all_characters[rand() % total_characters];
    }

    // Null-terminate the string
    password[length] = '\0';

    // Print the generated password
    printf("Your generated password is: %s\n", password);
}

int main() {
    int length;

    // Ask the user for the password length
    printf("Enter the desired length for your password (minimum 6): ");
    scanf("%d", &length);

    // Validate that the password length is at least 6
    if (length < 6) {
        printf("Password length should be at least 6 characters!\n");
    } else {
        // Generate and display the password
        generate_password(length);
    }

    return 0;
}
