#include <SoftwareSerial.h>
SoftwareSerial mySerial(3, 2); // TX, RX (GMS)
String input;

char URL[300];
char body[100];
char api_writekey[20] = "5O4GMBK6OK36E8VF";//"CL0YLK7884AWALX3"; //
char auxStr[100];

//char fieldVal1 = "200";
//char fieldVal2 = "1";
//char fieldVal3 = "1";
//char fieldVal4 = "1";
//char fieldVal5 = "1";

int count = 0;//number of times to run the commands


void setup()
{

  //FireBasics

  //Fire POST/PUT-write
  //sprintf(body, "{\"Mistake_to_be_cleaned\":\"eRr05\"}\r\n"); // Terminate with CR+NL
  //sprintf(URL, "PUT /hives/22072019GSM/-LkObYbfjtnUtV4F_iis.json HTTP/1.1\r\nHost: beehive-cd8ed.firebaseio.com\r\nConnection: open\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: %i\r\n\r\n", strlen(body));

  //Fire GET-read data
  //sprintf(URL, "GET /hives/22072019GSM.json HTTP/1.1\r\nHost: beehive-cd8ed.firebaseio.com\r\nConnection: open\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: %i\r\n\r\n", strlen(body));


  //Fire Delete-remove data
  //sprintf(URL, "DELETE /hives/22072019GSM/-LkOVm2f5BkDP0GJc6bA/location.json HTTP/1.1\r\nHost: beehive-cd8ed.firebaseio.com\r\nConnection: open\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: %i\r\n\r\n", strlen(body));

  //Fire Override method not working
 //sprintf(URL, "POST /hives/22072019GSM/-LkObYbfjtnUtV4F_iis.json?x-http-method-override=PUT HTTP/1.1\r\nHost: beehive-cd8ed.firebaseio.com\r\nConnection: open\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: %i\r\n\r\n", strlen(body));
 //sprintf(body, "{\"Rebirth\":\"52\"}\r\n");


  //sprintf(URL, "POST X-HTTP-Method-Override: DELETE /hives/22072019GSM/-LkOVm2f5BkDP0GJc6bA/location.json HTTP/1.1\r\nHost: beehive-cd8ed.firebaseio.com\r\nConnection: open\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: %i\r\n\r\n", strlen(body));


  /*
    POST /hives.json HTTP/1.1
    Host: beehive-cd8ed.firebaseio.com
    Content-Type: application/x-www-form-urlencoded
    cache-control: no-cache
    Postman-Token: 85b434df-1cff-4e63-8091-7f2a854dc3e9

    { "date": "19072019", "hive_name": "HIVEmind", "location": "Khalid" }
  */

  //finito
  //successful submission with server response
  //sprintf(URL, "GET /update?api_key=%s&field1=%s HTTP/1.1\r\nHost: https://api.thingspeak.com\r\nConnection: open\r\nX-TINGSPEAKAPIKEY: %s\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: %i\r\n\r\n", api_writekey, fieldVal1, api_writekey, strlen(body));

  //finito
  //successful submission but no server response
  //sprintf(URL, "GET /update?api_key=%s&field1=%s\r\n HTTP/1.1\r\nHost: https://api.thingspeak.com\r\nConnection: open\r\nX-TINGSPEAKAPIKEY: %s\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: %i\r\n\r\n", api_writekey, fieldVal1,api_writekey, strlen(body));



  // sprintf(URL, "GET /update?api_key=%s&field1=%s&field2=%s&field3=%s\r\n HTTP/1.1\r\nHost: https://api.thingspeak.com\r\nConnection: open\r\nX-TINGSPEAKAPIKEY: %s\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: %i\r\n\r\n", api_writekey, fieldVal1,fieldVal2,fieldVal3,api_writekey, strlen(body));
  //sprintf(body, "0");




  //sprintf(URL, "POST /update? HTTP/1.1\r\nHost: https://api.thingspeak.com\r\nConnection: open\r\nX-TINGSPEAKAPIKEY: %s\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: %i\r\n\r\n",api_writekey, strlen(body));
  //sprintf(body, "api_key=%s&field1=%s\r\n", api_writekey, fieldVal1);






  //sprintf(URL, "GET /update?api_key=%s&field1=%s\r\n HTTP/1.1\r\n\r\n", api_writekey, fieldVal1);
  //sprintf(URL, "GET /update?api_key=%s&field1=%s HTTP/1.1\r\n\r\n", api_writekey, fieldVal1);



  //sprintf(body, "", api_writekey, fieldVal1);





  //sprintf(body, "{\"api_key\":%s,\"field1\":%s,\"field2\":%s,\"field3\":%s,\"field4\":%s,\"field5\":%s}\r\n", api_writekey, fieldVal1, fieldVal2, fieldVal3, fieldVal4, fieldVal5); // Terminate with CR+NL
  //sprintf(body, "{\"api_key\":%s,\"field1\":%s}\r\n", api_writekey, fieldVal1);
  //sprintf(URL, "POST / HTTP/1.1\r\nHost: api.thingspeak.com\r\nContent-Length: %i\r\n\r\n", strlen(body));
  //sprintf(URL, "POST / HTTP/1.1\r\nHost: api.thingspeak.com\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: %i\r\n\r\n", strlen(body));
  //sprintf(URL, "POST /https://api.thingspeak.com/channels/815365.html HTTP/1.1\r\nHost: api.thingspeak.com\r\nContent-Length: %i\r\n\r\n", strlen(body));
  //sprintf(URL, "POST /api.thingspeak.com/channels/815365.html HTTP/1.1\r\nHost: api.thingspeak.com\r\nContent-Length: %i\r\n\r\n", strlen(body));
  //sprintf(URL, "POST /api.thingspeak.com/channels/815365.html HTTP/1.1\r\nHost: https://api.thingspeak.com\r\nContent-Length: %i\r\n\r\n", strlen(body));
  //sprintf(URL, "POST /api.thingspeak.com/channels/815365.html HTTP/1.1\r\nHost: api.thingspeak.com\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: %i\r\n\r\n", strlen(body));
  //sprintf(URL, "POST /channels/815365.html HTTP/1.1\r\nHost: https://api.thingspeak.com\r\nContent-Length: %i\r\n\r\n", strlen(body));
  //sprintf(URL, "POST /api.thingspeak.com/update.html HTTP/1.1\r\nHost: https://api.thingspeak.com\r\nContent-Length: %i\r\n\r\n", strlen(body));
  //sprintf(URL, "POST /https://api.thingspeak.com/update.html HTTP/1.1\r\nHost: https://api.thingspeak.com\r\nContent-Length: %i\r\n\r\n", strlen(body));
  //sprintf(URL, "POST /update HTTP/1.1\r\nHost: https://api.thingspeak.com\r\nContent-Length: %i\r\n\r\n", strlen(body));

  //sprintf(URL, "POST /update HTTP/1.1\r\nHost: https://api.thingspeak.com\r\nConnection: close\r\nX-THINGSPEAKAPIKEY: %s\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: %i\r\n\r\n", api_writekey, strlen(body));
  //sprintf(URL, "POST / THINTHINTHINupdate%s HTTP/1.1\r\nHost Iwatchedtheworldfloattothedarksid%i eofthmAfter allIknew,ithadtobesomethingtodowithyouIreallydon'tmindwhathappensnowand thenAdkdkdks\r\n\r\n", api_writekey, strlen(body));


  //sprintf(URL, "POST /update HTTP/1.1\r\nHost: https://api.thingspeak.com\r\nConnection: close\r\nX-THINGSPEAKAPIKEY: %s\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: %i\r\n\r\n", api_writekey, strlen(body));
  //sprintf(body, "{\"api_key\":%s,\"field1\":%s}\r\n", api_writekey, fieldVal1);


  //  for data visualisation testing



  //sprintf(URL, "POST /update HTTP/1.1\r\nHost: https://api.thingspeak.com\r\nConnection: open\r\nX-THINGSPEAKAPIKEY: %s\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: %i\r\n\r\n", api_writekey, strlen(body));
  // sprintf(body, "{\"api_key\":%s,\"field1\":%s}\r\n", api_writekey, fieldVal1);

  // question mark after update
  //sprintf(URL, "POST /update? HTTP/1.1\r\nHost: https://api.thingspeak.com\r\nConnection: open\r\nX-THINGSPEAKAPIKEY: %s\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: %i\r\n\r\n", api_writekey, strlen(body));
  //sprintf(body, "{\"api_key\":%s,\"field1\":%s}\r\n", api_writekey, fieldVal1);

  // body:no commas
  //sprintf(URL, "POST /update? HTTP/1.1\r\nHost: https://api.thingspeak.com\r\nConnection: open\r\nX-THINGSPEAKAPIKEY: %s\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: %i\r\n\r\n", api_writekey, strlen(body));
  //sprintf(body, "{\"api_key\":%s\"field1\":%s}\r\n", api_writekey, fieldVal1);

  // body: no brackets
  //sprintf(URL, "POST /update? HTTP/1.1\r\nHost: https://api.thingspeak.com\r\nConnection: open\r\nX-THINGSPEAKAPIKEY: %s\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: %i\r\n\r\n", api_writekey, strlen(body));
  //sprintf(body, "\"api_key\":%s,\"field1\":%s\r\n", api_writekey, fieldVal1);


  //GET series

  //BASIC GET, BODY: EQUALS TO SYMBOLS
  //sprintf(URL, "GET /update? HTTP/1.1\r\nHost: https://api.thingspeak.com\r\nConnection: open\r\nX-THINGSPEAKAPIKEY: %s\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: %i\r\n\r\n", api_writekey, strlen(body));
  //sprintf(body, "{\"api_key\"=%s,\"field1\"=%s}\r\n", api_writekey, fieldVal1);


  // BODY: EQUALS TO SYMBOLS, & IN FRONT OF FIELD
  // sprintf(URL, "GET /update? HTTP/1.1\r\nHost: https://api.thingspeak.com\r\nConnection: open\r\nX-THINGSPEAKAPIKEY: %s\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: %i\r\n\r\n", api_writekey, strlen(body));
  //sprintf(body, "{\"api_key\"=%s,\"&field1\"=%s}\r\n", api_writekey, fieldVal1);




  // BODY: EQUALS TO SYMBOLS, & IN FRONT OF FIELD, NO BRACKETS
  // sprintf(URL, "GET /update? HTTP/1.1\r\nHost: https://api.thingspeak.com\r\nConnection: open\r\nX-THINGSPEAKAPIKEY: %s\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: %i\r\n\r\n", api_writekey, strlen(body));
  //sprintf(body, "\"api_key\"=%s,\"&field1\"=%s\r\n", api_writekey, fieldVal1);

  // BODY: EQUALS TO SYMBOLS, & IN FRONT OF FIELD, NO BRACKETS, NO QUOTES \"\" ON API KEY AND FIELD1
  //sprintf(URL, "GET /update? HTTP/1.1\r\nHost: https://api.thingspeak.com\r\nConnection: open\r\nX-THINGSPEAKAPIKEY: %s\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: %i\r\n\r\n", api_writekey, strlen(body));
  //sprintf(body, "api_key=%s,&field1=%s\r\n", api_writekey, fieldVal1);

  // BODY: EQUALS TO SYMBOLS, & IN FRONT OF FIELD, NO BRACKETS, NO QUOTES \"\", NO COMMAS
  //sprintf(URL, "GET /update? HTTP/1.1\r\nHost: https://api.thingspeak.com\r\nConnection: open\r\nX-THINGSPEAKAPIKEY: %s\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: %i\r\n\r\n", api_writekey, strlen(body));
  //sprintf(body, "api_key=%s&field1=%s\r\n", api_writekey, fieldVal1);


  //sprintf(URL, "GET /update? HTTP/1.1\r\nHost: https://api.thingspeak.com\r\nConnection: open\r\nX-THINGSPEAKAPIKEY: %s\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: %i\r\n\r\n", api_writekey, strlen(body));
  //sprintf(body, "{\"api_key\"=%s\"&field1\"=%s}\r\n", api_writekey, fieldVal1);


  //just GET
  //sprintf(URL, "GET /update HTTP/1.1\r\nHost: https://api.thingspeak.com\r\nConnection: open\r\nX-THINGSPEAKAPIKEY: %s\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: %i\r\n\r\n", api_writekey, strlen(body));
  //sprintf(body, "{\"api_key\":%s,\"field1\":%s}\r\n", api_writekey, fieldVal1);


  //sprintf(URL, "GET /update HTTP/1.1\r\nHost: https://api.thingspeak.com\r\nConnection: open\r\nX-THINGSPEAKAPIKEY: %s\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: %i\r\n\r\n", api_writekey, strlen(body));
  //sprintf(body, "{\"api_key\":%s,\"field1\":%s}\r\n", api_writekey, fieldVal1);



  //for format testing

  // "https://" IN HOST missing
  //sprintf(URL, "POST /update HTTP/1.1\r\nHost: api.thingspeak.com\r\nConnection: open\r\nX-THINGSPEAKAPIKEY: %s\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: %i\r\n\r\n", api_writekey, strlen(body));
  //sprintf(body, "{\"api_key\":%s,\"field1\":%s}\r\n", api_writekey, fieldVal1);


  // "X-THINGSPEAKAPIKEY: %s" missing
  //sprintf(URL, "POST /update HTTP/1.1\r\nHost: https://api.thingspeak.com\r\nConnection: open\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: %i\r\n\r\n", strlen(body));
  //sprintf(body, "{\"api_key\":%s,\"field1\":%s}\r\n", api_writekey, fieldVal1);


  // "Content-Type: application/x-www-form-urlencoded" missing
  //sprintf(URL, "POST /update HTTP/1.1\r\nHost: https://api.thingspeak.com\r\nConnection: open\r\nX-THINGSPEAKAPIKEY: %s\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: %i\r\n\r\n", api_writekey, strlen(body));
  //sprintf(body, "{\"api_key\":%s,\"field1\":%s}\r\n", api_writekey, fieldVal1);


  // api write key value without name
  //sprintf(URL, "POST /update HTTP/1.1\r\nHost: api.thingspeak.com\r\nConnection: open\r\nX-THINGSPEAKAPIKEY: %s\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: %i\r\n\r\n", api_writekey, strlen(body));
  //sprintf(body, "{%s,\"field1\":%s}\r\n", api_writekey, fieldVal1);

  // "https://" IN HOST missing
  //sprintf(URL, "POST /update HTTP/1.1\r\nHost: api.thingspeak.com\r\nConnection: open\r\nX-THINGSPEAKAPIKEY: %s\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: %i\r\n\r\n", api_writekey, strlen(body));
  //sprintf(body, "{\"api_key\":%s,\"field1\":%s}\r\n", api_writekey, fieldVal1);


  /*
    sprintf(URL, "POST /update HTTP/1.1\r\nHost: https://api.thingspeak.com\r\nConnection: open\r\nX-THINGSPEAKAPIKEY: %s\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: %i\r\n\r\n", api_writekey, strlen(body));
    sprintf(body, "{%s,\"field1\":%s,\"field2\":%s,\"field3\":%s,\"field4\":%s,\"field5\":%s}\r\n", api_writekey, fieldVal1, fieldVal2, fieldVal3, fieldVal4, fieldVal5);
  */


  // Open serial communications to computer
  Serial.begin(115200);
  delay(100); // Let the command run
  Serial.println(F("Configuring to 4800 baud"));
  mySerial.begin(115200); // Default for the board
  mySerial.println("AT+IPR=4800");  // Set baud to 4800
  delay(100); // Let the command run
  mySerial.begin(4800); // Reconnect at lower baud, 4800 had issues with SoftwareSerial

  //Serial_command("AT+CFUN=1",5000);
  delay(5000);
  //Clear out any waiting serial data
  while (mySerial.available())
  {
    mySerial.read();
  }
  Serial.print("~");
  Serial.print("Alive");
  Serial.println("~");
  mySerial.println("AT");
  delay(500); //wait for AT wthen check for "OK" reply
  while (mySerial.available())
  {
    Serial.write(mySerial.read());
  }


  delay(5000);

while (Serial.available())
  {
    Serial.write(Serial.read());
  }
}




