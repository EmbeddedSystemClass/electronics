sudo ifup wlan0 
ifconfig 
sudo vim /etc/hostapd/hostapd.conf
sudo /usr/sbin/hostapd /etc/hostapd/hostapd.conf 
sudo vim /etc/hostapd/hostapd.conf 
sudo /usr/sbin/hostapd /etc/hostapd/hostapd.conf 
sudo vim /etc/default/hostapd 
sudo mv /etc/dnsmasq.conf /etc/dnsmasq.conf.orig
sudo vim /etc/dnsmasq.conf 
sudo vim /etc/sysctl.conf 
sudo iptables -t nat -A POSTROUTING -o eth0 -j MASQUERADE
sudo iptables -A FORWARD -i eth0 -o wlan0 -m state --state RELATED,ESTABLISHED -j ACCEPT
sudo iptables -A FORWARD -i wlan0 -o eth0 -j ACCEPT
sudo sh -c "iptables-save > /etc/iptables.ipv4.nat"
sudo vim /etc/rc.local 
sudo reboot
ssh localhost
sudo apt-get install openssh-server 
sudo shutdown -h now
exit
clear
ls
cd ~
ls
cd /
ls
cd
sudo apt-get install gnuplot-x11
ls
exit
shutdown 0
sudo shutdown 0
ll
ls -l
ls
pwd
git
ping 8.8.8.8
ls /media/
ls /
fdisl -l
fdisk -l
sudo fdisk -l
lsusb
scp
ls -l
cd RPI_RADIO/
ls -l
make re
./radio
sudo raspi-config
sudo reboot
cd RPI_RADIO/
make re
./radio
sudo halt
cd RPI_RADIO/
vim radio.c 
exit
cd RPI_RADIO/
vim nrf24l01_driver.c
exit
cd RPI_RADIO/
vim nrf24l01_driver.h
exit
cd RPI_RADIO/
./radio
make re && ./radio
make
make re && ./radio
make
make re && ./radio
make
make re && ./radio
make
make re && ./radio
sudo shutdown -h now
ls
cd RPI_RADIO/
ls

