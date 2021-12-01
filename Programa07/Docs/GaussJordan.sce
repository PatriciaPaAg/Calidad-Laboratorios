clear
///////////////////////////////////////////////////////
//  GaussJordan.sce
//
//  Este programa resuelve una matriz dada mediante el
//  metodo de Gauss Jordan, despliega paso a paso cada matriz
//  y al final depsliega los valores de la o las x's 
//
//   Patricia   Palula   Aguilar
//   22 / 01  / 2020    version 1.0
//////////////////////////////////////////////////////

//////////////////////////////////////////////////////
//  ObteMatriz
//
//  Funcion que obtiene los valores de la matriz
//
//   Parametros:
//      ren     numero de renglones
//      col     numero de columnas
/////////////////////////////////////////////////////
function dMat = ObteMatriz(ren, col)
    disp("   Introduce los siguientes datos ")
    for i = 1 : ren
        for j = 1 : col
            dMat(i,j) = input(" (" + string(i) + "," + string(j) + ")  ")
        end
    end
endfunction

//////////////////////////////////////////////////////
//  Desplegar
//
//  Funcion que despliega en pantalla una matriz
//
//   Parametros:
//      dMat    matriz a desplegar
//      ren     numero de renglones
//      col     numero de columnas
/////////////////////////////////////////////////////
function Desplegar(dMat, ren, col)
    for i = 1 : ren
        mprintf("\t")
        for j = 1 : col
            // agrega un espacio si es 0 o un numero positivo
            // despliega la matriz
            if dMat(i,j) >= 0 then
                mprintf("\t " + string(dMat(i , j)))
            else
                mprintf("\t" + string(dMat(i , j)))
            end
        end
        mprintf("\n")
    end
    mprintf("\n")
endfunction

//////////////////////////////////////////////////////
//  Resultados
//
//  Funcion que despliega en pantalla los valores finales
//  de la o las x's
//
//   Parametros:
//      dMat    matriz a desplegar
//      ren     numero de renglones
//      col     numero de columnas
/////////////////////////////////////////////////////
function Resultados(dMat, ren, col)
    for i = 1 : ren
        // asigna a la variable resul el valor del renglon i
        // de la ultima columna
        resul = dMat(i,col)
        // agrega un espacio si es 0 o un numero positivo
        // despliega resultado por resultado
        if dMat(i,col) >= 0 then
            mprintf("\t \t x" + string(i) + " =  " + string(resul)+ "\n")
        else
            mprintf("\t \t x" + string(i) + " = " + string(resul) + "\n")
        end
    end
endfunction

//////////////////////////////////////////////////////
//  GaussJordan
//
//  Funcion que resuelve la matriz por el método de Gauss Jordan
//
//   Parametros:
//      dMat    matriz a desplegar
//      ren     numero de renglones
//      col     numero de columnas
/////////////////////////////////////////////////////
function dVectResu = GaussJordan(dMat, ren, col)
    // empieza la cuenta de las matrices
    for cuenta = 1 : ren
        // obtiene el numero por el cual se tiene que dividir el renglon
        divisor = dMat(cuenta,cuenta)
        // simplifica el renglon en la posicion 'cuenta'
        for j = cuenta : col
            dMat(cuenta,j) = dMat(cuenta,j) / divisor 
        end
        // imprime la matriz simplificada
        mprintf(" Matriz " + string(cuenta - 1) + " simplificada: \n")
        Desplegar(dMat, ren, col)
        // vuelve 0's los digitos de la columna en la posicion 'cuenta'
        // diferentes del renglon 'cuenta'
        for i = 1 : ren
            if i <> cuenta then
                // obtiene el numero para volver 0 el digito
                num = (- 1) * (dMat(i,cuenta))
                for j = cuenta : col
                    // realiza las multiplicacion y adiciones
                    // segun Gauss Jordan
                    dMat(i,j)= dMat(cuenta,j) * num + dMat(i,j)
                end
            end
        end
        // imprime la nueva matriz
        mprintf(" Matriz " + string(cuenta) + ": \n")
        Desplegar(dMat, ren, col)
    end
    // despliega los resultados
    Resultados(dMat, ren, col)
endfunction

/////// Programa Principal

// inicializo las variables
colum = 0
rengl = 0
// pido los valores y los valido
while(colum <> rengl + 1 | rengl <= 0)
    colum = input("Columnas: ")
    rengl = input("Renglones: ")
    if(colum <> rengl + 1 | rengl <= 0) then
        mprintf("Numero de columnas o renglones invalido \n \n")
    end
end

// obtengo y despliego la matriz principal
dMatriz = ObteMatriz(rengl, colum)
disp("Matriz inicial: ")
Desplegar(dMatriz, rengl, colum)
// resuleve la matriz y la despliega paso por paso
// junto con los resultados
GaussJordan(dMatriz, rengl, colum)



// \(U.U)/