void loop() {


  while (count < 1) {


    Serial.println(strlen(URL));
    Serial.println(URL);
    Serial.println(strlen(body));
    Serial.println(body);



    HiveenableGPRS(true);

    HivepostData("beehive-cd8ed.firebaseio.com", 443, "HTTPS", URL, body);
    // Sample request Server: "www.thingspeak.com"
    // Sample request port: 443
    // Sample request connType: "HTTPS"
    //HiveenableGPRS(false);
    count++;
  }


  // put your main code here, to run repeatedly:
  if (Serial.available())
  {
    input = Serial.readStringUntil('\n');
    Serial.print("*");
    Serial.print(input);
    Serial.println("*");  //so user can read the text/command inputted distinguished with asterisks
    mySerial.print(input);    // softSerial inputs text/command to GMS mod
  }
  while (mySerial.available())
  {
    Serial.write(mySerial.read());
  }
}


/*Post code*/
boolean HivepostData(const char *server, uint16_t port, const char *connType, const char *URL, const char *body) {
  // Sample request URL: "GET /dweet/for/{deviceID}?temp={temp}&batt={batt} HTTP/1.1\r\nHost: dweet.io\r\n\r\n"
  // Sample request Server: "www.dweet.io"
  // Sample request port: 443
  // Sample request connType: "HTTPS"

  // Start HTTPS stack
  Serial_astprint("AT+CHTTPSSTART\r");
  Serial.println(F("Waiting 1s to ensure connection..."));
  delay(10000); //wait for response
  Softsee_read(); // check for ok replay

  delay(500); //buffer

  // Construct the AT command based on function parameters
  // char auxStr[strlen(URL) + strlen(server) + 7];


  //char auxStr[100];
  uint8_t connTypeNum = 1;

  if (strcmp(connType, "HTTP") == 0) {
    connTypeNum = 1;
  }
  if (strcmp(connType, "HTTPS") == 0) {
    connTypeNum = 2;
  }

  sprintf(auxStr, "AT+CHTTPSOPSE=\"%s\",%d,%d\r", server, port, connTypeNum);
  //"AT+CHTTPSOPSE=\"www.dweet.io\",443,2"  Use port 443 and HTTPS


  delay(1000); //buffer

  // Connect to HTTPS server


  Serial_tildeprint(auxStr);
  Serial.println(F("Connecting to HTTPS Server"));
  // Serial.println(F("Waiting 30s to make sure it works..."));
  Serial_command(auxStr, 30000);
  // delay(30000); //wait for response
  //  Softsee_read(); // check for ok replay
  //delay(30000); //wait for response
  //Softsee_read(); // check for ok replay

  delay(500); //buffer

  //Serial.println(strlen(URL));
  //  Serial.println(strlen(body));


  // Send data to server
  sprintf(auxStr, "AT+CHTTPSSEND=%i\r", strlen(URL)  + strlen(body)); // URL and body must include \r\n as needed
  Serial_command(auxStr, 1000); // check for ">" replay

  delay(500); //buffer

  if (strlen(body) == 0) {

    //For GET requests
    mySerial.print(URL);
    delay(10000);
    Softsee_read();// check for ok replay
    Serial_tildeprint("GET request");
  }
  else {
    //For POST requests
    mySerial.print(URL);
    delay(10000);
    Softsee_read();

    mySerial.print(body);
    delay(10000);
    Softsee_read();// check for ok replay
    Serial_tildeprint("POST request");
  }
  /*
    Serial_command(URL,10000);// check for ok replay


  */
  delay(1000);

  Serial_command("AT+CHTTPSSEND\r", 10000); // check for ok,"+CHTTPSSEND: 0" replay


  delay(1000); //buffer



  // Check server response length

  Serial_command("AT+CHTTPSRECV?\r", 10000);

}


