all:clean test_netstat

test_netstat:
	gcc test_net_stat.c ../../util/netstat.c -Wall -g -DNDEBUG -o test_net_stat

clean:
	rm -rf test_net_stat
