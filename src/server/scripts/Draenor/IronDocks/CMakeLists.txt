file(GLOB_RECURSE scripts_Draenor_IronDocks_FleshrenderNokgar Draenor/IronDocks/FleshrenderNokgar/*.cpp Draenor/IronDocks/FleshrenderNokgar/*.h)
file(GLOB_RECURSE scripts_Draenor_IronDocks_GrimrailEnforcers Draenor/IronDocks/GrimrailEnforcers/*.cpp Draenor/IronDocks/GrimrailEnforcers/*.h)
file(GLOB_RECURSE scripts_Draenor_IronDocks_Oshir Draenor/IronDocks/Oshir/*.cpp Draenor/IronDocks/Oshir/*.h)
file(GLOB_RECURSE scripts_Draenor_IronDocks_Skulloc Draenor/IronDocks/Skulloc/*.cpp Draenor/IronDocks/Skulloc/*.h)
file(GLOB scripts_Draenor_IronDocks Draenor/IronDocks/*.cpp Draenor/IronDocks/*.h)

source_group(Draenor\\IronDocks[Instance]\\[1]FleshrenderNokgar FILES ${scripts_Draenor_IronDocks_FleshrenderNokgar})
source_group(Draenor\\IronDocks[Instance]\\[2]GrimrailEnforcers FILES ${scripts_Draenor_IronDocks_GrimrailEnforcers})
source_group(Draenor\\IronDocks[Instance]\\[3]Oshir FILES ${scripts_Draenor_IronDocks_Oshir})
source_group(Draenor\\IronDocks[Instance]\\[4]Skulloc FILES ${scripts_Draenor_IronDocks_Skulloc})
source_group(Draenor\\IronDocks[Instance] FILES ${scripts_Draenor_IronDocks})

set(scripts_STAT_SRCS
  ${scripts_STAT_SRCS}
  ${scripts_Draenor_IronDocks_FleshrenderNokgar}
  ${scripts_Draenor_IronDocks_GrimrailEnforcers}
  ${scripts_Draenor_IronDocks_Oshir}
  ${scripts_Draenor_IronDocks_Skulloc}
  ${scripts_Draenor_IronDocks}
)