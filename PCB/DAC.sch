EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 9
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 1300 4750 0    50   Input ~ 0
PA5
Text HLabel 1300 2550 0    50   Input ~ 0
PA4
Text HLabel 3750 4000 2    50   Input ~ 0
AO0
Text HLabel 5750 2550 0    50   Input ~ 0
PA6
Text HLabel 3750 6200 2    50   Input ~ 0
AO1
Text HLabel 8200 4000 2    50   Input ~ 0
AO2
$Comp
L Amplifier_Operational:LM2902 U3
U 2 1 62897178
P 2650 2650
F 0 "U3" H 2650 3017 50  0000 C CNN
F 1 "LM2902" H 2650 2926 50  0000 C CNN
F 2 "Package_SO:SOIC-14_3.9x8.7mm_P1.27mm" H 2600 2750 50  0001 C CNN
F 3 "863-LM2902DR2G" H 2700 2850 50  0001 C CNN
F 4 "Mouser" H 2650 2650 50  0001 C CNN "Comment"
	2    2650 2650
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:LM2902 U3
U 4 1 62899EB9
P 2500 3400
F 0 "U3" H 2500 3767 50  0000 C CNN
F 1 "LM2902" H 2500 3676 50  0000 C CNN
F 2 "Package_SO:SOIC-14_3.9x8.7mm_P1.27mm" H 2450 3500 50  0001 C CNN
F 3 "863-LM2902DR2G" H 2550 3600 50  0001 C CNN
F 4 "Mouser" H 2500 3400 50  0001 C CNN "Comment"
	4    2500 3400
	-1   0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:LM2902 U3
U 5 1 6289DAE3
P 1250 1250
F 0 "U3" H 1208 1296 50  0000 L CNN
F 1 "LM2902" H 1208 1205 50  0000 L CNN
F 2 "Package_SO:SOIC-14_3.9x8.7mm_P1.27mm" H 1200 1350 50  0001 C CNN
F 3 "863-LM2902DR2G" H 1300 1450 50  0001 C CNN
F 4 "Mouser" H 1250 1250 50  0001 C CNN "Comment"
	5    1250 1250
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:BC847 Q?
U 1 1 628A2B05
P 3400 2650
AR Path="/5FB17A23/628A2B05" Ref="Q?"  Part="1" 
AR Path="/5FAFDC1C/628A2B05" Ref="Q1"  Part="1" 
F 0 "Q1" H 3591 2696 50  0000 L CNN
F 1 "BC847C-QR" H 3591 2605 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 3600 2575 50  0001 L CIN
F 3 "771-BC847C-QR" H 3400 2650 50  0001 L CNN
F 4 "C2145" H 3400 2650 50  0001 C CNN "LCSC"
F 5 "Mouser" H 3400 2650 50  0001 C CNN "Comment"
	1    3400 2650
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 628B87CF
P 2550 4000
AR Path="/628B87CF" Ref="R?"  Part="1" 
AR Path="/5FB17A23/628B87CF" Ref="R?"  Part="1" 
AR Path="/5FAFDC1C/628B87CF" Ref="R41"  Part="1" 
F 0 "R41" H 2620 4046 50  0000 L CNN
F 1 "10k" H 2620 3955 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2480 4000 50  0001 C CNN
F 3 "791-WR06X103JTL" H 2550 4000 50  0001 C CNN
F 4 "C25804" H 2550 4000 50  0001 C CNN "LCSC"
F 5 "Mouser" H 2550 4000 50  0001 C CNN "Comment"
	1    2550 4000
	0    -1   1    0   
$EndComp
Wire Wire Line
	2200 3400 2200 2750
Wire Wire Line
	2200 2750 2350 2750
Wire Wire Line
	2200 3400 2200 4000
Wire Wire Line
	2200 4000 2400 4000
Connection ~ 2200 3400
Wire Wire Line
	2700 4000 2800 4000
Wire Wire Line
	2800 4000 2800 3500
$Comp
L Device:R R?
U 1 1 628BA5C9
P 3100 4000
AR Path="/628BA5C9" Ref="R?"  Part="1" 
AR Path="/5FB17A23/628BA5C9" Ref="R?"  Part="1" 
AR Path="/5FAFDC1C/628BA5C9" Ref="R81"  Part="1" 
F 0 "R81" H 3170 4046 50  0000 L CNN
F 1 "10k" H 3170 3955 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 3030 4000 50  0001 C CNN
F 3 "791-WR06X103JTL" H 3100 4000 50  0001 C CNN
F 4 "C25804" H 3100 4000 50  0001 C CNN "LCSC"
F 5 "Mouser" H 3100 4000 50  0001 C CNN "Comment"
	1    3100 4000
	0    -1   1    0   
