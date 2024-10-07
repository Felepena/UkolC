#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_USERS = 30;

struct myuser {
    char name[20];
    char surname[20];
    char gmail[20];
};

struct myuser Createuser(char *jmeno, char *prijmeni, char *gmail) {
    struct myuser user;
    strcpy(user.name, jmeno);
    strcpy(user.surname, prijmeni);
    strcpy(user.gmail, gmail);
    return user;
}

void vypis_uzivatele(struct myuser users[], int user_count) {
    if (user_count == 0) {
        printf("Zadne uzivatele nejsou pridani.\n");
    } else {
        printf("\nSeznam uzivatelu:\n");
        for (int i = 0; i < user_count; i++) {
            printf("Uzivatel %d: %s %s", i + 1, users[i].name, users[i].surname);
            printf("Gmail %c:  %c ",  users[i].gmail);
        }
    }
}

void odebrat_uzivatele(struct myuser users[], int *user_count) {
    if (*user_count == 0) {
        printf("Zadne uzivatele nejsou pridani.\n");
        return;
    }

    int index;
    printf("Zadejte cislo uzivatele, ktereho chcete odebrat (1-%d): ", *user_count);
    scanf("%d", &index);

    if (index < 1 || index > *user_count) {
        printf("Neplatny index!\n");
        return;
    }

    for (int i = index - 1; i < *user_count - 1; i++) {
        users[i] = users[i + 1];
    }

    (*user_count)--;
    printf("Uzivatel odebran.\n");
}

int main() {
    struct myuser users[MAX_USERS];
    int user_count = 0;
    char odpoved;

    while (1) {
        printf("\nCo chcete udelat? 'P' pro Pridat uzivatele, 'O' pro Odebrat uzivatele, 'V' pro Vypsat uzivatele, 'Q' pro Ukoncit\n");
        scanf(" %c", &odpoved);

        switch (odpoved) {
            case 'P':
                if (user_count < MAX_USERS) {
                    char jmeno[20];
                    char prijmeni[20];
                    char gmail[20];

                    printf("Jak se jmenuje uzivatel? ");
                    scanf("%s", jmeno);

                    printf("Jake ma prijmeni? ");
                    scanf("%s", prijmeni);

                    printf("Jaky ma gmail? ");
                    scanf("%s", gmail);

                    users[user_count] = Createuser(jmeno, prijmeni, gmail);
                    user_count++;

                    printf("Uzivatel pridan!\n");
                } else {
                    printf("Maximalni pocet uzivatelu dosazen!\n");
                }
                break;

            case 'O':
                odebrat_uzivatele(users, &user_count);
                break;

            case 'V':
                vypis_uzivatele(users, user_count);
                break;

            case 'Q':
                printf("Ukonceni programu.\n");
                return 0;

            default:
                printf("Neplatna volba, zkuste to znovu.\n");
        }
    }

    return 0;   
}
