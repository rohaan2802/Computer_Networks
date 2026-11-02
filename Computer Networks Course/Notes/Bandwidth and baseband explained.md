# Bandwidth, Broadband and Baseband

## Bandwidth, Broadband and Baseband

1⃣ Bandwidth  
Meaning: Bandwidth is the capacity of a channel – how much data it can carry per second.  
Think of it like a water pipe: a bigger pipe (more bandwidth) lets more water (data) flow at the same time.  
Example:  
A 10 Mbps internet connection means the "bandwidth" is 10 megabits per second.  
A radio station may have a frequency range (say 100–101 MHz). That 1 MHz is its bandwidth.  
2⃣ Baseband  
Meaning: Baseband means using the entire channel for a single signal at one time. Data is sent in raw form (digital signals, like 0s and 1s), without dividing it into smaller frequency bands.  
Usually used for short-distance communication.  
Examples:  
Ethernet cable (LAN) → It sends pure digital signals over the whole wire (baseband).  
Telephone landline (old dial-up) → Carries only one voice call at a time (baseband).  
Think of it like:  
A single-lane road where only one car (signal) goes at a time.  
3⃣ Broadband  
Meaning: Broadband means dividing the channel into multiple frequency ranges (bands) so that many signals can travel at once. Each band carries its own signal, often modulated.  
Usually used for long-distance and high-speed communication.  
Examples:  
Wi-Fi, DSL, Fiber Internet → Broadband internet because many signals share the medium.  
Cable TV → Many TV channels are transmitted at different frequencies over the same cable.  
Mobile networks (4G/5G) → Different frequency bands are used for different users and services.  
Think of it like:  
A multi-lane highway where many cars (signals) move at the same time in different lanes.  
Quick Comparison Table:  
Term  
Meaning  
Example  
Bandwidth  
Capacity of the channel (like pipe size)  
10 Mbps internet speed  
Baseband  
Whole channel used by 1 signal at a time Ethernet cable, landline  
Broadband  
Channel split into multiple signals  
(frequency bands)  
Wi-Fi, Cable TV, 4G  
(baseband) vs multi-lane (broadband)?  

## How Computers Connect to the Internet

Ways to Connect a Computer to the Internet 1⃣ Wired Connection (LAN Cable / Ethernet) You connect your computer to a router or modem using an Ethernet cable.  
The router/modem is already connected to your Internet Service Provider (ISP).  
Very stable and fast.  
Example: In offices, labs, or gaming setups, PCs are usually connected this way.  
2⃣ Wireless Connection (Wi-Fi)  
Your computer has a Wi-Fi card (built-in or USB adapter).  
It connects wirelessly to the Wi-Fi router.  
The router connects to the ISP.  
Example: At home, when you enter the Wi-Fi password on your laptop, it connects to the internet.  
3⃣ Mobile Data (Hotspot / USB Tethering) If you don’t have Wi-Fi, you can use your mobile phone’s data.  
Options:  
Turn on Mobile Hotspot → connect your PC via Wi-Fi.  
Use USB Tethering → connect phone via cable.  
Use Bluetooth Tethering.  
Example: Traveling and no Wi-Fi? You turn on hotspot from your phone and connect your laptop.  
4⃣ Broadband / Fiber / DSL Modem  
ISP provides internet via telephone line (DSL), fiber optic cable, or coaxial cable.  
A modem converts signals → connects to your router → then to your PC (wired or wireless).  
Example: PTCL DSL, Nayatel Fiber, StormFiber (Pakistan).  
5⃣ Other Options (less common)  
Satellite Internet (Starlink, dish-based internet in remote areas).  
Dial-up (very old, slow internet via telephone line).  
Simple Flow:  
Your Computer → Router/Modem → ISP → Internet (Websites, Apps, Servers) Analogy:  
Think of it like sending a letter:  
Your computer = you writing the letter.  
The router/modem = the local post office.  
The ISP = the national postal system.  
The Internet = the world, where you can reach any house (website).  
Wi-Fi, mobile hotspot, ISP, internet) so it becomes crystal clear?  
What is FDM?  
FDM = Frequency Division Multiplexing  
It’s a technique where the available bandwidth of a channel is divided into multiple frequency bands.  
Each user or signal gets its own frequency band and all travel at the same time without interfering.  
Imagine a radio:  
One station uses 100 MHz, another uses 101 MHz, another 102 MHz.  
All stations broadcast at once, but your radio tunes to just one.  
That’s FDM in real life!  
Example  

### 1. Radio Broadcasting

Many FM channels share the air at the same time.  
88–108 MHz is the total frequency range (bandwidth).  
Each FM channel gets a small slice (e.g., 200 kHz).  

### 2. Cable TV

Many TV channels are transmitted together over one cable, each on a different frequency.  

### 3. Telephone (old analog systems)

Many calls could travel on the same wire using different frequencies.  
Analogy  
Think of a highway with multiple lanes:  
Each lane = one frequency band.  
Cars in each lane = one signal.  
They all move simultaneously without crashing, because each stays in its lane.  
Summary Table  
Feature  
FDM  
Full form  
Frequency Division Multiplexing  
How it works  
Divides channel into frequency bands  
Used for  
Radio, TV, old telephone lines  
Analogy  
Multi-lane highway  
with FDM, so you clearly see the difference?  

## Lecture Notes: Access Networks

HFC: hybrid fiber coax  
asymmetric: up to 40 Mbps – 1.2 Gbps downstream transmission rate,  
30-100 Mbps upstream transmission rate network of cable, fiber attaches homes to ISP router homes share access network to cable headend Coax) and  
an example.  
What is HFC?  
HFC = Hybrid Fiber-Coax  
It’s a type of network used by cable internet providers.  
It combines fiber optic cable (for high speed, long distances) and coaxial cable (for short distance, like inside neighborhoods).  
Think of it like this:  
Fiber = highway (fast, long-distance backbone).  
Coax = small streets (connecting to houses).  
How It Works  
1. ISP (Internet Service Provider) has a main router (called the cable headend).  

### 2. Fiber optic cables run from the ISP to your neighborhood.

