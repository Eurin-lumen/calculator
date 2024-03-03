#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
void displayMenu();
void arithmeticMenu();
void countingMenu();
int factorial(int n);
int arrangement(int n, int p);
int combination(int n, int p);
void solveQuadraticEquation();
void displayFirstNEvenNumbers();
void displayFirstNPrimeNumbers();
int isPrime(int num);

int main() {
    int choice;

    do {
        displayMenu();
        printf("Veuillez faire un choix : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                arithmeticMenu();
                break;
            case 2:
                countingMenu();
                break;
            case 3:
                solveQuadraticEquation();
                break;
            case 4:
                displayFirstNEvenNumbers();
                break;
            case 5:
                displayFirstNPrimeNumbers();
                break;
            case 6: {
                double num;
                printf("Veuillez entrer un nombre : ");
                scanf("%lf", &num);
                printf("La valeur absolue de %.2lf est %.2lf\n", num, fabs(num));
                break;
            }
            case 7: {
                int u, k;
                printf("Veuillez entrer les bornes u et k (u <= k) : ");
                scanf("%d %d", &u, &k);

                for (int i = u; i <= k; i++) {
                    printf("TABLE DE MULTIPLICATION DE %d\n", i);
                    for (int j = 0; j <= 12; j++) {
                        printf("%d*%d=%d\n", i, j, i * j);
                    }
                }
                break;
            }
            case 8:
                printf("Programme terminé. Au revoir!\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }

    } while (choice != 8);

    return 0;
}

void displayMenu() {
    printf("\nMENU N° 1\n");
    printf("1- Calculs arithmetiques\n");
    printf("2- Denombrement\n");
    printf("3- Equation du second degre\n");
    printf("4- Nombres pairs\n");
    printf("5- Nombres premiers\n");
    printf("6- Valeur absolue d’un nombre\n");
    printf("7- Table de multiplication d’un intervalle\n");
    printf("8- Quitter\n");
}

// ... (Previous code)

void arithmeticMenu() {
    char operation;
    int n, m;

    printf("\nMENU N° 1-1\n");
    printf("a- Addition de n nombres\n");
    printf("b- Soustraction de n nombres\n");
    printf("c- Multiplication de n nombres\n");
    printf("d- Division de n nombres par m nombres\n");
    printf("Veuillez faire un choix : ");
    scanf(" %c", &operation);

    switch (operation) {
        case 'a': {
            int result = 0;
            printf("Combien de nombres voulez-vous additionner ? ");
            scanf("%d", &n);

            for (int i = 0; i < n; i++) {
                int num;
                printf("Veuillez entrer le nombre %d : ", i + 1);
                scanf("%d", &num);
                result += num;
            }

            printf("Résultat de l'addition : %d\n", result);
            break;
        }
        case 'b': {
            int result;
            printf("Combien de nombres voulez-vous soustraire ? ");
            scanf("%d", &n);

            printf("Veuillez entrer le nombre 1 : ");
            scanf("%d", &result);

            for (int i = 1; i < n; i++) {
                int num;
                printf("Veuillez entrer le nombre %d : ", i + 1);
                scanf("%d", &num);
                result -= num;
            }

            printf("Résultat de la soustraction : %d\n", result);
            break;
        }
        case 'c': {
            int result = 1;
            printf("Combien de nombres voulez-vous multiplier ? ");
            scanf("%d", &n);

            for (int i = 0; i < n; i++) {
                int num;
                printf("Veuillez entrer le nombre %d : ", i + 1);
                scanf("%d", &num);
                result *= num;
            }

            printf("Résultat de la multiplication : %d\n", result);
            break;
        }
        case 'd': {
            double result;
            printf("Veuillez entrer le nombre n : ");
            scanf("%d", &n);

            printf("Veuillez entrer le nombre m : ");
            scanf("%d", &m);

            // Check if divisor is not zero
            if (m == 0) {
                printf("Erreur : Division par zéro.\n");
            } else {
                result = (double)n / m;
                printf("Résultat de la division : %.2lf\n", result);
            }
            break;
        }
        default:
            printf("Opération invalide. Veuillez réessayer.\n");
    }
}

void countingMenu() {
    char operation;
    int n, p;

    printf("\nMENU N° 1-2\n");
    printf("a- Factoriel d’un entier n\n");
    printf("b- Arrangement Anp\n");
    printf("c- Combinaison Cnp\n");
    printf("Veuillez faire un choix : ");
    scanf(" %c", &operation);

    switch (operation) {
        case 'a': {
            printf("Veuillez entrer un entier n : ");
            scanf("%d", &n);

            if (n < 0) {
                printf("Erreur : n doit être positif.\n");
            } else {
                int result = factorial(n);
                printf("Factoriel de %d : %d\n", n, result);
            }
            break;
        }
        case 'b':
            printf("Veuillez entrer deux entiers n et p (n <= p) : ");
            scanf("%d %d", &n, &p);

            if (n < 0 || p < 0 || n > p) {
                printf("Erreur : n et p doivent être non-négatifs, et n doit être inférieur ou égal à p.\n");
            } else {
                int result = arrangement(n, p);
                printf("Arrangement A(%d, %d) : %d\n", n, p, result);
            }
            break;
        case 'c':
            printf("Veuillez entrer deux entiers n et p (n <= p) : ");
            scanf("%d %d", &n, &p);

            if (n < 0 || p < 0 || n > p) {
                printf("Erreur : n et p doivent être non-négatifs, et n doit être inférieur ou égal à p.\n");
            } else {
                int result = combination(n, p);
                printf("Combinaison C(%d, %d) : %d\n", n, p, result);
            }
            break;
        default:
            printf("Opération invalide. Veuillez réessayer.\n");
    }
}

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int arrangement(int n, int p) {
    int result = 1;
    for (int i = 0; i < p; i++) {
        result *= n - i;
    }
    return result;
}

int combination(int n, int p) {
    return arrangement(n, p) / factorial(p);
}

void solveQuadraticEquation() {
    double a, b, c;
    double discriminant, root1, root2;

    printf("Veuillez entrer les coefficients a, b, et c de l'équation ax^2 + bx + c = 0 :\n");
    printf("a : ");
    scanf("%lf", &a);
    printf("b : ");
    scanf("%lf", &b);
    printf("c : ");
    scanf("%lf", &c);

    discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Les solutions de l'équation sont : %.2lf et %.2lf\n", root1, root2);
    } else if (discriminant == 0) {
        root1 = root2 = -b / (2 * a);
        printf("L'équation a une solution double : %.2lf\n", root1);
    } else {
        printf("L'équation n'a pas de solution réelle.\n");
    }
}

void displayFirstNEvenNumbers() {
    int n;
    printf("Veuillez entrer un nombre n : ");
    scanf("%d", &n);

    printf("Les %d premiers nombres pairs sont :\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", 2 * i);
    }
    printf("\n");
}

void displayFirstNPrimeNumbers() {
    int n;
    printf("Veuillez entrer un nombre n : ");
    scanf("%d", &n);

    printf("Les %d premiers nombres premiers sont :\n", n);

    int count = 0;
    int num = 2; // Starting from the first prime number

    while (count < n) {
        if (isPrime(num)) {
            printf("%d ", num);
            count++;
        }
        num++;
    }
    printf("\n");
}

int isPrime(int num) {
    if (num < 2) {
        return 0; // Not prime
    }

    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0; // Not prime
        }
    }

    return 1; // Prime
}