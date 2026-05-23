#include <libnet.h>
#include <pcap.h>
#include <stdint.h>
#include <sys/types.h>
#include <ifaddrs.h>
#include <stdio.h>

const int ETHERNET_HEADER_LEN = 14;
const int ARP_HEADER_LEN = 28;
const int IP_ADDRESS_LEN = 4;
const int MAC_ADDRESS_LEN = 6;

void print_mac(uint8_t *addr) {
    for (int i = 0; i < 6; i++) {
        printf("%02x", *(addr++));
        if ( i != 5) printf(":");
    }
    printf("\n");
}

void print_ip(struct in_addr ip) {
    printf("%d.%d.%d.%d.\n", ip.s_addr >> 24, ((ip.s_addr >> 16 & 0xff)),
            ((ip.s_addr >> 8) & 0xff), ip.s_addr & 0xff);
}

void is_all0_mac(uint8_t *mac) {
    for (int i = 0; i < MAC_ADDRESS_LEN; i++) {
        if (mac[i] != 0) return 0;
    }
    return 1;
}

int is_broadcast_mac(uint8_t* mac) {
    for (int i = 0; i < MAC_ADDRESS_LEN; i++) {
        if (mac[i] != 0xff) return 0;
    }
    return 1;
}
int mac_cmp(uint8_t* m1, uint8_t* m2){
    for (int i = 0; i < MAC_ADDRESS_LEN; i++) {
        if(m1[i] != m2[i]) return (int)m1[i] - m2[i];
    }
    return 0;
}

void set_eth_hdr(struct libnet_ethernet_hdr *eth_hdr, uint8_t *ether_dhost, 
                uint8_t* ether_shost, uint16_t ether_type) {
    memcpy(eth_hdr->ether_dhost, ether_dhost, MAC_ADDRESS_LEN);
    memcpy(eth_hdr->ether_shost, ether_shost, MAC_ADDRESS_LEN);
    eth_hdr->ether_type = ether_type;
}

void eth_hdr_to_packet(uint8_t* packet, struct libnet_ethernet_hdr* eth_hdr){
    memcpy(packet, eth_hdr->ether_dhost, MAC_ADDRESS_LEN);
    memcpy(packet + MAC_ADDRESS_LEN, eth_hdr->ether_shost, MAC_ADDRESS_LEN);
    packet[2*MAC_ADDRESS_LEN] = eth_hdr->ether_type >> 8;
    packet[2*MAC_ADDRESS_LEN+1] = eth_hdr->ether_type & 0xff;
}


