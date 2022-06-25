# PROBLEMA DE SATISFACCION DE RESTRICCIONES

* todas las varibles deben estar asignadas
* test-objetivo --> verifica que exista una asignacion completa y consistente

---

### Cryptoaritmetica
- Cada letra representa un digito

 Alldiff(F,T,U,W,R,O);

* 15 combinaciones donde todas son diferentes --> T!=O......

* Todas las varibles son diferentes
```
1. O + O = R + 10C1
2. C1 + W + W = U + 10C2
3. C2 + T + T = O + 10C3
4. C3 = F
5. F != 0
```

#### Caracteristicas
- Dominio
```
D={0,1,2,3,4,5,6,7,8,9}
```

- Varibles
```
X={F,T,U,W,R,O}

Xa={C1,C2,C3}
```
### Ejercicio

![a picture of bill](./criptoaritmetica_img.jpg)

## Restriccion Global
* En esta restriccion participa un numero arbitrario de variables
* Alldiff(F,T,U,W,R,O);

## Restriccion binaria
* En esta restriccion participan dos variables
   * T != O
   * F != O

## Restriccion Unaria
* En esta restriccion se restringe el valor de una sola variable 
* F != 0



### Primera restriccion 
* todas las variables tienen que ser diferentes 

### Segunda restriccion 
* todas las variables tienen que cumplir con: 

```
1. O + O = R + 10C1
2. C1 + W + W = U + 10C2
3. C2 + T + T = O + 10C3
4. C3 = F
5. F != 0
```