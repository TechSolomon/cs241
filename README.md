# cs241
Arduino projects from the Spring 2021 semester at UAF.

# Problem Solving
During this project, I set out to solve the problem of wildlife interactions with humans in Alaska. One common problem without outdoor trash cans (especially roll carts) is that they can easily get knocked over or tampered with when left outside for long durations. Numerous issues arise for moose, coyotes, bears, and other animals as habitat changes can adjust their behavior through interactions with people in the surrounding areas.

My initial minimum viable product (MVP) for this project was to build a “smart” outdoor trash can/roll cart latching mechanism that watches for changes in angle/location and alerts the owner about any intruders since the last visit. After further discussions and iterations, one issue that would arise is with the power supply; in some instances, this makes sense to use a battery, but in others, it makes more sense to plug it in. Ideally, the system should dock to a power supply; however, a “knocked over alarm” or latch would be sufficient for an MVP.

![bear-aware-lock](https://user-images.githubusercontent.com/7608183/116511179-840b4000-a872-11eb-8bb5-9e6b8697b36c.JPG)

# Technical Approach
Some supplies that I needed include an Arduino Uno/Nano, a Passive Infrared Sensor (PIR) to connect with an accelerometer to report changes in angle, a mini breadboard, and a servo motor to send lock and unlock commands. Stretch goals for this project included logging location changes through mapping and data visualization, in addition to a do not disturb mode to bypass the active alert system during user-specified dates and times.

For the initial project prototype, I decided to go with an Arduino Uno, a mini solderless breadboard (4x4 points), a standard servo (TowerPro SG-5010), a water sensor, and the RGB LED (K851264) from the lab kit. In the future, the servo should upgrade to a more powerful locking mechanism. Upon taking the dimensions of a traditional roll cart, I decided that a large pizza box design would be a good substitute for the lid; adding more size constraints yielded a much smaller, “customized” Adafruit cardboard box to house the electronics.

<img width="954" alt="bear-aware-ui" src="https://user-images.githubusercontent.com/7608183/116511168-7fdf2280-a872-11eb-802f-4ab3d6773caf.png">

# Project Code & Physical Design
For the physical aspects of my design, everything fits inside the Adafruit box with two mini breadboards tying everything together. Black wires signify ground (three-pin connections total), red is for power (5V), and the other wires match their respective breakout for carrying data.

Upon taking a look at my project code, all features encapsulate the instructions function. The program header describes the servo, water sensor, and RGB LED pin utilization to mirror my wiring setup. The locking and unlocking commands control the servo motor through their respective functions, while getWaterLevel (looping function) and showColor (table-driven programming) run repeatedly to send and receive the most accurate end-user information.

![bear-aware-wires](https://user-images.githubusercontent.com/7608183/116511136-75bd2400-a872-11eb-9827-3f4ccf7bc082.JPG)

# Conclusion
Lessons learned with this project included scope creep, time management, reading documentation, and ordering researched parts. My favorite aspect would have to be taking what we learned in the lab and experimenting with the interactions between multiple components.

For future improvements, I hope to conduct additional outdoor weather testing to explore the limitations of water and sub-zero temperatures. In addition to including an accelerometer & magnetometer (only need a STEMMA QT / Quiic JST SH 4-pin connection cable), an independent power supply (with solar power or rechargeable batteries), and IFTTT/Twilio SMS integration as the next iteration in the Bear Aware Smart Latch system.
