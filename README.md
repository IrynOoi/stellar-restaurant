#STELLAR RESTAURANT SYSTEM
## 📌 Overview
The **Cashierless Food Ordering System** is a C++ console-based application designed to modernize traditional restaurant ordering. It replaces manual ordering with a self-service flow, reducing wait times, minimizing human errors, and improving billing accuracy.

---

## 🎯 Objectives
- Eliminate manual ordering inefficiencies
- Provide a self-service ordering experience
- Ensure accurate billing and receipt generation
- Simulate a real-world cashierless system

---

## ⚙️ Features
- 🍴 Choose order type:
  - Dine-in
  - Takeaway
- 📋 Menu categories:
  - Western Food
  - Local Food
  - Drinks
- 🛒 Cart system with total calculation
- 💳 Payment method selection
- 🧾 Receipt generation (`Receipt.txt`)
- ✅ Input validation for invalid user entries

---

## 🧠 Implementation Details

### 📊 Data Structures
- `struct FoodItem` → Stores food details  
- `struct DrinkItem` → Stores drink details  
- `struct Receipt` → Stores order summary  

### 🔧 Core Functions
- `WesternFoodOrdering()` → Handles western menu orders  
- `LocalFoodOrdering()` → Handles local menu orders  
- `Drink()` → Handles drink selection  
- `DisplayCart()` → Shows selected items and total  
- `Payment()` → Processes payment method  
- `DisplayReceipt()` → Outputs receipt  

---

## 💰 Pricing Logic
- Calculates total based on selected items
- Adds **RM0.20 surcharge** for takeaway orders


# STELLAR RESTAURANT

## Main Menu
<img width="623" height="704" alt="image" src="https://github.com/user-attachments/assets/3c7e1f5b-5b45-4952-a0c1-988d426a3626" />


<br><br>

## Output of cart

<img width="627" height="679" alt="image" src="https://github.com/user-attachments/assets/7d5df73d-de71-4d06-8131-e08ee5896c97" />

<br><br>

## Output of receipt

<img width="547" height="210" alt="image" src="https://github.com/user-attachments/assets/92bb1423-e51d-4e5a-89a3-4a0a4f7899b9" />


<br><br>

<img width="630" height="430" alt="image" src="https://github.com/user-attachments/assets/8e218956-88bd-4ede-8567-e56a3e01bc24" />

## Output of checkout

<img width="564" height="727" alt="image" src="https://github.com/user-attachments/assets/3508781b-a64f-4218-a9af-1d430f97e2a0" />