3. In the neighborhood, the connection is split into coaxial cables that go to each home.  
4. Homes share the same access network → so internet speed can vary depending on how many people are online at the same time.  
Asymmetric Speeds  
Downstream (download): 40 Mbps – 1.2 Gbps → Download is much faster because most people download more than upload (videos, browsing).  
Upstream (upload): 30–100 Mbps  
→ Slower, because uploading is less common (sending files, live streaming).  
That’s why it’s called asymmetric (download ≠ upload).  
Real-Life Example  
In Pakistan: StormFiber, Nayatel (FTTH, but similar), or in other countries Comcast, Spectrum, Cox.  
You watch YouTube (download-heavy), upload a video (upload), all through the same  
HFC network.  
Summary Table  
Term  
Meaning  
HFC  
Hybrid Fiber-Coax (fiber + coax mix)  
Downstream  
Data from ISP → your home (download, streaming) Upstream  
Data from home → ISP (upload, video call) Asymmetric  
Download speed much higher than upload Cable Headend  
ISP’s main router station that connects homes Do you  
neighborhood → coax → homes) so it’s crystal clear?  
Access networks: digital subscriber line (DSL) central office  
telephone  
network  
DSLAM  
voice, data transmitted  
at different frequencies over  
dedicated line to central office  
use existing telephone line to central office DSLAM data over DSL phone line goes to Internet voice over DSL phone line goes to telephone net 24-52 Mbps dedicated downstream transmission rate 3.5-16 Mbps dedicated upstream transmission rate Let me  
What is DSL?  
DSL = Digital Subscriber Line  
It provides internet using the existing telephone line (copper wires).  
Unlike old dial-up, DSL can carry internet (data) and telephone (voice) at the same time → because they use different frequencies on the same wire.  
How DSL Works  
1. You have a telephone line from your home to the telephone company’s central office.  
2. At the central office, a device called DSLAM (Digital Subscriber Line Access Multiplexer) separates voice traffic and data traffic.  
Voice traffic → goes to the telephone network.  
Data traffic → goes to the internet.  
3. In your home, a splitter or modem separates the two signals so your phone and internet can work together.  
Speeds (Asymmetric DSL)  
Downstream (Download): 24 – 52 Mbps  
→ Data coming to you (videos, browsing).  
Upstream (Upload): 3.5 – 16 Mbps  
→ Data going from you (sending files, video call).  
Called asymmetric because download ≠ upload.  
Real-Life Example  
You open YouTube → data comes as download.  
You upload a file to Google Drive → data goes as upload.  
At the same time, you can also use the same line for a phone call.  
Summary Table  
Term  
Meaning  
DSL  
Internet over existing telephone line  
Central Office  
Telephone company’s building  
DSLAM  
Device at central office that splits voice/data Downstream  
24–52 Mbps (download)  
Upstream  
3.5–16 Mbps (upload)  
Advantage  
Internet + phone on one line, no conflict Do you  
Internet) so you clearly see the difference between the two access networks?  
Wireless access networks  
Shared wireless access network connects end system to router  
via base station also called, “access point” Wireless local area networks  
(WLANs)  
typically within or around  
building (~100 ft)  
802.11b/g/n (WiFi): 11, 54, 450  
Mbps transmission rate  
to Internet  
to Internet  
Wide-area cellular access networks  
provided by mobile, cellular network  
operator (10’s km)  
10’s Mbps  
4G/5G cellular networks  
Let me  
What is a Wireless Access Network?  
It’s a network where your computer/phone connects to the internet wirelessly.  
Your device sends data → to a base station (access point) → then to the router/ISP → then to the Internet.  
There are two main types:  
1⃣ Wireless Local Area Networks (WLANs) Range: Works inside or around a building (about 100 ft / 30 m).  
Uses Wi-Fi (IEEE 802.11 standards).  
Speeds:  
802.11b → 11 Mbps  
802.11g → 54 Mbps  
802.11n → up to 450 Mbps  
How it works:  
Your device (laptop/phone) → Wi-Fi Access Point (router) → ISP → Internet.  
Example:  
Home Wi-Fi, University Wi-Fi, Coffee shop Wi-Fi.  
Think of it like a wireless bubble around your router.  
2⃣ Wide-Area Cellular Networks  
Range: Covers many kilometers (10’s of km).  
Provided by mobile network operators.  
Uses cell towers (base stations) to connect your phone/laptop.  
Speeds:  
4G → 10s of Mbps  
5G → much higher (100 Mbps – Gbps).  
How it works:  
Your phone → nearest cell tower → mobile provider’s network → Internet.  
Example:  
Using Jazz 4G/5G, Zong, Telenor, Ufone data in Pakistan.  
Think of it like a giant wireless umbrella that covers your whole city.  
Summary Table  
Type  
Range  
Speed  
Example  
WLAN (Wi-Fi)  
~100 ft  
11 – 450 Mbps  
Home Wi-Fi, office Wi-Fi  
Cellular (4G/5G)  
10s of km  
10s Mbps – Gbps  
Mobile data, hotspot  
Analogy:  
Wi-Fi = your home router bubble (short range, very fast).  
Cellular = your city-wide umbrella (long range, shared).  
Internet vs devices → cell tower → Internet?  

## Lecture Notes: Enterprise Networks and Physical Media

you can also connect to internet by companies, universities, etc.  
mix of wired, wireless link technologies, connecting a mix of  
switches and routers (we’ll cover differences shortly) Ethernet: wired access at 100Mbps, 1Gbps, 10Gbps WiFi: wireless access points at 11, 54, 450 Mbps high-bandwidth links (10s to 100s Gbps) connect hundreds to thousands of  
servers together, and to Internet  
Links: physical media  
bit: propagates between  
transmitter/receiver pairs  
physical link: what lies  
between transmitter &  
receiver  
guided media:  
signals propagate in solid  
media: copper, fiber, coax  
unguided media:  
signals propagate freely,  
e.g., radio  
Twisted pair (TP)  
two insulated copper wires  
Category 5: 100 Mbps, 1 Gbps Ethernet  
Category 6: 10Gbps Ethernet  
Institutional Networks (Companies, Universities, Data Centers)  
These networks connect many users (hundreds or thousands) to the internet.  
They use a mix of wired and wireless technologies:  
Ethernet (wired) → 100 Mbps, 1 Gbps, or 10 Gbps.  
Wi-Fi (wireless) → 11, 54, up to 450 Mbps.  
Inside, they use switches and routers to connect computers together.  
To connect to the Internet, they use high-bandwidth links (10s–100s of Gbps).  
Example: FAST University or Google’s office network.  
Links and Physical Media  
A link = the physical path that connects a transmitter to a receiver.  
A bit travels over this link (from sender to receiver).  
There are two types:  
1⃣ Guided Media (solid medium)  
Signals travel inside a physical medium.  
Twisted Pair (TP):  
Two insulated copper wires twisted together.  
Categories:  
Cat 5 → 100 Mbps, 1 Gbps Ethernet  
Cat 6 → up to 10 Gbps Ethernet  
Coaxial Cable: Used in cable TV and HFC internet.  
Fiber Optic Cable: Uses light, very high speed (Gbps to Tbps).  
2⃣ Unguided Media (wireless)  
Signals propagate freely, no physical wire.  
Uses radio waves, microwaves, infrared.  
Examples: Wi-Fi, Bluetooth, 4G/5G, Satellite.  
Summary Table  
Network Type  
Speed Range  
Example  
Ethernet (wired)  
100 Mbps – 10 Gbps  
Office LAN  
Wi-Fi (wireless)  
11 – 450 Mbps  
Home router, university Wi-Fi  
High-bandwidth backbone  
10s–100s Gbps  
Data centers, ISPs  
Twisted Pair (Cat5/6)  
100 Mbps – 10 Gbps  
LAN cables  
Fiber optic  
Gbps–Tbps  
Internet backbone  
Unguided (radio)  
Varies (Mbps–Gbps)  
Wi-Fi, cellular  
Analogy:  
Guided media = like water flowing inside pipes (copper, coax, fiber).  
Unguided media = like water sprayed through air (wireless signals).  
Fi → switches/routers → high-speed backbone → Internet?  

