#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define W 5

typedef struct {
    int no;
    bool ack;
} F;

void send(F *f) {
    printf("Sending frame: %d\n", f->no);
}

void recv(int no) {
    printf("ACK received for: %d\n", no);
}

void loss(bool *l) {
    *l = rand() % 5 == 0;
}

void gbn(int n) {
    int nxt = 0, exp = 0;
    F f[n];
    for (int i = 0; i < n; i++) f[i].no = i, f[i].ack = false;

    while (exp < n) {
        while (nxt < exp + W && nxt < n) send(&f[nxt++]);

        bool l;
        loss(&l);

        if (!l && exp < n) {
            recv(f[exp].no);
            f[exp++].ack = true;
        } else {
            printf("Frame %d lost, retransmitting...\n", f[exp].no);
            nxt = exp;
            sleep(1);
        }
    }
    printf("All frames sent and acknowledged!\n");
}

int main() {
    int n;
    printf("Enter total frames: ");
    scanf("%d", &n);
    printf("\n--- Go-Back-N Simulation ---\n");
    gbn(n);
    return 0;
}