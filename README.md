# 💧 ESP32 Low-Power Water Usage Logger (v4.1.4)

Low-power multi-sensor water usage logger built for **XIAO ESP32-C3 (RISC-V)** with deep sleep wake-up, web interface, file management, configurable datalogging and advanced button post-correction logic.

---

## 📌 Project Overview

**Project:** ESP32 Low-Power Water Usage Logger  
**Version:** 4.1.4  
**Target Board:** Seeed Studio XIAO ESP32-C3  
**Author:** Petko Georgiev  
**Organization:** Villeroy & Boch Bulgaria  
**Location:** Sevlievo, Bulgaria  

This firmware is designed to:

- Log water usage via flow sensor
- Detect flush plate buttons (PF / FF)
- Operate in ultra low-power deep sleep mode
- Provide web-based configuration and monitoring
- Support LittleFS or SD storage
- Automatically correct misidentified flush events using volume logic

---

## ⚙️ Core Features

### 🔋 Low Power Operation
- Deep sleep using GPIO wake-up
- Automatic sleep after inactivity
- Optimized boot sequence for fast button detection (<1ms snapshot)

### 🚽 Multi-Button Detection
- Supports:
  - PF (Partial Flush)
  - FF (Full Flush)
- Configurable debounce (20–500ms)
- Edge detection to prevent multiple counts
- Early GPIO snapshot to avoid misidentification

### 🧠 Post-Correction Logic (v4.1.4+)
Volume-based correction of button identification:

- PF with volume ≥ threshold → corrected to FF
- FF with volume ≤ threshold → corrected to PF
- Configurable thresholds:
  - `pfToFfThreshold`
  - `ffToPfThreshold`
- Manual press detection:
  - If button held longer than `manualPressThresholdMs` (default 500ms), correction is skipped

Post-correction events are logged to:
