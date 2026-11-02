<div align="center">

# Computer Networks

**Computer Networks · FAST-NUCES · BS Computer Science**

My Computer Networks course work – lectures, labs with C socket programming, Packet Tracer routing (static, OSPF, EIGRP, BGP), subnetting and VLSM, DHCP and NAT, VLAN and ACL, Wireshark, assignments and notes.

[![Course: Computer Networks](https://img.shields.io/badge/Course-Computer%20Networks-1e3a8a?style=for-the-badge)](#course-overview)
[![FAST-NUCES BS CS](https://img.shields.io/badge/FAST--NUCES-BS%20CS-166534?style=for-the-badge)](#course-overview)
[![Labs: C Sockets, Packet Tracer](https://img.shields.io/badge/Labs-C%20Sockets%20%7C%20Packet%20Tracer-7c2d12?style=for-the-badge)](#course-overview)
[![Topics: Subnetting, OSPF, BGP](https://img.shields.io/badge/Topics-Subnetting%20%7C%20OSPF%20%7C%20BGP-6d28d9?style=for-the-badge)](#course-overview)
[![Release](https://img.shields.io/badge/Release-v1.0-b91c1c?style=for-the-badge)](https://github.com/rohaan2802/Computer_Networks/releases/tag/v1.0)
[![Website](https://img.shields.io/badge/Website-Live-0b7285?style=for-the-badge)](https://rohaan2802.github.io/Computer_Networks/)

</div>

---

## Live Links

| What | Link |
|---|---|
| Repository | https://github.com/rohaan2802/Computer_Networks |
| Website (GitHub Pages) | https://rohaan2802.github.io/Computer_Networks/ |
| Download whole repository (ZIP) | https://github.com/rohaan2802/Computer_Networks/archive/refs/heads/main.zip |
| Releases page | https://github.com/rohaan2802/Computer_Networks/releases |
| Release v1.0 – Large Files | https://github.com/rohaan2802/Computer_Networks/releases/tag/v1.0 |

---

## Table of Contents

- [Course Overview](#course-overview)
- [Topics Covered](#topics-covered)
- [Repository at a Glance](#repository-at-a-glance)
- [Lectures](#lectures)
- [Labs](#labs)
- [Assignments, Project and Exams](#assignments-project-and-exams)
- [Books and Notes](#books-and-notes)
- [Large Files (Release Downloads)](#large-files-release-downloads)
- [Folder Structure](#folder-structure)
- [Screenshots](#screenshots)
- [Using the Files](#using-the-files)
- [License](#license)
- [Author](#author)

---

## Course Overview

Computer Networks at FAST-NUCES Islamabad. The repository has 16 weeks of lecture slides, 15 labs with my C socket programs and Packet Tracer files, three assignments, the CNET project, sessional exams, quizzes, the Kurose and Ross textbook and my study notes.

## Topics Covered

| Unit | Topics |
|---|---|
| **Unit 1 – Application layer** | Network edge and core, delay and throughput, HTTP, DNS, email, P2P and sockets. |
| **Unit 2 – Transport layer** | UDP, checksums, reliable data transfer, Go-Back-N, Selective Repeat, TCP and congestion control. |
| **Unit 3 – Network layer** | IP addressing, subnetting and VLSM, DHCP, NAT, IPv6, routing algorithms, OSPF and BGP. |
| **Unit 4 – Link layer and labs** | Ethernet, ARP, VLANs and 15 labs: C socket programming, Packet Tracer routing, Wireshark. |

## Repository at a Glance

| Item | Count |
|---|---|
| Lecture decks (Weeks 1–16) | 14 |
| Labs | 15 |
| Slide decks (PPTX) | 14 |
| Word documents | 24 |
| C source files | 14 |
| Packet Tracer files (.pkt) | 8 |
| Study notes (Markdown) | 14 |
| PDF documents | 27 |
| Screenshots | 30 |
| Files in total | 128 |

## Lectures

| Week | Topic | Covers |
|---|---|---|
| 01 | [Introduction](https://github.com/rohaan2802/Computer_Networks/tree/main/Computer%20Networks%20Course/Lecture%20%2301) | What the Internet is, network edge, access networks and physical media |
| 02 | [Network core and performance](https://github.com/rohaan2802/Computer_Networks/tree/main/Computer%20Networks%20Course/Lecture%20%2302) | Packet vs circuit switching, Internet structure, delay, loss, throughput, security and layering |
| 03 | [Application layer and HTTP](https://github.com/rohaan2802/Computer_Networks/tree/main/Computer%20Networks%20Course/Lecture%20%2303) | Client-server and P2P, sockets, HTTP, cookies and web caching |
| 04 | [FTP, email and DNS](https://github.com/rohaan2802/Computer_Networks/tree/main/Computer%20Networks%20Course/Lecture%20%2304) | FTP, SMTP, POP3 and IMAP, and the Domain Name System |
| 05 | [P2P, video streaming and CDNs](https://github.com/rohaan2802/Computer_Networks/tree/main/Computer%20Networks%20Course/Lecture%20%2305) | Peer-to-peer file distribution, BitTorrent, DASH streaming and content networks |
| 06 | [Transport layer and UDP](https://github.com/rohaan2802/Computer_Networks/tree/main/Computer%20Networks%20Course/Lecture%20%2306) | Multiplexing, demultiplexing, UDP and the Internet checksum |
| 07 | [Reliable data transfer](https://github.com/rohaan2802/Computer_Networks/tree/main/Computer%20Networks%20Course/Lecture%20%2307) | rdt 1.0 to 3.0, stop-and-wait, pipelining, Go-Back-N and Selective Repeat |
| 08 | [TCP](https://github.com/rohaan2802/Computer_Networks/tree/main/Computer%20Networks%20Course/Lecture%20%2308) | TCP segment structure, RTT and timeout, reliable transfer, flow control and connection management |
| 09-10 | [Congestion control](https://github.com/rohaan2802/Computer_Networks/tree/main/Computer%20Networks%20Course/Lecture%20%2309-10) | Causes of congestion, AIMD, slow start, CUBIC, ECN, fairness and QUIC |
| 11 | [Network layer: data plane](https://github.com/rohaan2802/Computer_Networks/tree/main/Computer%20Networks%20Course/Lecture%20%2311) | Router architecture, longest prefix matching, switching fabrics and scheduling |
| 12-13 | [IP, DHCP, NAT and IPv6](https://github.com/rohaan2802/Computer_Networks/tree/main/Computer%20Networks%20Course/Lecture%20%2312-13) | IP datagrams, subnets and CIDR, DHCP, NAT, IPv6 and generalised forwarding |
| 14 | [Routing algorithms](https://github.com/rohaan2802/Computer_Networks/tree/main/Computer%20Networks%20Course/Lecture%20%2314) | Link-state (Dijkstra) and distance-vector (Bellman-Ford) routing |
| 15 | [OSPF, BGP and SDN](https://github.com/rohaan2802/Computer_Networks/tree/main/Computer%20Networks%20Course/Lecture%20%2315) | Intra- and inter-AS routing, OSPF, BGP, SDN, OpenFlow and ICMP |
| 16 | [Link layer](https://github.com/rohaan2802/Computer_Networks/tree/main/Computer%20Networks%20Course/Lecture%20%2316) | Error detection, multiple access, ARP, Ethernet, switches and VLANs |

## Labs

| Lab | Topic | Contents |
|---|---|---|
| 01 | [Introduction to networking and Packet Tracer](https://github.com/rohaan2802/Computer_Networks/tree/main/Computer%20Networks%20Lab/Lab%20%2301) | Lab manual |
| 02 | [Protocol layers, wireless, ping and traceroute](https://github.com/rohaan2802/Computer_Networks/tree/main/Computer%20Networks%20Lab/Lab%20%2302) | Manual, my report, Packet Tracer files and screenshots |
| 03 | [Capturing HTTP and HTTPS with Wireshark](https://github.com/rohaan2802/Computer_Networks/tree/main/Computer%20Networks%20Lab/Lab%20%2303) | Manual, my report and HTML test pages |
| 04 | [DNS and email server in Packet Tracer](https://github.com/rohaan2802/Computer_Networks/tree/main/Computer%20Networks%20Lab/Lab%20%2304) | Lab manual |
| 05 | [TCP socket programming in C](https://github.com/rohaan2802/Computer_Networks/tree/main/Computer%20Networks%20Lab/Lab%20%2305) | Manual, task and my client/server code |
| 06 | [UDP socket programming in C](https://github.com/rohaan2802/Computer_Networks/tree/main/Computer%20Networks%20Lab/Lab%20%2306) | Manual, task and my largest-number and palindrome programs |
| 07 | [Concurrent servers](https://github.com/rohaan2802/Computer_Networks/tree/main/Computer%20Networks%20Lab/Lab%20%2307) | fork and thread servers and my client/server code |
| 08 | [Static routing in Packet Tracer](https://github.com/rohaan2802/Computer_Networks/tree/main/Computer%20Networks%20Lab/Lab%20%2308) | Manual, task and my .pkt file |
| 09 | [Digital transmission and subnetting](https://github.com/rohaan2802/Computer_Networks/tree/main/Computer%20Networks%20Lab/Lab%20%2309) | Wireshark manual, subnetting and VLSM practice and my solution |
| 10 | [Routing configuration](https://github.com/rohaan2802/Computer_Networks/tree/main/Computer%20Networks%20Lab/Lab%20%2310) | Manual, task, my report and .pkt file |
| 11 | [OSPF and EIGRP](https://github.com/rohaan2802/Computer_Networks/tree/main/Computer%20Networks%20Lab/Lab%20%2311) | Manual, task, my report and .pkt file |
| 12 | [VLSM](https://github.com/rohaan2802/Computer_Networks/tree/main/Computer%20Networks%20Lab/Lab%20%2312) | VLSM manual, my report and .pkt file |
| 13 | [DHCP and NAT](https://github.com/rohaan2802/Computer_Networks/tree/main/Computer%20Networks%20Lab/Lab%20%2313) | Manual, my report and .pkt file |
| 14 | [VLAN and ACL](https://github.com/rohaan2802/Computer_Networks/tree/main/Computer%20Networks%20Lab/Lab%20%2314) | Manual, task, my report and .pkt file |
| 15 | [BGP simulation](https://github.com/rohaan2802/Computer_Networks/tree/main/Computer%20Networks%20Lab/Lab%20%2315) | Manual and my report |

## Assignments, Project and Exams

| Item | Folder | Contents |
|---|---|---|
| A | [Assignments](https://github.com/rohaan2802/Computer_Networks/tree/main/Computer%20Networks%20Course/Assignments) | Assignment 1 to 3 statements and my solutions |
| P | [CNET project](https://github.com/rohaan2802/Computer_Networks/tree/main/Computer%20Networks%20Course/CNET_PROJECT) | Project description, rubric, IP address plan and topology |
| M | [Sessional exams](https://github.com/rohaan2802/Computer_Networks/tree/main/Computer%20Networks%20Course/Mids) | Sessional I and II papers with solutions |
| Q | [Quizzes and class tasks](https://github.com/rohaan2802/Computer_Networks/tree/main/Computer%20Networks%20Course/Quizes) | Quiz archives and class tasks with solutions |

## Books and Notes

| Folder | Contents |
|---|---|
| [Study notes](https://github.com/rohaan2802/Computer_Networks/tree/main/Computer%20Networks%20Course/Notes) | My notes on bandwidth, delay and throughput, checksums, GBN and SR, subnetting and VLSM, web caching, security and more, plus a cheat sheet |
| [Textbook](https://github.com/rohaan2802/Computer_Networks/tree/main/Computer%20Networks%20Course/Books) | Kurose and Ross, Computer Networking: A Top-Down Approach, 8th ed. |

## Large Files (Release Downloads)

GitHub does not allow files bigger than 100 MB inside a repository, so one file is attached to the **[v1.0 release](https://github.com/rohaan2802/Computer_Networks/releases/tag/v1.0)** instead:

| File | Size | Belongs in | Contents |
|---|---|---|---|
| Lab3_Solution_3.pcapng | 502.7 MB | Computer Networks Lab/Lab #03 | Wireshark capture for Lab 3 (HTTP and HTTPS), also used in Assignment 1 |

Every other file is in the repository. The biggest one is the Kurose and Ross textbook PDF (20.5 MB).

## Folder Structure

```text
Computer_Networks/
├── Computer Networks Course/
│   ├── Assignments/                      (12 files)
│   ├── Books/                            (1 file)
│   ├── CNET_PROJECT/                     (4 files)
│   ├── Lecture #01/                      (1 file)
│   ├── Lecture #02/                      (1 file)
│   ├── Lecture #03/                      (1 file)
│   ├── Lecture #04/                      (1 file)
│   ├── Lecture #05/                      (1 file)
│   ├── Lecture #06/                      (1 file)
│   ├── Lecture #07/                      (1 file)
│   ├── Lecture #08/                      (1 file)
│   ├── Lecture #09-10/                   (1 file)
│   ├── Lecture #11/                      (1 file)
│   ├── Lecture #12-13/                   (1 file)
│   ├── Lecture #14/                      (1 file)
│   ├── Lecture #15/                      (1 file)
│   ├── Lecture #16/                      (1 file)
│   ├── Mids/                             (4 files)
│   ├── Notes/                            (18 files)
│   └── Quizes/                           (5 files)
├── Computer Networks Lab/
│   ├── Lab #01/                          (1 file)
│   ├── Lab #02/                          (14 files)
│   ├── Lab #03/                          (4 files)
│   ├── Lab #04/                          (1 file)
│   ├── Lab #05/                          (6 files)
│   ├── Lab #06/                          (6 files)
│   ├── Lab #07/                          (9 files)
│   ├── Lab #08/                          (4 files)
│   ├── Lab #09/                          (5 files)
│   ├── Lab #10/                          (4 files)
│   ├── Lab #11/                          (4 files)
│   ├── Lab #12/                          (3 files)
│   ├── Lab #13/                          (3 files)
│   ├── Lab #14/                          (4 files)
│   └── Lab #15/                          (2 files)
├── assets/
│   ├── screenshots/   30 images
│   ├── thumbs/        gallery previews
│   └── css/  js/      website
├── index.html
├── .gitattributes
├── .gitignore
├── .nojekyll
├── LICENSE
└── README.md
```

## Screenshots

### 1. Repository Folder Structure

<img src="assets/screenshots/01_repository_structure.png" alt="Repository Folder Structure" width="100%">

### 2. Lab 5 – TCP Server in C (socket, bind, listen, accept)

<img src="assets/screenshots/02_tcp_server_socket.png" alt="Lab 5 – TCP Server in C (socket, bind, listen, accept)" width="100%">

### 3. Lab 5 – TCP Client in C (connect, send, recv)

<img src="assets/screenshots/03_tcp_client_socket.png" alt="Lab 5 – TCP Client in C (connect, send, recv)" width="100%">

### 4. Lab 6 – UDP Server: Largest Number (recvfrom/sendto)

<img src="assets/screenshots/04_udp_server_largest.png" alt="Lab 6 – UDP Server: Largest Number (recvfrom/sendto)" width="100%">

### 5. Lab 6 – UDP Client: Palindrome Check

<img src="assets/screenshots/05_udp_client_palindrome.png" alt="Lab 6 – UDP Client: Palindrome Check" width="100%">

### 6. Lab 7 – Concurrent Server with fork()

<img src="assets/screenshots/06_fork_concurrent_server.png" alt="Lab 7 – Concurrent Server with fork()" width="100%">

### 7. Lab 7 – Concurrent Server with pthreads

<img src="assets/screenshots/07_thread_concurrent_server.png" alt="Lab 7 – Concurrent Server with pthreads" width="100%">

### 8. Lab 8 – Static Routing Topology in Packet Tracer

<img src="assets/screenshots/08_static_routing_topology.png" alt="Lab 8 – Static Routing Topology in Packet Tracer" width="100%">

### 9. Lab 10 – Router Configuration and Routing Table

<img src="assets/screenshots/09_lab10_routing_configuration.png" alt="Lab 10 – Router Configuration and Routing Table" width="100%">

### 10. Lab 11 – OSPF Topology (Multiple Areas)

<img src="assets/screenshots/10_ospf_topology.png" alt="Lab 11 – OSPF Topology (Multiple Areas)" width="100%">

### 11. Lab 11 – EIGRP Topology and Verification

<img src="assets/screenshots/11_eigrp_topology.png" alt="Lab 11 – EIGRP Topology and Verification" width="100%">

### 12. Lab 12 – VLSM Network in Packet Tracer

<img src="assets/screenshots/12_vlsm_lab_topology.png" alt="Lab 12 – VLSM Network in Packet Tracer" width="100%">

### 13. Lab 13 – DHCP and NAT Topology

<img src="assets/screenshots/13_dhcp_nat_configuration.png" alt="Lab 13 – DHCP and NAT Topology" width="100%">

### 14. Lab 14 – VLAN and ACL Topologies

<img src="assets/screenshots/14_vlan_acl_topology.png" alt="Lab 14 – VLAN and ACL Topologies" width="100%">

### 15. Lab 15 – BGP Between Autonomous Systems

<img src="assets/screenshots/15_bgp_simulation.png" alt="Lab 15 – BGP Between Autonomous Systems" width="100%">

### 16. Lab 2 – Ping and Traceroute in Packet Tracer

<img src="assets/screenshots/16_ping_traceroute_packet_tracer.png" alt="Lab 2 – Ping and Traceroute in Packet Tracer" width="100%">

### 17. Lab 4 – DNS and Email Server Topology

<img src="assets/screenshots/17_dns_email_server_topology.png" alt="Lab 4 – DNS and Email Server Topology" width="100%">

### 18. Lab 3 – Capturing HTTP with Wireshark

<img src="assets/screenshots/18_wireshark_http_capture.png" alt="Lab 3 – Capturing HTTP with Wireshark" width="100%">

### 19. Lab 9 – Subnetting Worked Solution

<img src="assets/screenshots/19_subnetting_worked_solution.png" alt="Lab 9 – Subnetting Worked Solution" width="100%">

### 20. VLSM Tree Method – Address Allocation

<img src="assets/screenshots/20_vlsm_allocation_tree.png" alt="VLSM Tree Method – Address Allocation" width="100%">

### 21. Lab 12 – VLSM Addressing Table

<img src="assets/screenshots/21_vlsm_manual_example.png" alt="Lab 12 – VLSM Addressing Table" width="100%">

### 22. CNET Project – Network Topology

<img src="assets/screenshots/22_project_topology.png" alt="CNET Project – Network Topology" width="100%">

### 23. Week 2 – How Packet Delay and Loss Occur

<img src="assets/screenshots/23_packet_delay_and_loss.png" alt="Week 2 – How Packet Delay and Loss Occur" width="100%">

### 24. Week 3 – Access Link Utilisation and Delay with a Web Cache

<img src="assets/screenshots/24_web_cache_delay_calculation.png" alt="Week 3 – Access Link Utilisation and Delay with a Web Cache" width="100%">

### 25. Week 4 – DNS Iterated Query

<img src="assets/screenshots/25_dns_iterated_query.png" alt="Week 4 – DNS Iterated Query" width="100%">

### 26. Week 6 – Internet Checksum Example

<img src="assets/screenshots/26_internet_checksum_example.png" alt="Week 6 – Internet Checksum Example" width="100%">

### 27. Week 7 – Go-Back-N in Action

<img src="assets/screenshots/27_go_back_n_in_action.png" alt="Week 7 – Go-Back-N in Action" width="100%">

### 28. Week 9-10 – TCP Slow Start

<img src="assets/screenshots/28_tcp_slow_start.png" alt="Week 9-10 – TCP Slow Start" width="100%">

### 29. Week 12-13 – NAT Translation Table

<img src="assets/screenshots/29_nat_translation_table.png" alt="Week 12-13 – NAT Translation Table" width="100%">

### 30. Week 15 – eBGP and iBGP Connections

<img src="assets/screenshots/30_ebgp_ibgp_connections.png" alt="Week 15 – eBGP and iBGP Connections" width="100%">

## Using the Files

```bash
git clone https://github.com/rohaan2802/Computer_Networks.git
cd Computer_Networks
```

- Lectures are PowerPoint (`.pptx`) files; lab manuals, reports, assignments and exams are PDF and Word (`.docx`) files.
- Lab code is C for Linux: compile with `gcc server.c -o server` (add `-lpthread` for the thread server), run the server, then the client.
- `.pkt` files open in Cisco Packet Tracer; `.pcapng` captures open in Wireshark.
- The study notes in `Notes` are Markdown and read directly on GitHub.
- You can also download everything as a ZIP from the Live Links table.

## License

Lecture slides, lab manuals, assignment and exam papers, project statements and the textbook belong to their instructors at FAST-NUCES and to their authors and publishers. They are shared here only for learning and revision. My own solutions, notes, code and the way this repository is organised are free to use for study. See [LICENSE](LICENSE).

## Author

**Mohammad Rohaan** – BS Computer Science, FAST-NUCES

- GitHub: [@rohaan2802](https://github.com/rohaan2802)
- Email: [m.rohaanarshad@gmail.com](mailto:m.rohaanarshad@gmail.com)

If this helped you with Computer Networks, a ⭐ on the repository is appreciated.
