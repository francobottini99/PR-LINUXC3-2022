# Prácticas de Lenguaje C en GNU/Linux

Este repositorio aborda la tarea de mapeo de memoria en el contexto de un programa en lenguaje C ejecutado en GNU/Linux. El objetivo principal es acceder a datos en un archivo binario llamado `datos`, proveniente del radar meteorológico RMA1 en Ciudad Universitaria (UNC). Se espera que el programa realice mapeo de memoria, castee los datos según la estructura proporcionada y resuelva algunas actividades incrementales.

## Estructura del Proyecto

El proyecto se organiza de la siguiente manera:

- **inc/Lab6.h:** Encabezado que contiene la estructura de datos RMA1 y las declaraciones de funciones.
- **src/Lab6.c:** Archivo fuente que implementa las funciones para cargar el archivo y obtener muestras.
- **main.c:** Programa principal que utiliza las funciones implementadas en Lab6.c.
- **Makefile:** Archivo para compilar y construir el proyecto.

## Compilación y Ejecución

Para compilar el proyecto, se puede utilizar el siguiente comando:

```bash
make
```

Este comando generará el ejecutable "lab6". Luego, se puede ejecutar el programa con:

```bash
./lab6
```

## Funcionamiento del Programa

El programa realiza las siguientes acciones:

1. Carga el archivo binario "datos" utilizando la función `load_rawdata`.
2. Obtiene las muestras mediante la función `get_samples`, que mapea el archivo y devuelve un arreglo de estructuras RMA1.
3. Calcula la cantidad total de muestras y la media de la variable `validSamples`.
4. Imprime los resultados en la consola.

## Cuestionarios Adicionales

### 1. ¿Cuál es la importancia del mapeo de memoria en este contexto?

El mapeo de memoria es crucial en este contexto porque nos permite acceder directamente a los datos almacenados en el archivo binario sin necesidad de leerlos explícitamente. Al mapear el archivo en memoria, se crea una correspondencia entre la memoria del programa y el archivo en disco. Esto facilita la manipulación eficiente de grandes conjuntos de datos y mejora el rendimiento al evitar múltiples lecturas del archivo.

### 2. ¿Cómo se gestiona la liberación de memoria utilizada?

La liberación de memoria se realiza al final del programa. Se liberan las muestras obtenidas mediante la función `free(samples)`. Además, se utiliza la función `munmap` para liberar la memoria asignada al mapeo del archivo.

## Conclusiones

El uso de mapeo de memoria proporciona una forma eficiente de acceder y manipular datos almacenados en archivos. La estructura del programa facilita la comprensión y modificación del código, y la organización en módulos mejora la mantenibilidad. La compilación con flags específicos y la ausencia de errores y warnings garantizan la robustez del código.