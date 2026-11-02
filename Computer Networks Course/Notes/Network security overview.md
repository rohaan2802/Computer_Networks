# Network Security, Layers and the Application Layer

## Lecture Notes: Network Security

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
Lines of defense:  
authentication: proving you are who you say you are cellular networks provides hardware identity via SIM card; no such  
hardware assist in traditional Internet confidentiality: via encryption  
integrity checks: digital signatures prevent/detect tampering  
access restrictions: password-protected VPNs firewalls: specialized “middleboxes” in access and core networks:  
off-by-default: filter incoming packets to restrict senders, receivers,  
applications  
detecting/reacting to DOS attacks  
… lots more on security (throughout, Chapter 8) Overview/roadmap:  
Network core: packet/circuit  
switching, internet structure  
Performance: loss, delay, throughput  
Security  
Protocol layers, service models  
History  
Protocol “layers” and reference models Networks are complex,  
with many “pieces”:  
hosts  
routers  
links of various media  
applications  
protocols  
hardware, software  
Question: is there any hope  
of organizing structure of  
network?  
and/or our discussion of  
networks?  
Example: organization of air travel  
a series of steps, involving many services ticket (purchase)  
baggage (check)  
gates (load)  
runway takeoff  
airplane routing  
ticket (complain)  
baggage (claim)  
gates (unload)  
runway landing  
airplane routing  
airplane routing  
How would you define/discuss the system style notes from your Computer Networks course (FAST NUCES). The last line you wrote is:  
How to Define/Discuss the System  
The lecturer is drawing an analogy between computer networks and air travel. The idea is that both are complex systems with multiple steps, actors, and services. To make sense of them, we use layers of abstraction.  

### 1. Air Travel System Example

Air travel involves multiple steps, each with its own role:  
Ticket purchase → like application protocols (user-facing service) Baggage check & claim → like transport layer ensuring data is delivered to the right user  
Gates & loading/unloading → like network layer & routing (deciding where to send passengers/data)  
Runway takeoff/landing → like link layer handling the actual medium Airplane routing → like core of the network (moving packets between locations)  
Each stage is independent but coordinated. You don’t need to know the technical details of runway operations to buy a ticket.  

### 2. Network System

Similarly, a computer network is made of many components:  
Applications (web, email, video calls) Protocols (HTTP, TCP, IP, Ethernet)  
Hardware (routers, switches, links, servers) To manage the complexity, we use layered architecture:  
Application Layer (what users see: browsers, apps) Transport Layer (TCP/UDP: reliable delivery, error handling) Network Layer (IP: addressing, routing) Link Layer (Ethernet, Wi-Fi: physical transmission) Physical Layer (actual signals, wires, radio waves)  

### 3. Why Layers?

Modularity → each layer handles its own job without worrying about others.  
Simplification → complex system broken into smaller pieces.  
Interoperability → different hardware/software can work together if they follow the same layer protocols.  
Analogy with air travel: Passengers don’t care how the pilot flies → App developers don’t care how IP routes packets.  
So, when you’re asked “How would you define/discuss the system?” You’d say:  
side by side” in one page) so you can revise this quickly?  
“How would you define/discuss the system” The system (network) is organized using a layered architecture, just like air travel.  
Each layer/service performs a specific role, and together they provide end-to-end communication. This layering allows us to manage complexity, design secure and efficient protocols, and ensure interoperability between different technologies.  

## OSI Layers Explained Simply

OSI Layers (Easy Explanation)  
Think of sending a message over the Internet like air travel steps (ticket → baggage → gate → airplane). Each layer has its job:  
1. Application Layer – What the user sees (apps like WhatsApp, browser, email).  
Like buying a ticket – you request a service.  
2. Presentation Layer – Formats and secures the data (encryption, compression).  
Like translating languages or checking documents before travel.  
3. Session Layer – Starts, manages, and ends a communication (login session).  
Like airport control keeping track of your flight.  
4. Transport Layer – Ensures reliable delivery (TCP = guaranteed, UDP = fast).  
Like luggage tags making sure your bag arrives with you.  

### 5. Network Layer – Decides the path (IP addressing, routing).

Like airplane routing between airports.  
6. Data Link Layer – Handles direct connection between devices (Ethernet, Wi-Fi).  
Like boarding gate ensuring passengers get on the right plane.  
7. Physical Layer – Actual transmission of bits as signals (cables, radio waves).  
Like the runway and airplane physically moving.  
In short:  
Top 3 (Application, Presentation, Session) = Services for users.  
Middle (Transport, Network) = Delivery and addressing.  
Bottom 2 (Data Link, Physical) = Actual transmission over hardware.  
cheat sheet for quick revision)?  

## Lecture Notes: Layering and the Internet Protocol Stack

