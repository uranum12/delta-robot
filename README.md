# delta robot

## overview

A delta robot is a type of parallel robot that consists of three arms connected to universal joints at the base.

## requirements

Requires latest pico sdk.

## build and flash

Setup a CMake build directory. For example, if not using an IDE:

```shell
cmake -G Ninja -B build
ninja -C build
```

Boot the Raspberry Pi Pico with the BOOTSEL button pressed and drag on `main.uf2`.

