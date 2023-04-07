![Banner](https://github.com/BojanG72/STM32-Ceedling-Base/blob/main/banner.png)

# STM32 & Ceedling Base Project

![GitHub](https://img.shields.io/github/last-commit/bojang72/stm32-ceedling-base)
![GitHub](https://img.shields.io/github/license/bojang72/STM32-Ceedling-Base)

I created this project as a starting point for anyone looking to create production quality firmware for an embedded system running an STM32
microcontroller. This project makes use of the [ceedling](http://www.throwtheswitch.org/ceedling) build system. I chose to centre this project
around ceedling, because for software to be production quality it must contain unit tests. I found ceedling to be the easiest build system 
that incorporates unit testing for firmware development.

This project is currently setup to compile for the STM32L496AG MCU, becuase I happen to have a dev kit with that processor. I included both the CMSIS, and
HAL libraries for the MCU. If you would like to compile for a different MCU, you would need to replace the libraries in the lib folder as well as the startup code and linker script. The startup file and linker script is located in the startup folder.

The ceedling project.yml file has been setup to compile for a cortex M4 processor when the release command is run, and will compile with whatever the default GCC compiler is
installed on your host machine when the test command is run. 

# Table of contents

- [Project Title](#project-title)
- [Table of contents](#table-of-contents)
- [Installation](#installation)
- [Usage](#usage)
- [License](#license)
- [Footer](#footer)

# Installation
[(Back to top)](#table-of-contents)

This project has a couple dependencies that are required before you can build and run the tests.
1) The Ceedling build system                ---> [Here](http://www.throwtheswitch.org/ceedling)
2) GCC compiler for your host machine       ---> [Here](https://gcc.gnu.org/install/binaries.html)
3) GCC compiler for your target             ---> [Here](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads)

Make sure you install the correct toolchain for your setup. The toolchains will vary depending on if your host machine is running linux or windows. The target compiler I listed here is for ARM MCUs, if your MCU is not ARM based then you will need to find the correct compiler for your MCU and modify the .yml file to use that compiler instead.

Finally, make sure that you update your environment variables so that you can access these tools from anywhere in your host system. A simple way to check if they were installed correctly is to check the version for each of the tools from the terminal

```
ceedling version
```
```
gcc --version
```
```
arm-none-eabi-gcc --version
```

Once you have all the dependancies installed, you can then clone this repo and try to build and test the project.

```
git clone https://github.com/BojanG72/STM32-Ceedling-Base.git
```

# Usage
[(Back to top)](#table-of-contents)

To compile and run the unit tests on your host machine, navigate to the project folder and run the following command
```
ceedling test:all
```
To compile and build the binaries for the taget machine, run the following command
```
ceedling release
```
I like to run the following command for building the binaries and running all tests
```
ceedling verbosity[5] clobber test:all release
```
the verbosity command enables ceedling to print out all the traces generated by the compiler, which is very useful for debugging. The clobber command will remove all
the previous artifacts generated by the compiler. This allows for a clean build each time. The release command will build the release binaries and the test:all command will run the unit tests.

Depending on which editor or IDE you choose to use, you can create a hotkey to run this command at the push of a button. Additionally, because it can be run from the command line, this can be easily incorporated into whatever CI/CD pipeline you decide to use. If you do not have a CI/CD pipeline setup, I would highly recommend it for production level firmware.

# Dev Container
[(Back to top)](#table-of-contents)

It is also possible to compile and run the unit tests inside of a docker container. The project now contains a Dockerfile that can be used to create a docker image running ubuntu and all of the tools required for building and testing. Additionally, that dockerfile can be used with the [vscode dev container extension](https://code.visualstudio.com/docs/devcontainers/containers#_quick-start-open-an-existing-folder-in-a-container).

This extention give vscode hooks into the container, and allows you to use the container as a dev environment.

# License
[(Back to top)](#table-of-contents)

[MIT License](https://github.com/BojanG72/STM32-Ceedling-Base/blob/main/LICENSE)

# Footer
[(Back to top)](#table-of-contents)

Leave a star in GitHub, and share this repo if you found it helpful.


![Footer](https://github.com/BojanG72/STM32-Ceedling-Base/blob/main/footer.png)
