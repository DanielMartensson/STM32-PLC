EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 6 9
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Device:R R?
U 1 1 608DE1A3
P 2450 6000
AR Path="/5FAFE50B/608DE1A3" Ref="R?"  Part="1" 
AR Path="/5FB05F69/608DE1A3" Ref="R?"  Part="1" 
AR Path="/608DE1A3" Ref="R?"  Part="1" 
AR Path="/5FC2CC0E/608DE1A3" Ref="R29"  Part="1" 
AR Path="/60B91B73/608DE1A3" Ref="R21"  Part="1" 
F 0 "R21" H 2520 6046 50  0000 L CNN
F 1 "160" H 2520 5955 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2380 6000 50  0001 C CNN
F 3 "660-RK73B1JTTD161J" H 2450 6000 50  0001 C CNN
F 4 "C22814" H 2450 6000 50  0001 C CNN "LCSC"
F 5 "Mouser" H 2450 6000 50  0001 C CNN "Comment"
	1    2450 6000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2450 5850 2450 5700
Wire Wire Line
	2450 5700 2600 5700
$Comp
L Device:Polyfuse F?
U 1 1 608DE1A4
P 2050 5700
AR Path="/5FAFE50B/608DE1A4" Ref="F?"  Part="1" 
AR Path="/5FB05F69/608DE1A4" Ref="F?"  Part="1" 
AR Path="/608DE1A4" Ref="F?"  Part="1" 
AR Path="/5FC2CC0E/608DE1A4" Ref="F11"  Part="1" 
AR Path="/60B91B73/608DE1A4" Ref="F10"  Part="1" 
F 0 "F10" V 1825 5700 50  0000 C CNN
F 1 "Max 30mA" V 1916 5700 50  0000 C CNN
F 2 "Fuse:Fuse_0603_1608Metric" H 2100 5500 50  0001 L CNN
F 3 "530-0ZCM0001FF2G" H 2050 5700 50  0001 C CNN
F 4 "C426238" H 2050 5700 50  0001 C CNN "LCSC"
F 5 "Mouser" H 2050 5700 50  0001 C CNN "Comment"
	1    2050 5700
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 608DE1A5
P 2450 6150
AR Path="/5FAFE50B/608DE1A5" Ref="#PWR?"  Part="1" 
AR Path="/5FB05F69/608DE1A5" Ref="#PWR?"  Part="1" 
AR Path="/608DE1A5" Ref="#PWR?"  Part="1" 
AR Path="/5FC2CC0E/608DE1A5" Ref="#PWR065"  Part="1" 
AR Path="/60B91B73/608DE1A5" Ref="#PWR0127"  Part="1" 
F 0 "#PWR0127" H 2450 5900 50  0001 C CNN
F 1 "GND" H 2455 5977 50  0000 C CNN
F 2 "" H 2450 6150 50  0001 C CNN
F 3 "" H 2450 6150 50  0001 C CNN
	1    2450 6150
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 5700 2450 5700
Connection ~ 2450 5700
Wire Wire Line
	2900 5700 3600 5700
Text HLabel 1900 5700 0    50   Input ~ 0
DAI2P
Text HLabel 7700 3450 2    50   Input ~ 0
PD9
$Comp
L Device:R R?
U 1 1 5FC4BD57
P 6550 2850
AR Path="/5FAFE50B/5FC4BD57" Ref="R?"  Part="1" 
AR Path="/5FB05F69/5FC4BD57" Ref="R?"  Part="1" 
AR Path="/5FC4BD57" Ref="R?"  Part="1" 
AR Path="/5FC2CC0E/5FC4BD57" Ref="R30"  Part="1" 
AR Path="/60B91B73/5FC4BD57" Ref="R18"  Part="1" 
F 0 "R18" H 6620 2896 50  0000 L CNN
F 1 "160" H 6620 2805 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 6480 2850 50  0001 C CNN
F 3 "660-RK73B1JTTD161J" H 6550 2850 50  0001 C CNN
F 4 "C22814" H 6550 2850 50  0001 C CNN "LCSC"
F 5 "Mouser" H 6550 2850 50  0001 C CNN "Comment"
	1    6550 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	6550 2700 6550 2550
Wire Wire Line
	6550 2550 6700 2550
$Comp
L Device:Polyfuse F?
U 1 1 5FC4BD7A
P 6150 2550
AR Path="/5FAFE50B/5FC4BD7A" Ref="F?"  Part="1" 
AR Path="/5FB05F69/5FC4BD7A" Ref="F?"  Part="1" 
AR Path="/5FC4BD7A" Ref="F?"  Part="1" 
AR Path="/5FC2CC0E/5FC4BD7A" Ref="F12"  Part="1" 
AR Path="/60B91B73/5FC4BD7A" Ref="F9"  Part="1" 
F 0 "F9" V 5925 2550 50  0000 C CNN
F 1 "Max 30mA" V 6016 2550 50  0000 C CNN
F 2 "Fuse:Fuse_0603_1608Metric" H 6200 2350 50  0001 L CNN
F 3 "530-0ZCM0001FF2G" H 6150 2550 50  0001 C CNN
F 4 "C426238" H 6150 2550 50  0001 C CNN "LCSC"
F 5 "Mouser" H 6150 2550 50  0001 C CNN "Comment"
	1    6150 2550
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 608DE1A8
P 6550 3000
AR Path="/5FAFE50B/608DE1A8" Ref="#PWR?"  Part="1" 
AR Path="/5FB05F69/608DE1A8" Ref="#PWR?"  Part="1" 
AR Path="/608DE1A8" Ref="#PWR?"  Part="1" 
AR Path="/5FC2CC0E/608DE1A8" Ref="#PWR066"  Part="1" 
AR Path="/60B91B73/608DE1A8" Ref="#PWR0128"  Part="1" 
F 0 "#PWR0128" H 6550 2750 50  0001 C CNN
F 1 "GND" H 6555 2827 50  0000 C CNN
F 2 "" H 6550 3000 50  0001 C CNN
F 3 "" H 6550 3000 50  0001 C CNN
	1    6550 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	6300 2550 6550 2550
Connection ~ 6550 2550
Wire Wire Line
	7000 2550 7700 2550
Text HLabel 6000 2550 0    50   Input ~ 0
DAI1P
$Comp
L Device:R R?
U 1 1 608DE1A9
P 2450 2350
AR Path="/5FAFE50B/608DE1A9" Ref="R?"  Part="1" 
AR Path="/5FB05F69/608DE1A9" Ref="R?"  Part="1" 
AR Path="/608DE1A9" Ref="R?"  Part="1" 
AR Path="/5FC2CC0E/608DE1A9" Ref="R19"  Part="1" 
AR Path="/60B91B73/608DE1A9" Ref="R14"  Part="1" 
F 0 "R14" H 2520 2396 50  0000 L CNN
F 1 "160" H 2520 2305 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2380 2350 50  0001 C CNN
F 3 "660-RK73B1JTTD161J" H 2450 2350 50  0001 C CNN
F 4 "C22814" H 2450 2350 50  0001 C CNN "LCSC"
F 5 "Mouser" H 2450 2350 50  0001 C CNN "Comment"
	1    2450 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	2450 2200 2450 2050
