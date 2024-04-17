rm ./db

./a.out ./db insert Samarsky YV m 9 - 89 88 90 93 +
./a.out ./db insert Olegov OO m 134 + 11 15 20 14 +
./a.out ./db insert Abobina BC f -4 + 100 100 100 100 -
./a.out ./db insert Babulkin TR o 1 - 2 3 4 5 -
./a.out ./db insert Churchhella VK f 16 - 79 80 100 101 +

echo ""
echo "All"
./a.out ./db select-all

echo ""
echo "Sum 360"
./a.out ./db select-where-score-eq 360

echo ""
echo "Sum 61"
./a.out ./db select-where-score-eq 61

echo ""
echo "Sum 60"
./a.out ./db select-where-score-eq 60