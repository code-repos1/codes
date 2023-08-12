#include <stdio.h>
// A calculator with 10 functions.
// Author Karlson
// Email : kohkarlson@gmail.com

int main() {
    int choice;
    double num1, num2;
    	
    printf("Welcome to this calculator program. Select from the menu below of what you'd like to do\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("6. Power\n");
    printf("7. Square Root\n");
    printf("8. Logarithm\n");
    printf("9. Sine\n");
    printf("10.Cosine\n");
    printf("11.Tangent\n");
    printf("Enter your choice (1-11): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            printf("Result: %.2lf\n", num1 + num2);
            break;
        case 2:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            printf("Result: %.2lf\n", num1 - num2);
            break;
        case 3:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            printf("Result: %.2lf\n", num1 * num2);
            break;
        case 4:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            if (num2 != 0) {
                printf("Result: %.2lf\n", num1 / num2);
            } else {
                printf("Error: Division by zero is not allowed.\n");
            }
            break;
        case 5:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            printf("Result: %.2lf\n", fmod(num1, num2));
            break;
        case 6:
            printf("Enter the base number: ");
            scanf("%lf", &num1);
            printf("Enter the exponent: ");
            scanf("%lf", &num2);
            printf("Result: %.2lf\n", pow(num1, num2));
            break;
        case 7:
            printf("Enter a number: ");
            scanf("%lf", &num1);
            if (num1 >= 0) {
                printf("Result: %.2lf\n", sqrt(num1));
            } else {
                printf("Error: Square root of a negative number is not defined.\n");
            }
            break;
        case 8:
            printf("Enter a number: ");
            scanf("%lf", &num1);
            if (num1 > 0) {
                printf("Result: %.2lf\n", log10(num1));
            } else {
                printf("Error: Logarithm of a non-positive number is not defined.\n");
            }
            break;
        case 9:
            printf("Enter an angle in degrees: ");
            scanf("%lf", &num1);
            printf("Result: %.2lf\n", sin(num1 * 3.14159 / 180.0));
            break;
        case 10:
            printf("Enter an angle in degrees: ");
            scanf("%lf", &num1);
            printf("Result: %.2lf\n", cos(num1 * 3.14159 / 180.0));
            break;
        case 11:
            printf("Enter an angle in degrees: ");
            scanf("%lf", &num1);
            printf("Result: %.2lf\n", tan(num1 * 3.14159 / 180.0));
            break;
        default:
            printf("Invalid choice. Please select a number between 1 and 11.\n");
            break;
    }

    return 0;
}


/*
Certainly! Let's go through the code line by line to explain what each part does:

```c
#include <stdio.h>
```

This line includes the `stdio.h` header file, which provides input and output functionality in C. It allows us to use functions like `printf` and `scanf`.

```c
int main() {
```

This is the starting point of the program. It defines the `main` function, which is the entry point for execution.

```c
    int choice;
    double num1, num2;
```

These lines declare variables `choice`, `num1`, and `num2`. `choice` will store the user's menu choice, while `num1` and `num2` will store the operands for the calculations.

```c
    printf("Calculator Menu:\n");
    printf("1. Addition\n");
    // ...
    printf("11. Trigonometric Tangent\n");
    printf("Enter your choice (1-11): ");
    scanf("%d", &choice);
```

These lines display the calculator menu to the user and prompt them to enter a choice. The user's input is read into the `choice` variable using `scanf`.

```c
    switch (choice) {
        case 1:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            printf("Result: %.2lf\n", num1 + num2);
            break;
        case 2:
            // ...
```

This is a switch statement that determines the action to be performed based on the user's choice. Depending on the value of `choice`, the program executes the corresponding case. Each case prompts the user for input, reads the operands, performs the calculation, and displays the result using `printf`.

```c
        default:
            printf("Invalid choice. Please select a number between 1 and 11.\n");
            break;
    }
```

The `default` case is executed if the user enters a choice other than 1 to 11. It displays an error message indicating an invalid choice.

```c
    return 0;
}
```

This statement ends the `main` function and indicates the successful execution of the program. The value `0` is returned to the operating system, indicating that the program terminated without errors.
*/