Wire Wire Line
	2450 2050 2600 2050
$Comp
L Device:Polyfuse F?
U 1 1 608DE1AA
P 2050 2050
AR Path="/5FAFE50B/608DE1AA" Ref="F?"  Part="1" 
AR Path="/5FB05F69/608DE1AA" Ref="F?"  Part="1" 
AR Path="/608DE1AA" Ref="F?"  Part="1" 
AR Path="/5FC2CC0E/608DE1AA" Ref="F7"  Part="1" 
AR Path="/60B91B73/608DE1AA" Ref="F5"  Part="1" 
F 0 "F5" V 1825 2050 50  0000 C CNN
F 1 "Max 30mA" V 1916 2050 50  0000 C CNN
F 2 "Fuse:Fuse_0603_1608Metric" H 2100 1850 50  0001 L CNN
F 3 "530-0ZCM0001FF2G" H 2050 2050 50  0001 C CNN
F 4 "C426238" H 2050 2050 50  0001 C CNN "LCSC"
F 5 "Mouser" H 2050 2050 50  0001 C CNN "Comment"
	1    2050 2050
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 608DE1AB
P 2450 2500
AR Path="/5FAFE50B/608DE1AB" Ref="#PWR?"  Part="1" 
AR Path="/5FB05F69/608DE1AB" Ref="#PWR?"  Part="1" 
AR Path="/608DE1AB" Ref="#PWR?"  Part="1" 
AR Path="/5FC2CC0E/608DE1AB" Ref="#PWR049"  Part="1" 
AR Path="/60B91B73/608DE1AB" Ref="#PWR0145"  Part="1" 
F 0 "#PWR0145" H 2450 2250 50  0001 C CNN
F 1 "GND" H 2455 2327 50  0000 C CNN
F 2 "" H 2450 2500 50  0001 C CNN
F 3 "" H 2450 2500 50  0001 C CNN
	1    2450 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 2050 2450 2050
Connection ~ 2450 2050
Wire Wire Line
	2900 2050 3600 2050
Text HLabel 1900 3000 0    50   Input ~ 0
DAI4P
Text HLabel 3600 3000 2    50   Input ~ 0
PD14
$Comp
L Device:R R?
U 1 1 608DE1AC
P 6550 3750
AR Path="/5FAFE50B/608DE1AC" Ref="R?"  Part="1" 
AR Path="/5FB05F69/608DE1AC" Ref="R?"  Part="1" 
AR Path="/608DE1AC" Ref="R?"  Part="1" 
AR Path="/5FC2CC0E/608DE1AC" Ref="R20"  Part="1" 
AR Path="/60B91B73/608DE1AC" Ref="R17"  Part="1" 
F 0 "R17" H 6620 3796 50  0000 L CNN
F 1 "160" H 6620 3705 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 6480 3750 50  0001 C CNN
F 3 "660-RK73B1JTTD161J" H 6550 3750 50  0001 C CNN
F 4 "C22814" H 6550 3750 50  0001 C CNN "LCSC"
F 5 "Mouser" H 6550 3750 50  0001 C CNN "Comment"
	1    6550 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	6550 3600 6550 3450
Wire Wire Line
	6550 3450 6700 3450
$Comp
L Device:Polyfuse F?
U 1 1 608DE1AD
P 6150 3450
AR Path="/5FAFE50B/608DE1AD" Ref="F?"  Part="1" 
AR Path="/5FB05F69/608DE1AD" Ref="F?"  Part="1" 
AR Path="/608DE1AD" Ref="F?"  Part="1" 
AR Path="/5FC2CC0E/608DE1AD" Ref="F8"  Part="1" 
AR Path="/60B91B73/608DE1AD" Ref="F6"  Part="1" 
F 0 "F6" V 5925 3450 50  0000 C CNN
F 1 "Max 30mA" V 6016 3450 50  0000 C CNN
F 2 "Fuse:Fuse_0603_1608Metric" H 6200 3250 50  0001 L CNN
F 3 "530-0ZCM0001FF2G" H 6150 3450 50  0001 C CNN
F 4 "C426238" H 6150 3450 50  0001 C CNN "LCSC"
F 5 "Mouser" H 6150 3450 50  0001 C CNN "Comment"
	1    6150 3450
	0    1    1    0   
$EndComp
Wire Wire Line
	6300 3450 6550 3450
Connection ~ 6550 3450
Wire Wire Line
	7000 3450 7700 3450
Text HLabel 6000 3450 0    50   Input ~ 0
DAI1M
$Comp
L power:GND #PWR?
U 1 1 5FAD7E64
P 4050 5400
AR Path="/5FAFDC1C/5FAD7E64" Ref="#PWR?"  Part="1" 
AR Path="/5FC2CC0E/5FAD7E64" Ref="#PWR040"  Part="1" 
AR Path="/60B91B73/5FAD7E64" Ref="#PWR0147"  Part="1" 
F 0 "#PWR0147" H 4050 5150 50  0001 C CNN
F 1 "GND" H 4055 5227 50  0000 C CNN
F 2 "" H 4050 5400 50  0001 C CNN
F 3 "" H 4050 5400 50  0001 C CNN
	1    4050 5400
	1    0    0    -1  
$EndComp
$Comp
L Diode:BZX84Cxx D?
U 1 1 608DE19C
P 3750 5400
AR Path="/5FAFDC1C/608DE19C" Ref="D?"  Part="1" 
AR Path="/5FC2CC0E/608DE19C" Ref="D24"  Part="1" 
AR Path="/60B91B73/608DE19C" Ref="D23"  Part="1" 
F 0 "D23" H 3750 5625 50  0000 C CNN
F 1 "BZX84C3V6LT1G" H 3750 5534 50  0000 C CNN
F 2 "Diode_SMD:D_SOT-23_ANK" H 3825 5525 50  0001 L CNN
F 3 "863-BZX84C3V6LT1G" H 3630 5400 50  0001 C CNN
F 4 "C118564" H 3750 5400 50  0001 C CNN "LCSC"
F 5 "Köp in lite" H 3750 5400 50  0001 C CNN "Comment"
	1    3750 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 5400 3900 5400
Wire Wire Line
	3600 5400 3600 5700
$Comp
L power:GND #PWR?
U 1 1 5FADC73D
P 8150 2250
AR Path="/5FAFDC1C/5FADC73D" Ref="#PWR?"  Part="1" 
AR Path="/5FC2CC0E/5FADC73D" Ref="#PWR041"  Part="1" 
AR Path="/60B91B73/5FADC73D" Ref="#PWR0148"  Part="1" 
F 0 "#PWR0148" H 8150 2000 50  0001 C CNN
F 1 "GND" H 8155 2077 50  0000 C CNN
F 2 "" H 8150 2250 50  0001 C CNN
F 3 "" H 8150 2250 50  0001 C CNN
	1    8150 2250
	1    0    0    -1  