## Is 10 Mbps 10 Megabytes per Second?

When you see 10 Mbps on an internet plan, it does not mean 10 MegaBytes per second.  
Mbps vs MBps  
Mbps = Megabits per second  
1 bit = smallest unit of data (0 or 1).  
Internet speeds are almost always measured in bits per second.  
MBps = MegaBytes per second  
1 Byte = 8 bits  
File sizes (documents, songs, videos) are measured in Bytes, not bits.  
Conversion  
To convert:  
So, if your internet is 10 Mbps:  
That means your maximum download speed is about 1.25 MegaBytes per second.  
Example  
Your ISP plan: 10 Mbps internet.  
You download a 100 MB file:  
Speed = ~1.25 MBps  
Time =  
seconds (~1 min 20 sec).  
Summary  
Internet providers → use Mbps (bits).  
File sizes on your computer → use MB (Bytes).  
To convert: divide by 8.  
Mbps → 6.25 MBps, 100 Mbps → 12.5 MBps, etc.) so you can easily compare internet plans?  
1 MBps = 8 Mbps  
10 ÷ 8 = 1.25 MBps  
100/1.25 = 80  

## Lecture Notes: Coax, Fibre and Wireless Radio

Links: physical media  
Coaxial cable:  
two concentric copper conductors  
bidirectional  
broadband:  
multiple frequency channels on cable  
100’s Mbps per channel  
Fiber optic cable:  
glass fiber carrying light pulses, each pulse a bit  
high-speed operation:  
high-speed point-to-point  
transmission (10’s-100’s Gbps)  
low error rate:  
repeaters spaced far apart  
immune to electromagnetic noise  
Links: physical media  
Wireless radio  
signal carried in various  
“bands” in electromagnetic  
spectrum  
no physical “wire”  
broadcast, “half-duplex”  
(sender to receiver)  
propagation environment  
effects:  
reflection  
obstruction by objects  
Interference/noise  
Radio link types:  
Wireless LAN (WiFi)  
10-100’s Mbps; 10’s of meters  
wide-area (e.g., 4G/5G cellular)  
100’s Mbps (4G/5G) over ~10 Km  
Bluetooth: cable replacement  
short distances, limited rates  
terrestrial microwave  
point-to-point; 45 Mbps channels  
satellite  
up to < 100 Mbps (Starlink) downlink  
270 msec end-end delay (geostationary) Perfect  you’re now covering the different types of physical media (links) used to carry data in networks.  
Links: Physical Media  
A link is the physical path a signal travels between a sender (transmitter) and receiver.  
There are three main types:  
1⃣ Coaxial Cable  
Structure: two concentric copper conductors (one inside, one outside with insulation).  
Bidirectional: data can flow both ways.  
Broadband: supports multiple frequency channels on the same cable.  
Speed: 100’s of Mbps per channel.  
Example: Cable TV, Cable Internet (HFC) 2⃣ Fiber Optic Cable  
Made of glass fiber that carries light pulses.  
Each light pulse = 1 bit of data.  
High speed: 10’s–100’s of Gbps.  
Low error rate: repeaters (signal boosters) are far apart.  
Immune to electromagnetic noise (no interference from electricity or radio).  
Example: Nayatel Fiber Internet, Google Fiber, submarine cables 3⃣ Wireless Radio  
Data sent using electromagnetic spectrum bands (no wires).  
Usually broadcast, half-duplex (one device talks at a time).  
Challenges: reflection, obstruction (walls, trees), interference (other signals).  
Types of Radio Links:  
Wi-Fi (WLAN):  
Speed: 10–100’s Mbps  
Range: 10’s of meters (home, office).  
Cellular (4G/5G):  
Speed: 100’s Mbps (4G), even Gbps for 5G.  
Range: ~10 km.  
Bluetooth:  
Short range (a few meters).  
Replaces cables (e.g., headphones, keyboards).  
Terrestrial Microwave:  
Point-to-point (line of sight between towers).  
~45 Mbps per channel.  
Used for long-distance communication between cell towers.  
Satellite:  
Downlink speeds: up to <100 Mbps (Starlink: higher).  
Delay: ~270 ms for geostationary satellites (because signals travel ~36,000 km up and back).  
Example: Wi-Fi router, Jazz 4G, AirBlue Inflight Wi-Fi (satellite), Bluetooth headphones  
Summary Table  
Medium  
Speed  
Range  
Example  
Coaxial  
100’s Mbps  
Local area  
Cable TV, Cable Internet  
Fiber  
10–100’s Gbps  
Long distance  
Nayatel, Submarine cables  
Wi-Fi  
10–450 Mbps  
10–100 m  
Home/office routers  
Cellular  
100’s Mbps–Gbps  
10 km  
4G/5G networks  
Bluetooth  
<10 Mbps  
Few meters  
Wireless headphones  
Microwave  
~45 Mbps  
km’s (line of sight)  
Tower-to-tower links  
Satellite  
<100 Mbps  
Global  
Starlink, GEO comms  
Analogy:  
Coaxial/Fiber = fast underground pipelines for water.  
Wireless Radio = water sprayed in the air, affected by wind, walls, etc.  
coax, Wi-Fi, cellular, satellite) connected to the Internet?  

## Lecture Notes: Hosts Sending Packets

Host: sends packets of data  
host sending function:  
takes application message  
breaks into smaller chunks,  
known as packets, of length L bits  
transmits packet into access  
network at transmission rate R  
link transmission rate, aka link  
capacity, aka link bandwidth  
R: link transmission rate  
host  
two packets,  
L bits each  
packet  
transmission  
delay  
time needed to  
transmit L-bit  
packet into link  
L (bits)  
R (bits/sec)  
Host: Sending Packets of Data  
1⃣ Host creates packets  
An application (like WhatsApp, YouTube, Gmail) generates a message.  
This message is broken into smaller pieces called packets (each of length L bits).  
Why packets? Because small chunks are easier to send, route, and reassemble.  
2⃣ Transmission into the network  
The host sends the packet into the access network (e.g., Wi-Fi, Ethernet, 4G).  
The link transmission rate (R) = how fast bits can be pushed into the link.  
Also called link capacity or link bandwidth.  
Example: If you have a 100 Mbps Ethernet, then R = 100,000,000 bits/sec.  
3⃣ Transmission Delay  
Transmission delay = the time it takes to push all the packet’s bits into the link.  
Formula:  
Where:  
L = packet length (bits)  
R = link transmission rate (bits/sec)  
4⃣ Example Calculation  
Suppose:  
Packet size = L = 1,000 bits  
Link transmission rate = R = 100,000 bits/sec (100 kbps) That means it takes 10 milliseconds just to push the packet into the link.  
5⃣ Multiple Packets  
If host sends 2 packets of L bits each:  
First packet takes L/R time.  
Second packet starts after first finishes, so total = 2L/R.  
Summary  
Host breaks message → packets of size L bits.  
Packets sent over link at rate R bits/sec.  
Transmission delay = L / R.  
Multiple packets take more time (each adds L/R).  
Analogy:  
Imagine packets are cars.  
The link is a toll booth that lets cars pass at a fixed rate (R).  
Each car takes L/R seconds to fully get through.  
If you have 2 cars (packets), total time doubles.  
propagation delay, queuing delay, and processing delay (the four main types of network delay)?  
Transmission Delay =  
Delay =  
100, 000  
0.01 sec = 10 ms  

