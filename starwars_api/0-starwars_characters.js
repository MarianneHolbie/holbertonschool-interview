#!/usr/bin/node

// Include module
const process = require('process');
const request = require('request');

// use process to store argv in command line
const args = process.argv;
// construct request url by adding id film
const URL = 'https://swapi-api.hbtn.io/api/films/' + args[2];

// print all characters of one episode in rigth order
request.get(URL, (err, response, body) => {
    if (err) {
      console.error('error', err);
    } else {
      // stock all url of characters
      const char = JSON.parse(body).characters;
  
      for (let i = 0; i < char.length; i++) {
        request.get(char[i], (err, response, body) => {
          if (err) {
            console.error('error', err);
          } else {
            console.log(JSON.parse(body).name);
          }
        });
      }
    }
  });