#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "xxxxx";
const char* password = "xxxxx";

WebServer server(80);

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
  <title>ESP32 Pin Status</title>
</head>
<body>
  <h1>ESP32 Pin Status</h1>
  <canvas id="pinChart" width="400" height="400"></canvas>
  <script>
    var ctx = document.getElementById('pinChart').getContext('2d');
    var pinChart = new Chart(ctx, {
      type: 'line',
      data: {
        labels: [], // X axis labels
        datasets: [{
          label: 'Pin Value',
          data: [], // Your data
          backgroundColor: 'rgba(255, 99, 132, 0.2)',
          borderColor: 'rgba(255, 99, 132, 1)',
          borderWidth: 1
        }]
      },
      options: {
        scales: {
          y: {
            beginAtZero: true
          }
        }
      }
    });
    const getData = () => {
      fetch("/pin-status")
        .then(response => response.json())
        .then(data => {
          pinChart.data.labels.push(data.time);
          pinChart.data.datasets.forEach((dataset) => {
            dataset.data.push(data.value);
          });
          pinChart.update();
        });
    };
    setInterval(getData, 2000); // Update every 2000 milliseconds
  </script>
</body>
</html>
)rawliteral";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  server.on("/", HTTP_GET, []() {
    server.send(200, "text/html", index_html);
  });

  server.on("/pin-status", HTTP_GET, []() {
    int pinValue = digitalRead(2); // Exemplo de leitura do pino GPIO 2
    String json = "{\"time\":\"" + String(millis()) + "\",\"value\":" + String(pinValue) + "}";
    server.send(200, "application/json", json);
  });

  server.begin();
}

void loop() {
  server.handleClient();
}
