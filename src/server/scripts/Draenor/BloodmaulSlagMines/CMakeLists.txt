file(GLOB_RECURSE scripts_Draenor_BloodmaulSlagMines_SlaveWatcherCrushto Draenor/BloodmaulSlagMines/SlaveWatcherCrushto/*.cpp Draenor/BloodmaulSlagMines/SlaveWatcherCrushto/*.h)
file(GLOB_RECURSE scripts_Draenor_BloodmaulSlagMines_ForgemasterGogDuh Draenor/BloodmaulSlagMines/ForgemasterGogDuh/*.cpp Draenor/BloodmaulSlagMines/ForgemasterGogDuh/*.h)
file(GLOB_RECURSE scripts_Draenor_BloodmaulSlagMines_Roltall Draenor/BloodmaulSlagMines/Roltall/*.cpp Draenor/BloodmaulSlagMines/Roltall/*.h)
file(GLOB_RECURSE scripts_Draenor_BloodmaulSlagMines_GugRokk Draenor/BloodmaulSlagMines/GugRokk/*.cpp Draenor/BloodmaulSlagMines/GugRokk/*.h)
file(GLOB scripts_Draenor_BloodmaulSlagMines Draenor/BloodmaulSlagMines/*.cpp Draenor/BloodmaulSlagMines/*.h)

source_group(Draenor\\BloodmaulSlagMines[Instance]\\[1]SlaveWatcherCrushto FILES ${scripts_Draenor_BloodmaulSlagMines_SlaveWatcherCrushto})
source_group(Draenor\\BloodmaulSlagMines[Instance]\\[2]ForgemasterGogDuh FILES ${scripts_Draenor_BloodmaulSlagMines_ForgemasterGogDuh})
source_group(Draenor\\BloodmaulSlagMines[Instance]\\[3]Roltall FILES ${scripts_Draenor_BloodmaulSlagMines_Roltall})
source_group(Draenor\\BloodmaulSlagMines[Instance]\\[4]GugRokk FILES ${scripts_Draenor_BloodmaulSlagMines_GugRokk})
source_group(Draenor\\BloodmaulSlagMines[Instance]\\ FILES ${scripts_Draenor_BloodmaulSlagMines})

set(scripts_STAT_SRCS
  ${scripts_STAT_SRCS}
  ${scripts_Draenor_BloodmaulSlagMines_SlaveWatcherCrushto}
  ${scripts_Draenor_BloodmaulSlagMines_ForgemasterGogDuh}
  ${scripts_Draenor_BloodmaulSlagMines_Roltall}
  ${scripts_Draenor_BloodmaulSlagMines_GugRokk}
  ${scripts_Draenor_BloodmaulSlagMines}
)
