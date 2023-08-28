#ifndef SERVER_H
#define SERVER_H

#include <string>
#include <string.h>

#include "pico/cyw43_arch.h"
#include "pico/stdlib.h"

#include "lwip/pbuf.h"
#include "lwip/tcp.h"

#include "dhcpserver.h"
#include "dnsserver.h"
#include "webpage.h"

#define TCP_PORT 80
#define DEBUG_printf printf
#define POLL_TIME_S 5
#define HTTP_GET "GET"
#define PAGE_MAX_SIZE 4096

typedef struct TCP_SERVER_T_ {
    struct tcp_pcb *server_pcb;
    bool complete;
    ip_addr_t gw;
    async_context_t *context;
} TCP_SERVER_T;

typedef struct TCP_CONNECT_STATE_T_ {
    struct tcp_pcb *pcb;
    int sent_len;
    char headers[128];
    std::string result;
    int header_len;
    ip_addr_t *gw;
} TCP_CONNECT_STATE_T;

extern TCP_SERVER_T *state;
extern dhcp_server_t dhcp_server;
extern dns_server_t dns_server;

err_t tcp_server_recv(void *arg, struct tcp_pcb *pcb, struct pbuf *p, err_t err);
void key_pressed_worker_func(async_context_t *context, async_when_pending_worker_t *worker);
void key_pressed_func(void *param);

int serverInit(const char *ap_name, const char *password);
void serverDeinit();

#endif