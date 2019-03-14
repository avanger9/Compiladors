if [ "$EUID" -ne 0 ]; then
	echo "Please run this script as root!"
	exit
fi

echo "    [1/3] Removing antlr4 directory ..."
rm -rf /usr/local/lib/ANTLR*/

echo "    [2/3] Removing libraries ..."
rm -rf /usr/local/include/antlr*-runtime
rm -rf /usr/local/lib/libantlr*-runtime*
rm -rf /usr/local/share/antlr*-demo
rm -rf /usr/local/share/doc/libantlr*/

echo "    [3/3] Removing antlr4 jar ..."
rm -rf /usr/local/lib/antlr-*.jar*

echo "Uninstall successful."
