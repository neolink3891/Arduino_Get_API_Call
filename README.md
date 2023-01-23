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
    This function is reading from Serial any incoming data from Keypad, each new key pressed in the Keypad is added to a string while cheking for characters * for new PIN and # for ending PIN char, characters between those two values are stored in <i>lpass<i/> variable
  </p>
<div>