$EndComp
$Comp
L Diode:BZX84Cxx D?
U 1 1 5FADC743
P 7850 2250
AR Path="/5FAFDC1C/5FADC743" Ref="D?"  Part="1" 
AR Path="/5FC2CC0E/5FADC743" Ref="D25"  Part="1" 
AR Path="/60B91B73/5FADC743" Ref="D22"  Part="1" 
F 0 "D22" H 7850 2475 50  0000 C CNN
F 1 "BZX84C3V6LT1G" H 7850 2384 50  0000 C CNN
F 2 "Diode_SMD:D_SOT-23_ANK" H 7925 2375 50  0001 L CNN
F 3 "863-BZX84C3V6LT1G" H 7730 2250 50  0001 C CNN
F 4 "C118564" H 7850 2250 50  0001 C CNN "LCSC"
F 5 "Köp in lite" H 7850 2250 50  0001 C CNN "Comment"
	1    7850 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	8150 2250 8000 2250
$Comp
L power:GND #PWR?
U 1 1 5FAE8C31
P 4050 1750
AR Path="/5FAFDC1C/5FAE8C31" Ref="#PWR?"  Part="1" 
AR Path="/5FC2CC0E/5FAE8C31" Ref="#PWR036"  Part="1" 
AR Path="/60B91B73/5FAE8C31" Ref="#PWR0149"  Part="1" 
F 0 "#PWR0149" H 4050 1500 50  0001 C CNN
F 1 "GND" H 4055 1577 50  0000 C CNN
F 2 "" H 4050 1750 50  0001 C CNN
F 3 "" H 4050 1750 50  0001 C CNN
	1    4050 1750
	1    0    0    -1  
$EndComp
$Comp
L Diode:BZX84Cxx D?
U 1 1 5FAE8C37
P 3750 1750
AR Path="/5FAFDC1C/5FAE8C37" Ref="D?"  Part="1" 
AR Path="/5FC2CC0E/5FAE8C37" Ref="D20"  Part="1" 
AR Path="/60B91B73/5FAE8C37" Ref="D18"  Part="1" 
F 0 "D18" H 3750 1975 50  0000 C CNN
F 1 "BZX84C3V6LT1G" H 3750 1884 50  0000 C CNN
F 2 "Diode_SMD:D_SOT-23_ANK" H 3825 1875 50  0001 L CNN
F 3 "863-BZX84C3V6LT1G" H 3630 1750 50  0001 C CNN
F 4 "C118564" H 3750 1750 50  0001 C CNN "LCSC"
F 5 "Köp in lite" H 3750 1750 50  0001 C CNN "Comment"
	1    3750 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 1750 3900 1750
Wire Wire Line
	3600 1750 3600 2050
$Comp
L power:GND #PWR?
U 1 1 5FAEC28A
P 8150 3150
AR Path="/5FAFDC1C/5FAEC28A" Ref="#PWR?"  Part="1" 
AR Path="/5FC2CC0E/5FAEC28A" Ref="#PWR037"  Part="1" 
AR Path="/60B91B73/5FAEC28A" Ref="#PWR0150"  Part="1" 
F 0 "#PWR0150" H 8150 2900 50  0001 C CNN
F 1 "GND" H 8155 2977 50  0000 C CNN
F 2 "" H 8150 3150 50  0001 C CNN
F 3 "" H 8150 3150 50  0001 C CNN
	1    8150 3150
	1    0    0    -1  
$EndComp
$Comp
L Diode:BZX84Cxx D?
U 1 1 5FAEC290
P 7850 3150
AR Path="/5FAFDC1C/5FAEC290" Ref="D?"  Part="1" 
AR Path="/5FC2CC0E/5FAEC290" Ref="D21"  Part="1" 
AR Path="/60B91B73/5FAEC290" Ref="D19"  Part="1" 
F 0 "D19" H 7850 3375 50  0000 C CNN
F 1 "BZX84C3V6LT1G" H 7850 3284 50  0000 C CNN
F 2 "Diode_SMD:D_SOT-23_ANK" H 7925 3275 50  0001 L CNN
F 3 "863-BZX84C3V6LT1G" H 7730 3150 50  0001 C CNN
F 4 "C118564" H 7850 3150 50  0001 C CNN "LCSC"
F 5 "Köp in lite" H 7850 3150 50  0001 C CNN "Comment"
	1    7850 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	8150 3150 8000 3150
Wire Wire Line
	7700 3150 7700 3450
$Comp
L Device:R R?
U 1 1 607285A5
P 2750 2050
AR Path="/607285A5" Ref="R?"  Part="1" 
AR Path="/5FB17A23/607285A5" Ref="R?"  Part="1" 
AR Path="/5FC2CC0E/607285A5" Ref="R23"  Part="1" 
AR Path="/60B91B73/607285A5" Ref="R22"  Part="1" 
F 0 "R22" H 2820 2096 50  0000 L CNN
F 1 "160" H 2820 2005 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2680 2050 50  0001 C CNN
F 3 "660-RK73B1JTTD161J" H 2750 2050 50  0001 C CNN
F 4 "C25804" H 2750 2050 50  0001 C CNN "LCSC"
F 5 "Mouser" H 2750 2050 50  0001 C CNN "Comment"
	1    2750 2050
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 608DE1B0
P 6850 3450
AR Path="/608DE1B0" Ref="R?"  Part="1" 
AR Path="/5FB17A23/608DE1B0" Ref="R?"  Part="1" 
AR Path="/5FC2CC0E/608DE1B0" Ref="R24"  Part="1" 
AR Path="/60B91B73/608DE1B0" Ref="R25"  Part="1" 
F 0 "R25" H 6920 3496 50  0000 L CNN
F 1 "160" H 6920 3405 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 6780 3450 50  0001 C CNN
F 3 "660-RK73B1JTTD161J" H 6850 3450 50  0001 C CNN
F 4 "" H 6850 3450 50  0001 C CNN "LCSC"
F 5 "Mouser" H 6850 3450 50  0001 C CNN "Comment"
	1    6850 3450
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 60731C3D
P 2750 5700
AR Path="/60731C3D" Ref="R?"  Part="1" 
AR Path="/5FB17A23/60731C3D" Ref="R?"  Part="1" 
AR Path="/5FC2CC0E/60731C3D" Ref="R31"  Part="1" 
AR Path="/60B91B73/60731C3D" Ref="R27"  Part="1" 
F 0 "R27" H 2820 5746 50  0000 L CNN
F 1 "160" H 2820 5655 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2680 5700 50  0001 C CNN
F 3 "660-RK73B1JTTD161J" H 2750 5700 50  0001 C CNN
F 4 "" H 2750 5700 50  0001 C CNN "LCSC"
F 5 "Mouser" H 2750 5700 50  0001 C CNN "Comment"
	1    2750 5700
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 60732B47
P 6850 2550
AR Path="/60732B47" Ref="R?"  Part="1" 
AR Path="/5FB17A23/60732B47" Ref="R?"  Part="1" 
AR Path="/5FC2CC0E/60732B47" Ref="R32"  Part="1" 
AR Path="/60B91B73/60732B47" Ref="R26"  Part="1" 
F 0 "R26" H 6920 2596 50  0000 L CNN
F 1 "160" H 6920 2505 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 6780 2550 50  0001 C CNN
F 3 "660-RK73B1JTTD161J" H 6850 2550 50  0001 C CNN
F 4 "" H 6850 2550 50  0001 C CNN "LCSC"
F 5 "Mouser" H 6850 2550 50  0001 C CNN "Comment"
	1    6850 2550
	0    -1   -1   0   
