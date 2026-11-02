# Network Performance Overview

## Lecture Notes: Throughput, Security and Delay

Throughput: network scenario  
10 connections (fairly) share  
backbone bottleneck link R bits/sec  
Rs  
Rs  
Rs  
Rc  
Rc  
Rc  
per-connection end-end  
throughput:  
min(Rc,Rs,R/10)  
in practice: Rc or Rs is  
often bottleneck  
- Check out the online interactive exercises for more
examples: http://gaia.cs.umass.edu/kurose_ross/ Overview/roadmap:  
Network core: packet/circuit  
switching, internet structure  
Performance: loss, delay, throughput  
Security  
Protocol layers, service models  
History  
Network security  
Internet not originally designed with (much) security in mind  
original vision: “a group of mutually trusting users attached to a  
transparent network”  
Internet protocol designers playing “catch-up” security considerations in all layers!  
We now need to think about:  
how bad guys can attack computer networks how we can defend networks against attacks how to design architectures that are immune to attacks Bad guys: packet interception  
packet “sniffing”:  
broadcast media (shared Ethernet, wireless) promiscuous network interface reads/records all packets (e.g., including  
passwords!) passing by  
src:B dest:A payload  
Wireshark software used for our end-of-chapter labs is a (free) packet-sniffer  
Bad guys: fake identity  
IP spoofing: injection of packet with false source address src:B dest:A payload  
Bad guys: denial of service  
target  
Denial of Service (DoS): attackers make resources (server, bandwidth) unavailable to legitimate traffic by overwhelming  
resource with bogus traffic  

### 1. select target

### 2. break into hosts around

the network (see botnet)  

### 3. send packets to target from

compromised hosts  
sheet + worked examples +  
A probe packet is a deliberately sent packet (usually small) used to measure properties of a network path or device — e.g. round-trip time (RTT), loss, available bandwidth, or the sequence of routers (traceroute). Examples:  
ping uses ICMP echo request/response probe packets to measure RTT and loss.  
traceroute sends UDP/ICMP/TTL-limited probes with increasing TTL to discover intermediate routers and per-hop delays.  
Bandwidth estimation tools send probe streams and measure arrival spacing to infer bottleneck capacity.  
Formula sheet — core network performance formulas (Short name, formula, what each symbol means)  

### 1. Transmission delay

L = packet length (bits), R = link transmission rate (bits/sec).  

### 2. Propagation delay

d = link length (meters), s = propagation speed (~2×10^8 m/s in copper/fiber).  

### 3. Nodal (per-hop) delay

d_proc = processing delay; d_queue = queuing delay.  

### 4. End-to-end delay (sum of nodal delays across path)

### 5. Bandwidth–delay product (BDP)

Interprets how many bits “in flight” f R = bottleneck rate, RTT = round-trip time.  

### 6. Per-connection throughput in the 10-flow example (from your slide)

R_c = client access rate, R_s = server access rate, R = backbone bottleneck; shares equally among 10 flows.  

### 7. Transmission link utilization (simple)

If arrival rate of packets is λ (packets/sec) and each packet size is L bits:  
ρ is fraction of time link is busy (servers/queues: ρ < 1 for stable queue).  

### 8. Little’s Law (queueing)

L = average number in system, λ = arrival rate, W = average waiting (system) time.  
9. TCP congestion-control (approximate) — long-lived TCP throughput vs loss  
MSS = max segment size (bytes), p = packet loss probability (loss fraction), RTT in seconds. (This is an approximation for TCP Reno’s steady-state throughput.)  

### 10. Packet loss rate (empirical)

