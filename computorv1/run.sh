mkdir bin

javac -sourcepath ./src -d bin src/com/unitfactory/*.java
java -classpath ./bin com.unitfactory.Main "$1"
#cat simulation.txt
rm -rf bin
