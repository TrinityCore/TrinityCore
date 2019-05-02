このディレクトリにはパラメータファイルを生成するデータが置いてあります。
擬似乱数をいくつか並列に生成する場合、同一のパラメータを使用し、初期値
だけを変えるという方法には（無視出来る程低い確率ですが）問題があり、そ
の問題を避けるために、異なるパラメータを使用することが推奨されています。
詳しくは松本・西村による[1]の論文を参照してください。

[1]では、パラメータを動的に求めますが、ここではいくつかの周期に対して、
計算済みの32個のパラメータを提供します。

csv2param.awk を使うことによって、csvファイルからパラメータファイルを作
ることができます。

./csv2param.awk line-no csv-filename > parameter-file

ここで、line-no はcsvファイルの行を指定する1から32までの数です。

[1] Makoto Matsumoto and Takuji Nishimura, 
    "Dynamic Creation of Pseudorandom Number Generators",
     Monte Carlo and Quasi-Monte Carlo Methods 1998, Springer, 2000, pp 56--69.
     http://www.math.sci.hiroshima-u.ac.jp/~m-mat/MT/ARTICLES/articles.html	
