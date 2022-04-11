#include <vector>
#include <iostream>
#include <string>
using namespace std;
namespace zich{
    class Matrix {
    private:
        int row;
        int col;
        vector<double> mat;
    public:
        Matrix(vector<double>  mat, int rows, int cols);
        Matrix(const Matrix& matrix);
        Matrix();
        bool operator==(Matrix const & mat);
        bool operator!=(Matrix const & mat);
        bool operator<(Matrix const & mat);
        void checkMatSize(Matrix const & mat) const;
        double getMatAt(int pos);
        int getRows() const;
        int getCols() const;
        bool operator>(Matrix  const & mat);
        bool operator<=(Matrix const & mat);
        bool operator>=(Matrix const & mat);
        Matrix operator+(const Matrix &);
        Matrix& operator++();
        Matrix operator++(int);
        Matrix& operator--();
        Matrix operator--(int);
        Matrix& operator=(Matrix const &);
        Matrix operator*=(double num);
        Matrix operator*(Matrix const &);
        Matrix operator*=(Matrix const &);
        Matrix operator+=(Matrix const &);
        Matrix operator-(Matrix const &);
        Matrix operator-();
        Matrix operator+();
        Matrix operator-=(Matrix const &);
        friend istream& operator>>(istream &in, Matrix &mat);
        friend ostream& operator<<(ostream &out,  Matrix const &mat);
        Matrix operator*(int num);
        friend Matrix operator*(int num,Matrix mat);
        friend Matrix operator*(double num,Matrix mat);
        Matrix operator*(double num);
        friend bool operator==(Matrix const & matrix1,Matrix const & matrix2);
        static bool isValid(vector<char> str);
        string matrixSum(Matrix const & mat);
    };
};