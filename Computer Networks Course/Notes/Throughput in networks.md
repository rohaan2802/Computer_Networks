# Throughput, DNS and the Application Layer

## Throughput in Computer Networks

Throughput in computer networks is a performance metric that measures how much useful data is successfully transferred from sender to receiver over a network in a given amount of time.  
Definition:  
It reflects the real performance of a network, not just its theoretical maximum speed.  
Formula:  
For example, if 10 MB of data is transferred in 20 seconds:  
Throughput vs Bandwidth:  
Bandwidth → Maximum possible data transfer capacity of a link (theoretical).  
Throughput → Actual data transfer achieved in practice (depends on conditions).  
Example:  
A Wi-Fi link might have bandwidth = 100 Mbps, But due to interference, congestion, and protocol overhead, throughput = 60 Mbps.  
Factors Affecting Throughput:  

### 1. Network Congestion – too many users reduce throughput.

2. Propagation & Transmission Delays – distance and link speed matter.  

### 3. Packet Loss & Retransmissions – reduce efficiency.

4. Protocol Overhead – headers, acknowledgments, etc. consume bandwidth.  
5. Hardware Limitations – routers, switches, or end systems may limit speed.  
6. Cross-Traffic Variability – other traffic sharing the same link affects throughput.  
Example in Real Life:  
A 4G mobile network claims bandwidth = 100 Mbps, but when you download a file, you may see only 20–30 Mbps throughput because of congestion and overhead.  
In short:  
Throughput = Actual data transfer speed you experience.  
Bandwidth = The maximum possible capacity of the channel.  
examples and practice problems), like the one I made for your earlier networking topics?  
Throughput is the actual rate at which data is delivered over a network, usually measured in bits per second (bps), Kbps, Mbps, or Gbps.  
Throughput =  
Total Time Taken  
Total Data Successfully Delivered  
Throughput =  
10 × 8 (Mb)  
4 Mbps  
Overhead means  
In computer networks, overhead means the extra data or processing added to support communication, but which is not part of the actual user data (payload).  
Definition:  
Overhead is the additional information (like headers, control bits, acknowledgments, etc.) required for proper delivery of data across a network.  
It ensures reliability, error-checking, routing, and synchronization, but it reduces the effective throughput because not all transmitted bits are user data.  
Example:  
Suppose you want to send a 1000-byte message over TCP/IP:  
TCP adds a 20-byte header  
IP adds a 20-byte header  
Ethernet adds a 26-byte header & trailer So, total sent = 1000 + 20 + 20 + 26 = 1066 bytes.  
Here, 66 bytes = overhead, only 1000 bytes are useful data.  
Why overhead matters:  
High overhead → less efficient network (more bandwidth wasted on control info).  
Low overhead → more bandwidth is used for actual user data.  
Types of Overhead:  
1. Protocol overhead – headers, trailers (e.g., TCP, IP, Ethernet headers).  
2. Processing overhead – extra CPU cycles for encryption, routing, error correction.  
3. Timing overhead – delays due to acknowledgments, handshakes (e.g., TCP 3-way handshake).  
4. Control overhead – routing updates, ARP messages, ICMP packets, etc.  
In short:  
Overhead = the extra cost of communication that supports data transfer but isn’t the actual user data.  
UDP, IP, Ethernet, Wi-Fi) so you can quickly see how much extra data each adds?  

## Keys of Encrypted Data

Let me clarify:  
Encryption Context  
When we encrypt data, there’s extra information added for security.  
This is also called overhead, because it is not part of the original message.  
Examples:  
Encryption key (used by both sender and receiver, but not the actual message).  
Initialization vector (IV) – random value added for randomness.  
Padding – extra bytes added to make the data fit block size.  
Authentication tag / MAC – ensures integrity.  
So if your message is 1000 bytes, the encrypted version might become 1040 bytes →  
40 bytes = encryption overhead.  
Comparison with Network Overhead  
Network overhead = headers, control bits, retransmissions (for communication).  
Encryption/security overhead = keys, IVs, padding, tags (for confidentiality & integrity).  
Both are necessary “extra” data that doesn’t belong to the main message but is essential for correct and secure transmission.  
So yes — the key, IV, padding, etc. in encrypted communication are considered overhead, just like TCP/IP headers are overhead in networking.  
goes through:  
Application → Encryption overhead → Transport overhead (TCP/UDP) → Network overhead (IP) → Link overhead (Ethernet/Wi-Fi) ?  

## Cookies in Simple Words

Let me explain cookies in super simple words:  
Easy Definition:  
Cookies are small pieces of data that websites store on your computer or phone to remember things about you.  
Example:  
You log in to Facebook → it puts a cookie in your browser so you don’t have to log in again every time.  
You add items to an online shopping cart → cookies remember your cart even if you close the page and come back.  
What Cookies Can Store:  
Your login session (so websites know it’s you).  
Your preferences (dark mode, language, etc.).  
Your activity (pages you visited, items you viewed).  
Good vs. Bad:  
Good use: Saves time, remembers your settings, keeps you logged in.  
Bad use: Some sites use cookies to track your browsing across different websites for ads (called third-party cookies).  
In short:  
Cookies = tiny memory notes that websites leave in your browser to remember who you are and what you did.  
persistent cookies, third-party cookies) with simple examples?  

## Lecture Notes: Application Layer, FTP and Email

