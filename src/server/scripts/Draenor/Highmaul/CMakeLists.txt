file(GLOB_RECURSE scripts_Draenor_Highmaul Draenor/Highmaul/*.cpp Draenor/Highmaul/*.h)

source_group(Draenor\\Highmaul[Raid] FILES ${scripts_Draenor_Highmaul})

set(scripts_STAT_SRCS
  ${scripts_STAT_SRCS}
  ${scripts_Draenor_Highmaul}
)
