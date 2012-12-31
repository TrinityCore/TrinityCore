# Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

set(scripts_STAT_SRCS
  ${scripts_STAT_SRCS}
  Commands/cs_account.cpp
  Commands/cs_achievement.cpp
  Commands/cs_ban.cpp
  Commands/cs_bf.cpp
  Commands/cs_cast.cpp
  Commands/cs_character.cpp
  Commands/cs_cheat.cpp
  Commands/cs_debug.cpp
  Commands/cs_disable.cpp
  Commands/cs_event.cpp
  Commands/cs_gm.cpp
  Commands/cs_go.cpp
  Commands/cs_gobject.cpp
  Commands/cs_guild.cpp
  Commands/cs_honor.cpp
  Commands/cs_instance.cpp
  Commands/cs_learn.cpp
  Commands/cs_lfg.cpp
  Commands/cs_list.cpp
  Commands/cs_lookup.cpp
  Commands/cs_message.cpp
  Commands/cs_misc.cpp
  Commands/cs_modify.cpp
  Commands/cs_npc.cpp
  Commands/cs_quest.cpp
  Commands/cs_reload.cpp
  Commands/cs_reset.cpp
  Commands/cs_tele.cpp
  Commands/cs_ticket.cpp
  Commands/cs_server.cpp
  Commands/cs_titles.cpp
  Commands/cs_wp.cpp
#  Commands/cs_pdump.cpp
#  Commands/cs_channel.cpp
#  Commands/cs_pet.cpp
#  Commands/cs_aura.cpp
#  Commands/cs_unaura.cpp
#  Commands/cs_nameannounce.cpp
#  Commands/cs_gmnameannounce.cpp
#  Commands/cs_announce.cpp
#  Commands/cs_gmannounce.cpp
#  Commands/cs_notify.cpp
#  Commands/cs_gmnotify.cpp
#  Commands/cs_appear.cpp
#  Commands/cs_summon.cpp
#  Commands/cs_groupsummon.cpp
#  Commands/cs_commands.cpp
#  Commands/cs_demorph.cpp
#  Commands/cs_die.cpp
#  Commands/cs_revive.cpp
#  Commands/cs_dismount.cpp
#  Commands/cs_guid.cpp
#  Commands/cs_help.cpp
#  Commands/cs_itemmove.cpp
#  Commands/cs_cooldown.cpp
#  Commands/cs_unlearn.cpp
#  Commands/cs_distance.cpp
#  Commands/cs_recall.cpp
#  Commands/cs_save.cpp
#  Commands/cs_saveall.cpp
#  Commands/cs_kick.cpp
#  Commands/cs_start.cpp
#  Commands/cs_taxicheat.cpp
#  Commands/cs_linkgrave.cpp
#  Commands/cs_neargrave.cpp
#  Commands/cs_explorecheat.cpp
#  Commands/cs_hover.cpp
#  Commands/cs_levelup.cpp
#  Commands/cs_showarea.cpp
#  Commands/cs_hidearea.cpp
#  Commands/cs_additem.cpp
#  Commands/cs_additemset.cpp
#  Commands/cs_bank.cpp
#  Commands/cs_wchange.cpp
#  Commands/cs_maxskill.cpp
#  Commands/cs_setskill.cpp
#  Commands/cs_whispers.cpp
#  Commands/cs_pinfo.cpp
#  Commands/cs_respawn.cpp
#  Commands/cs_send.cpp
#  Commands/cs_mute.cpp
#  Commands/cs_unmute.cpp
#  Commands/cs_movegens.cpp
#  Commands/cs_cometome.cpp
#  Commands/cs_damage.cpp
#  Commands/cs_combatstop.cpp
#  Commands/cs_flusharenapoints.cpp
#  Commands/cs_repairitems.cpp
#  Commands/cs_waterwalk.cpp
#  Commands/cs_freeze.cpp
#  Commands/cs_unfreeze.cpp
#  Commands/cs_listfreeze.cpp
#  Commands/cs_possess.cpp
#  Commands/cs_unpossess.cpp
#  Commands/cs_bindsight.cpp
#  Commands/cs_unbindsight.cpp
#  Commands/cs_playall.cpp
)

message("  -> Prepared: Commands")