apt-get update
sudo apt-get update
exit
cd RPI_RADIO/
vim radio.c
exit
ll
ls -l
cd RPI_RADIO/
ls -l
vim nrf24l01_driver.c
exit
ls
cd RPI_RADIO/
ls
vim radio.c 
ls
make
make re
./radio
ls
cd rpi
cd RPI_RADIO/
ls
cd ..
ls
cd RPI_RADIO/
ls
mv ~Bureau/gnuplot-5.0.6 ~/RPI_RADIO
mv ~/Bureau/gnuplot-5.0.6 ~/RPI_RADIO
scp /home/morgane/Bureau/gnuplot-5.0.6 ~/RPI_RADIO
sudo apt-get gnuplot
cd RPI_RADIO/
ls
make re
make re && ./radio
sudo halt
cd RPI_RADIO/
exit
cd RPI_RADIO/
exit
cd RPI_RADIO/
exit
cd RPI_RADIO/
make re
make re && ./radio
sudo halt
ls
cd RPI_RADIO/
ls
cd RPI_RADIO/
ll
ls -l
vim radio.c 
exit
cd RPI_RADIO/
make re
make
./radio
make re && ./radio
make
make re && ./radio
make re
make
make re && ./radio
vim Makefile 
make 
make re
gdb ./radio
./radio
exit
cd RPI_RADIO/
./radio
make re && ./radio
cd /sys/class/
ls -l
cd gpio/
ls -l
cd
sudo halt
ls -la
sudo apt install nginx
sudo apt update
ls -la
sudo apt install nginx
ls -la
sudo /etc/nginx/sites-enabled/
sudo vim /etc/nginx/sites-enabled/
sudo
cd /etc/nginx/
ls -la
cd sites-available/
ls
ls -la
cd ..
ls -la sites-enabled/
rm sites-enabled/default 
sudo rm sites-enabled/default 
ls -la
ls -la sites-available/
cd sites-
cd sites-available/
sudo cp default eoe-plot
vi eoe-plot 
sudo vi eoe-plot 
cd ~
ls
mkdir eoe-plot
ls -la
chown pi:www-data eoe-plot/
sudo chown pi:www-data eoe-plot/
ls -la
cd -
vi eoe-plot 
sudo vi eoe-plot 
cd ../sites-enabled/
ln -s --help
man ln 
sudo ln -s /etc/nginx/sites-available/eoe-plot .
ls -la
sudo service nginx reload
ls
cd
cd eoe-plot/
ls
apt search gnuplot
apt search gnuplot | less
apt-cache search gnuplot
apt-cache search gnuplot }
apt-cache search gnuplot | less
sudo apt install gnuplot5
gnuplot --help[
gnuplot --help
gnuplot --version
cd ..
cd gnuplot-5.0.6/
ls
cd ..
ls
sudo apt remove gnuplot5
sudo apt autoremove
sudo apt-get autoremove
cds gnuplot-5.0.6/
cd gnuplot-5.0.6/
./config
./configure
./configure | less
sudo apt install libgd2
sudo apt install libgd2-dev
sudo apt install build-essentials
sudo apt install build-essential
ls -la
./configure
./configure | less
ls -la
make
sudo make install
which gnuplot 
gnuplot
ls
mv plot.jpg ../eoe-plot/
cat /etc/nginx/sites-enabled/eoe-plot 
CD ..
cd ..
ls
cd eoe-plot/
ls -la
chown pi:www-data plot.jpg
sudo chown pi:www-data plot.jpg
cat /var/log/nginx/error.log 
cd ..
ls -la
sudo vi /etc/nginx/sites-enabled/eoe-plot 
service nginx reload
sudo service nginx reload
sudo vi /etc/nginx/sites-enabled/eoe-plot 
sudo shutdown -h now
cd RPI_RADIO/
cd ..
cd RPI_RADIO/
vim gpio_driver.c
clear
exit
cd RPI_RADIO/
cd ..
cd RPI_RADIO/
vim nrf24l01_driver.c
watch ls /sys/class/gpio
cd RPI_RADIO/
cd ..
ls -l
ls -l gnuplot-5.0.6/
cd RPI_RADIO/
./radio
make re
make
./radio
gdb ./radio
make re
./radio
make re && ./r
./radio
make re && ./radio
make
make re && ./radio
make
make re && ./radio
cd RPI_RADIO/
ls -l
./radio
make re && ./radio
make
make re
make
./radio
make re && ./radio
make
./radio
make re && ./radio
exit
cd /sys/class
cd gpio/
ls -l
ls
cat 8 >> export 
cat "8" >> export 
echo "8" >> export 
ls -l
echo 8 >> unexport 
man gpio
man ./gpiochip0
ls -l
cd
pwd
cd gnuplot-5.0.6/
ls -l
ls -l | grep dat
cat data 
man open
man 2 open
ls
cd ../
ll
ls -l
cd
ls -a
vim .bash
man alias
ls -l
ls
touch plot_test
ls
pwd
man 2 open
man 2 close
man 2 write
man sprintf
ls -l
echo "" >> plot_test 
echo "" > plot_test 
exit
watch cat plot_test 
watch tail plot_test 
watch cat plot_test 
cat plot_test 
vim plot_test 
cat plot_test 
vim plot_test 
cat plot_test 
watch cat plot_test 
vim plot.script 
terminal
clear
echo -e "\n\n\n            .;;;, .;;;,                   .;;;, .;;;,\n        .;;;,;;;;;,;;;;;,.;;;,       .;;;.,;;;;;,;;;;;,;;;.\n       ;;;;oOOoOOoOOoOOoOOo;;;. .,. .;;;oOOoOOoOOoOOoOOo;;;;\n   .,,.'oOOo'           'OoOOo,;;;;;,oOOoO'          'oOOo;',,.\n  ;;;;oOOo'    ,;;;,       'OoOOo;oOOoO'       ,;;;,   'oOOo;;;;\n  ';;OOoO'    ;;;'             'OOO'             ';;;   'OoOO;;'\n ,;;,OOoO     ;;                 \"                 ;;    OoOO,;;,\n ;;;;OOoO     ';     ,;;.                          ;'    OoOO;;;;\n  ''.;OOoO,    ';    ' ;;    .;;. ;; ;; .;;,      ;'   ,OoOO;,''\n    ;;;;OOoO,          ;;    ;  ; '; ;' ;..'         ,OoOO;;;;\n     '''.;OOoO,        ;,;;, ';;'  ';'  ';;'       ,OoOO;,'''\n        ;;;;OOoO,      '    ',  ,                ,OoOO;;;;\n         ''',;OOoO,.          ''              .,OoOO;,'''\n             ;;;;OOoO,.                    .,OoOO;;;;\n              '''',;OOoO,.              .,OoOO;, '''\n                  ;;;;;OOoO,.        .,OoOO;;;;\n                   ''''',;OOoO,.  .,OoOO;,''''\n                        ;;;;;OOoOOoOO;;;;;\n                         ''''';;OO;;'''''\n                              ';;;;'"
sudo halt
cd RPI_RADIO/
cd ..
ls -l eoe-plot/
cd RPI_RADIO/
vim radio.c
pwd
cd ..
ls -l
rm data.dat 
mv plot_test data.dat
ls -l
./plot.sh
sudo bash ./plot.sh
vim plot.sh
ls -l
vim plot.script 
sudo bash ./plot.sh
bash ./plot.sh
vim data.dat 
bash ./plot.sh
vim plot.sh 
vim data.dat 
ls -l
cp graph.jpeg eoe-plot/
bash ./plot.sh
vim data.dat 
bash ./plot.sh
vim data.dat 
bash ./plot.sh
cd RPI_RADIO/
vim radio
vim radio.c 
cd ..
bash ./plot.sh
ls -l
sudo chown -r 777 RPI_RADIO/
sudo chown 777 RPI_RADIO/ -r
sudo chown 777 RPI_RADIO/ -R
ls -l
pwd
sh plot.sh 
cat -e data.dat 
scp pi@172.24.1.1:data.dat ~/Desktop/
ls
scp pi@172.24.1.1:data.dat .
exit
ls
cd RPI_RADIO/
ls
make
./radio
cd ..
ls
cd RPI_RADIO/
ls
clear
./radio
ls
vim radio.c
ls
./radio
ls ../
ls ../eoe-plot/
vim ../data.dat 
cleaer
ls
cd ..
ls
vim plot_test 
ls
vim plot.script 
clear
ls
sh plot.sh 
vim plot.sh
ls
vim data.dat 
sh plot.sh 
vim data.dat 
scp pi@172.24.1.1:data.dat ./Desktop
ls -l /dev/disk/by-uuid
cd /media
ls
ls -l /dev/disk/by-uuid
ls
cd
ls
cd /
ls
cd mnt/
ls
cd ..
ls
cd media/
ls
cd ..
ls
ls -l /dev/disk/by-uuid
cd
scp pi@172.24.1.1:~/data.dat ~/Desktop/data.dat
sh plot.sh 
ls
pwd
touch plot_test
cat plot_test 
ls
cat plop.sh
cat plot.sh
vi plot.script 
sh plot.sh 
vi plot.script 
sh plot.sh 
vi plot.script 
sh plot.sh 
vi plot.script 
sh plot.sh 
vi plot.script 
sh plot.sh 
vi plot.script 
gnuplot 
vi plot.script 
sh plot.sh 
vi plot.script 
sh plot.sh 
vim plot.script 
sh plot.sh 
gmuplot
gnuplot
ls
ls Desktop 
rm Desktop 
ls
ls eoe-plot/
rm eoe-plot/graph.jpeg 
ls
vim plot.script 
sh plot.sh 
ls
vim gnuplot_auto.c 
cd RPI_RADIO/
ls
vim radio.c
vim nrf24l01_driver.c
clear
ls
cd ..
ls
cat plot_test 
cd RPI_RADIO/
./radio
clear
ls
cd ..
ls
cat plot_test 
ls
time
date
man date
ls
clear
ls
mkdir DATE
cd DATE/
ls
vim main.c
gcc -Wall -Wextra -Werror main.c
ls
vim main.c 
gcc -Wall -Wextra -Werror main.c
clear
sudo date -s "Jul 5 08:10"
sudo date -s "2017-07-25 13:00:00"
date
time
clear
ls
clear
ls
vim main.c 
gcc -Wall -Wextra -Werror main.c
vim main.c 
gcc -Wall -Wextra -Werror main.c
./a.out 
vim main.c 
gcc -Wall -Wextra -Werror main.c
vim main.c 
gcc -Wall -Wextra -Werror main.c
./a.out 
man date 
vim main.c 
gcc -Wall -Wextra -Werror main.c
./a.out 
vim main.c 
gcc -Wall -Wextra -Werror main.c
./a.out 
vim main.c 
gcc -Wall -Wextra -Werror main.c
./a.out 
vim main.c 
gcc -Wall -Wextra -Werror main.c
./a.out 
vim main.c 
gcc -Wall -Wextra -Werror main.c
./a.out 
vim main.c 
gcc -Wall -Wextra -Werror main.c
./a.out 
vim main.c 
ls
clear
ls
cd ..
ls
cat plot_test 
clear
ls
vim plot_test 
cat plot_test 
ls
clear
ls
rm data.dat 
mv plot_test data.dat
ls
sh plot.sh 
vim data.dat 
cat data.dat 
sh plot.sh 
cle
ls
sh plot.sh 
vim data.dat 
cleaer
sh plot.sh 
vim data.dat 
clear
ls
rm -rf DATE/
ls
sh plot.sh 
ls
cd RPI_RADIO/
ls
clear
vim radio.c
make
make re
vim radio.c
make re
ls
vim Makefile 
make
./radio
vim radio.c 
make
make re
./radio
vim radio.c 
make re
./radio
ls
cd ..
vim plot.script 
clear
ls
vim plot.script 
sh plot.sh 
vim plot.script 
sh plot.sh 
vim plot.script 
sh plot.sh 
vim plot.script 
sh plot.sh 
vim plot.script 
sh plot.sh 
vim plot.script 
cat data.dat 
vim plot.script 
sh plot.sh 
clear
ls
cd RPI_RADIO/
ls
./radio
touch ../plot_test
ls
./radio
ls
cd ..
ls
mv data.dat ~data.dat 
ls
mv plot_test data.dat
vim plot.script 
sh plot.sh 
vim plot.script 
cat data.dat 
cd RPI_RADIO/
vim radio.c
ls
cd ..
ls
vim data.dat 
sh plot.sh 
clear
ls
vim plot.script 
vim RPI_RADIO/radio.c
clear
ls
man cat
man system
clear
ls
mkdir PARSE
cd PARSE/
cp -r ../data.dat .
ls
clear
ls
man cat
ls
cat head -1 data.dat 
cat head-1 data.dat 
head-1 data.dat 
head -1 data.dat 
head -1 data.dat | cut -d ' ' 2
cut --help
head -1 data.dat | cut -d=' ' 2
head -1 data.dat | cut -d=' ' 1-2
head -1 data.dat | cut -d' ' 1-2
head -1 data.dat | cut -d' ' -c1-2
cut -c1-2 data.dat 
ls
cat data.dat 
cut -c1-3 data.dat 
cut -c1-4 data.dat 
cut -c1-7 data.dat 
cut -c1-15 data.dat 
cut -d  data.dat | head -1
clear
cp ../plot.script 
cp ../plot.script  .
ls
vim plot.script 
ls
cp -r ../* .
ls
clear
ls
clear
ls
cd ..
ls
rm -rf PARSE/
ls
clear
mkdir PARSE
cd PARSE/
ls
cp ../data.dat .
cut -c1-15 data.dat 
cut -c1-15 data.dat |head -1
cut -c1-15 data.dat |head -2
cut -c1-15 data.dat |head -1
clear
cut -c1-15 data.dat | head -1 
cut -c1-15 data.dat | tail -1 
cat data.dat 
clear
cd ..
ls
cp plot.script ~plot.script 
ls
vim plot.script 
sh plot.sh 
help show
gnuplot
clear
ls
vim plot.script 
sh plot.sh 
vim plot.script 
sh plot.sh 
clear
ls
cp plot.s ~plot.sh
cp plot.sh ~plot.sh
ls
vim plot.sh
vim plot.script 
ls
clear
ls
cd RPI_RADIO/
ls
cd ..
ls
cd PARSE/
ls
vim main.c
ls
cp ../plot.script .
ls
vim plot.script 
ls
cd ..
ls
rm -rf PARSE/
ls
vim plot.script 
sh plot.sh 
vim plot.script 
sh plot.sh 
ls
vim plot.script 
vim plot.sh
sh plot.sh 
vim plot.sh
sh plot.sh 
vim plot.sh
sh plot.sh 
vim plot.sh 
sh plot.sh 
ls
cat data.dat 
clear
ls
vim plot.script 
vim plot.sh
sh plot.sh 
vim plot.sh
sh plot.sh 
vim plot.sh
sh plot.sh 
vim plot.sh
sh plot.sh 
clear
ls
sh plot.sh 
vim plot.sh
sh plot.sh 
vim plot.sh
vim data.dat 
sh plot.sh 
vim data.dat 
sh plot.sh 
vim plot.sh
sh plot.sh 
ls
clear
ls
sh plot.sh 
vim plot.sh
sh plot.sh 
vim plot.sh
sh plot.sh 
vim plot.sh
sh plot.sh 
vim plot.sh
clear
ls
cut -d' ' -f1-2 data.dat
cut -d'\t' -f1-2 data.dat
cut -d'\\t' -f1-2 data.dat
cut -f2 -d$'\t' data.dat
cut -f1 -d$'\t' data.dat
cut -f1 -d$'\t' data.dat | head -1
clear
ls
cut -f1 -d$'\t' data.dat | head -1
cat data.dat 
vim plot.sh
sh plot.sh 
vim plot.sh
cut -f1 -d$'\t' data.dat | head -1
vim plot.sh
sh plot.sh 
vim plot.sh
sh plot.sh 
vim data.dat 
sh plot.sh 
clear
ls
cd RPI_RADIO/
make
./radio
ls
clear
ls
mkdir old
mv ~* old/
ls
mv plot.script old/
ls
vim plot.sh 
clear
ls
cd RPI_RADIO/
ls
vim radio.c
clear
ls
make re
./radio
vim radio.c
clear
cd
sudo shutdown
clear
ls
vim plot.sh 
ls
vim nu
sh plot.sh 
vim plot.sh 
sh plot.sh 
ls
ls eoe-plot/
cat nu
cat -e nu
man cat
clear
ls
vim plot.sh 
rm eoe-plot/plot001.jpg 
ls
sh plot.sh 
ls eoe-plot/
vim plot.sh 
sh plot.sh 
ls eoe-plot/
vim plot.sh 
sh plot.sh 
vim plot.sh 
sh plot.sh 
vim plot.sh 
ls
clear
ls
awk -F, '{printf($1+1)}' nu
cat nu
awk -F, '{printf($1+1)}' nu
vim nu
awk -F, '{printf($1+1)}' nu
awk -F, '{printf("%03d", $1+1)}' nu
awk -F, '{printf("%03d", $1+1)}' > nu
vim nu
ls
cat nu
awk -F, '{printf("%03d", $1+1)}' | >> nu
cat nu
vim nu
awk -F, '{printf("%03d", $1+1)}' | >> nu
vim nu
awk -F, '{printf("%03d", $1+1)}' | cat -e
awk -F, '{printf("%03d", $1+1)}'
vim nu
awk -F, '{printf("%03d", $1+1)}' nu 
awk -F, '{printf("%03d", $1+1)}' nu > nu
cat nu
awk -F, '{printf("%03d", $1+1)}' nu | cat -e
vim nu
awk -F, '{printf("%03d", $1+1)}' nu | cat -e
awk -F, '{printf("%03d", $1+1)}' nu | cut -c1
awk -F, '{printf("%03d", $1+1)}' nu | >> nu
cat nu
awk -F, '{printf("%03d\nwq", $1+1)}' nu | >> nu
awk -F, '{printf("%03d\n", $1+1)}' nu | >> nu
awk -F, '{printf("%03d\n", $1+1)}' nu
awk -F '{printf("%03d\n", $1+1)}' nu
awk -F, '{printf("%03d\n", $1+1)}' nu | cat -e
awk -F, '{printf("%03d\n", $1+1)}' nu | cat > nu
ls
cat nu
vim nu
awk -F, '{printf("%03d\n", $1+1)}' nu |
awk -F, '{printf("%03d\n", $1+1)}' nu 
vim plot.sh 
sh plot.sh 
vim plot.sh 
sh plot.sh 
vim plot.sh 
sh plot.sh 
vim plot.sh 
sh plot.sh 
vim plot.sh 
sh plot.sh 
cat nu
vim plot.sh 
touch test
echo "Hello" > test
cat test 
rm test 
vim plot.sh 
sh plot.sh 
cat nu
ls
cat nu?
vim plot.sh 
vim nu?
sh plot.sh 
cat nu?
ls eoe-plot/
rm eoe-plot/plot001.jpg 
rm eoe-plot/plot1.jpg 
ls
clear
ls
vim plot.sh 
sh plot.sh 
ls
vim plot.sh 
ls
cat nu???
cat nu??
ls
vim plot.sh 
sh plot.sh 
ls
cat nu
vim plot.sh 
ls
sh plot.sh 
ls
vim plot.sh 
ls
sh plot.sh 
ls
echo "lala" test
echo "lala" > test
ls
rm test 
ls
shutdown
sudo shutdown
ls
clear
ls
vim default 
ls
vim default 
ls
clear
ls
vim default 
sudo sut down
sudo shutdown
sudo shutdown -t 0
clear
ls
rm eoe-plot/plot001.jpg 
rm eoe-plot/plot002.jpg 
ls
clear
ls eoe-plot/
ls
rm nu?
rm nu??
ls
clear
vim nu
vim plot.sh 
sh plot.sh 
ls
vim plot.sh 
ls
rm nu# 
ls
clear
ls
ls eoe-plot/
rm eoe-plot/plot?.jpg
ls
ls eoe-plot/
ls
vim plot.sh 
mv nu index
ls
sh plot.sh 
ls
vim plot.sh 
sh plot.sh 
vim plot.sh 
sh plot.sh 
vim plot.sh 
sh plot.sh 
ls
clear
ls
vim plot.sh 
sh plot.sh 
ls
cat index
vim plot.sh 
ls
clear
ls
rm index
ls
clear
ls
rm index 
vim index
ls
clear
ls
vim plot.sh 
sh plot.sh 
ls
ls eoe-plot/
cat index?
cat index 
ls
cd RPI_RADIO/
./radio
touch ../plot_test
./radio
clear
ls
cd ..
ls
touch "test\n"
ls
rm test\\n 
ls
vim plot.sh 
ls
sh plot.sh 
ls
ls eoe-plot/
vim plot.sh 
sh plot.sh 
ls eoe-plot/
vim plot.sh 
ls eoe-plot/
ls
vim plot.sh 
sh plot.sh 
vim plot.sh 
sh plot.sh 
vim plot
vim plot.sh 
sh plot.sh 
ls
vim plot.sh 
sh plot.sh 
ls
clear
ls
vim plot.sh 
sh plot.sh 
ls
rm test 
rm test\? 
ls
clear
ls
vim plot.sh 
ls -la
cat -e plot.sh 
ls
clear
ls
man dos2unix
ls
cat -e plot.sh 
dos2unix plot.sh 
vim plot.sh 
clear
ls
cat -e plot.sh 
vim plot.sh 
ls
cp plot.sh la.sh
sh la.sh 
ls
clear
ls
rm index 
sh la.sh 
ls
cat index
rm la.sh 
rm index?
ls
clear
ls
cat index
cat plot.sh
cat -e plot.sh
s
clear
ls
vim t.sh
ls
sh t.sh 
ls
rm t.sh 
ls
rm te
ls
clear
ls
cat plot.sh > te.sh
cat -e te.sh 
ls
rm te.sh 
ls
clear
ls
cat -e plot.sh 
ls
mv plot.sh old/
ls
clear
ls
cat -e plot.sh 
clear
ls
sh plot.sh 
ls
cat index 
sh plot.sh 
cat index 
rm eoe-plot/plot001^*
rm eoe-plot/plot00*
ls
clear
ls
clear
ls
rm test 
ls
clear
ls
vim RPI_RADIO/radio.c 
ls
rm plot_test 
ls
vim plot.sh 
ls
mkdir backup
ls
sh plot.sh 
ls
ls backup/
ls
vim index 
ls
rm eoe-plot/plot0*
ls
clear
ls
rm graph.jpeg 
ls
clear
ls
sh plot.sh 
ls backup/
rm backup/data003
rm backup/data003.dat 
ls
cat index 
ls
vim plot.sh 
ls
vim RPI_RADIO/radio.c 
ls
cd RPI_RADIO/
ls
sudo vim radio.c
ls
cd ..
ls
vim plot.sh 
ls
clear
ls
vim index 
rm eoe-plot/plot001.jpg 
ls
rm backup/*
ls
clear
ls
vim RPI_RADIO/
cd RPI_RADIO/
ls
make
make re
vim radio.c
make re
./radio
ls
clear
ls
cd ..
ls
cat data.dat 
ls
cd RPI_RADIO/
ls
cat data.dat 
vim radio.c
ls
rm data.dat 
ls
clear
ls
rm index 
ls
clear
ls
cd ..
ls
cp RPI_RADIO/radio .
ls
>data.dat 
ls
./radio 
clear
ls
vim plot.sh 
sh plot.sh 
clear
ls
vim plot.sh 
sh plot.sh 
ls
cat data.dat 
ls
cat backup/data001.dat > data.dat 
sh plot.sh 
ls
clear
ls
cd backup/
ls
cd ..
ls
cat index 
sh plot.sh 
ls
cat backup/data004.dat > data.dat 
sh plot.sh 
ls
clear
ls
vim RPI_RADIO/
ls
vim default
ls
clear
ls
cd RPI_RADIO/
ls
vim radio_send.c
ls
gcc -Wall -Wextra -Werror radio_send.c 
vim radio_send.c 
vim spi_driver.h
gcc -Wall -Wextra -Werror radio_send.c 
vim spi_driver.h
gcc -Wall -Wextra -Werror radio_send.c 
gcc radio_send.c
vim spi_driver.h
gcc -Wall -Wextra -Werror radio_send.c 
vim Makefile 
g++ -Wall -Wextra -Werror radio_send.c 
vim spi_driver.h
g++ -Wall -Wextra -Werror radio_send.c 
ls
clear
ls
./a.out 
./a.out lala lulu lili
vim radio_send.c 
g++ -Wall -Wextra -Werror radio_send.c 
./a.out lala lulu lili
ls
vim radio_send.c 
g++ -Wall -Wextra -Werror radio_send.c 
vim radio_send.c 
g++ -Wall -Wextra -Werror radio_send.c 
ls
vim Makefile 
g++ -Wall -Wextra -Werror gpio_driver.c nrf24l01_driver.c spi_driver.c radio_send.c 
ls
clear
./a.out 
./a.out lala
vim radio_send.c 
g++ -Wall -Wextra -Werror gpio_driver.c nrf24l01_driver.c spi_driver.c radio_send.c 
./a.out 
./a.out lala
vim radio_send.c 
g++ -Wall -Wextra -Werror gpio_driver.c nrf24l01_driver.c spi_driver.c radio_send.c 
./a.out lala
./a.out bonjour la la lou
ls
clear
ls
rm a.out 
g++ -Wall -Wextra -Werror gpio_driver.c nrf24l01_driver.c spi_driver.c radio_send.c -o send
ls
./send lala
clear
ls
mv send ../
ls
cd ..
ls
mkdir system
ls
rm -rf system/
ls
vim send.sh
ls
vim RPI_RADIO/radio.c 
vim default 
ls
vim RPI_RADIO/radio.c
ls
cd libft/
ls
make re
make 
vim include/ft_printf.h 
make
vim src/ft_litob.c 
make
ls
clear
ls
cd ..
ls
vim RPI_RADIO/radio.c 
make re
cd RPI_RADIO/
vim radio.c
make re
ks
ls
cd ..
ls
mv libft/ RPI_RADIO/
ls
cd RPI_RADIO/
ls
vim Makefile 
make re
ls
make
vim radio.c 
make
clear
ls
vim radio.c
make
ls
vim radio.c
make
cat libft/include/libft.h 
clear
make
vim Makefile 
make
vim radio.c
ls
clear
ls
make
vim Makefile 
maje
makje
make
ls
cd libft/
ls
make re
ls
make re
cleaer
make
vim Makefile 
make re
vim Makefile 
make
make re
clear
ls
cd ..
ls
make
cat libft/include/get_next_line.h 
clear
ls
vim radio.c
make
vim Makefile 
make
vim Makefile 
vim radio.c
cat libft/include/get_next_line.h 
clear
ls
vim radio.c
gcc -Wall -Wextra -Werror gpio_driver.c nrf24l01_driver.c radio.c spi_driver.c -I./libft/include/
g++ -Wall -Wextra -Werror gpio_driver.c nrf24l01_driver.c radio.c spi_driver.c -I./libft/include/
g++ -Wall -Wextra gpio_driver.c nrf24l01_driver.c radio.c spi_driver.c -I./libft/include/
g++ gpio_driver.c nrf24l01_driver.c radio.c spi_driver.c -I./libft/include/
g++ gpio_driver.c nrf24l01_driver.c radio.c spi_driver.c libft/src/get_next_line.c -I./libft/include/ 
g++ gpio_driver.c nrf24l01_driver.c radio.c spi_driver.c -I./libft/include/ -L ./libft/-lft
g++ gpio_driver.c nrf24l01_driver.c radio.c spi_driver.c -I./libft/include/ -L./libft/-lft
g++ gpio_driver.c nrf24l01_driver.c radio.c spi_driver.c libft/libft.a -I./libft/include/
g++ gpio_driver.c nrf24l01_driver.c radio.c spi_driver.c ./libft/libft.a -I./libft/include/
g++ -o radio gpio_driver.c nrf24l01_driver.c radio.c spi_driver.c -I./libft/include ./libft/libft.a
g++ -o radio gpio_driver.c nrf24l01_driver.c radio.c spi_driver.c libft/src/* -I./libft/include/
clear
ls
cd libft/
vim Makefile 
make re
vim Makefile 
make re
vim Makefile 
make re
vim Makefile 
vim src/ft_memalloc.c 
make
vim src/ft_memccpy.c 
make
vim src/ft_memcpy.c 
make
vim src/ft_memset.c 
make
vim src/ft_strnew.c 
make
vim Makefile 
make
vim Makefile 
make
vim Makefile 
make
vim Makefile 
make
clear
cd ..
make
g++ radio.c nrf24l01_driver.c spi_driver.c gpio_driver.c libft/src/* -I./libft/include/
clear
ls
cd libft/
ls
cd src/
ls
rm *itoa*
rm handle*
rm *printf*
ls
rm utils.c parse.c wchar_t.c print_memory.c 
ls
clear
cd ..
ls
cd ..
g++ radio.c nrf24l01_driver.c spi_driver.c gpio_driver.c libft/src/* -I./libft/include/
rm ./libft/src/*lst*
g++ radio.c nrf24l01_driver.c spi_driver.c gpio_driver.c libft/src/* -I./libft/include/
ls
./a.out 
clear
vim radio.c
g++ radio.c nrf24l01_driver.c spi_driver.c gpio_driver.c libft/src/* -I./libft/include/
vim radio.c
g++ radio.c nrf24l01_driver.c spi_driver.c gpio_driver.c libft/src/* -I./libft/include/
./a.out 
clear
vim radio.c
g++ radio.c nrf24l01_driver.c spi_driver.c gpio_driver.c libft/src/* -I./libft/include/
./a.out 
clear
vim radio.c
ls
clear
g++ radio.c nrf24l01_driver.c spi_driver.c gpio_driver.c libft/src/* -I./libft/include/
vim radio.c
g++ radio.c nrf24l01_driver.c spi_driver.c gpio_driver.c libft/src/* -I./libft/include/
./a.out 
ls
vim radio.c 
g++ radio.c nrf24l01_driver.c spi_driver.c gpio_driver.c libft/src/* -I./libft/include/
./a.out 
ls
cd old
ls
cd ..
ls eoe-plot/
ls send 
ls radio 
ls -la send 
cat plot.sh 
ls
cat index 
ls
cat default 
cat data.dat 
kill radio
htop
top
pkill radio
clear
ls
cat default 
cd RPI_RADIO/
ls
cat spi_driver.h
cat gpio_driver.h
cat *.h
cat *.h | less
cd ..
ls
./radio 
cat *.h | less
ls
pwd
cd RPI_RADIO/
cat *.h | less
cd ..
./radio 
./radio 
clear
ls
cd RPI_RADIO/
ls
make
make re
vim radio.c
cd ..
ls
cd backup/
ls
rm *
ls
cd ..
ls
cd eoe-plot/
ls
rm *
ls
cd ..
ls
vim index 
ls
clear
ls
cd RPI_RADIO/
vim radio.c
sudo shutdown -t 0
clear
ls
./radio 
ls
cd RPI_RADIO/
ls
./a.out 
clear
l
cd ..
ls
./send 
cd RPI_RADIO/
vim radio_send.c 
cd ..
./send lala
ls
clear
ls
cd  RPI_RADIO/
ls
vim radio.c
ls
g++ -Wall -Wextra -Werror gpio_driver.c nrf24l01_driver.c spi_driver.c radio.c libft/src/*.c
vim radio.cclear
vim radio.
clear
ls
exit
cd RPI_RADIO/
ls
g++ -Wall -Wextra -Werror gpio_driver.c nrf24l01_driver.c spi_driver.c radio.c libft/src/*.c -I ./libft/includes
g++ -Wall -Wextra -Werror gpio_driver.c nrf24l01_driver.c spi_driver.c radio.c libft/src/*.c -I ./libft/includesgccexit
exit
vim default 
man ascii
vim default 
cd RPI_RADIO/
ls
g++ -Wall -Wextra -Werror gpio_driver.c nrf24l01_driver.c spi_driver.c radio.c libft/src/*.c -I ./libft/include
ls
clear
g++ -Wall -Wextra -Werror gpio_driver.c nrf24l01_driver.c spi_driver.c radio.c libft/src/*.c -I ./libft/include
g++ gpio_driver.c nrf24l01_driver.c spi_driver.c radio.c libft/src/*.c -I ./libft/include
./a.out 
vim radio.c
g++ gpio_driver.c nrf24l01_driver.c spi_driver.c radio.c libft/src/*.c -I ./libft/include
./a.out 
clear
vim radio.c
g++ gpio_driver.c nrf24l01_driver.c spi_driver.c radio.c libft/src/*.c -I ./libft/include
./a.out 
clear
ls
rm a.out 
vim radio.c
g++ gpio_driver.c nrf24l01_driver.c spi_driver.c radio.c libft/src/*.c -I ./libft/include
./a.out 
vim radio.c
g++ gpio_driver.c nrf24l01_driver.c spi_driver.c radio.c libft/src/*.c -I ./libft/include
./a.out 
sudo shutdown -t 0
clear
ls
cd RPI_RADIO/
ls
vim radio.c
ls
clear
ls
g++ gpio_driver.c nrf24l01_driver.c radio.c spi_driver.c libft/src/*c 
clear
exit
cd RPI_RADIO/
g++ gpio_driver.c nrf24l01_driver.c radio.c spi_driver.c libft/src/*c -I ./libft/include
echo "g++ gpio_driver.c nrf24l01_driver.c radio.c spi_driver.c libft/src/*c -I ./libft/include" > make.sh
ls
cat make.sh 
clear
ls
ls -l
chmod 755 make.sh 
ls
ls -a
ls -l
clear
chmod 744 make.sh 
ls -l
ls
clear
ls
cd ..
cd /
ls
cd srv/
ls
cd ..
ls
cd var/
ls
cd www
ls
cd html/
ls
vim index.nginx-debian.html 
ls
cd ..
ls
cd ..
ls
clear
ls
cd ~
ls
clear
vim default 
cd RPI_RADIO/
ls
clear
ls
vim nrf24l01_driver.c
vim nrf24l01_driver.h
vim nrf24l01_driver.c
clear
ls
cd ..
vim default 
./send lala
clear
vim default 
pkill radio
ls
clear
ls
vim default 
clear
ls
cd eoe-plot/
ls
vim index.css
cd RPI_RADIO/
./a.out 
vim radio.c
sh make.sh 
./a.out 
vim radio.c
./a.out 
clear
sh make.sh 
./a.out 
clear
vim radio.c
sh make.sh 
./a.out 
clear
ls
vim radio.c
sh make.sh 
./a.out 
vim radio.c
sh make.sh 
./a.out 
vim radio.c
sh make.sh 
clear
vim radio.c
sh make.sh 
./a.out 
clear
ls
vim radio.c
sh make.sh 
./a.out 
sh make.sh 
./a.out 
sh make.sh 
./a.out 
sh make.sh 
./a.out 
clear
ls
cd ..
ls
./send lala
./send buok
./send lala
./send buok
./send lala
./send buok
./send aaaa
./send bbbb
./send cccc
./send dddd
./send eeee
./send ffff
./send gggg
./send lala
./send ****
./send "****"
lear
clear
ls
./send lala lala lala
clear
ls
cd /var/www
ls
cd html/
ls
vim index.nginx-debian.html 
ls
cd ..
ls
cd ..
ls
cd ~
ls
cd /
ls
cd srv/
ls
cd ..
ls
cd ss
vim ssh 
cd ~/RPI_RADIO/
sh make.sh 
./a.out 
sh make.sh 
./a.out 
ls
clear
ls
./a.out 
sh make.sh 
./a.out 
sh make.sh 
./a.out 
sh make.sh 
./a.out 
clear
./a.out 
clear
sh make.sh 
./a.out 
sh make.sh 
./a.out 
sh make.sh 
sh make.sh
./a.out 
ll
ls
cd ..
ls -l
vim default 
ifconfig
sudo apt-get search php cgi
sudo apt search
sudo apt search php
sudo apt search fastcgi
sudo apt search php fastcgi
php
sudo apt search php7-fpm
sudo apt search php7
sudo apt search php
sudo apt search fpm

sudo apt search fpm
sudo apt search php-fpm
sudo apt-get install php5-fpm
sudo service php5-fpm start
sudo vi /etc/php5/fpm/php.ini
vim /etc/nginx/sites-enabled/eoe-plot 
sudo vim /etc/nginx/sites-enabled/eoe-plot 
nginx -t -c /etc/nginx/sites-enabled/eoe-plot
sudo nginx -t -c /etc/nginx/sites-enabled/eoe-plot
sudo vim /etc/nginx/sites-enabled/eoe-plot 
sudo service nginx restart 
sudo vim /etc/nginx/sites-enabled/eoe-plot 
vim /home/pi/eoe-plot/
cd /home/pi/eoe-plot/
ls
vim tt.php
rm tt.php 
vim config.html 
mv config.html config.php
vim index.html 
vim /etc/php5/fpm/php-fpm.conf 
vim /etc/php5/fpm/php.ini 
vim /etc/php5/fpm/conf.d/20-readline.ini 
vim /etc/php5/fpm/conf.d/10-pdo.ini 
vim /etc/php5/fpm/conf.d/05-opcache.ini 
vim /var/log/php5-fpm.log 
sudo vim /var/log/php5-fpm.log 
vim /etc/php5/fpm/php-fpm.conf 
sudo vim /etc/php5/fpm/php-fpm.conf 
sudo service php5-fpm restart 
sudo vim /etc/php5/fpm/pool.d/www.conf 
sudo service php5-fpm restart 
sudo vim /etc/php5/fpm/pool.d/www.conf 
sudo service php5-fpm restart 
sudo vim /etc/php5/fpm/pool.d/www.conf 
sudo service php5-fpm restart 
sudo vim /etc/php5/fpm/pool.d/www.conf 
sudo service php5-fpm restart 
ls ~
vim ~/default 
chmod 777 conf
touch conf
chmod 777 conf
vim conf
clear
cd RPI_RADIO/
vim radio.c
ls
clear
ls
vim radio.c
clear
cd ../eoe-plot/
ls
vim index.html
vim config.html
cp index.html config.html
vim config.html 
vim index.html 
vim config.html 
reset
rm -f config.html 
vim config.php 
reset
vim config.php 
sudo shutdown -t 0
ls
cd eoe-plot/
ls
vim conf
vim config.php 
ls
vim index.css
vim index.html
vim index.css 
ls
vim page02.html 
ls -l
cd ..
ls -l
vim gnuplot_auto.c 
./
vim radio 
ls -l
ate
date
./radio 
cd eoe-plot/
ls
ls -l ..
cd ..
cat page104.html 
cat page105.html 
ls -l
pwm
pwd
cd eoe-plot/
ls -l
let "var_a = 42 + 2"
echo $var_a
ls
cat page108.html 
let
vim test.sh
ll
ls
chmod + x test.sh 
chmod +x test.sh 
./test.sh 
ls -l
ls
cat page110.html 
ls -l
ls
cd 
exit