$EndComp
Text HLabel 7700 2550 2    50   Input ~ 0
PD8
Text HLabel 3600 5700 2    50   Input ~ 0
PD10
$Comp
L Device:R R?
U 1 1 60C35CFC
P 6550 5500
AR Path="/5FAFE50B/60C35CFC" Ref="R?"  Part="1" 
AR Path="/5FB05F69/60C35CFC" Ref="R?"  Part="1" 
AR Path="/60C35CFC" Ref="R?"  Part="1" 
AR Path="/5FC2CC0E/60C35CFC" Ref="R?"  Part="1" 
AR Path="/60B91B73/60C35CFC" Ref="R61"  Part="1" 
F 0 "R61" H 6620 5546 50  0000 L CNN
F 1 "160" H 6620 5455 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 6480 5500 50  0001 C CNN
F 3 "660-RK73B1JTTD161J" H 6550 5500 50  0001 C CNN
F 4 "C22814" H 6550 5500 50  0001 C CNN "LCSC"
F 5 "Mouser" H 6550 5500 50  0001 C CNN "Comment"
	1    6550 5500
	1    0    0    -1  
$EndComp
Wire Wire Line
	6550 5350 6550 5200
Wire Wire Line
	6550 5200 6700 5200
$Comp
L Device:Polyfuse F?
U 1 1 60C35D04
P 6150 5200
AR Path="/5FAFE50B/60C35D04" Ref="F?"  Part="1" 
AR Path="/5FB05F69/60C35D04" Ref="F?"  Part="1" 
AR Path="/60C35D04" Ref="F?"  Part="1" 
AR Path="/5FC2CC0E/60C35D04" Ref="F?"  Part="1" 
AR Path="/60B91B73/60C35D04" Ref="F28"  Part="1" 
F 0 "F28" V 5925 5200 50  0000 C CNN
F 1 "Max 30mA" V 6016 5200 50  0000 C CNN
F 2 "Fuse:Fuse_0603_1608Metric" H 6200 5000 50  0001 L CNN
F 3 "530-0ZCM0001FF2G" H 6150 5200 50  0001 C CNN
F 4 "C426238" H 6150 5200 50  0001 C CNN "LCSC"
F 5 "Mouser" H 6150 5200 50  0001 C CNN "Comment"
	1    6150 5200
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60C35D0A
P 6550 5650
AR Path="/5FAFE50B/60C35D0A" Ref="#PWR?"  Part="1" 
AR Path="/5FB05F69/60C35D0A" Ref="#PWR?"  Part="1" 
AR Path="/60C35D0A" Ref="#PWR?"  Part="1" 
AR Path="/5FC2CC0E/60C35D0A" Ref="#PWR?"  Part="1" 
AR Path="/60B91B73/60C35D0A" Ref="#PWR0151"  Part="1" 
F 0 "#PWR0151" H 6550 5400 50  0001 C CNN
F 1 "GND" H 6555 5477 50  0000 C CNN
F 2 "" H 6550 5650 50  0001 C CNN
F 3 "" H 6550 5650 50  0001 C CNN
	1    6550 5650
	1    0    0    -1  
$EndComp
Wire Wire Line
	6300 5200 6550 5200
Connection ~ 6550 5200
Wire Wire Line
	7000 5200 7700 5200
Text HLabel 6000 5200 0    50   Input ~ 0
DAI0M
$Comp
L Device:R R?
U 1 1 60C35D15
P 2450 3300
AR Path="/5FAFE50B/60C35D15" Ref="R?"  Part="1" 
AR Path="/5FB05F69/60C35D15" Ref="R?"  Part="1" 
AR Path="/60C35D15" Ref="R?"  Part="1" 
AR Path="/5FC2CC0E/60C35D15" Ref="R?"  Part="1" 
AR Path="/60B91B73/60C35D15" Ref="R60"  Part="1" 
F 0 "R60" H 2520 3346 50  0000 L CNN
F 1 "160" H 2520 3255 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2380 3300 50  0001 C CNN
F 3 "660-RK73B1JTTD161J" H 2450 3300 50  0001 C CNN
F 4 "C22814" H 2450 3300 50  0001 C CNN "LCSC"
F 5 "Mouser" H 2450 3300 50  0001 C CNN "Comment"
	1    2450 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	2450 3150 2450 3000
Wire Wire Line
	2450 3000 2600 3000
$Comp
L Device:Polyfuse F?
U 1 1 60C35D1D
P 2050 3000
AR Path="/5FAFE50B/60C35D1D" Ref="F?"  Part="1" 
AR Path="/5FB05F69/60C35D1D" Ref="F?"  Part="1" 
AR Path="/60C35D1D" Ref="F?"  Part="1" 
AR Path="/5FC2CC0E/60C35D1D" Ref="F?"  Part="1" 
AR Path="/60B91B73/60C35D1D" Ref="F27"  Part="1" 
F 0 "F27" V 1825 3000 50  0000 C CNN
F 1 "Max 30mA" V 1916 3000 50  0000 C CNN
F 2 "Fuse:Fuse_0603_1608Metric" H 2100 2800 50  0001 L CNN
F 3 "530-0ZCM0001FF2G" H 2050 3000 50  0001 C CNN
F 4 "C426238" H 2050 3000 50  0001 C CNN "LCSC"
F 5 "Mouser" H 2050 3000 50  0001 C CNN "Comment"
	1    2050 3000
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60C35D23
P 2450 3450
AR Path="/5FAFE50B/60C35D23" Ref="#PWR?"  Part="1" 
AR Path="/5FB05F69/60C35D23" Ref="#PWR?"  Part="1" 
AR Path="/60C35D23" Ref="#PWR?"  Part="1" 
AR Path="/5FC2CC0E/60C35D23" Ref="#PWR?"  Part="1" 
AR Path="/60B91B73/60C35D23" Ref="#PWR0152"  Part="1" 
F 0 "#PWR0152" H 2450 3200 50  0001 C CNN
F 1 "GND" H 2455 3277 50  0000 C CNN
F 2 "" H 2450 3450 50  0001 C CNN
F 3 "" H 2450 3450 50  0001 C CNN
	1    2450 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 3000 2450 3000
Connection ~ 2450 3000
Wire Wire Line
	2900 3000 3600 3000
$Comp
L Device:R R?
U 1 1 60C35D2D
P 2450 4200
AR Path="/5FAFE50B/60C35D2D" Ref="R?"  Part="1" 
AR Path="/5FB05F69/60C35D2D" Ref="R?"  Part="1" 
AR Path="/60C35D2D" Ref="R?"  Part="1" 
AR Path="/5FC2CC0E/60C35D2D" Ref="R?"  Part="1" 
AR Path="/60B91B73/60C35D2D" Ref="R28"  Part="1" 
F 0 "R28" H 2520 4246 50  0000 L CNN
F 1 "160" H 2520 4155 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2380 4200 50  0001 C CNN
F 3 "660-RK73B1JTTD161J" H 2450 4200 50  0001 C CNN
F 4 "C22814" H 2450 4200 50  0001 C CNN "LCSC"
F 5 "Mouser" H 2450 4200 50  0001 C CNN "Comment"
	1    2450 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	2450 4050 2450 3900
