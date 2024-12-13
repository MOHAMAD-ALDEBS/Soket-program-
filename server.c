#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <time.h>
#include "utils.h"

typedef struct {
    int client_score;
    int server_score;
} Score;

DWORD WINAPI handle_client(LPVOID client_socket) {
    SOCKET sock = (SOCKET)(long)client_socket;
    char buffer[BUFFER_SIZE], result[BUFFER_SIZE];
    Score score = {0, 0}; // Başlangıç skorları
    const char *moves[] = {"tas", "kagit", "makas"};

    srand(time(NULL)); // Rastgele seçim için seed

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Bir istemci bağlantısı kapandı.\n");
            break;
        }

        buffer[bytes_received] = '\0';
        to_lowercase(buffer);
        printf("\nİstemciden gelen: %s\n", buffer);

        if (strcmp(buffer, "exit") == 0) {
            printf("İstemci bağlantıyı kapattı.\n");
            break;
        } else if (strcmp(buffer, "yardim") == 0) {
            strcpy(result, "Komutlar: 'tas', 'kagit', 'makas', 'yardim', 'skor', 'exit'.");
        } else if (strcmp(buffer, "skor") == 0) {
            sprintf(result, "Skor: Sen %d - %d Sunucu", score.client_score, score.server_score);
        } else if (is_valid_move(buffer)) {
            int server_choice = rand() % 3;
            const char *server_move = moves[server_choice];

            determine_winner(buffer, server_move, result);

            if (strcmp(result, "Kazandın") == 0) {
                score.client_score++;
            } else if (strcmp(result, "Kaybettin") == 0) {
                score.server_score++;
            }

            char move_result[BUFFER_SIZE];
            sprintf(move_result, "Sunucu: %s - %s", server_move, result);
            strcpy(result, move_result);
        } else {
            strcpy(result, "Geçersiz hamle. Lütfen 'tas', 'kagit', 'makas', 'yardim', 'skor' veya 'exit' girin.");
        }

        send(sock, result, strlen(result), 0);
    }

    closesocket(sock);
    return 0;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    WSADATA wsa;
    SOCKET server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    int client_addr_len = sizeof(client_addr);

    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("Winsock başlatılamadı. Hata kodu: %d\n", WSAGetLastError());
        return 1;
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == INVALID_SOCKET) {
        printf("Socket oluşturulamadı. Hata kodu: %d\n", WSAGetLastError());
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        printf("Bind başarısız. Hata kodu: %d\n", WSAGetLastError());
        return 1;
    }

    listen(server_socket, MAX_CLIENTS);
    printf("Sunucu dinleniyor...\n");

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket == INVALID_SOCKET) {
            printf("İstemci bağlantısı başarısız. Hata kodu: %d\n", WSAGetLastError());
            continue;
        }

        printf("Yeni istemci bağlandı.\n");
        CreateThread(NULL, 0, handle_client, (LPVOID)(long)client_socket, 0, NULL);
    }

    closesocket(server_socket);
    WSACleanup();
    return 0;
}
