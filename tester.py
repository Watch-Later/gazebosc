import sph

# pip install python-osc
from pythonosc import osc_message_builder

class tester(object):

    def handleMsg(self, msg, type, name, uuid, *args, **kwargs):
        print(self, msg, type, name, uuid, args, kwargs)
        # just pop the first string and return the rest
        if msg.size() > 0:
            t = msg.popstr()
            print("Message received: {}".format(t) )
            #return msg
            msg = osc_message_builder.OscMessageBuilder(address="/Hello")
            msg.add_arg("hello from python")
            osc = msg.build()
            return osc.dgram
        else:
            return None
        # construct new zmsg
        # c = sph.PyZmsg()
        #frame = Zframe(b"Hello", 5)
        #msg.prepend(frame)
        #c.addstr("Hello");
        #return c

