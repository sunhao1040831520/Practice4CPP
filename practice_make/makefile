# gcc/g++ 编译流程
#	1.预处理，生成.i的文件
#	2.将预处理后的文件转换成汇编语言，生成.s文件
#	3.汇编变为目标代码(机器代码)生成.o的文件
#	4.连接目标代码,生成可执行程序
# makefile 语法规则
#		target(标签) : prerequisites(先决条件，依赖文件)
#			command(指令)
#			command(指令)
# 单个手写实现编译
# myapp: include/main.h include/module1.h include/module2.h include/module3.h
	# g++ -o myapp src/main.cpp src/module1.cpp src/module2.cpp src/module3.cpp



# C 编译参数 
CFLAGS		:= -Wall -O2 -fno-builtin
# CPP 编译参数
CPPFLAGS	:= 

#获取工程的根目录的全路径
SOURCE_ROOT = $(shell pwd)
# g++ 编译指令
CC = g++
# 编译后的文件名
EXEC = app
# 找寻头文件，将其添加到依赖位置，使得 make 是检测到 .h 头文件内容修改
DESP = $(shell find ./ -name *.h)
DESP = $(wildcard ./include/*.h ./include2/*.h)
# 所有的 .cpp 文件，使得 make 能找到并编译单个 cpp 程序
SRC = ${shell find ./ -name *.cpp}
# .o 文件是汇编代码，可执行文件，只需要连接动态库就可生成 可执行文件
# 将所有符合 SRC:xx.cpp 的字段替换成 SRC:xx.o 字段
OBJ = $(SRC:%.cpp=%.o)

# 动态库链接(link): .o  ---> 可执行文件
# 依赖的 ObjectFile 会自动生成，下次编译没有修改的cpp，相应的.o文件也不会再次编译
#  $(OBJ) 找到本makefile定好的操作：   $(OBJ): %.o:%.cpp
$(EXEC): $(OBJ) $(DESP)
	@echo "主 Makefile begin"
	# @make other-all
	$(CC) -o $(EXEC) $(OBJ)
	@echo "主 Makefile End"


# 编译成动态连接库文件(.so)
lib.so: $(OBJ) $(DESP)
	@echo begin compile execution
	$(CC) -shared $(OBJ) -o lib.so


# 编译(compile):	.cpp源文件 ---> .o目标文件文件
# %.o:%.cpp:	表示所有的.o目标都依赖于与它同名的.c文件
 $(OBJ): %.o:%.cpp
	$(CC)  $(CPPFLAGS) -fPIC -c $< -o $@ 
# $@ 	目标集合
# $% 	当目标是函数库文件时, 表示其中的目标文件名
# $< 	第一个依赖目标. 如果依赖目标是多个, 逐个表示依赖目标
# $? 	比目标新的依赖目标的集合
# $^ 	所有依赖目标的集合, 会去除重复的依赖目标
# $+ 	所有依赖目标的集合, 不会去除重复的依赖目标
# $* 	这个是GNU make特有的, 其它的make不一定支持



# 清除任务
# .PHONY: clean 表示伪目标，不会真正生成目标，不加也行
.PHONY: clean  
clean:
	rm -f lib.so
	rm -f $(EXEC) 
	rm -f $(OBJ)