$EndComp
Wire Wire Line
	2950 4000 2800 4000
Connection ~ 2800 4000
$Comp
L Device:R R?
U 1 1 628BF8B9
P 3500 3350
AR Path="/5FAFE50B/628BF8B9" Ref="R?"  Part="1" 
AR Path="/5FB05F69/628BF8B9" Ref="R?"  Part="1" 
AR Path="/628BF8B9" Ref="R?"  Part="1" 
AR Path="/5FC2CC0E/628BF8B9" Ref="R?"  Part="1" 
AR Path="/60B91B73/628BF8B9" Ref="R?"  Part="1" 
AR Path="/5FAFDC1C/628BF8B9" Ref="R87"  Part="1" 
F 0 "R87" H 3570 3396 50  0000 L CNN
F 1 "160" H 3570 3305 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 3430 3350 50  0001 C CNN
F 3 "660-RK73B1JTTD161J" H 3500 3350 50  0001 C CNN
F 4 "C22814" H 3500 3350 50  0001 C CNN "LCSC"
F 5 "Mouser" H 3500 3350 50  0001 C CNN "Comment"
	1    3500 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 3200 3500 2900
Wire Wire Line
	3500 3500 3500 4000
Wire Wire Line
	3500 4000 3250 4000
$Comp
L Device:R R?
U 1 1 628C0810
P 3100 3050
AR Path="/628C0810" Ref="R?"  Part="1" 
AR Path="/5FB17A23/628C0810" Ref="R?"  Part="1" 
AR Path="/5FAFDC1C/628C0810" Ref="R43"  Part="1" 
F 0 "R43" H 3170 3096 50  0000 L CNN
F 1 "10k" H 3170 3005 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 3030 3050 50  0001 C CNN
F 3 "791-WR06X103JTL" H 3100 3050 50  0001 C CNN
F 4 "C25804" H 3100 3050 50  0001 C CNN "LCSC"
F 5 "Mouser" H 3100 3050 50  0001 C CNN "Comment"
	1    3100 3050
	1    0    0    1   
$EndComp
$Comp
L Device:R R?
U 1 1 628C0B2A
P 3100 3500
AR Path="/628C0B2A" Ref="R?"  Part="1" 
AR Path="/5FB17A23/628C0B2A" Ref="R?"  Part="1" 
AR Path="/5FAFDC1C/628C0B2A" Ref="R80"  Part="1" 
F 0 "R80" H 3170 3546 50  0000 L CNN
F 1 "10k" H 3170 3455 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 3030 3500 50  0001 C CNN
F 3 "791-WR06X103JTL" H 3100 3500 50  0001 C CNN
F 4 "C25804" H 3100 3500 50  0001 C CNN "LCSC"
F 5 "Mouser" H 3100 3500 50  0001 C CNN "Comment"
	1    3100 3500
	1    0    0    1   
$EndComp
Wire Wire Line
	3100 3200 3100 3300
Wire Wire Line
	2800 3300 3100 3300
Connection ~ 3100 3300
Wire Wire Line
	3100 3300 3100 3350
Wire Wire Line
	3100 2900 3500 2900
Connection ~ 3500 2900
Wire Wire Line
	3500 2900 3500 2850
Wire Wire Line
	3200 2650 2950 2650
$Comp
L power:GND #PWR0101
U 1 1 628C244D
P 3100 3650
F 0 "#PWR0101" H 3100 3400 50  0001 C CNN
F 1 "GND" H 3105 3477 50  0000 C CNN
F 2 "" H 3100 3650 50  0001 C CNN
F 3 "" H 3100 3650 50  0001 C CNN
	1    3100 3650
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 628C4F8C
P 1600 2700
AR Path="/628C4F8C" Ref="C?"  Part="1" 
AR Path="/5FAFDC1C/628C4F8C" Ref="C21"  Part="1" 
F 0 "C21" H 1715 2746 50  0000 L CNN
F 1 "100nF" H 1715 2655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 1638 2550 50  0001 C CNN
F 3 "581-06033G104Z" H 1600 2700 50  0001 C CNN
F 4 "C14663" H 1600 2700 50  0001 C CNN "LCSC"
F 5 "Mouser" H 1600 2700 50  0001 C CNN "Comment"
	1    1600 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	2350 2550 1600 2550
