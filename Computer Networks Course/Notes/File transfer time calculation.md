# File Transfer Time and Web Cache Problems

## Problem: File Transfer Time over 4 Intermediate Nodes

Scenario  
- 4 intermediate nodes, each adding 30 ms of processing
per packet.  
- Packet size: 1024 bytes.
- File to transfer: 5 000 000 bytes.
- Minimum bandwidth of the link: 2 Mbps.
How many seconds will it take to transfer the file from server to client?  
Assumptions  
Store-and-forward switching with pipelining (normal for packet switching).  
No propagation delay given, so we ignore it.  
1 byte = 8 bits, 1 Mbps = 1,000,000 bits/s.  
Step 1 — Number of packets  
File size = 5,000,000 bytes, packet size = 1024 bytes Number of packets = ceil(5,000,000 / 1024) = 4883 packets.  
Step 2 — Times per packet  
Packet size in bits = 1024 × 8 = 8192 bits.  
Link bandwidth = 2 Mbps = 2,000,000 bits/s.  
Transmission time per packet,  
Processing time at each intermediate node = 30 ms = 0.03 s. There are 4 intermediate nodes.  
Step 3 — First-packet (pipeline fill) delay First packet must traverse 5 links and be processed at 4 intermediate nodes, so Step 4 — Steady-state packet spacing (throughput) Pipeline stage times alternate between transmission (4.096 ms) and processing (30 ms).  
The bottleneck (largest stage) is processing (30 ms). So after the pipeline fills, one packet arrives every 30 ms (0.03 s).  
Total time = time for first packet + (N − 1) × steady spacing:  
Final answer  
≈ 146.60 seconds (about 2 minutes 26.6 seconds).  
propagation delays if you provide them.  
tx  
8192/2,000,000 = 0.004096 s = 4.096 ms first  
5 ⋅t  
tx  
4 ⋅t  
proc  
5(0.004096) + 4(0.03) = 0.02048 + 0.12 = 0.14048 s.  
T = 0.14048 + (4883 −1) × 0.03 = 0.14048 + 4882 × 0.03 = 0.14048 + 146.46 = 146.60048 s.  

## Why the First Packet Is Multiplied by 5

When we calculated the first-packet delay, I multiplied transmission time ( ) by 5.  
Path from server → client  
We have 4 intermediate nodes (routers/switches).  
That means 5 links in total:  

### 1. Server → Node 1

### 2. Node 1 → Node 2

### 3. Node 2 → Node 3

### 4. Node 3 → Node 4

### 5. Node 4 → Client

