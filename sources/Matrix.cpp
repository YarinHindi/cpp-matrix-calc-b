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

string Matrix::matrixSum(Matrix const & matrix)const {
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
bool Matrix::operator>=(Matrix const &mat) const{
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
bool Matrix::operator>(Matrix const &mat)const {
    Matrix::checkMatSize(mat);
    int ans = 1;
    if(Matrix::matrixSum(mat)=="Bigger"){
        ans = 1;
    }else{
        ans = 0;
    }
    return bool(ans);
}

bool Matrix::operator<(Matrix const &mat)const {
    Matrix::checkMatSize(mat);
    int ans = 1;
    if(Matrix::matrixSum(mat)=="Smaller"){
        ans =  1;
    }else{
        ans = 0;
    }
    return bool(ans);
}
bool Matrix::operator<=(Matrix const &mat)const {
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

bool Matrix::operator==(Matrix const &mat)const {
        Matrix::checkMatSize(mat);
    for (int i=0; i< this->col*this->row;i++){
        unsigned int pos = (unsigned int)(i);
        if(mat.mat.at(pos)!=this->mat.at(pos)){
            return false;
        }
    }
    return true;
}
bool Matrix::operator!=(Matrix const &mat)const{
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
Matrix Matrix::operator*(int num)const{
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
Matrix Matrix::operator*(double num)const{
    Matrix result(*this);
    for(size_t i=0;i<this->col*this->row;i++){
        result.mat.at(i)*=num;
    }
    return result;
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

    Matrix Matrix::operator*(const Matrix &mat)const {
    Matrix result(*this);
    result*=mat;
    return result;
}
Matrix Matrix::operator-(Matrix const & mat) const{
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
Matrix Matrix::operator-()const{
    Matrix result(*this);
    for (size_t i=0; i< this->col*this->row;i++){
        if(result.mat.at(i)!=0) {
            result.mat.at(i) *= -1;
        }
    }
    return result;
}
Matrix Matrix::operator+()const{
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
Matrix Matrix::operator+(Matrix const & mat)const {
    Matrix::checkMatSize(mat);
    Matrix result(mat.mat,mat.row,mat.col);
    for (size_t i = 0; i < mat.row*mat.col; ++i) {
        result.mat.at(i)+=this->mat.at(i);
    }
    return result;
}
bool Matrix::isNumber(string const& str){
    int counter = 0;
    char ch=' ';
    for (size_t i = 0; i < str.length(); ++i) {
        ch = str.at(i);
        cout<<ch;
        if(ch=='.'&&i==0){
            return false;
        }
        if(ch<'0'||ch>'9'){
            if(ch!='.') {
                return false;
            }
        }
        if(ch=='.'){
            counter++;
        }
        if(counter==2){
            return false;
        }
    }
    return true;
}
void Matrix::throwFunction(){
    throw invalid_argument("wrong input for matrix >> operator");
}

istream& zich::operator >>(istream& in,Matrix  &mat) {
    vector<double> vec;
    int row = 0;
    int rowLenght = 0;
    int counter = 0;
    double number = 0;
    bool b = false;
    bool first = false;
    string tempNum;
    char temp = in.get();
    while (temp != '\n') {
        if(!b&&temp!='['){
            Matrix::throwFunction();
        }
        if(temp=='['){
            temp= in.get();
            if(temp<'0'||temp>'9'){
                Matrix::throwFunction();
            }
        }
        if(temp==' '){
            if(!(Matrix::isNumber(tempNum))){
                Matrix::throwFunction();
            }
            cout<<tempNum<<"this is the current number"<<endl;
            number = stod(tempNum);
            vec.push_back(number);
            tempNum="";
            temp =in.get();
            counter++;
        }
        if(temp==']') {
            if(!Matrix::isNumber(tempNum)){
                Matrix::throwFunction();
            }
            cout<<tempNum<<"this is the current number"<<endl;
            number = stod(tempNum);
            vec.push_back(number);
            tempNum = "";
            row++;
            counter++;
            if (first && rowLenght != counter) {
                Matrix::throwFunction();
            }
            if (!first) {
                rowLenght = counter;
                first = true;
            }
            counter = 0;
            temp = in.get();
            if (temp == '\n') {
                break;
            }
            if (temp != ',') {
                Matrix::throwFunction();
            }
            temp = in.get();
            if (temp != ' ') {
                Matrix::throwFunction();
            }
            temp = in.get();
            if(temp!='['){
                Matrix::throwFunction();
            }
            temp = in.get();
        }
        b= true;
        tempNum += temp;
        temp= in.get();

    }
    if(row ==0|| rowLenght==0){
        Matrix::throwFunction();
    }
        mat.col=rowLenght;
        mat.row = row;
        mat.mat = vec;
        return in;
}

ostream& zich::operator <<(ostream& out,  Matrix const &matrix) {
    for (size_t i = 0; i < matrix.row; ++i) {
        out << '[';
        for (size_t j = 0; j < matrix.col; ++j) {
            if (j == 0) {
                out << matrix.mat.at(i*size_t(matrix.col)+j);
            } else {
                out << " " << matrix.mat.at(i*size_t(matrix.col)+j);
            }
        }
        if(i ==matrix.row-1) {
            out <<"]";
        }else{
            out <<"]"<<endl;
        }
    }
    return out;
}
