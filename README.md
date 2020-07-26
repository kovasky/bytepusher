# BytePusher Virtual Machine

BytePusher Virtual Machine created in Python using Pygame and Numpy; in C++ using SDL2.

## Description

BytePusher is a small VM with a one instruction set ByteByteJump CPU, 16 MiB RAM, 16 key keyboard (like Chip8), 256x256 Display, and 8-bit mono sampled sound. This is an implementation created in Python to get me started with the language.

You can read more about it here: https://esolangs.org/wiki/BytePusher

## Screenshots

<table>
  <tr>
    <td><img src="img/bpvm.gif"></td>
    <td><img src="img/palette.png"></td>
  </tr>
</table>

## Getting Started

### Dependencies
<ins>Python</ins>
* Python 3.6.9 (not tested on other versions)
* Numpy 1.18.1 (not tested on other versions)
* Pygame 1.9.6 (not tested on other versions)

<ins>C++</ins>
* C++11
* cmake 3.5
* SDL2  2.0.12

<ins>Swig</ins>
* Swig 4.0.1
* C++11
* Python 3.6.9
* Numpy 1.18.1 (not tested on other versions)
* Pygame 1.9.6 (not tested on other versions)

Built and run Linux Mint 19.3 running Linux 5.3.0-24

### Executing program

```
python3 main.py romLocation
```

```
cmake CMakeLists.txt
make
./bytepusher romLocation
```

```
make
python3 main.py romLocation
```

## To Do

* Implement Sound

## License

This project is licensed under the [GNU General Public License v3.0] License - see the LICENSE.md file for details

## Acknowledgments

* [Esolangs/BytePusher](https://esolangs.org/wiki/BytePusher)
* [Coder36](http://coder36.blogspot.com/2012/05/bytepusher.html)
* [Browser Safe Colors](http://www.ion.uillinois.edu/resources/tutorials/webdesign/WebGraphicsWorkshop/bscolors.htm)
