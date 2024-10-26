<h1>Numerical Methods Assignment</h1>

<p>This repository contains a console application implementing various Numerical Methods. The project was developed by a group of three members, focusing on the solution of linear and non-linear equations, solving differential equations, and matrix inversion. The methods are implemented in C++.</p>
<h2>Group - 2 members are <ul><li>Al Shariar Hossain - 2107066</li><li>Shaila Aktar - 2107084</li><li>Abir Mahmud - 2107049</li></ul></h2>

<p>The motive of the project is to  solve Numerical problems</p>

<h2>Solution of Linear Equations</h2>
<ol><h3><li>Jacobi Iteration Method:</li></h3><p>The Jacobi Iteration Method is an algorithm for solving a system of linear equations of the form AX=B, where A is the coefficient matrix, 𝑋 is the vector of variables, and B is the constants vector. It is an iterative method, meaning it starts with an initial guess for the solution and improves the guess in each iteration.</p><p>The method starts with an initial guess for the solution vector. In each iteration, the new value of each variable Xi is computed using the old values of the other variables from the previous iteration. The process continues until the change between successive iterations is smaller than a predefined tolerance level, indicating that the solution has converged.The Jacobi method converges if the matrix A is diagonally dominant, meaning that for each row, the absolute value of the diagonal element is greater than the sum of the absolute values of the other elements in that row.</p><h3><li>Gauss-Seidel Iteration Method:</li></h3><p>The Gauss-Seidel Iteration Method is an iterative technique for solving a system of linear equations of the form AX = B. It improves upon the Jacobi method by using the most recent updated values of the unknowns during the same iteration, rather than waiting for the next iteration.Start with an initial guess for the unknown variables.Repeat the process until the values converge, meaning the change between successive iterations is within a defined tolerance which is known as convergence</p><h3><li>Gaussian Elimination:</li></h3><p>Gaussian Elimination is a method for solving systems of linear equations by transforming the system's augmented matrix into an upper triangular form, where all elements below the main diagonal are zero. The process consists of two main steps 1. Forward Elimination 2. Backward Substitution and solve the required solution</p><h3><li>Gauss-Jordan Elimination:</li></h3><p>Converts the system into reduced row echelon form for direct solutions.It produces reduced row echelon form by using Forward and backward Elimination</p><h3><li>LU Factorization:</li></h3><p>LU Factorization decomposes a matrix into lower and upper triangular matrices to simplify solving linear systems.</p></ol>
<h2>Solution of Non-linear Equations</h2>
<ol><h3><li>Bisection Method:</li></h3><p>Bisection Method finds roots by repeatedly halving an interval.</p><h3><li>False Position Method:</li></h3><p>A refinement of the bisection method using the secant line to approximate the root.</p><h3><li>Secant Method:</li></h3><p>This methods approximates roots by using two previous points without needing derivatives</p><h3><li>Newton-Raphson Method:</li></h3><p>Newton- Raphson Method is an efficient method using function derivatives to find roots rapidly.</p></ol>
<h2>Solution of Differential Equations</h2>
<ol><h3><li>Runge-Kutta Method:</li></h3><p>A numerical method to solve ordinary differential equations (ODEs), particularly useful for initial value problems.</p></ol>
<h2>Matrix Inversion</h2>
<p>Matrix Inversion generally implements matrix inversion using Gauss-Jordan elimination by augmenting the matrix with the identity matrix.</p>
<h2>How to use</h2> 

```bash
Cloning:
git clone https://github.com/alshariarmithu/Numerical-Methods-Assignment.git
Run:
g++ main.cpp -o numerical_methods
./numerical_methods






