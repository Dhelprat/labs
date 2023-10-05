#!/bin/bash

mkdir cats
cd cats
touch names.txt
echo "cats and names.txt successfully created!"

echo "cat
cat
dog
parrot
cat" > names.txt

echo "open names.txt..."
cat names.txt -n
echo "here's the number of lines, words and chars:"
wc -l -w -c names.txt

cd ..
mkdir new_cats
mv cats/names.txt new_cats
echo "names.txt moved to new_cats"

rm -r cats
echo "cats removed"

cd new_cats
echo "count of cats in names.txt:"
grep "cat" -c names.txt

echo "downloading cute cat..."
wget https://images.satu.kz/162448773_w640_h640_tovary-dlya-koshek.jpg
echo "cat's here! You can look at it"

exit 0