Wire Wire Line
	1600 2550 1300 2550
Connection ~ 1600 2550
$Comp
L power:GND #PWR0108
U 1 1 628C5AB5
P 1600 2850
F 0 "#PWR0108" H 1600 2600 50  0001 C CNN
F 1 "GND" H 1605 2677 50  0000 C CNN
F 2 "" H 1600 2850 50  0001 C CNN
F 3 "" H 1600 2850 50  0001 C CNN
	1    1600 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 4000 3750 4000
Connection ~ 3500 4000
$Comp
L Amplifier_Operational:LM2902 U3
U 1 1 628D2168
P 2650 4850
F 0 "U3" H 2650 5217 50  0000 C CNN
F 1 "LM2902" H 2650 5126 50  0000 C CNN
F 2 "Package_SO:SOIC-14_3.9x8.7mm_P1.27mm" H 2600 4950 50  0001 C CNN
F 3 "863-LM2902DR2G" H 2700 5050 50  0001 C CNN
F 4 "Mouser" H 2650 4850 50  0001 C CNN "Comment"
	1    2650 4850
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:LM2902 U3
U 3 1 628D216E
P 2500 5600
F 0 "U3" H 2500 5967 50  0000 C CNN
F 1 "LM2902" H 2500 5876 50  0000 C CNN
F 2 "Package_SO:SOIC-14_3.9x8.7mm_P1.27mm" H 2450 5700 50  0001 C CNN
F 3 "863-LM2902DR2G" H 2550 5800 50  0001 C CNN
F 4 "Mouser" H 2500 5600 50  0001 C CNN "Comment"
	3    2500 5600
	-1   0    0    -1  
$EndComp
$Comp
L Transistor_BJT:BC847 Q?
U 1 1 628D2175
P 3400 4850
AR Path="/5FB17A23/628D2175" Ref="Q?"  Part="1" 
AR Path="/5FAFDC1C/628D2175" Ref="Q2"  Part="1" 
F 0 "Q2" H 3591 4896 50  0000 L CNN
F 1 "BC847C-QR" H 3591 4805 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 3600 4775 50  0001 L CIN
F 3 "771-BC847C-QR" H 3400 4850 50  0001 L CNN
F 4 "C2145" H 3400 4850 50  0001 C CNN "LCSC"
F 5 "Mouser" H 3400 4850 50  0001 C CNN "Comment"
	1    3400 4850
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 628D217C
P 2550 6200
AR Path="/628D217C" Ref="R?"  Part="1" 
AR Path="/5FB17A23/628D217C" Ref="R?"  Part="1" 
AR Path="/5FAFDC1C/628D217C" Ref="R42"  Part="1" 
F 0 "R42" H 2620 6246 50  0000 L CNN
F 1 "10k" H 2620 6155 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2480 6200 50  0001 C CNN
F 3 "791-WR06X103JTL" H 2550 6200 50  0001 C CNN
F 4 "C25804" H 2550 6200 50  0001 C CNN "LCSC"
F 5 "Mouser" H 2550 6200 50  0001 C CNN "Comment"
	1    2550 6200
	0    -1   1    0   
$EndComp
Wire Wire Line
	2200 5600 2200 4950
Wire Wire Line
	2200 4950 2350 4950
Wire Wire Line
	2200 5600 2200 6200
Wire Wire Line
	2200 6200 2400 6200
Connection ~ 2200 5600
Wire Wire Line
	2700 6200 2800 6200
Wire Wire Line
	2800 6200 2800 5700
$Comp
L Device:R R?
U 1 1 628D218A
P 3100 6200
AR Path="/628D218A" Ref="R?"  Part="1" 
AR Path="/5FB17A23/628D218A" Ref="R?"  Part="1" 
AR Path="/5FAFDC1C/628D218A" Ref="R86"  Part="1" 
F 0 "R86" H 3170 6246 50  0000 L CNN
F 1 "10k" H 3170 6155 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 3030 6200 50  0001 C CNN
F 3 "791-WR06X103JTL" H 3100 6200 50  0001 C CNN
F 4 "C25804" H 3100 6200 50  0001 C CNN "LCSC"
F 5 "Mouser" H 3100 6200 50  0001 C CNN "Comment"
	1    3100 6200
	0    -1   1    0   
