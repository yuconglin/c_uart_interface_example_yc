all: mavlink_serial send_quad_commands send_adsb_msg test_adsb_msg

mavlink_serial: mavlink_serial.o
	g++ mavlink_serial.o -o mavlink_serial

mavlink_serial.o: mavlink_serial.cpp
	g++ -I mavlink/include/mavlink/v1.0 -c mavlink_serial.cpp

send_quad_commands: send_quad_commands.o
	g++ send_quad_commands.o -o send_quad_commands

send_quad_commands.o: send_quad_commands.cpp
	g++ -I mavlink/include/mavlink/v1.0 -c send_quad_commands.cpp

send_adsb_msg: send_adsb_msg.o
	g++ send_adsb_msg.o -o send_adsb_msg

send_adsb_msg.o: send_adsb_msg.cpp
	g++ -I mavlink/include/mavlink/v1.0 -c send_adsb_msg.cpp

test_adsb_msg: test_adsb_msg.o
	g++ test_adsb_msg.o -o test_adsb_msg

test_adsb_msg.o: test_adsb_msg.cpp
	g++ -I mavlink/include/mavlink/v1.0 -c test_adsb_msg.cpp

clean:
	rm -rf *o mavlink_serial send_quad_commands send_adsb_msg test_adsb_msg