Example: organization of air travel  
ticket (purchase)  
baggage (check)  
gates (load)  
runway takeoff  
airplane routing  
ticket (complain)  
baggage (claim)  
gates (unload)  
runway landing  
airplane routing  
airplane routing  
ticketing service  
baggage service  
gate service  
runway service  
routing service  
layers: each layer implements a service via its own internal-layer actions  
relying on services provided by layer below Why layering?  
Approach to designing/discussing complex systems:  
explicit structure allows identification, relationship of system’s pieces  
layered reference model for discussion modularization eases maintenance, updating of system  
change in layer's service implementation:  
transparent to rest of system  
e.g., change in gate procedure doesn’t affect rest of system  
Layered Internet protocol stack  
application: supporting network applications  
HTTP, IMAP, SMTP, DNS  
transport: process-process data transfer  
TCP, UDP  
network: routing of datagrams from source to destination  
IP, routing protocols  
link: data transfer between neighboring network elements  
Ethernet, 802.11 (WiFi), PPP  
physical: bits “on the wire”  
link  
application  
network  
transport  
physical  
application  
transport  
network  
link  
physical  
Services, Layering and Encapsulation  
source  
transport-layer protocol encapsulates  
application-layer message, M, with transport layer-layer header Ht to create a  
transport-layer segment  
Ht used by transport layer protocol to implement its service  
application  
transport  
network  
link  
physical  
destination  
application  
transport  
network  
link  
physical  
Transport-layer protocol transfers M (e.g., reliably) from one  
process to another, using services of network layer Application exchanges messages to implement some application service using services of transport layer Services, Layering and Encapsulation  
source  
application  
transport  
network  
link  
physical  
destination  
application  
transport  
network  
link  
physical  
Transport-layer protocol transfers M (e.g., reliably) from one process to another, using services of network layer network-layer protocol encapsulates  
transport-layer segment [Ht | M] with network layer-layer header Hn to create a  
network-layer datagram  
Hn used by network layer protocol to  
implement its service  
Network-layer protocol transfers transport-layer segment [Ht | M] from one host to another, using link layer services  
application  
transport  
network  
link  
physical  
destination  
application  
transport  
network  
link  
physical  
link-layer protocol encapsulates network datagram [Hn| [Ht |M], with link-layer header Hl to create a link-layer frame  
Link-layer protocol transfers datagram [Hn| [Ht |M] from host to neighboring host, using network-layer services  
Let me explain this in a short and easy way while keeping it tied to the examples given (air travel + Internet layers).  

### 1. Why Layering?

Networks are complex systems (apps, routers, links, protocols, etc.).  
To manage complexity, we divide into layers (like airport services).  
Each layer provides a service, and it only needs to know:  
What service it offers to the layer above.  
What service it needs from the layer below.  
Example: Gate service in airports doesn’t care about how baggage is checked — it just assumes baggage is handled by the layer below.  

### 2. Internet Protocol Stack (5 Layers)

### 1. Application Layer – Apps (HTTP, SMTP, DNS).

Like ticketing service (buy/complain).  

### 2. Transport Layer – Reliable delivery between processes (TCP/UDP).

Like baggage tags ensuring your bag arrives safely.  
3. Network Layer – Routing datagrams host-to-host (IP, routing protocols).  
Like airplane routing from one airport to another.  
4. Link Layer – Data transfer between direct neighbors (Ethernet, Wi-Fi).  
Like boarding gate ensuring you get on the correct plane.  

### 5. Physical Layer – Bits on the medium (cables, wireless signals).

Like the runway carrying the actual plane.  

### 3. Encapsulation (Very Important)

When data goes down the layers, each layer adds its own header:  
Application data = M  
Transport layer adds header = [Ht | M] → segment Network layer adds header = [Hn | Ht | M] → datagram Link layer adds header = [Hl | Hn | Ht | M] → frame Each lower layer wraps (encapsulates) the data from above.  
At the destination, the process reverses: headers are removed step by step.  
Think of it like sending a gift:  
You put the item (message M) in a box (Ht).  
Then another bigger box (Hn).  
Then wrap it again for shipping (Hl).  
At the other end, the receiver unwraps layer by layer until the actual gift (M) is revealed.  

### 4. Key Takeaway

Layering = modular system design (easy to update/change).  
Encapsulation = each layer adds headers to provide its service.  
Services flow downward (application uses transport, transport uses network, …) and data flows upward at the receiver.  
encapsulation flow) for you as a printable cheat sheet? That way you can revise layering + encapsulation visually in seconds.  
Services, Layering and Encapsulation  
source  
application  
transport  
network  
link  
physical  
destination  
application  
transport  
network  
link  
physical  
Encapsulation: an  
end-end view  
source  
segment  
datagram  
destination  
router  
switch  
message  
end in a  
layered network, and how devices like routers and switches handle the data.  
1⃣ End-to-End Encapsulation (Source → Destination) When a message M travels from source to destination:  

### 1. Transport Layer adds header Ht → creates segment [Ht | M] .

### 2. Network Layer adds header Hn → creates datagram [Hn | Ht | M] .

### 3. Link Layer adds header Hl → creates frame [Hl | Hn | Ht | M] .

### 4. Physical Layer sends bits over the wire/wireless.

2⃣ Encapsulation Through the Network Devices Router: Looks at the network-layer header (Hn) to decide where to forward the packet.  
It does not care about Ht or M.  
Example: Like an airport directing planes to the correct airport, not worrying about passengers’ baggage details.  
Switch: Looks at the link-layer header (Hl) to forward frames to the correct port.  
Example: Like a gate attendant directing passengers to the correct plane.  
3⃣ Simplified Flow Table  
Layer  
Encapsulation  
Purpose  
Application  
Original message  
Transport  
Ht + M  
Reliable delivery, process-to-process  
Network  
Hn + [Ht + M]  
Routing from source to destination  
Link  
Hl + [Hn + Ht + M]  
Delivery to next hop / neighbor  
Physical  
Bits  
Transmit over wire/wireless  
Flow: Source → Segment → Datagram → Frame → Bits → Frame → Datagram → Segment → Message → Destination  
Bottom line:  
Encapsulation wraps data layer by layer at the sender.  
Decapsulation unwraps it at the receiver.  
Routers and switches only handle the headers relevant to their layer.  
This is the end-to-end principle in networking.  
destination with all headers. It makes encapsulation & layering super easy to memorize.  
At the destination, each layer removes its header and passes the remaining data upward:  
“Physical → Link → Network → Transport → Application → delivers original message M .”  
Key point: Each device only reads the header relevant to its layer, and the rest of the data is passed along untouched.  

## Lecture Notes: Internet History

Internet history  
1961: Kleinrock - queueing  
theory shows effectiveness of  
packet-switching  
1964: Baran -  
packet-switching in military  
nets  
1967: ARPAnet conceived by  
Advanced Research Projects  
Agency  
1969: first ARPAnet node  
operational  
1972:  
ARPAnet public demo  
NCP (Network Control Protocol)  
first host-host protocol  
first e-mail program  
ARPAnet has 15 nodes  
Internet history  
1970: ALOHAnet satellite network in  
Hawaii  
1974: Cerf and Kahn - architecture for interconnecting networks  
1976: Ethernet at Xerox PARC  
late70’s: proprietary architectures:  
DECnet, SNA, XNA  
1979: ARPAnet has 200 nodes  
1972-1980: Internetworking, new and proprietary networks Cerf and Kahn’s internetworking  
principles:  
minimalism, autonomy - no internal  
changes required to interconnect  
networks  
best-effort service model  
stateless routing  
decentralized control  
define today’s Internet architecture  
Internet history  
1983: deployment of TCP/IP  
1982: smtp e-mail protocol defined  
1983: DNS defined for  
name-to-IP-address translation  
1985: ftp protocol defined  
1988: TCP congestion control  
new national networks: CSnet,  
BITnet, NSFnet, Minitel  
100,000 hosts connected to  
confederation of networks  
Internet history  
early 1990s: ARPAnet  
decommissioned  
1991: NSF lifts restrictions on  
commercial use of NSFnet  
(decommissioned, 1995)  
early 1990s: Web  
hypertext [Bush 1945, Nelson 1960’s]  
HTML, HTTP: Berners-Lee  
1994: Mosaic, later Netscape  
late 1990s: commercialization of the Web late 1990s – 2000s:  
more killer apps: instant  
messaging, P2P file sharing  
network security to forefront  
est. 50 million host, 100 million+  
users  
backbone links running at Gbps  
Internet history  
aggressive deployment of broadband home access (10- 100’s Mbps)  
2008: software-defined networking (SDN) increasing ubiquity of high-speed wireless access: 4G/5G, WiFi  
service providers (Google, FB, Microsoft) create their own networks  
bypass commercial Internet to connect “close” to end user, providing “instantaneous”  
access to social media, search, video content, … enterprises run their services in “cloud” (e.g., Amazon Web Services, Microsoft  
Azure)  
rise of smartphones: more mobile than fixed devices on Internet (2017)  
~15B devices attached to Internet (2023, statista.com) 2005-present: scale, SDN, mobility, cloud Chapter 1: summary  
We’ve covered a “ton” of material!  
Internet overview  
what’s a protocol?  
network edge, access network, core  
packet-switching versus circuit-switching Internet structure  
performance: loss, delay, throughput  
layering, service models  
security  
history  
You now have:  
context, overview,  
vocabulary, “feel” of  
networking  
more depth, detail,  
and fun to follow!  
Thank you for sticking up through this week!  
Any Questions?  
Coming Up …..  
Principles of network applications  
Web and HTTP  
Cookies and web caches  
1⃣ Internet History (Timeline Highlights) Year  
Event / Milestone  
Kleinrock: queueing theory → packet switching feasible Baran: packet-switching for military networks ARPAnet conceived (DARPA)  
First ARPAnet node operational  
ALOHA network in Hawaii (satellite network) ARPAnet public demo; first email program; NCP protocol Cerf & Kahn: internetworking architecture Ethernet developed at Xerox PARC  
Late 70s  
Proprietary networks: DECnet, SNA, XNA Deployment of TCP/IP; DNS defined (1983)  
FTP protocol defined  
TCP congestion control introduced  
Early 1990s  
ARPAnet decommissioned; NSF allows commercial use World Wide Web: HTML + HTTP (Berners-Lee) Mosaic browser, later Netscape  
Late 1990s-2000s  
Web commercialization, IM, P2P, network security becomes key  
2005+  
Broadband, SDN, cloud, mobile devices, 4G/5G, WiFi Mobile devices outnumber fixed devices ~15B devices connected globally  
Key Principles of Early Internet (Cerf & Kahn):  
Minimalism & autonomy → networks can interconnect without internal changes Best-effort service  
Stateless routing  
Decentralized control  
2⃣ Chapter 1 Summary (Networking Overview) Protocols → rules for communication between devices.  
Network Edge & Core → devices/users at edge, routers/switches in core.  
Packet-Switching vs Circuit-Switching → packets more efficient, flexible.  
Internet Structure → layered architecture (application → transport → network → link → physical).  
Performance Metrics → loss, delay, throughput.  
Security → authentication, encryption, firewalls, DoS protection.  
History → from ARPAnet → TCP/IP → WWW → broadband/mobile/cloud.  
3⃣ Key Takeaways  

### 1. Networking evolved from military research to global Internet.

### 2. Layering and encapsulation simplify complexity.

3. Internet principles: decentralized, scalable, best-effort delivery.  

### 4. Modern networks: high-speed, mobile, cloud-based, highly secure.

OSI/Internet layers  
Encapsulation diagram  
Air travel analogy  
Internet history timeline  
This w  

## Lecture Notes: Application Layer

Application layer: overview  
Principles of network  
applications  
Web and HTTP  
E-mail, SMTP, IMAP  
The Domain Name System  
DNS  
socket programming with  
UDP and TCP  
Application layer: overview  
Our goals:  
conceptual and  
implementation aspects of  
application-layer protocols  
transport-layer service  
models  
client-server paradigm  
peer-to-peer paradigm  
learn about protocols by  
examining popular  
application-layer protocols  
and infrastructure  
HTTP  
SMTP, IMAP  
DNS  
programming network  
applications  
socket API  
Some network apps  
social networking  
Web  
text messaging  
e-mail  
multi-user network games  
streaming stored video  
(YouTube, Hulu, Netflix)  
P2P file sharing  
voice over IP (e.g., Skype)  
real-time video conferencing  
(e.g., Zoom)  
Internet search  
remote login  
Q: your favorites?  
Creating a network app  
write programs that:  
run on (different) end systems  
communicate over network  
e.g., web server software  
communicates with browser software  
no need to write software for  
network-core devices  
network-core devices do not run user  
applications  
applications on end systems allows  
for rapid app development,  
propagation  
understand way:  
Application Layer Overview  
1⃣ Goals of Application Layer  
Understand concepts and implementation of application-layer protocols.  
Learn transport-layer service models (TCP vs UDP).  
Understand paradigms:  
Client-server → centralized service provider (web server).  
Peer-to-peer (P2P) → direct communication between peers (file sharing).  
Study popular application protocols:  
HTTP → web browsing  
SMTP / IMAP → email  
DNS → translating names to IP addresses Learn programming network applications using sockets.  
2⃣ Examples of Network Applications  
Social networking (Facebook, Instagram) Web browsing (HTTP/HTTPS)  
Email (SMTP, IMAP)  
Text messaging / chat apps  
Multi-user games  
Streaming video (YouTube, Netflix)  
P2P file sharing (BitTorrent)  
Voice over IP (Skype, WhatsApp calls)  
Real-time video conferencing (Zoom, Teams) Internet search (Google, Bing)  
Remote login (SSH, Telnet)  
3⃣ How Network Applications Work  
End systems (your laptop, phone, or server) run the app programs.  
Apps communicate over the network using protocols (HTTP, SMTP, etc.).  
Network-core devices (routers, switches) do not run applications.  
Advantage: apps can be developed rapidly without modifying the network.  
4⃣ Paradigms  
Paradigm  
Description  
Example  
Client-Server  
Central server provides service to clients Web browsing (server →  
browser)  
Peer-to-Peer  
Peers communicate directly  
P2P file sharing (BitTorrent)  
Bottom line:  
Application layer enables user-facing apps to communicate.  
Uses underlying transport (TCP/UDP) to send data reliably or quickly.  
Focus is on end systems, so new apps can be deployed without changing the network itself.  
protocols, transport services, and paradigms so it’s super easy to memorize.  
Key Idea: All apps run on end systems, not core network devices.  
Client-server paradigm  
server:  
always-on host  
permanent IP address  
often in data centers, for scaling  
clients:  
contact, communicate with server  
may be intermittently connected  
may have dynamic IP addresses  
do not communicate directly with  
each other  
examples: HTTP, IMAP, FTP  
Application Layer: 2-#  
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
Peer-peer architecture  
no always-on server  
arbitrary end systems directly  
communicate  
peers request service from other  
peers, provide service in return to  
other peers  
self scalability – new peers bring new service capacity, as well as new service demands  
peers are intermittently connected  
and change IP addresses  
complex management  
example: P2P file sharing  
Application Layer: 2-#  
Processes communicating  
process: program running  
within a host  
within same host, two  
processes communicate  
using inter-process  
communication (defined by  
OS)  
processes in different hosts  
communicate by exchanging  
messages  
note: applications with  
P2P architectures have  
client processes &  
server processes  
client process: process that  
initiates communication  
server process: process  
that waits to be contacted  
clients, servers  
Peer (P2P) architectures and  
processes in network communication.  
1⃣ Client-Server Paradigm  
Server:  
Always-on host with permanent IP.  
Often in data centers to handle many clients.  
Provides services to clients.  
Client:  
Connects to server to request/receive services.  
May connect intermittently.  
Can have dynamic IP addresses.  
Clients do not communicate directly with each other.  
Examples: HTTP (web browsing), IMAP (email), FTP (file transfer) Network layers involved:  
Clients → home/mobile/enterprise networks → ISP → server network/datacenter → content provider.  
2⃣ Peer-to-Peer (P2P) Architecture  
No always-on server.  
End systems (peers) communicate directly with each other.  
Each peer requests and provides service.  
Self-scalable: more peers = more capacity and more demand.  
Peers are often intermittently connected, IPs can change.  
Management is more complex than client-server.  
Example: P2P file sharing (BitTorrent) 3⃣ Processes Communicating  
Process = program running inside a host.  
Same host → communicate via OS inter-process communication.  
Different hosts → communicate by exchanging messages over the network.  
In networked applications:  
Client process → initiates communication (e.g., browser requesting a webpage).  
Server process → waits for requests (e.g., web server responding to browser).  
Quick Comparison Table  
Feature  
Client-Server  
Peer-to-Peer (P2P)  
Always-on server?  
No  
Direct client-client communication  
No  
Scalability  
Server-limited  
Self-scalable  
Complexity  
Lower  
Higher  
Example  
Web, Email, FTP  
BitTorrent  
Bottom line:  
Client-server = centralized, easier to manage.  
P2P = decentralized, scalable, but more complex.  
Processes = units of communication; client initiates, server waits/responds.  
including:  
Client-server vs P2P  
Process communication  

## Lecture Notes: Sockets and Transport Services

Sockets  
process sends/receives messages to/from its socket socket analogous to door  
sending process shoves message out the door sending process relies on transport infrastructure on other side of  
door to deliver message to socket at receiving process two sockets involved: one on each side Internet  
controlled  
by OS  
controlled by  
app developer  
transport  
application  
physical  
link  
network  
proce  
ss  
transport  
application  
physical  
link  
network  
proce  
ss  
socket  
Application Layer: 2-#  
Addressing processes  
to receive messages, process  
must have identifier  
host device has unique 32-bit  
IP address  
Q: does IP address of host on  
which process runs suffice for  
identifying the process?  
identifier includes both IP address  
and port numbers associated with  
process on host.  
example port numbers:  
HTTP server: 80  
mail server: 25  
to send HTTP message to  
gaia.cs.umass.edu web server:  
IP address: 128.119.245.12  
port number: 80  
more shortly…  
A: no, many processes  
can be running on  
same host  
Application Layer: 2-#  
An application-layer protocol defines:  
types of messages exchanged,  
e.g., request, response  
message syntax:  
what fields in messages &  
how fields are delineated  
message semantics  
meaning of information in  
fields  
rules for when and how  
processes send & respond to  
messages  
open protocols:  
defined in RFCs, everyone  
has access to protocol  
definition  
allows for interoperability  
e.g., HTTP, SMTP  
proprietary protocols:  
e.g., Skype, Zoom  
Application Layer: 2-#  
What transport service does an app need?  
data integrity  
some apps (e.g., file transfer,  
web transactions) require  
100% reliable data transfer  
other apps (e.g., audio) can  
tolerate some loss  
timing  
some apps (e.g., Internet  
telephony, interactive games)  
require low delay to be “effective”  
throughput  
some apps (e.g., multimedia)  
require minimum amount of  
throughput to be “effective”  
other apps (“elastic apps”)  
make use of whatever  
throughput they get  
security  
encryption, data integrity,  
Application Layer: 2-#  
Transport service requirements: common apps application  
file transfer/download  
e-mail  
Web documents  
real-time audio/video  
streaming audio/video  
interactive games  
text messaging  
data loss  
no loss  
no loss  
no loss  
loss-tolerant  
loss-tolerant  
loss-tolerant  
no loss  
throughput  
elastic  
elastic  
elastic  
audio: 5Kbps-1Mbps  
video:10Kbps-5Mbps  
same as above  
Kbps+  
elastic  
time sensitive?  
no  
no  
no  
yes, 10’s msec  
yes, few secs  
yes, 10’s msec  
yes and no  
also what is bit torrent  
1⃣ Sockets (Process Communication Doors) Socket = an endpoint for sending/receiving messages in a process.  
Analogy: Socket is like a door:  
Sending process → pushes message out the door.  
Transport infrastructure → delivers message to socket (door) of receiving process.  
Two sockets involved: one at sender, one at receiver.  
Controlled by:  
OS → manages low-level socket operations.  
Application developer → decides what data to send and when.  
2⃣ Addressing Processes  
IP address = identifies host machine.  
Port number = identifies process on that host.  
Together → uniquely identifies a process on the network.  
Example:  
Web server: IP = 128.119.245.12 , Port = 80 Email server: Port = 25  
3⃣ Application-Layer Protocols  
Define how apps talk to each other:  

### 1. Types of messages: request, response

### 2. Syntax: fields & formatting of messages

### 3. Semantics: meaning of fields

### 4. Rules: when/how messages are sent & responded

Open protocols → standardized, publicly defined (HTTP, SMTP, DNS) Proprietary protocols → private (Skype, Zoom) 4⃣ Transport Service Requirements  
Different applications have different needs from transport layer:  
Application  
Loss Tolerance  
Throughput  
Time Sensitivity  
File transfer / download  
No loss  
Elastic  
No  
Email  
No loss  
Elastic  
No  
Web documents  
No loss  
Elastic  
No  
Real-time audio/video  
Loss-tolerant  
5Kbps–1Mbps  
10’s ms  
Streaming audio/video  
Loss-tolerant  
10Kbps–5Mbps  
few sec  
Interactive games  
Loss-tolerant  
Kbps+  
10’s ms  
Text messaging  
No loss  
Elastic  
Sometimes  
Data integrity → important for file transfer, email, web.  
Timing → crucial for telephony, interactive games.  
Throughput → multimedia apps need minimum bandwidth.  
Security → encryption, integrity checks.  
5⃣ BitTorrent (Example of P2P)  
BitTorrent = a peer-to-peer (P2P) file sharing protocol.  
Instead of downloading from a single server:  
You download pieces of a file from multiple peers simultaneously.  
You also upload pieces you have to other peers.  
Advantages:  
Fast downloads (many peers share the load) Self-scalable → more peers = more capacity Reduces server bandwidth cost  
Sockets  
Client-server vs P2P  
Transport requirements  
BitTorrent flow  
This w  
Many processes can run on the same host → need port numbers.  
Example: You download a movie in parts from 100 peers and also share those parts with others.  
page cheat sheet for the Application Layer including sockets, architectures, transport requirements, and BitTorrent. You can use this for quick revision.  
Application Layer Cheat Sheet  
1⃣ Network Application Architectures  
Client-Server  
Server: always-on, permanent IP, provides service Client: intermittent connection, may have dynamic IP, requests service Clients don’t communicate with each other Examples: HTTP, FTP, IMAP  
Paradigm: client process initiates; server process waits/responds Peer-to-Peer (P2P)  
No always-on server; peers communicate directly Peers request & provide services  
Self-scalable; IPs can change; intermittent connections Example: BitTorrent, P2P file sharing  
Each peer can have client & server processes 2⃣ Processes & Sockets  
Process: program running on a host  
Client process: initiates communication Server process: waits for requests  
Socket: endpoint for sending/receiving messages (like a “door”) Two sockets per connection: sender & receiver Controlled by OS & application  
Process Identification  
IP address + Port number → uniquely identifies a process on a host Example: Web server → IP 128.119.245.12 , port 80 3⃣ Application-Layer Protocols  
Define how processes communicate:  
Message Types: request, response  
Syntax: message fields & format  
Semantics: meaning of fields  
Rules: when/how messages are sent/responded Protocol Type  
Example  
Open/Proprietary  
Open  
HTTP, SMTP, DNS  
Open  
Proprietary  
Skype, Zoom  
Proprietary  
4⃣ Transport Service Requirements  
Application  
Loss Tolerance  
Throughput  
Time Sensitive?  
File transfer / download  
No loss  
Elastic  
No  
Email  
No loss  
Elastic  
No  
Web documents  
No loss  
Elastic  
No  
Real-time audio/video  
Loss-tolerant  
5Kbps–1Mbps  
10’s ms  
Streaming audio/video  
Loss-tolerant  
10Kbps–5Mbps  
Few seconds  
Interactive games  
Loss-tolerant  
Kbps+  
10’s ms  
Text messaging  
No loss  
Elastic  
Sometimes  
Data integrity → for file/web/email  
Timing → for telephony, games  
Throughput → for multimedia apps  
Security → encryption, integrity checks 5⃣ BitTorrent (P2P Example)  
Peer-to-peer file sharing protocol  
Download pieces of a file from multiple peers Upload pieces you have to other peers simultaneously Advantages:  
Fast downloads  
Self-scalable  
Reduces server bandwidth  
This cheat sheet covers everything you need to quickly revise the Application Layer, sockets, architectures, transport requirements, and BitTorrent.  
Client-server vs P2P  
Socket communication  
Encapsulation & transport services  
BitTorrent flow  
This would be even easier to memorize. Download a movie from 100 peers; each peer shares parts with others.  

## What Latency Is

Latency (Network Delay)  
Definition:  
Latency is the time it takes for a packet of data to travel from the source to the destination across a network.  
Think of it as the “travel time” for your message or request.  
Components of Latency  
1. Processing delay – time routers/switches take to examine the packet header.  
2. Queuing delay – time a packet waits in router/switch queues before being transmitted.  
3. Transmission delay – time to push all packet bits onto the link ( Packet size / Link bandwidth ).  

### 4. Propagation delay – time for a signal to travel through the medium

(cable/fiber/wireless), depends on distance and speed of the medium.  
Formula (Approximate)  
Propagation delay:  
= distance  
= signal speed in medium (~2×10⁸ m/s in fiber) Transmission delay:  
= packet length (bits)  
= link bandwidth (bits/sec)  
Example:  
Sending 1,000-bit packet over 1 Mbps link, 200 km distance.  
Transmission delay:  
sec = 1 ms  
Propagation delay:  
sec = 1 ms  
Total ≈ 2 ms + any processing/queuing delays Key Points  
Low latency → faster response (important for gaming, video calls).  
High latency → noticeable delay (bad for real-time apps).  
Latency is different from bandwidth, which is how much data can flow per second.  
latency with arrows from source → destination, so it’s super easy to remember.  
Total Latency = Processing + Queuing + Transmission + Propagation d/s  
L/R  
1000/1,000,000 = 0.001  
200,000/2 × 10 ≈  
0.001  
Internet transport protocols services  
TCP service:  
reliable transport between sending  
and receiving process  
flow control: sender won’t  
overwhelm receiver  
congestion control: throttle sender  
when network overloaded  
connection-oriented: setup required  
between client and server processes  
does not provide: timing, minimum  
throughput guarantee, security  
UDP service:  
unreliable data transfer  
between sending and receiving  
process  
does not provide: reliability,  
flow control, congestion  
control, timing, throughput  
guarantee, security, or  
connection setup.  
Q: why bother? Why  
is there a UDP?  
Application Layer: 2-#  
Internet applications, and transport  
protocols  
application  
file transfer/download  
e-mail  
Web documents  
Internet telephony  
streaming audio/video  
interactive games  
application  
layer protocol  
FTP [RFC 959]  
SMTP [RFC 5321]  
HTTP 1.1 [RFC 7320]  
SIP [RFC 3261], RTP [RFC  
3550], or proprietary  
HTTP [RFC 7320], DASH  
WOW, FPS (proprietary)  
transport protocol  
TCP  
TCP  
TCP  
TCP or UDP  
TCP  
UDP or TCP  
Application Layer: 2-#  
Securing TCP  
Vanilla TCP & UDP sockets:  
no encryption  
cleartext passwords sent into socket  
traverse Internet in cleartext (!)  
Transport Layer Security (TLS)  
provides encrypted TCP connections  
data integrity  
end-point authentication  
TSL implemented in  
application layer  
apps use TSL libraries, that  
use TCP in turn  
cleartext sent into “socket”  
traverse Internet encrypted  
more: Chapter  
Web and HTTP  
First, a quick review…  
web page consists of objects, each of which can be stored on  
different Web servers  
object can be HTML file, JPEG image, Java applet, audio file,…  
web page consists of base HTML-file which includes several  
referenced objects, each addressable by a URL, e.g., www.someschool.edu/someDept/pic.gif  
host name  
path name  
Transport Layer: 3-#  
HTTP overview  
HTTP: hypertext transfer protocol  
Web’s application-layer protocol  
client/server model:  
client: browser that requests,  
receives, (using HTTP protocol) and  
“displays” Web objects  
server: Web server sends (using  
HTTP protocol) objects in response  
to requests  
HTTP request  
HTTP response  
HTTP request  
HTTP response  
iPhone running  
Safari browser  
PC running  
Firefox browser  
server running  
Apache Web  
server  
Transport Layer: 3-#  
HTTP overview (continued)  
HTTP uses TCP:  
client initiates TCP connection  
(creates socket) to server, port 80  
server accepts TCP connection  
from client  
HTTP messages (application-layer  
protocol messages) exchanged  
between browser (HTTP client) and  
Web server (HTTP server)  
TCP connection closed  
HTTP is “stateless”  
server maintains no  
information about past client  
requests  
protocols that maintain “state”  
are complex!  
past history (state) must be  
maintained  
if server/client crashes, their views  
of “state” may be inconsistent, must  
be reconciled  
1⃣ Internet Transport Protocols  
TCP (Transmission Control Protocol)  
Reliable: guarantees delivery of data without errors or loss.  
Flow control: sender won’t overwhelm the receiver.  
Congestion control: slows sending rate if network is overloaded.  
Connection-oriented: requires setup (handshake) before sending data.  
Does NOT guarantee: timing, minimum throughput, security.  
Use cases: web browsing (HTTP), email (SMTP), file transfer (FTP).  
UDP (User Datagram Protocol)  
Unreliable: no guarantees for delivery, ordering, or duplication.  
No flow/congestion control  
Connectionless: no handshake required.  
Lightweight and fast → low overhead.  
Use cases: Internet telephony, streaming audio/video, online gaming, DNS queries.  
2⃣ Application Examples & Transport Protocols Application  
App-layer Protocol  
Transport Protocol  
File transfer / download  
FTP [RFC 959]  
TCP  
Email  
SMTP [RFC 5321]  
TCP  
Web documents  
HTTP [RFC 7320]  
TCP  
Internet telephony  
SIP [RFC 3261], RTP [RFC 3550]  
TCP or UDP  
Streaming audio/video  
HTTP/DASH  
TCP or UDP  
Online games  
Proprietary  
UDP  
3⃣ Securing TCP Connections  
Problem: Standard TCP/UDP sockets send cleartext data, including passwords → easily intercepted.  
Solution: TLS (Transport Layer Security):  
Encrypts data sent over TCP  
Ensures data integrity  
Provides end-point authentication  
Applications use TLS libraries over TCP → secure communication 4⃣ Web & HTTP Overview  
Web Pages  
Consist of objects: HTML, images, audio, Java applets, etc.  
Base HTML file references multiple objects → each can be on different servers.  
Objects are identified by URL:  
www.someschool.edu → host name  
/someDept/pic.gif → path  
HTTP Protocol  
Hypertext Transfer Protocol → Web’s application-layer protocol Client-server model:  
Client: browser → requests & displays objects Server: web server → responds to requests  
TCP connection:  

### 1. Client initiates TCP connection to server port 80

### 2. HTTP messages exchanged

### 3. TCP connection closed

Stateless:  
Server does not remember past requests Keeps protocol simple; avoids maintaining session state Stateful protocols are more complex (must handle crashes, inconsistencies) Key Takeaways  
TCP = reliable, connection-oriented → web, email, file transfer  
UDP = fast, lightweight, connectionless → streaming, VoIP, games  
TLS = secures TCP data → prevents interception & tampering  
HTTP = client-server, stateless, uses TCP → transfers web page objects server flow — this is super useful for exams and visual memory.  
Q: Why UDP?  
“Some applications can tolerate small loss but need low delay and minimal overhead.”  
“Example: Video call can skip a lost packet instead of waiting.” bash  
www.someschool.edu/someDept/pic.gif  

## Lecture Notes: HTTP Connections and Messages

HTTP connections: two types  
Non-persistent HTTP  
TCP connection opened  
at most one object sent  
over TCP connection  
TCP connection closed  
downloading multiple  
objects required multiple  
connections  
Persistent HTTP  
TCP connection opened to  
a server  
multiple objects can be  
sent over single TCP  
connection between client,  
and that server  
TCP connection closed  
Transport Layer: 3-#  
Non-persistent HTTP: example  
User enters URL:  
1a. HTTP client initiates TCP  
connection to HTTP server  
(process) at www.someSchool.edu on  
port 80  

### 2. HTTP client sends HTTP

request message (containing  
URL) into TCP connection  
socket. Message indicates  
that client wants object  
someDepartment/home.index  
1b. HTTP server at host  
www.someSchool.edu waiting for TCP  
connection at port 80 “accepts”  
connection, notifying client  

### 3. HTTP server receives request message,

forms response message containing  
requested object, and sends message  
into its socket  
time  
(containing text, references to 10 jpeg images) www.someSchool.edu/someDepartment/home.index Transport Layer: 3-#  
Non-persistent HTTP: example (cont.)  
User enters URL:  
(containing text, references to 10 jpeg images) www.someSchool.edu/someDepartment/home.index  

### 5. HTTP client receives response

message containing html file,  
displays html. Parsing html file,  
finds 10 referenced jpeg objects  

### 6. Steps 1-5 repeated for

each of 10 jpeg objects  

### 4. HTTP server closes TCP

connection.  
time  
Transport Layer: 3-#  
Non-persistent HTTP: response time  
RTT (definition): time for a small  
packet to travel from client to  
server and back  
HTTP response time (per object):  
one RTT to initiate TCP connection  
one RTT for HTTP request and first few bytes of HTTP response to return  
object/file transmission time  
time to  
transmit  
file  
initiate TCP  
connection  
RTT  
request file  
RTT  
file received  
time  
time  
Non-persistent HTTP response time = 2RTT+ file transmission time  
Transport Layer: 3-#  
Persistent HTTP (HTTP 1.1)  
Non-persistent HTTP issues:  
requires 2 RTTs per object  
OS overhead for each TCP  
connection  
browsers often open multiple  
parallel TCP connections to  
fetch referenced objects in  
parallel  
Persistent HTTP (HTTP1.1):  
server leaves connection open after  
sending response  
subsequent HTTP messages  
between same client/server sent  
over open connection  
client sends requests as soon as it  
encounters a referenced object  
as little as one RTT for all the  
referenced objects (cutting  
response time in half)  
Transport Layer: 3-#  
HTTP request message  
two types of HTTP messages: request, response  
HTTP request message:  
ASCII (human-readable format)  
header  
lines  
GET /index.html HTTP/1.1\r\n  
Host: www-net.cs.umass.edu\r\n  
User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10.15; rv:80.0) Gecko/20100101 Firefox/80.0 \r\n Accept: text/html,application/xhtml+xml\r\n Accept-Language: en-us,en;q=0.5\r\n  
Accept-Encoding: gzip,deflate\r\n  
Connection: keep-alive\r\n  
\r\n  
carriage return character  
line-feed character  
1⃣ HTTP Connections: Two Types  
Non-Persistent HTTP  
One object per TCP connection  
TCP connection opened → object sent → connection closed Multiple objects → multiple TCP connections Response time per object:  
1 RTT → to establish TCP connection  
1 RTT → for HTTP request & first few bytes of response Example:  
HTML page references 10 images → 11 TCP connections (1 for HTML + 10 for images) Slow because 2 RTTs per object + OS overhead Persistent HTTP (HTTP/1.1)  
TCP connection remains open after sending response Multiple objects can be sent over the same connection Client sends requests as soon as it finds a referenced object Response time for all objects can be reduced to ≈ 1 RTT + total file transmission time  
Benefits:  
Fewer TCP connections → less overhead  
Faster page loading  
Efficient use of server and network resources 2⃣ HTTP Request Message (Client → Server) Format: ASCII text (human-readable)  
Request line: method, URL, version  
Header lines: provide info about client, accepted content, connection preferences Blank line → separates headers from message body Request types:  
GET → request object  
POST → send data to server (e.g., form submission) 3⃣ Round-Trip Time (RTT)  
Definition: Time it takes for a small packet to travel from client → server → back to client  
Non-persistent HTTP → 2 RTTs per object Persistent HTTP → 1 RTT can suffice for multiple objects Summary Table: Non-Persistent vs Persistent HTTP Feature  
Non-Persistent  
Persistent (HTTP/1.1)  
TCP connections per object  
1 (shared for all objects)  
RTT per object  
1 (approx)  
Overhead  
High  
Low  
Page load speed  
Slower  
Faster  
OS TCP overhead  
Repeated  
Once  
HTTP with RTT timelines, so you can see the difference at a glance.  
Non-persistent HTTP time = 2 × RTT + file transmission time pgsql  
GET /index.html HTTP/1.1  
makefile  
Host: www-net.cs.umass.edu  
User-Agent: Mozilla/5.0 ...  
Accept: text/html  
Connection: keep-alive  
Key point: Reducing RTT or number of TCP connections reduces page load time  
HTTP request message  
two types of HTTP messages: request, response  
HTTP request message:  
ASCII (human-readable format)  
header  
lines  
GET /index.html HTTP/1.1\r\n  
Host: www-net.cs.umass.edu\r\n  
User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10.15; rv:80.0) Gecko/20100101 Firefox/80.0 \r\n Accept: text/html,application/xhtml+xml\r\n Accept-Language: en-us,en;q=0.5\r\n  
Accept-Encoding: gzip,deflate\r\n  
Connection: keep-alive\r\n  
\r\n  
carriage return character  
line-feed character  
request line (GET, POST,  
HEAD commands)  
carriage return, line feed  
at start of line indicates  
end of header lines  
- Check out the online interactive exercises for more
examples:  
http://gaia.cs.umass.edu/kurose_ross/interactive/ Transport Layer: 3-#  
HTTP request message: general format  
request  
line  
header  
lines  
body  
method  
sp  
sp  
cr  
lf  
version  
URL  
cr  
lf  
value  
header field name  
cr  
lf  
value  
header field name  
cr  
lf  
entity body  
Transport Layer: 3-#  
Other HTTP request messages  
POST method:  
web page often includes form  
input  
user input sent from client to  
server in entity body of HTTP  
POST request message  
GET method (for sending data to server):  
include user data in URL field of HTTP  
GET request message (following a ‘?’):  
www.somesite.com/animalsearch?monkeys&banana  
HEAD method:  
requests headers (only) that  
would be returned if specified  
URL were requested with an  
HTTP GET method.  
PUT method:  
uploads new file (object) to server  
completely replaces file that exists  
at specified URL with content in  
entity body of POST HTTP request  
message  
Transport Layer: 3-#  
HTTP response message  
status line (protocol  
status code status phrase)  
header  
lines  
data, e.g., requested  
HTML file  
HTTP/1.1 200 OK  
Date: Tue, 08 Sep 2020 00:53:20 GMT  
Server: Apache/2.4.6 (CentOS)  
OpenSSL/1.0.2k-fips PHP/7.4.9  
mod_perl/2.0.11 Perl/v5.16.3  
Last-Modified: Tue, 01 Mar 2016 18:57:50 GMT ETag: "a5b-52d015789ee9e"  
Accept-Ranges: bytes  
Content-Length: 2651  
Content-Type: text/html; charset=UTF-8 \r\n  
data data data data data ...  
- Check out the online interactive exercises for more
examples:  
http://gaia.cs.umass.edu/kurose_ross/interactive/ Transport Layer: 3-#  
HTTP response status codes  
200 OK  
request succeeded, requested object later in this message  
301 Moved Permanently  
requested object moved, new location specified later in this message (in  
Location: field)  
400 Bad Request  
request msg not understood by server  
404 Not Found  
requested document not found on this server  
505 HTTP Version Not Supported  
status code appears in 1st line in server-to-client response message.  
some sample codes:  
Transport Layer: 3-#  
Trying out HTTP (client side) for yourself  

