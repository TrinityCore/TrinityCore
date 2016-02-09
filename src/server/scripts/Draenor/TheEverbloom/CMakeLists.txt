file(GLOB_RECURSE scripts_Draenor_TheEverbloom Draenor/TheEverbloom/*.cpp Draenor/TheEverbloom/*.h)

source_group(Draenor\\TheEverbloom[Instance] FILES ${scripts_Draenor_TheEverbloom})

set(scripts_STAT_SRCS
  ${scripts_STAT_SRCS}
  ${scripts_Draenor_TheEverbloom}
)
