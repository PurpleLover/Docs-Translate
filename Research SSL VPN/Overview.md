# Overview about SSL VPN

## The need of SSL VPN
* TCP/IP is widely used to provide network communication.
(_Get Figure 2-1 to provide TCP/IP layers_)
* Security used in each layer
  * application layer
    * control establish for each app
  * transport layer
    * control to protect data in single session between 2 hosts
    * **TLS (transport layer security)**
    * use SSL Portal VPN
  * network layer
    * control can be applice to all apps, but provide less control to specific apps
    * NLS (network layer security)
    * use SSL Tunnel VPN, IPSEC
  * data link layer
    * applied to all communication on particular physical link -> cannot protect multiple links as VPN
* TLS
  * require each app support TLS
  * do not need to understand app
  * may need to modify app
  * well-tested -> relatively low-risk option
* NLS
  * no need modify apps to provide protection
  * excessive if a least apps in-use
* **SSL** (use for TLS)
  * HTTP-based app
  * provide protection for communication session of other types of app
  * Advantages
    * all major Web Browsers support TLS -> user only need browser
    * newer TLS protocols protect both HTTP and non-HTTP, include client/server and other network traffic
* IPSEC (user for NLS)
* Both IPSEC & SSL provide types of protection (add more later)

## Definition
### VPN (Virtual Private Network)
* a virtual network, build on top of existing physical network, provide secure communication _mechanism_ for data and other info transmit between netwrok
  * can be used over Internet, faciliate secure transfer of sensitive data across public network
  * less expesive than dedicated private telecom lines between organization or branch office
  * secure communication between remote telecom with organization server, regardless location
  * establish in single network to protect sensitive communicatioin from other parties in the same network
* VPN do not remove all risk from networking
  * Advantage
    * greatly reduce risk for communication occur over public network
    * support confidentiality and integrity
  * Disadvantage
    * cannot eleminate risks
  * Problems
    * strength of implementation: flaws in encryption algortihm, etc
    * encryption key disclosure: if attacker has key, he is inside system (as a end-user) and hard to detect
    * availabilty: sometimes vpn add more services and components to existing network infrasture (base on VPN architecture)
* Types (Models)
  * Portal
  * Tunnel
  (Both above provide remote access to multiple services controlled and administered by SSL VPN gateway)
  * Gateway-to-gateway (rarely used)
* SSL VPN gateway
  * maybe hardware system contain software need to perform SSL VPN task
  * maybe fireway and router contain SSL VPN capbilities (when turned on in sys admin interface)
* **NO** standard for SSLVPN
### VPN Models
#### SSL Portal VPN
* act as transport layer VPN, work over single port (443)
* indentify remote user via authentication method supported by SSL VPN gateway
* portal (single page lead to many resource), use as simple Web Page, but have more service after user authenticated
* using HTTPS
* work with every browsers (not) allow/support active content

#### SSL Tunnel VPN
* require browser allow/support active content, user can run them
* tunnel
  * almost all IP traffic is fully protected by the tunnel -> user full access to service on network protected by VPN gateway
  * created in SSL using non-standard tunneling method
* allow wide range of protocol and app run through it
  * more content than Portal
  * plugin or apps need to be loaded on user's browser first -> increase load time, maybe prevent by browser itself

#### Administing SSL VPN
Gateway admin needs to specific:
* Access: which user have access to VPN?
* Capabilities: what authenticated users allow to do?

## Fundamental
(Need more time and effort)