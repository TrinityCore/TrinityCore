
########### next target ###############

SET(trinityinterface_LIB_SRCS
   ScriptMgr.cpp
   ScriptMgr.h
   config.h
   system.cpp
   Scripts/sc_default.cpp
   Scripts/sc_defines.cpp
   Scripts/sc_defines.h
   Scripts/on_events.cpp
)

add_library(trinityinterface SHARED ${trinityinterface_LIB_SRCS})

target_link_libraries(trinityinterface)

set_target_properties(trinityinterface PROPERTIES VERSION 4.2.0 SOVERSION 4)
install(TARGETS trinityinterface DESTINATION lib)
