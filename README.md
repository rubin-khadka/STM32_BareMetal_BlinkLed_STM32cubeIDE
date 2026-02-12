# STM32 BareMetal BlinkLed STM32cubeIDE

![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)
![STM32](https://img.shields.io/badge/STM32-F103C8T6-blue)
![CubeIDE](https://img.shields.io/badge/IDE-STM32CubeIDE-green)
![Bare Metal](https://img.shields.io/badge/Level-Register--Only-red)

## Project Overview

This project demonstrates **complete bare-metal programming** on the STM32F103C8 "Blue Pill" without using HAL, LL, or CubeMX. It configures the system clock to **72MHz** from the 8MHz HSE crystal and PLL and blinks the onboard LED on PC13.

## Features

| Feature | Description |
|---------|-------------|
| **72MHz System Clock** | HSE 8MHz × 9 PLL multiplication | 
| **Flash Configuration** | 2 wait states for 72MHz operation | 
| **APB1 Prescaler** | 72MHz/2 = 36MHz | 
| **LED Control** | PC13 push-pull output, active low | 

## Video Demonstration

## Key Registers Configured

| Register | Setting | Purpose |
|----------|---------|---------|
| `RCC->CR` | `HSEON`, `PLLON` | Enable HSE crystal and PLL |
| `RCC->CFGR` | `PLLMULL9`, `PLLSRC`, `PPRE1_DIV2` | 72MHz clock, APB1 = 36MHz |
| `FLASH->ACR` | `LATENCY_2` | 2 wait states for 72MHz |
| `GPIOC->CRH` | `MODE13_0` | PC13 as output 10MHz, push-pull |
| `GPIOC->BSRR` | `BS13`, `BR13` | Atomic LED control |

[View complete clock configuration code](https://github.com/rubin-khadka/STM32_BareMetal_BlinkLed_STM32cubeIDE/blob/main/Src/system_stm32f1xx.c)<br>
[View GPIO initialisation and control code](https://github.com/rubin-khadka/STM32_BareMetal_BlinkLed_STM32cubeIDE/blob/main/Src/gpio.c)<br>
[View main application code](https://github.com/rubin-khadka/STM32_BareMetal_BlinkLed_STM32cubeIDE/blob/main/Src/main.c)

## Hardware Requirements

| Components | Details |
|------|---------|
| **MCU** | STM32F103C8T6 "Blue Pill" |
| **Crystal** | 8MHz HSE (onboard) |
| **LED** | PC13 (onboard, active LOW) |
| **Programmer** | ST-Link V2 |

## Getting Started

### Prerequisites
- STM32CubeIDE v1.13.0+
- ST-Link V2 programmer
- STM32F103C8 "Blue Pill" board

### Installation

1. Clone the repository
```bash
git clone https://github.com/rubin-khadka/STM32_BareMetal_BlinkLed_STM32cubeIDE.git
```
2. Open in STM32CubeIDE

- `File` → `Open Projects from File System...`
- Select the project directory
- Click `Finish`    

3. Verify Project Settings
- `Project` → `Properties` → `C/C++ Build` → `Settings`
- `MCU GCC Compiler` → `Preprocessor`
- Ensure `STM32F103xB` is defined

4. Build & Flash
- Build: `Ctrl+B`
- Debug: `F11`
- Run: `F8` (Resume)

### Expected Behavior
- LED ON: 500ms
- LED OFF: 500ms
- Cycle: 1 second total
- Frequency: 1 Hz

**LED blinks at 1Hz = 72MHz configured correctly**

## Future Improvements
- **SysTick Timer** - Precise millisecond delays
- **MCO Output** - Measure actual clock on PA8
- **UART Debug** - Print clock speed
- **Power Optimization** - Disable HSI after PLL lock
- **Keil Version** - Same project in uVision5

## Resources
- [STM32F103 Datasheet](https://www.st.com/resource/en/datasheet/stm32f103c8.pdf)
- [STM32F103 Reference Manual](https://www.st.com/resource/en/reference_manual/rm0008-stm32f101xx-stm32f102xx-stm32f103xx-stm32f105xx-and-stm32f107xx-advanced-armbased-32bit-mcus-stmicroelectronics.pdf)

## Project Status
- **Status**: Complete
- **Version**: v1.0
- **Last Updated**: February 2026

## Contact
**Rubin Khadka Chhetri**  
📧 rubin.robotic@gmail.com  
🐙 GitHub: https://github.com/rubin-khadka