$EndComp
Wire Wire Line
	2950 6200 2800 6200
Connection ~ 2800 6200
$Comp
L Device:R R?
U 1 1 628D2193
P 3500 5550
AR Path="/5FAFE50B/628D2193" Ref="R?"  Part="1" 
AR Path="/5FB05F69/628D2193" Ref="R?"  Part="1" 
AR Path="/628D2193" Ref="R?"  Part="1" 
AR Path="/5FC2CC0E/628D2193" Ref="R?"  Part="1" 
AR Path="/60B91B73/628D2193" Ref="R?"  Part="1" 
AR Path="/5FAFDC1C/628D2193" Ref="R88"  Part="1" 
F 0 "R88" H 3570 5596 50  0000 L CNN
F 1 "160" H 3570 5505 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 3430 5550 50  0001 C CNN
F 3 "660-RK73B1JTTD161J" H 3500 5550 50  0001 C CNN
F 4 "C22814" H 3500 5550 50  0001 C CNN "LCSC"
F 5 "Mouser" H 3500 5550 50  0001 C CNN "Comment"
	1    3500 5550
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 5400 3500 5100
Wire Wire Line
	3500 5700 3500 6200
Wire Wire Line
	3500 6200 3250 6200
$Comp
L Device:R R?
U 1 1 628D219D
P 3100 5250
AR Path="/628D219D" Ref="R?"  Part="1" 
AR Path="/5FB17A23/628D219D" Ref="R?"  Part="1" 
AR Path="/5FAFDC1C/628D219D" Ref="R84"  Part="1" 
F 0 "R84" H 3170 5296 50  0000 L CNN
F 1 "10k" H 3170 5205 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 3030 5250 50  0001 C CNN
F 3 "791-WR06X103JTL" H 3100 5250 50  0001 C CNN
F 4 "C25804" H 3100 5250 50  0001 C CNN "LCSC"
F 5 "Mouser" H 3100 5250 50  0001 C CNN "Comment"
	1    3100 5250
	1    0    0    1   
$EndComp
$Comp
L Device:R R?
U 1 1 628D21A4
P 3100 5700
AR Path="/628D21A4" Ref="R?"  Part="1" 
AR Path="/5FB17A23/628D21A4" Ref="R?"  Part="1" 
AR Path="/5FAFDC1C/628D21A4" Ref="R85"  Part="1" 
F 0 "R85" H 3170 5746 50  0000 L CNN
F 1 "10k" H 3170 5655 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 3030 5700 50  0001 C CNN
F 3 "791-WR06X103JTL" H 3100 5700 50  0001 C CNN
F 4 "C25804" H 3100 5700 50  0001 C CNN "LCSC"
F 5 "Mouser" H 3100 5700 50  0001 C CNN "Comment"
	1    3100 5700
	1    0    0    1   
$EndComp
Wire Wire Line
	3100 5400 3100 5500
Wire Wire Line
	2800 5500 3100 5500
Connection ~ 3100 5500
Wire Wire Line
	3100 5500 3100 5550
Wire Wire Line
	3100 5100 3500 5100
Connection ~ 3500 5100
Wire Wire Line
	3500 5100 3500 5050
Wire Wire Line
	3200 4850 2950 4850
$Comp
L power:GND #PWR0115
U 1 1 628D21B2
P 3100 5850
F 0 "#PWR0115" H 3100 5600 50  0001 C CNN
F 1 "GND" H 3105 5677 50  0000 C CNN
F 2 "" H 3100 5850 50  0001 C CNN
F 3 "" H 3100 5850 50  0001 C CNN
	1    3100 5850
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 628D21B9
P 1600 4900
AR Path="/628D21B9" Ref="C?"  Part="1" 
AR Path="/5FAFDC1C/628D21B9" Ref="C22"  Part="1" 
F 0 "C22" H 1715 4946 50  0000 L CNN
F 1 "100nF" H 1715 4855 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 1638 4750 50  0001 C CNN
F 3 "581-06033G104Z" H 1600 4900 50  0001 C CNN
F 4 "C14663" H 1600 4900 50  0001 C CNN "LCSC"
F 5 "Mouser" H 1600 4900 50  0001 C CNN "Comment"
	1    1600 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	2350 4750 1600 4750
Wire Wire Line
	1600 4750 1300 4750