Application Layer: Overview  
Principles of network  
applications  
Web and HTTP  
FTP, E-mail, SMTP, IMAP  
The Domain Name System  
DNS  
socket programming with  
UDP and TCP  
Application Layer: 2-#  
Application Layer  
2-#  
FTP: the file transfer protocol  
file transfer  
FTP  
server  
FTP  
user  
interface  
FTP  
client  
local file  
system  
remote file  
system  
user  
at host  
transfer file to/from remote host  
client/server model  
client: side that initiates transfer (either to/from remote) server: remote host  
ftp: RFC 959  
ftp server: port 21  
Application Layer  
2-#  
FTP: separate control, data connections  
FTP client contacts FTP server at  
port 21, using TCP  
client authorized over control  
connection  
client browses remote directory,  
sends commands over control  
connection (username and  
password, commands to  
change remote directory, and  
commands to “put” and “get”  
files)  
when server receives file transfer  
command, server opens 2nd TCP data  
connection (for file) to client  
after transferring one file, server  
closes data connection  
FTP  
client  
FTP  
server  
TCP control connection,  
server port 21  
TCP data connection,  
server port 20  
server opens another TCP data  
connection to transfer another file  
control connection: “out of band”  
FTP server maintains “state”: current  
directory, earlier authentication  
HTTP “in-band” sends request  
and response header lines into the same TCP connection that carries the transferred file itself  
Application Layer  
2-#  
FTP commands, responses  
sample commands:  
sent as ASCII text over control  
channel  
USER username  
PASS password  
LIST return list of file in  
current directory  
RETR filename retrieves  
(gets) file  
STOR filename stores (puts)  
file onto remote host  
sample return codes  
status code and phrase (as in  
HTTP)  
331 Username OK,  
password required  
125 data connection  
already open; transfer  
starting  
425 Can’t open data  
connection  
452 Error writing file  
Application Layer  
2-#  
Electronic mail  
Three major components:  
user agents  
mail servers  
simple mail transfer protocol:  
SMTP  
User Agent  
a.k.a. “mail reader”  
composing, editing, reading mail  
messages  
e.g., Outlook, Thunderbird,  
iPhone mail client  
outgoing, incoming messages  
stored on server  
user mailbox  
outgoing  
message queue  
mail  
server  
mail  
server  
mail  
server  
SMTP  
SMTP  
SMTP  
user  
agent  
user  
agent  
user  
agent  
user  
agent  
user  
agent  
user  
agent  
Application Layer  
2-#  
Electronic mail: mail servers  
mail servers:  
mailbox contains incoming  
messages for user  
message queue of outgoing  
(to be sent) mail messages  
SMTP protocol between  
mail servers to send email  
messages  
client: sending mail  
server  
“server”: receiving mail  
server  
mail  
server  
mail  
server  
mail  
server  
SMTP  
SMTP  
SMTP  
user  
agent  
user  
agent  
user  
agent  
user  
agent  
user  
agent  
Electronic Mail: SMTP [RFC 2821]  
uses TCP to reliably transfer email message from client to server, port 25  
direct transfer: sending server to receiving server three phases of transfer  
handshaking (greeting)  
transfer of messages  
closure  
command/response interaction (like HTTP, FTP) commands: ASCII text  
response: status code and phrase  
messages must be in 7-bit ASCI  
Application Layer  
2-#  
user  
agent  
Scenario: Alice sends message to Bob  

### 1) Alice uses UA to compose

message “to”  
bob@someschool.edu  

### 2) Alice’s UA sends message to

her mail server; message placed  
in message queue  

### 3) client side of SMTP opens TCP

connection with Bob’s mail  
server  

### 4) SMTP client sends Alice’s

message over the TCP  
connection  

### 5) Bob’s mail server places the

message in Bob’s mailbox  

### 6) Bob invokes his user agent to

read message  
mail  
server  
mail  
server  
Alice’s mail server  
Bob’s mail server  
user  
agent  
Scenario: Alice sends message to Bob  
Application Layer  
2-#  
Sample SMTP interaction  
S: 220 hamburger.edu  
C: HELO crepes.fr  
S: 250 Hello crepes.fr, pleased to meet you C: MAIL FROM: <alice@crepes.fr>  
S: 250 alice@crepes.fr... Sender ok  
C: RCPT TO: <bob@hamburger.edu>  
S: 250 bob@hamburger.edu ... Recipient ok C: DATA  
S: 354 Enter mail, end with "." on a line by itself C:  
C: How about pickles?  
C: .  
S: 250 Message accepted for delivery  
C: QUIT  
S: 221 hamburger.edu closing connection http://www.tcpipguide.com/free/t_SMTPMailTransactionPr ocess-3.htm  
Application Layer  
2-#  
Try SMTP interaction for yourself:  
telnet servername 25  
see 220 reply from server  
enter HELO, MAIL FROM, RCPT TO, DATA, QUIT commands  
above lets you send email without using email client (reader)  
Let me give you a clean, simplified overview so you can quickly revise the main points.  
Application Layer Overview  
The Application Layer is the top layer in computer networks. It provides services and protocols that enable end-user applications (web, email, file transfer, etc.) to communicate over the network.  
Principles of Network Applications  
Client-Server Model: Client requests, server responds (e.g., Web, FTP, SMTP).  
Processes communicate via sockets.  
Protocols define:  
Message types (request/response)  
Message format  
Rules for exchange  
Web and HTTP  
HTTP (Hypertext Transfer Protocol): Basis of the web.  
Uses TCP port 80 (or 443 for HTTPS).  
Stateless: Each request/response independent.  
HTTP/1.1 → persistent connections.  
HTTP/2, HTTP/3 → more efficient, multiplexing.  
FTP (File Transfer Protocol) — RFC 959 Ports: Control (21), Data (20).  
Client-Server model:  
Client initiates connection to server.  
Separate control and data connections.  
Control = “out-of-band” (commands like USER, PASS, LIST).  
Data = actual file transfer.  
Commands (sent as ASCII text):  
USER username  
PASS password  
LIST (list directory)  
RETR filename (download)  
STOR filename (upload)  
Electronic Mail (E-mail)  
Components:  

### 1. User Agents (UA) – mail clients (Outlook, Thunderbird, Gmail).

### 2. Mail Servers – store incoming & outgoing mail.

### 3. Protocols:

SMTP: Sending mail (server-to-server).  
POP3/IMAP: Retrieving mail.  
SMTP (Simple Mail Transfer Protocol) — RFC 2821 Uses TCP port 25 (reliable transfer).  
Direct transfer: Sending server → Receiving server.  
Phases:  

### 1. Handshake (HELO)

### 2. Message transfer (MAIL FROM, RCPT TO, DATA)

### 3. Closure (QUIT)

Commands: ASCII text.  
Responses: status codes (e.g., 220 , 250 , 354 ).  
Example: Alice → Bob  

### 1. Alice writes mail in UA.

