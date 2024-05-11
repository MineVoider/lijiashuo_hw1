#include "algebra.h"
#include <stdio.h>
#include <math.h>

Matrix create_matrix(int row, int col)
{
    Matrix m;
    m.rows = row;
    m.cols = col;
    return m;
}

Matrix add_matrix(Matrix a, Matrix b)
{
    /**
     * @brief 错误提示
    */
    if (a.rows != b.rows || a.cols != b.cols)
    {
        printf("Error: Matrix a and b must have the same rows and cols.");
        return create_matrix(0,0);
    }

    Matrix c;
    int row = a.rows; // 矩阵的行数
    int col = a.cols; // 矩阵的列数

    c.rows = row;
    c.cols = col;

    /**
     * @brief 矩阵加法
    */
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            c.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }
    
    return c;
}

Matrix sub_matrix(Matrix a, Matrix b)
{
    /**
     * @brief 错误提示
    */
    if (a.rows != b.rows || a.cols != b.cols)
    {
        printf("Error: Matrix a and b must have the same rows and cols.");
        return create_matrix(0,0);
    }
    
    Matrix c;
    int row = a.rows; // 矩阵的行数
    int col = a.cols; // 矩阵的列数

    c.rows = row;
    c.cols = col;

    /**
     * @brief 矩阵减法
    */
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            c.data[i][j] = a.data[i][j] - b.data[i][j];
        }
    }

    return c;
}

Matrix mul_matrix(Matrix a, Matrix b)
{
    /**
     * @brief 错误提示
    */
    if (a.cols != b.rows)
    {
        printf("Error: The number of cols of matrix a must be equal to the number of rows of matrix b.");
        return create_matrix(0,0);
    }

    Matrix c={};
    c.rows = a.rows; // c的行数
    c.cols = b.cols; // c的列数

    /**
     * @brief 矩阵乘法
    */
    for (int i = 0; i < c.rows; i++)
    {
        for (int j = 0; j < c.cols; j++)
        {
            for (int k = 0; k < a.cols; k++)
            {
                c.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }

    return c;
}

Matrix scale_matrix(Matrix a, double k)
{
   Matrix c;
   c.rows = a.rows; //c的行数
   c.cols = a.cols; //c的列数

    /**
     * @brief 矩阵数乘
    */
   for (int i = 0; i < c.rows; i++)
   {
        for (int j = 0; j < c.cols; j++)
        {
            c.data[i][j] = k * a.data[i][j];
        }
   }

   return c;
}

Matrix transpose_matrix(Matrix a)
{
    // ToDo
    return create_matrix(0, 0);
}

double det_matrix(Matrix a)
{
    // ToDo
    return 0;
}

Matrix inv_matrix(Matrix a)
{
    // ToDo
    return create_matrix(0, 0);
}

int rank_matrix(Matrix a)
{
    // ToDo
    return 0;
}

double trace_matrix(Matrix a)
{
    // ToDo
    return 0;
}

void print_matrix(Matrix a)
{
    for (int i = 0; i < a.rows; i++)
    {
        for (int j = 0; j < a.cols; j++)
        {
            // 按行打印，每个元素占8个字符的宽度，小数点后保留2位，左对齐
            printf("%-8.2f", a.data[i][j]);
        }
        printf("\n");
    }
}