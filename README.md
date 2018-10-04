# SerialNESolver
Serial Normal Equation Solver for linear regression using Gauss Elimination and Gauss Sidel methods
# Data Set
Housing data containing size in sq. ft., age, number of bedrooms, number of floors as attributes.
# File Description
main.cpp - Contains the main() function <br /><br />
transpose.cpp - Function to calculate matrix transpose <br /><br />
multiply.cpp - Calculates product of two matrices/matrix and vector <br /><br />
gaussElimination.cpp - Direct solver code <br /><br />
gaussSiedel.cpp - Iterative solver<br /><br />
A.txt - File containing the data set (independant variable values) <br /><br />
B.txt - File containing dependant variable values <br /><br />
# Result
Depending on the number of features f, we get a f-dimensional "theta" vector as the output. The linear regression model has hence been built and can be used to make predictions.