### 1. netcat to your favorite Web server:

opens TCP connection to port 80 (default HTTP server port) at gaia.cs.umass. edu.  
anything typed in will be sent to port 80 at gaia.cs.umass.edu  
% nc -c -v gaia.cs.umass.edu 80  

### 3. look at response message sent by HTTP server!

(or use Wireshark to look at captured HTTP request/response)  

### 2. type in a GET HTTP request:

GET /kurose_ross/interactive/index.php HTTP/1.1 Host: gaia.cs.umass.edu  
by typing this in (hit carriage return twice), you send this minimal (but complete) GET request to HTTP server  
Transport Layer: 3-#  
1⃣ HTTP Messages  
HTTP has two types of messages:  

### 1. Request messages → sent client → server

### 2. Response messages → sent server → client

A. HTTP Request Message  
Structure:  
Example: GET Request:  
Request line: METHOD URL HTTP-VERSION  
e.g., GET /index.html HTTP/1.1  
Headers: provide info about client, accepted content, connection type Blank line ( \r\n ): indicates end of headers Body (optional): contains data (e.g., form submission in POST) B. HTTP Methods  
Method  
Purpose  
GET  
Retrieve object (data in URL)  
POST  
Send data to server (data in request body)  
HEAD  
Retrieve only headers, no body  
PUT  
Upload/replace file at specified URL  
GET example with parameters:  
C. HTTP Response Message  
Structure:  
Example:  
Status line: HTTP-version status-code status-phrase Headers: info about server, object length, content type Body: requested object (HTML, image, etc.) D. Common HTTP Status Codes  
Code  
Meaning  
OK → request succeeded  
Moved Permanently → object moved to new URL Bad Request → server cannot understand request Not Found → requested object not found  
HTTP Version Not Supported  
E. Trying HTTP Requests Yourself  
Option 1: Using netcat ( nc ):  
Opens TCP connection to HTTP server on port 80 Type a GET request, e.g.:  
Hit Enter twice → sends request  
Server responds with HTTP response message You can also capture traffic with Wireshark Key Points to Remember  
Request = client → server, Response = server → client  
HTTP is stateless (server does not remember previous requests)  
GET → fetch data, POST → send data, HEAD → only headers, PUT → upload/replace Status codes tell you if request succeeded, failed, or redirected with request/response flow, including status codes and body/header separation — makes it much easier to remember.  
css  
Request Line  
Header Lines  
[Optional Body]  
vbnet  
GET /index.html HTTP/1.1\r\n  
Host: www-net.cs.umass.edu\r\n  
User-Agent: Mozilla/5.0 (Macintosh; ...) \r\n Accept: text/html\r\n  
Connection: keep-alive\r\n  
\r\n  
bash  
www.somesite.com/animalsearch?monkeys&banana css  
Status Line  
Header Lines  
[Optional Data/Body]  
yaml  
HTTP/1.1 200 OK  
Date: Tue, 08 Sep 2020 00:53:20 GMT  
Server: Apache/2.4.6  
Content-Length: 2651  
Content-Type: text/html; charset=UTF-8 \r\n  
<data of requested HTML file>  
Status code appears in the first line of server-to-client response.  
% nc -c -v gaia.cs.umass.edu 80  
swift  
GET /kurose_ross/interactive/index.php HTTP/1.1 Host: gaia.cs.umass.edu  

