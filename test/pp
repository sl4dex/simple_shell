#!/usr/bin/env bash

touch /var/run/myscript.pid
echo $$ > /var/run/myscript.pid
while true
do
	echo "te tengo aca putito"
	trap 'echo "no me voy"' SIGINT
	trap 'echo "no me voy"' SIGTERM
	trap 'echo "no me voy"' SIGQUIT
done