Connection ~ 1600 4750
$Comp
L power:GND #PWR0116
U 1 1 628D21C2
P 1600 5050
F 0 "#PWR0116" H 1600 4800 50  0001 C CNN
F 1 "GND" H 1605 4877 50  0000 C CNN
F 2 "" H 1600 5050 50  0001 C CNN
F 3 "" H 1600 5050 50  0001 C CNN
	1    1600 5050
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 6200 3750 6200
Connection ~ 3500 6200
$Comp
L power:GND #PWR0119
U 1 1 628DA8B0
P 1150 1550
F 0 "#PWR0119" H 1150 1300 50  0001 C CNN
F 1 "GND" H 1155 1377 50  0000 C CNN
F 2 "" H 1150 1550 50  0001 C CNN
F 3 "" H 1150 1550 50  0001 C CNN
	1    1150 1550
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:LM2904 U5
U 1 1 628DBEEB
P 7100 2650
F 0 "U5" H 7100 3017 50  0000 C CNN
F 1 "LM2904" H 7100 2926 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 7100 2650 50  0001 C CNN
F 3 "863-LM2904DR2G" H 7100 2650 50  0001 C CNN
F 4 "Mouser" H 7100 2650 50  0001 C CNN "Comment"
	1    7100 2650
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:LM2904 U5
U 2 1 628DE2C0
P 6950 3400
F 0 "U5" H 6950 3767 50  0000 C CNN
F 1 "LM2904" H 6950 3676 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 6950 3400 50  0001 C CNN
F 3 "863-LM2904DR2G" H 6950 3400 50  0001 C CNN
F 4 "Mouser" H 6950 3400 50  0001 C CNN "Comment"
	2    6950 3400
	-1   0    0    -1  
$EndComp
$Comp
L Transistor_BJT:BC847 Q?
U 1 1 628E6496
P 7850 2650
AR Path="/5FB17A23/628E6496" Ref="Q?"  Part="1" 
AR Path="/5FAFDC1C/628E6496" Ref="Q3"  Part="1" 
F 0 "Q3" H 8041 2696 50  0000 L CNN
F 1 "BC847C-QR" H 8041 2605 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 8050 2575 50  0001 L CIN
F 3 "771-BC847C-QR" H 7850 2650 50  0001 L CNN
F 4 "C2145" H 7850 2650 50  0001 C CNN "LCSC"
F 5 "Mouser" H 7850 2650 50  0001 C CNN "Comment"
	1    7850 2650
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 628E649D
P 7000 4000
AR Path="/628E649D" Ref="R?"  Part="1" 
AR Path="/5FB17A23/628E649D" Ref="R?"  Part="1" 
AR Path="/5FAFDC1C/628E649D" Ref="R89"  Part="1" 
F 0 "R89" H 7070 4046 50  0000 L CNN
F 1 "10k" H 7070 3955 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 6930 4000 50  0001 C CNN
F 3 "791-WR06X103JTL" H 7000 4000 50  0001 C CNN
F 4 "C25804" H 7000 4000 50  0001 C CNN "LCSC"
F 5 "Mouser" H 7000 4000 50  0001 C CNN "Comment"
	1    7000 4000
	0    -1   1    0   
$EndComp
Wire Wire Line
	6650 2750 6800 2750
Wire Wire Line
	6650 4000 6850 4000
Wire Wire Line
	7150 4000 7250 4000
Wire Wire Line
	7250 4000 7250 3500
$Comp
L Device:R R?
U 1 1 628E64AB
P 7550 4000
AR Path="/628E64AB" Ref="R?"  Part="1" 
AR Path="/5FB17A23/628E64AB" Ref="R?"  Part="1" 
AR Path="/5FAFDC1C/628E64AB" Ref="R92"  Part="1" 
F 0 "R92" H 7620 4046 50  0000 L CNN
F 1 "10k" H 7620 3955 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 7480 4000 50  0001 C CNN
F 3 "791-WR06X103JTL" H 7550 4000 50  0001 C CNN
F 4 "C25804" H 7550 4000 50  0001 C CNN "LCSC"
F 5 "Mouser" H 7550 4000 50  0001 C CNN "Comment"
	1    7550 4000
	0    -1   1    0   
$EndComp
Wire Wire Line
	7400 4000 7250 4000
