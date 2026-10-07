# Chroma Key

Programa desarrollado en C++ utilizando OpenCV para aplicar la técnica de Chroma Key, permitiendo sustituir el fondo de una imagen mediante una máscara de color.

## Compilación

```bash
mkdir build
cd build
cmake ..
make
```

## Ejemplos de ejecución

El programa se ejecuta indicando las opciones deseadas, la imagen de entrada, la imagen de fondo y, opcionalmente, la imagen de salida:

```bash
./chroma_key [opciones] <imagen_entrada> <imagen_fondo> [imagen_salida]
```

Por ejemplo:

```bash
./chroma_key ../data/supermangreen.jpg ../data/background.jpg salida.jpg
```

También se pueden especificar el tono del Chroma Key y la sensibilidad:

```bash
./chroma_key -k=60 -s=20 ../data/supermangreen.jpg ../data/background.jpg salida.jpg
```

Los parámetros y opciones disponibles pueden consultarse mediante:

```bash
./chroma_key --help
```

## Imágenes de entrada

Las imágenes y vídeos que se vayan a utilizar deben almacenarse en el directorio `data/`.

Por ejemplo:

```text
data/
├── supermangreen.jpg
├── harrypgreen.jpeg
├── background.jpg
└── Spokesperson.mp4
```

Al ejecutar el programa desde el directorio `build/`, los archivos de entrada pueden utilizarse mediante la ruta relativa `../data/`.