
.PHONY: all clean server
all:
	make -C sim
	./sim/out
	mv data.json web/data.json
	xdg-open http://localhost:3000/web
	python3 -m http.server 3000

server:
    xdg-open http://localhost:3000/web
	python3 -m http.server 3000

clean:
	rm sim/out
	rm web/data.json