### 2. Sent to Alice’s mail server (queued).

### 3. SMTP opens TCP connection to Bob’s mail server.

### 4. Message delivered to Bob’s mailbox.

### 5. Bob retrieves it using his UA.

DNS (Domain Name System)  
Distributed database that maps domain names → IP addresses.  
Hierarchy: Root → TLD (.com, .org, .edu) → Authoritative servers.  
UDP port 53 (mostly), sometimes TCP.  
Types of records:  
A: hostname → IPv4  
AAAA: hostname → IPv6  
MX: mail server  
CNAME: alias  
Socket Programming  
Sockets = interface between application and transport layer.  
UDP sockets: Unreliable, faster, no connection.  
TCP sockets: Reliable, connection-oriented, stream-based.  
In short:  
HTTP → web pages  
FTP → file transfers  
SMTP/IMAP/POP3 → email  
DNS → name resolution  
Sockets → programming interface  
can print as a PDF for quick revision?  
SMTP: final words  
SMTP uses persistent  
connections  
SMTP requires message (header  
& body) to be in 7-bit ASCII  
comparison with HTTP:  
HTTP: pull  
SMTP: push  
both have ASCII  
command/response interaction,  
status codes  
HTTP: each object encapsulated  
in its own response msg  
SMTP: multiple objects sent in  
multipart msg  
Application Layer  
2-#  
Mail message format  
SMTP: protocol for exchanging  
email msgs  
RFC 822: standard for text  
message format:  
header lines, e.g.,  
To:  
From:  
Subject:  
Body: the “message”  
ASCII characters only  
header  
body  
blank  
line  
Application Layer  
2-#  
Mail access protocols  
SMTP: delivery/storage to receiver’s server mail access protocol: retrieval from server  
POP: Post Office Protocol [RFC 1939]: authorization, download  
IMAP: Internet Mail Access Protocol [RFC 1730]: more features, including manipulation of stored msgs on server  
HTTP: gmail, Hotmail, Yahoo! Mail, etc.  
sender’s mail  
server  
SMTP  
SMTP  
mail access  
protocol  
receiver’s mail  
server  
(e.g., POP,  
IMAP)  
user  
agent  
user  
agent  
Application Layer  
2-#  
POP3 protocol  
authorization phase  
client commands:  
user: declare username  
pass: password  
server responses  
- OK
- ERR
transaction phase, client:  
list: list message numbers  
retr: retrieve message by  
number  
dele: delete  
quit  
C: list  
S: 1 498  
S: 2 912  
S: .  
C: retr 1  
S: <message 1 contents>  
S: .  
C: dele 1  
C: retr 2  
S: <message 1 contents>  
S: .  
C: dele 2  
C: quit  
S: +OK POP3 server signing  
off  
S: +OK POP3 server ready  
C: user bob  
S: +OK  
C: pass hungry  
S: +OK user successfully logged on  
Application Layer  
2-#  
POP3 (more) and IMAP  
more about POP3  
previous example uses  
POP3 “download and  
delete” mode  
Bob cannot re-read  
e-mail if he changes  
client  
POP3  
“download-and-keep”:  
copies of messages on  
different clients  
POP3 is stateless across  
sessions  
IMAP  
keeps all messages in one  
place: at server  
allows user to organize  
messages in folders  
keeps user state across  
sessions:  
names of folders and  
mappings between  
message IDs and folder  
name  
Application Layer: Overview  
Principles of network  
applications  
Web and HTTP  
E-mail, SMTP, IMAP  
The Domain Name System  
DNS  
P2P applications  
video streaming and  
content distribution  
networks  
socket programming with  
UDP and TCP  
Application Layer: 2-#  
DNS: Domain Name System  
people: many identifiers:  
SSN, name, passport #  
Internet hosts, routers:  
IP address (32 bit) - used for  
addressing datagrams  
“name”, e.g., cs.umass.edu -  
used by humans  
Q: how to map between IP  
address and name, and vice  
versa ?  
Domain Name System (DNS):  
distributed database implemented in  
hierarchy of many name servers  
application-layer protocol: hosts, DNS servers communicate to resolve  
names (address/name translation)  
note: core Internet function,  
implemented as application-layer  
protocol  
complexity at network’s “edge”  
you’ve now got the rest of the Application Layer notes (SMTP final details, Mail formats, POP3, IMAP, DNS). Let me give you a clear, summarized version so it’s easy to revise before exams.  
SMTP and E-Mail Protocols  
SMTP (Simple Mail Transfer Protocol)  
Purpose: Sending mail between mail servers (push protocol).  
Connection: Persistent TCP connection (port 25).  
Message format: Must be 7-bit ASCII (RFC 822 standard).  
Comparison with HTTP:  
HTTP → Pull (client fetches objects).  
SMTP → Push (server delivers mail).  
Both use ASCII commands, status codes.  
HTTP: each object = separate response.  
SMTP: multiple objects can be in one multipart message.  
Mail Message Format (RFC 822)  
Header: To: , From: , Subject: (ASCII only).  
Blank line  
Body: Actual message text.  
Mail Access Protocols  
SMTP only delivers to the recipient’s mail server.  
Retrieval uses mail access protocols:  
POP3 (Post Office Protocol v3) [RFC 1939] Simple, stateless.  
Modes:  
Download-and-delete → messages removed after fetch.  
Download-and-keep → messages remain on server.  
Commands:  
USER , PASS (authentication).  
LIST , RETR <msg#> , DELE <msg#> , QUIT .  
Limitation: If Bob uses multiple devices, messages may not sync.  
IMAP (Internet Mail Access Protocol) [RFC 1730] Keeps mail on server.  
Allows organizing into folders.  
Maintains state across sessions (folders, read/unread status).  
Better for multi-device access.  
HTTP (Webmail) – Gmail, Outlook.com, Yahoo Mail.  
DNS (Domain Name System)  
Purpose  
Maps hostnames ↔ IP addresses.  
Example: cs.umass.edu → 128.119.40.12  
Structure  
Distributed database (not centralized).  
Implemented by hierarchy of name servers:  

### 1. Root servers

