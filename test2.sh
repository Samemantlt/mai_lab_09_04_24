rm ./db

./a.out ./db insert Samarsky YV m 9 - 89 88 90 93 +
./a.out ./db insert Olegov OO m 134 + 11 15 20 14 +
./a.out ./db insert Churchhella VK f 16 - 79 80 100 101 +

# ./a.out ./db select-all

./a.out ./db select-where-score-eq 360