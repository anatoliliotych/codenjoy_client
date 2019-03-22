from player import Player
from codenjoy_connection import CodenjoyConnection


try:
    user_id = 'bn8vtogio4cp05s5o5ql' # name which was used during registration
    code = '789585278044203241'
    port = '8080' # game port
    host = 'localhost' # game host
    game_url = 'codenjoy-contest/ws?' # game url

    url = "ws://{0}:{1}/{2}user={3}&code={4}".format(host, port, game_url, user_id, code)
    player = Player()
    ws = CodenjoyConnection(url, player)
    ws.connect()
    ws.run_forever()
except KeyboardInterrupt:
    ws.close()
