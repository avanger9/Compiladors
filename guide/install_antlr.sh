if [ "$EUID" -ne 0 ]; then 
	echo "Please run this script as root!"
	exit
fi

echo "    [1/5] Getting ANTLR4 ..."
echo "    [1/5] Getting ANTLR4 ..."
echo "    [1/5] Getting ANTLR4 ..."
cd /usr/local/lib
wget http://www.antlr.org/download/antlr-4.7.1-complete.jar
echo "    [2/5] Generating aliases..."
export CLASSPATH=".:/usr/local/lib/antlr-4.7.1-complete.jar:$CLASSPATH"
alias antlr4='java -jar /usr/local/lib/antlr-4.7.1-complete.jar'
alias grun='java org.antlr.v4.gui.TestRig'

mkdir ANTLR4
cd ANTLR4

echo "    [3/5] Getting runtime for C++..."
wget www.antlr.org/download/antlr4-cpp-runtime-4.7.1-source.zip
unzip antlr4-cpp-runtime-4.7.1-source.zip
mkdir build ; mkdir run ; cd build
echo "    [4/5] Installing runtime..."
cmake .. -DANTLR_JAR_LOCATION=/usr/local/lib/antlr-4.7.1-complete.jar -DWITH_DEMO=True
make
DESTDIR=/usr/local/lib/ANTLR4/run make install

echo "    [5/5] Making link on /usr/local/bin ..."
cd /usr/local/bin
touch antlr4
printf "java -jar /usr/local/lib/antlr-4.7.1-complete.jar \"\$@\"\n" > antlr4
chmod 777 /usr/local/bin/antlr4
echo "Installation has finished. :-)"