# Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

# file(GLOB_RECURSE sources_Custom *.cpp *.h)

set(scripts_STAT_SRCS
  ${scripts_STAT_SRCS}
  Draenor/worldboss_Drov.cpp
  Draenor/worldboss_Tarlna.cpp
  Draenor/worldboss_Rukhmar.cpp
  Draenor/Objects/Bonemaw_doorlevers.cpp
  Draenor/Objects/bossdoor_levers1.cpp
  Draenor/Raids/Highmaul/Highmaul_doorlevers.cpp
  Draenor/ShadowmoonValley/DefenseofKarabor/karabor_doorlevers.cpp
  Draenor/SpiresOfArrak/SpiresofArak_doorlevers.cpp
  Draenor/Dungeons/Auchindoun/Auchindoun.h
  Draenor/Dungeons/Auchindoun/instance_Auchindoun.cpp
  Draenor/Dungeons/Auchindoun/boss_azzakel.cpp
  Draenor/Dungeons/Auchindoun/boss_Nyami.cpp
  Draenor/Dungeons/Auchindoun/boss_ProtectorOfAuch.cpp
  Draenor/Dungeons/Auchindoun/boss_Terongor.cpp
  Draenor/Dungeons/BloodmaulSlagMines/BloodmaulSlagMines.h
  Draenor/Dungeons/BloodmaulSlagMines/instance_BloodmaulSlagMines.cpp
  Draenor/Dungeons/BloodmaulSlagMines/boss_Crushto.cpp
  Draenor/Dungeons/BloodmaulSlagMines/boss_Gugrokk.cpp
  Draenor/Dungeons/BloodmaulSlagMines/boss_Magmolatus.cpp
  Draenor/Dungeons/BloodmaulSlagMines/boss_Roltall.cpp
  Draenor/Dungeons/GrimrailDepot/GrimrailDepot.h
  Draenor/Dungeons/GrimrailDepot/instance_GrimrailDepot.cpp
  Draenor/Dungeons/GrimrailDepot/boss_BlackrockAssaultCommander.cpp
  Draenor/Dungeons/GrimrailDepot/boss_RocketAndBorka.cpp
  Draenor/Dungeons/GrimrailDepot/boss_ThunderlordGeneral.cpp
  Draenor/Dungeons/IronDocks/IronDocks.h
  Draenor/Dungeons/IronDocks/instance_IronDocks.cpp
  Draenor/Dungeons/IronDocks/boss_GrimrailEnforcers.cpp
  Draenor/Dungeons/IronDocks/boss_Nokgar.cpp
  Draenor/Dungeons/IronDocks/boss_Oshir.cpp
  Draenor/Dungeons/IronDocks/boss_Skulloc.cpp
  Draenor/Dungeons/ShadowmoonBurialGrounds/ShadowmoonBurialGrounds.h
  Draenor/Dungeons/ShadowmoonBurialGrounds/instance_ShadowmoonBurialGrounds.cpp
  Draenor/Dungeons/ShadowmoonBurialGrounds/boss_Bonemaw.cpp
  Draenor/Dungeons/ShadowmoonBurialGrounds/boss_Nerzhul.cpp
  Draenor/Dungeons/ShadowmoonBurialGrounds/boss_Nhallish.cpp
  Draenor/Dungeons/ShadowmoonBurialGrounds/boss_SadanaBloodfury.cpp
  Draenor/Dungeons/Skyreach/Skyreach.h
  Draenor/Dungeons/Skyreach/instance_Skyreach.cpp
  Draenor/Dungeons/Skyreach/boss_Araknath.cpp
  Draenor/Dungeons/Skyreach/boss_Ranjit.cpp
  Draenor/Dungeons/Skyreach/boss_Rukhran.cpp
  Draenor/Dungeons/Skyreach/boss_Viryx.cpp
  Draenor/Dungeons/TheEverbloom/TheEverbloom.h
  Draenor/Dungeons/TheEverbloom/instance_TheEverbloom.cpp
  Draenor/Dungeons/TheEverbloom/boss_AncientProtectors.cpp
  Draenor/Dungeons/TheEverbloom/boss_ArchmageSol.cpp
  Draenor/Dungeons/TheEverbloom/boss_Witherbark.cpp
  Draenor/Dungeons/TheEverbloom/boss_Xeritac.cpp
  Draenor/Dungeons/TheEverbloom/boss_Yalnu.cpp
  Draenor/Dungeons/UpperBlackrockSpire/UpperBlackrockSpire.h
  Draenor/Dungeons/UpperBlackrockSpire/instance_UpperBlackrockSpire.cpp
  Draenor/Dungeons/UpperBlackrockSpire/boss_Gorashan.cpp
  Draenor/Dungeons/UpperBlackrockSpire/boss_Kyrak.cpp
  Draenor/Dungeons/UpperBlackrockSpire/boss_Ragewing.cpp
  Draenor/Dungeons/UpperBlackrockSpire/boss_Tharbek.cpp
  Draenor/Dungeons/UpperBlackrockSpire/boss_Zaela.cpp
  Draenor/Raids/BlackrockFoundry/BlackrockFoundry.h
  Draenor/Raids/BlackrockFoundry/instance_BlackrockFoundry.cpp
  Draenor/Raids/BlackrockFoundry/boss_Blackhand.cpp
  Draenor/Raids/BlackrockFoundry/boss_Darmac.cpp
  Draenor/Raids/BlackrockFoundry/boss_HansgarAndFranzok.cpp
  Draenor/Raids/BlackrockFoundry/boss_Kagraz.cpp
  Draenor/Raids/BlackrockFoundry/boss_Kromog.cpp
  Draenor/Raids/BlackrockFoundry/boss_Oregorger.cpp
  Draenor/Raids/BlackrockFoundry/boss_TheBlastFurnace.cpp
  Draenor/Raids/BlackrockFoundry/boss_TheIronMaidens.cpp
  Draenor/Raids/BlackrockFoundry/boss_Thogar.cpp
  Draenor/Raids/Highmaul/Highmaul.h
  Draenor/Raids/Highmaul/instance_Highmaul.cpp
  Draenor/Raids/Highmaul/boss_Brackenspore.cpp
  Draenor/Raids/Highmaul/boss_KargathBladefist.cpp
  Draenor/Raids/Highmaul/boss_Koragh.cpp
  Draenor/Raids/Highmaul/boss_Margok.cpp
  Draenor/Raids/Highmaul/boss_Tectus.cpp
  Draenor/Raids/Highmaul/boss_TheButcher.cpp
  Draenor/Raids/Highmaul/boss_TwinOgron.cpp
  Draenor/Garrisons/Garrison_Frostwall/Garrison_Frostwall.cpp
)

message("  -> Prepared: Draenor")
