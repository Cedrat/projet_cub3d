EXEC=cub3D ;ARGS=./map/cub.cub;valgrind --tool=memcheck --leak-check=full --leak-resolution=high --show-reachable=yes --log-file=valgrind_log ./$EXEC $ARGS;grep -A1 "valgrind" valgrind_log|grep $EXEC