Connection ~ 7250 4000
$Comp
L Device:R R?
U 1 1 628E64B4
P 7950 3350
AR Path="/5FAFE50B/628E64B4" Ref="R?"  Part="1" 
AR Path="/5FB05F69/628E64B4" Ref="R?"  Part="1" 
AR Path="/628E64B4" Ref="R?"  Part="1" 
AR Path="/5FC2CC0E/628E64B4" Ref="R?"  Part="1" 
AR Path="/60B91B73/628E64B4" Ref="R?"  Part="1" 
AR Path="/5FAFDC1C/628E64B4" Ref="R93"  Part="1" 
F 0 "R93" H 8020 3396 50  0000 L CNN
F 1 "160" H 8020 3305 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 7880 3350 50  0001 C CNN
F 3 "660-RK73B1JTTD161J" H 7950 3350 50  0001 C CNN
F 4 "C22814" H 7950 3350 50  0001 C CNN "LCSC"
F 5 "Mouser" H 7950 3350 50  0001 C CNN "Comment"
	1    7950 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	7950 3200 7950 2900
Wire Wire Line
	7950 3500 7950 4000
Wire Wire Line
	7950 4000 7700 4000
$Comp
L Device:R R?
U 1 1 628E64BE
P 7550 3050
AR Path="/628E64BE" Ref="R?"  Part="1" 
AR Path="/5FB17A23/628E64BE" Ref="R?"  Part="1" 
AR Path="/5FAFDC1C/628E64BE" Ref="R90"  Part="1" 
F 0 "R90" H 7620 3096 50  0000 L CNN
F 1 "10k" H 7620 3005 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 7480 3050 50  0001 C CNN
F 3 "791-WR06X103JTL" H 7550 3050 50  0001 C CNN
F 4 "C25804" H 7550 3050 50  0001 C CNN "LCSC"
F 5 "Mouser" H 7550 3050 50  0001 C CNN "Comment"
	1    7550 3050
	1    0    0    1   
$EndComp
$Comp
L Device:R R?
U 1 1 628E64C5
P 7550 3500
AR Path="/628E64C5" Ref="R?"  Part="1" 
AR Path="/5FB17A23/628E64C5" Ref="R?"  Part="1" 
AR Path="/5FAFDC1C/628E64C5" Ref="R91"  Part="1" 
F 0 "R91" H 7620 3546 50  0000 L CNN
F 1 "10k" H 7620 3455 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 7480 3500 50  0001 C CNN
F 3 "791-WR06X103JTL" H 7550 3500 50  0001 C CNN
F 4 "C25804" H 7550 3500 50  0001 C CNN "LCSC"
F 5 "Mouser" H 7550 3500 50  0001 C CNN "Comment"
	1    7550 3500
	1    0    0    1   
$EndComp
Wire Wire Line
	7550 3200 7550 3300
Wire Wire Line
	7250 3300 7550 3300
Connection ~ 7550 3300
Wire Wire Line
	7550 3300 7550 3350
Wire Wire Line
	7550 2900 7950 2900
Connection ~ 7950 2900
Wire Wire Line
	7950 2900 7950 2850
Wire Wire Line
	7650 2650 7400 2650
$Comp
L power:GND #PWR0123
U 1 1 628E64D3
P 7550 3650
F 0 "#PWR0123" H 7550 3400 50  0001 C CNN
F 1 "GND" H 7555 3477 50  0000 C CNN
F 2 "" H 7550 3650 50  0001 C CNN
F 3 "" H 7550 3650 50  0001 C CNN
	1    7550 3650
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 628E64DA
P 6050 2700
AR Path="/628E64DA" Ref="C?"  Part="1" 
AR Path="/5FAFDC1C/628E64DA" Ref="C24"  Part="1" 
F 0 "C24" H 6165 2746 50  0000 L CNN
F 1 "100nF" H 6165 2655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 6088 2550 50  0001 C CNN
F 3 "581-06033G104Z" H 6050 2700 50  0001 C CNN
F 4 "C14663" H 6050 2700 50  0001 C CNN "LCSC"
F 5 "Mouser" H 6050 2700 50  0001 C CNN "Comment"
	1    6050 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 2550 6050 2550
Wire Wire Line
	6050 2550 5750 2550
Connection ~ 6050 2550
$Comp
L power:GND #PWR0124
U 1 1 628E64E3
P 6050 2850
F 0 "#PWR0124" H 6050 2600 50  0001 C CNN
F 1 "GND" H 6055 2677 50  0000 C CNN
F 2 "" H 6050 2850 50  0001 C CNN
F 3 "" H 6050 2850 50  0001 C CNN
	1    6050 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	7950 4000 8200 4000
