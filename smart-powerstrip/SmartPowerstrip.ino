/*SMART POWERSTRIP by Gabriele Baudo
 * Version 2.0
 * Updated 22/03/2020 12.50
*/

#include <SPI.h>
#include <Ethernet.h>

/////////////CHANGE THIS/////////////
int presa1 = 2;          //relay1
int presa2 = 7;          //relay2
int presa3 = 8;          //relay3
int presa4 = 3;          //relay4
/////////////////////////////////////

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; //MAC Address

/////////////CHANGE THIS/////////////
byte ip[] = { 192, 168, 1, 89 };       //IP Address
byte gateway[] = { 192, 168, 1, 1 };   //Gateway
byte subnet[] = { 255, 255, 255, 0 };  //Subnetmask
EthernetServer server(888);            //Port  
/////////////////////////////////////

String readString;

void setup() {
  Serial.begin(9600);
   while (!Serial) {
    ;
  }
  
  //Set pins as OUTPUT
  pinMode(presa1, OUTPUT);
  pinMode(presa2, OUTPUT);
  pinMode(presa3, OUTPUT);
  pinMode(presa4, OUTPUT);

  //Set all pins to low
  digitalWrite(presa1, LOW);
  digitalWrite(presa2, LOW);
  digitalWrite(presa3, LOW);
  digitalWrite(presa4, LOW);

  Ethernet.begin(mac, ip, gateway, subnet);
  server.begin();
  Serial.print("server is at: ");
  Serial.println(Ethernet.localIP());
}


void loop() {
  EthernetClient client = server.available();
  if (client) {
    while (client.connected()) {   
      if (client.available()) {
        char c = client.read();
        //Leggo char from HTTP
        if (readString.length() < 100) { 
          readString += c;
          Serial.print(c);
         }
         if (c == '\n') {          
           Serial.println(readString);
           
           ///////////////HTML PAGE, Change this graphic as you want///////////////
           client.println("HTTP/1.1 200 OK");
           client.println("Content-Type: text/html");
           client.println();     
           client.println("<HTML>");
           client.println("<HEAD>");
           client.println("<meta name='apple-mobile-web-app-capable' content='yes' />");
           client.println("<meta name='apple-mobile-web-app-status-bar-style' content='black-translucent' />");
           client.println("<link rel='stylesheet' type='text/css' href='http://www.progettiarduino.com/uploads/8/1/0/8/81088074/style3.css' />");
           client.println("<TITLE>CONTROL PANEL</TITLE>");
           client.println("</HEAD>");
           client.println("<BODY>");
           client.println("<H1>SMART POWERSTRIP</H1>");
           client.println("<H2>Gabriele Baudo</H1>");
           client.println("<hr />");
           client.println("<br />");  
           client.println("<a href=\"1on\"\">Presa 1: ON</a>");          //CHANGE THIS "Presa 1: ON"
           client.println("<a href=\"/1off\"\">Presa 1: OFF</a><br />"); //CHANGE THIS "Presa 1: OFF"
           client.println("<br />");  
           client.println("<br />");
           client.println("<a href=\"/2on\"\">Presa 2: ON</a>");          //CHANGE THIS "Presa 2: ON"
           client.println("<a href=\"/2off\"\">Presa 2: OFF</a><br />");  //CHANGE THIS "Presa 2: OFF"
           client.println("<br />");   
           client.println("<br />");
           client.println("<a href=\"/3on\"\">Presa 3: ON</a>");          //CHANGE THIS "Presa 3: ON"
           client.println("<a href=\"/3off\"\">Presa 3: OFF</a><br />");  //CHANGE THIS "Presa 3: ON"
           client.println("<br />");   
           client.println("<br />");
           client.println("<a href=\"/4on\"\">Presa 4: ON</a>");          //CHANGE THIS "Presa 4: ON"
           client.println("<a href=\"/4off\"\">Presa 4: OFF</a><br />");  //CHANGE THIS "Presa 4: OFF"
           client.println("<br />");  
           client.println("</BODY>");
           client.println("</HTML>");
           //////////////HTML PAGE END///////////////
           
           delay(1);
           client.stop();

           ///////////CONTROL TO ACTIVATE OR DEACTIVATE RELAYS////////////////
           if (readString.indexOf("1on") >0){
               digitalWrite(presa1, HIGH);
           }
           if (readString.indexOf("1off") >0){
               digitalWrite(presa1, LOW);
           }
           if (readString.indexOf("2on") >0){
               digitalWrite(presa2, HIGH);  
           }
           if (readString.indexOf("2off") >0){
               digitalWrite(presa2, LOW);
           }
           if (readString.indexOf("3on") >0){
               digitalWrite(presa3, HIGH);  
           }
           if (readString.indexOf("3off") >0){
               digitalWrite(presa3, LOW);
           }
           if (readString.indexOf("4on") >0){
               digitalWrite(presa4, HIGH);  
           }
           if (readString.indexOf("4off") >0){
               digitalWrite(presa4, LOW);
           }
           if (readString.indexOf("allon") >0){
               digitalWrite(presa1, HIGH);
               digitalWrite(presa2, HIGH);
               digitalWrite(presa3, HIGH);
               digitalWrite(presa4, HIGH);
           }
           if (readString.indexOf("allof") >0){
               digitalWrite(presa1, LOW);
               digitalWrite(presa2, LOW);
               digitalWrite(presa3, LOW);
               digitalWrite(presa4, LOW);
           }
            readString="";  
            
           
         }
       }
    }
}
}
