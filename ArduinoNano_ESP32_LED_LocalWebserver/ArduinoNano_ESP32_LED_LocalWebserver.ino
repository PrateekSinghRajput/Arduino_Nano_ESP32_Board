

#include <WiFi.h>

// WiFi credentials
const char* ssid = "Prateek";
const char* password = "justdoelectronics@#12345";

// Built-in LED pin
const int ledPin = 13; // D13 - GPIO48

WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (!client) return;

  String request = client.readStringUntil('\r');
  client.flush();

  // Control LED based on URL
  if (request.indexOf("/LED=ON") != -1) digitalWrite(ledPin, HIGH);
  if (request.indexOf("/LED=OFF") != -1) digitalWrite(ledPin, LOW);

  bool ledState = digitalRead(ledPin);

  // Build HTML page with inline CSS for styling
  String html = R"rawliteral(
    <!DOCTYPE html>
    <html>
    <head>
      <title>ESP32 LED Control</title>
      <style>
        body {
          font-family: Arial, sans-serif;
          background: #f4f4f9;
          text-align: center;
          padding: 30px;
        }
        h2 {
          color: #333;
        }
        .led-status {
          margin: 20px auto;
          width: 60px;
          height: 60px;
          border-radius: 50%;
          background-color: )rawliteral";

  html += (ledState ? "#28a745" : "#dc3545"); // green if ON, red if OFF

  html += R"rawliteral(;
          box-shadow: 0 0 20px )rawliteral";

  html += (ledState ? "#28a745" : "#dc3545");

  html += R"rawliteral(;
          margin-bottom: 20px;
        }
        .btn {
          display: inline-block;
          padding: 15px 30px;
          font-size: 18px;
          margin: 10px;
          border: none;
          border-radius: 8px;
          cursor: pointer;
          color: white;
          transition: background-color 0.3s ease;
          text-decoration: none;
        }
        .btn-on {
          background-color: #28a745;
        }
        .btn-on:hover {
          background-color: #218838;
        }
        .btn-off {
          background-color: #dc3545;
        }
        .btn-off:hover {
          background-color: #c82333;
        }
      </style>
    </head>
    <body>
      <h2>Arduino Nano ESP32 LED Control</h2>
      <div class="led-status"></div>
      <p>LED is currently <strong>)rawliteral";

  html += (ledState ? "ON" : "OFF");

  html += R"rawliteral(</strong></p>
      <a href="/LED=ON" class="btn btn-on">Turn LED ON</a>
      <a href="/LED=OFF" class="btn btn-off">Turn LED OFF</a>
    </body>
    </html>
  )rawliteral";

  client.println("HTTP/1.1 200 OK");
  client.println("Content-type:text/html");
  client.println();
  client.print(html);
  client.println();
  delay(1);
  client.stop();
}

