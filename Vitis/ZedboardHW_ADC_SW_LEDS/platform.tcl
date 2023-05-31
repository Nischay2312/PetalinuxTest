# 
# Usage: To re-create this platform project launch xsct with below options.
# xsct C:\fake_d\ZedboardPractice\PetalinuxTest\Vitis\ZedboardHW_ADC_SW_LEDS\platform.tcl
# 
# OR launch xsct and run below command.
# source C:\fake_d\ZedboardPractice\PetalinuxTest\Vitis\ZedboardHW_ADC_SW_LEDS\platform.tcl
# 
# To create the platform in a different location, modify the -out option of "platform create" command.
# -out option specifies the output directory of the platform project.

platform create -name {ZedboardHW_ADC_SW_LEDS}\
-hw {D:\ZedboardPractice\PetalinuxTest\Zynq_hardware\XSA_Files\ZynqSystem2_LED_SW_ADC.xsa}\
-proc {ps7_cortexa9} -os {linux} -fsbl-target {psu_cortexa53_0} -out {C:/fake_d/ZedboardPractice/PetalinuxTest/Vitis}

platform write
platform active {ZedboardHW_ADC_SW_LEDS}
domain config -boot {C:\fake_d\ZedboardPractice\PetalinuxTest\OS\images\linux}
platform write
platform generate
platform clean
platform generate
