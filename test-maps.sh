make re
for file in maps/*.fdf
do
	echo $file
	./fdf $file
done
clear
