Here are some data to make parameter files in this directory.  Using
one same pesudorandom number generator for generating multiple independent
streams by changing the initial values may cause a problem (with
negligibly small probability). To avoid the problem, using
diffrent parameters for each generation is prefered. See Matsumoto
and Nishimura [1] for detailed information.

Here we put some csv files for parameters of SFMT
giving several different period length. For each period,
we list 32 distinct sets of parameters.

You can make parameter files from csv files using scv2params.awk

./csv2param.awk line-no csv-filename > parameter-file

Here, line-no is a number of range 1 to 32 which specifies the line no
of csv file.

[1] Makoto Matsumoto and Takuji Nishimura,
    "Dynamic Creation of Pseudorandom Number Generators",
     Monte Carlo and Quasi-Monte Carlo Methods 1998, Springer, 2000, pp 56--69.
     http://www.math.sci.hiroshima-u.ac.jp/~m-mat/MT/ARTICLES/articles.html
