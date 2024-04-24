#!/usr/bin/node

// Include module
const request = require('request');

// use process to store argv in command line
const args = process.argv;
if (args.length !== 3 || isNaN(parseInt(args[2]))) {
    console.error('Usage: ./script.js <movie_id>');
    process.exit(1);
}
// construct request url by adding id film
const movieId = parseInt(args[2]);
const URL = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

// print all characters of one episode in rigth order
request.get(URL, (err, response, body) => {
    if (err) {
      console.error('error', err);
      process.exit(1);
    } 
    if (response.statusCode !== 200) {
        console.error(`HTTP Error: ${response.statusCode} - ${response.statusMessage}`);
        process.exit(1);
    }
    
    const characters = JSON.parse(body).characters;
    const promises = characters.map(characterUrl => {
        return new Promise((resolve, reject) => {
            request.get(characterUrl, (err, response, body) => {
                if (err) {
                    reject(err);
                } else {
                    resolve(JSON.parse(body).name);
                }
            });
        });
    });

    Promise.all(promises)
        .then(names => {
            names.forEach(name => console.log(name));
        })
        .catch(err => {
            console.error('Error:', err);
            process.exit(1);
        });
});