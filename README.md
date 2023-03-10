# Arduino GET API Call with Keypad and Ethernet Shield
Arduino code reading from a Keypad and making an API Call via GET Request using a Ethernet Shield.
<hr />
<div>
  Code example for Arduino UNO using a Keypad connected via Serial Connection and making an API Call via GET passing the pin from the Keypad using Ethernet Shield.
</div>
<div>
  <h2>Main Components</h2>
  <ul>
    <li>Arduino UNO Board</li>
    <li>Arduino Ethernet Shield</li>
    <li>Keypad 4x4 - PCF8574IC</li>
  </ul>
</div>
<div>
  <h2>Overview</h2>
  The code is used to connect to a Network by using an Arduino Ethernet Shield, it then reads a PIN from a Keypad, the PIN is input in the Keypad starting    with * + 4 digits number + #, this PIN is used as parameter to make a GET call to a Web API.
</div>
<div>
  <h2>Libraries</h2>
  <p>This example uses the following libraries:</p>
  <p>Libraries: 
    <ul>
      <li>Keypad.h</li>
      <li>SPI.h</li>
      <li>Ethernet.h</li>
    </ul>
  </p>
</div>
<div>
  <h2>Start up Network Variables</h2>
  <p>
   As you know, the Arduino Ethernet Shield must be configured manually with an MAC Address and some basic info such as the assigned IP Address and the DNS Address, for this example, their values are:
    <ul>
      <li><i>byte mac[] = { 0x00, 0xAA, 0xBB, 0xCC, 0xDA, 0x03 };</i> - setting up MAC Address</li>
      <li><i>IPAddress ip(192, 168, 1, 158);</i> - Assingning local IP</li>
      <li><i>IPAddress myDns(192, 168, 1, 254);</i> - Current DNS Address</li>
    </ul>
  </p>
</div>
<div>
  <h2>Functions</h2>
  <p>
    <b>setupNetworkInterface()</b><br />
    This functions sets up the Network Interface by checking the presence and status of the Network Adapter passing the MAC Address defined, the assigned IP Address and the DNS Address, all of them from the start up variables.
  </p>
  <p>
    <b>catchInputEntry()</b><br />
    This function is reading from Serial any incoming data from Keypad, each new key pressed in the Keypad is added to a string while cheking for characters * for new PIN and # for ending PIN char, characters between those two values are stored in <i>lpass</i> variable and updates <i>curAct</i> variable.
  </p>
  <p>
    <b>makeCall(char ser[], String req, String act, String hos)</b><br />
    This functions does the API call by taking <i>ser</i> as first parameter, <i>req</i> as "GET /url_complement?get=variables HTTP/1.1" where GET must start the string and end with HTTP/1.1 while the middle value is the rest of the url + any GET paramenter passed being in this case the PIN, <i>act</i> which is a 3 characters code used to filter actions, and finally <i>hos</i> as "Host: domain.com" which has to start with Host: and the API url.
  </p>
  <b>parseLNSData()</b><br />
  This function runs in the main loop and is checking the status of Ethernet client and <i>curAct</i> variable, if the Ethernet client has completed to load it will display in Serial output any incomming data. If it is waiting for an action, if <i>curAct</i> value is PIN then it makes an API call.
<div>
