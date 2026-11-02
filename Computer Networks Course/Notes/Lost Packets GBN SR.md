# Lost Packets in Go-Back-N and Selective Repeat

## Problem: Lost Packets in Go-Back-N and Selective Repeat

Scenario  
A sender transmits 15 data packets (P1 to P15) to a receiver over an unreliable communication channel. Two protocols are used: Go-Back-N (GBN) and Selective Repeat (SR).  
Given Data  
1 Window size (N) = 6  
2 Every 6th transmitted packet is lost (including retransmissions)  
3 GBN: Receiver discards out-of-order packets  
4 SR: Receiver buffers out-of-order packets  
Questions  

### 1. Identify lost transmissions and corresponding packet

numbers.  
GIVEN  
Total packets: P1 → P15  
Window size = 6  
Rule: Every 6th transmission is LOST (important ) Applies to ALL transmissions (even retransmissions)  
STEP 1: Understand “every 6th transmission” We count transmissions, NOT packet numbers.  
So we count like this:  
Transmission #  
Packet Sent  
Status  
P1  
P2  
P3  
P4  
P5  
P6  
LOST  
P7  
P8  
P9  
P10  
P11  
P12  
LOST  
P13  
P14  
P15  
FINAL ANSWER (Lost Packets)  
Lost transmissions occur at:  
6th transmission → P6  
12th transmission → P12  
IMPORTANT CONCEPT (Very Important )  
The rule says:  
So if we continue further:  
18th transmission → LOST  
24th transmission → LOST  
etc.  
SIMPLE SUMMARY  
Count transmissions (1,2,3,...)  
Every 6th one fails  
So lost packets are:  
P6 and P12 (in first round)  
This question is usually followed by:  
What happens in Go-Back-N (GBN)?  
What happens in Selective Repeat (SR)?  
Those parts are more interesting (retransmissions behave differently ) “Every 6th transmission is lost (including retransmissions)”  

## What Including Retransmissions Means

this is the most important part to really understand  
FIRST: What does “including retransmissions” mean?  
It means:  
Example:  
If P6 is lost and we send it again:  
First send of P6 → counts  
Retransmission of P6 → also counts  
So both are counted in transmission numbering.  
Simple analogy:  
Think like throwing balls:  
Every throw = 1 transmission  
Even if you throw the same ball again, it is still a new throw  
NOW: Go-Back-N (GBN) — Step-by-Step  
Rule:  
Receiver discards out-of-order packets If one packet is lost → everything after it is useless Window size = 6  
Sender sends:  
P1 P2 P3 P4 P5 P6  
P6 is LOST (6th transmission)  
Receiver got:  
P1–P5  
P6 missing  
Next packets sent  
Sender continues:  
P7 P8 P9 P10 P11  
But receiver says:  
“I am still waiting for P6”  
So it DISCARDS P7–P11  
Timeout happens → retransmission starts Sender goes back and sends again:  
P6 P7 P8 P9 P10 P11  
Now count transmissions carefully  
COUNTING TRANSMISSIONS (VERY IMPORTANT) We continue counting:  
Transmission #  
Packet  
Result  
1–5  
P1–P5  
P6  
LOST  
7–11  
P7–P11  
wasted  
P6 (retransmit)  
LOST again  
See this?  
12th transmission is also lost → retransmitted P6 is lost again Again timeout → resend  
Sender again sends:  
P6 P7 P8 P9 P10 P11  
Continue counting:  
Transmission #  
Packet  
Result  
P6  
P7  
P8  
P9  
P10  
P11  
LOST  
GBN RESULT SUMMARY  
Lost transmissions:  
6 → P6  
12 → P6 (retransmission)  
18 → P11  
And many packets wasted due to discarding  
NOW: Selective Repeat (SR)  
Rule:  
Receiver buffers (stores) out-of-order packets Only missing packets are retransmitted First send  
P1 P2 P3 P4 P5 P6  
P6 is LOST  
Receiver:  
Stores P1–P5  
Missing P6  
Next send  
P7 P8 P9 P10 P11  
Receiver:  
Stores ALL (P7–P11) in buffer  
No discarding!  
Retransmit only missing packet  
Sender sends:  
P6 again  
Count transmissions:  
Transmission #  
Packet  
Result  
P6  
LOST  
P6 (retransmit)  
LOST again  
Again retransmit P6  
Transmission #  
Packet  
Result  
P6  
Now receiver already has:  
P1–P5 + buffered P7–P11  
So everything becomes complete instantly!  
SR RESULT SUMMARY  
Lost transmissions:  
6 → P6  
12 → P6 (retransmission)  
Much more efficient than GBN  
FINAL COMPARISON  
Feature  
GBN  
SR  
Out-of-order packets  
Discarded  
Stored  
Retransmission  
Many packets  
Only lost ones  
Efficiency  
Low  
High  
SUPER SIMPLE FINAL IDEA  
“Including retransmissions” = count every send attempt  
GBN = wasteful (resend everything)  
SR = smart (resend only missing)  
Draw a timeline diagram  
Or give you a shortcut trick to solve such questions in exams When we count transmissions (1, 2, 3, …), we count EVERY send, even if it's sent again.  

## Does Go-Back-N Restart or Loop Forever?