So the first packet must be transmitted once per link.  
That’s 5 transmissions, each costing  
Processing  
At each of the 4 intermediate nodes, the packet incurs processing delay = 30 ms.  
So we add  
Therefore  
t_{\text{first packet}} = (\text{#links}) \times t_{tx} + (\text{#nodes}) \times t_{proc} = 5t_{tx}  
- 4t_{proc}.
That’s why I multiplied by 5.  
the network was using cut-through switching (where processing overlaps with transmission)?  
tx  
tx  
4 × t  
proc  

## Adding One Node Each Time

Not exactly  — let me phrase it carefully.  
We don’t add a node each time. What we add depends on whether we’re counting links or nodes:  
Links (transmission)  
Every packet must be transmitted across each link.  
If you have  
intermediate nodes:  
Links =  
Example: 4 nodes → 5 links (server → node1, node1 → node2, …, node4 → client).  
That’s why in the first-packet delay we had 5 × transmission time.  
Nodes (processing)  
Only intermediate nodes add processing delay.  
Server and client usually don’t count (they just send/receive).  
So: #processing delays = #nodes.  
Example: 4 nodes → 4 × processing time.  
Formula for first-packet delay  
where  
= number of intermediate nodes  
= transmission delay per link  
= processing delay per node  
So you don’t add an extra “node” each time — you just count:  
links for transmission,  
nodes for processing.  
nodes, file size  
, and packet size  
)? That way you can apply it directly to any scenario.  
N + 1  
first  
(N + 1) ⋅t  
tx  
N ⋅t  
proc  
tx  
proc  

## Why Later Packets Do Not Need N+1 Node Times

First packet  
The first packet has to “open the road”:  
It must go through all  
links sequentially,  
And through all  
intermediate processing steps.  
That’s why the first packet delay is big:  
Subsequent packets (why they don’t wait for full path each time) Once the first packet has entered Node 1, the link between server → Node 1 becomes free again.  
At that moment, the server can start transmitting packet 2, While packet 1 is moving between Node 1 → Node 2.  
This overlapping is called a pipeline — like an assembly line in a factory.  
So after the pipeline is “full,”  
Every packet st  
The slowest stage (the bottleneck: either transmission or processing) determines how often a new packet arrives at the client.  
That’s why subsequent packets are separated by only:  
not by the full  
Analogy  
Imagine 5 toll booths (links) and 4 security checks (processing).  
The first car (packet 1) must stop at each booth + check → takes a long time.  
But once the first car has moved to booth 2, booth 1 is free for car 2.  
Soon, all booths/checks are busy with different cars. After that, one car exits every fixed interval (the slowest booth time).  
So:  
First packet = full path delay.  
Other packets = only separated by the bottleneck stage delay, because of pipelining.  
packets overlap across links and nodes? That usually makes it super clear.  
N + 1  
first  
(N + 1)t  
tx  
Nt  
proc  
spacing  
max(t  
, t  
tx  
proc  
(N + 1)t  
tx  
Nt  
proc  

## Is the First Packet Used for a Handshake?

Not exactly  — the first packet delay we are calculating here is not a handshake (like TCP’s 3-way handshake).  
It’s simply the time it takes for the very first data packet to physically make it all the way from the server → client, crossing all links and intermediate nodes.  
Difference:  
Handshake = extra control packets (like SYN, SYN-ACK, ACK in TCP) exchanged before data transfer begins. That’s a protocol overhead.  
First-packet delay in our calculation = even if the network is ready and no handshake is needed, the first data packet still has to cross the entire path before the pipeline fills up.  
Why it matters:  
First packet = sets up the pipeline (assembly line).  
Later packets benefit from pipelining (so they don’t take the full end-to-end delay individually).  
If a handshake were required (e.g., TCP), you’d add its cost before this delay.  
So the first packet isn’t a handshake — it’s just the “pipeline warm-up.” (3 packets) was included before file transfer?  

## Problem: Web Cache Utilisation and Delay

Suppose an institutional network has the following parameters:  
- Access link rate = 2 Mbps
- Average object size = 200 Kbits
- Average request rate from all browsers = 10 requests/sec
- RTT to the origin server = 1.5 sec and LAN delay is low
(10ms).  
With local web cache: Cache hit rate = 50% (all other requests go to the origin server).  
Ignore queueing when utilization ≤ 0.8 but assume queueing delays infinite when  
utilization > 0.9.  
Without Cache With Cache  
Average access link utilization  
Average request delay  
Delay = Internet delay (RTT) + Access link transmission delay.  
Given  
Access link rate  
Average object size  
Aggregate request rate  
RTT to origin  
LAN delay (cache hit)  
Cache hit rate = 50% → miss rate = 0.5 Transmission delay per object over access link:  

### 1) Average access-link utilization

Utilization  
Without cache: every request goes over the access link, so traffic = bits/s.  
With cache (50% hit): only misses go to origin, traffic = bits/s.  

### 2) Average request delay

The problem statement gives:  
Delay = Internet delay (RTT) + Access link transmission delay for requests that go to origin. Cache hits use local/LAN delay.  
First compute the per-case delays:  
Miss (to origin):  
Hit (from cache):  
Average delay with hit rate  is  
Important queuing rule given  
Ignore queueing when utilization ≤ 0.8.  
If utilization > 0.9, assume queueing delays are infinite.  
Apply these rules:  
Without cache:  
Per the rule, queueing delay → infinite, so the average request delay is effectively infinite (system overloaded).  
— (If you ignored that special rule and computed only RTT+tx per request, each request to origin would be  
s, but the given policy forces infinite delay when With cache:  
. Queueing ignored, so use average of hit/miss delays:  
Final table (summary)  
Scenario  
Access-link utilization  
Average request delay  
Without cache  
100% (1.0)  
Infinite (utilization > 0.9)  
With cache  
50% (0.5)  
0.805 s (≈ 805 ms)  
change for different cache hit rates)?  
R = 2 Mbps = 2,000,000 bits/s  
S = 200 Kbits = 200,000 bits  
λ = 10 requests/s  
= 1.5 s  
= 10 ms = 0.01 s  
tx  
2,000,000  
200,000  
0.1 s = 100 ms.  
U =  
traffic on access link (bits/s)  
λ ⋅S = 10 ⋅  
200,000 = 2,000,000  
no cache  
2,000,000  
2,000,000  
1.0 (100%).  
λ ⋅miss_rate ⋅S = 10 ⋅  
0.5 ⋅200,000 = 1,000,000  
with cache  
2,000,000  
1,000,000  
0.5 (50%).  
miss  
RTT + t  
tx  
1.5 + 0.1 = 1.6 s.  
hit  
LAN delay = 0.01 s.  
avg  
h ⋅D  
hit  
(1 −h) ⋅D  
miss  
no cache  
1.0 > 0.9  
1.6  
U >  
0.9  
with cache  
0.5 ≤0.8  
with cache  
0.5 ⋅0.01 + 0.5 ⋅1.6 = 0.005 + 0.8 = 0.805 s.  

## Problem: Protocol Design for a Real-Time VR Game

Part 2 (2 Marks)  
You are tasked with designing a new application-layer protocol for a real-time  
multiplayer VR game. This protocol must support:  
- Low-delay communication (on the order of tens of
milliseconds).  
- High bandwidth fluctuations (due to both video streams
and frequent positional  
tracking updates).  
- Authentication and encryption for all sessions.
- No strict reliability guarantees for continuous
position/video updates, but some gamecritical control data (e.g., match events, inventory changes) must be reliably  
delivered.  

### 1. Which transport protocol (TCP, UDP, UDP with TLS, TCP

with TLS, or  
a combination (hybrid) of protocols) would you use and why?  

### 2. How should the state be maintained between client and

server sessions (cookies vs  
server-managed state vs stateless) and why?  
Protocol(s) Why?  
style clarity  

### 1. Transport Protocol Choice

Requirements:  
Low delay (~tens of ms): TCP can introduce head-of-line blocking → bad for real- time.  
High bandwidth fluctuations: Must adapt quickly. UDP is lighter.  
Authentication & encryption: Needed, so plain UDP not enough → use DTLS (Datagram TLS) or equivalent.  
Mixed reliability:  
Continuous streams (video/position) → tolerate some packet loss, don’t need retransmissions.  
Critical control data (events, inventory) → must be reliably delivered.  
Best fit: Hybrid  
UDP + DTLS (encrypted, low-latency) for real-time position & video.  
TCP + TLS (reliable, secure) for occasional game-critical control data.  

### 2. Session State Maintenance

Requirements:  
Multiplayer VR → continuous interaction → server must track player state, positions, inventory, etc.  
Stateless (like HTTP) or cookies won’t work — too much per-packet overhead, too slow.  
Server-managed session state is better:  
Client sends minimal identifiers (session token).  
Server holds authoritative game state.  
Supports authentication, prevents tampering.  
Best fit: Server-managed state.  
Final Answer (Tabular Form)  
Protocol(s)  
Why?  
UDP with DTLS (for  
position/video) + TCP  
with TLS (for control data)  
UDP ensures low latency and tolerance for packet loss in real-time updates; DTLS secures those packets. TCP ensures reliable delivery for critical game events, TLS secures them.  
Server-managed state  
Centralized authority ensures consistency, security, and scalability. Clients only keep session tokens; server maintains full session/game state.  
which data travels over UDP vs TCP in a session diagram)? That would make it crystal clear for presentation.  

