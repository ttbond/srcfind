if [ -f "a.out" ]; then
	rm a.out
fi
g++ -lcrypt  main.cpp
if [ -f "a.out" ]; then
	./a.out
else
	echo "compile error"
fi