Does GBN retransmit from the start (P1)?  
NO  
It does NOT go back to P1.  
It goes back to the first unacknowledged packet.  
In your case  
Packets sent:  
P1 P2 P3 P4 P5 P6  
P1–P5 → received  → ACKed  
P6 →  LOST  
So the first unacknowledged packet = P6 What happens next?  
Sender sends more:  
P7 P8 P9 P10 P11  
Receiver:  
Rejects them (because P6 missing)  
Timeout occurs  
Now sender says:  
So it sends:  
P6 P7 P8 P9 P10 P11  
KEY IDEA  
GBN retransmits from:  
So:  
NOT from P1  
Starts from P6  
Will it go into infinite loop?  
NO (in theory)  
YES (temporarily possible in this question) Why NOT infinite loop normally?  
Because:  
Rule says:  
So:  
6th → P6 lost  
12th → P6 lost again  
18th → P11 lost  
This can cause repeated failures, but:  
Eventually some transmission will not fall on 6th position, so it succeeds Simple visualization  
Think like this:  
You’re trying to send P6 again and again Sometimes it hits “bad number” (6, 12, 18…) → fails Other times → succeeds  
So it may retry multiple times, but not forever  
FINAL ANSWER  
GBN does NOT restart from beginning (P1) It retransmits from first unacknowledged packet (P6) It does NOT get stuck in infinite loop, but may retry multiple times One-line memory trick  
GBN = “Go back to error point, not start” Exact timeline diagram (very easy visual) OR a shortcut method to solve exam questions fast “I didn’t get ACK for P6 → I must resend from P6” first unacknowledged packet (NOT from start) Every 6th transmission is LOST (even retransmissions)  

## Tracing Go-Back-N Step by Step

First, your idea (slightly corrected)  
This is almost right, but there are 2 important mistakes:  
MISTAKE 1: Window size violation  
Window size = 6  
So sender can send only 6 packets at a time So:  
After P1–P6  
Next should be P7–P12 (correct)  
BUT only 6 packets max in flight  
MISTAKE 2: ACK behavior misunderstanding In Go-Back-N (GBN):  
Receiver sends cumulative ACK  
Meaning:  
If P6 is missing → it keeps saying:  
“I only accept up to P5”  
So even if it receives:  
P7, P8, P9… →  DISCARDED  
STEP 1: Send first window  
P1 P2 P3 P4 P5 P6  
P6 →  LOST (6th transmission)  
Receiver:  
P1–P5 accepted  
Waiting for P6  
STEP 2: Sender continues (window slides partially) Sender sends:  
P7 P8 P9 P10 P11 P12  
Receiver:  
Discards ALL (because P6 missing)  
STEP 3: Timeout → Go-Back-N triggers  
Sender goes back to P6  
Sends:  
P6 P7 P8 P9 P10 P11  
COUNT carefully (important!)  
We already had 12 transmissions → so:  
12th transmission =  LOST → this is P12 earlier Now continue:  
Transmission #  
Packet  
Result  
P6  
P7  
P8  
P9  
P10  
P11  
LOST  
STEP 4: Now what happens?  
P11 is LOST  
Receiver got P6–P10  
Now expecting P11  
STEP 5: Sender continues  
Sender sends:  
P12 P13 P14 P15  
Receiver:  
Discards (because P11 missing)  
STEP 6: Timeout again  
Sender goes back to P11  
Sends:  
P11 P12 P13 P14 P15  
NOW compare with your statement  
YES — this part is CORRECT  
FINAL CORRECT FLOW (SHORT)  

### 1. P6 lost

### 2. P7–P12 sent → discarded

### 3. Retransmit P6–P11

### 4. P11 lost

### 5. P12–P15 sent → discarded

### 6. Retransmit P11–P15

FINAL IDEA (VERY IMPORTANT)  
In GBN:  
Loss at P6 → go back to P6  
Loss at P11 → go back to P11  
Always go back to first missing packet  
ONE-LINE RULE  
GBN = “Lose one → resend from that point onward” If you want next:  
I can draw a timeline diagram (very easy to memorize) Or solve the Selective Repeat in same detailed flow (even easier) after P6 fails → send P7–P12 → then go back → then P11 lost → then send P12–P15… “then it will transmit P12–P15 but discard then again transmit from P11–P15”  

## Tracing Selective Repeat Step by Step

RULES OF SR (Quick Reminder)  
Receiver accepts and stores out-of-order packets Sender retransmits only lost packets  
Window size = 6  
STEP-BY-STEP FLOW  
STEP 1: First window  
Sender sends:  
P1 P2 P3 P4 P5 P6  
6th transmission = P6 LOST  
Receiver:  
Gets P1–P5  
Missing P6  
STEP 2: Sender continues  
Sender sends next window:  
P7 P8 P9 P10 P11 P12  
12th transmission = P12 LOST  
Receiver:  
Stores P7–P11  (buffered)  
P12 missing  
IMPORTANT POINT  
Now receiver has:  
P1–P5  
P6 missing  
P7–P11 stored  
P12 missing  
STEP 3: Sender sends remaining  
Sender sends:  
P13 P14 P15  
(All are successful here)  
Receiver:  
Stores P13–P15  
NOW: What is missing?  
Only:  
P6  
P12  
STEP 4: Retransmissions (Selective Repeat) Sender retransmits ONLY lost packets:  
P6 and P12  
But remember rule:  
Every 6th transmission is lost  
Transmission #  
Packet  
Result  
P6  
P12  
P13  
P14  
P15  
P6 (retransmit)  
P12 (retransmit)  
FINAL RESULT  
Lost packets:  
P6 (first time)  
P12 (first time)  
Retransmitted:  
Only P6 and P12  
No unnecessary retransmissions  
CORRECTING YOUR STATEMENT  
CORRECT  
But small improvement:  
FINAL SIMPLE IDEA  
SR works like:  
FINAL COMPARISON (SUPER EASY)  
GBN → “Start again from error”  
SR → “Fix only missing packets”  
Show side-by-side diagram (GBN vs SR)  
Or give you exam shortcut trick (solve in 30 sec) “then it sends P13–P15 total 3 transmission then resend only lost packets” It resends only missing packets (P6 and P12)  
NOT whole windows  
“Store everything → fix only missing pieces later”
