#include <iostream>
#include <math.h>

int main(int argCount, char *args[]) {

    /*
        Program will create a list of subnet address values
        based on an IP address and a subnet mask

        IP address is passed in
        - Address is kept as a string of decimals
        - May have to convert to binary

        Subnet mask is passed in using CIDR notation
        - Passed in "i" = /i

        Calculate subnet address, first address,
        last address, broadcast address, number
        of hosts, number of potential networks
    
    */

    std::string ip;
    int cidr, anchor = 0; // anchor used to get ip addrss numbers
    int ipAddrss[4], snMaskAddrss[4] = {0,0,0,0}, count = 0; // holds 4 numbers


    std::cout << "Please enter an IP address\n" << std::endl; 
    std::cin >> ip; // separated by periods

    std::cout << "Please enter a subnet mask value in accordance with CIDR notation\n" << std::endl;
    std::cin >> cidr;

    // check input of ip address
    if (false) {}

    // check input of subnet mask
    if (cidr < 0 || cidr > 32) {
        std::cout << "Bad subnet mask" << std::endl;
        exit(0);
    }



    // process ip address
    for (int i = 0; i < ip.length(); i++) {
        //std::cout << "Current char: " << ip[i] << std::endl;
        if (ip[i] == '.') {
            // we found a number, take the digits into an integer

            ipAddrss[count++] = std::stoi(ip.substr(anchor, i-anchor)); 
            anchor = i+1; // increment anchor to beginning of next num
        } else if (i == ip.length()-1) { // last number
            ipAddrss[count] = std::stoi(ip.substr(anchor, i-anchor+1)); 
        }
    }

    // process subnet mask
    count = 0;

    for (int i = 1; i < cidr+1; i++) {
        if (i%8 == 0)
            snMaskAddrss[count++] += 1;
        else snMaskAddrss[count] += pow(2, 8-i%8);
    }

    // check processed ip address

    std::cout << "The IP address is: "
        << ipAddrss[0] << '.'
        << ipAddrss[1] << '.'
        << ipAddrss[2] << '.'
        << ipAddrss[3] << std::endl;

    std::cout << "The subnet mask is: " 
        << snMaskAddrss[0] << '.'
        << snMaskAddrss[1] << '.'
        << snMaskAddrss[2] << '.'
        << snMaskAddrss[3] << std::endl;


    int snAddress[4] = {
                (ipAddrss[0] & snMaskAddrss[0]),
                (ipAddrss[1] & snMaskAddrss[1]),
                (ipAddrss[2] & snMaskAddrss[2]),
                (ipAddrss[3] & snMaskAddrss[3])
            };
    
    std::cout << "Your subnet address is: "
        << snAddress[0] << '.'
        << snAddress[1] << '.'
        << snAddress[2] << '.'
        << snAddress[3] << std::endl;




    return 0;
}