## Definitions of Important Terms

Definitions of Important Terms (note them down) Packet Switching: the network divides the data into packets and then forwards those  
packets from source to destination via intermediate routers  
Circuit Switching: the path and all its resources are reserved only for passing data  
between the source and destination  
FDM: frequency division multiplexing - frequencies divided into bands and then each  
call for data is allocated its own frequency band  
TDM: time division multiplexing - time slots allocated to the data calls and they can  
only transmit data only at their specified slot  
ISP: internet service providers - organizations or companies that provide services to  
connect to and use the internet  
Queuing: phenomenon when more data arrives per unit time than can be  
transmitted. because of this packets start gathering at the router  
Important Networking Terms  

### 1. Packet Switching

Data is divided into packets.  
Packets are forwarded from source to destination via intermediate routers.  
Efficient use of network resources, but can face delays due to queuing.  

### 2. Circuit Switching

A dedicated path (and resources) are reserved between source and destination.  
Ensures guaranteed performance, but can waste resources if the channel is idle.  

### 3. FDM (Frequency Division Multiplexing)

Available frequencies are divided into separate bands.  
Each call or data stream is assigned its own frequency band.  

### 4. TDM (Time Division Multiplexing)

Transmission time is divided into time slots.  
Each call or data stream gets a specific time slot to transmit.  

### 5. ISP (Internet Service Provider)

Companies or organizations that provide internet connectivity and services.  
Examples: PTCL, Nayatel, StormFiber, Jazz 4G/5G.  

### 6. Queuing

Occurs when incoming data packets arrive faster than they can be transmitted.  
Packets wait in a queue at the router → may lead to delays or packet loss.  
circuit switching for  

## Lecture Notes: The Network Core

The network core  
mesh of interconnected routers  
packet-switching: hosts break  
application-layer messages into  
packets  
network forwards packets from  
one router to the next, across  
links on path from source to  
destination  
Two key network-core functions  
destination address in arriving  
packet’s header  
routing algorithm  
header value  
output link  
local forwarding table  
Forwarding:  
aka “switching”  
local action: move  
arriving packets from  
router’s input link to  
appropriate router  
output link  
local forwarding table  
Routing:  
global action:  
determine  
source-destinatio  
n paths taken by  
packets  
routing  
algorithms  
The Network Core  
The network core is a mesh of interconnected routers.  
Uses packet switching:  
Hosts break application messages into packets.  
Packets travel router → link → router until they reach the destination.  
Two Key Functions of the Network Core  

### 1. Forwarding (Local Action)

Happens inside a router.  
Moves an arriving packet from its input link to the correct output link.  
Uses the forwarding table.  
Fast operation, local to each router.  
Example:  
Packet arrives with destination address in header.  
Router looks up forwarding table.  
Sends it out via the appropriate link.  

### 2. Routing (Global Action)

Determines the entire path that packets w Uses routing algorithms to compute best paths.  
Updates forwarding tables across all routers.  
Difference Between Forwarding & Routing Forwarding  
Routing  
Local action (per-router)  
Global action (network-wide)  
Moves packets from input → output  
link  
Determines the end-to-end path  
Uses forwarding table  
Uses routing algorithms  
Very fast, per packet  
Slower, done occasionally to update paths forwarding table, and output link) so this becomes more visual for  

## Lecture Notes: Store-and-Forward and Queueing

Packet-switching: store-and-forward  
packet transmission delay: takes L/R seconds to transmit (push out) L-bit packet into link at R bps  
store and forward: entire packet must arrive at router before it can be transmitted on next link  
source  
R bps  
destination  
L bits  
per packet  
R bps  
One-hop numerical example:  
L = 10 Kbits  
R = 100 Mbps  
one-hop transmission delay  
= 0.1 msec  
note style with the example worked out:  
Packet Switching: Store-and-Forward  
In packet switching, data is broken into packets.  
Each router uses the store-and-forward principle:  
The entire packet must arrive at the router before it can be transmitted to the next link.  
⏳ Packet Transmission Delay  
Formula:  
where:  
= packet size (bits)  
= link transmission rate (bits per second, bps) This is the time required to push (transmit) all packet bits into the link.  
One-Hop Numerical Example  
Given:  
So it takes 0.1 milliseconds to transmit a 10 Kbit packet over a 100 Mbps link.  
routers) with store-and-forward, so you can see how delays add up?  
Transmission delay =  
L = 10 Kbits = 10, 000 bits  
R = 100 Mbps = 100, 000, 000 bps  
Delay =  
sec  
100, 000, 000  
10, 000  
Delay = 0.0001 sec = 0.1 ms  
Packet-switching: queueing  
R = 100 Mb/s  
R = 1.5 Mb/s  
queue of packets  
waiting for transmission  
over output link  
Queueing occurs when work arrives faster than it can be serviced:  
Packet-switching: queueing  
R = 100 Mb/s  
R = 1.5 Mb/s  
queue of packets  
waiting for transmission  
over output link  
Packet queuing and loss: if arrival rate (in bps) to link exceeds  
transmission rate (bps) of link for some period of time:  
packets will queue, waiting to be transmitted on output link  
packets can be dropped (lost) if memory (buffer) in router fills up  
Packet Switching: Queueing  
When does queueing happen?  
At a router, packets must be sent out over an output link.  
If packets arrive faster (arrival rate > transmission rate) → they wait in a queue.  
Example:  
Incoming link speed  
Outgoing link speed  
Packets build up in a buffer (waiting line) because output is much slower.  
Effects of Queueing  

### 1. Queueing Delay

Time a packet spends waiting in line before transmission.  
Delay increases when the queue is long.  

### 2. Packet Loss (Dropped Packets)

