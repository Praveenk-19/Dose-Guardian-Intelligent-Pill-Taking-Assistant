# 📦 DoseGuardian — Intelligent Pill-Taking Assistant

**DoseGuardian** is an embedded systems-based intelligent medication reminder designed to ensure timely medicine intake and improve patient health management.  
Built on an ARM7 microcontroller (LPC2148), this system integrates a real-time clock, LCD display, keypad interface, LED indicators, and buzzer alerts for accurate medicine scheduling and user interaction. :contentReference[oaicite:0]{index=0}

---

## 🚀 🧠 Motivation

Missing or delaying prescribed doses is a common issue, especially for elderly patients, people with chronic illnesses, and busy individuals.  
Medication non-adherence can lead to:
- Reduced treatment effectiveness
- Worsening health conditions
- Increased caregiver stress
- Hospital readmissions and complications

DoseGuardian addresses this challenge **with a user-friendly, real-time embedded solution** that reminds users to take medicines at the right time. :contentReference[oaicite:1]{index=1}

---

## 🛠️ Key Features

✔ **Real-Time Scheduling**  
Reminds users when it’s time to take their medicine using an onboard Real-Time Clock (RTC). :contentReference[oaicite:2]{index=2}

✔ **Intuitive LCD Interface**  
Displays current time, medicine schedules, alerts, and configuration menus. :contentReference[oaicite:3]{index=3}

✔ **User Input via Keypad**  
Configure current time and medicine times easily. :contentReference[oaicite:4]{index=4}

✔ **Alert System**  
When it’s time to take medicine:
- Buzzer alarm sounds
- LED blinks
- LCD displays notification :contentReference[oaicite:5]{index=5}

✔ **Missed Dose Detection**  
Tracks if the user didn’t confirm intake and indicates missed doses. :contentReference[oaicite:6]{index=6}

✔ **Modular Embedded C Implementation**  
Clean code organization with source and header files that make future enhancements easier. :contentReference[oaicite:7]{index=7}

---

---

## 📸 Simulation Results (Proteus Verification)

The complete system was designed and validated using **Proteus Design Suite** to ensure correct functionality before hardware deployment.  
The simulation verifies RTC timing accuracy, user input handling, and medicine alert triggering.

### 🖥️ 1️⃣ System Initialization & RTC Display
The system initializes the Real-Time Clock and continuously displays the current time on the 16×2 LCD.

![RTC Display](docs/images/proteus_rtc_display.png)

**Verified:**
- RTC time increment accuracy  
- LCD data communication  
- Proper initialization sequence  

---

### 💊 2️⃣ Medicine Time Configuration
Users can configure medicine reminder timings using the 4×4 matrix keypad interface.

![Medicine Configuration](docs/images/proteus_medicine_config.png)

**Verified:**
- Keypad scanning logic  
- Time input validation  
- LCD menu navigation  

---

### 🔔 3️⃣ Medicine Alert Trigger
When the RTC time matches the scheduled medicine time:
- Buzzer activates  
- LED indicator blinks  
- LCD displays reminder notification  

![Medicine Alert](docs/images/proteus_medicine_alert.png)

**Verified:**
- Time comparison algorithm  
- Alert triggering mechanism  
- User confirmation workflow  

---

### ⚙️ 4️⃣ Complete Circuit Simulation
Full Proteus schematic showing microcontroller, LCD, keypad, RTC module, buzzer, and LED connections.

![Complete Simulation](docs/images/proteus_full_simulation.png)

**Verified:**
- Pin configuration correctness  
- Peripheral interfacing  
- System-level integration  

---

### ✅ Simulation Outcome

✔ Accurate RTC synchronization  
✔ Reliable user input handling  
✔ Real-time medicine alert generation  
✔ Successful system-level validation before hardware implementation  

---
---

## 🧪 How It Works (User Flow)

1. **Power On & Initialize**  
   System initializes RTC and LCD. :contentReference[oaicite:8]{index=8}

2. **Set Current Time**  
   Navigate using keypad to update the RTC time. :contentReference[oaicite:9]{index=9}

3. **Configure Medicine Time**  
   Enter medicine reminders (hours/minutes). :contentReference[oaicite:10]{index=10}

4. **Reminder & Alerts**  
   When the current time matches the medicine time:  
   - Buzzer sounds  
   - LED blinks  
   - LCD displays alert :contentReference[oaicite:11]{index=11}

5. **User Confirmation**  
   User confirms intake using the keypad. :contentReference[oaicite:12]{index=12}

---

## 📦 Hardware Components Used

| Component | Role |
|-----------|------|
| **LPC2148 ARM7 Microcontroller** | Main processing unit |
| **16×2 LCD Display (LM016L)** | Visual interface |
| **4×4 Matrix Keypad** | Input device |
| **Real-Time Clock (RTC)** | Timekeeping |
| **Buzzer** | Audio alert |
| **LED Indicator** | Visual alert |
| **Pull-up Resistors & Power Supply** | Circuit support | :contentReference[oaicite:13]{index=13}

---

## 📈 Benefits & Impact

- Helps elderly and memory-challenged individuals follow medication schedules
- Improves treatment outcomes
- Reduces dependency on caregivers for medicine reminders
- Demonstrates practical embedded system design skills

---

## 🌱 Future Improvements

- **GSM / IoT Notifications** — send reminders via SMS or mobile app
- **Multiple Medicine Scheduling**
- **EEPROM Storage for Persistent Settings**
- **Voice Alerts or Mobile Integration**

---

## 🛠️ How To Build & Run

1. Clone the repository  
2. Open firmware in your preferred IDE/toolchain (e.g., Keil uVision)
3. Compile and generate the hex
4. Load the hex onto LPC2148 using programmer
5. Connect hardware and test

*(Detailed instructions can be added to `docs/Installation.md`)*

---

## 💡 Credits

*Developed by:* **Korada Praveen Kumar**  
Electronics and Communication Engineer 📡  
(*Contact or portfolio links can be added here*) :contentReference[oaicite:14]{index=14}

---

## 📄 License

This project is developed for **educational and demonstration purposes**.

---