\text{loss\_rate} = \frac{\text{# lost packets}}{\text{# sent packets}} Worked examples (step-by-step)  
Example 1 — per-connection throughput (uses your slide formula).  
Given: 10 connections share a backbone R = 50 Mbps. Each client access link R_c = 10 Mbps, server access link R_s = 8 Mbps. What is per-connection end-to-end throughput?  
Compute R/10 = 50 Mbps / 10 = 5 Mbps. So per-connection throughput = min(R_c, R_s, R/10) = min(10, 8, 5) Mbps = 5 Mbps.  
Example 2 — transmission + propagation + RTT.  
Link: L = 10,000 bits packet, R = 2 Mbps, distance d = 2,000 km, propagation speed s = 2×10^8 m/s (≈200,000 km/s). Single link RTT (assume return propagation same, ignore processing/queueing):  
d_trans = L / R = 10,000 bits / (2×10^6 bits/s) = 0.005 s = 5 ms.  
d_prop one way = 2,000 km / 200,000 km/s = 0.01 s = 10 ms.  
RTT ≈ 2*(d_trans + d_prop) = 2*(5 ms + 10 ms) = 30 ms.  
Example 3 — bandwidth delay product.  
If bottleneck R = 10 Mbps and RTT = 80 ms:  
BDP = 10×10^6 bits/s * 0.08 s = 800,000 bits = 100,000 bytes.  
So to fully utilize the link you need ~100 KB of outstanding data.  
Practice problems (with short answers) — for each main topic  
A. Throughput sharing / bottleneck  
1. (P1) A backbone link R = 100 Mbps is shared fairly by 20 identical TCP connections.  
Server links R_s = 200 Mbps (not limiting), each client access R_c = 10 Mbps. What is per-connection throughput?  
Answer: R/20 = 5 Mbps (min(10,200,5) = 5 Mbps).  
2. (P2) Same as (P1) but 5 clients have R_c = 2 Mbps while rest have R_c = 20 Mbps. If sharing is fair, what is throughput for a low-rate client and high-rate client?  
Short guide: Bottleneck is R/20 = 5 Mbps. Low-rate clients can’t exceed 2 Mbps, so low clients get 2 Mbps; high clients share remaining capacity (100 − 5×2 = 90) among 15 high clients → 6 Mbps each, but capped by their R_c=20 Mbps so 6 Mbps.  
B. Delay components  
3. (P3) A 1200-byte packet traverses 3 identical links, each R = 5 Mbps and each link length 300 km. Propagation speed 2×10^8 m/s. Processing per router 0.5 ms, ignore queueing. Find end-to-end delay.  
Answer steps: L=1200 bytes=9600 bits; d_trans = 9600/5e6 = 0.00192 s = 1.92 ms per link. d_prop per link = 300,000 m / 2e8 m/s = 1.5 ms. For 3 links: total trans = 3×1.92=5.76 ms; total prop = 3×1.5 = 4.5 ms; processing at 2 intermediate routers + sender? If 2 routers ×0.5 ms =1.0 ms. Total ≈ 11.26 ms.  
4. (P4) If queueing suddenly adds 20 ms on link 2 (one hop), what is new end-to-end delay? Add 20 ms → ~31.26 ms.  
C. Bandwidth–Delay Product  
5. (P5) If RTT = 120 ms and R = 25 Mbps, how many 1500-byte packets fit in flight?  
Answer: BDP = 25e6 * 0.12 = 3,000,000 bits ≈ 375,000 bytes; packets = 375,000 / 1500 ≈ 250 packets.  
D. Probe packets / measurement  
6. (P6) You send 100 ICMP pings; 3 do not return. What’s loss rate?  
Answer: 3/100 = 3%.  
7. (P7) Using traceroute you see an increase in RTT at hop 4. What could that indicate?  
Answer: A congested router or link at/after hop 4, or an overloaded interface causing queueing; or it could be ICMP deprioritization — interpret carefully.  
E. TCP throughput (loss limited)  
8. (P8) MSS = 1460 bytes, RTT = 50 ms, measured packet loss p = 0.01 (1%). Estimate  
TCP throughput (approx).  
Solution: throughput ≈ 1.22MSS/(RTTsqrt(p)) = 1.221460 bytes / (0.05 s * sqrt(0.01)) sqrt(0.01)=0.1 → denom = 0.050.1=0.005 → numerator = 1.22*1460 ≈ 1781 bytes ≈ 14,248 bits. throughput ≈ 14,248 / 0.005 ≈ 2,849,600 bps ≈ 2.85 Mbps.  
Suggested further practice problems (no answers — try solving)  
1. A streaming server can send at up to 30 Mbps. 6 clients each have access links 8 Mbps. If all request a continuous stream simultaneously, what is fair per-client throughput? If one client’s link is only 1 Mbps, how does allocation change?  
2. A path consists of 4 links with rates 10, 5, 2, 8 Mbps. What is the path bottleneck, and what effect does that have on throughput for a single flow? If 8 identical flows share the path, what is per-flow throughput (assuming equal share at bottleneck)?  
3. Measure the BDP for a satellite link: RTT = 600 ms, capacity = 50 Mbps. How much window (in KB) must TCP keep to fully utilize the link?  
4. Design an experiment using ping/traceroute to detect which hop is introducing 30 ms of extra delay: what probes, intervals, and interpretation would you use?  
Short checklist for analyzing real network measurement problems  
Identify bottleneck (smallest capacity along path).  
Compute transmission (L/R) and propagation (d/s) delays separately.  
Use BDP to reason about how much outstanding data is needed.  
For throughput with many flows, use fair-share model: per-flow ≈ min(access rates, bottleneck capacity / #flows).  
For TCP, remember loss & RTT dominate achievable steady throughput (use TCP formula as a guide).  
When probing: repeat measurements (statistically), watch for ICMP deprioritization and cross-traffic variability.  
Generate 10 more graded practice problems with full solutions, or Walk through any one practice problem step-by-step.  
Which of those  
trans  
prop  
nodal  
proc  
queue  
trans  
prop  
e2e  
i=1  
nodal,i  
BDP = R × RTT  
throughput  
per connection  
min(R  
, R  
s 10  
ρ =  
λ ⋅L  
L = λ ⋅W  
TCP_throughput ≈  
RTT ⋅  
1.22 ⋅MSS  
(P2) Same as (P1) but 5 clients have R_c = 2 Mbps while rest have R_c = 20 Mbps. If sharing is fair, what is throughput for a low-rate client and high-rate client?  
Short guide: Bottleneck is R/20 = 5 Mbps. Low-rate clients can’t exceed 2 Mbps, so low clients get 2 Mbps; high clients share remaining capacity (100 − 5×2 = 90) among  
15 high clients → 6 Mbps each, but capped by their R_c=20 Mbps so 6 Mbps.  
explain this  
the reasoning behind that short  
guide.  
Problem restated  
Backbone bottleneck capacity:  
20 total clients (flows) share fairly  
5 clients have access link rate  
(low-rate clients)  
15 clients have access link rate  
(high-rate clients)  
We want the actual throughput for a low-rate client and for a high-rate client.  
Step 1 — Fair share ignoring access rates If everyone were equal and had no bottlenecks at the edge, the fair share of backbone capacity would be:  
So, ideally, every client would get 5 Mbps.  
Step 2 — Apply client access link limits But:  
Low-rate clients have  
, so they can’t reach 5 Mbps. They max out at  
2 Mbps.  
Each low-rate client therefore uses only 2 Mbps.  
Step 3 — Remaining capacity after serving low-rate clients Each of the 5 low clients consumes 2 Mbps → total = Backbone was 100 Mbps, so remaining capacity is:  
Step 4 — Redistribute leftover among high-rate clients Now 15 high-rate clients share this leftover 90 Mbps.  
Fair share =  
Check:  
Each high-rate client’s access link is  
6 Mbps < 20 Mbps → not constrained.  
So each high-rate client really gets 6 Mbps.  
Final Answer  
Low-rate clients: 2 Mbps each (limited by their access link).  
High-rate clients: 6 Mbps each (limited by fair share of remaining backbone).  
The key idea is:  

### 1. Start with backbone fair share.

2. Cap flows that can’t reach fair share (due to their own link limit).  

### 3. Redistribute the freed capacity among the others.

these mixed-client fair-sharing problems (so you won’t have to reason from scratch every time)?  
R = 100 Mbps  
2 Mbps  
20 Mbps  
5 Mbps  
2 Mbps  
5 × 2 = 10 Mbps  
100 −10 = 90 Mbps  
6 Mbps  
20 Mbps  

## Fair Throughput for a Streaming Server

1 — Streaming server (30 Mbps) with 6 clients (8 Mbps each)  
Given: server capacity  
Mbps, 6 clients with access  
Mbps each.  
Fair per-client share of server capacity = Calculate:  
Mbps.  
Compare with client access (8 Mbps). Each client can accept 8 Mbps, which is higher than 5 Mbps, so the server bottleneck determines throughput.  
Answer: each client gets 5 Mbps.  
If one client’s link is only 1 Mbps  
Now one client is limited to 1 Mbps; the other 5 clients have 8 Mbps.  
Step 1 — the low-rate client uses 1 Mbps.  
Step 2 — remaining server capacity:  
total server = 30 Mbps  
used by low client = 1 Mbps  
leftover =  
Mbps.  
Step 3 — split leftover among the remaining 5 clients:  
Mbps per high-rate client.  
Check access limits: high clients have 8 Mbps access, and , so no further cap.  
Answer: low client = 1 Mbps; each other client = 5.8 Mbps.  
2 — Path with link rates [10, 5, 2, 8] Mbps  
Given link rates: 10 Mbps, 5 Mbps, 2 Mbps, 8 Mbps.  
The path bottleneck = the minimum link rate = Mbps.  
Effect for a single flow: a single flow cannot exceed the bottleneck, so maximum throughput = 2 Mbps.  
If 8 identical flows share the path (equal share at bottleneck):  
Bottleneck capacity = 2 Mbps total for flows.  
Per-flow throughput =  
Mbps =  
kbps.  
Answer: bottleneck = 2 Mbps; single flow ≤ 2 Mbps; with 8 flows each ≈ 0.25 Mbps (250 kb/s).  
3 — BDP for satellite link (RTT = 600 ms, capacity =  
50 Mbps)  
Given: RTT  
ms  
s, capacity  
Mbps  
bits/s.  
Bandwidth–delay product:  
Convert bits → bytes:  
Convert bytes → kilobytes (KB, using 1024 bytes per KB):  
Convert to megabytes (MB, 1024 KB per MB):  
Round for practical answer.  
Answer: BDP ≈ 30,000,000 bits = 3,750,000 bytes ≈ 3,662 KB (≈ 3.58 MB).  
So TCP needs a window of roughly 3.7 million bytes (~3.6 MB) (≈ 3,662 KB) to fully fill the pipe.  
4 — Experiment design using ping / traceroute to find the hop adding ~30 ms delay  
Goal: find which hop introduces ~30 ms extra delay consistently.  
Tools: traceroute (or tracert on Windows), ping to intermediate IPs, repeat measurements.  
Experiment steps (practical, repeatable):  

### 1. Run traceroute several times.

Command (Unix): traceroute -I <destination> (ICMP) or traceroute -n <destination> to avoid DNS lookups.  
Run it 10 times spaced 2 seconds apart (e.g., a short script loop).  
Record per-hop RTTs reported for each run.  

### 2. Look for a hop where RTT increases suddenly.

For each traceroute run, compute per-hop incremental delay:  
incremental delay from hop i to i+1 ≈ RTT(i+1) − RTT(i).  
A consistent jump ≈ +30 ms at the same hop across multiple runs points to that hop/link as the likely source.  

### 3. Ping the suspected hop(s) directly.

From traceroute results note the IP of the hop before and after the jump (call them H_before and H_after).  
Ping H_after directly: ping -c 20 H_after (20 pings, 1 s apart).  
Ping H_before similarly.  
Compare average RTTs and whether the increase appears when pinging H_after vs H_before.  

### 4. Interpretation rules:

If traceroute shows a consistent +30 ms at hop k, and ping to hop k shows similarly high RTTs, that hop (or its outgoing link) is likely adding the delay (queueing or long propagation).  
If traceroute shows +30 ms but direct ping to that router shows low RTT, suspect that the router de-prioritizes ICMP or responds slowly to traceroute probes — the actual data path may not see the same delay. In that case, ping the next hop or test with application-level probes.  
If the large increase appears only intermittently, the problem is likely transient congestion. Check variance and packet loss.  
If packet loss appears at a hop (loss > a few %), and RTT also jumps, that hop is highly suspect.  

### 5. Additional robustness:

Use different probe types (ICMP, UDP, TCP traceroute variants) because some routers treat ICMP/UDP differently.  
Run tests at different times to rule out transient cross-traffic.  
Increase probe rate for short intervals (e.g., 3 probes/second for 30 seconds) to detect bursty congestion, but avoid overloading the network.  

### 6. Summary of a minimal command plan (example):

for i in {1..10}; do traceroute -n -I example.com; sleep 2; done Identify hops with RTT jumps.  
ping -c 20 <suspect-hop-ip>  
mtr -n <destination> (if available) — it combines traceroute+ping and shows history.  
What to watch for in results:  
A consistent incremental jump of ~30 ms at hop k across runs → likely culprit.  
If jump appears only in traceroute but not in pings or application flows → likely ICMP deprioritization (not necessarily a real data-path slowdown).  
Packet loss at same hop + RTT jump → strong evidence of congestion.  
Produce a small shell script you can run to implement this probing plan, or Walk through an example traceroute output and show exactly how to compute the incremental delays and identify the culprit. Which would be most helpful?  
= 30  
= 8  
30 ÷ 6 = 5  
30 −1 = 29  
29 ÷ 5 = 5.8  
5.8 < 8  
min(10, 5, 2, 8) = 2  
2 ÷ 8 = 0.25  
= 600  
= 0.600  
= 50  
= 50,000,000  
BDP = R × RTT = 50,000,000 × 0.6 = 30,000,000 bits.  
30,000,000 ÷ 8 = 3,750,000 bytes.  
3,750,000 ÷ 1024 ≈3,662.109375 KB.  
3,662.109375 ÷ 1024 ≈3.575 MB.  

## ICMP Deprioritization and Cross-Traffic Variability

Short explanations — ICMP deprioritization & cross- traffic variability (with what they mean for measurements)  
ICMP deprioritization  
What it is:  
Many routers and middleboxes handle ICMP (ping/traceroute) messages at lower priority than normal data forwarding — or they rate-limit or even drop ICMP replies. This is done for security and to avoid CPU overload from probe floods.  
Why it matters for measurements:  
A traceroute hop may show a large RTT or packet loss because the router delays or drops the ICMP reply, not because the router is slow at forwarding real traffic.  
That can create false positives: you might think a link is congested when only the router’s control-plane/ICMP handling is slow.  
How to detect/suspect it:  
The RTT jump appears in traceroute ICMP/UDP probes but application flows (TCP) don’t suffer the same delay.  
Direct ping to that router shows high variance or lost ICMP replies while pinging the next hop or end host shows smaller RTTs.  
Different traceroute probe types give different results (ICMP vs UDP vs TCP).  
How to reduce measurement error:  
Use TCP/UDP-based probes (e.g., traceroute -T or tcptraceroute ) to mimic application traffic.  
Compare multiple probe types. If ICMP shows a jump but TCP doesn’t, trust TCP for application impact.  
Repeat measurements and look for consistent patterns (not single-sample anomalies).  
Use mtr (continuous traceroute) to get time series rather than one-shot traceroutes.  
Cross-traffic variability  
What it is:  
Cross-traffic = all other traffic sharing a link. Cross-traffic variability describes how that traffic changes over time (bursts, diurnal patterns, short spikes). Because queuing delay and loss depend on instantaneous load, variable cross-traffic produces variable delay, loss and available bandwidth.  
Why it matters for measurements & performance:  
Queuing delay (and jitter) rises when cross-traffic increases → measured RTTs and throughput vary.  
Short bursts can cause transient packet loss or throughput drops that one-off probes miss.  
Effective available bandwidth is stochastic, not a single fixed number.  
How to measure / cope with it:  
Repeat measurements over time and report statistics (mean, median, 95th percentile) not just single values.  
Use packet trains or bandwidth-estimation tools that infer available bandwidth from spacing changes — but interpret results cautiously (tools are sensitive to cross-traffic patterns).  
Run tests at different times (peak vs off-peak) to characterize diurnal patterns.  
Look at variance and percentiles (e.g., 5th/95th) to capture worst/best case rather than only averages.  
Quick worked mini-example (ICMP vs TCP effect) Suppose traceroute shows:  
hop 4 RTT = 45 ms  
hop 5 RTT = 78 ms  
incremental = 78 − 45 = 33 ms jump at hop 5.  
If:  
direct ping hop5 returns high RTTs and ping hop4 low RTTs → hop5 likely adding delay.  
but tcptraceroute to destination shows no big jump at that hop → likely ICMP deprioritization at hop5 (router delays ICMP replies), and real TCP flows might not see the 33 ms penalty.  
Which of the next actions  
1.  
2. Generate 10 graded practice problems with full solutions (similar style to earlier problems).  
3.  
Which do you do now?  

## Cheat Sheet and Practice Problems

page Cheat Sheet + Practice  
Problems  
Contents:  
One-page formula / cheat sheet (compact) Key definitions (probe packet, ICMP deprioritization, cross-traffic variability) Short worked examples  
10 graded practice problems with full solutions Detailed step-by-step walkthrough of Problem 9 One-page cheat sheet (compact)  
Delays  
Transmission delay:  
(L = bits, R = bits/s)  
Propagation delay:  
(d = meters, s ≈ 2×10^8 m/s)  
Nodal delay:  
End-to-end delay:  
Bandwidth / throughput  
Per-connection fair-share (simple model):  
(R =  
bottleneck capacity, N = number of active flows) Link utilization:  
(λ = pkts/s, L = bits/packet)  
Bandwidth–Delay Product (BDP)  
(bits in flight to fill the pipe)  
Little's law  
(L = average number in system, W = average time in system) Approx TCP throughput (Reno)  
(bytes/s)  
Practical rules  
Bottleneck = smallest capacity along path — flows limited by bottleneck.  
If some flows are edge-limited (access link smaller than fair share), they free capacity for others — redistribute leftover fairly.  
Repeat measurements to handle cross-traffic variability.  
Key definitions  
Probe packet: a deliberately sent packet (e.g., ping/traceroute probes) used to measure RTT, loss, route, or available bandwidth.  
ICMP deprioritization: routers may process ICMP (ping/traceroute) at lower priority or rate-limit replies — traceroute/ping may show high RTT or loss even when actual data traffic is unaffected.  
Cross-traffic variability: other traffic sharing the link varies over time (bursts, diurnal), producing variable queuing delay, jitter, and available bandwidth.  
Short worked examples  
Example A — Fair share with server bottleneck Server R = 50 Mbps, 10 clients, client access R_c = 10 Mbps → fair share = 50/10 = 5 Mbps (each client capped at 10 Mbps, so each gets 5 Mbps).  
Example B — Transmission + propagation + RTT Packet L = 10,000 bits, R = 2 Mbps, distance d = 2000 km.  
d_trans = 10,000 / 2,000,000 = 0.005 s = 5 ms d_prop (one way) = 2,000,000 m / (2×10^8 m/s) = 0.01 s = 10 ms  
RTT ≈ 2*(5 + 10) ms = 30 ms  
Example C — BDP  
R = 10 Mbps, RTT = 80 ms → BDP = 10×10^6 × 0.08 = 800,000 bits = 100,000 bytes  
10 Graded Practice Problems (with  
full solutions)  
Problem 1 (Easy)  
Q: A streaming server can send at up to 30 Mbps. 6 clients each have access links  
8 Mbps. If all request a continuous stream simultaneously, what is fair per-client throughput?  
Solution: Fair share = 30 / 6 = 5 Mbps. Each client’s access (8 Mbps) > 5 Mbps so each gets 5 Mbps.  
Problem 2 (Easy–Medium)  
Q: Same as P1 but one client’s link is only 1 Mbps (others st How is the  
30 Mbps allocated?  
Solution:  
1. Low client uses 1 Mbps.  
2. Remaining capacity = 30 − 1 = 29 Mbps.  
3. Remaining 5 clients share 29 Mbps → 29 / 5 = 5.8 Mbps each.  
Answer: low client = 1 Mbps, each other client = 5.8 Mbps.  
Problem 3 (Medium)  
Q: Same model as earlier: backbone R = 100 Mbps, 20 clients. 5 clients have access 2 Mbps (low), 15 clients have access 20 Mbps (high). What is per-client throughput for each class?  
Solution:  
1. If equal: fair share = 100 / 20 = 5 Mbps.  
2. Low clients cannot reach 5 Mbps; each low client caps at 2 Mbps.  
3. Low clients total use = 5 × 2 = 10 Mbps. Remaining capacity = 100 − 10 = 90 Mbps.  
4. Remaining 15 high clients share 90 Mbps → 90 / 15 = 6 Mbps each (less than their 20 Mbps access limit).  
Answer: low clients = 2 Mbps each; high clients = 6 Mbps each.  
Problem 4 (Easy)  
Q: A path has link rates [10, 5, 2, 8] Mbps. What is the path bottleneck and how much throughput can a single flow achieve? If 8 identical flows share the path, what is each flow’s throughput (assume equal share at bottleneck)?  
Solution:  
Bottleneck = min(10,5,2,8) = 2 Mbps.  
Single flow ≤ 2 Mbps.  
With 8 identical flows: per-flow = 2 / 8 = 0.25 Mbps = 250 kbps.  
Problem 5 (Easy–Medium)  
Q: Measure the BDP for a satellite link: RTT = 600 ms, capacity = 50 Mbps. How large must the TCP window be (in KB) to fully utilize the link?  
Solution:  
BDP = R × RTT = 50,000,000 bits/s × 0.6 s = 30,000,000 bits.  
Bytes = 30,000,000 / 8 = 3,750,000 bytes.  
KB (1024) = 3,750,000 / 1024 ≈ 3,662.11 KB ≈ 3.58 MB.  
Answer: approximately 3,662 KB (≈ 3.6 MB).  
Problem 6 (Medium)  
Q: A 1200-byte packet traverses 3 identical links. Each link rate R = 5 Mbps, length  
300 km, propagation speed 2×10^8 m/s. Processing at each intermediate router = 0.5 ms. Ignore queueing. Find end-to-end delay.  
Solution:  

### 1. Packet size = 1200 bytes = 1200 × 8 = 9,600 bits.

2. Transmission delay per link = 9,600 / 5,000,000 = 0.00192 s = 1.92 ms.  
3. Propagation per link = 300,000 m / (2×10^8 m/s) = 0.0015 s = 1.5 ms.  
4. For 3 links: total transmission = 3 × 1.92 = 5.76 ms; total propagation = 3 × 1.5 = 4.5 ms.  
5. Processing at intermediate routers: 2 routers × 0.5 ms = 1.0 ms.  
6. Total end-to-end ≈ 5.76 + 4.5 + 1.0 = 11.26 ms.  
Answer: approximately 11.26 ms.  
Problem 7 (Medium)  
Q: Estimate steady-state TCP Reno throughput given MSS = 1460 bytes, RTT = 50 ms, packet loss p = 1%.  
Solution (Padhye/Reno approx):  
Throughput (bytes/s) ≈ (1.22 × MSS) / (RTT × √p).  
Numerator = 1.22 × 1460 = 1,781.2 bytes.  
Denominator = 0.05 s × √0.01 = 0.05 × 0.1 = 0.005.  
Bytes/s ≈ 1,781.2 / 0.005 = 356,240 bytes/s.  
Bits/s = ×8 = 2,849,920 bps ≈ 2.85 Mbps.  
Answer: roughly 2.85 Mbps.  
Problem 8 (Medium — measurement)  
Q: Design an experiment using ping/traceroute to detect which hop is introducing ~30 ms extra delay to a destination. Describe probes, intervals, and interpretation.  
Solution (concise plan):  
1. Run traceroute -n -I <dest> 10 times at 2s intervals; collect per-hop RTTs.  
2. For each run compute incremental RTT per hop: RTT(i+1) − RTT(i). Look for consistent ≈+30 ms increment at same hop.  
3. Ping the suspected hop IP directly with 20 probes ( ping -c 20 ip ) and compare averages.  
4. Use TCP/UDP traceroute ( traceroute -T or tcptraceroute ) to check if ICMP deprioritization is affecting traceroute results.  

### 5. Interpret: consistent jump + ping-confirmation → likely

congestion/propagation; jump only in ICMP traceroute but not TCP → ICMP deprioritization.  
Answer: (plan & interpretation above). Tools: traceroute , mtr , ping , tcptraceroute .  
Problem 9 (Medium — fair-share iterative allocation) Q: Link/server capacity R = 100 Mbps. There are 10 clients: 4 clients with access links 1 Mbps (low), and 6 clients with access links 20 Mbps (high). Compute per- client throughput.  
Solution (step-by-step):  
1. If equal: fair share = 100 / 10 = 10 Mbps — but low clients capped at 1 Mbps.  
2. Low clients total use = 4 × 1 = 4 Mbps.  
3. Remaining capacity = 100 − 4 = 96 Mbps.  
4. Remaining flows = 6 high clients. Per-high-client = 96 / 6 = 16 Mbps (less than their 20 Mbps cap).  
Answer: low clients = 1 Mbps each; high clients = 16 Mbps each.  
Problem 10 (Challenging — M/M/1 queueing approx) Q: A link R = 10 Mbps serves packets of average size 1250 bytes (1,250 × 8 = 10,000 bits). Arrival process average λ = 800 packets/s. Using M/M/1 approximation, compute utilization ρ, average number in system L, and average waiting time W.  
Solution:  
1. Service rate μ (pkts/s) = R / (packet bits) = 10,000,000 / 10,000 = 1,000 pkts/s.  

### 2. Utilization ρ = λ / μ = 800 / 1000 = 0.8.

3. For M/M/1, average number in system L = ρ / (1 − ρ) = 0.8 / 0.2 = 4 packets.  
4. Average time in system W = L / λ = 4 / 800 = 0.005 s = 5 ms.  
Answer: ρ = 0.8, L = 4 pkts, W = 5 ms.  
Detailed step‑by‑step  
walkthrough — Problem 9  
(iterative fair allocation)  
Problem recap: R = 100 Mbps. 4 clients at 1 Mbps, 6 clients at 20 Mbps. Compute per-client throughput.  
Walkthrough (algorithmic):  
1. Compute naive fair share: If every client were unconstrained, fair share = R / N = 100 / 10 = 10 Mbps.  
2. Compare to each client’s access cap: Any client whose access cap < fair share w  
The 4 low clients: cap = 1 Mbps < 10 Mbps → each w  

### 3. Subtract capacity used by capped flows:

Total used by low clients = 4 × 1 = 4 Mbps.  
Remaining capacity = 100 − 4 = 96 Mbps.  

### 4. Redistribute remaining capacity among the remaining (uncapped)

flows:  
Remaining flows = initially 10 − 4 = 6 high clients.  
New fair share for these flows = 96 / 6 = 16 Mbps.  

### 5. Check caps again:

High clients’ caps are 20 Mbps; computed share 16 Mbps ≤ 20 → OK (no more caps).  

### 6. Final allocation:

Low clients: 1 Mbps each. High clients: 16 Mbps each.  
Why this algorithm works: capped (edge-limited) flows free unused capacity which is fairly redistributed among the remaining flows; repeat until no remaining flows are capped.  
Notes & printing  
The cheat-sheet section is intentionally compact for printing on a single page.  
The practice problems and walkthrough give worked examples and deeper practice.  
(single-page cheat sheet + supplemental pages for problems).  
End of document.  
trans  
prop  
nodal  
proc  
queue  
trans  
prop  
e2e  
nodal,i  
T = min(R  
, R  
ρ =  
λL  
BDP = R × RTT  
L = λW  
Throughput ≈  
RTT ⋅  
1.22 ⋅MSS  
Network Performance — One-page Cheat Sheet + Practice Pro Copy  
Edit  
Download  
Done — I created a canvas document titled “Network Performance — One-page Cheat Sheet + Practice Problems”. It contains:  
the printable one-page formula/cheat sheet,  
10 graded practice problems with full step-by-step solutions, and a detailed walkthrough of Problem 9 (iterative fair-share allocation).  
You can open and download the document from the canvas (it’s ready to print or export as  
PDF).  
RTT (Round-Trip Time) = the time it takes for a packet to travel from a source to a destination and back again.  
It’s basically the latency of a round-trip in a network.  
For example:  
If your computer sends a ping (ICMP Echo Request) to a server, and the server replies (ICMP Echo Reply), the total elapsed time is the RTT.  
Why it matters  
TCP throughput depends on RTT (larger RTT → larger required window to fully utilize the link).  
RTT influences perceived responsiveness (e.g., web browsing, gaming, VoIP).  
Tools like ping report RTT in milliseconds.  
Formula (conceptual):  
where each part includes propagation delay + transmission + queuing + processing delays.  
So, if a packet takes 100 ms to reach the server and 100 ms to come back → RTT = 200 ms.  
usually measure RTT instead of one-way)?  
RTT = T  
forward path  
return path
