#include <Keypad.h>
#include <SPI.h>
#include <Ethernet.h>

char getAnswer[16]; 
int getAnswerCount = 0; 
char answerValue[10]; 
int answerValueCount = 0; 

const byte n_rows = 4;
const byte n_cols = 4;
char keys[n_rows][n_cols] = {
 {'1','2','3','A'},
 {'4','5','6','B'},
 {'7','8','9','C'},
 {'*','0','#','D'}
};
byte rowPins[n_rows] = {2, 3, 4, 5};
byte colPins[n_cols] = {6, 7, 8, 9};
Keypad myKeypad = Keypad( makeKeymap(keys), rowPins, colPins, n_rows, n_cols);

String serRes = "";
bool printWebData = true;
bool comDet = false;
String curAct = "";
unsigned long beginMicros, endMicros;
String doorPin = "*0000";
String lpass = "";
int passlen = 0;

byte mac[] = { 0x00, 0xAA, 0xBB, 0xCC, 0xDA, 0x03 };
IPAddress ip(192, 168, 1, 158);
IPAddress myDns(192, 168, 1, 254);
EthernetClient client;

void setup() {
  Serial.begin(9600);

  setupNetworkInterface();
  
  makeCall("domain.com", "GET /url_complement?get=variables HTTP/1.1", "REQ", "Host: domain.com");
}

void loop() {
  delay(5);
  
  catchInputEntry();

  parseLNSData();
}

void catchInputEntry() {
  char myKey = myKeypad.getKey();
  if (myKey != NULL){
  Serial.println(myKey);
  if(myKey == '#') {
      passlen = lpass.length();
      if(passlen == 9) {
        Serial.println("Sending Example");
        Serial.println(lpass);
        makeCall("domain.com", "GET /url_complement?get=variables HTTP/1.1", "REQ", "Host: domain.com");
          lpass = "";
        } else {
          lpass = "";
          Serial.println("param cleared");
        }
   } else {
      if(myKey == '*') {
        lpass = myKey;
        Serial.println("param started");
      } else {
        lpass += myKey;
        Serial.println("param built");
      }
    }
  }
}

void parseLNSData() {
  if (client.available()) {
    char c = client.read();
    if(c == '|') {
      comDet = true;
    } else {
      if(c == '=') {
        comDet = false;
        printWebData = true;
      }
      if(comDet == true) {
        serRes += c;
      }
    }
  } else {
    if(printWebData) {
      if(curAct == "TAG") {
        doorPin = serRes;
        Serial.print(doorPin);
        curAct = "";
      } else if (curAct == "PIN") {
        Serial.println("Controller called");
        Serial.println(serRes);
        makeCall("192.168.1.157", "GET /?com=" + serRes + " HTTP/1.1", "EMP", "Host: 192.168.1.157");
        curAct = "";
      } else {
        curAct = "";
      }
      
      printWebData = false;
    }
  }
}

void makeCall(char ser[], String req, String act, String hos) {
  client.stop();
  serRes = "";
  printWebData = false;
  comDet = false;
  curAct = act;
  
  Serial.println("Connecting to PQP Live Network Server");

  if (client.connect(ser, 80)) {
    Serial.println("Connection estabilished!");
    client.println(req);
    client.println(hos);
    client.println("Connection: close");
    client.println();
  } else {
    Serial.println("connection failed");
  }
  Serial.println("request sent");
  beginMicros = micros();
}

void setupNetworkInterface() {
  Serial.println("======== NeoLink Test =========");
  Serial.println(" ");
  Serial.println("Initializing...");
  Serial.println("Launching Networking Interface.");
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    if (Ethernet.hardwareStatus() == EthernetNoHardware) {
      Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
      while (true) {
        delay(1);
      }
    }
    if (Ethernet.linkStatus() == LinkOFF) {
      Serial.println("Ethernet cable is not connected.");
    }
    Ethernet.begin(mac, ip, myDns);
    
  } else {
    Serial.println("Hardwared Initialized.");
    Serial.println("Connecting to LAN.");
    Serial.println("Connected!");
    Serial.print("Assigned IP: ");
    Serial.println(Ethernet.localIP());
    Serial.println("Setup finished successful.");
  }
}
