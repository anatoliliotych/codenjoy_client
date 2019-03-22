# encoding: utf-8

require 'faye/websocket'
require 'eventmachine'
require File.expand_path('../player', __FILE__)

host_ip = '127.0.0.1' # ip of host with running tetris-server
port = '8080' # this port is used for communication between your client and tetris-server
user_id = 'bn8vtogio4cp05s5o5ql' # from url after registration
code = '789585278044203241' # from url after registration

url = "ws://#{host_ip}:#{port}/codenjoy-contest/ws?user=#{user_id}&code=#{code}"

player = Player.new
EM.run do
  ws = Faye::WebSocket::Client.new(url)
  ws.on :message do |event|
    p [:message, event.data]
    player.process_data(event.data)
    ws.send(player.make_step)
  end
end