## Lecture Notes: Cookies and Web Caching

Maintaining user/server state: cookies Recall: HTTP GET/response  
interaction is stateless  
no notion of multi-step exchanges of  
HTTP messages to complete a Web  
“transaction”  
no need for client/server to track  
“state” of multi-step exchange  
all HTTP requests are independent of  
each other  
no need for client/server to “recover” from a  
partially-completed-but-never-complete ly-completed transaction  
a stateful protocol: client makes  
two changes to X, or none at all  
time  
time  
OK  
OK  
unlock X  
OK  
update X X’  
update X  
X’’  
lock data record X  
OK  
X’  
X’’  
X’’  
t’  
Q: what happens if network connection or client crashes at t’ ?  
Transport Layer: 3-#  
Maintaining user/server state: cookies Web sites and client browser use  
cookies to maintain some state  
between transactions  
four components:  

### 1) cookie header line of HTTP response

message  

### 2) cookie header line in next HTTP

request message  

### 3) cookie file kept on user’s host,

managed by user’s browser  

### 4) back-end database at Web site

Example:  
Susan uses browser on laptop,  
visits specific e-commerce site  
for first time  
when initial HTTP requests  
arrives at site, site creates:  
unique ID (aka “cookie”)  
entry in backend database  
for ID  
subsequent HTTP requests  
from Susan to this site will  
contain cookie ID value,  
allowing site to “identify”  
Susan  
Transport Layer: 3-#  
Maintaining user/server state: cookies client  
server  
usual HTTP response msg  
usual HTTP response msg  
cookie file  
one week later:  
usual HTTP request msg  
cookie: 1678  
cookie-  
specific  
action  
access  
ebay 8734  
usual HTTP request msg  
Amazon server  
creates ID  
1678 for user  
create  
entry  
usual HTTP response  
set-cookie: 1678  
ebay 8734  
amazon 1678  
usual HTTP request msg  
cookie: 1678  
cookie-  
specific  
action  
access  
ebay 8734  
amazon 1678  
backend  
database  
time  
time  
Transport Layer: 3-#  
HTTP cookies: comments  
What cookies can be used for:  
authorization  
shopping carts  
recommendations  
user session state (Web e-mail)  
cookies and privacy:  
cookies permit sites to  
learn a lot about you on  
their site.  
third party persistent  
cookies (tracking cookies)  
allow common identity  
(cookie value) to be  
tracked across multiple  
web sites  
aside  
Challenge: How to keep state?  
at protocol endpoints: maintain state at sender/receiver over multiple  
transactions  
in messages: cookies inHTTP messages  
carry state  
Transport Layer: 3-#  
Web caches  
user configures browser to  
point to a (local) Web cache  
browser sends all HTTP  
requests to cache  
if object in cache: cache  
returns object to client  
else cache requests object  
from origin server, caches  
received object, then  
returns object to client  
Goal: satisfy client requests without involving origin server client  
Web  
cache  
client  
HTTP request  
HTTP response  
HTTP request  
HTTP request  
origin  
server  
HTTP response  
HTTP response  
Transport Layer: 3-#  
Web caches (aka proxy servers)  
Web cache acts as both  
client and server  
server for original  
requesting client  
client to origin server  
Why Web caching?  
reduce response time for client  
request  
cache is closer to client  
reduce traffic on an institution’s  
access link  
Internet is dense with caches  
enables “poor” content providers  
to more effectively deliver content  
1⃣ Maintaining State with Cookies  
Why needed?  
HTTP is stateless: each request is independent.  
No memory of multi-step transactions or previous user actions.  
Example problem: updating a shopping cart — if user disconnects or crashes, site can’t know what was in progress.  
How cookies help  
Cookies let servers maintain state across multiple HTTP transactions.  
Components:  

