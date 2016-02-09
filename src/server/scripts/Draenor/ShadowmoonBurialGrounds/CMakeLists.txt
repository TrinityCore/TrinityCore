file(GLOB_RECURSE scripts_Draenor_ShadowmoonBurialGrounds Draenor/ShadowmoonBurialGrounds/*.cpp Draenor/ShadowmoonBurialGrounds/*.h)

source_group(Draenor\\ShadowmoonBurialGrounds[Instance] FILES ${scripts_Draenor_ShadowmoonBurialGrounds})

set(scripts_STAT_SRCS
  ${scripts_STAT_SRCS}
  ${scripts_Draenor_ShadowmoonBurialGrounds}
)