Wire Wire Line
	2450 3900 2600 3900
$Comp
L Device:Polyfuse F?
U 1 1 60C35D35
P 2050 3900
AR Path="/5FAFE50B/60C35D35" Ref="F?"  Part="1" 
AR Path="/5FB05F69/60C35D35" Ref="F?"  Part="1" 
AR Path="/60C35D35" Ref="F?"  Part="1" 
AR Path="/5FC2CC0E/60C35D35" Ref="F?"  Part="1" 
AR Path="/60B91B73/60C35D35" Ref="F21"  Part="1" 
F 0 "F21" V 1825 3900 50  0000 C CNN
F 1 "Max 30mA" V 1916 3900 50  0000 C CNN
F 2 "Fuse:Fuse_0603_1608Metric" H 2100 3700 50  0001 L CNN
F 3 "530-0ZCM0001FF2G" H 2050 3900 50  0001 C CNN
F 4 "C426238" H 2050 3900 50  0001 C CNN "LCSC"
F 5 "Mouser" H 2050 3900 50  0001 C CNN "Comment"
	1    2050 3900
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60C35D3B
P 2450 4350
AR Path="/5FAFE50B/60C35D3B" Ref="#PWR?"  Part="1" 
AR Path="/5FB05F69/60C35D3B" Ref="#PWR?"  Part="1" 
AR Path="/60C35D3B" Ref="#PWR?"  Part="1" 
AR Path="/5FC2CC0E/60C35D3B" Ref="#PWR?"  Part="1" 
AR Path="/60B91B73/60C35D3B" Ref="#PWR0153"  Part="1" 
F 0 "#PWR0153" H 2450 4100 50  0001 C CNN
F 1 "GND" H 2455 4177 50  0000 C CNN
F 2 "" H 2450 4350 50  0001 C CNN
F 3 "" H 2450 4350 50  0001 C CNN
	1    2450 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 3900 2450 3900
Connection ~ 2450 3900
Wire Wire Line
	2900 3900 3600 3900
Text HLabel 1900 3900 0    50   Input ~ 0
DAI3P
Text HLabel 3600 3900 2    50   Input ~ 0
PD12
$Comp
L power:GND #PWR?
U 1 1 60C35D5E
P 8150 4900
AR Path="/5FAFDC1C/60C35D5E" Ref="#PWR?"  Part="1" 
AR Path="/5FC2CC0E/60C35D5E" Ref="#PWR?"  Part="1" 
AR Path="/60B91B73/60C35D5E" Ref="#PWR0155"  Part="1" 
F 0 "#PWR0155" H 8150 4650 50  0001 C CNN
F 1 "GND" H 8155 4727 50  0000 C CNN
F 2 "" H 8150 4900 50  0001 C CNN
F 3 "" H 8150 4900 50  0001 C CNN
	1    8150 4900
	1    0    0    -1  
$EndComp
$Comp
L Diode:BZX84Cxx D?
U 1 1 60C35D64
P 7850 4900
AR Path="/5FAFDC1C/60C35D64" Ref="D?"  Part="1" 
AR Path="/5FC2CC0E/60C35D64" Ref="D?"  Part="1" 
AR Path="/60B91B73/60C35D64" Ref="D37"  Part="1" 
F 0 "D37" H 7850 5125 50  0000 C CNN
F 1 "BZX84C3V6LT1G" H 7850 5034 50  0000 C CNN
F 2 "Diode_SMD:D_SOT-23_ANK" H 7925 5025 50  0001 L CNN
F 3 "863-BZX84C3V6LT1G" H 7730 4900 50  0001 C CNN
F 4 "C118564" H 7850 4900 50  0001 C CNN "LCSC"
F 5 "Köp in lite" H 7850 4900 50  0001 C CNN "Comment"
	1    7850 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	8150 4900 8000 4900
Wire Wire Line
	7700 4900 7700 5200
$Comp
L power:GND #PWR?
U 1 1 60C35D6C
P 4050 2700
AR Path="/5FAFDC1C/60C35D6C" Ref="#PWR?"  Part="1" 
AR Path="/5FC2CC0E/60C35D6C" Ref="#PWR?"  Part="1" 
AR Path="/60B91B73/60C35D6C" Ref="#PWR0156"  Part="1" 
F 0 "#PWR0156" H 4050 2450 50  0001 C CNN
F 1 "GND" H 4055 2527 50  0000 C CNN
F 2 "" H 4050 2700 50  0001 C CNN
F 3 "" H 4050 2700 50  0001 C CNN
	1    4050 2700
	1    0    0    -1  
$EndComp
$Comp
L Diode:BZX84Cxx D?
U 1 1 60C35D72
P 3750 2700
AR Path="/5FAFDC1C/60C35D72" Ref="D?"  Part="1" 
AR Path="/5FC2CC0E/60C35D72" Ref="D?"  Part="1" 
AR Path="/60B91B73/60C35D72" Ref="D36"  Part="1" 
F 0 "D36" H 3750 2925 50  0000 C CNN
F 1 "BZX84C3V6LT1G" H 3750 2834 50  0000 C CNN
F 2 "Diode_SMD:D_SOT-23_ANK" H 3825 2825 50  0001 L CNN
F 3 "863-BZX84C3V6LT1G" H 3630 2700 50  0001 C CNN
F 4 "C118564" H 3750 2700 50  0001 C CNN "LCSC"
F 5 "Köp in lite" H 3750 2700 50  0001 C CNN "Comment"
	1    3750 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 2700 3900 2700
Wire Wire Line
	3600 2700 3600 3000
$Comp
L power:GND #PWR?
U 1 1 60C35D7A
P 4050 3600
AR Path="/5FAFDC1C/60C35D7A" Ref="#PWR?"  Part="1" 
AR Path="/5FC2CC0E/60C35D7A" Ref="#PWR?"  Part="1" 
AR Path="/60B91B73/60C35D7A" Ref="#PWR0157"  Part="1" 
F 0 "#PWR0157" H 4050 3350 50  0001 C CNN
F 1 "GND" H 4055 3427 50  0000 C CNN
F 2 "" H 4050 3600 50  0001 C CNN
F 3 "" H 4050 3600 50  0001 C CNN
	1    4050 3600
	1    0    0    -1  
$EndComp
$Comp
L Diode:BZX84Cxx D?
U 1 1 60C35D80
P 3750 3600
AR Path="/5FAFDC1C/60C35D80" Ref="D?"  Part="1" 
AR Path="/5FC2CC0E/60C35D80" Ref="D?"  Part="1" 
AR Path="/60B91B73/60C35D80" Ref="D29"  Part="1" 
F 0 "D29" H 3750 3825 50  0000 C CNN
F 1 "BZX84C3V6LT1G" H 3750 3734 50  0000 C CNN
F 2 "Diode_SMD:D_SOT-23_ANK" H 3825 3725 50  0001 L CNN
F 3 "863-BZX84C3V6LT1G" H 3630 3600 50  0001 C CNN
F 4 "C118564" H 3750 3600 50  0001 C CNN "LCSC"
F 5 "Köp in lite" H 3750 3600 50  0001 C CNN "Comment"
	1    3750 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 3600 3900 3600
