#include "foo.h"

Matriz2D::Matriz2D(){
    // Constructor por defecto
    filas = 3;
    columnas = 3;
    ptr = new float*[3];
    for(int fil = 0; fil < filas; fil++){
        ptr[fil] = new float[3];
        for(int col = 0; col < columas; col++){
            ptr[fil][col] = 0.2;
        }
    }
}

Matriz2D::Matriz2D(int n){
    // Constructor con un parametro
    filas = n;
    columnas = n;
    ptr = new float*[n];
    for(int fil = 0; fil < filas; fil ++){
        ptr[fil] = new float[columnas];
        for(int col = 0; col < columnas;col++){
            ptr[fil][col] = 0.3;
        }
    }
}

Matriz2D::Matriz2D(int n, int m){
    // Constructor con dos parametros
    filas = n;
    columnas = m;
    ptr = new float*[n];
    for(int fil = 0; fil < filas; fil++){
        ptr[fil] = new float[columnas];
        for(int col = 0; col < columnas; col++){
            ptr[fil][col] = 0.2;
        }
    }
}

Matriz2D::Matriz2D(const Matriz2D& m){
    // Constructor de copia
    filas = m.filas;
    columnas = m.columnas;
    ptr = new float*[filas];
    for(int fil = 0; fil < filas; fil++){
        ptr[fil] = new float[columnas];
        for(int col = 0; col < columnas; col++){
            ptr[fil][col] = m.ptr[i][col];
        }
    }
}

Matriz2D::Matriz2D(Matriz2D&& m){
    // Constructor de movimiento
    filas = m.filas;
    columnas = m.columnas;
    ptr = new float*[filas];
    for(int fil = 0; fil < filas; fil++){
        ptr[fil] = new float[columnas];
        for(int col = 0; col< columnas; col++){
            ptr[fil][col] = m.ptr[fil][col];
        }
    }
    m.columnas = 0;
    m.filas = 0;
    m.ptr = nullptr;
}

Matriz2D t(Matriz2D& m){
    // Transpuesta de una matriz
    Matriz2D m2(m.colum, m.fila);
    for(int fil= 0; fil < m.colum; fil++){
        for(int col = 0; col < m.fila; col++){
            m2.ptr[fil][col] = m.ptr[col][fil];
        }
    }
    return m2;
}

Matriz2D operator+(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador +
    Matriz2D m3(m1.fila, m1.colum);
    for(int fil = 0; fil < m1.fila; fil++){
        for(int col = 0; col < m2.colum; col++){
            m3.ptr[fil][col] = m1.ptr[fil][col] + m2.ptr[fil][col];
        }
    }
    return m3;
}

Matriz2D operator+(const Matriz2D& m, float n){
    // Sobrecarga del operador +
    Matriz2D m2(m.fila, m.colum);
    for(int fil = 0; fil < m.fila; fil++){
        for(int col = 0; col < m.colum; col++){
            m2.ptr[fil][col] = m.ptr[fil][col] + n;
        }
    }
    return m2;

}

Matriz2D operator-(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador -
    Matriz2D m3(m1.fila, m2.colum);
    for(int fil = 0; fil < m1.fila; fil++){
        for(int col = 0; col < m2.colum; col++){
            m3.ptr[fil][col] = m1.ptr[fil][col] - m2.ptr[fil][col];
        }
    }
    return m3;
}

Matriz2D operator-(const Matriz2D& m, float n){
    // Sobrecarga del operador -
    Matriz2D m2(m.fila, m.colum);
    for(int fil = 0; fil< m.fila; fil++){
        for(int col = 0; col < m.colum; col++){
            m2.ptr[fil][col] = m.ptr[fil][col] - n;
        }
    }
    return m2;
}

Matriz2D operator*(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador *
    Matriz2D m3(m1.fila, m2.colum);
    for(int fil = 0; fil < m1.fila; fil++){
        for(int col = 0; col < m2.colum; col++){
            m3.ptr[fil][col] = 0;
            for(int k = 0; k < m1.fila; k++){
                m3.ptr[fil][col] = m1.ptr[fil][col] * m2.ptr[fil][col];
            }
        }
    }
    return m3;
}

Matriz2D operator*(const Matriz2D& m, float n){
    // Sobrecarga del operador *
    Matriz2D m2(m.fila, m.colum);
    for(int fil = 0; fil < m.fila; fil++){
        for(int col = 0; col < m.colum; col++){
            m2.ptr[fil][col] = m.ptr[fil][col] * n;
        }
    }
    return m2;
}

Matriz2D operator/(const Matriz2D& m, float n){
    // Sobrecarga del operador /
    Matriz2D m2(m.fila, m.colum);
    for(int fil = 0; fil < m.fila; fil++){
        for(int col = 0; col < m.colum; col++){
            m2.ptr[fil][col] = m.ptr[fil][col] / n;
        }
    }
    return m2;
}

std::ostream& operator<<(std::ostream& cout, const Matriz2D& m){
    for(int fil= 0; fil < m.fila; fil++){
        for(int col = 0; col < m.colum; col++){
            cout << m.ptr[fil][col] << " ";
        }
        cout << endl;
    }
    return cout;
}

float Matriz2D::get(int i, int j){
    return ptr[i][j];
}

int Matriz2D::getFilas(){
    return filas;
}

int Matriz2D::getColumnas(){
    return columnas;
}