### 1. Set-Cookie header in HTTP response (server → client)

Assigns a unique ID to client.  

### 2. Cookie header in HTTP request (client → server)

Sends cookie ID back to server with each request.  

### 3. Cookie file stored on client machine, managed by browser.

### 4. Backend database on server stores data associated with cookie ID.

Example flow:  
Step  
Action  
User visits site → server creates cookie ID and stores entry in DB Server sends HTTP response with Set-Cookie: 1678 Next request from user includes Cookie: 1678 → server identifies user  
Uses of cookies  
Authorization & login sessions  
Shopping carts  
Personal recommendations  
Webmail session state  
Privacy concerns  
Cookies can track user activity on a site.  
Third-party persistent cookies can track identity across multiple sites.  
2⃣ Web Caches (Proxy Servers)  
Purpose  
Reduce response time for client requests.  
Reduce network traffic to origin servers.  
Serve content closer to user.  
How it works  

### 1. Browser sends HTTP request to cache.

### 2. If object is in cache → cache returns object directly.

3. If object is not in cache → cache fetches object from origin server, stores it, then returns it to client.  
Roles of cache:  
Acts as server to clients.  
Acts as client to origin servers.  
Benefits  
Faster content delivery (cache is closer to client).  
Reduces load on origin servers and access links.  
Helps smaller content providers distribute content efficiently.  
Key Points  
Cookies = carry state between stateless HTTP requests.  
Web caches = store content to improve speed and reduce network load.  
Together, they make the Web efficient and user-friendly.  
this makes it super easy to remember visually.  
server tells cache about  
object’s allowable caching in  
response header:  
Transport Layer: 3-#  
Caching example  
origin  
servers  
public  
Internet  
institutional  
network  
1 Gbps LAN  
1.54 Mbps  
access link  
Performance:  
access link utilization = .97  
LAN utilization: .0015  
end-end delay = Internet delay +  
access link delay + LAN delay  
= 2 sec + minutes + usecs  
Scenario:  
access link rate: 1.54 Mbps  
RTT from institutional router to server: 2 sec web object size: 100K bits  
average request rate from browsers to origin servers: 15/sec  
avg data rate to browsers: 1.50 Mbps  
problem: large  
queueing delays at  
high utilization!  
Transport Layer: 3-#  
Performance:  
access link utilization = .97  
LAN utilization: .0015  
end-end delay = Internet delay +  
access link delay + LAN delay  
= 2 sec + minutes + usecs  
Option 1: buy a faster access link  
origin  
servers  
public  
Internet  
institutional  
network  
1 Gbps LAN  
1.54 Mbps  
access link  
Scenario:  
access link rate: 1.54 Mbps  
RTT from institutional router to server: 2 sec web object size: 100K bits  
average request rate from browsers to origin servers: 15/sec  
avg data rate to browsers: 1.50 Mbps  
154 Mbps  
154 Mbps  
.0097  
msecs  
Cost: faster access link (expensive!)  
Transport Layer: 3-#  
Performance:  
LAN utilization: .?  
access link utilization = ?  
average end-end delay = ?  
Option 2: install a web cache  
origin  
servers  
public  
Internet  
institutional  
network  
1 Gbps LAN  
1.54 Mbps  
access link  
Scenario:  
access link rate: 1.54 Mbps  
RTT from institutional router to server: 2 sec web object size: 100K bits  
average request rate from browsers to origin servers: 15/sec  
avg data rate to browsers: 1.50 Mbps  
How to compute link  
utilization, delay?  
Cost: web cache (cheap!)  
local web cache  
Transport Layer: 3-#  
Calculating access link utilization, end-end delay with cache:  
origin  
servers  
public  
Internet  
institutional  
network  
1 Gbps LAN  
1.54 Mbps  
access link  
local web cache  
suppose cache hit rate is 0.4:  
40% requests served by cache, with low (msec) delay  
60% requests satisfied at origin  
rate to browsers over access link  
= 0.6 * 1.50 Mbps = .9 Mbps  
access link utilization = 0.9/1.54 = .58 means low (msec) queueing delay at access link average end-end delay:  
= 0.6 * (delay from origin servers)  
- 0.4 * (delay when satisfied at cache)
= 0.6 (2.01) + 0.4 (~msecs) = ~ 1.2 secs lower average end-end delay than with 154 Mbps link (and cheaper too!)  
Transport Layer: 3-#  
Conditional GET  
Goal: don’t send object if cache has  
up-to-date cached version  
no object transmission delay (or use  
of network resources)  
client: specify date of cached copy  
in HTTP request  
If-modified-since: <date>  
server: response contains no  
object if cached copy is up-to-date:  
HTTP/1.0 304 Not Modified  
HTTP request msg  
If-modified-since: <date>  
HTTP response  
HTTP/1.0  
304 Not Modified  
object  
not  
modified  
before  
<date>  
HTTP request msg  
If-modified-since: <date>  
HTTP response  
HTTP/1.0 200 OK  
<data>  
object  
modified  
after  
<date>  
client  
server  
Transport Layer: 3-#  
1⃣ Web Cache Impact on Performance  
Scenario  
Institutional network: 1.54 Mbps access link, 1 Gbps LAN.  
Web object: 100 Kbits.  
Average request rate: 15/sec → avg data rate to browsers: 1.50 Mbps.  
Round-trip time (RTT) to origin server: 2 sec.  
Problem:  
Access link utilization = 0.97 → very high → large queueing delays.  
LAN utilization = 0.0015 → negligible.  
End-to-end delay = Internet delay + access link delay + LAN delay ≈ minutes for requests.  
Option 1: Buy a Faster Link  
Costly solution.  
Reduces access link utilization, but expensive.  
Option 2: Install a Local Web Cache  
Cache stores frequently requested objects.  
Suppose cache hit rate = 0.4:  
40% requests served locally → very small delay (milliseconds).  
60% requests go to origin server → original RTT applies.  
Calculations:  
Access link utilization:  
→ much lower than 0.97 → smaller queueing delays.  
Average end-to-end delay:  
Conclusion:  
Cache → lower average delay, cheaper than upgrading link.  
2⃣ Conditional GET  
Goal:  
Avoid sending full object if cached copy is up-to-date → saves bandwidth and reduces delay.  
How it works  
1. Client request: includes If-Modified-Since: <date> header → date of cached copy.  

