
本程序可以实现wordsearch的验证工作

##使用方法

指定的输入文件\<file name\>（默认input.txt）第一行包含一个整数n表示有n个单词。

接下来n行每行一个单词

最后包含一个矩阵

比如

	57
	ASCII
	BANDWIDTH
	BIOS
	BUG
	CACHE
	CHIP
	COPY
	CPU
	CRASH
	CYBERSPACE
	DATABASE
	DESKTOP
	DISK
	DOCUMENT
	DOWNLOAD
	DRIVER
	EMOTICON
	ETHERNET
	FAQ
	FIREWIRE
	FONT
	FREEWARE
	GIGABYTE
	HACKER
	HARDWARE
	INPUT
	JAVA
	JPEG
	KEYBOARD
	LINUX
	MENU
	MODEM
	MULTIMEDIA
	NETIQUETTE
	OPEN
	PASSWORD
	PCI
	PERIPHERAL
	PORT
	PRINTER
	REBOOT
	RESOLUTION
	SAVE
	SCROLL
	SERVER
	SMILEY
	SOUNDCARD
	SPYWARE
	TERAFLOP
	TROJANHORSE
	UPLOAD
	USB
	USERNAME
	VIRUS
	WEBBROWSER
	WINDOWS
	ZIPFILE
	JPEGEMHTDIWDNABIXIM
	CEERRSNDCACHEEBSUNE
	DVMEAORORWVRPRYTNPD
	DAOKFWCOEOAAIAEEIUO
	OSTCUPYBHWWIJWLRLTM
	WPIAUNBPENCSDDIAAED
	NOCHBREESSAASRMFRNO
	LTOIOARMAROJNASLERC
	OKNWCFSONLDOOHPOHEU
	ASSFARPEPEIRERPPPHM
	DEWQIOAUUTTLARTRITE
	RDOVRRCSUSIIICENREN
	SRDTIOELHFCNQBDPECT
	EINEPROWPGTROUINPPS
	RVIYNSUIIEUOOHEDUOO
	VEWAESZSRRTBCLSTIOO
	ERMRMULTIMEDIALBTSS
	REGIGABYTERDRAOBYEK

输出结果显示是否满足1，2，3条件

	1、每个单词只出现且必须出现一次、没空行空列
	2、长宽必须一样
	3、四个角必须被单词包含

对于上述文件，输出：

	STATE1:	is good!
	J-P-E-G E M H-T-D-I-W-D-N-A-B I X I M 
	     \   \   /                  | | | 
	C E E R R S N D C-A-C-H-E E B-S-U N E 
	  | | |\   \   \   \   /  |     | | | 
	D V M E A O R O R W V R P R Y T N P D 
	 \| | |  \   \   \   /    | | | | | | 
	D A O K F W C O E O A A I A E E I U O 
	| |\| |    \|  \   \   /  | | | | | | 
	O S T C U P Y B H W W I J W L R L T M 
	|   |\|  \  |\   \   \    | | | | |   
	W P I A U N B P E N C S D D I A A E D 
	| |\| |\   \|  /   \   /  | | | | | | 
	N O C H B R E E S S A A S R M F R N O 
	| | |\   /  |/   /   \   \| | | | | | 
	L T O I O A R M A R O J N A S L E R C 
	| | |  /   /|      /   /  |\  | | | | 
	O K N W C F S O N L D O O H P O H E U 
	| |  /   /  |\   /   \   \    | | | | 
	A S S F A R P E P E I R E R P P P H M 
	| |/|  \   /|  /   /   \   \    | | | 
	D E W Q I O A U U T T L A R T R I T E 
	 /| |    /  |\ / /   /   \   /  | | | 
	R D O V R R C S U S I I I C E N R E N 
	  | |  \   /|/ /   /   /   \   \|   | 
	S R D T I O E L H F C N Q B D P E C T 
	| | |    / / /   /   \   /   \  |\    
	E I N E P R O W P G T R O U I N P P S 
	| | |  / / /   /   \   \   /   \   /  
	R V I Y N S U I I E U O O H E D U O O 
	| | |  / /   /   /   \   /   \ \ \    
	V E W A E S Z S R R T B C L S T I O O 
	| |  / /           \       \   / \ \  
	E R M R M-U-L-T-I-M-E-D-I-A L B T S S 
	|  /                             \ \  
	R E G-I-G-A-B-Y-T-E R D-R-A-O-B-Y-E-K 

	STATE2:	bad! n=18 m=19

	STATE3:	is good!

