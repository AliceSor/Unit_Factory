mkdir bin
javac -sourcepath ./src -d bin src/com/asoroka/launcher/*.java
java -classpath ./bin com.asoroka.launcher.Launcher $1
#cat simulation.txt
rm -rf bin
