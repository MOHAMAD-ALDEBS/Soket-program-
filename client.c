#include <winsock2.h>
#include "utils.h"

int main() {
    SetConsoleOutputCP(CP_UTF8); // Konsol çıktısını UTF-8 olarak ayarla
    SetConsoleCP(CP_UTF8);       // Konsol girdisini UTF-8 olarak ayarla
    WSADATA wsa;
    SOCKET client_socket;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE], message[BUFFER_SIZE];

    WSAStartup(MAKEWORD(2, 2), &wsa);
    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(PORT);

    connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    printf("Sunucuya bağlanıldı.\n");

    while (1) {
        printf("Hamle (tas/kagit/makas, 'yardim', 'skor', 'exit'): ");
        fgets(message, BUFFER_SIZE, stdin);
        message[strcspn(message, "\n")] = '\0';

        send(client_socket, message, strlen(message), 0);

        int read_size = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (read_size > 0) {
            buffer[read_size] = '\0';
            printf("Sunucu: %s\n", buffer);
        }
    }

    closesocket(client_socket);
    WSACleanup();
    return 0;
}