## Problem: MEDIX Lab Network

Consider that you are working on one of the lab systems of MEDIX software house having a LAN network with 350 Mb/s transmission rate to institutional Router 1, for which there is an institutional network connected to the Internet.  
Suppose that the average object size is 250,000 bits and that the average request rate from the Lab’s browsers to the origin servers is 35 requests per second.  
Also suppose that the amount of time it takes from when the router on the Internet side (Router 2) of the access link forwards an HTTP request until it receives the response is 2.5 seconds on average. Model the total average response time as the sum of the average access delay (that is, the delay from Router 2 to Router 1) and the average Internet delay.  
i. Find the total average response time. [4] ii. Now suppose that a web cache is installed on the MEDIX Lab network’s LAN. Suppose that the miss rate is 0.7. Find the total response time (considering that the response time from the cache is 0.01 sec) [6]  
a) Find the total average response time.  
L= 250, 000 Bits  
R = 500 * 10^6 bits/ sec  
a= 35  
Cache response = 0.01 sec  
Internet delay = 2.5 sec  
Average Transmission Delay = Ttrans = L / R = 0.25 * 10^6 / 500 * 10^6  
= 0.0005 sec  
Traffic Intensity on the access Link = Ttrans * a = (0.0005) *  
35 = 0.0175  
The average access delay is = Ttrans / (1-Traffic intensity) = 0.0005 / (1- 0.0175)  
= 0.0005 sec  
Final average response time = 0.0005 + 2.5 = 2.5005 sec b) with installed cache  
The average access delay is (70 % for cache miss) Average Access delay = (0.0005 sec) / [1 – (0.7) (0.0175)] = 0.0005 seconds  
Average Response Time = 0.0005 sec + 2.5 sec =2.5005 sec  
For Cache Hit (30 %)  
The response time is approximately .01 sec if the request is satisfied by the cache  
Average Access delay = 0.3 * 0.01 =0.003 sec Final Average Response Time = (0.3)(0.01) + (0.7) (2.5005) = 1.75335 sec  
Thus, the average response time has been reduced from 2.5005 sec to 1.75335 s  
You made the right modeling choices (M/M/1-style access-link delay  
where  
), but there were two small slips to correct:  

