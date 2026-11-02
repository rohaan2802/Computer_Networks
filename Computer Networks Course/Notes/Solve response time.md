# Solving Response Time with a Web Cache

Given  
Object size  
bits  
Request rate  
requests/sec  
Internet round-trip (Internet-side) delay s (given)  
Access link rate  
Mbps  
b/s  
LAN rate  
Mbps (used later)  
Formula used for the access (queueing) system time (M/M/1):  
where  
is the service time and  
is utilization.  

### 1) No cache — total average response time

Service time on access link:  
Utilization:  
Access (system) delay:  
Total average response time = Internet delay + access delay:  

### 2) Cache installed with miss rate = 0.4

There are two useful ways to interpret what the question wants — both are shown.  
(A) Simple: only misses go over the access link Effective arrival to access link =  
New utilization:  
Access delay for misses:  
Total response for a miss = Internet delay + access delay ≈ If the problem expects “find the total response time” for requests that go to the Internet, answer:  
(B) More complete — overall average across hits and misses Hits (probability 0.6) are served from the cache over the LAN. Service time on LAN:  
LAN utilization (with arrival  
LAN (system) time for hits:  
Misses (probability 0.4) cost about  
(from part A).  
Weighted average overall:  
Final numeric answers (rounded)  
No cache: total average response time ≈ 3.18 s.  
With cache (if you only evaluate misses over access link): miss response ≈ 3.08 s.  
With cache (overall average including hits served on LAN): overall average ≈ 1.24 s.  
S = 850,000  
λ = 12  
Internet  
access  
= 15,000,000  
LAN  
access_delay =  
1 −λ(S/R)  
S/R  
S/R  
ρ = λ(S/R)  
access  
15,000,000  
0.0566666667 s.  
ρ = λS  
access  
12 × 0.0566666667 = 0.68.  
access_delay =  
1 −0.68  
0.0566666667  
0.32  
0.0566666667  
0.1770833333 s.  
total  
3 + 0.1770833 ≈3.18 s.  
miss  
λ × 0.4 = 4.8 req/s.  
miss  
4.8 × 0.0566666667 = 0.272.  
access_delay  
miss  
1 −0.272  
0.0566666667  
0.07784 s.  
3 + 0.07784 = 3.07784 s.  
3.08 s (for misses)  
LAN  
100,000,000  
0.0085 s.  
λ = 12  
λS  
LAN  
12 × 0.0085 = 0.102.  
hit_delay =  
1 −0.102  
0.0085  
0.0094655 s.  
3 + 0.0778388 = 3.0778388 s  
overall  
0.6 × 0.0094655 + 0.4 × 3.0778388 ≈1.237 s.  
Given  
Object size  
Kbits  
bits  
Access link rate  
Mbps  
b/s  
Request arrival rate  
requests/s  
Service time (time to transmit one object on the access link) Utilization  
Average access (system) delay using  
Answer: Average access delay ≈ 3.89 s.  
Note:  
is very high (close to 1), meaning the access link is nearly saturated and delays blow up — small increases in arrival rate would make the system unstable.  
S = 350  
= 350,000  
R = 2.54  
= 2,540,000  
λ = 7  
0.1377952756 s.  
ρ = λt  
7 × 0.1377952756 = 0.9645669291.  
1 −ρ  
access_delay =  
1 −0.9645669291  
0.1377952756  
3.8888888889 s.  
ρ ≈0.965
