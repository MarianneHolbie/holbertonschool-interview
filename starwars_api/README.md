# StarWars API

## Requierements

* Node 10
```bash
$ curl -sL https://deb.nodesource.com/setup_10.x | sudo -E bash -
$ sudo apt-get install -y nodejs
```

* Semi-standard
```bash
$ sudo npm install semistandard --global
```

* request
```bash
$ sudo npm install request --global
$ export NODE_PATH=/usr/lib/node_modules
```

## TASKS
Write a script that prints all characters of a Star Wars movie:

* The first positional argument passed is the Movie ID - example: 3 = “Return of the Jedi”
* Display one character name per line **in the same order as the “characters” list in the `/films/` endpoint**
* You must use the Star wars API
* You must use the `request` module