Router buffer (memory) is finite.  
If queue is full and new packets arrive → packets are dropped (lost).  
This happens when arrival rate > link rate for too long.  
Real-World Analogy  
Imagine cars entering a toll booth:  
Road before booth = fast lane (100 Mbps) Booth processing cars = slow lane (1.5 Mbps) Cars line up → queue.  
If the parking lot is full, extra cars must turn away (packet loss).  
the simple traffic intensity formula ( R = 100 Mbps  
R = 1.5 Mbps  
ρ = La/R  

## Which Packets Are Lost When the Queue Is Full

In packet switching with queueing, when the queue (buffer) is full:  
The packets that are already in the queue are safe — they will eventually get transmitted.  
The newly arriving packets are the ones that get dropped (lost).  
Why?  
The router buffer works like a first-in-first-out (FIFO) line.  
Once a packet is stored, it has its place in line.  
If a new packet arrives and there’s no room in the buffer, the router has no space to store it → so it simply discards it.  
Example  
Imagine a bus with 50 seats:  
50 passengers (packets) already sitting = safe.  
Passenger 51 arrives = no seat → rejected (lost).  
Some advanced routers use Active Queue Management (AQM) (like Random Early Detection, RED) where they intentionally drop packets early (even before the buffer is full) to avoid congestion collapse.  

## Lecture Notes: Circuit Switching

Alternative to packet switching: circuit switching end-end resources allocated to, reserved for “call” between source and destination in diagram, each link has four circuits.  
call gets 2nd circuit in top link and 1st circuit in right link.  
dedicated resources: no sharing  
circuit-like (guaranteed) performance  
circuit segment idle if not used by call (no sharing)  
Circuit switching: FDM and TDM  
frequenc  
tim  
frequency  
tim  
users  
Frequency Division Multiplexing (FDM)  
optical, electromagnetic frequencies divided into (narrow) frequency bands  
Time Division Multiplexing (TDM)  
time divided into slots  
each call allocated its own band, can  
transmit at max rate of that narrow  
band  
each call allocated periodic slot(s), can transmit at maximum rate of (wider)  
frequency band (only) during its time  
slot(s)  
Packet switching versus circuit switching example:  
1 Gb/s link  
each user:  
100 Mb/s when “active”  
active 10% of time  
Q: how many users can use this network under circuit- switching and packet  
switching?  
users  
1 Gbps  
link  
circuit-switching: 10 users  
Q: how did we get value 0.0004?  
A: HW problem (for those with  
course in probability only)  
packet switching: with 35 users,  
probability > 10 active at same time  
is less than .0004 *  
Alternative to Packet Switching: Circuit Switching Circuit Switching = end-to-end resources (bandwidth, buffer slots, link capacity) are reserved for a communication (a “call”) between source and destination.  
Example: If a link has 4 circuits, a call may occupy circuit #2 on one link and circuit #1 on another.  
Properties  
Dedicated resources: Once reserved, they cannot be used by others.  
Guaranteed performance: No congestion delay.  
Wasted capacity: If the circuit is idle, nobody else can use it.  
Circuit Switching Techniques  

### 1. FDM (Frequency Division Multiplexing)

Frequency spectrum is divided into narrow frequency bands.  
Each user gets a band → can transmit continuously, but only at that frequency.  
Example: Old telephone systems.  

### 2. TDM (Time Division Multiplexing)

Time is divided into slots.  
Each user gets a periodic time slot to send data.  
Example: Digital telephone systems.  
Packet Switching vs Circuit Switching  
Example Scenario:  
Link Capacity = 1 Gbps  
Each User Needs = 100 Mbps when active Activity = Each user is active 10% of the time Circuit Switching  
Each user requires 100 Mbps guaranteed.  
A 1 Gbps link can support:  
So, only 10 users can be supported under circuit switching.  
Packet Switching  
Packets are sent only when users are active (10% of the time).  
On average, only 10% of all users are active at a time.  
So the link can support more users statistically.  
With 35 users, the probability that more than 10 are active simultaneously is less than 0.0004 (0.04%).  
Meaning: In practice, 35 users can share the link with very little risk of overload.  
Analogy  
Circuit Switching: Like booking the whole road lane for your car, even if you’re not driving.  
Packet Switching: Like a shared road where many cars take turns, but congestion may happen if too many use it at once.  
Packet Switching (speed, efficiency, flexibility, etc.) for  
100 Mbps  
1 Gbps  
10 users  

## Lecture Notes: Packet vs Circuit Switching and Internet Structure

Packet switching versus circuit switching sometimes has data to send, but  
at other times not  
resource sharing  
simpler, no call setup  
excessive congestion possible: packet delay and loss due to buffer overflow  
protocols needed for reliable data transfer, congestion control  
Q: How to provide circuit-like behavior with packet- switching?  
“It’s complicated.” We’ll study various techniques that try to make packet switching as  
“circuit-like” as possible.  
Is packet switching a “slam dunk winner”?  
Q: human analogies of reserved resources (circuit switching) versus  
on-demand allocation (packet switching)?  
Internet structure: a “network of networks” hosts connect to Internet via access  
Internet Service Providers (ISPs)  
access ISPs in turn must be  
interconnected  
so that any two hosts (anywhere!) can send packets to each other  
resulting network of networks is very  
complex  
evolution driven by economics, national policies  
mobile network  
home network  
enterprise  
network  
national or global ISP  
local or  
regional ISP  
datacenter  
network  
content  
provider  
network  
Internet structure: a “network of networks”  
Question: given millions of access ISPs, how to connect them together?  
Packet Switching vs Circuit Switching  
Packet Switching  
g., web browsing, emails, streaming).  
Resource sharing: multiple users can share the same link.  
No call setup: start sending packets immediately.  
Issues:  
Congestion possible → packets experience delay or loss (buffers overflow).  
Needs protocols (TCP/IP) for reliable transfer & congestion control.  
Circuit Switching  
Dedicated resources reserved → predictable, guaranteed performance.  
Wasted resources if idle (nothing to send).  
Requires call setup phase before sending data.  
Q: How to make packet switching behave like circuit switching?  
Very complex: requires QoS (Quality of Service) techniques, traffic engineering, priority queues, etc.  
Modern Internet (packet-switched) tries to imitate circuit-like guarantees for applications like voice/video.  
Human Analogy  
Circuit Switching = Reserving a seat in a train → it’s yours the whole time, even if you don’t sit.  
Packet Switching = Uber ride-sharing → you use the car only when needed, others share when you don’t.  
Internet Structure: A Network of Networks The Internet is not a single network, but a huge interconnection of many networks.  
Hosts (computers, phones, IoT devices) connect via access ISPs (PTCL, Nayatel, Jazz 4G).  
Access ISPs must interconnect so any two devices worldwide can talk.  
Layers of Internet Structure  

### 1. Home/Enterprise Networks

WiFi routers, office LANs, etc. → connect end-users.  

### 2. Access ISPs

Local/regional providers that connect homes and small businesses.  

### 3. National/Global ISPs

Large ISPs with high-speed backbone networks.  
Interconnect multiple regional ISPs.  

### 4. Datacenter Networks

Host cloud services, apps, and storage (Google, AWS, Azure).  

### 5. Content Provider Networks

Google, Facebook, Netflix build their own networks to deliver content directly.  
Q: Given millions of access ISPs, how to connect them together?  
Through hierarchical interconnection:  
Local ISPs → connect to Regional ISPs → connect to National/Global ISPs.  
ISPs interconnect at IXPs (Internet Exchange Points) and through peering agreements.  
Economics + policies decide how connections are made (not just technology).  
ISP → Regional ISP → Global ISP → Content Providers)? It’ll make the “network of networks” idea crystal clear.  
what is access network  
Access Network  
The access network is the part of the Internet that connects end-users (you and me) to their Internet Service Provider (ISP).  
It’s basically the “last mile” connection between your device/home/office and the wider Internet.  
Examples of Access Networks  