### 2. Top-Level Domain (TLD) servers (.com, .org, .edu, etc.)

### 3. Authoritative servers (responsible for domains like umass.edu )

Operation  
Application-layer protocol (runs over UDP/TCP port 53).  
Used by hosts and DNS servers to resolve queries.  
Critical Internet function, but kept at application layer (edge complexity).  
Common DNS Records  
A → hostname → IPv4 address.  
AAAA → hostname → IPv6 address.  
MX → mail server.  
CNAME → alias for another hostname.  
NS → authoritative name server.  
In summary:  
SMTP → sends email (push).  
POP3/IMAP/HTTP → access email.  
POP3 = simple, stateless.  
IMAP = powerful, keeps state.  
DNS = Internet “phonebook” (hostnames ↔ IP addresses).  
sockets) into one neat exam-ready cheat sheet PDF with diagrams for quick revision?  

## Lecture Notes: DNS

DNS: services, structure  
Q: Why not centralize DNS?  
single point of failure  
traffic volume  
distant centralized database  
maintenance  
DNS services:  
hostname-to-IP-address translation  
host aliasing  
canonical, alias names  
mail server aliasing  
load distribution  
replicated Web servers: many IP  
addresses correspond to one  
name  
A: doesn‘t scale!  
Comcast DNS servers alone:  
600B DNS queries/day  
Akamai DNS servers alone:  
2.2T DNS queries/day  
Application Layer: 2-#  
Thinking about the DNS  
humongous distributed database:  
~ billion records, each simple  
handles many trillions of queries/day:  
many more reads than writes  
performance matters: almost every  
Internet transaction interacts with  
DNS - msecs count!  
organizationally, physically decentralized:  
millions of different organizations  
responsible for their records  
“bulletproof”: reliability, security  
Application Layer: 2-#  
DNS: a distributed, hierarchical database Client wants IP address for www.amazon.com; 1st approximation:  
client queries root server to find .com DNS server client queries .com DNS server to get amazon.com DNS server  
client queries amazon.com DNS server to get IP address for www.amazon.com  
.com DNS servers  
.org DNS servers  
.edu DNS servers  
Top Level Domain  
Root DNS Servers  
Root  
nyu.edu  
DNS servers  
umass.edu  
DNS servers  
yahoo.com  
DNS servers  
amazon.com  
DNS servers  
pbs.org  
DNS servers  
Authoritative  
Application Layer: 2-#  
DNS: root name servers  
official, contact-of-last-resort by  
name servers that can not  
resolve name  
Application Layer: 2-#  
DNS: root name servers  
official, contact-of-last-resort by  
name servers that can not  
resolve name  
incredibly important Internet  
function  
Internet couldn’t function without it!  
Remember Facebook outage a  
couple of days ago  
DNSSEC – provides security  
(authentication, message integrity)  
ICANN (Internet Corporation for  
Assigned Names and Numbers)  
manages root DNS domain  
13 logical root name “servers”  
worldwide each “server” replicated  
many times (~200 servers in US)  
Application Layer: 2-#  
Top-Level Domain, and authoritative servers Top-Level Domain (TLD) servers:  
responsible for .com, .org, .net, .edu, .aero, .jobs, .museums, and all top-level  
country domains, e.g.: .cn, .uk, .fr, .ca, .jp Network Solutions: authoritative registry for .com, .net TLD Educause: .edu TLD  
authoritative DNS servers:  
organization’s own DNS server(s), providing authoritative hostname to IP  
mappings for organization’s named hosts can be maintained by organization or service provider Application Layer: 2-#  
Local DNS name servers  
when host makes DNS query, it is sent to its local DNS server  
Local DNS server returns reply, answering:  
from its local cache of recent name-to-address translation pairs (possibly out  
of date!)  
forwarding request into DNS hierarchy for resolution each ISP has local DNS name server; to find yours:  
MacOS: % scutil --dns  
Windows: >ipconfig /all  
local DNS server doesn’t strictly belong to hierarchy Application Layer: 2-#  
DNS name resolution: iterated query  
Example: host at engineering.nyu.edu  
wants IP address for gaia.cs.umass.edu Iterated query:  
contacted server replies  
with name of server to  
contact  
“I don’t know this name,  
but ask this server”  
requesting host at  
engineering.nyu.edu  
gaia.cs.umass.edu  
root DNS server  
local DNS server  
dns.nyu.edu  
authoritative DNS server  
dns.cs.umass.edu  
TLD DNS server  
Application Layer: 2-#  
DNS name resolution: recursive query  
requesting host at  
engineering.nyu.edu  
gaia.cs.umass.edu  
root DNS server  
local DNS server  
dns.nyu.edu  
authoritative DNS server  
dns.cs.umass.edu  
TLD DNS server  
Recursive query:  
puts burden of name  
resolution on  
contacted name  
server  
heavy load at upper  
levels of hierarchy?  
Let me turn all that  
into a structured, simplified study summary you can revise quickly.  
DNS (Domain Name System)  
DNS Services  

### 1. Hostname → IP translation (e.g., www.amazon.com → 72.21.214.131 )

### 2. Host aliasing

Canonical name: actual hostname.  
Alias: user-friendly name.  

### 3. Mail server aliasing (MX records).

### 4. Load distribution

One name → multiple IPs (replicated servers for scalability & performance).  
Why Not Centralize DNS?  
Single point of failure → if central server fails, Internet breaks.  
Traffic volume → billions/trillions of queries/day.  
Latency → users worldwide would experience delays.  
Maintenance → impossible for one org to manage all records.  
Answer: Doesn’t scale. Must be distributed & hierarchical.  
DNS Structure  
Distributed, hierarchical database  
Millions of organizations manage their own records.  
High reliability (replication, caching, decentralization).  
Hierarchy  

### 1. Root DNS Servers

13 logical root servers (replicated worldwide ~200+ instances).  
Managed by ICANN.  
“Last resort” if a query cannot be resolved.  
Supports DNSSEC for authentication & integrity.  

### 2. Top-Level Domain (TLD) Servers

Responsible for domains like .com , .org , .edu , .cn , .uk , etc.  
Examples: Network Solutions (.com/.net), Educause (.edu).  

