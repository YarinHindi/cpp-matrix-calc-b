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
        bool operator==(Matrix const & mat)const;
        bool operator!=(Matrix const & mat)const;
        bool operator<(Matrix const & mat)const;
        void checkMatSize(Matrix const & mat) const;
        double getMatAt(int pos);
        int getRows() const;
        int getCols() const;
        bool operator>(Matrix  const & mat)const;
        bool operator<=(Matrix const & mat)const;
        bool operator>=(Matrix const & mat)const;
        Matrix operator+(const Matrix &)const;
        Matrix& operator++();
        Matrix operator++(int);
        Matrix& operator--();
        Matrix operator--(int);
        Matrix& operator=(Matrix const &);
        Matrix operator*=(double num);
        Matrix operator*(Matrix const &)const;
        Matrix operator*=(Matrix const &);
        Matrix operator+=(Matrix const &);
        Matrix operator-(Matrix const &)const;
        Matrix operator-()const;
        Matrix operator+()const;
        Matrix operator-=(Matrix const &);
        friend istream& operator>>(istream &in, Matrix &mat);
        friend ostream& operator<<(ostream &out,  Matrix const &mat);
        Matrix operator*(int num)const;
        friend Matrix operator*(int num,Matrix mat);
        friend Matrix operator*(double num,Matrix mat);
        Matrix operator*(double num)const;
        static bool isNumber(string const & str);
        static void throwFunction();
        string matrixSum(Matrix const & mat)const;
    };
};