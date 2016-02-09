file(GLOB_RECURSE scripts_Draenor_Skyreach Draenor/Skyreach/*.cpp Draenor/Skyreach/*.h)

source_group(Draenor\\Skyreach[Instance] FILES ${scripts_Draenor_Skyreach})

set(scripts_STAT_SRCS
  ${scripts_STAT_SRCS}
  ${scripts_Draenor_Skyreach}
)