### 1. In your intermediate step you left the access delay equal to

instead of computing  
. With the small but nonzero utilization  that slightly increases the access delay.  
2. Also the problem text earlier said the LAN → Router1 link is 350 Mb/s, but in your working you used  
Mb/s.  
Given / model  
bits (object size)  
requests/sec  
Internet delay = 2.5 s (round-trip from Router2’s forwarded request to response) Cache response = 0.01 s (when hit)  
Cache miss rate = 0.7 (so hit rate = 0.3) Service time (transmission)  
Access-link delay (M/M/1)  
where  
Total response time (no cache) =  
Internet delay.  
With cache: cache hits return in 0.01 s; misses incur access delay + Internet delay.  
A — If the link rate is 350 Mb/s (use this if following the problem statement)  

### 2. No cache

Total response  

### 3. With cache (miss rate 0.7, hit rate 0.3)

For misses: arrival rate =  
Average response  
B — If you instead use 500 Mb/s (your numbers)  

### 2. No cache

Total response  

### 3. With cache

Average response  
Short summary / correction  
Your final answers (≈ 1.75335 s and 1.75351 s) are essentially correct — the tiny differences come from the  
you pick (350 vs 500 Mb/s) and from rounding.  
The small arithmetic mistake in your working was not applying the factor  
explicitly (you used  
directly). For these tiny utilizations the correction is small but it is required by the M/M/1 formula.  
Re-run these with more significant digits, or Produce a one-line formula you can paste into your answer sheet, or Make a tiny table showing results for a range of cache miss rates (e.g., 0.1 → 0.9) so you can see sensitivity. Which  
1 −ρ  
tx  
ρ = λT  
tx  
tx  
/(1 −  
tx  
ρ)  
R = 500  
L = 250,000  
λ = a = 35  
tx  
L/R  
access  
1 −ρ  
tx  
ρ = λT  
tx  
access  
R = 350 × 10  b/s  
tx  
350 × 106  
0.0007142857 s  
ρ = 35 × 0.0007142857 = 0.025  
access  
1 −0.025  
0.0007142857  
0.00073236 s  
= 2.5 + 0.00073236 ≈2.500732 s  
35 × 0.7 = 24.5 req/s  
miss  
24.5 × 0.0007142857 = 0.0175  
access,miss  
1 −0.0175  
0.0007142857  
0.00072750 s  
= 0.3 × 0.01 + 0.7 × (2.5 + 0.00072750) ≈0.003 + 1.75050925 = 1.75351 s  
R = 500 × 10  b/s  
tx  
250000/500 × 10 =  
0.0005 s  
ρ = 35 × 0.0005 = 0.0175  
access  
0.0005/(1 −0.0175) ≈0.00050889 s  
= 2.5 + 0.00050889 ≈2.500509 s  
miss  
24.5 × 0.0005 = 0.01225  
access,miss  
0.0005/(1 −0.01225) ≈0.00050621 s  
= 0.3 × 0.01 + 0.7 × (2.5 + 0.00050621) ≈1.75335 s  
1/(1 −ρ)  
tx  

## Hit Delay and Miss Delay Formulas in Terms of La/R

