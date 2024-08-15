# Keylogger (C lang)

Esta sección del repositorio de Seguridad Informatica contiene el código fuente para un _Keylogger_ creado en C para
el sistema operativo Linux.

**Nota: Las pruebas fueron realizadas en Lubuntu (24.04) y GCC (13.2.0).**

**Nota: El código fuente fue desarrollado en conjunto con el profesor Palma Lopez Daniel Fernando durante la clase del
Martes 13 de Agosto de 2024.**

## Requisitos Previos

- Git: Para poder clonar el repositorio con el código fuente.
- GCC: Compilador de C que nos permitira crear el ejecutable del código fuente.
- Acceso al usuario con privilegios elevados (SUDO).

## Instrucciones de Uso

- Clonar el repositorio de GitHub.

```
git clone https://github.com/YaelAram/SeguridadInformatica.git
```

- Navegar al directorio con el código fuente del _Keylogger_ dentro de la terminal.
- Compilar el código fuente.

```
gcc keylogger.c -o EJECUTABLE
```

**Donde EJECUTABLE, se refiere al nombre que deseamos darle al ejecutable generado por compilador de C.**

- Ejecutar el resultado de la compilación.

```
sudo ./EJECUTABLE
```

**Nota: El nombre del ejecutable debe coincidir con el nombre asignado al compilar el codigo fuente.**
**Nota: Es necesario ejecutar el programa otorgando privilegios de SUper Usuario para el correcto funcionamiento del mismo.**

## Configuraciones

El _Keylogger_ permite establecer las siguientes configuraciones:

- Establecer la ruta del archivo TXT con el log del teclado.

Mediante la constante LOG_FILE_PATH podemos modificar la ruta en la que sera generado el archivo TXT con las teclas presionadas
por el usuario. 

Por defecto el archivo TXT es generado en la misma ruta en la que se encuentra el ejecutable del codigo fuente.

## Notas de Uso

El _Keylogger_ imprime las teclas que el usuario oprime dentro del archivo TXT siguiendo las consideraciones sigueintes:

- Teclas numericas, signos de puntuacion u operaciones aritmeticas: Cuando el usuario oprime una de estas teclas el _Keylogger_ 
las registra utilizando el caracter ASCII asociado a la tecla.

```
Al pulsar la tecla 1: Registra "1"
Al pulsar la tecla +: Registra "+"
Al pulsar la tecla .: Registra "."
```

**Nota: Las teclas del teclado numerico no reciben ningun tratamiento especial, es decir, la tecla 1 del teclado numerico
registra el mismo resultado que la tecla 1 del teclado normal.**

- Teclas letras: El _Keylogger_ registra el caracter ASCII asociado a la tecla. Al iniciar, el _Keylogger_ este detecta si la tecla 
CAPS_LOCK esta activada y constantemente verifica su estado, por lo que es capaz de registrar letras mayusculas y minusculas segun el 
estado de la tecla CAPS_LOCK.

```
Al pulsar la tecla A (CAPS_LOCK desactivado): Registra "a"
Al pulsar la tecla A (CAPS_LOCK activado): Registra "A"
```

- Teclas especiales: Las teclas especiales son todas aquellas que no representan un numero, letra o signo, cuando esto sucede el 
_Keylogger_ la registra de la siguiente manera: " [NOMBRE DE LA TECLA] " (El nombre de la tecla mas un espacio al inicio y final).

```
Al pulsar la tecla ENTER: Registra " ENTER \n"
Al pulsar la tecla TAB: Registra " TAB \t"
Al pulsar la tecla SHIFT: Registra " SHIFT "
```

**Nota: En el caso de la tecla ENTER y TAB adicionalmente se registra un \\n o un \\t respectivamente.**

## Casos de Uso

### Configurar la ruta del archivo TXT del _Keylogger_

- Actor: Usuario Final
- Objetivo: Cambiar la ruta de generacion del archivo TXT
- Escenario:
  1. Abrir el archivo _keylogger.c_ en un editor de codigo o texto.
  2. Modificar el valor de la constante LOG_FILE_PATH con la ruta deseada
  3. Guardar los cambios.
  4. Compilar el codigo fuente.

### Terminar la ejecución del _Keylogger_

- Actor: Usuario Final
- Objetivo: Terminar la ejecucion del _Keylogger_
- Escenario:
  1. Abrir la terminal en la que esta corriendo el _Keylogger_.
  2. Oprimir Ctrl + C.
