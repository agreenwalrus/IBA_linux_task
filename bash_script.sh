#! /bin/bash

#Script for bash with some 
#simple commands.
#It's difficult to be a creative person
#when you have to do a lot of labs
#at university. 

function my_help {
 echo 1 - list current directory
 echo 2 - see proccesses
 echo 3 - clean screan
 echo 4 - create or clear file
 echo 5 - write msg to file
 echo 6 - show the file
 echo 7 - exit
}
SCRIPT_NAME=$1
if [ "$1" ] 
then
 :
else
 SCRIPT_NAME=$USER
fi
while [ 1 ]
do
 echo "$SCRIPT_NAME, please, enter any command!"
 my_help
 read -r ans
 case $ans in
  1) ls -al;
   ;;
  2) ps -ux; 
   ;;
  3) clear;
   ;;
  4) touch file;
   ;;
  5) echo "Enter msg to write it to file:" 
     read -r msg;
     echo $msg >> file;
   ;;
  6) cat file;
   ;;
  7) echo Bye;
     exit;
   ;;
  *) echo Unknown
   ;;
esac
done