### 1. Home Broadband

DSL (uses telephone line)  
Cable (HFC) (uses TV coax + fiber)  
Fiber-to-the-Home (FTTH)  

### 2. Wireless

WiFi (WLAN) – within a building (~100 ft range).  
Cellular (4G/5G) – wide-area, covers kilometers.  

### 3. Enterprise/University Access

Ethernet LANs, WiFi, or leased fiber lines connecting offices/campuses.  
Analogy  
Think of the Internet as a huge highway system:  
Access network = the small road from your house that takes you to the main highway.  
Core network = the highways that connect cities (ISPs, backbone).  
In short:  
The access network = how your device gets onto the Internet through your ISP.  
Network for  
Internet structure: a “network of networks” Option: connect each access ISP to one global transit ISP?  
Customer and provider ISPs have economic agreement.  
global  
ISP  
access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
ISP A  
ISP C  
ISP B  
Internet structure: a “network of networks” access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
But if one global ISP is viable business, there will be competitors ….  
ISP A  
ISP C  
ISP B  
Internet structure: a “network of networks” access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
But if one global ISP is viable business, there will be competitors …. who will want to be  
connected  
IXP  
peering link  
Internet exchange point  
IXP  
ISP A  
ISP C  
ISP B  
Internet structure: a “network of networks” access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
… and regional networks may arise to connect access nets to ISPs  
IXP  
IXP  
access  
net  
access  
net  
regional ISP  
access  
net  
access  
net  
access  
net  
ISP A  
ISP C  
ISP B  
Internet structure: a “network of networks” access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
… and content provider networks (e.g., Google, Microsoft, Akamai) may run their own  
network, to bring services, content close to end users  
IXP  
IXP  
access  
net  
access  
net  
access  
net  
access  
net  
access  
net  
Content provider network  
regional ISP  
Internet structure: a “network of networks” acce  
ss  
ISP  
acce  
ss  
ISP  
acce  
ss  
ISP  
acce  
ss  
ISP  
acce  
ss  
ISP  
acce  
ss  
ISP  
acce  
ss  
ISP  
acce  
ss  
ISP  
At “center”: small # of well-connected large networks “tier-1” commercial ISPs (e.g., Level 3, Sprint, AT&T, NTT), national & international  
coverage  
content provider networks (e.g., Google, Facebook): private network that connects its  
data centers to Internet, often bypassing tier-1, regional ISPs  
Regional  
ISP  
Regional  
ISP  
Tier 1  
ISP  
Tier 1  
ISP  
IXP  
Google  
IXP  
IXP  
Overview/roadmap:  
Network core: packet/circuit  
switching, internet structure  
Performance: loss, delay, throughput  
Security  
Protocol layers, service models  
History  
How do packet delay and loss occur?  
packets queue in router buffers, waiting for turn for transmission  
queue length grows when arrival rate to link (temporarily) exceeds output link capacity  
packet loss occurs when memory to hold queued packets fills up  
packet being transmitted (transmission delay) packets in buffers (queueing delay)  
free (available) buffers: arriving packets dropped (loss) if no free buffers  
Internet Structure: A "Network of Networks"  

### 1. Basic Idea

The Internet is not one single network, but a huge interconnection of thousands of networks.  
These include:  
Access networks (homes, offices, universities) Regional ISPs  
Global ISPs (Tier-1)  
Content provider networks (Google, Microsoft, Facebook, Netflix, Akamai, etc.)  

### 2. Option 1: One Global ISP

Imagine if all access ISPs connected to one big global ISP.  
Problem: if it works, competitors w  
This creates a need for multiple ISPs to interconnect.  

### 3. Competition: Multiple Global ISPs

Different global ISPs (e.g., AT&T, NTT, Level 3, Sprint).  
They must interconnect with each other, otherwise some customers cannot reach others.  
Interconnection happens at Internet Exchange Points (IXPs) and through peering links.  

### 4. Regional ISPs

Sits between access ISPs and global ISPs.  
Help smaller ISPs connect to the bigger backbone.  

### 5. Content Provider Networks

Companies like Google, Facebook, Netflix build their own networks:  
Connect data centers across the world.  
Often bypass Tier-1 ISPs and connect directly to regional ISPs or IXPs.  
Reduces cost + improves performance (closer to end users).  

### 6. At the Center

Small number of Tier-1 ISPs:  
Global coverage.  
Interconnect with each other.  
Example: AT&T, NTT, Level 3.  
Content provider networks are now as powerful as Tier-1 ISPs.  
Performance: Delay and Loss  

### 1. Sources of Delay

Transmission Delay: time to push packet bits into the link.  
Propagation Delay: time for signal to travel across medium.  
Queueing Delay: packets waiting in buffer if output link is busy.  
Processing Delay: time to examine packet header, check errors, etc.  

### 2. Packet Loss

Occurs when router buffer is full and new packets arrive.  
Lost packets must be retransmitted (by sender if using TCP).  
Analogy  
Think of a traffic jam at a toll booth:  
Cars entering booth = packets being transmitted.  
Cars waiting in line = queueing delay.  
Cars turned away because parking is full = packet loss.  
Up to now, you’ve covered:  
Access networks  
Network core: switching + Internet structure Performance issues (delay, loss, throughput) Do you  
transmission + propagation + queueing) so you can calculate delays in problems?  
what is link peering  
What is Link Peering?  
Peering = when two networks connect directly to each other to exchange traffic, without paying a third-party transit provider.  
The connection itself is called a peering link.  
Types of Peering  

### 1. Private Peering

Two ISPs (or an ISP + content provider) set up a direct physical link between their routers.  
Example: Google peers privately with an ISP to deliver YouTube videos faster.  

### 2. Public Peering

Happens at an Internet Exchange Point (IXP).  
Many networks bring one router each to the IXP and interconnect with others.  
Saves cost (one connection to IXP instead of many separate private links).  
Why Peering?  
Lower cost: Avoids paying upstream transit providers.  
Better performance: Fewer hops, lower delay.  
Redundancy: Multiple paths increase reliability.  
Control: ISPs manage traffic directly.  
Peering vs. Transit  
Transit: One ISP pays another (usually a bigger one) to carry all its traffic to the rest of the Internet.  
Peering: Two ISPs agree to exchange only their customers’ traffic (usually without money involved).  
In short:  
Link peering = direct connection between two networks (ISPs or content providers) to exchange traffic, usually at an IXP or private link, without using an upstream ISP.  
difference visually?  

## Lecture Notes: Packet Delay

