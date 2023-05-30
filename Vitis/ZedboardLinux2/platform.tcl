# 
# Usage: To re-create this platform project launch xsct with below options.
# xsct C:\fake_d\ZedboardPractice\PetalinuxTest\Vitis\ZedboardLinux2\platform.tcl
# 
# OR launch xsct and run below command.
# source C:\fake_d\ZedboardPractice\PetalinuxTest\Vitis\ZedboardLinux2\platform.tcl
# 
# To create the platform in a different location, modify the -out option of "platform create" command.
# -out option specifies the output directory of the platform project.

platform create -name {ZedboardLinux2}\
-hw {C:\fake_d\ZedboardPractice\PetalinuxTest\Zynq_hardware\XSA_Files\HardwareConfig1_wrapper.xsa}\
-proc {ps7_cortexa9} -os {linux} -fsbl-target {psu_cortexa53_0} -out {C:/fake_d/ZedboardPractice/PetalinuxTest/Vitis}

platform write
platform active {ZedboardLinux2}
domain config -boot {C:\fake_d\ZedboardPractice\PetalinuxTest\OS\images\linux}
platform write
platform generate
platform clean
platform generate
platform clean
platform generate