### 2. Server response:

If object not modified:  
HTTP/1.0 304 Not Modified → no data sent, cache used.  
If object modified:  
HTTP/1.0 200 OK → full object sent.  
Benefits  
Reduces unnecessary traffic.  
Saves time and network resources.  
Works together with local web caches.  
Key Points  
Web caches improve speed and reduce access link utilization.  
Conditional GETs ensure only updated content is sent.  
Combining caches + conditional GETs → efficient content delivery and lower delays.  
Utilization =  
1.54  
0.6 × 1.50  
0.58  
Avg delay = 0.6 × 2.01 + 0.4 × few ms ≈1.2 sec  

## Caching Problem and All Formulas

Problem Recap: Web Cache Performance  
Scenario:  
Access link rate (R_access): 1.54 Mbps  
LAN rate (R_LAN): 1 Gbps  
Web object size (F): 100 Kbits  
Request rate (λ): 15 requests/sec  
Average traffic rate to browsers: 1.50 Mbps  
RTT to origin servers: 2 sec  
Without Cache  
Traffic to access link = 1.50 Mbps  
Access link utilization:  
→ Almost saturated → large queueing delay.  
End-to-end delay:  
With Cache (Hit rate = 0.4)  
40% requests served by cache → very low delay (ms).  
60% requests st  
Traffic to access link:  
Access link utilization:  
Average End-to-End Delay:  
If file transmission ≈ 0.01 sec and cache delay ≈ ms:  
With cache → lower utilization + faster response time.  
All Key Formulas  

