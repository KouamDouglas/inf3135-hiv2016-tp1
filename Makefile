ECHO = echo
tp1:	 *.c
	@$(ECHO) Compilation de l\'executable du programme
	 gcc -Wall tp1.c -o tp1
clean:	
	@$(ECHO) Suppression de l\'executable du programme
	rm -f tp1
	rm -f tp1.o
	
database:
	curl http://download.geonames.org/export/dump/countryInfo.txt > countryInfo.txt 
	curl http://download.geonames.org/export/dump/cities15000o.zip > citiecities15000.zip 
	unzip cities15000.zip
