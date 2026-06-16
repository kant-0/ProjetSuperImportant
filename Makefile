
.PHONY: all clean
all:
	make -C sim
	./sim/out
	mv data.json web/data.json
	cd web
	python3 -m http.server 3000 & \
	xdg-open http://localhost:3000/web

clean:
	make -C sim clean
