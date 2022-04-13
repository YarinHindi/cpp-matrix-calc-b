#include "doctest.h"
#include "Matrix.hpp"
#include <ctime>
#include <ostream>
#include <sstream>

using namespace zich;
using namespace std;

TEST_CASE("Test Matrix constructor and methods on valid matrix for small matrix"){
    vector<double> vec1 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    Matrix matrix1(vec1,3,4);
    Matrix matrix2(vec1,4,3);
    CHECK_THROWS(matrix1*matrix1);
    Matrix matrix3 = -matrix2;
    CHECK_THROWS(matrix1+matrix2);
    CHECK_THROWS(bool ans = (matrix1==matrix2));
    CHECK_NOTHROW(3.7*matrix1);
    CHECK_NOTHROW(matrix1+matrix1+matrix1);
    Matrix matrix4 = matrix3+matrix2;
}
TEST_CASE("generate bigger matrix and test out put"){
    srand(time(0));
    vector<double> vec2;
    vector<int> dvided;
    int counter = 0;
    int size;
    int size_counter;
    bool end = false;
    for (int i=0; i<1000;i++){
        size = 1+rand()%1000;
        counter = 0;
        vec2.clear();
        dvided.clear();
        for (int j = 0; j < size; ++j) {
            vec2.push_back(rand() % 10000 - rand() % 10000);
            if (j > 0) {
                if (size % j == 0) {
                    int div = size / j;
                    dvided.push_back(div);
                    counter++;
                }
            }
        }
        if(counter>0){
            int pos = rand()%counter;
            unsigned int rpos = (unsigned int)(pos);
            int rows = dvided.at(rpos);
            int cols = size / rows;
            Matrix bigmat(vec2, rows, cols);
            Matrix bigmat2 = bigmat+bigmat;
            bool equ = (bigmat2==2*bigmat);
            CHECK_NOTHROW(-bigmat);
            CHECK_NOTHROW(bigmat+bigmat);
            CHECK(equ== true);
        }

    }
}

