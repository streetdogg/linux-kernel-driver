# About

This repository implemnts a sample linux kernel device driver just for the purposes of pratice and to explore the kernel.

# Testing
- building the module
```
[piyush@cow] /media/piyush/data/code/linux_device_drier (main) ⚡ 
❯ make
```
- Checking the module info
```shell
[piyush@cow] /media/piyush/data/code/linux_device_drier (main) ⚡ 
❯ modinfo ./fake_module.ko
filename:       /media/piyush/data/code/linux_device_drier/./fake_module.ko
license:        GPL
author:         Piyush Itankar <pitankar@gmail.com>
srcversion:     C12FE96951541D680D1018D
depends:        
retpoline:      Y
name:           fake_module
vermagic:       5.11.0-22-generic SMP mod_unload modversions 
parm:           msg:Custom greeting message (charp)
parm:           times:Number of times the greeting message needs to be printed (int)
parm:           key:Random 4 digit key, used for nothing :P (array of int)
```
- load the module
```shell
[piyush@cow] /media/piyush/data/code/linux_device_drier (main) ⚡ 
❯ sudo insmod fake_module.ko msg="Greetings" times=3 key=1,9,9,1                 

[piyush@cow] /media/piyush/data/code/linux_device_drier (main) ⚡ 
❯ sudo dmesg                                                    
[  601.059421] Fake module init!
[  601.059429] Greetings
[  601.059433] Greetings
[  601.059436] Greetings
[  601.059438] Key: 1991
```
- unload the module
```
[piyush@cow] /media/piyush/data/code/linux_device_drier (main) ⚡ 
❯ sudo rmmod fake_module                                        

[piyush@cow] /media/piyush/data/code/linux_device_drier (main) ⚡ 
❯ sudo dmesg            
[  601.059421] Fake module init!
[  601.059429] Greetings
[  601.059433] Greetings
[  601.059436] Greetings
[  601.059438] Key: 1991
[  608.854395] Good bye, cruel world!

```
- clean the repo
```
[piyush@cow] /media/piyush/data/code/linux_device_drier (main) ⚡ 
❯ make clean
```
# References

I have referred the following resources while working on this repository.
- Linux Device Driver Development - John Madieu
    - [Book](https://www.packtpub.com/product/linux-device-drivers-development/9781785280009)
    - [Source code](https://github.com/PacktPublishing/Linux-Device-Drivers-Development)