import zmq
import random
import string

ctx = zmq.Context.instance()
sock = ctx.socket(zmq.PUSH)
sock.connect("tcp://localhost:9997")

for x in range(20):
    sock.send_multipart(['\x00\x00\x00\x00',''.join(random.choice(string.ascii_uppercase + string.digits) for x in range(10))])
