# Práctica 5: El mayor de tres números

## 1. Descripción del problema (Fase 1)

Mi programa pide tres números y compara sus valores para encontrar cuál es el mayor. Al final muestra el número mayor. Esto podría servir para comparar medidas, temperaturas, velocidades o cualquier otro dato numérico.

## 2. Entradas y salidas (Fase 1)

**Entradas:**

1. **Número 1:** tipo `double`, primer número que ingresa el usuario.
2. **Número 2:** tipo `double`, segundo número que ingresa el usuario.
3. **Número 3:** tipo `double`, tercer número que ingresa el usuario.

**Salida:**

1. El valor del número mayor.

**¿Muestro el valor del mayor o cuál de los tres fue (primero, segundo o tercero)? ¿Por qué?**

Muestro el valor del mayor porque lo que pide el problema es encontrar cuál de los tres números tiene el valor más grande. No es necesario indicar su posición.

**¿Qué función de `utilerias.h` uso para leer los números? ¿Por qué esa y no la otra?**

Uso la función para leer números decimales, porque así mi programa puede aceptar números enteros y también números con decimales.

## 3. Restricciones e invariante (Fases 1 y 2)

**Restricciones**:

- Se deben ingresar tres números.
- Los datos deben ser números válidos.

**¿Hace falta validar el rango de los números (por ejemplo, rechazar el 0 o los negativos)? ¿Por qué?**

No hace falta validar un rango porque cualquier número puede ser comparado, incluyendo el 0, números negativos y números positivos.

**¿Qué hace mi programa cuando dos números son iguales y son los mayores? ¿Y cuando los tres son iguales?**

Si dos números son iguales y son los mayores, muestra ese valor mayor. Si los tres son iguales, muestra ese mismo valor.

**¿Quién detecta cada error?**

La función de `utilerias.h` se encarga de revisar que el dato ingresado sea un número válido. Yo me encargo de comparar los tres números para encontrar el mayor.

**Invariante**:

Justo antes de mostrar el resultado, la variable que contiene el mayor tiene un valor que es mayor o igual que los otros dos números.

## 4. Casos resueltos a mano (Fase 1)

## 10. Tabla de pruebas (Fase 4)

| Caso | Entradas | Esp. | Obt. | ¿Pasó? |
|---|---|---:|---:|---|
| Mayor 1.º | 9, 4, 2 | 9 | 9 | Sí |
| Mayor 2.º | 4, 9, 2 | 9 | 9 | Sí |
| Mayor 3.º | 2, 4, 9 | 9 | 9 | Sí |
| Empate 1.º-2.º | 7, 7, 3 | 7 | 7 | Sí |
| Empate 1.º-3.º | 7, 3, 7 | 7 | 7 | Sí |
| Empate 2.º-3.º | 8, 3, 3 | 8 | 8 | Sí |
| Los 3 iguales | 5, 5, 5 | 5 | 5 | Sí |
| Negativos | -4, -1, -9 | -1 | -1 | Sí |
| Con cero | -2, 0, -5 | 0 | 0 | Sí |
| Decimales | 2.5, 2.7, 2.6 | 2.7 | 2.7 | Sí |

## 5. Receta en pseudocódigo (Fase 2)

**¿Probé mi receta a mano con mis 5 casos?**

Sí.

**¿Tuve que corregirla? ¿Qué cambié?**

Sí. Revisé las comparaciones para asegurarme de que también funcionaran cuando hubiera números iguales.

**¿Cuántas versiones de mi receta escribí hasta la final?**

2 versiones.

**¿Se me ocurrió otra forma de resolver el problema? ¿Cuál? ¿Por qué elegí la que usé?**

Sí. Podía comparar los tres números usando varias condiciones. Elegí hacerlo guardando primero el mayor entre los dos primeros y después comparándolo con el tercero porque me pareció más sencillo de entender.

## 6. Cómo compilar y ejecutar (Fase 3)

```bash
g++ -Wall -Wextra -std=c++17 main.cpp -o numero_mayor

./numero_mayor

```

## 7. Ejemplo de ejecución (Fase 3)
<!-- Pega aquí lo que muestra tu programa en pantalla con un caso de empate (por ejemplo 7, 7 y 3). -->

Bienvenido al programa para encontrar el mayor de tres números.

Ingresa el primer número: 7
Ingresa el segundo número: 7
Ingresa el tercer número: 3

El número mayor es: 7

## 8. De la receta al código (Fase 3)
<!-- Para cada paso de TU receta, escribe la instrucción (o instrucciones) de C++ que lo implementa. Agrega las filas que necesites. -->

| Paso de la receta                                   | Instrucción de C++ que lo implementa               |
| --------------------------------------------------- | -------------------------------------------------- |
| 1. Mensaje de bienvenida                            | `cout << "Bienvenido al programa..." << endl;`     |
| 2. Leer el primer número                            | `cin >> a;`                                        |
| 3. Leer el segundo número                           | `cin >> b;`                                        |
| 4. Leer el tercer número                            | `cin >> c;`                                        |
| 5. Guardar inicialmente el primer número como mayor | `mayor = a;`                                       |
| 6. Comparar el segundo número con el mayor          | `if (b > mayor) mayor = b;`                        |
| 7. Comparar el tercer número con el mayor           | `if (c > mayor) mayor = c;`                        |
| 8. Mostrar el resultado                             | `cout << "El número mayor es: " << mayor << endl;` |


**¿Hubo algún paso de mi receta que me costó traducir a C++? ¿Cuál y por qué?**
_____Sí, la parte de las comparaciones porque tuve que entender cómo cambiar el valor de mayor cuando encontraba un número más grande.

## 9. Experimentos (Fase 3)

