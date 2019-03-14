check_dependency()
{
	PKG_OK=$(dpkg-query -W --showformat='${Status}\n' $1 | grep "install ok installed")
	echo "            Checking for $1: $PKG_OK"
	if [ "" == "$PKG_OK" ]; then
	  echo "No $1 installed. Setting up $1 ..."
	  sudo apt-get install $1
	fi
}

if [ "$EUID" -ne 0 ]; then
	echo "Please run this script as root!"
	exit
fi

echo "    [1/6] Getting ANTLR4 ..."
echo "    [1/6] Getting ANTLR4 ..."
echo "    [1/6] Getting ANTLR4 ..."
cd /usr/local/lib
wget http://www.antlr.org/download/antlr-4.7.2-complete.jar
echo "    [2/6] Generating aliases ..."
export CLASSPATH=".:/usr/local/lib/antlr-4.7.2-complete.jar:$CLASSPATH"
#echo "alias antlr4='java -jar /usr/local/lib/antlr-4.7.2-complete.jar';" >> ~/.bash_aliases
#echo "alias grun='java org.antlr.v4.gui.TestRig';" >> ~/.bash_aliases
alias antlr4='java -jar /usr/local/lib/antlr-4.7.2-complete.jar'
alias grun='java org.antlr.v4.gui.TestRig'

mkdir -p ANTLR4
cd ANTLR4

echo "    [3/6] Getting runtime for C++ ..."
wget www.antlr.org/download/antlr4-cpp-runtime-4.7.2-source.zip
unzip antlr4-cpp-runtime-4.7.2-source.zip
mkdir -p build ; mkdir -p run ; cd build

echo "    [4/6] Checking dependencies ..."
echo "        [1/3] Checking for cmake ..."
check_dependency cmake
echo "        [2/3] Checking for pkg-config ..."
check_dependency pkgconf
echo "        [3/3] Checking for uuid-dev ..."
check_dependency uuid-dev

echo "    [5/6] Installing runtime ..."
cmake .. -DANTLR_JAR_LOCATION=/usr/local/lib/antlr-4.7.2-complete.jar -DWITH_DEMO=True
make
DESTDIR=/usr/local/lib/ANTLR4/run make install
cp -r /usr/local/lib/ANTLR4/run/usr/* /usr/
ldconfig

echo "    [6/6] Making link on /usr/local/bin ..."
cd /usr/local/bin
touch antlr4
printf "java -jar /usr/local/lib/antlr-4.7.2-complete.jar \"\$@\"\n" > antlr4
chmod 777 /usr/local/bin/antlr4
echo "Installation successful."
