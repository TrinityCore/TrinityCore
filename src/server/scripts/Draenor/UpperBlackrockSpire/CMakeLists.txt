file(GLOB_RECURSE scripts_Draenor_UpperBlackrockSpire Draenor/UpperBlackrockSpire/*.cpp Draenor/UpperBlackrockSpire/*.h)

source_group(Draenor\\UpperBlackrockSpire[Instance] FILES ${scripts_Draenor_UpperBlackrockSpire})

set(scripts_STAT_SRCS
  ${scripts_STAT_SRCS}
  ${scripts_Draenor_UpperBlackrockSpire}
)
