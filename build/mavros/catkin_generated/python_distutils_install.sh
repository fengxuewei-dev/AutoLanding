#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/mavros/mavros"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/install/lib/python2.7/dist-packages:/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/mavros/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/mavros" \
    "/usr/bin/python2" \
    "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/mavros/mavros/setup.py" \
     \
    build --build-base "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/mavros" \
    install \
    --root="${DESTDIR-/}" \
    --install-layout=deb --prefix="/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/install" --install-scripts="/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/install/bin"
