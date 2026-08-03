# OGXMSB

Fork of https://github.com/MegaCadeDev/OGX-Mini-2026/



```
git clone --recurse-submodules https://github.com/MegaCadeDev/OGX-Mini-2026
cd OXG-Mini-2026/Firmware/external
git clone --recurse-submodules https://github.com/RaspberryPi/pico-sdk
mkdir ../RP2040/build
cd ../RP2040/build
cmake -DOGXM_BOARD=[BOARD OPTION] -DOGXM_FIXED_DRIVER=[CONTROLLER OPTION] -DCMAKE_BUILD_TYPE=[Debug or Release] ..
make
```