/*GPRS enable */
boolean HiveenableGPRS(boolean onoff) {



  // char auxStr[400];
  char apn[50] = "myt";

  if (onoff) {
    Serial_tildeprint("Turning on GPRS");
    // disconnect all sockets
    //sendCheckReply(F("AT+CIPSHUT"), F("SHUT OK"), 5000);
    delay(500); //buffer

    Serial_command("AT+CGATT=1\r", 10000); // check for "ok" replay
    delay(500); //buffer

    // set bearer profile access point name
    if (apn) {
      //Serial.println(apn);
      // Send command AT+CGSOCKCONT=1,"IP","<apn value>" where <apn value> is the configured APN name.
      sprintf(auxStr, "AT+CGSOCKCONT=1,\"IP\",\"%s\"\r", apn);
      Serial_command(auxStr, 10000); // check for "ok" replay


      // set username/password

    }

    // connect in transparent mode
    Serial_command("AT+CIPMODE=1\r", 10000); // check for "ok" replay

    delay(5000);
    // open network (?)
    Serial_command("AT+NETOPEN=,,1\r", 10000); // check for "ok","Network opened" replay
    /*
        Serial_command("AT+NETOPEN=,,1\r", 5000);
      delay(1000);
        Serial_astprint("AT+CHTTPSSTART\r");
    */
  }

  else {
    Serial_tildeprint("Turning off GPRS");
    // close GPRS context
    Serial_command("AT+CHTTPSCLSE\r", 10000); // check for "ok", reply
    Serial_command("AT+CHTTPSSTOP\r", 10000); // check for "ok","+CHTTPSSTOP: 0" reply
    Serial_command("AT+NETCLOSE\r", 10000); // check for "ok","Network closed" reply





    // if (! sendCheckReply(F("AT+NETCLOSE"), ok_reply, 10000))
    //   return false;
    //    if (! sendCheckReply(F("AT+CHTTPSSTOP"), F("+CHTTPSSTOP: 0"), 10000))
    //  return false;
    // if (! sendCheckReply(F("AT+CHTTPSCLSE"), ok_reply, 10000))
    //  return false;

  }
  return true;
}