Wire Wire Line
	3600 3600 3600 3900
$Comp
L Device:R R?
U 1 1 60C35D96
P 2750 3900
AR Path="/60C35D96" Ref="R?"  Part="1" 
AR Path="/5FB17A23/60C35D96" Ref="R?"  Part="1" 
AR Path="/5FC2CC0E/60C35D96" Ref="R?"  Part="1" 
AR Path="/60B91B73/60C35D96" Ref="R62"  Part="1" 
F 0 "R62" H 2820 3946 50  0000 L CNN
F 1 "10k" H 2820 3855 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2680 3900 50  0001 C CNN
F 3 "660-RK73B1JTTD161J" H 2750 3900 50  0001 C CNN
F 4 "" H 2750 3900 50  0001 C CNN "LCSC"
F 5 "Mouser" H 2750 3900 50  0001 C CNN "Comment"
	1    2750 3900
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 60C35DA2
P 6850 5200
AR Path="/60C35DA2" Ref="R?"  Part="1" 
AR Path="/5FB17A23/60C35DA2" Ref="R?"  Part="1" 
AR Path="/5FC2CC0E/60C35DA2" Ref="R?"  Part="1" 
AR Path="/60B91B73/60C35DA2" Ref="R65"  Part="1" 
F 0 "R65" H 6920 5246 50  0000 L CNN
F 1 "160" H 6920 5155 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 6780 5200 50  0001 C CNN
F 3 "660-RK73B1JTTD161J" H 6850 5200 50  0001 C CNN
F 4 "" H 6850 5200 50  0001 C CNN "LCSC"
F 5 "Mouser" H 6850 5200 50  0001 C CNN "Comment"
	1    6850 5200
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 60C35DA8
P 2750 3000
AR Path="/60C35DA8" Ref="R?"  Part="1" 
AR Path="/5FB17A23/60C35DA8" Ref="R?"  Part="1" 
AR Path="/5FC2CC0E/60C35DA8" Ref="R?"  Part="1" 
AR Path="/60B91B73/60C35DA8" Ref="R64"  Part="1" 
F 0 "R64" H 2820 3046 50  0000 L CNN
F 1 "160" H 2820 2955 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2680 3000 50  0001 C CNN
F 3 "660-RK73B1JTTD161J" H 2750 3000 50  0001 C CNN
F 4 "" H 2750 3000 50  0001 C CNN "LCSC"
F 5 "Mouser" H 2750 3000 50  0001 C CNN "Comment"
	1    2750 3000
	0    -1   -1   0   
$EndComp
Text HLabel 3600 2050 2    50   Input ~ 0
PD15
Text HLabel 7700 5200 2    50   Input ~ 0
PB15
Text HLabel 3600 6600 2    50   Input ~ 0
PD11
$Comp
L Device:R R?
U 1 1 60C397A8
P 2450 5050
AR Path="/5FAFE50B/60C397A8" Ref="R?"  Part="1" 
AR Path="/5FB05F69/60C397A8" Ref="R?"  Part="1" 
AR Path="/60C397A8" Ref="R?"  Part="1" 
AR Path="/5FC2CC0E/60C397A8" Ref="R?"  Part="1" 
AR Path="/60B91B73/60C397A8" Ref="R66"  Part="1" 
F 0 "R66" H 2520 5096 50  0000 L CNN
F 1 "160" H 2520 5005 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2380 5050 50  0001 C CNN
F 3 "660-RK73B1JTTD161J" H 2450 5050 50  0001 C CNN
F 4 "C22814" H 2450 5050 50  0001 C CNN "LCSC"
F 5 "Mouser" H 2450 5050 50  0001 C CNN "Comment"
	1    2450 5050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2450 4900 2450 4750
Wire Wire Line
	2450 4750 2600 4750
$Comp
L Device:Polyfuse F?
U 1 1 60C397B0
P 2050 4750
AR Path="/5FAFE50B/60C397B0" Ref="F?"  Part="1" 
AR Path="/5FB05F69/60C397B0" Ref="F?"  Part="1" 
AR Path="/60C397B0" Ref="F?"  Part="1" 
AR Path="/5FC2CC0E/60C397B0" Ref="F?"  Part="1" 
AR Path="/60B91B73/60C397B0" Ref="F29"  Part="1" 
F 0 "F29" V 1825 4750 50  0000 C CNN
F 1 "Max 30mA" V 1916 4750 50  0000 C CNN
F 2 "Fuse:Fuse_0603_1608Metric" H 2100 4550 50  0001 L CNN
F 3 "530-0ZCM0001FF2G" H 2050 4750 50  0001 C CNN
F 4 "C426238" H 2050 4750 50  0001 C CNN "LCSC"
F 5 "Mouser" H 2050 4750 50  0001 C CNN "Comment"
	1    2050 4750
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60C397B6
P 2450 5200
AR Path="/5FAFE50B/60C397B6" Ref="#PWR?"  Part="1" 
AR Path="/5FB05F69/60C397B6" Ref="#PWR?"  Part="1" 
AR Path="/60C397B6" Ref="#PWR?"  Part="1" 
AR Path="/5FC2CC0E/60C397B6" Ref="#PWR?"  Part="1" 
AR Path="/60B91B73/60C397B6" Ref="#PWR0159"  Part="1" 
F 0 "#PWR0159" H 2450 4950 50  0001 C CNN
F 1 "GND" H 2455 5027 50  0000 C CNN
F 2 "" H 2450 5200 50  0001 C CNN
F 3 "" H 2450 5200 50  0001 C CNN
	1    2450 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 4750 2450 4750
Connection ~ 2450 4750
Wire Wire Line
	2900 4750 3600 4750
Text HLabel 1900 4750 0    50   Input ~ 0
DAI3M
Text HLabel 3600 4750 2    50   Input ~ 0
PD13
$Comp
L Device:R R?
U 1 1 60C397C1
P 2450 6900
AR Path="/5FAFE50B/60C397C1" Ref="R?"  Part="1" 
AR Path="/5FB05F69/60C397C1" Ref="R?"  Part="1" 
AR Path="/60C397C1" Ref="R?"  Part="1" 
AR Path="/5FC2CC0E/60C397C1" Ref="R?"  Part="1" 
AR Path="/60B91B73/60C397C1" Ref="R67"  Part="1" 
F 0 "R67" H 2520 6946 50  0000 L CNN
F 1 "160" H 2520 6855 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2380 6900 50  0001 C CNN
F 3 "660-RK73B1JTTD161J" H 2450 6900 50  0001 C CNN
F 4 "C22814" H 2450 6900 50  0001 C CNN "LCSC"
F 5 "Mouser" H 2450 6900 50  0001 C CNN "Comment"
	1    2450 6900
	1    0    0    -1  
$EndComp
Wire Wire Line
	2450 6750 2450 6600
