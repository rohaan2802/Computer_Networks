# Network Performance – Cheat Sheet and Practice Problems

Network Performance — One-page Cheat Sheet + Practice Problems  
Contents: - One-page formula / cheat sheet (compact) - Key definitions (probe packet, ICMP deprioritization, cross-traffic variability) - Short worked examples - 10 graded practice problems with full solutions - Detailed step-by-step walkthrough of Problem 9 One-page cheat sheet (compact)  
Delays - Transmission delay:  
(L = bits, R = bits/s) - Propagation delay:  
(d = meters, s  
≈ 2×10^8 m/s) - Nodal delay:  
- End-to-end delay:
Bandwidth / throughput - Per-connection fair-share (simple model):  
(R = bottleneck  
capacity, N = number of active flows) - Link utilization:  
(λ = pkts/s, L = bits/packet)  
Bandwidth–Delay Product (BDP) -  
(bits in flight to fill the pipe)  
Little's law -  
(L = average number in system, W = average time in system) Approx TCP throughput (Reno) -  
(bytes/s)  
Practical rules - Bottleneck = smallest capacity along path — flows limited by bottleneck. - If some flows are edge-limited (access link smaller than fair share), they free capacity for others — redistribute leftover fairly. - Repeat measurements to handle cross-traffic variability.  
Key definitions  
Probe packet: a deliberately sent packet (e.g., ping/traceroute probes) used to measure RTT, loss, route, or available bandwidth.  
ICMP deprioritization: routers may process ICMP (ping/traceroute) at lower priority or rate-limit replies — traceroute/ping may show high RTT or loss even when actual data traffic is unaffected.  
Cross-traffic variability: other traffic sharing the link varies over time (bursts, diurnal), producing variable queuing delay, jitter, and available bandwidth.  
trans  
prop  
nodal  
proc  
queue  
trans  
dprop  
e2e  
nodal,i  
T = min(R , R ,  
ρ = R  
λL  
BDP = R × RTT  
L = λW  
Throughput ≈RTT ⋅  
1.22 ⋅MSS  
Short worked examples  
Example A — Fair share with server bottleneck - Server R = 50 Mbps, 10 clients, client access R_c = 10 Mbps → fair share = 50/10 = 5 Mbps (each client capped at 10 Mbps, so each gets 5 Mbps).  
Example B — Transmission + propagation + RTT - Packet L = 10,000 bits, R = 2 Mbps, distance d = 2000 km. - d_trans = 10,000 / 2,000,000 = 0.005 s = 5 ms - d_prop (one way) = 2,000,000 m / (2×10^8 m/s) = 0.01 s = 10 ms - RTT ≈ 2*(5 + 10) ms = 30 ms  
Example C — BDP - R = 10 Mbps, RTT = 80 ms → BDP = 10×10^6 × 0.08 = 800,000 bits = 100,000 bytes  
10 Graded Practice Problems (with full solutions) Problem 1 (Easy)  
Q: A streaming server can send at up to 30 Mbps. 6 clients each have access links 8 Mbps. If all request a continuous stream simultaneously, what is fair per-client throughput?  
Solution: Fair share = 30 / 6 = 5 Mbps. Each client’s access (8 Mbps) > 5 Mbps so each gets 5 Mbps.  
Problem 2 (Easy–Medium)  
Q: Same as P1 but one client’s link is only 1 Mbps (others st How is the 30 Mbps allocated?  
Solution: 1. Low client uses 1 Mbps. 2. Remaining capacity = 30 − 1 = 29 Mbps. 3. Remaining 5 clients share  
29 Mbps → 29 / 5 = 5.8 Mbps each.  
Answer: low client = 1 Mbps, each other client = 5.8 Mbps.  
Problem 3 (Medium)  
Q: Same model as earlier: backbone R = 100 Mbps, 20 clients. 5 clients have access 2 Mbps (low), 15 clients have access 20 Mbps (high). What is per-client throughput for each class?  
Solution: 1. If equal: fair share = 100 / 20 = 5 Mbps. 2. Low clients cannot reach 5 Mbps; each low client caps at 2 Mbps. 3. Low clients total use = 5 × 2 = 10 Mbps. Remaining capacity = 100 − 10 = 90 Mbps. 4.  
Remaining 15 high clients share 90 Mbps → 90 / 15 = 6 Mbps each (less than their 20 Mbps access limit).  
Answer: low clients = 2 Mbps each; high clients = 6 Mbps each.  
Problem 4 (Easy)  
Q: A path has link rates [10, 5, 2, 8] Mbps. What is the path bottleneck and how much throughput can a single flow achieve? If 8 identical flows share the path, what is each flow’s throughput (assume equal share at bottleneck)?  
Solution: - Bottleneck = min(10,5,2,8) = 2 Mbps. - Single flow ≤ 2 Mbps. - With 8 identical flows: per-flow =  
2 / 8 = 0.25 Mbps = 250 kbps.  
Problem 5 (Easy–Medium)  
Q: Measure the BDP for a satellite link: RTT = 600 ms, capacity = 50 Mbps. How large must the TCP window be (in KB) to fully utilize the link?  
Solution: - BDP = R × RTT = 50,000,000 bits/s × 0.6 s = 30,000,000 bits. - Bytes = 30,000,000 / 8 = 3,750,000 bytes. - KB (1024) = 3,750,000 / 1024 ≈ 3,662.11 KB ≈ 3.58 MB.  
Answer: approximately 3,662 KB (≈ 3.6 MB).  
Problem 6 (Medium)  
Q: A 1200-byte packet traverses 3 identical links. Each link rate R = 5 Mbps, length 300 km, propagation speed 2×10^8 m/s. Processing at each intermediate router = 0.5 ms. Ignore queueing. Find end-to-end delay.  
Solution: 1. Packet size = 1200 bytes = 1200 × 8 = 9,600 bits. 2. Transmission delay per link = 9,600 / 5,000,000 = 0.00192 s = 1.92 ms. 3. Propagation per link = 300,000 m / (2×10^8 m/s) = 0.0015 s = 1.5 ms. 4.  
For 3 links: total transmission = 3 × 1.92 = 5.76 ms; total propagation = 3 × 1.5 = 4.5 ms. 5. Processing at intermediate routers: 2 routers × 0.5 ms = 1.0 ms. 6. Total end-to-end ≈ 5.76 + 4.5 + 1.0 = 11.26 ms.  
Answer: approximately 11.26 ms.  
Problem 7 (Medium)  
Q: Estimate steady-state TCP Reno throughput given MSS = 1460 bytes, RTT = 50 ms, packet loss p = 1%.  
Solution (Padhye/Reno approx): - Throughput (bytes/s) ≈ (1.22 × MSS) / (RTT × √p). - Numerator = 1.22 ×  
1460 = 1,781.2 bytes. - Denominator = 0.05 s × √0.01 = 0.05 × 0.1 = 0.005. - Bytes/s ≈ 1,781.2 / 0.005 = 356,240 bytes/s. - Bits/s = ×8 = 2,849,920 bps ≈ 2.85 Mbps.  
Answer: roughly 2.85 Mbps.  
Problem 8 (Medium — measurement)  
Q: Design an experiment using ping/traceroute to detect which hop is introducing ~30 ms extra delay to a destination. Describe probes, intervals, and interpretation.  
Solution (concise plan): 1. Run traceroute -n -I <dest> 10 times at 2s intervals; collect per-hop RTTs. 2. For each run compute incremental RTT per hop: RTT(i+1) − RTT(i). Look for consistent ≈+30 ms increment at same hop. 3. Ping the suspected hop IP directly with 20 probes ( ping -c 20 ip ) and compare averages. 4. Use TCP/UDP traceroute ( traceroute -T or tcptraceroute ) to check if ICMP deprioritization is affecting traceroute results. 5. Interpret: consistent jump + ping-confirmation → likely congestion/propagation; jump only in ICMP traceroute but not TCP → ICMP deprioritization.  
Answer: (plan & interpretation above). Tools: traceroute , mtr , ping , tcptraceroute .  
Problem 9 (Medium — fair-share iterative allocation) Q: Link/server capacity R = 100 Mbps. There are 10 clients: 4 clients with access links 1 Mbps (low), and 6 clients with access links 20 Mbps (high). Compute per-client throughput.  
Solution (step-by-step): 1. If equal: fair share = 100 / 10 = 10 Mbps — but low clients capped at 1 Mbps. 2.  
Low clients total use = 4 × 1 = 4 Mbps. 3. Remaining capacity = 100 − 4 = 96 Mbps. 4. Remaining flows = 6 high clients. Per-high-client = 96 / 6 = 16 Mbps (less than their 20 Mbps cap).  
Answer: low clients = 1 Mbps each; high clients = 16 Mbps each.  
Problem 10 (Challenging — M/M/1 queueing approx) Q: A link R = 10 Mbps serves packets of average size 1250 bytes (1,250 × 8 = 10,000 bits). Arrival process average λ = 800 packets/s. Using M/M/1 approximation, compute utilization ρ, average number in system L, and average waiting time W.  
Solution: 1. Service rate μ (pkts/s) = R / (packet bits) = 10,000,000 / 10,000 = 1,000 pkts/s. 2. Utilization ρ = λ / μ = 800 / 1000 = 0.8. 3. For M/M/1, average number in system L = ρ / (1 − ρ) = 0.8 / 0.2 = 4 packets. 4.  
Average time in system W = L / λ = 4 / 800 = 0.005 s = 5 ms.  
Answer: ρ = 0.8, L = 4 pkts, W = 5 ms.  
Detailed step‑by‑step walkthrough — Problem 9 (iterative fair allocation)  
Problem recap: R = 100 Mbps. 4 clients at 1 Mbps, 6 clients at 20 Mbps. Compute per-client throughput.  
Walkthrough (algorithmic):  
Compute naive fair share: If every client were unconstrained, fair share = R / N = 100 / 10 = 10 Mbps.  
Compare to each client’s access cap: Any client whose access cap < fair share will be capped and thus use less than fair share.  
The 4 low clients: cap = 1 Mbps < 10 Mbps → each w Subtract capacity used by capped flows:  
Total used by low clients = 4 × 1 = 4 Mbps.  
Remaining capacity = 100 − 4 = 96 Mbps.  
Redistribute remaining capacity among the remaining (uncapped) flows:  
Remaining flows = initially 10 − 4 = 6 high clients.  
New fair share for these flows = 96 / 6 = 16 Mbps.  
Check caps again:  
High clients’ caps are 20 Mbps; computed share 16 Mbps ≤ 20 → OK (no more caps).  
Final allocation:  
Low clients: 1 Mbps each. High clients: 16 Mbps each.  
Why this algorithm works: capped (edge-limited) flows free unused capacity which is fairly redistributed among the remaining flows; repeat until no remaining flows are capped.  
Notes & printing  
The cheat-sheet section is intentionally compact for printing on a single page. The practice problems and walkthrough give worked examples and deeper practice.  
End of document.
