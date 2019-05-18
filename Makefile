json : JsonParser.c
	gcc -o json JsonParser.c

clean :
	rm -rf json