Wire Wire Line
	2450 6600 2600 6600
$Comp
L Device:Polyfuse F?
U 1 1 60C397C9
P 2050 6600
AR Path="/5FAFE50B/60C397C9" Ref="F?"  Part="1" 
AR Path="/5FB05F69/60C397C9" Ref="F?"  Part="1" 
AR Path="/60C397C9" Ref="F?"  Part="1" 
AR Path="/5FC2CC0E/60C397C9" Ref="F?"  Part="1" 
AR Path="/60B91B73/60C397C9" Ref="F30"  Part="1" 
F 0 "F30" V 1825 6600 50  0000 C CNN
F 1 "Max 30mA" V 1916 6600 50  0000 C CNN
F 2 "Fuse:Fuse_0603_1608Metric" H 2100 6400 50  0001 L CNN
F 3 "530-0ZCM0001FF2G" H 2050 6600 50  0001 C CNN
F 4 "C426238" H 2050 6600 50  0001 C CNN "LCSC"
F 5 "Mouser" H 2050 6600 50  0001 C CNN "Comment"
	1    2050 6600
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60C397CF
P 2450 7050
AR Path="/5FAFE50B/60C397CF" Ref="#PWR?"  Part="1" 
AR Path="/5FB05F69/60C397CF" Ref="#PWR?"  Part="1" 
AR Path="/60C397CF" Ref="#PWR?"  Part="1" 
AR Path="/5FC2CC0E/60C397CF" Ref="#PWR?"  Part="1" 
AR Path="/60B91B73/60C397CF" Ref="#PWR0160"  Part="1" 
F 0 "#PWR0160" H 2450 6800 50  0001 C CNN
F 1 "GND" H 2455 6877 50  0000 C CNN
F 2 "" H 2450 7050 50  0001 C CNN
F 3 "" H 2450 7050 50  0001 C CNN
	1    2450 7050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 6600 2450 6600
Connection ~ 2450 6600
Wire Wire Line
	2900 6600 3600 6600
Text HLabel 1900 6600 0    50   Input ~ 0
DAI2M
$Comp
L power:GND #PWR?
U 1 1 60C397F5
P 4050 4450
AR Path="/5FAFDC1C/60C397F5" Ref="#PWR?"  Part="1" 
AR Path="/5FC2CC0E/60C397F5" Ref="#PWR?"  Part="1" 
AR Path="/60B91B73/60C397F5" Ref="#PWR0161"  Part="1" 
F 0 "#PWR0161" H 4050 4200 50  0001 C CNN
F 1 "GND" H 4055 4277 50  0000 C CNN
F 2 "" H 4050 4450 50  0001 C CNN
F 3 "" H 4050 4450 50  0001 C CNN
	1    4050 4450
	1    0    0    -1  
$EndComp
$Comp
L Diode:BZX84Cxx D?
U 1 1 60C397FB
P 3750 4450
AR Path="/5FAFDC1C/60C397FB" Ref="D?"  Part="1" 
AR Path="/5FC2CC0E/60C397FB" Ref="D?"  Part="1" 
AR Path="/60B91B73/60C397FB" Ref="D38"  Part="1" 
F 0 "D38" H 3750 4675 50  0000 C CNN
F 1 "BZX84C3V6LT1G" H 3750 4584 50  0000 C CNN
F 2 "Diode_SMD:D_SOT-23_ANK" H 3825 4575 50  0001 L CNN
F 3 "863-BZX84C3V6LT1G" H 3630 4450 50  0001 C CNN
F 4 "C118564" H 3750 4450 50  0001 C CNN "LCSC"
F 5 "Köp in lite" H 3750 4450 50  0001 C CNN "Comment"
	1    3750 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 4450 3900 4450
Wire Wire Line
	3600 4450 3600 4750
$Comp
L power:GND #PWR?
U 1 1 60C39803
P 4050 6300
AR Path="/5FAFDC1C/60C39803" Ref="#PWR?"  Part="1" 
AR Path="/5FC2CC0E/60C39803" Ref="#PWR?"  Part="1" 
AR Path="/60B91B73/60C39803" Ref="#PWR0162"  Part="1" 
F 0 "#PWR0162" H 4050 6050 50  0001 C CNN
F 1 "GND" H 4055 6127 50  0000 C CNN
F 2 "" H 4050 6300 50  0001 C CNN
F 3 "" H 4050 6300 50  0001 C CNN
	1    4050 6300
	1    0    0    -1  
$EndComp
$Comp
L Diode:BZX84Cxx D?
U 1 1 60C39809
P 3750 6300
AR Path="/5FAFDC1C/60C39809" Ref="D?"  Part="1" 
AR Path="/5FC2CC0E/60C39809" Ref="D?"  Part="1" 
AR Path="/60B91B73/60C39809" Ref="D39"  Part="1" 
F 0 "D39" H 3750 6525 50  0000 C CNN
F 1 "BZX84C3V6LT1G" H 3750 6434 50  0000 C CNN
F 2 "Diode_SMD:D_SOT-23_ANK" H 3825 6425 50  0001 L CNN
F 3 "863-BZX84C3V6LT1G" H 3630 6300 50  0001 C CNN
F 4 "C118564" H 3750 6300 50  0001 C CNN "LCSC"
F 5 "Köp in lite" H 3750 6300 50  0001 C CNN "Comment"
	1    3750 6300
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 6300 3900 6300
Wire Wire Line
	3600 6300 3600 6600
$Comp
L Device:R R?
U 1 1 60C39811
P 2750 4750
AR Path="/60C39811" Ref="R?"  Part="1" 
AR Path="/5FB17A23/60C39811" Ref="R?"  Part="1" 
AR Path="/5FC2CC0E/60C39811" Ref="R?"  Part="1" 
AR Path="/60B91B73/60C39811" Ref="R68"  Part="1" 
F 0 "R68" H 2820 4796 50  0000 L CNN
F 1 "160" H 2820 4705 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2680 4750 50  0001 C CNN
F 3 "660-RK73B1JTTD161J" H 2750 4750 50  0001 C CNN
F 4 "" H 2750 4750 50  0001 C CNN "LCSC"
F 5 "Mouser" H 2750 4750 50  0001 C CNN "Comment"
	1    2750 4750
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 60C39817
P 2750 6600
AR Path="/60C39817" Ref="R?"  Part="1" 
AR Path="/5FB17A23/60C39817" Ref="R?"  Part="1" 
AR Path="/5FC2CC0E/60C39817" Ref="R?"  Part="1" 
AR Path="/60B91B73/60C39817" Ref="R69"  Part="1" 
F 0 "R69" H 2820 6646 50  0000 L CNN
F 1 "160" H 2820 6555 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 2680 6600 50  0001 C CNN
F 3 "660-RK73B1JTTD161J" H 2750 6600 50  0001 C CNN
F 4 "" H 2750 6600 50  0001 C CNN "LCSC"
F 5 "Mouser" H 2750 6600 50  0001 C CNN "Comment"
	1    2750 6600
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7700 2250 7700 2550
$Comp
L Device:R R?
U 1 1 60C35D9C
P 6850 4300
AR Path="/60C35D9C" Ref="R?"  Part="1" 
AR Path="/5FB17A23/60C35D9C" Ref="R?"  Part="1" 
AR Path="/5FC2CC0E/60C35D9C" Ref="R?"  Part="1" 
AR Path="/60B91B73/60C35D9C" Ref="R63"  Part="1" 
F 0 "R63" H 6920 4346 50  0000 L CNN
F 1 "160" H 6920 4255 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 6780 4300 50  0001 C CNN
F 3 "660-RK73B1JTTD161J" H 6850 4300 50  0001 C CNN
F 4 "" H 6850 4300 50  0001 C CNN "LCSC"
F 5 "Mouser" H 6850 4300 50  0001 C CNN "Comment"
	1    6850 4300
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7700 4000 7700 4300
Wire Wire Line
	8150 4000 8000 4000
