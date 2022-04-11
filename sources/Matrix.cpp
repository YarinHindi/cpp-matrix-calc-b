//
// Created by yarin on 3/30/2022.
//
#include "Matrix.hpp"
using namespace std;
using namespace zich;
Matrix::Matrix(vector<double>  mat,int row,int col){
        if(row*col!=mat.size()||row<=0||col<=0){
            throw std::invalid_argument("row*col should be equal to vector size");
        }
        this->mat = std::move(mat);
        this->row = row;
        this->col = col;
}
Matrix::Matrix(){
    this->row = 0;
    this->col = 0;
}
bool zich::operator==(Matrix const & matrix1,Matrix const & matrix2){
    for (size_t i=0; i< matrix1.col*matrix1.row;i++){
        if(matrix1.mat.at(i)!=matrix2.mat.at(i)){
            return false;
        }
    }
    return true;
}

Matrix::Matrix(const Matrix& matrix) // copy constructor
{
    this->row = matrix.row;
    this->col = matrix.col;
    this->mat = matrix.mat;
}

int Matrix::getRows() const {
    return this->row;
}
int Matrix::getCols() const {
    return this->col;
}

string Matrix::matrixSum(Matrix const & matrix){
    double sum1=0;
    double  sum2 =0;
    for (size_t i = 0; i < matrix.col*matrix.row; ++i) {
        sum1+=this->mat.at(i);
        sum2+=matrix.mat.at(i);
    }
    if(sum1==sum2){return "Even";}
    if(sum1<sum2){return "Smaller";}
    if (sum1>sum2){return "Bigger";}
    return "";
    }
double Matrix::getMatAt(int pos) {
    if(pos<0||pos> this->col*this->row){
        throw std::invalid_argument("index out of range");
    }
    unsigned int position = (unsigned int)(pos);
    return this->mat.at(position);
}
void Matrix::checkMatSize(Matrix const & mat) const{
    if(mat.col!=this->col||mat.row!=this->row){
        throw std::invalid_argument("matrix should be in same size");
    }
}
bool Matrix::operator>=(Matrix const &mat) {
    Matrix::checkMatSize(mat);
    string ans = Matrix::matrixSum(mat);
    int answer = 1;
    if(ans=="Even"||ans=="Bigger"){
        answer= 1;
    }else{
        answer = 0;
    }
    return bool(answer);
}
bool Matrix::operator>(Matrix const &mat) {
    Matrix::checkMatSize(mat);
    int ans = 1;
    if(Matrix::matrixSum(mat)=="Bigger"){
        ans = 1;
    }else{
        ans = 0;
    }
    return bool(ans);
}

bool Matrix::operator<(Matrix const &mat) {
    Matrix::checkMatSize(mat);
    int ans = 1;
    if(Matrix::matrixSum(mat)=="Smaller"){
        ans =  1;
    }else{
        ans = 0;
    }
    return bool(ans);
}
bool Matrix::operator<=(Matrix const &mat) {
    Matrix::checkMatSize(mat);
    string ans = Matrix::matrixSum(mat);
    int answer = 1;
    if(ans=="Even"||ans=="Smaller"){
        answer= 1;
    }else{
        answer = 0;
    }
    return bool(answer);
}

bool Matrix::operator==(Matrix const &mat) {
        Matrix::checkMatSize(mat);
    for (int i=0; i< this->col*this->row;i++){
        unsigned int pos = (unsigned int)(i);
        if(mat.mat.at(pos)!=this->mat.at(pos)){
            return false;
        }
    }
    return true;
}
bool Matrix::operator!=(Matrix const &mat) {
    Matrix::checkMatSize(mat);
    return !(Matrix::operator==(mat));
}
Matrix Matrix::operator*=(double num){
    for (int i=0; i< this->col*this->row;i++){
        unsigned int pos = (unsigned int)(i);
        if(this->mat.at(pos)!=0) {
            this->mat.at(pos) *= num;
        }
    }
    return (*this);
}