**Experimento A: ¿qué te dijo el compilador con `if (a > b > c)`? ¿Qué mostró el programa con 3, 2 y 1? ¿Por qué?**
_____El compilador no necesariamente marca un error porque la expresión es válida en C++, pero no funciona como una comparación matemática de los tres números.

Con 3, 2 y 1, primero se evalúa a > b, que da verdadero. Después ese resultado se compara con c. Como verdadero se convierte en 1, termina evaluando algo parecido a 1 > 1, que es falso.

Por eso no se debe usar a > b > c para encontrar el mayor de tres números.

**Experimento B: al cambiar `>=` por `>` (o al revés), ¿qué mostró el programa con 7, 7, 3 y con 5, 5, 5? ¿Por qué?**
_____Con > el programa mantiene el primer número cuando encuentra números iguales, porque un número igual no es mayor.

Con >=, también puede reemplazar el valor cuando encuentra otro número igual. Sin embargo, como solamente mostramos el valor del mayor, en los dos casos se obtiene 7 para 7, 7, 3 y 5 para 5, 5, 5.

Experimento C (opcional): con if (a = b), ¿qué te dijo el compilador? ¿Qué le pasó al valor de a?

La expresión puede compilar, pero no compara los valores. El operador = asigna el valor de b a a. Por lo tanto, a cambia y toma el valor de b.

Para comparar se debe utilizar ==.

**Experimento C (opcional): con `if (a = b)`, ¿qué te dijo el compilador? ¿Qué le pasó al valor de `a`?**
_____

## 10. Tabla de pruebas (Fase 4)

| Caso | Entradas | Esp. | Obt. | ¿Pasó? |
|---|---|---:|---:|---|
| Mayor 1.º | 9, 4, 2 | 9 | 9 | Sí |
| Mayor 2.º | 4, 9, 2 | 9 | 9 | Sí |
| Mayor 3.º | 2, 4, 9 | 9 | 9 | Sí |
| Empate 1.º-2.º | 7, 7, 3 | 7 | 7 | Sí |
| Empate 1.º-3.º | 7, 3, 7 | 7 | 7 | Sí |
| Empate 2.º-3.º | 8, 3, 3 | 8 | 8 | Sí |
| Los 3 iguales | 5, 5, 5 | 5 | 5 | Sí |
| Negativos | -4, -1, -9 | -1 | -1 | Sí |
| Con cero | -2, 0, -5 | 0 | 0 | Sí |
| Decimales | 2.5, 2.7, 2.6 | 2.7 | 2.7 | Sí |
| Texto | abc, 1, 2 | 3 | 3 | Sí |
| Propio 1 | 100, 50, 75 | 100 | 100 | Sí |
| Propio 2 | -10, -20, -5 | -5 | -5 | Sí |


## 11. Bitácora de mejoras (Fase 4)

| # | ¿Qué falló o qué quise mejorar? | ¿Qué cambié? | ¿Funcionó? |
|---|---|---|---|
| 1 | No había considerado los números iguales. | Revisé las condiciones de comparación. | Si |
| 2 | Quería aceptar números negativos y decimales. |  Usé un tipo de dato que permite ambos. | Si |

**Reto elegido (opcional):** Hacer que el programa también indique si hubo empate entre dos o tres números.

## 12. Dudas para el profesor (Fase 3)

| Duda | Lo que ya intenté |
|---|---|
| ¿Es mejor usar > o >= para este problema? | Probé las dos opciones con números iguales y obtuve el mismo valor mayor. |

## 13. Reflexión final

**¿Qué aprendí con esta práctica?**
Aprendí a comparar tres números para encontrar el mayor y entendí que las condiciones deben estar bien planteadas. También aprendí que los números negativos y los empates deben tomarse en cuenta al hacer las pruebas.

**Ahora que terminé, ¿qué cambiaría de mi proceso?**
Primero haría más casos a mano antes de comenzar a programar para encontrar posibles problemas desde el principio.

**¿Qué fue lo más difícil y cómo lo resolví?**
Lo más difícil fue entender cómo hacer las comparaciones entre los tres números. Lo resolví separando el problema en pasos más pequeños y probando diferentes valores.

**¿Qué pregunta me quedó sin responder?**
Me quedó la duda de cuál sería la mejor forma de modificar el programa para que también indique la posición del número mayor.

**¿Qué fue más fácil para mí: la Práctica 3 (receta propia con un paso de ejemplo), la 4 (receta ajena) o esta (todo desde cero)? ¿Por qué?**
La Práctica 4 fue más fácil porque ya tenía una receta que seguir. Esta práctica fue un poco más difícil porque tuve que pensar desde cero en las condiciones y en los casos de prueba.

**¿Pensé en los empates antes de programar o los descubrí al probar?**
Los pensé al hacer los casos de prueba, porque me di cuenta de que dos o tres números podían tener el mismo valor mayor.

## 14. Lista de verificación antes de entregar (Fase 5)

- [ ] Llené las secciones 1 a 13 (no quedan `_____`)
- [ ] Escribí mi receta completa en `RECETA.md` antes de programar
- [ ] Cada bloque de `main.cpp` tiene su comentario `// Paso N`, de acuerdo con mi receta
- [ ] Mi programa compila sin advertencias
- [ ] Probé todos los casos de la tabla, incluidos los empates
- [ ] Hice los Experimentos A y B y dejé el código correcto al terminar
- [ ] No modifiqué `utilerias.h`
- [ ] Hice al menos 3 commits con mensajes claros
- [ ] Hice `git push` y verifiqué mi fork en GitHub
- [ ] Mi fork se llama `ulsa_ime_1_dp_numero_mayor` y el código está en `main.cpp`
- [ ] Entregué el enlace de mi fork en Classroom
