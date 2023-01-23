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
  <h2>Code Explanation</h2>
  <p>The following code connects to a Network and reads a PIN from a Keypad, this PIN is used as parameter to make a GET call to a Web API.</p>
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
