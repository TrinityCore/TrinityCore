file(GLOB_RECURSE scripts_Draenor_GrimrailDepot Draenor/GrimrailDepot/*.cpp Draenor/GrimrailDepot/*.h)

source_group(Draenor\\GrimrailDepot[Instance] FILES ${scripts_Draenor_GrimrailDepot})

set(scripts_STAT_SRCS
  ${scripts_STAT_SRCS}
  ${scripts_Draenor_GrimrailDepot}
)