Packet delay: four sources  
dproc: nodal processing  
check bit errors  
determine output link  
typically < microsecs  
dqueue: queueing delay  
time waiting at output link for  
transmission  
depends on congestion level of  
router  
propagation  
nodal  
processing  
queueing  
dnodal = dproc + dqueue + dtrans + dprop Caravan analogy  
car ~ bit; caravan ~ packet; toll  
service ~ link transmission  
toll booth takes 12 sec to service car (bit transmission time)  
“propagate” at 100 km/hr  
Q: How long until caravan is lined up  
before 2nd toll booth?  
time to “push” entire caravan  
through toll booth onto highway =  
12*10 = 120 sec  
time for last car to propagate from  
1st to 2nd toll both:  
100km/(100km/hr) = 1 hr  
A: 62 minutes  
toll booth  
toll booth  
(aka link)  
ten-car caravan  
(aka 10-bit packet)  
100 km  
100 km  
toll booth  
toll booth  
(aka link)  
toll booth  
Caravan analogy  
toll booth  
toll booth  
(aka router)  
ten-car caravan  
(aka 10-bit packet)  
100 km  
100 km  
suppose cars now “propagate” at 1000 km/hr and suppose toll booth now takes one min to service a car Q: Will cars arrive to 2nd booth before all cars serviced at first booth?  
A: Yes! after 7 min, first car arrives at second booth; three cars still at first  
booth  
Packet queueing delay (revisited)  
a: average packet arrival rate  
L: packet length (bits)  
R: link bandwidth (bit transmission rate) La/R ~ 0: avg. queueing delay small  
La/R -> 1: avg. queueing delay large  
La/R > 1: more “work” arriving is more than can be serviced - average delay infinite!  
La/R ~ 0  
La/R -> 1  
traffic intensity = La/R  
average queueing delay  
service rate of bits  
arrival rate of bits  
“traffic  
intensity”  
Packet  

### 1.  Four Sources of Packet Delay

When a packet travels through a router (node), it experiences nodal delay:  
: Processing delay  
Router checks for bit errors, determines output link.  
Very small (microseconds).  
: Queueing delay  
Time waiting in buffer before being transmitted.  
Depends on congestion (how busy the router is).  
Can range from microseconds → seconds.  
: Transmission delay  
Time to put all packet bits on the link.  
Formula:  
where  
= packet length (bits),  
= link bandwidth (bits/sec).  
: Propagation delay  
Time for the signal to physically travel across the link.  
Formula:  
where  = distance,  = propagation speed (~ m/s in fiber).  

### 2.  Caravan Analogy

Caravan = packet  
Car = bit  
Toll booth = router link  
Helps visualize transmission & propagation separately:  
Transmission delay (pushing onto the road):  
Cars enter the road one by one (like bits onto a link).  
Example: 10 cars × 12 sec each = 120 sec.  
Propagation delay (moving across the road):  
Time to drive from booth 1 → booth 2.  
Example: 100 km / 100 km/hr = 1 hour.  
Total delay until last car arrives at booth 2:  
Transmission delay + propagation delay = 120 sec + 3600 sec = 62 minutes.  

### 3.  Queueing Delay & Traffic Intensity

Key metric:  
= packet length (bits)  
= average packet arrival rate (packets/sec) = link bandwidth (bits/sec)  
Behavior:  
If  
→ very light load → small queueing delay.  
If  
→ congestion builds → large queueing delay.  
If  
→ arrival rate > service rate → infinite delay (packets drop).  
In summary:  
Delays come from processing, queueing, transmission, propagation.  
Caravan analogy shows difference between transmission (time to “load cars”) vs.  
propagation (time to “drive”).  
Queueing delay depends on traffic intensity — if arrivals exceed capacity, delay blows up.  
at the second booth) to make the caravan analogy clearer?  
nodal  
proc  
queue  
trans  
prop  
proc  
queue  
trans  
trans  
prop  
prop  
2 × 108  
Traffic Intensity =  
La  
La  
La  
La  
What is a Protocol?  
A protocol in networking is like a set of rules or an agreement that devices follow when they communicate.  
Just like humans follow grammar rules when speaking a language, computers and routers follow protocol rules when sending/receiving data.  
Key Things a Protocol Defines  
1. Format → How the data looks (like a letter with To, From, Subject).  

### 2. Order → Who speaks first, who replies after.

3. Actions → What to do if something goes wrong (e.g., data lost, corrupted).  
Example Analogy  
Imagine mailing a letter:  
Protocol rules:  
Envelope must have sender + receiver address.  
Post office follows fixed steps to deliver.  
If address is wrong, letter is returned.  
This is just like how Internet protocols work.  
Common Networking Protocols  
HTTP / HTTPS → For web browsing (rules for requesting and sending web pages).  
FTP → For file transfer.  
SMTP / POP3 / IMAP → For email.  
TCP → Ensures reliable, ordered delivery of data (like a careful postman).  
UDP → Faster but no guarantee (like throwing postcards, some may get lost).  
IP → Assigns addresses and delivers packets between devices.  
Ethernet / Wi-Fi (802.11) → Rules for sending data over cables or wireless.  
In short:  
A protocol = language of communication between computers, ensuring they understand each other and data moves correctly.  
often comes next in your networking slides)?  

## Lecture Notes: Real Internet Delays, Loss and Throughput

“Real” Internet delays and routes  
what do “real” Internet delay & loss look like?  
traceroute program: provides delay measurement from source to  
router along end-end Internet path towards destination.  
For all i:  
3 probes  
3 probes  
3 probes  
sends three packets that will reach router i on path towards destination  
(with time-to-live field value of i)  
router i will return packets to sender sender measures time interval between transmission and reply  
Real Internet delays and routes  
1 cs-gw (128.119.240.254) 1 ms 1 ms 2 ms  
2 border1-rt-fa5-1-0.gw.umass.edu (128.119.3.145) 1 ms 1 ms 2 ms  
3 cht-vbns.gw.umass.edu (128.119.3.130) 6 ms 5 ms 5 ms  
4 jn1-at1-0-0-19.wor.vbns.net (204.147.132.129) 16 ms 11 ms 13 ms  
5 jn1-so7-0-0-0.wae.vbns.net (204.147.136.136) 21 ms 18 ms 18 ms  
6 abilene-vbns.abilene.ucaid.edu (198.32.11.9) 22 ms 18 ms 22 ms  
7 nycm-wash.abilene.ucaid.edu (198.32.8.46) 22 ms 22 ms  
22 ms  
8 62.40.103.253 (62.40.103.253) 104 ms 109 ms 106 ms  
9 de2-1.de1.de.geant.net (62.40.96.129) 109 ms 102 ms  
104 ms  
10 de.fr1.fr.geant.net (62.40.96.50) 113 ms 121 ms 114 ms  
11 renater-gw.fr1.fr.geant.net (62.40.103.54) 112 ms 114 ms 112 ms  
12 nio-n2.cssi.renater.fr (193.51.206.13) 111 ms 114 ms 116 ms  
13 nice.cssi.renater.fr (195.220.98.102) 123 ms 125 ms 124 ms  
14 r3t2-nice.cssi.renater.fr (195.220.98.110) 126 ms 126 ms  
124 ms  
15 eurecom-valbonne.r3t2.ft.net (193.48.50.54) 135 ms 128 ms 133 ms  
16 194.214.211.25 (194.214.211.25) 126 ms 128 ms 126 ms  
17 * * *  
18 * * *  
19 fantasia.eurecom.fr (193.55.113.142) 132 ms 128 ms 136 ms  
traceroute: gaia.cs.umass.edu to www.eurecom.fr  
- Do some traceroutes from exotic countries at
www.traceroute.org  
- means no response (probe lost, router not replying)
3 delay measurements from  
gaia.cs.umass.edu to cs-gw.cs.umass.edu  
3 delay measurements  
to  
border1-rt-fa5-1-0.gw.umass.edu  
looks like delays  
decrease! Why?  
Packet loss  
queue (aka buffer) preceding link in buffer has finite capacity  
packet being transmitted  
buffer  
(waiting area)  
- Check out the Java applet for an interactive animation
(on publisher’s website) of queuing and loss packet arriving to  
full buffer is lost  
packet arriving to full queue dropped (aka lost) lost packet may be retransmitted by previous node, by source end system, or  
not at all  
Throughput  
throughput: rate (bits/time unit) at which bits are being sent from  
sender to receiver  
instantaneous: rate at given point in time average: rate over longer period of time server, with  
file of F bits  
to send to client  
link capacity  
Rs bits/sec  
link capacity  
Rc bits/sec  
server sends bits  
(fluid) into pipe  
pipe that can carry  
fluid at rate  
(Rs bits/sec)  
pipe that can carry  
fluid at rate  
(Rc bits/sec)  
Throughput  
Rs < Rc What is average end-end throughput?  
Rs bits/sec  
Rc bits/sec  
Rs > Rc What is average end-end throughput?  
link on end-end path that constrains end-end throughput bottleneck link  
Rs bits/sec  
Rc bits/sec  

