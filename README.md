# 🤖 Maze Solving Robot

An autonomous robot built using Arduino and ultrasonic sensors to detect walls and solve a maze in real-time. Developed for a college-level robotics competition.


---

## 📽️ Demo

Watch the robot solve a Level 1 maze:
[![Watch on YouTube](https://youtube.com/shorts/zVQJwBg-Mak?feature=share)

---

## 🔧 Features

- Detects front, left, and right obstacles using 3 ultrasonic sensors
- Navigates by decision-making logic based on distance thresholds
- Can move forward, turn left/right, or go back
- Fully autonomous after power-up

---

## 💡 Technologies Used

- Arduino UNO
- HC-SR04 Ultrasonic Sensors × 3
- L298N Motor Driver
- 2 DC Motors
- 12V Battery
- Embedded C (Arduino)

---

## 📁 Project Structure

Arduino_Code/ └── maze_solver.ino Images/ └── robot_photo.jpg Videos/ └── maze_level1_demo.mp4


---

## 👨‍💻 Team

- **Mutyala Pramod Abhiram** (238T1A05B2) — Team Lead, Coder
- **G Achyuth** 
- **Nutakki Ashok Gowtham** (238T1A05C3)
- **Paidipati Naga Sumanth** (238T1A05C5)


---

## 🧠 Logic Summary

If left is open → turn left  
Else if front is open → move forward  
Else if right is open → turn right  
Else → turn back

---

## 📜 License

This project is licensed under the [MIT License](LICENSE).

---

