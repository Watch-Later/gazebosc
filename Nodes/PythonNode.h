#ifndef PYTHONNODE_H
#define PYTHONNODE_H

#include <string>
#include "GNode.h"
#include "Python.h"

void python_init();

class PythonNode : public GNode
{
public:
    explicit PythonNode(const char* uuid) : GNode(   "PythonNode",              // title
                                                          { {"OSC", NodeSlotOSC} },       // Input slots
                                                          { {"OSC", NodeSlotOSC} },       // Output slots
                                                            uuid )                        // uuid pass-through
    {

    }

    int UpdatePythonFile();

    void ActorInit( const sphactor_node_t *node );
    zmsg_t *ActorMessage( sphactor_event_t *ev );
    //zmsg_t *ActorCallback( );
    //void ActorStop(const sphactor_node_t *node);

    std::string filename = "tester";
    PyObject *pClassInstance;

    const char *py_template = "#!/usr/bin/env python3\n"
            "import sph\n"
            "from pythonosc import osc_message_builder\n"
            "\n"
            "class <FILENAME>(object):\n"
            "\n"
            "    def handleMsg(self, msg, type, name, uuid):\n"
            "        #  Handle the received msg"
            "        return msg\n"
            "\n";
};

#endif // PYTHONNODE_H