### 1. Encapsulation & Networking Basics

Encapsulation adds headers (H) at each layer:  

### 2. Latency (Delay)

### 3. RTT (Round Trip Time)

### 4. HTTP Response Time

For non-persistent HTTP:  

### 5. Access Link Utilization

### 6. Traffic with Cache

### 7. Average End-to-End Delay with Cache

where  
Final Notes  
Caching reduces utilization → fewer bottlenecks.  
Conditional GET ensures only updated objects are fetched → avoids wasting bandwidth.  
Formulas above cover encapsulation, latency, RTT, HTTP timing, link utilization, and caching performance.  
sheet), so you can use it directly in your study notes?  
U =  
access  
traffic to browsers  
1.54  
1.50  
0.97  
D = Internet delay (2 sec) + queueing delay (minutes) + LAN delay (μs) browsers,access  
(1 −hit rate) × R  
browsers  
= 0.6 × 1.50 Mbps = 0.9 Mbps  
U =  
1.54  
0.9  
0.58  
D = 0.6 × (RTT + file transmission) + 0.4 × (cache delay) D ≈0.6 × 2.01 + 0.4 × (0.01) ≈1.2 sec  
Message →Segment →Datagram →Frame →Bits Latency = Propagation Delay + Transmission Delay + Queueing Delay + Processing Delay  
RTT = time from client → server → back to client response  
2 × RTT + File transmission time  
U =  
Link capacity  
Traffic sent over link  
access  
(1 −hit rate) × R  
browsers  
D = (1 −h) × (RTT + T  
file  
h × T  
cache  
h = hit rate
