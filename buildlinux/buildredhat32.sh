#!/bin/bash
# Run this script from the buildlinux folder to build a debian/ubuntu package
qmake DEFINES+="Q_OS_REDHAT" ../src
make
cp safejumper/safejumper linuxfiles
cp launchopenvpn/launchopenvpn linuxfiles
cp netdown/netdown linuxfiles
cp openvpn32 linuxfiles/openvpn

# Then the content of linuxfiles mostly goes into /opt/safejumper/.

# To package debian/ubuntu do the following:

tar --transform "s/^linuxfiles/safejumper-$1/" -zcpvf ~/rpmbuild/SOURCES/safejumper-$1.tar.gz linuxfiles
rpmbuild -ba -v --target=i686 ./safejumper.spec
