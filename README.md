# Project Z

WIP Platformer

## Dependencies
- SFML
    - Either install using a package manager
        - e.g. (`sudo apt-get install libsfml-devel`)
    -  Or build from source: https://www.sfml-dev.org/tutorials/2.5/compile-with-cmake.php

## How to build
If SFML is installed in a standard path, run:
```
cmake . bin
```

Otherwise use `SFML_DIR` to set path to look for SFML:
```
cmake -DSFML_DIR=/path/to/SFML . bin
```
