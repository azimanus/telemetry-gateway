# Embedded Linux Telemetry Gateway

A Linux based telemetry and monitoring gateway written in C.

## Overview

This project collects real-time system information from Linux kernel interfaces such as `/proc` and `/sys`, then formats and publishes telemetry data.

The goal of the project is to practice Embedded Linux system programming concepts including:

- Linux system monitoring
- `/proc` filesystem parsing
- Modular C architecture
- Makefile-based builds
- Telemetry collection
- Background service design

---

## Current Features

- Read system uptime from `/proc/uptime`
- Read memory usage from `/proc/meminfo`
- Modular source/header structure
- Makefile based build system

---

## Project Structure

telemetry-gateway/
├── src/
├── include/
├── build/
├── config/
├── logs/
├── Makefile
└── README.md