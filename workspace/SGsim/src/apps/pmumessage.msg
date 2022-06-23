packet pmumessage
{
    string pmuID;
    double timeStep;
	unsigned char data_frm[1024];
	int pmusize;
	simtime_t ctime;
    int source;
    int destination;
	int hops=0;
}

