# Lissajous curve generator

Console application written in C++11 with SDL2 [working on Windows platform].

## Math background
Lissajous curve can be described via parametric equation:
```
x(t) = A sin(bt + c)
y(t) = D sin(et)
```
The patterns which we can obtain by changing curves parameters are really impress.
## Running app

- Clone repository by typing in command prompt: 
```git clone https://github.com/jedluk/Lissajous .``` 
- You can launch the app in two ways:
  - directly from console by typing:
  ```sh
  cd bin 
  Lissajous.exe
  ```
  - by double clicking on Lissajous.exe (command prompt will launch automatically in background)
- Lissajous curves will refresh after each 5 seconds
- You can also use mapped keyboard's keys:
    -- R - refresh curve factor instantly
    -- S - save current view to bitmap. It will be saved in current folder