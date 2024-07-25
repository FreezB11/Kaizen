#include <winsock2.h>
#include <stdio.h>

int main() {
    // Initialize Winsock
    WSADATA wsaData;
    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0) {
        printf("WSAStartup failed: %d\n", result);
        return 1;
    }

    // Create a socket
    SOCKET sockt = socket(AF_INET, SOCK_STREAM, 0);
    if (sockt == INVALID_SOCKET) {
        printf("Socket creation failed: %d\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Replace with server IP
    server_addr.sin_port = htons(8080); // Replace with server port

    if (connect(sockt, (struct sockaddr*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        printf("Connect failed: %d\n", WSAGetLastError());
        closesocket(sockt);
        WSACleanup();
        return 1;
    }

    printf("Connected to server\n");

    // Close the socket and cleanup
    closesocket(sockt);
    WSACleanup();

    return 0;
}
