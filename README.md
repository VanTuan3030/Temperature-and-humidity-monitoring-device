# Temperature-and-humidity-monitoring-device
Smart Temperature, Humidity Monitoring &amp; Fan Control System via Blynk IoT Description: IoT project uses ESP8266 and DHT11 sensor to monitor real-time environment, automatically control cooling fan and send alerts to phone via Blynk platform.
# IoT Smart Fan Control System (ESP8266 + Blynk)

This IoT project implements real-time monitoring of environmental temperature and humidity, along with an automatic ventilation fan control system using the ESP8266 microcontroller and the new generation Blynk IoT platform.

## 🚀 Key Features

* **Real-time Monitoring:** Continuously reads and displays Temperature & Humidity data on the Blynk app.
* **Automatic Mode (Auto):** The system automatically activates the fan (Relay) when the temperature exceeds the set threshold (**> 33°C**).
* **Manual Control:** Allows users to manually turn the fan ON/OFF remotely via a button on the mobile app.
* **Alert System:** Sends a Push Notification ("CANH_BAO_NHIET_DO") to the phone when the temperature gets too high.
* **Status Indicator:** Blinking LED indicates the device is operating and has a stable connection.

## 🛠️ Hardware Requirements

* **Microcontroller:** ESP8266 (NodeMCU or Wemos D1 Mini).
* **Sensor:** DHT11 (Temperature and Humidity Sensor).
* **Control Module:** 5V Relay Module (High/Low trigger).
* **Actuator:** Cooling Fan (DC/AC).
* **Others:** Jumper wires, Breadboard, Power supply (5V micro USB).

## 🔌 Wiring Diagram (Pinout)

| Device | ESP8266 Pin (GPIO) | NodeMCU Pin | Notes |
| :--- | :--- | :--- | :--- |
| **DHT11 Data** | GPIO 16 | D0 | Temp/Hum Sensor |
| **Relay Signal** | GPIO 4 | D2 | Fan Control |
| **LED Connect** | GPIO 16 (Built-in) | V0 (Virtual) | Status LED on App |



[Image of ESP8266 DHT11 Relay wiring schematic]


## 📱 Blynk App Configuration (Datastreams)

Create a Template in the Blynk Console with the following Datastreams:

| Name | Virtual Pin | Data Type | Units | Function |
| :--- | :---: | :---: | :---: | :--- |
| **Temperature** | V1 | Double | °C | Display Temperature |
| **Humidity** | V2 | Double | % | Display Humidity |
| **Fan Control** | V3 | Integer | 0/1 | Button (Switch) |
| **LED Status** | V0 | Integer | 0/1 | Connection Status LED |

## 💻 Installation and Usage

1.  **Install Arduino Libraries:**
    * `ESP8266WiFi`
    * `BlynkSimpleEsp8266`
    * `DHTesp` (by BeeGee)

2.  **Configure Code:**
    * Open the `.ino` file.
    * Update WiFi credentials (`ssid`, `pass`).
    * Update Blynk credentials (`BLYNK_TEMPLATE_ID`, `BLYNK_TEMPLATE_NAME`, `BLYNK_AUTH_TOKEN`).

3.  **Upload Program:**
    * Connect the ESP8266 to your computer.
    * Select the correct COM Port and Board (NodeMCU 1.0).
    * Upload the code.

## 👤 Author

* **Student:** Vo Van Tuan
* **Student ID:** 6251020094
* **Class:** CQ.62.KTDTVT
* **University:** University of Transport and Communications - HCMC Campus - UTC2

---
*Project for the course: IoT and Applications Final Report.*
