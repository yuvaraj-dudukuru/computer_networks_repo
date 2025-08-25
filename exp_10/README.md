10. Wireshark and Nmap
These are practical exercises using network tools. No code is required, only instructions.

Wireshark Guide
Packet Capture:

Open Wireshark. You will see a list of network interfaces (e.g., "Wi-Fi," "Ethernet").

Double-click the interface that has network activity (you'll see a graph next to it).

Wireshark will immediately start capturing all packets on that interface.

Viewing Captured Traffic:

As packets are captured, they appear in real-time in the "Packet List" pane.

Click on any packet in the list.

The "Packet Details" pane below will show you the protocol layers of that packet (e.g., Frame, Ethernet, IPv4, TCP, HTTP). You can expand each layer to see detailed fields.

The "Packet Bytes" pane at the bottom shows the raw hexadecimal data of the packet.

Analysis, Statistics & Filters:

Filters: In the filter bar at the top, you can type filters to see specific traffic.

ip.addr == 8.8.8.8 (shows packets to/from Google's DNS server)

tcp.port == 80 (shows HTTP traffic)

dns (shows only DNS queries and responses)

Press Enter to apply the filter.

Statistics: Go to the Statistics menu for powerful analysis tools.

Statistics -> Endpoints: Shows all the IP addresses your computer communicated with.

Statistics -> Protocol Hierarchy: Shows a breakdown of all protocols captured and their percentage of the traffic.

Statistics -> Conversations: Lists all the TCP/IP conversations between hosts.

Nmap Guide
Nmap is a powerful network scanner. Open a command prompt or terminal to run these commands.

How to Run a Basic Nmap Scan:

This scan checks for common open ports and determines if a host is online. Replace <target> with an IP address or hostname (e.g., 192.168.1.1 or scanme.nmap.org).

Command: nmap <target>

Operating System Detection using Nmap:

Nmap can analyze TCP/IP stack responses to make an educated guess about the target's operating system. This requires root/administrator privileges.

Command: sudo nmap -O <target> (on Linux/macOS) or run Command Prompt as Administrator on Windows.

Example: sudo nmap -O 192.168.1.1

