#ifndef UTILS_H
#define UTILS_H
///// (Ortak Sabitler ve İşlevler)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

// Sabitler
#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 5

// Fonksiyonlar
void to_lowercase(char *str);
int is_valid_move(const char *move);
void determine_winner(const char *client_move, const char *server_move, char *result);

// Geçerli hamle kontrolü
int is_valid_move(const char *move) {
    return strcmp(move, "tas") == 0 || strcmp(move, "kagit") == 0 || strcmp(move, "makas") == 0;
}

// Küçük harfe çevirme
void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

// Kazananı belirle
void determine_winner(const char *client_move, const char *server_move, char *result) {
    if (strcmp(client_move, server_move) == 0) {
        strcpy(result, "Berabere");
    } else if ((strcmp(client_move, "tas") == 0 && strcmp(server_move, "makas") == 0) ||
               (strcmp(client_move, "kagit") == 0 && strcmp(server_move, "tas") == 0) ||
               (strcmp(client_move, "makas") == 0 && strcmp(server_move, "kagit") == 0)) {
        strcpy(result, "Kazandın");
    } else {
        strcpy(result, "Kaybettin");
    }
}
 
#endif 