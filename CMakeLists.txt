cmake_minimum_required(VERSION 3.5)
project(JudgerToTeaching)
set(CMAKE_CXX_STANDARD 11)
set(linuxUser none)
set(temp none)
set(linuxUserCMD whoami)
set(userHomeDir none)
message("************************************************************************************************************************************************************")
#获取linux当前用户家目录
#execute_process(COMMAND ${linuxUserCMD} OUTPUT_VARIABLE temp)
#string(REGEX REPLACE "\n$" "" linuxUser "${temp}") #去除换行
#message("current user:" ${linuxUser})
#if("${linuxUser}" STREQUAL "root")
#    set(userHomeDir /root)
#else()
#    set(userHomeDir /home/ "${linuxUser}")
#endif()
#message("user home dir:" "${userHomeDir}")
# 拼接程序工作目录
#string(APPEND configDir  ${userHomeDir} /.ets/judge)
#message("configDir:" ${configDir})
#set(cleanDir ${configDir} "/JudgeExeFilePath/* " ${configDir} "/JudgeOutputFilePath/*")
#message("cleanDir:" ${cleanDir})
#创建程序工作目录
#set(mkdirCMD "mkdir " ${configDir})
#MESSAGE("mkdirCMD:" ${mkdirCMD})
#set(mkdirResult success)
#execute_process(COMMAND mkdir -p ${configDir})
#file(MAKE_DIRECTORY ${configDir})
#execute_process(COMMAND ${CMAKE_COMMAND} -E
#        copy "${CMAKE_CURRENT_SOURCE_DIR}/config.ini"  "${configDir}"
#        )
#添加pthread库，seccomp库
link_libraries(seccomp)
link_libraries(pthread)
#判断编译器类型,如果是gcc编译器,则在编译选项中加入c++11支持
if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-std=c++11 -g ${CMAKE_CXX_FLAGS}")
endif(CMAKE_COMPILER_IS_GNUCXX)
set(CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS}")
include_directories(/usr/lib/jvm/java-8-openjdk-amd64/include/) # jni头文件
include_directories(/usr/lib/jvm/java-8-openjdk-amd64/include/linux)
message("************************************************************************************************************************************************************")
#execute_process(COMMAND rm -r ${configDir})
add_executable(JudgeToTeaching main.cpp compiler/Compiler.h common/Util.h compiler/CCompiler.cpp compiler/CCompiler.h compiler/CXXCompiler.cpp compiler/CXXCompiler.h checker/AnswerChecker.cpp checker/AnswerChecker.h controller/SubProcess.cpp controller/SubProcess.h controller/ProgramController.cpp controller/ProgramController.h common/Util.cpp controller/Pipe3.cpp controller/Pipe3.h common/Result.cpp common/Result.h common/ConfigurationTool.cpp common/ConfigurationTool.h common/JudgeConfig.cpp common/JudgeConfig.h common/Macro.h common/CharsetUtil.cpp common/CharsetUtil.h jni/jnimacro.h controller/SeccompRules.h controller/SeccompRules.cpp)

set(LIBRARY_OUTPUT_PATH "/root/IdeaProjects/ets/lib")
add_library(judge SHARED main.cpp compiler/Compiler.h common/Util.h compiler/CCompiler.cpp compiler/CCompiler.h compiler/CXXCompiler.cpp compiler/CXXCompiler.h checker/AnswerChecker.cpp checker/AnswerChecker.h controller/SubProcess.cpp controller/SubProcess.h controller/ProgramController.cpp controller/ProgramController.h common/Util.cpp controller/Pipe3.cpp controller/Pipe3.h common/Result.cpp common/Result.h common/ConfigurationTool.cpp common/ConfigurationTool.h common/JudgeConfig.cpp common/JudgeConfig.h common/Macro.h common/CharsetUtil.cpp common/CharsetUtil.h jni/jnimacro.h controller/SeccompRules.h controller/SeccompRules.cpp)

install(TARGETS judge
        EXPORT judgeStaticLibTarget
        LIBRARY DESTINATION /usr/lib # 动态库安装路径
        )