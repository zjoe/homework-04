##WordsSearch生成，验证工具

new.c		:读入words.txt 生成 result.txt 

test.c		:读入（默认读入sample.txt 需要指定参数伟result.txt） 屏幕生成测试结果说明

words.txt	:第一行一个整数n，表示以下有n行单词

result.txt	:new生成的结果，第一行一个整数n，以下n行单词，最后输出一个矩阵

sample.txt	:老师网站上的例子

new			:new.c的可执行文件(under linux)

##new.c使用方法

>gcc new.c -o new
>./new 18 18 #生成18\*18的结果矩阵（有很小的几率出错）

目前可以生成的最优矩阵为18\*18


	K MXUNIL      OFAQ
	 SPEYELIMSURIVPOU 
	 AI DOCUMENT  ENS 
	 VHDROWSSAPPRINTER
	TECCAPMENUFREEWARE
	BRSCOOINOCITOME NR
	 SOUBLIMULTIMEDIAA
	CPUPYFCYBERSPACEMW
	Y NLEASBUGO SDRWEY
	  DOKRAQTBJ O EPLP
	 TCAIEICPEAWIBVOIS
	 OADTTUPNINNB RTFW
	 OR EAU HLHRD EKPO
	JBDN HBLOEOAEWSSID
	PEHSARCAOWRVCHIEZN
	EREVIRDASSSA KTD I
	GIGABYTECEEJL EETW
	FIREWIRE  ERAWDRAH

test  result from my test.c

	STATE1:	is good!
	K   M X-U-N-I-L             O F-A-Q 
	 \   \       /              | |     
	  S P E Y-E-L-I-M-S-U-R-I-V P O U   
	  |\|  \   /                | | |   
	  A I   D-O-C-U-M-E-N-T     E N S   
	  | |\  |/                  | | |   
	  V H D-R-O-W-S-S-A-P P-R-I-N-T-E-R 
	  | |  /|  \                    |   
	T E C C A P M-E-N-U F-R-E-E-W-A-R-E 
	 \   /  | |            /        | | 
	B R S C O O I N-O-C-I-T-O-M-E   N R 
	 \ \|/  | | |        /          | | 
	  S O U B L I M-U-L-T-I-M-E-D-I-A A 
	   \|\| | | |      /|           | | 
	C-P-U P Y F C-Y-B-E-R-S-P-A-C-E M W 
	 /  | |\| | |    /  |           | | 
	Y   N L E A S B-U-G O   S D R W E Y 
	    |\| |\| |  /    |   |/  |/  | | 
	    D O K R A Q T B J   O   E P L P 
	    |\|\  |\ /   \ \|  /|  /| | | | 
	  T C A I E I-C-P E A W I B V O I S 
	  | | |\ \|/ \     \|\  |/  | | | | 
	  O A D T T-U-P-N-I N N B   R T F W 
	  | |    / \   \   /|\ \    | | | | 
	  O R   E A U   H L H R D   E K P O 
	  | |  / \ \ \   /  |\ \ \  | | | | 
	J B D N   H B L O E O A E W S S I D 
	| |        \ \ \   /| |\ \ \  | | | 
	P E H-S-A-R-C A O W R V C H I E Z N 
	| |          \ \ \  |\|  \ \ \|   | 
	E R-E-V-I-R-D A S S S A   K T D   I 
	|              \ \ \| |\   \ \ \  | 
	G-I-G-A-B-Y-T-E C E E J L   E E T W 
	             /       \       \   \  
	F-I-R-E-W-I-R-E     E-R-A-W-D-R-A-H 

	STATE2:	is good! n&m = 18

	STATE3:	is good!


##test.c使用方法
输出结果显示是否满足1，2，3条件

	1、每个单词只出现且必须出现一次、没空行空列
	2、长宽必须一样
	3、四个角必须被单词包含

对于sample.txt文件，输出：

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

