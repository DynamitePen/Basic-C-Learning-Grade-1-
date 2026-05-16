#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int classifyIP(string ipStr) {
    int octets[4] = {0, 0, 0, 0};
    sscanf(ipStr.c_str(), "%d.%d.%d.%d", &octets[0], &octets[1], &octets[2], &octets[3]);
    int firstOctet = octets[0];

    if (firstOctet >= 0 && firstOctet <= 127) {
        return 0;
    } else if (firstOctet >= 128 && firstOctet <= 191) {
        return 1;
    } else if (firstOctet >= 192 && firstOctet <= 223) {
        return 2;
    } else if (firstOctet >= 224 && firstOctet <= 239) {
        return 3;
    } else {
        return 4;
    }
}

int main() {
    int counts[5] = {0, 0, 0, 0, 0};

    cout << "Enter IP addresses (enter 'quit' to finish):\n";

    string ip;
    while (cin >> ip) {
        if (ip == "quit") break;
        int classIdx = classifyIP(ip);
        counts[classIdx]++;
    }

    cout << "\nNumber of class A addresses: " << counts[0] << "\n";
    cout << "Number of class B addresses: " << counts[1] << "\n";
    cout << "Number of class C addresses: " << counts[2] << "\n";
    cout << "Number of class D addresses: " << counts[3] << "\n";
    cout << "Number of class E addresses: " << counts[4] << "\n";

    return 0;
}
