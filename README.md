# 💊 DoseGuardian – Intelligent Pill-Taking Assistant

An Embedded Systems project designed to remind patients to take medicine on time using RTC, LCD Display, Keypad Interface, LED indication, and Buzzer alert.

---

## 📌 Project Overview

DoseGuardian is a real-time medicine reminder system built using **LPC2148 ARM7 Microcontroller**.  
It allows users to:

- Set current RTC time
- Configure medicine intake time
- Receive alerts at scheduled time
- Confirm medicine intake
- Detect missed doses

This system improves medication adherence using an interactive embedded interface.

---

## 🛠️ Hardware Components

- LPC2148 ARM7 Microcontroller
- 16x2 LCD (LM016L)
- 4x4 Matrix Keypad
- RTC (Internal)
- Buzzer
- LED Indicator
- Pull-up Resistors
- Power Supply

---

## 🖥️ System Architecture

![Complete Circuit Diagram](images/system_overview.png)

---

## 📸 Working Screens & Functional Flow

---

### 🕒 1️⃣ RTC Display (Current Time & Date)

The system continuously displays real-time clock data.

![RTC Display](images/rtc_display.png)

---

### ⚙️ 2️⃣ Main Menu

User can select:
- Edit RTC
- Edit Medicine Time
- Exit

![Main Menu](images/main_menu.png)

---

### ⏰ 3️⃣ Edit RTC Menu

User selects:
- Hours
- Minutes
- Seconds

![RTC Edit Menu](images/rtc_edit.png)

---

### 💾 4️⃣ RTC Time Saved Confirmation

After updating time, confirmation is displayed.

![RTC Saved](images/rtc_saved.png)

---

### 💊 5️⃣ Medicine Time Saved

After configuring medicine time.

![Medicine Time Saved](images/med_time_saved.png)

---

### 🔔 6️⃣ Medicine Alert

When medicine time matches RTC time:

- Buzzer activates
- LED blinks
- LCD shows alert

![Take Medicine Alert](images/take_medicine.png)

---

### ❌ 7️⃣ Missed Dose Detection

If user does not confirm within predefined time:

![Missed Dose](images/missed_dose.png)

---

### ✅ 8️⃣ Medicine Intake Confirmation

After user confirmation:

![Medicine Completed](images/medicine_completed.png)

---

## 🔄 System Workflow

1. System initializes RTC and LCD
2. User sets RTC time
3. User sets Medicine Time
4. RTC runs continuously
5. When RTC == Medicine Time:
   - Buzzer ON
   - LED ON
   - LCD Alert Displayed
6. User confirms intake
7. If no confirmation → Missed Dose alert

---

## 💡 Key Features

✔ Real-Time Clock Integration  
✔ User-Friendly LCD Interface  
✔ Missed Dose Detection  
✔ Alert System (LED + Buzzer)  
✔ Interactive Keypad Navigation  
✔ Embedded C Implementation  

---

## 🧠 Embedded Concepts Used

- GPIO Configuration
- LCD Interfacing (8-bit Mode)
- Matrix Keypad Scanning
- RTC Configuration
- Interrupt Handling
- Delay Routines
- State Machine Logic

---

## 🚀 Applications

- Elderly Patient Care
- Hospital Monitoring Systems
- Smart Home Healthcare
- Personal Medicine Reminder Device

---

## 🎯 Future Improvements

- GSM Notification System
- IoT Integration
- Mobile App Synchronization
- Multiple Medicine Scheduling
- EEPROM Storage

---

## 👨‍💻 Developed By

**Korada Praveen Kumar**  
Electronics and Communication Engineer  

---

## 📜 License

This project is developed for educational and demonstration purposes.