### 3. Authoritative DNS Servers

Maintained by an organization (e.g., Amazon, NYU).  
Provide authoritative mappings for hostnames to IPs.  

### 4. Local DNS Servers (a.k.a. Default Resolver)

Each ISP or organization has one.  
Acts as a cache and proxy:  
Answers if cached.  
Forwards query if not.  
Not part of hierarchy, but essential for reducing load.  
DNS Query Types  

### 1. Iterative Query

Resolver asks each server step by step:  
Root → TLD → Authoritative.  
Each server replies with “Ask this next server.” Client does more work.  

### 2. Recursive Query

Resolver asks one server to do all the work.  
That server queries others on behalf of the client.  
Heavier load on upper-level servers.  
Key Takeaways  
DNS = Internet’s phonebook (names ↔ IPs).  
Distributed & hierarchical → solves scaling & reliability.  
Root → TLD → Authoritative → Local DNS.  
Supports aliasing, mail routing, load balancing.  
Iterative vs Recursive queries define how resolution is done.  
FTP, SMTP, POP3/IMAP, DNS, Sockets) with one-page diagrams so you can use it as an exam revision PDF?  

## DNS Query Types and Root DNS Servers

When your computer wants to know the IP address of a website (like www.google.com ), it asks using different types of DNS queries:  

### 1. Recursive Query

Your computer asks the DNS server:  
“Please give me the final answer (IP). Don’t send me halfway results.” The DNS server then does all the searching (asking other servers if needed) and gives you the final IP.  
Example: You ask your local ISP DNS for www.google.com . It will contact root →  
TLD → authoritative servers and return the IP.  

### 2. Iterative Query

Your computer (or DNS server) asks:  
“If you don’t know the final answer, at least tell me who I should ask next.” The server replies with a referral (e.g., “I don’t know, but ask this server instead”).  
Example: Root DNS → says “ask .com server” → .com server says “ask google’s  
DNS” → google’s DNS gives IP.  

### 3. Inverse Query (Reverse DNS Lookup)

