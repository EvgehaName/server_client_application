[screenshot_client_app]: images/main_app_client.png
[screenshot_server_app_readyConfig]: images/server_app_and_client_readyConfig.png
[screenshot_send_to_data_server]: images/send_to_data_server.png
[screenshot_disconnection_client]: images/disconnection_client.png
[screenshot_config_client]: images/config_client_app.png
[screenshot_config_server]: images/config_server_app.png

## About the project

This project is a pet project! It was designed to explore and understand the QTcpServer and QTcpSocket objects. This project contains two programs (Server and Client) that communicate with each other via QTcpSocket.

**Project objectives:**

* Learning and understanding the QTcpServer and QTcpSocket objects;
* Working with configuration files using the QSettings object;
* Connecting and using external custom widgets;
* Working with QT resources;
* Practical application of QT and C++.

## An example of how a software product works

1. The main window of the client side for logging into the control of the radar system
[![Main Screen Shot Client App][screenshot_client_app]]

2. The main menu is to control the radar system (after connecting). After connection, the server sends data to the client to receive data from the radar system.
[![Main Control Screen Shot Client App][screenshot_server_app_readyConfig]]

3. Demonstration of sending data from the client to the server
[![Demonstration Send To Data Server][screenshot_send_to_data_server]]

4. Demonstration disconnecting the client from the server
[![Demonstration Disconnection Client Server][screenshot_disconnection_client]]

5. Client configuration file
[![Configuration file client][screenshot_config_client]]

6. Server configuration file
[![Configuration file server][screenshot_config_server]]

## Project build

**To compile the project, the installed QT components are required.** 
It will be possible to compile the project on all systems where QT is supported, but the compilation example (which is presented below) will take place on the Linux operating system.

Compilations:
1. Clone the project from the repository
```sh
   git clone https://github.com/EvgehaName/server_client_application.git
   ```
2. Go to the root of each software and compile the project using the make utility.
```sh
   make
   ```
If there is no makefile, configure the makefile using qmake (the project uses QT 5.15)
**An example is provided from the Fedora distribution:**
```sh
   qmake-qt5
   ```
**The qmake call may differ depending on which distribution is being compiled on.**

After successful compilation, you can run the executable file.
**Attention! You should start the Server using the terminal.**
