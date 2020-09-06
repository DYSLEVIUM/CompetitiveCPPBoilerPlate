template <typename T, typename DIM = unsigned long int>
class Matrix {
   public:
    DIM m;
    DIM n;
    T* data;
    T* identity;

    Matrix() : m(0), n(0), data(new T[this->m * this->n]), identity(new T[this->m * this->n]) {
        for (DIM i = 0; i < this->m; ++i) {
            for (DIM j = 0; j < this->n; ++j) {
                if (i == j) {
                    this->identity[i * this->n + j] = 1;
                } else {
                    this->identity[i * this->n + j] = 0;
                }
                this->data[i * this->n + j] = 0;
            }
        }
    }

    Matrix(DIM r, DIM c) {
        this->m = r;
        this->n = c;

        this->data = new T[this->m * this->n];
        this->identity = new T[this->m * this->n];

        for (DIM i = 0; i < this->m; ++i) {
            for (DIM j = 0; j < this->n; ++j) {
                if (i == j) {
                    this->identity[i * this->n + j] = 1;
                } else {
                    this->identity[i * this->n + j] = 0;
                }
                this->data[i * this->n + j] = 0;
            }
        }
    }

    Matrix(const Matrix& mat) {
        this->m = mat.m;
        this->n = mat.n;
        this->data = new T[this->m * this->n];
        this->identity = new T[this->m * this->n];

        for (DIM i = 0; i < this->m; ++i) {
            for (DIM j = 0; j < this->n; ++j) {
                this->data[i * this->n + j] = mat.data[i * this->n + j];
            }
        }

        for (DIM i = 0; i < this->m; ++i) {
            for (DIM j = 0; j < this->n; ++j) {
                this->identity[i * this->n + j] = mat.identity[i * this->n + j];
            }
        }
    }

    friend istream& operator>>(istream& in, const Matrix& mat) {
        for (DIM i = 0; i < mat.m; ++i) {
            for (DIM j = 0; j < mat.n; ++j) {
                in >> mat.data[i * mat.n + j];
            }
        }
        return in;
    }

    friend ostream& operator<<(ostream& o, const Matrix& mat) {
        for (DIM i = 0; i < mat.m; ++i) {
            for (DIM j = 0; j < mat.n; ++j) {
                o << mat.data[i * mat.n + j] << ' ';
            }
            o << '\n';
        }
        return o;
    }

    friend Matrix operator+(const Matrix& mat1, const Matrix& mat2) {
        try {
            if (mat1.m != mat2.m && mat1.n != mat2.n) throw true;

            Matrix temp(mat1.m, mat1.n);

            for (DIM i = 0; i < mat1.m; ++i) {
                for (DIM j = 0; j < mat1.n; ++j) {
                    temp.data[i * mat1.n + j] = mat1.data[i * mat1.n + j] + mat2.data[i * mat1.n + j];
                }
            }

            return temp;
        } catch (bool err) {
            Matrix temp;
            cout << "Dimensions are not equal.\n";
            return temp;
        }
    }

    void operator+=(const Matrix& mat) {
        *this = *this + mat;
    }

    friend Matrix operator-(const Matrix& mat1, const Matrix& mat2) {
        try {
            if (mat1.m != mat2.m && mat1.n != mat2.n) throw true;

            Matrix temp(mat1.m, mat1.n);

            for (DIM i = 0; i < mat1.m; ++i) {
                for (DIM j = 0; j < mat1.n; ++j) {
                    temp.data[i * mat1.n + j] = mat1.data[i * mat1.n + j] - mat2.data[i * mat1.n + j];
                }
            }

            return temp;
        } catch (bool err) {
            Matrix temp;
            cout << "Dimensions are not equal.\n";
            return temp;
        }
    }

    void operator-=(const Matrix& mat) {
        *this = *this - mat;
    }

    friend Matrix operator*(const Matrix& mat1, const Matrix& mat2) {
        try {
            if (mat1.n != mat2.m) throw true;

            Matrix temp(mat1.m, mat2.n);

            for (DIM i = 0; i < mat1.m; ++i) {
                for (DIM j = 0; j < mat2.n; ++j) {
                    for (DIM k = 0; k < mat2.n; ++k) {
                        temp.data[i * mat2.n + j] += mat1.data[i * mat1.n + k] * mat2.data[k * mat2.n + j];
                    }
                }
            }

            return temp;
        } catch (bool err) {
            Matrix temp;
            cout << "Error in dimensions.\n";
            return temp;
        }
    }

    friend Matrix operator^(Matrix mat, long long exp) {
        Matrix temp(mat.m, mat.n);

        temp.data = mat.identity;

        while (exp > 0) {
            if (exp & 1) temp = temp * mat;
            mat = mat * mat;
            exp /= 2;
        }

        return temp;
    }

    void operator=(const Matrix& mat) {
        for (DIM i = 0; i < this->m; ++i) {
            for (DIM j = 0; j < this->n; ++j) {
                this->data[i * this->n + j] = mat.data[i * this->n + j];
            }
        }
    }

    ~Matrix() {
        delete[] data;
        delete[] identity;
    }
}
