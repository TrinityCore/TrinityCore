# Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
#
# Copyright (C) 2008 Trinity <http://www.trinitycore.org/>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

## Process this file with automake to produce Makefile.in

## Sub-directories to parse

## CPP flags for includes, defines, etc.
AM_CPPFLAGS = 

## Build MaNGOS game library as convenience library.
#  All libraries will be convenience libraries. Might be changed to shared
#  later.
noinst_LIBRARIES = libgame.a

libgame_a_CPPFLAGS = \
$(MYSQL_INCLUDES) \
$(POSTGRE_INCLUDES) \
$(TRINI_INCLUDES) \
-I$(top_srcdir)/dep/include \
-I$(top_srcdir)/src/framework \
-I$(top_srcdir)/src/shared \
-I$(top_srcdir)/src/shared/vmap

#  libmangossgame library will later be reused by ...
libgame_a_SOURCES = \
$(srcdir)/AccountMgr.cpp \
$(srcdir)/AccountMgr.h \
$(srcdir)/AddonHandler.cpp \
$(srcdir)/AddonHandler.h \
$(srcdir)/AggressorAI.cpp \
$(srcdir)/AggressorAI.h \
$(srcdir)/AnimalRandomMovementGenerator.h \
$(srcdir)/ArenaTeam.cpp \
$(srcdir)/ArenaTeam.h \
$(srcdir)/ArenaTeamHandler.cpp \
$(srcdir)/AuctionHouse.cpp \
$(srcdir)/AuctionHouseObject.h \
$(srcdir)/Bag.cpp \
$(srcdir)/Bag.h \
$(srcdir)/BattleGround.cpp \
$(srcdir)/BattleGroundAA.cpp \
$(srcdir)/BattleGroundAB.cpp \
$(srcdir)/BattleGroundAV.cpp \
$(srcdir)/BattleGroundBE.cpp \
$(srcdir)/BattleGroundEY.cpp \
$(srcdir)/BattleGroundNA.cpp \
$(srcdir)/BattleGroundRL.cpp \
$(srcdir)/BattleGroundWS.cpp \
$(srcdir)/BattleGround.h \
$(srcdir)/BattleGroundAA.h \
$(srcdir)/BattleGroundAB.h \
$(srcdir)/BattleGroundAV.h \
$(srcdir)/BattleGroundBE.h \
$(srcdir)/BattleGroundEY.h \
$(srcdir)/BattleGroundNA.h \
$(srcdir)/BattleGroundRL.h \
$(srcdir)/BattleGroundWS.h \
$(srcdir)/BattleGroundHandler.cpp \
$(srcdir)/BattleGroundMgr.cpp \
$(srcdir)/BattleGroundMgr.h \
$(srcdir)/Cell.h \
$(srcdir)/CellImpl.h \
$(srcdir)/Channel.cpp \
$(srcdir)/Channel.h \
$(srcdir)/ChannelHandler.cpp \
$(srcdir)/ChannelMgr.h \
$(srcdir)/CharacterHandler.cpp \
$(srcdir)/Chat.cpp \
$(srcdir)/Chat.h \
$(srcdir)/ChatHandler.cpp \
$(srcdir)/CombatHandler.cpp \
$(srcdir)/ConfusedMovementGenerator.cpp \
$(srcdir)/ConfusedMovementGenerator.h \
$(srcdir)/Corpse.cpp \
$(srcdir)/Corpse.h \
$(srcdir)/CreatureAI.cpp \
$(srcdir)/CreatureAI.h \
$(srcdir)/CreatureAIImpl.h \
$(srcdir)/CreatureAIRegistry.cpp \
$(srcdir)/CreatureAIRegistry.h \
$(srcdir)/CreatureAISelector.cpp \
$(srcdir)/CreatureAISelector.h \
$(srcdir)/CreatureGroups.cpp \
$(srcdir)/CreatureGroups.h \
$(srcdir)/Creature.cpp \
$(srcdir)/Creature.h \
$(srcdir)/debugcmds.cpp \
$(srcdir)/DestinationHolder.cpp \
$(srcdir)/DestinationHolder.h \
$(srcdir)/DestinationHolderImp.h \
$(srcdir)/DuelHandler.cpp \
$(srcdir)/DynamicObject.cpp \
$(srcdir)/DynamicObject.h \
$(srcdir)/FleeingMovementGenerator.cpp \
$(srcdir)/FleeingMovementGenerator.h \
$(srcdir)/Formulas.h \
$(srcdir)/GameEvent.cpp \
$(srcdir)/GameEvent.h \
$(srcdir)/GameObject.cpp \
$(srcdir)/GameObject.h \
$(srcdir)/GlobalEvents.cpp \
$(srcdir)/GlobalEvents.h \
$(srcdir)/GMTicketHandler.cpp \
$(srcdir)/GMTicketMgr.cpp \
$(srcdir)/GMTicketMgr.h \
$(srcdir)/GossipDef.cpp \
$(srcdir)/GossipDef.h \
$(srcdir)/GridDefines.h \
$(srcdir)/GridNotifiers.cpp \
$(srcdir)/GridNotifiers.h \
$(srcdir)/GridNotifiersImpl.h \
$(srcdir)/GridStates.cpp \
$(srcdir)/GridStates.h \
$(srcdir)/Group.cpp \
$(srcdir)/Group.h \
$(srcdir)/GroupHandler.cpp \
$(srcdir)/GuardAI.cpp \
$(srcdir)/GuardAI.h \
$(srcdir)/Guild.cpp \
$(srcdir)/Guild.h \
$(srcdir)/GuildHandler.cpp \
$(srcdir)/HomeMovementGenerator.cpp \
$(srcdir)/HomeMovementGenerator.h \
$(srcdir)/HostilRefManager.cpp \
$(srcdir)/HostilRefManager.h \
$(srcdir)/IdleMovementGenerator.cpp \
$(srcdir)/IdleMovementGenerator.h \
$(srcdir)/InstanceData.cpp \
$(srcdir)/InstanceData.h \
$(srcdir)/InstanceSaveMgr.cpp \
$(srcdir)/InstanceSaveMgr.h \
$(srcdir)/Item.cpp \
$(srcdir)/Item.h \
$(srcdir)/ItemEnchantmentMgr.cpp \
$(srcdir)/ItemEnchantmentMgr.h \
$(srcdir)/ItemHandler.cpp \
$(srcdir)/ItemPrototype.h \
$(srcdir)/Language.h \
$(srcdir)/Level0.cpp \
$(srcdir)/Level1.cpp \
$(srcdir)/Level2.cpp \
$(srcdir)/Level3.cpp \
$(srcdir)/LFGHandler.cpp \
$(srcdir)/LootHandler.cpp \
$(srcdir)/LootMgr.cpp \
$(srcdir)/LootMgr.h \
$(srcdir)/Mail.cpp \
$(srcdir)/Mail.h \
$(srcdir)/Map.cpp \
$(srcdir)/Map.h \
$(srcdir)/MapInstanced.cpp \
$(srcdir)/MapInstanced.h \
$(srcdir)/MapManager.cpp \
$(srcdir)/MapManager.h \
$(srcdir)/MiscHandler.cpp \
$(srcdir)/MotionMaster.cpp \
$(srcdir)/MotionMaster.h \
$(srcdir)/MovementGenerator.cpp \
$(srcdir)/MovementGenerator.h \
$(srcdir)/MovementGeneratorImpl.h \
$(srcdir)/MovementHandler.cpp \
$(srcdir)/NPCHandler.cpp \
$(srcdir)/NPCHandler.h \
$(srcdir)/NullCreatureAI.cpp \
$(srcdir)/NullCreatureAI.h \
$(srcdir)/ObjectAccessor.cpp \
$(srcdir)/ObjectAccessor.h \
$(srcdir)/Object.cpp \
$(srcdir)/ObjectDefines.h \
$(srcdir)/ObjectGridLoader.cpp \
$(srcdir)/ObjectGridLoader.h \
$(srcdir)/Object.h \
$(srcdir)/ObjectMgr.cpp \
$(srcdir)/ObjectMgr.h \
$(srcdir)/Opcodes.cpp \
$(srcdir)/Opcodes.h \
$(srcdir)/OutdoorPvP.cpp \
$(srcdir)/OutdoorPvP.h \
$(srcdir)/OutdoorPvPEP.cpp \
$(srcdir)/OutdoorPvPEP.h \
$(srcdir)/OutdoorPvPHP.cpp \
$(srcdir)/OutdoorPvPHP.h \
$(srcdir)/OutdoorPvPMgr.cpp \
$(srcdir)/OutdoorPvPMgr.h \
$(srcdir)/OutdoorPvPNA.cpp \
$(srcdir)/OutdoorPvPNA.h \
$(srcdir)/OutdoorPvPObjectiveAI.cpp \
$(srcdir)/OutdoorPvPObjectiveAI.h \
$(srcdir)/OutdoorPvPSI.cpp \
$(srcdir)/OutdoorPvPSI.h \
$(srcdir)/OutdoorPvPTF.cpp \
$(srcdir)/OutdoorPvPTF.h \
$(srcdir)/OutdoorPvPZM.cpp \
$(srcdir)/OutdoorPvPZM.h \
$(srcdir)/Path.h \
$(srcdir)/PetAI.cpp \
$(srcdir)/PetAI.h \
$(srcdir)/Pet.cpp \
$(srcdir)/Pet.h \
$(srcdir)/PetHandler.cpp \
$(srcdir)/PetitionsHandler.cpp \
$(srcdir)/Player.cpp \
$(srcdir)/Player.h \
$(srcdir)/PlayerDump.cpp \
$(srcdir)/PlayerDump.h \
$(srcdir)/PointMovementGenerator.cpp \
$(srcdir)/PointMovementGenerator.h \
$(srcdir)/PossessedAI.cpp \
$(srcdir)/PossessedAI.h \
$(srcdir)/QueryHandler.cpp \
$(srcdir)/QuestDef.cpp \
$(srcdir)/QuestDef.h \
$(srcdir)/QuestHandler.cpp \
$(srcdir)/RandomMovementGenerator.cpp \
$(srcdir)/RandomMovementGenerator.h \
$(srcdir)/ReactorAI.cpp \
$(srcdir)/ReactorAI.h \
$(srcdir)/ScriptCalls.cpp \
$(srcdir)/ScriptCalls.h \
$(srcdir)/SharedDefines.h \
$(srcdir)/SkillHandler.cpp \
$(srcdir)/SpellAuraDefines.h \
$(srcdir)/SpellAuras.cpp \
$(srcdir)/SpellAuras.h \
$(srcdir)/Spell.cpp \
$(srcdir)/SpellEffects.cpp \
$(srcdir)/Spell.h \
$(srcdir)/SkillDiscovery.cpp \
$(srcdir)/SkillDiscovery.h \
$(srcdir)/SkillExtraItems.cpp \
$(srcdir)/SkillExtraItems.h \
$(srcdir)/SpellHandler.cpp \
$(srcdir)/SocialMgr.cpp \
$(srcdir)/SocialMgr.h \
$(srcdir)/SpellMgr.cpp \
$(srcdir)/SpellMgr.h \
$(srcdir)/StatSystem.cpp \
$(srcdir)/TargetedMovementGenerator.cpp \
$(srcdir)/TargetedMovementGenerator.h \
$(srcdir)/TaxiHandler.cpp \
$(srcdir)/TemporarySummon.cpp \
$(srcdir)/TemporarySummon.h \
$(srcdir)/tools.cpp \
$(srcdir)/Tools.h \
$(srcdir)/TotemAI.cpp \
$(srcdir)/TotemAI.h \
$(srcdir)/Totem.cpp \
$(srcdir)/Totem.h \
$(srcdir)/TradeHandler.cpp \
$(srcdir)/Transports.cpp \
$(srcdir)/Transports.h \
$(srcdir)/ThreatManager.cpp \
$(srcdir)/ThreatManager.h \
$(srcdir)/Traveller.h \
$(srcdir)/Unit.cpp \
$(srcdir)/Unit.h \
$(srcdir)/UnitEvents.h \
$(srcdir)/UpdateData.cpp \
$(srcdir)/UpdateData.h \
$(srcdir)/UpdateFields.h \
$(srcdir)/UpdateMask.h \
$(srcdir)/VoiceChatHandler.cpp \
$(srcdir)/WaypointManager.cpp \
$(srcdir)/WaypointManager.h \
$(srcdir)/WaypointMovementGenerator.cpp \
$(srcdir)/WaypointMovementGenerator.h \
$(srcdir)/Weather.cpp \
$(srcdir)/Weather.h \
$(srcdir)/World.cpp \
$(srcdir)/World.h \
$(srcdir)/WorldLog.cpp \
$(srcdir)/WorldLog.h \
$(srcdir)/WorldSession.cpp \
$(srcdir)/WorldSession.h \
$(srcdir)/WorldSocket.cpp \
$(srcdir)/WorldSocket.h \
$(srcdir)/WorldSocketMgr.cpp \
$(srcdir)/WorldSocketMgr.h \
$(srcdir)/FollowerReference.cpp \
$(srcdir)/FollowerReference.h \
$(srcdir)/FollowerRefManager.h \
$(srcdir)/GroupReference.cpp \
$(srcdir)/GroupReference.h \
$(srcdir)/GroupRefManager.h

## Additional files to include when running 'make dist'
#  Nothing yet.
