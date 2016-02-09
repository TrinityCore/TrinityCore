file(GLOB_RECURSE scripts_Draenor_Auchinoun Draenor/Auchinoun/*.cpp Draenor/Auchinoun/*.h)

source_group(Draenor\\Auchinoun[Instance] FILES ${scripts_Draenor_Auchinoun})

set(scripts_STAT_SRCS
  ${scripts_STAT_SRCS}
  ${scripts_Draenor_Auchinoun}
)