= access link rate (bits/sec)  
= aggregate request rate (req/sec)  
Step 1 — Transmission time per object  
Step 2 — Traffic intensity  
Step 3 — Average access delay (M/M/1 queue formula) Step 4 — Delays  
Cache hit delay:  
Response comes directly from LAN cache, so (It does not depend on  
because the access link is bypassed.)  
Cache miss delay:  
Must traverse the access link plus incur Internet delay. So:  
Final formulas (in terms of  
rate  
, like:  
tx  
ρ = a ⋅  
aL  
access  
1 −ρ  
tx  
1 −  
aL  
hit  
(often given as 0.01 s)  
LAN  
L, a, R  
miss  
access  
Internet  
1 −  
aL  
Internet  
L, a, R  
≈T  
hit  
LAN  
- D
miss  
1 −  
aL  
Internet  
avg  
(1 −m)D  
hit  
mD  
miss  

## SMTP and Email Protocols in Short

Here’s a short and clear description:  
SMTP (Simple Mail Transfer Protocol)  
Purpose: Used to send and forward emails between mail servers.  
Type: Application-layer protocol, text-based, uses TCP (port 25 by default).  
Direction: Client → Server (sending mail) and Server → Server (relaying mail).  
Limitation: SMTP only handles sending, not retrieving emails.  
Email Retrieval Protocols  

### 1. POP3 (Post Office Protocol v3)

Downloads email from the server to the client.  
Default port: 110.  
Typically deletes mail from the server after download (unless configured to keep a copy).  
Simple, but not good for accessing the same mailbox from multiple devices.  

### 2. IMAP (Internet Message Access Protocol)

Lets you read/manipulate mail directly on the server.  
Default port: 143.  
Supports multiple folders, synchronization across devices.  
Better for modern email clients with multi-device access.  
Summary  
SMTP = for sending mail.  
POP3/IMAP = for retrieving mail (POP3 = simple download, IMAP = server-synced).  
quick revision sheet?  

## What TTL Is

Let me explain simply:  
TTL (Time To Live)  
Definition: TTL is a field in the IP packet header that specifies how many hops (routers) the packet can pass through before being discarded.  
Purpose: Prevents packets from looping infinitely in the network if there’s a routing error.  
How it works:  
TTL is set by the sender (e.g., 64, 128, or 255).  
Each router that forwards the packet decrements TTL by 1.  
When TTL = 0 → the packet is discarded, and usually an ICMP “Time Exceeded” message is sent back to the sender.  
Uses:  
Traceroute command relies on TTL → it sends packets with increasing TTL to discover each hop on the path.  
Helps avoid network congestion from stuck packets.  
In short:  
TTL = "packet lifetime" in terms of hops.  
If not expired, packet reaches destination.  
If expired, packet is dropped.  
there with a different meaning.  

## IP Spoofing vs Packet Sniffing

IP Spoofing  
What it is: Pretending to be someone else’s IP address.  
How: The attacker forges the source IP in a packet to trick the receiver into thinking it came from a trusted device.  
Goal: Bypass security, impersonate a machine, or hide identity (often used in DDoS attacks).  
Analogy: Writing a fake return address on an envelope.  
Packet Sniffing  
What it is: Secretly “listening” to network traffic.  
How: The attacker (or admin) uses special software/tools (like Wireshark) to capture data packets flowing through a network.  
Goal: Steal sensitive info (passwords, emails) or monitor network activity.  
Analogy: Eavesdropping on a phone call.  
In short:  
IP Spoofing = faking identity (sending from a fake IP).  
Packet Sniffing = spying (reading other people’s packets).  
revision?  
ip spoofing  
IP Spoofing  
Definition: IP spoofing is when an attacker fakes the source IP address in a network packet so that it looks like it came from a trusted machine instead of the attacker’s device.  
How it works:  

### 1. Normally, a packet has your real IP in the source field.

### 2. In spoofing, the attacker changes this source field to another IP.

### 3. The receiver thinks the packet came from that fake IP.

Why attackers use it:  
To hide their identity.  
To bypass security filters that trust certain IPs.  
To launch DDoS attacks (sending tons of fake requests from spoofed IPs).  
To trick victims into sending replies to the wrong machine.  
Analogy: Imagine you send a letter but write your friend’s name and address instead of yours. The receiver thinks your friend sent it, not you.  
In short:  
IP Spoofing = faking your “From Address” in Internet communication to deceive others.  
non-blind spoofing, DoS spoofing) with examples?