$Comp
L Diode:BZX84Cxx D?
U 1 1 60C35D8E
P 7850 4000
AR Path="/5FAFDC1C/60C35D8E" Ref="D?"  Part="1" 
AR Path="/5FC2CC0E/60C35D8E" Ref="D?"  Part="1" 
AR Path="/60B91B73/60C35D8E" Ref="D35"  Part="1" 
F 0 "D35" H 7850 4225 50  0000 C CNN
F 1 "BZX84C3V6LT1G" H 7850 4134 50  0000 C CNN
F 2 "Diode_SMD:D_SOT-23_ANK" H 7925 4125 50  0001 L CNN
F 3 "863-BZX84C3V6LT1G" H 7730 4000 50  0001 C CNN
F 4 "C118564" H 7850 4000 50  0001 C CNN "LCSC"
F 5 "Köp in lite" H 7850 4000 50  0001 C CNN "Comment"
	1    7850 4000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60C35D88
P 8150 4000
AR Path="/5FAFDC1C/60C35D88" Ref="#PWR?"  Part="1" 
AR Path="/5FC2CC0E/60C35D88" Ref="#PWR?"  Part="1" 
AR Path="/60B91B73/60C35D88" Ref="#PWR0158"  Part="1" 
F 0 "#PWR0158" H 8150 3750 50  0001 C CNN
F 1 "GND" H 8155 3827 50  0000 C CNN
F 2 "" H 8150 4000 50  0001 C CNN
F 3 "" H 8150 4000 50  0001 C CNN
	1    8150 4000
	1    0    0    -1  
$EndComp
Text HLabel 6000 4300 0    50   Input ~ 0
DAI0P
Wire Wire Line
	7000 4300 7700 4300
Connection ~ 6550 4300
Wire Wire Line
	6300 4300 6550 4300
$Comp
L power:GND #PWR?
U 1 1 60C35D54
P 6550 4750
AR Path="/5FAFE50B/60C35D54" Ref="#PWR?"  Part="1" 
AR Path="/5FB05F69/60C35D54" Ref="#PWR?"  Part="1" 
AR Path="/60C35D54" Ref="#PWR?"  Part="1" 
AR Path="/5FC2CC0E/60C35D54" Ref="#PWR?"  Part="1" 
AR Path="/60B91B73/60C35D54" Ref="#PWR0154"  Part="1" 
F 0 "#PWR0154" H 6550 4500 50  0001 C CNN
F 1 "GND" H 6555 4577 50  0000 C CNN
F 2 "" H 6550 4750 50  0001 C CNN
F 3 "" H 6550 4750 50  0001 C CNN
	1    6550 4750
	1    0    0    -1  
$EndComp
$Comp
L Device:Polyfuse F?
U 1 1 60C35D4E
P 6150 4300
AR Path="/5FAFE50B/60C35D4E" Ref="F?"  Part="1" 
AR Path="/5FB05F69/60C35D4E" Ref="F?"  Part="1" 
AR Path="/60C35D4E" Ref="F?"  Part="1" 
AR Path="/5FC2CC0E/60C35D4E" Ref="F?"  Part="1" 
AR Path="/60B91B73/60C35D4E" Ref="F26"  Part="1" 
F 0 "F26" V 5925 4300 50  0000 C CNN
F 1 "Max 30mA" V 6016 4300 50  0000 C CNN
F 2 "Fuse:Fuse_0603_1608Metric" H 6200 4100 50  0001 L CNN
F 3 "530-0ZCM0001FF2G" H 6150 4300 50  0001 C CNN
F 4 "C426238" H 6150 4300 50  0001 C CNN "LCSC"
F 5 "Mouser" H 6150 4300 50  0001 C CNN "Comment"
	1    6150 4300
	0    1    1    0   
$EndComp
Wire Wire Line
	6550 4300 6700 4300
Wire Wire Line
	6550 4450 6550 4300
$Comp
L Device:R R?
U 1 1 60C35D46
P 6550 4600
AR Path="/5FAFE50B/60C35D46" Ref="R?"  Part="1" 
AR Path="/5FB05F69/60C35D46" Ref="R?"  Part="1" 
AR Path="/60C35D46" Ref="R?"  Part="1" 
AR Path="/5FC2CC0E/60C35D46" Ref="R?"  Part="1" 
AR Path="/60B91B73/60C35D46" Ref="R35"  Part="1" 
F 0 "R35" H 6620 4646 50  0000 L CNN
F 1 "160" H 6620 4555 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 6480 4600 50  0001 C CNN
F 3 "660-RK73B1JTTD161J" H 6550 4600 50  0001 C CNN
F 4 "C22814" H 6550 4600 50  0001 C CNN "LCSC"
F 5 "Mouser" H 6550 4600 50  0001 C CNN "Comment"
	1    6550 4600
	1    0    0    -1  
$EndComp
Text HLabel 7700 4300 2    50   Input ~ 0
PB14
$Comp
L power:GND #PWR?
U 1 1 5FC64D20
P 6550 3900
AR Path="/5FAFE50B/5FC64D20" Ref="#PWR?"  Part="1" 
AR Path="/5FB05F69/5FC64D20" Ref="#PWR?"  Part="1" 
AR Path="/5FC64D20" Ref="#PWR?"  Part="1" 
AR Path="/5FC2CC0E/5FC64D20" Ref="#PWR050"  Part="1" 
AR Path="/60B91B73/5FC64D20" Ref="#PWR0146"  Part="1" 
F 0 "#PWR0146" H 6550 3650 50  0001 C CNN
F 1 "GND" H 6555 3727 50  0000 C CNN
F 2 "" H 6550 3900 50  0001 C CNN
F 3 "" H 6550 3900 50  0001 C CNN
	1    6550 3900
	1    0    0    -1  
$EndComp
Text HLabel 1900 2050 0    50   Input ~ 0
DAI4M
Wire Notes Line
	10600 1450 10600 900 
Wire Notes Line
	6800 900  6800 1450
Text Notes 10500 1300 2    50   ~ 0
Here we convert 4-20mA to 0.64-3.2V due to the 160 ohm resistor.\nProtection is avaiable due to the polyfuse and the 160 ohm resistor for\nprotecting the zener diode and the zener diode protecting the analog input of the controller.
Wire Notes Line
	6800 1450 10600 1450
Wire Notes Line
	6800 900  10600 900 
$EndSCHEMATC
