
.PHONY: all clean
all:
	make -C sim
	./sim/out
	mv data.json web/data.json
	cd web
	xdg-open http://localhost:3000/web
	python3 -m http.server 3000

clean:
	rm sim/out
	rm web/data.json
