# Checksum

## What a Checksum Is

A checksum is a small piece of data used to check if something (like a file or message) has been changed or corrupted.  
Simple idea:  
Think of it like a fingerprint of data.  
Easy example:  
Suppose you have a file: "hello"  
A system runs a formula on it and creates a number (checksum), like: 12345 Later, when you receive the file, the system calculates the checksum again If the new checksum = 12345 → file is unchanged If it's different -→ file was modified or damaged Real-life analogy:  
It's like sending a parcel with a seal:  
If the seal is intact -→ everything is fine If the seal is broken -→ something changed Why checksum is useful:  
Detects errors during file transfer  
Ensures data integrity  
Used in downloads, networking, and storage In one line:  
Checksum = a quick way to verify data hasn't changed.  

## Checksums in File Downloads and Computer Networks

h 1. Checksum in Downloading Files  
When you download a file (like software, game, PDF):  
How it works:  

### 1. The website gives a checksum value (e.g., MD5, SHA-256)

### 2. You download the file

### 3. Your system calculates the checksum of the downloaded file

### 4. You compare both values

Result:  
Same checksum -→ File is correct and safe Different checksum -→ File is corrupted or tampered Example:  
Website checksum: A1B2c3  
Your file checksum: A1B2c3  
OK  
Your file checksum: x9Y8z7  
Problem  
Used to:  
Ensure file didn't break during download Verify file is not modified (security) ( 2. Checksum in Computer Networks  
When data travels over the internet:  
How it works:  

### 1. Sender calculates checksum of data packet

### 2. Sends data + checksum

### 3. Receiver recalculates checksum

### 4. Compares with received checksum

Result:  
Match -→ Data received correctly  
Not match → Data has errors → request resend Example:  
Sender sends:  
Data: 101010  
Checksum:111  
Receiver checks:  
If checksum matches → accept  
If not -→ discard and ask again  
Key Difference  
Area  
Purpose  
Downloading files  
Verify file integrity & security  
Computer networks  
Detect transmission errors  
In One Line:  
Downloading: "Did my file arrive safely?" Networking: "Did my data travel without errors?"  

## Worked Problem

Example (Computer Networks Checksum)  
Data1 =10101010  
Data2 = 11001100  
Data3 = 11110000  

### Step 1: Add all data (binary addition)

- 11001100
- 11110000
(Add them)  
First add two:  
= 1 01110110  
(carry ignored for now)  
Add third:  

### Step 2: Add carry (wrap-around)

01100110+1=01100111  

### Step 3: Take 1's complement

Flip bits:  
01100111 → 10011000  
This is the checksum  
Sender sends:  
Data + Checksum =  
- At Receiver Side

### Step 1: Add everything (including checksum)

:11111111  

### Step 2: Check result

If result = 11111111 →  
No error  
If not → X Error in transmission  
Final Answer:  
Checksum = 10011000  
Data is correct if final sum = all 1s  
Simple Trick:  
Add all numbers  
Add carry  
Take complement -→ checksum  
At receiver -→ result must be all 1s  
problems
