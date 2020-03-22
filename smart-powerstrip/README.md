# smart-powerstrip

# Goal
In this project we'll make a smart powerstrip controlled by webpage and integrated with Alexa and Google Assistant.

# Component used:
- Arduino Uno Board
- DFRobot Relay Shield 2.1
- Ethernet Shield

# Software used:
- Arduino IDE
- IFTT

# First Steps:
- First download the code
- Change relay pins as you want 
- Change ip address, subnet mask, gateway and server port to your favourite values+
- If you want you can change information and graphic of the HTML page
- Upload the code onto Arduino board
- Connect from your browser to: adruinoip:serverport (ex 192.168.1.1:888)
- Fun!


# IoT integration (advanced):
First of all, you need to set Dynamic DNS serice on your router, because Webhook service can't maek GET request to your local Arduino ip. So you need to set Dynamic DNS choosing from many providers offering this service (ex noip.com, dyndns.it).
Than you need to make a open specific port in your router (the same you set in arduino code). So from WAN you can access to your LAN via browser typing "yourhostname.yourdomain:port" (es. mysmarthome.ddns.net:888 || i use noip provider).
Now you have all ready, last thing to do is make a IFTT account, because we are going to use this service for IoT integration.
## Alexa
For Alexa integration, you have to create two applets for every relay you have in your powerstrip (one applet for ON and another for OFF). So, let's start.
- Log In in your IFTT account
- From you profile select "create new applet"
- In "this" statement use "Alexa" service
- Link your Amazon account to IFTT
- Select the option "say a specific phrase"
- Write the phrase you want
- In "that" statement use "Webhook" service
- Select "make a web request"
- In URL field write the link of your smart home (http://yourhostname.yourdomain:port/arduinotrigger) In "arduinotrigger" field you have to write the trigger set in the code (default are: 1on, 1off, 2on, 2off...)
- Choose GET method
- Select create action
- Now you have alexa connected with your smart powerstrip
## Google Assistant
For Google Assistant integration we use the same method of Alexa service, so we'll create two applets for every single relay.  So, let's start.
- Log In in your IFTT account
- From you profile select "create new applet"
- In "this" statement use "Google Assistant" service
- Link your Google account to IFTT
- Select the option "say a simple phrase"
- Write the phrase you want
- In "that" statement use "Webhook" service
- Select "make a web request"
- In URL field write the link of your smart home (http://yourhostname.yourdomain:port/arduinotrigger) In "arduinotrigger" field you have to write the trigger set in the code (default are: 1on, 1off, 2on, 2off...)
- Choose GET method
- Select create action
- Now you have Google Assistant connected with your smart powerstrip
