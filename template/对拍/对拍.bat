g++ mkd.cpp -o mkd -g
g++ my.cpp -o my -g
g++ ok.cpp -o ok -g
:loop
	mkd.exe > data.txt
	my.exe < data.txt > myout.txt
	ok.exe < data.txt > answer.txt
	fc myout.txt answer.txt
if not errorlevel 1 goto loop
pause
goto loop