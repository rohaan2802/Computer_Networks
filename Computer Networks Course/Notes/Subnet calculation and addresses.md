# Subnet Calculation and Addresses

## Finding Subnets, Usable Hosts, Network and Broadcast Addresses

We’ll treat 172.168.0.0 as a Class B network (default mask /16 = 255.255.0.0), and 172.168.1.0 is just an example host in it.  

### 1. Decide how many bits for subnets and hosts

Original (Class B) host bits = 16 (3rd + 4th octet).  
a) Bits for required subnets  
We need at least 60 subnets:  
2⁵ = 32 (not enough)  
2⁶ = 64  enough  
So we must borrow 6 bits for subnetting.  
b) Host bits left  
Host bits left = 16 − 6 = 10 bits  
Check hosts per subnet:  
Hosts per subnet = 2¹⁰ − 2 = 1024 − 2 = 1022 hosts This is ≥ 160, so it satisfies the requirement.  

### 2. New subnet mask

Default /16 + 6 borrowed bits = /22  
In dotted decimal:  
/22 = 255.255.252.0  
(third octet: 11111100 → 252, block size = 256 − 252 = 4) So each subnet jumps by 4 in the third octet.  

### 3. Total subnets and usable hosts

Number of subnets = 2⁶ = 64 subnets  
Usable hosts per subnet = 1022  

### 4. Find a few Network Addresses (NA) and Broadcast Addresses

(BA)  
Since the block size is 4 in the 3rd octet, the subnets of 172.168.0.0/16 with mask /22 are:  
Third octet: 0, 4, 8, 12, 16, …, 252  
Subnet 0  
Network Address (NA): 172.168.0.0  
Broadcast Address (BA): 172.168.3.255  
Usable hosts: 172.168.0.1 → 172.168.3.254 (Your example IP 172.168.1.0 lies inside this first subnet.) Subnet 1  
NA: 172.168.4.0  
BA: 172.168.7.255  
Usable hosts: 172.168.4.1 → 172.168.7.254 Subnet 2  
NA: 172.168.8.0  
BA: 172.168.11.255  
Usable hosts: 172.168.8.1 → 172.168.11.254 Subnet 3  
NA: 172.168.12.0  
BA: 172.168.15.255  
Usable hosts: 172.168.12.1 → 172.168.15.254 …and so on, adding 4 to the third octet each time (16, 20, 24, …, 252).  
IP address: 172.168.1.0  
Required hosts per subnet: 160  
Required subnets: 60  

## Why Not Start from 172.0.0.0

— this is the main confusion students have about Class B addressing.  
Why we do NOT start from 172.0.0.0  
Because your network is not 172.0.0.0.  
Your given address is:  
172.168.1.0  
This belongs to the Class B block:  
172.168.0.0 (network ID)  
—not 172.0.0.0.  
Understanding the CLASS B rule  
A Class B address starts with 172.x.x.x, but the network portion is the first TWO octets:  
So your ENTIRE network that you are subnetting is:  
172.168.0.0/16  
That is your "starting point".  
You cannot start from 172.0.0.0 because it is a different network that your company does NOT own.  
Wrong starting point:  
starting point:  
EASY WAY TO REMEMBER  
Look at the first TWO octets of the given IP:  
Given IP: 172.168.1.0  
Network = 172.168.0.0  
This is ALWAYS the network you must subnet.  
Example to visualize:  
If someone gives:  
IP: 10.5.3.8 → you subnet 10.0.0.0 (Class A) IP: 172.16.9.2 → you subnet 172.16.0.0 (Class B) IP: 192.168.1.55 → you subnet 192.168.1.0 (Class C) So for 172.168.1.0 → we subnet 172.168.0.0 Full list of all 64 subnets  
OR  
How to draw the VLSM tree for your chart Just tell me!  
yaml  
Network: 172.168.0.0  
Host range: 172.168.0.0 – 172.168.255.255 css  
172.0.0.0  → This is a completely different Class B network.  
pgsql  
172.168.0.0 → This is YOUR Class B network (based on given IP).  

## Why 39.54.43.32/8 Starts at 39.0.0.0

If the IP is: 39.54.43.32/8  
The subnet mask /8 means:  
First 8 bits = Network  
Remaining 24 bits = Host  
A /8 mask always corresponds to:  
So the network portion = ONLY the first octet.  
Therefore:  
Given IP: 39.54.43.32  
Network portion (first octet): 39  
Rest become 0.0.0 because they belong to the host section.  
Network Address = 39.0.0.0  
WHY NOT START FROM 39.54.0.0 ?  
Because that would only be correct if the mask were /16, not /8.  
/8 → network is only the FIRST octet  
/16 → network is first TWO octets  
/24 → network is first THREE octets  
Quick breakdown  
CIDR  
Subnet Mask  
Network Portion  
/8  
255.0.0.0  
Only 1st octet  
/16  
255.255.0.0  
1st + 2nd octet  
/24  
255.255.255.0  
1st + 2nd + 3rd octet  
So with /8, ONLY the 39 matters for the network ID.  
Everything after 39 is HOST space.  
Final Key Rule  
The network ALWAYS starts from the network address.  
The network address is formed by zeroing out all host bits.  
For 39.54.43.32/8:  
Network part = 39  
Host part (54.43.32) becomes 0.0.0  
So:  
Network = 39.0.0.0  
First usable = 39.0.0.1  
Last usable = 39.255.255.254  
Broadcast = 39.255.255.255  
Subnets  
Usable ranges  
Broadcast addresses  
Block sizes  
…for any given mask.  
255.0.0.0
