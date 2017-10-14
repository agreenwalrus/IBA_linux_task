#! /usr/bin/perl

my $ans;
my $pid;

sub printProc {
 for ( my $i=0; $i < @_[0]; $i++) {
  print " ";
 }
 
 #print @_[0];   #am of spases
 print `ps --pid @_[1] -o cmd=,pid=,ppid=`;  #pid
 my @chld=split("\n", `ps --ppid @_[1] -o pid=`);
 printProc (@_[0] + 3, $_) for @chld; 
}

sub killProc {
 print @_[0];   #proc pid
 my @chld=split("\n", `ps --ppid @_[0] -o pid=`);
 killProc ($_) for @chld;
 `kill @_[0]`;
}

while (1) {
print "
HELP
1 - show all the process
2 - show all the process of curent user
3 - show all the children of the process with PID
4 - show all the children of the process with name
5 - kill the process with PID and all it's children
6 - exit\n
";

print "Your choise: ";
$ans=<STDIN>;
chop($ans);
if ($ans==1) { 
 print `pstree -p`;
} elsif ($ans==2) {
 print `ps -fH`;
} elsif ($ans==3) {
 print "Enter pid: ";
 $pid=<STDIN>;
 chomp($pid);
 printProc(0, $pid);
} elsif ($ans==4) {
 my $proc_name;
 my $result;
 print "Enter name: ";
 $proc_name=<STDIN>;
 chop($proc_name);
 $result = `ps -e -o cmd=,pid= | grep "$proc_name"`;
 $result =~ m/\s([0-9]+)/;
 printProc(0, $1);
} elsif ($ans==5) {
 print "Enter pid: ";
 $pid=<STDIN>;
 chomp($pid);
 killProc($pid);
} elsif ($ans==6) {
 last;
}
}
