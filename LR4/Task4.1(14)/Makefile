all: main main_test runTest
	
main: 
	gcc -o main main.c mylib.c -std=c89

main_test: 
	gcc -o main_test main_test.c mylib.c -std=c89 

runMain:
	./main

runTest:
	./main_test