Matrix& Matrix::operator++(){
    for (size_t i = 0; i < this->col * this->row; i++) {
        this->mat.at(i)++;
    }
    return (*this);
}
Matrix Matrix::operator++(int){
    Matrix result(*this);
    ++(*this);
    return result;
}
Matrix& Matrix::operator--(){
    for (size_t i = 0; i < this->col * this->row; i++) {
        this->mat.at(i)--;
    }
    return (*this);
}
Matrix Matrix::operator--(int){
    Matrix result(*this);
    --(*this);
    return result;
}
Matrix Matrix::operator*(int num){
    Matrix result(*this);
    for(size_t i=0;i<this->col*this->row;i++){
        result.mat.at(i)*=num;
    }
    return result;
}
Matrix zich::operator*(int num,Matrix mat){
    for(size_t i=0;i<mat.col*mat.row;i++){
        mat.mat.at(i)*=num;
    }
    return mat;
}
Matrix zich::operator*(double num,Matrix mat){
    for(size_t i=0;i<mat.col*mat.row;i++){
        mat.mat.at(i)*=num;
    }
    return mat;
}
Matrix Matrix::operator*(double num){
    for(size_t i=0;i<this->col*this->row;i++){
        this->mat.at(i)*=num;
    }
    return (*this);
}
Matrix Matrix::operator*=(Matrix const & matrix) {
    if (this->col != matrix.row) {
        throw std::invalid_argument("col of left matrix should be equal to row of right");
    }
    vector<double> vec;
    for (size_t i = 0; i < this->row; ++i) {
        for (size_t j = 0; j < matrix.col; ++j) {
            double val = 0;
            for (size_t k = 0; k < this->col ; ++k) {
                val+= this->mat.at(i*size_t(this->col)+k)*matrix.mat.at(k*size_t(matrix.col)+j);
            }
            vec.push_back(val);
        }

    }
    this->mat=vec;
    this->col = matrix.col;
    return (*this);
}

    Matrix Matrix::operator*(const Matrix &mat) {
    Matrix result(*this);
    result*=mat;
    return result;
}
Matrix Matrix::operator-(Matrix const & mat) {
    Matrix::checkMatSize(mat);
    Matrix result(this->mat,this->row,this->col);
    for (size_t i = 0; i < mat.row*mat.col; ++i) {
        result.mat.at(i)-=mat.mat.at(i);
    }
    return result;
}
Matrix Matrix::operator-=(Matrix const & mat) {
    Matrix::checkMatSize(mat);
    for (size_t i = 0; i < mat.row*mat.col; ++i) {
        this->mat.at(i)-=mat.mat.at(i);
    }
    return (*this);
}
Matrix Matrix::operator+=(Matrix const & mat) {
    Matrix::checkMatSize(mat);
    for (size_t i = 0; i < mat.row*mat.col; ++i) {
        this->mat.at(i)+=mat.mat.at(i);
    }
    return (*this);
}
Matrix Matrix::operator-() {
    Matrix result(*this);
    for (size_t i=0; i< this->col*this->row;i++){
        if(result.mat.at(i)!=0) {
            result.mat.at(i) *= -1;
        }
    }
    return result;
}
Matrix Matrix::operator+() {
    Matrix result(*this);
    return result;
}
Matrix& Matrix::operator=(const Matrix & mat) {
    this->row = mat.row;
    this->col = mat.col;
    for (int i = 0; i < mat.row*mat.col; ++i) {
        unsigned int pos = (unsigned int)(i);
        this->mat.at(pos)=mat.mat.at(pos);
    }
    return (*this);
}
Matrix Matrix::operator+(Matrix const & mat) {
    Matrix::checkMatSize(mat);
    Matrix result(mat.mat,mat.row,mat.col);
    for (size_t i = 0; i < mat.row*mat.col; ++i) {
        result.mat.at(i)+=this->mat.at(i);
    }
    return result;
}

//bool isValid(vector<char> str){
//    for (size_t i = 0; i < str.size(); ++i) {
//        if(str.at(i)==']'){
//            if(i<str.size()-3){
//                if(str.at(i+1)!=','||str.at(i+2)!=' '||str.at(i+3)!='['){
//                    return false;
//                }
//            }
//        }
//    }
//}
istream& zich::operator >>(istream& in,Matrix &mat){
    vector<double> vec;
    int row=0;
    int rowLenght = 1;
    int counter = 1;
    char last=' ';
    char beforeLast=',';
    double number = 0;
    bool first = false;
    string tempNum;
    char temp = in.get();
    while(temp!='\n'){
        if(temp==' '){
            number= stod(tempNum);
            vec.push_back(number);
            tempNum="";
            counter++;
        }
        if(temp==','){
            row++;
            if(first&&rowLenght!=counter){
                throw invalid_argument("wrong input for matrix");
            }
            if(!first) {
                rowLenght = counter;
                first= true;
            }
            counter=0;

        }
            if(temp!='['&&temp!=']') {
                tempNum += temp;
            }
            temp = in.get();

        }
    mat.col=rowLenght;
    mat.row = row;
    mat.mat = vec;
    return in;
}
ostream& zich::operator <<(ostream& out,  Matrix const &mat){
    for (int i = 0; i < mat.row*mat.col; ++i) {
        unsigned int pos = (unsigned int)(i);
        if(mat.col==1) {
            out << "[" <<mat.mat.at(pos)<<"]"<<endl;
        }else
            if (i % mat.col == 0) {
                out << "[" << mat.mat.at(pos) << " ";
            } else {
                if ((i + 1) % mat.col == 0) {
                    if(i==mat.col*mat.row-1){
                        out << mat.mat.at(pos) << "]";
                    }else {
                        out << mat.mat.at(pos) << "]" << endl;
                    }
                } else {
                    out << mat.mat.at(pos) << " ";
                }
            }
        }

    return out;
}
