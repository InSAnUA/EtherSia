html: doxygen
tags.xml: doxygen

examples.txt: ../examples/*/*.ino
	./generate-examples.pl > examples.txt

doxygen: examples.txt
	@doxygen Doxyfile
	@echo ""
	@echo "Done, error log follows:"
	@echo ""
	@cat doxygen.log

../keywords.txt: tags.xml
	./generate-keywords.pl $< > $@

clean:
	rm -rf html
	rm -f doxygen.log
	rm -f examples.txt

upload: doxygen
	rsync -avz -e ssh html/ njh@www.aelius.com:~/public_html/ethersia/

.PHONY: html doxygen clean upload
