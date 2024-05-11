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
    c.rows = a.rows;
    c.cols = b.cols;

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
   c.rows = a.rows;
   c.cols = a.cols;

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
    Matrix c;
    c.rows = a.cols;
    c.cols = a.rows;
    
    /**
     * @brief 矩阵转置
    */
    for (int i = 0; i < c.rows; i++)
    {
        for (int j = 0; j < c.cols; j++)
        {
            c.data[i][j] = a.data[j][i];
        }
    }

    return c;
}

double det_matrix(Matrix a)
{
    /**
     * @brief 错误提示
    */
   if (a.rows != a.cols)
   {
        printf("Error: The matrix must be a square matrix.");
        return 0;
   }

    Matrix c; // 代数余子式
    int n = a.rows; // 矩阵阶数
    int det = 0; // 行列式的值

    c.rows = c.cols = n-1;

   if (n > 2)
   {
        for (int i = 0; i < n; i++) // 行循环
        {
            for (int j = 0; j < n; j++) // 列循环
            {
                det += cofactor_matrix(a, i, j);
            }
        }
   }
   else if (n = 2)
   {
        return a.data[0][0] * a.data[1][1] - a.data[0][1] * a.data[1][0];
   }
   else
   {
        return a.data[0][0];
   }

   return det;
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
    /**
     * @brief 错误提示
    */
   if (a.rows != a.cols)
   {
        printf("Error: The matrix must be a square matrix.");
        return 0;
   }

   int trace = 0; //矩阵的迹

   for (int i = 0; i < a.rows; i++)
   {
        trace += a.data[i][i];
   }

   return trace;
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

int cofactor_matrix(Matrix a, int i, int j)
{
    Matrix c; // a的余子式
    int n = a.rows - 1; // c的阶数
    int flag; // 系数正负

    /**
     * @brief 判断系数正负
    */
    if ((i+j)%2 == 1)
    {
        flag = -1;
    }
    else
    {
        flag = 1;
    }

    c.rows = a.rows - 1;
    c.cols = a.cols - 1;

    /**
     * @brief 求余子式
    */
    for (int z = 0; z < n && z != i; z++) // 行循环
    {
        for (int y = 0; y < n && y != j; y++) // 列循环
        {
            int z1 = z - (z > i); // c对应行
            int y1 = y - (y > j); // c对应列

            c.data[z1][y1] = a.data[z][y];
        }
    }

    return flag*det_matrix(c);
}