/*Serial Read and write*/
void Serial_tildeprint(String txt) { //prints to serial monitor alone
  Serial.print("~");
  Serial.print(txt);
  Serial.println("~");

}


void Serial_astprint(String txt) { //prints to software serial and indicates on serial monitor

  Serial.println();
  Serial.println();

  //Palette cleanser just in case of proceeding error
  mySerial.println("AT");
  delay(30); //wait for response else error in printout
  while (mySerial.available())
  {
    Serial.write(mySerial.read());
  }
  mySerial.println("AT");
  delay(30); //wait for response else error in printout
  while (mySerial.available())
  {
    Serial.write(mySerial.read());
  }

  delay(30); //buffer
  Serial.print("*");
  Serial.print(txt);
  Serial.println("*");
  mySerial.print(txt);
}

void Softsee_read() {

  while (mySerial.available())
  {
    Serial.write(mySerial.read());
  }
}


void Serial_command(String txt, int dur) {
  //input command string as arg 1(end with \r(not /r)),
  //wait duration in milliseconds before checking for response as arg 2 (>= 100, bare minimum = 20ms)

  Serial_astprint(txt);
  Serial.print("Waiting ");
  int sec = dur / 1000;
  Serial.print(sec);
  Serial.println("secs for a response");
  delay(dur);
  Softsee_read();

  //failsafe incase of readout happens too early
  delay(500);
  if (mySerial.available()) {
    Softsee_read();
  }
}
