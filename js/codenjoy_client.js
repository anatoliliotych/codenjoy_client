var log = function(string) {
    console.log(string);
};

// Codenjoy server host ip
var hostIp = '127.0.0.1';
var port = 8080;

// Your username
var userName = 'anatoliliotych';
var gameUrl = 'codenjoy-contest/ws?'

var ws_url = 'ws://' + hostIp + ':' + port + '/' + gameUrl + 'user=' + userName;
var WebSocket = require('ws');
var ws = new WebSocket(ws_url)

ws.on('open', function() {
  log('Opened');
});

ws.on('close', function() {
  log('Closed');
});

ws.on('message', function(message) {
  log('received: ' + message);

  var result = answer(message);
  log("submitted: " + result);

  ws.send(result);
});

// The method which will be used to send commands to Codenjoy server
function answer(msg) {
	return "right=1";// Please specify your command
}

