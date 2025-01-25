#include <stdio.h>
#include <string.h>

int count_digits(long int number);
int card_type(long int number);
int luhn_check(long int card_number);

int main() {
    long int card;

    while (1) {
        printf("Card Number: ");
        if (scanf("%li", &card) != 1) {
            while (getchar() != '\n');
            printf("Invalid card number. Try again.\n");
            continue;
        }

        int digits = count_digits(card);

        if (digits == 13 || digits == 15 || digits == 16) {
            if (luhn_check(card) && card_type(card)) {
                break;
            } else {
                printf("Invalid card number. Try again.\n");
            }
        } else {
            printf("Invalid card number. Try again.\n");
        }
    }

    return 0;
}

int count_digits(long int number) {
    int counter = 0;
    while (number != 0) {
        number /= 10;
        counter++;
    }
    return counter;
}

int card_type(long int number) {
    while (number >= 100) {
        number /= 10;
    }

    if ((number >= 51 && number <= 55) || (number >= 22 && number <= 27)){
        printf("MasterCard\n");
        return 1;
    } else if (number == 34 || number == 37) {
        printf("American Express\n");
        return 1;
    } else if (number / 10 == 4) {
        printf("Visa\n");
        return 1;
    } else {
        return 0;
    }
}

int luhn_check(long int card_number) {
    char card_str[20];
    snprintf(card_str, sizeof(card_str), "%li", card_number);

    int length = strlen(card_str);
    int sum = 0;
    int is_second = 0;

    for (int i = length - 1; i >= 0; i--) {
        int digit = card_str[i] - '0'; // 

        if (is_second) {
            digit *= 2;
            if (digit > 9) {
                digit -= 9;
            }
        }

        sum += digit;
        is_second = !is_second; 
    }

    return (sum % 10 == 0); 
}