### 1. Traceroute and Internet Delays

Traceroute is a tool that measures the path packets take from a source host to a destination host.  
It works by sending packets with an increasing TTL (Time-to-Live) value:  
TTL = 1 → only the first router responds.  
TTL = 2 → second router responds.  
… until the destination is reached.  
Each line in the traceroute output shows:  

### 1. Router name or IP.

### 2. Delay for 3 probe packets (in ms).

Why do delays sometimes decrease?  
Internet routing is dynamic — not all probes follow the exact same path.  
Queuing and congestion vary at each moment, so delay is not strictly increasing hop- by-hop.  
Sometimes an intermediate router is less busy → faster response than the previous one.  

### 2. Packet Loss

Routers have buffers (queues) before each output link.  
If packets arrive faster than they can be transmitted:  
They queue up.  
If the queue is full → new arriving packets are dropped (lost).  
Important: already-queued packets stay safe; new arrivals are lost.  
Recovery depends on higher layers:  
TCP retransmits lost packets.  
UDP may just ignore the loss.  

### 3. Throughput

Throughput = the actual data rate achieved between sender and receiver.  
There are two kinds:  
Instantaneous throughput → at a given moment.  
Average throughput → measured over a longer session.  
Example (like pipes carrying water):  
If sender rate Rs < receiver capacity Rc → Throughput = Rs (sender is the limit).  
If sender rate Rs > receiver capacity Rc → Throughput = Rc (receiver/bottleneck is the limit).  
The bottleneck link is the slowest link on the path that determines overall throughput.  
In short:  
Traceroute = shows real Internet path + delays (not always increasing).  
Packet loss = happens when queue is full; new packets get dropped.  
Throughput = limited by the bottleneck (min of sender rate & link capacity).  
10 MB file over mixed links) so you can see how bottleneck works in practice?  

## Probe Packets and a Formula Sheet with Practice Problems

- practice problems + probe packet definition. This will serve as your mini revision
notes .  
Probe Packet  
A probe packet is a special packet sent by tools like traceroute to measure the path and delay across routers.  
Each probe has a TTL (Time-to-Live) value that determines how many hops it can travel.  
When TTL expires, the router returns an ICMP “time exceeded” message back to the sender.  
By sending multiple probes with increasing TTLs, traceroute maps the route + measures delay to each router.  
Formula & Concept Sheet  

### 1. Transmission Delay (dtrans)

= packet length (bits)  
= link transmission rate (bps)  
Example:  
If  

### 2. Propagation Delay (dprop)

Example:  
If distance = 100 km, speed =  

### 3. Nodal Delay (dnodal)

: processing delay (tiny, < μs)  
: depends on congestion level  
: transmission delay  
: propagation delay  

### 4. Traffic Intensity

= packet length (bits)  
= average arrival rate (packets/sec)  
= link transmission rate (bps)  
If  
→ queue grows infinitely, packets lost.  

### 5. Throughput

Limited by the bottleneck link.  
= sender rate  
= slowest link on path  

### 6. Circuit Switching Capacity

If link capacity =  
, each user needs  
, then:  
Example:  
1 Gbps link, each user needs 100 Mbps → only 10 users can be supported.  

### 7. Packet Switching Capacity (Probabilistic)

If users are active only  
of time, we can support more than circuit switching because not all are active at once.  
Example:  
1 Gbps link  
Each user = 100 Mbps  
Each active 10% time → about 35 users supported (with very low probability of >10 active at once).  
Practice Problems  
Problem 1: Transmission Delay  
A 1,500-byte packet is sent over a 100 Mbps link.  
Find transmission delay.  
Problem 2: Propagation Delay  
A 500 km fiber link with propagation speed Find propagation delay.  
Problem 3: Nodal Delay  
bits  
Distance = 200 km, speed =  
Find nodal delay.  
Problem 4: Traffic Intensity  
Packets of length 2,000 bits arrive at average rate 500 packets/sec to a link of 1 Mbps.  
Find traffic intensity.  
Will there be queuing?  
Problem 5: Circuit vs Packet Switching  
2 Gbps link.  
Each user requires 200 Mbps when active.  
Users active 20% of time.  
(a) Max users with circuit switching.  
(b) Approx users with packet switching (use reasoning: can oversubscribe since only 20% active at a time).  
Problem 6: Throughput (Bottleneck)  
A file is sent from server to client:  
Server rate = 10 Mbps  
First link = 5 Mbps  
Second link = 20 Mbps  
Find end-to-end throughput.  
worked examples), or do you prefer them as homework exercises with answers hidden for self-practice?  
trans  
L = 10 Kbits R = 100 Mbps  
trans  
100 × 106  
10 × 103  
0.0001 s = 0.1 ms  
prop  
propagation speed  
distance  
2 × 10 m/s  
prop  
2 × 108  
100, 000  
0.0005 s = 0.5 ms  
nodal  
proc  
queue  
trans  
prop  
proc  
queue  
trans  
prop  
Traffic Intensity =  
La  
La/R > 1  
Throughput = min(R  
, R , … )  
Max Users =  
p%  
2.5 × 10 m/s  
proc  
2 μs  
queue  
5 ms  
L = 104  
R = 1 Mbps  
2 × 10 m/s