Connection ~ 7950 4000
Wire Wire Line
	6650 2750 6650 3400
Connection ~ 6650 3400
Wire Wire Line
	6650 3400 6650 4000
$Comp
L Amplifier_Operational:LM2904 U5
U 3 1 628FBF37
P 1500 1250
F 0 "U5" H 1312 1296 50  0000 R CNN
F 1 "LM2904" H 1312 1205 50  0000 R CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 1500 1250 50  0001 C CNN
F 3 "863-LM2904DR2G" H 1500 1250 50  0001 C CNN
F 4 "Mouser" H 1500 1250 50  0001 C CNN "Comment"
	3    1500 1250
	-1   0    0    -1  
$EndComp
Wire Notes Line
	700  600  700  1900
Wire Notes Line
	2700 1900 2700 600 
Text Notes 1900 1850 0    50   ~ 0
Supply for Op-amp
$Comp
L Device:C C31
U 1 1 62547921
P 3100 1150
F 0 "C31" H 3215 1196 50  0000 L CNN
F 1 "10uF" H 3215 1105 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 3138 1000 50  0001 C CNN
F 3 "81-GRM319R6YA106MA2D" H 3100 1150 50  0001 C CNN
F 4 "Mouser" H 3100 1150 50  0001 C CNN "Comment"
	1    3100 1150
	1    0    0    -1  
$EndComp
Wire Notes Line
	700  1900 2700 1900
Wire Notes Line
	700  600  2700 600 
Text HLabel 3000 850  0    50   Input ~ 0
VDC
Text Notes 3050 1850 0    50   ~ 0
Voltage reverse protection
$Comp
L power:GND #PWR0177
U 1 1 624F96CE
P 1600 1550
F 0 "#PWR0177" H 1600 1300 50  0001 C CNN
F 1 "GND" H 1605 1377 50  0000 C CNN
F 2 "" H 1600 1550 50  0001 C CNN
F 3 "" H 1600 1550 50  0001 C CNN
	1    1600 1550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0171
U 1 1 62902460
P 3100 1450
F 0 "#PWR0171" H 3100 1200 50  0001 C CNN
F 1 "GND" H 3105 1277 50  0000 C CNN
F 2 "" H 3100 1450 50  0001 C CNN
F 3 "" H 3100 1450 50  0001 C CNN
	1    3100 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3100 1450 3100 1300
Wire Wire Line
	3100 1000 3100 850 
Wire Wire Line
	3100 850  3000 850 
Connection ~ 3100 850 
$Comp
L power:GND #PWR0219
U 1 1 62521A45
P 3600 1450
F 0 "#PWR0219" H 3600 1200 50  0001 C CNN
F 1 "GND" H 3605 1277 50  0000 C CNN
F 2 "" H 3600 1450 50  0001 C CNN
F 3 "" H 3600 1450 50  0001 C CNN
	1    3600 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3600 1200 3600 1450
Wire Notes Line
	4650 600  4650 1900
Wire Notes Line
	2750 600  2750 1900
Wire Notes Line
	2750 1900 4650 1900
Wire Notes Line
	2750 600  4650 600 
Wire Wire Line
	3800 850  3600 850 
Wire Wire Line
	3600 850  3600 900 
Connection ~ 3600 850 
$Comp
L Device:D D44
U 1 1 62517A19
P 3600 1050
F 0 "D44" V 3554 1130 50  0000 L CNN
F 1 "SK56A-LTP" V 3645 1130 50  0000 L CNN
F 2 "Diode_SMD:D_SMA" H 3600 1050 50  0001 C CNN
F 3 "833-SK56A-LTP" H 3600 1050 50  0001 C CNN
F 4 "Mouser" H 3600 1050 50  0001 C CNN "Comment"
	1    3600 1050
	0    1    1    0   
$EndComp
Wire Wire Line
	3100 850  3600 850 
Text HLabel 3800 850  2    50   Input ~ 0
VDC
Text HLabel 1600 950  1    50   Input ~ 0
VDC
Text HLabel 1150 950  1    50   Input ~ 0
VDC
Text HLabel 3500 2450 1    50   Input ~ 0
VDC
Text HLabel 7950 2450 1    50   Input ~ 0
VDC
Text HLabel 3500 4650 1    50   Input ~ 0
VDC
$EndSCHEMATC
