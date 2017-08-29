cmake_minimum_required(VERSION 3.4.1)

set(cpp_path src/main/cpp)
# 设置SO库路径
set(my_lib_path ${CMAKE_SOURCE_DIR}/libs)

#将第三方库作为动态库引用
add_library( fmod
             SHARED
             IMPORTED)
set_target_properties(fmod
                      PROPERTIES IMPORTED_LOCATION
                      ${my_lib_path}/${ANDROID_ABI}/libfmod.so)

add_library( fmodL
             SHARED
             IMPORTED)
set_target_properties(fmodL
                      PROPERTIES IMPORTED_LOCATION
                      ${my_lib_path}/${ANDROID_ABI}/libfmodL.so)

#变声
add_library( effect_utils
             SHARED
             ${cpp_path}/com_levylin_voicechange_EffectUtils.cpp
             ${cpp_path}/play_sound.cpp
             ${cpp_path}/common.cpp
             ${cpp_path}/common_platform.cpp)

find_library( log-lib
              log )

target_link_libraries( #effects
                       effect_utils
                       fmod
                       fmodL
                       ${log-lib} )