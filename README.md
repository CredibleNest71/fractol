# fract-ol

Renders the Mandelbrot set, Julia sets and the Burning Ship fractal in real time with the MiniLibX graphics library. Written in C at 42 Vienna.

## Build and run

```sh
make
./fractal mandel
./fractal julia                # default Julia set
./fractal julia -0.8 0.156     # Julia set for c = real + imaginary·i
```

## Controls

| Input | Action |
| --- | --- |
| Mouse wheel | Zoom in and out, centred on the cursor |
| Right click | Switch fractal: Mandelbrot → Julia → Burning Ship |
| Middle click | Switch colour palette |
| Left click | Explore mode on/off: the Julia constant follows the mouse |
| `Esc` or the window's close button | Quit |
