# fract-ol

fract-ol is a C fractal viewer using MiniLibX. I t render Mandelbrot, Julia and Burning Ship sets in an interactive window.

## Dependencies

Requires MiniLibX and its dependencies:

```bash
sudo apt install libx11-dev libxext-dev
```

MiniLibX should be present in a `minilibx-linux/` folder at the project root.

## Build

```bash
make
```

## Usage

```bash
./fractol <fractal_type>
```

```bash
./fractol mandelbrot   #or: ./fractol 1
./fractol julia        #or: ./fractol 2
./fractol burningship  #or: ./fractol 3
```

## Controls


| Key / Input | Action |
|-------------|--------|
| Arrow keys | Pan |
| Scroll wheel | Zoom in / out |
| `+` / `-` | Zoom in / out (keyboard) |
| `C` | Cycle colour scheme |
| `M` | Toggle mouse tracking (Julia only) |
| `Q` / `E` | Increase / decrease iteration depth |
| `ESC` | Close window |

Mouse tracking on Julia updates the complex constant in real time as you move the cursor.

## Project Structure

```

fract-ol/
├── includes/
│   └── fractol.h
├── libft/
├── minilibx-linux/
├── complex.c
├── events.c
├── events2.c
├── fractal_sets.c
├── fractol.c
├── initialisation.c
├── render.c
├── utils.c
└── Makefile
```

## License
42Luxembourg

## Author
Alexandra Henriques (alehenri - 42Luxembourg)
