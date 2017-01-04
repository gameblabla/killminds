===========
KillMinds
=========== 

Copyright Gameblabla, 2016

Sound Effects by Jesus Lastra, licensed under the Creative Commons Attribution-ShareAlike version 3.0 license.

The game code is licensed under the GAMEBLABLA's VIDEO GAME PUBLIC LICENSE, a custom license.

Read the file COPYRIGHT for more details.

Killminds is a puzzle game made by gameblabla, first released for the 3DO in 2013.
In September 2016, i have decided to enhance it for mobile devices and this is the result of that.
Killminds is a clone of SupraKillMinds for Sega Genesis by Jack Nolddor, with some improvements and changes to the gameplay.
SupraKillminds in itself was too inspired by Quartet, another similar puzzle game.

KillMinds was released on September 20, 2016 for Android and Sailfish OS on September 23, 2016.
Other platforms include the 3DO, the TI Nspire CX and the NUON.

The goal is simple : fill the 4 slots with a square given to you.
A full single color square will give you 300 points, anything else will give you 30 points.
But if you chain several full single color squares in a row, your score will be multiplied !
If you score 1000 points, you will get an extra live.
But be careful !

The more you progress, the harder it gets, to the point of being almost impossible.

Will you be able to master this game ? Find out in KillMinds !


=============
Compilation
=============

The build system for Android is not yet provided, but basically it's this :
On Android, it uses JNI : SDL2 and SDL2_mixer are compiled as shared libraries.
Then, it is simply a matter of using ndk-build and packing things up with ant.

For Sailfish OS, you have everything you need up but you need to have the official SailfishOS SDK.
There are some bugs for the ARM binary however...
Run sb2 -t SailfishOS-armv7hl make -f Makefile.sail before using the commands from "Compilation_sailfish.txt".
You should get a RPM file in a newly-created folder RPMS.