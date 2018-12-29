# 由于编译中出现许多中间的文件，因此最好新建一个独立的目录build，在该目录下进行编译，编译步骤如下所示
# cmake ..
# make



#1.cmake verson，指定cmake版本
cmake_minimum_required(VERSION 3.2)

#2.project name，指定项目的名称，一般和项目的文件夹名称对应
PROJECT(practice_cmake)

#3.head file path，头文件目录
INCLUDE_DIRECTORIES(
include
)

#4. source directory: 搜集所有在指定路径下的源文件的文件名，将输出结果列表储存在指定的变量中
AUX_SOURCE_DIRECTORY(src DIR_SRCS)
AUX_SOURCE_DIRECTORY(src2 DIR_SRCS2)

#5.set environment variable，设置环境变量，编译用到的源文件全部都要放到这里，否则编译能够通过，但是执行的时候会出现各种问题，比如"symbol lookup error xxxxx , undefined symbol"
# 将所有的源文件变量添加到变量 TEST_MATH 中
SET(TEST_MATH
${DIR_SRCS}
${DIR_SRCS2}
)

#6.add executable file，添加要编译的可执行文件
# ${PROJECT_NAME}: 是步骤2设置的工程名
# ${TEST_MATH}:    是步骤5设置的环境变量，其中有所有的源码路径，包括 src、src2
ADD_EXECUTABLE(${PROJECT_NAME} ${TEST_MATH})

#7.add link library，添加可执行文件所需要的库，比如我们用到了libm.so（命名规则：lib+name+.so），就添加该库的名称
# ${PROJECT_NAME}: 是步骤2设置的工程名
TARGET_LINK_LIBRARIES(${PROJECT_NAME} m)