Instead of asking “What is the IP of example.com ?”, you ask:  
“I have an IP, tell me the domain name.” Example: 8.8.8.8 → resolves back to dns.google .  
Root DNS Servers  
Root servers are like the top-level phonebook keepers of the internet.  
They don’t know the IP of every site, but they know where to look next.  
There are 13 root server systems (named A to M), but each has many copies worldwide (using Anycast).  
What they contain:  
The list of TLD (Top-Level Domain) servers → like .com , .org , .net , .pk , .uk , etc.  
They do not store all domain names (like google.com ), only the pointers to the  
TLD servers.  
Example:  
You ask root DNS: “Where is www.google.com?” Root says: “I don’t know directly, but ask .com TLD servers.” Then .com servers point to Google’s authoritative DNS.  
Finally, Google’s DNS gives the IP.  
So:  
DNS Query types = recursive (give me final), iterative (give me next step), reverse (IP → name).  
Root DNS servers = contain addresses of TLD servers, not every website.  
how your browser gets an IP using recursive query → root → TLD → authoritative?  
DNS records  
DNS: distributed database storing resource records (RR) type=NS  
name is domain (e.g., foo.com)  
value is hostname of  
authoritative name server for  
this domain  
RR format: (name, value, type, ttl)  
type=A  
name is hostname  
value is IP address  
type=CNAME  
name is alias name for some “canonical” (the real) name  
www.ibm.com is really servereast.backup2.ibm.com value is canonical name  
type=MX  
value is name of SMTP mail  
server associated with name  
Application Layer: 2-#  
identification  
flags  
# questions  
questions (variable # of questions)  
# additional RRs  
# authority RRs  
# answer RRs  
answers (variable # of RRs)  
authority (variable # of RRs)  
additional info (variable # of RRs)  
2 bytes  
2 bytes  
DNS protocol messages  
DNS query and reply messages, both have same format:  
message header:  
identification: 16 bit # for query,  
reply to query uses same #  
flags:  
query or reply  
recursion desired  
recursion available  
reply is authoritative  
Application Layer: 2-#  
identification  
flags  
# questions  
questions (variable # of questions)  
# additional RRs  
# authority RRs  
# answer RRs  
answers (variable # of RRs)  
authority (variable # of RRs)  
additional info (variable # of RRs)  
2 bytes  
2 bytes  
DNS query and reply messages, both have same format:  
name, type fields for a query  
RRs in response to query  
records for authoritative servers  
additional “ helpful” info that may  
be used  
DNS protocol messages  
Getting your info into the DNS  
example: new startup “Network Utopia”  
register name networkuptopia.com at DNS registrar (e.g., Network  
Solutions)  
provide names, IP addresses of authoritative name server (primary and  
secondary)  
registrar inserts NS, A RRs into .com TLD server:  
(networkutopia.com, dns1.networkutopia.com, NS) (dns1.networkutopia.com, 212.212.212.1, A) create authoritative server locally with IP address 212.212.212.1  
type A record for www.networkuptopia.com type MX record for networkutopia.com  
Application Layer: 2-#  
Caching DNS Information  
once (any) name server learns mapping, it caches mapping,  
and immediately returns a cached mapping in response to query  
caching improves response time  
cache entries timeout (disappear) after some time (TTL)  
TLD servers typically cached in local name servers cached entries may be out-of-date  
if named host changes IP address, may not be known Internet-wide until all TTLs expire!  
best-effort name-to-address translation!  
Application Layer: 2-#  
DNS security  
DDoS attacks  
bombard root servers with  
traffic  
not successful to date  
traffic filtering  
local DNS servers cache IPs of TLD  
servers, allowing root server  
bypass  
bombard TLD servers  
potentially more dangerous  
you’ve gathered the main points of DNS basics, records, protocol messages, caching, and security  
Let me now explain this whole thing in easy, structured words so you can quickly recall:  
DNS Records (RR – Resource Records)  
Every entry in DNS is stored as a record in the format:  
Common Types:  

### 1. A Record

Maps hostname → IP address  
Example:  
(www.google.com, 142.250.183.14, A)  

### 2. NS Record

Shows the authoritative DNS server for a domain.  
Example:  
(example.com, dns1.example.com, NS)  

### 3. CNAME Record (Canonical Name)

Creates an alias for another hostname.  
Example:  
(www.ibm.com, servereast.backup2.ibm.com, CNAME)  

### 4. MX Record (Mail Exchange)

Points to the mail server for a domain.  
Example:  
(example.com, mail.example.com, MX)  
DNS Protocol Messages  
DNS uses the same format for queries and replies.  
Message Header (fixed part):  
Identification (16-bit ID) → matches query & reply.  
Flags → query or reply, recursion desired/available, authoritative, etc.  
Counters → number of questions, answers, authority RRs, additional RRs.  
Message Body:  
Questions → what you’re asking for (name + type).  
Answers → resource records answering the query.  
Authority → tells you which servers are authoritative.  
Additional → extra helpful info (like IP of the authoritative server).  
How Domains Get into DNS (Example: networkutopia.com )  

### 1. Register domain at a registrar.

### 2. Provide authoritative name server details (primary & secondary).

### 3. Registrar inserts NS & A records into .com TLD servers:

(networkutopia.com, dns1.networkutopia.com, NS) (dns1.networkutopia.com, 212.212.212.1, A)  

### 4. Set up your authoritative server with records:

(www.networkutopia.com, 212.212.212.1, A) (networkutopia.com, mail.networkutopia.com, MX)  
DNS Caching  
Local DNS servers cache results to answer faster.  
Cached data expires after TTL.  
Risk: If a host’s IP changes, old cache may give wrong results until TTL expires.  
DNS Security Issues  

### 1. DDoS attacks: attackers flood root or TLD servers.

Root servers are distributed (Anycast), so they are resilient.  
Local caches help reduce reliance on root servers.  
2. Cache Poisoning: attacker tricks a resolver into storing false info.  
Solution: DNSSEC (signed DNS responses).  
So in short:  
DNS Records = phonebook entries (A, NS, CNAME, MX).  
Messages = same format, with header + questions + answers + authority + additional.  
Caching = saves time but can become stale.  
Root servers = only store TLD pointers, not every domain.  
Security = target of DDoS & poisoning attacks.  
query goes from your browser → local DNS → root → TLD → authoritative → back? That pgsql  
(name, value, type, TTL)  

## Lecture Notes: Application Layer Review

Application Layer: Overview  
Principles of network  
applications  
Web and HTTP  
E-mail, SMTP, IMAP  
The Domain Name System  
DNS  
socket programming with  
UDP and TCP  
Application Layer: 2-#  
Socket programming  
goal: learn how to build client/server applications that communicate using sockets  
socket: door between application process and end-end- transport  
protocol  
Internet  
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
Socket programming  
In computer networks, communication happens between processes  
on different or same hosts.  
IP Addresses identify devices; Port Numbers identify processes.  
Example: 192.168.1.10:80  
IP for the host: 192.168.1.10  
Port for the webserver process: 80  
A socket is an endpoint for communication between two processes. It  
abstracts network communication and provides APIs for sending and  
receiving data.  
Socket programming  
Application Example:  
client reads a line of characters (data) from its keyboard and sends  
data to server  
server receives the data and converts characters to uppercase  
server sends modified data to client  
client receives modified data and displays line on its screen Socket programming  
Two socket types for two transport services:  
UDP: unreliable  
Datagram Sockets (SOCK_DGRAM)  
TCP: reliable  
Stream Sockets (SOCK_STREAM)  
Address families:  
AF_UNIX (local), if you want to use sockets on the same host.  
AF_INET (network), if you want to use sockets on the network.  
Application Layer: 2-#  
Socket programming  
sockaddr_in structure:  
This structure is used to store Internet Protocol (IP) addresses and  
port numbers for network communication. Think of it as the "address  
label" for a network endpoint.  
struct sockaddr_in {  
short int sin_family; // Address family (e.g., AF_INET) unsigned short int sin_port; // Port number struct in_addr sin_addr; // IP address unsigned char sin_zero[8]; // Padding (not used, but for size alignment)  
struct in_addr {  
unsigned long int s_addr; // IP address in network byte order  
Socket programming with TCP  
Client must contact server  
server process must first be  
running  
server must have created socket  
(door) that welcomes client’s  
contact  
Client contacts server by:  
Creating TCP socket, specifying IP  
address, port number of server  
process  
when client creates socket: client  
TCP establishes connection to  
server TCP  
when contacted by client, server  
TCP creates new socket for server  
process to communicate with that  
particular client  
allows server to talk with multiple  
clients  
source port numbers used to  
distinguish clients (more in Chap 3)  
TCP provides reliable, in-order  
byte-stream transfer (“pipe”)  
between client and server  
processes  
Application viewpoint  
Application Layer: 2-#  
Socket programming – Server (TCP)  
socket()  
First, a server application creates a socket, which like a file descriptor, is a  
resource assigned to the server process and that process alone.  
bind()  
Next, the server process gives the socket a name.  
listen()  
The server process then waits for a client to connect to the named socket.  
listen() creates a queue for incoming connections.  
accept()  
The server can accept them using the system call accept().  
Socket programming – Server (TCP)  
When the server calls accept(), it blocks.  
An incoming client connection unblocks accept().  
A new socket is created and returned by accept() is Distinct from the named (server) socket.  
This new socket is used solely for communication with the particular  
client.  
NOTE: The named socket (created in the start) remains intact to  
intercept more client connections.  
Socket programming – Client (TCP)  
socket()  
The client side of a socket-based system is more straightforward. The client  
creates an unnamed socket by calling socket().  
connect()  
It then calls connect() to establish a connection with the server by using the  
server’s named socket as an address.  
Once established, sockets can be used like low-level file descriptors,  
providing two-way data communications.  
Client/server socket interaction: TCP  
server  
Application Layer: 2-#  
int main()  
int S_sockfd, C_sockfd;  
int S_len, C_len;  
struct sockaddr_in S_address;  
struct sockaddr_in C_address;  
int result;  
char ch='A';  
S_sockfd = socket(AF_INET, SOCK_STREAM, 0); S_address.sin_family = AF_INET;  
S_address.sin_addr.s_addr = inet_addr("127.0.0.1"); S_address.sin_port = htons(9734);  
S_len = sizeof(S_address);  
bind(S_sockfd, (struct sockaddr *) &S_address, S_len); listen(S_sockfd, 5);  
host-to-network-short  
converts 16bit integer  
from host byte order  
to network byte order  
Client/server socket interaction: TCP  
server  
Application Layer: 2-#  
while(1)  
char ch;  
printf("Server %d waiting\n", getpid()); C_len = sizeof(C_address);  
C_sockfd = accept(S_sockfd, (struct sockaddr  
- )&C_address, &C_len);
if (C_sockfd == -1){  
perror("accept");  
continue; // Continue to next iteration instead of exiting result = read(C_sockfd, &ch, 1);  
if (result == -1){  
perror("read");  
close(C_sockfd);  
continue;  
ch++;  
result = write(C_sockfd, &ch, 1);  
if (result == -1){  
perror("write");  
close(C_sockfd);  
close(S_sockfd);  
exit(0);  
Client/server socket interaction: TCP  
client  
Application Layer: 2-#  
int main()  
int sockfd;  
int len;  
struct sockaddr_in address;  
int result;  
char ch='A';  
sockfd = socket(AF_INET, SOCK_STREAM, 0); address.sin_family = AF_INET;  
address.sin_addr.s_addr = inet_addr("127.0.0.1"); address.sin_port = htons(9734);  
len = sizeof(address);  
result = connect(sockfd, (struct sockaddr *)&address, len); if (result == -1){  
perror("client3");  
exit(1);  
write(sockfd, &ch, 1);  
read(sockfd, &ch, 1);  
printf("char from server = %c\n", ch); close(sockfd);  
exit(0);  
host-to-network-short  
converts 16bit integer  
from host byte order  
to network byte order  
Socket programming with UDP  
UDP: no “connection” between client  
and server:  
no handshaking before sending data  
sender explicitly attaches IP  
destination address and port # to each packet  
receiver extracts sender IP address and port# from received packet  
UDP: transmitted data may be lost or received out-of- order  
Application viewpoint:  
UDP provides unreliable transfer of groups of bytes (“datagrams”)  
between client and server processes  
Application Layer: 2-#  
Client/server socket interaction: UDP  
server  
Application Layer: 2-#  
int main()  
int S_sockfd;  
int S_len, C_len;  
struct sockaddr_in S_address;  
struct sockaddr_in C_address;  
int result;  
char ch='A’;  
S_sockfd = socket(AF_INET, SOCK_DGRAM, 0); S_address.sin_family = AF_INET;  
S_address.sin_addr.s_addr = inet_addr("127.0.0.1"); S_address.sin_port = htons(9734); // Added htons() for proper byte order  
S_len = sizeof(S_address);  
bind(S_sockfd, (struct sockaddr *) &S_address, S_len); host-to-network-short  
converts 16bit integer  
from host byte order  
to network byte order  
Client/server socket interaction: UDP  
server  
Application Layer: 2-#  
while(1)  
char ch;  
printf("Server %d waiting\n", getpid()); C_len = sizeof(C_address);  
result = recvfrom(S_sockfd, &ch, 1, 0, (struct sockaddr  
- )&C_address, &C_len);
if (result == -1)  
perror("recvfrom");  
continue; // Continue to next iteration instead of exiting ch++;  
result = sendto(S_sockfd, &ch, 1, 0, (struct sockaddr  
- )&C_address, C_len);
if (result == -1)  
perror("sendto");  
// No need to close C_sockfd - UDP uses same socket for all clients  
close(S_sockfd);  
exit(0);  
Client/server socket interaction: UDP  
client  
Application Layer: 2-#  
int main()  
int sockfd, len;  
struct sockaddr_in address;  
int result;  
char ch='A’;  
sockfd = socket(AF_INET, SOCK_DGRAM, 0); address.sin_family = AF_INET;  
address.sin_addr.s_addr = inet_addr("127.0.0.1"); address.sin_port = htons(9734);  
len = sizeof(address);  
result = sendto(sockfd, &ch, 1, 0, (struct sockaddr  
- )&address, len);
if (result == -1)  
perror("client3");  
exit(1);  
result = recvfrom(sockfd, &ch, 1, 0, (struct sockaddr  
- )&address, &len);
if (result == -1)  
perror("client3");  
exit(1);  
printf("char from server = %c\n", ch); close(sockfd);  
exit(0);  
host-to-network-short  
converts 16bit integer  
from host byte order  
to network byte order  
Chapter 2: Summary  
application architectures  
client-server  
P2P  
application service requirements:  
reliability, bandwidth, delay  
Internet transport service model  
connection-oriented, reliable: TCP  
unreliable, datagrams: UDP  
our study of network application layer is now complete!  
specific protocols:  
HTTP  
SMTP, IMAP  
DNS  
socket programming:  
TCP, UDP sockets  
Application Layer: 2-#  
Chapter 2: Summary  
Most importantly: learned about protocols!  
typical request/reply message  
exchange:  
client requests info or service  
server responds with data, status code message formats:  
headers: fields giving info about data data: info(payload) being  
communicated  
important themes:  
centralized vs. decentralized  
stateless vs. stateful  
scalability  
reliable vs. unreliable  
message transfer  
“complexity at network  
edge”  
Application Layer: 2-#  
Application Layer: 2-#  
Questions  
Socket Programming  
int socket(int domain, int type, int protocol); Creates a new socket (communication endpoint).  
domain: Address family (e.g., AF_INET, AF_UNIX).  
type: Communication type (SOCK_STREAM for TCP, SOCK_DGRAM for UDP).  
protocol: Usually 0 (system chooses default).  
int bind(int sockfd, const struct sockaddr  
- addr, socklen_t addrlen);
Assigns a local address (IP + port) to the socket.  
sockfd: The socket descriptor.  
addr: Address structure (e.g., sockaddr_in).  
addrlen: Size of address structure.  
Socket Programming  
int listen(int sockfd, int backlog);  
Marks the socket as passive (server) and sets up a connection queue.  
sockfd: Bound TCP socket.  
backlog: Max number of pending connections allowed.  
int accept(int sockfd, struct sockaddr  
- addr, socklen_t *addrlen);
Extracts the first connection request from the queue.  
sockfd: Listening socket.  
addr: Filled with client’s address info.  
addrlen: Input = size of structure, Output = actual size returned.  
Returns new socket descriptor for that client.  
Socket Programming  
int connect(int sockfd, const struct sockaddr  
- addr, socklen_t addrlen);
Initiates a connection on a socket.  
sockfd: Your TCP client socket.  
addr: The server's address (IP + port) to connect to.  
addrlen: Size of the server's address structure.  
Purpose: For TCP clients, this function actively attempts to establish a  
connection with a listening server. Once successful, sockfd is then  
connected to the server.  
Socket programming with UDP –  
sendto/recvfrom  
ssize_t sendto(int sockfd, const void *buf, size_t len, int flags  
, const struct sockaddr *dest_addr, socklen_t addrlen); ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags, s truct sockaddr *src_addr, socklen_t *addrlen); ssize_t → return value = number of bytes sent/received, or  
- 1 on error.
sockfd → socket descriptor (must be UDP for connectionless use).  
buf/len → actual data buffer and its size.  
flags → usually 0.  
dest_addr/addrlen (sendto) → specify recipient’s IP + port.  
src_addr/addrlen (recvfrom) → filled in with sender’s IP + port.  
Application Layer Overview  

### 1. Principles of Network Applications

Apps communicate over the network using protocols.  
Protocols define:  
Message formats (headers + data)  
Rules (who speaks first, request/reply) Examples: HTTP, SMTP, IMAP, DNS  

### 2. Application Architectures

Client-Server:  
Server always on, clients connect.  
Example: Web browsing.  
Peer-to-Peer (P2P):  
No always-on server, peers share resources directly.  
Example: BitTorrent.  

### 3. Transport Service Needs

Apps may need:  
Reliability (TCP ensures delivery & order) Low delay (VoIP, video calls)  
High bandwidth (video streaming)  

### 4. Internet Transport Models

TCP (SOCK_STREAM)  
Connection-oriented  
Reliable, in-order byte stream (like a pipe)  
UDP (SOCK_DGRAM)  
Connectionless  
Unreliable, faster (best effort)  

### 5. DNS (Domain Name System)

Maps names → IP addresses  
Distributed & hierarchical (root, TLD, authoritative servers) Types of records: A, NS, CNAME, MX  
Uses caching for faster lookups  
Socket Programming  
Concept  
A socket = door between application process and the network.  
Identified by IP address + Port number.  
Example: 192.168.1.10:80  
Server (TCP)  

### 1. socket() → create socket

### 2. bind() → assign IP + port

### 3. listen() → wait for clients (queue)

### 4. accept() → accept a client, new socket created

### 5. read() / write() → exchange data

### 6. close()

Client (TCP)  

### 1. socket() → create socket

### 2. connect() → connect to server’s IP + port

### 3. read() / write() → send/receive data

### 4. close()

UDP (No Connection)  
No handshake → just send and receive.  
Functions:  
sendto() → attach destination IP + port each time recvfrom() → receive + get sender info Important Socket Functions (Summary)  
socket(domain, type, protocol) → create bind(sockfd, addr, len) → assign address listen(sockfd, backlog) → wait for clients accept(sockfd, addr, len) → accept connection connect(sockfd, addr, len) → client connects to server sendto() / recvfrom() → used in UDP  
Key Themes  
Centralized vs. Decentralized (DNS is decentralized) Stateless vs. Stateful (HTTP = stateless, TCP = stateful) Scalability (DNS designed to scale)  
Reliable vs. Unreliable transfer (TCP vs. UDP) Complexity at edge (apps & protocols mostly handled at endpoints, not core network)  
So in short:  
Application layer = where apps live (Web, Email, DNS).  
Uses sockets to talk to transport layer (TCP/UDP).  
TCP = reliable stream, UDP = fast datagrams.  
DNS = distributed phonebook of the internet.  
diagrams for TCP vs UDP sockets and DNS resolution flow? That way you’ll have it handy for quick revision.  

## Formulas for Numericals

From all the Application Layer + DNS + Socket programming discussion above, most of it is conceptual and protocol-based, so there aren’t many “mathematical” formulas like you see in physical/network layers.  
But there are a few key formulas / numerical ideas that sometimes appear in exam problems or assignments:  
Useful Formulas (Application Layer context)  

### 1. Throughput

Measures how much data per second is delivered to the application.  
Example: If 10 MB file is transferred in 20s →  

### 2. Response Time (Web / HTTP request)

RTT = Round Trip Time (time to send a request and get first byte).  
Example: If RTT = 100 ms, Object = 1 MB, Bandwidth = 10 Mbps →  

### 3. Total Download Time (Multiple Objects in HTTP)

Non-persistent HTTP (no parallel connections):  
(1 RTT for handshake + N RTTs for N objects) Persistent HTTP with pipelining:  

### 4. DNS Query Delay

If DNS resolution requires  lookups, each costing 1 RTT:  
Example: If query needs root + TLD + authoritative →  

### 5. Email Transmission (SMTP)

If a message of size  
bits is sent over link bandwidth  
(Handshake RTT + transmission time).  
Summary  
Throughput formula  
Response time for file download  
HTTP total download time (persistent vs non-persistent)  
DNS lookup time  
SMTP/Email transmission delay  
step examples with numbers) so you can practice before exams?  
Throughput =  
Total Time (seconds)  
Total Data Transferred (bits)  
Throughput =  
10 × 8 × 106  
4 Mbps  
Response Time = RTT +  
Bandwidth  
Object Size  
Time = 0.1 +  
10 × 106  
8 × 106  
0.1 + 0.8 = 0.9 sec  
T = (1 + N) ⋅RTT +  
Bandwidth  
File Size  
T = RTT +  
Bandwidth  
File Size  
DNS  
n ⋅RTT  
3 ⋅RTT  
T = RTT +