TEST_CASE("multiply  matrix and more operators check"){
    vector<double> unitMulBy2 = {2, 0, 0, 0, 2, 0, 0, 0, 2};
    Matrix unitMatrixMulBy2(unitMulBy2,3,3);
    int byTwo =2;
    for (int i = 0; i <15; ++i) {
        bool bol =unitMatrixMulBy2*unitMatrixMulBy2==byTwo*unitMatrixMulBy2;
        CHECK(bol==true);
        CHECK_NOTHROW(unitMatrixMulBy2*=2);
        byTwo*=2;
    }
    Matrix rowVector(unitMulBy2,9,1);
    Matrix colVector(unitMulBy2,1,9);
    CHECK_NOTHROW(rowVector*colVector);
    CHECK_NOTHROW(colVector*rowVector);
    CHECK_NOTHROW(++rowVector);
    CHECK_THROWS(bool bol1 =rowVector<colVector);
    CHECK_THROWS(bool bol2 =rowVector<colVector);
    CHECK_THROWS(bool bol3 =rowVector<=colVector);
    CHECK_THROWS(bool bol4 =rowVector>=colVector);
    CHECK_THROWS(bool bol5 =rowVector==colVector);

}
TEST_CASE("- unari operator"){
    vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix matrix1{vec1, 3, 3};
    Matrix check1 = -matrix1;
    CHECK_NE(matrix1 == check1, true);
    matrix1 *= -1;
    CHECK_EQ(matrix1 == check1, true);
    vector<double> vec2 = {-1, 1, 2, -3, -4, 10, 1, 7};
    Matrix matrix2{vec2,2,4};
    Matrix check2 = -matrix2;
    CHECK_NE(matrix2 == check2, true);
    matrix2 *= -1;
    CHECK_EQ(matrix2 == check2, true);
}
TEST_CASE("++ after Matrix operator"){
    vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix matrix1{vec1, 3, 3};
    Matrix mat_check = (++matrix1)++;
    vector<double> ans_vec1 = {3, 2, 2, 2, 3, 2, 2, 2, 3};
    vector<double> check_vec = {2, 1, 1, 1, 2, 1, 1, 1, 2};
    Matrix ans1{ans_vec1,3,3};
    Matrix check_ans{check_vec, 3, 3};
    CHECK_EQ(matrix1 == ans1, true);
    CHECK_EQ(mat_check == check_ans, true);
    vector<double> vec2 = {-1, 0, 0, 0, -1, 0, 0, 0, -1};
    Matrix matrix2{vec2,3,3};
    ++matrix2;
    vector<double> ans_vec2 = {0, 1, 1, 1, 0, 1, 1, 1, 0};
    Matrix ans2{ans_vec2,3,3};
    CHECK_EQ(matrix2 == ans2, true);
    vector<double> vec3 = {-1, 1, 1, 1, -1, 1, 1, 1, -1};
    Matrix matrix3{vec3,3,3};
    Matrix matrix4 = matrix3;
    ++(++matrix3);
    vector<double> ans_vec3 = {1, 3, 3, 3, 1, 3, 3, 3, 1};
    Matrix ans3{ans_vec3,3,3};
    CHECK_EQ(matrix3 == ans3, true);
    CHECK_NE(matrix3 == matrix4, true);
}
TEST_CASE("++ before Matrix operator") {
    vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix matrix1{vec1, 3, 3};
    Matrix mat_check = (++matrix1)++;
    vector<double> ans_vec1 = {3, 2, 2, 2, 3, 2, 2, 2, 3};
    vector<double> check_vec = {2, 1, 1, 1, 2, 1, 1, 1, 2};
    Matrix ans1{ans_vec1, 3, 3};
    Matrix check_ans{check_vec, 3, 3};
    CHECK_EQ(matrix1 == ans1, true);
    CHECK_EQ(mat_check == check_ans, true);
    vector<double> vec2 = {-1, 0, 0, 0, -1, 0, 0, 0, -1};
    Matrix matrix2{vec2, 3, 3};
    ++matrix2;
    vector<double> ans_vec2 = {0, 1, 1, 1, 0, 1, 1, 1, 0};
    Matrix ans2{ans_vec2, 3, 3};
    CHECK_EQ(matrix2 == ans2, true);

}
TEST_CASE("matrix * matrix operator: bad")
{
vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0};
Matrix matrix1{vec1, 2, 5};
Matrix matrix2{ vec1, 1, 10};
CHECK_THROWS(matrix1 * matrix1);
CHECK_THROWS(matrix2 * matrix2);
CHECK_THROWS(matrix1 * matrix2);
CHECK_THROWS(matrix2 * matrix1);
vector<double> vec2 = {1, 0, 0, 1, 0, 1, 1, 0};
Matrix matrix3{vec2, 2, 4};
Matrix matrix4{vec2, 8, 1};
CHECK_THROWS(matrix1 * matrix3);
CHECK_THROWS(matrix3 * matrix2);
CHECK_THROWS(matrix3 * matrix4);
CHECK_THROWS(matrix4 * matrix3);
}

TEST_CASE("Output operator")
{
    vector<double> vec1 = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
    vector<double> vec2 = {6, 5, 4, 3, 2, 1};
    vector<double> vec3 = {2, 0, 2, 0};
    stringstream stream;
    stream << Matrix(vec1, 4, 4);
            CHECK(stream.str() == "[1 0 0 0]\n[0 1 0 0]\n[0 0 1 0]\n[0 0 0 1]");
    stream.str(std::string());
    stream << Matrix(vec1, 2, 8);
            CHECK(stream.str() == "[1 0 0 0 0 1 0 0]\n[0 0 1 0 0 0 0 1]");
    stream.str(std::string());
    stream << Matrix(vec1, 16, 1);
            CHECK(stream.str() == "[1]\n[0]\n[0]\n[0]\n[0]\n[1]\n[0]\n[0]\n[0]\n[0]\n[1]\n[0]\n[0]\n[0]\n[0]\n[1]");
    stream.str(std::string());
}