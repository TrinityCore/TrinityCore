-- Add Name placeholder for phaseshift

DELETE FROM `trinity_string` WHERE `entry` = 179;
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES
(179, "PhaseShift:
* Flags %u, PersonalGuid: %s (%s)");



-- ------------------------- Variables

-- Currently requires:
-- https://github.com/TrinityCore/TrinityCore/pull/26178 - dynamic actors

SET @ATT_START := 3; -- Initial highest value of `Id` in `areatrigger_template`, + 1            SELECT max(Id)+1 FROM `areatrigger_template` WHERE IsServerSide=1;
SET @AT_START := 3; -- Initial highest value of `Id` in `areatrigger`, + 1                      SELECT max(SpawnId)+1 FROM `areatrigger` WHERE IsServerSide=1;
SET @WP_START := 9541002;  -- Initial highest value of `entry` in `Waypoints, + 1               SELECT max(entry)+1 FROM `waypoints`;

SET @CONVT_START := 1; -- `conversation_template`                                               ELECT max(Id)+1 FROM `conversation_template`;
SET @CONVAT_START := 1; -- `conversation_actor_template`                                        SELECT max(Id)+1 FROM `conversation_actor_template`;

SET @OGUID := 301852; --                                                                        SELECT max(guid)+1 FROM gameobject;
SET @CGUID := 459918; --                                                                        SELECT max(guid)+1 FROM creature;

SET @WFL := 7583; --                                                                            SELECT max(ID)+1 FROM world_safe_locs;

SET @INQ_ENTRY := 171789; -- High Inquisitor Whitemane
SET @GOSSIP := 26056; -- SELECT `gossip_menu_id` FROM `creature_template` WHERE `entry` = @INQ_ENTRY;
SET @QUEST := 60545; -- A chilling summon
SET @QUEST_OBJ_ONE := 406744; -- Learn about your leaders' fate
SET @QUEST_OBJ_TWO := 406745; -- Take the Death Gate to Acherus
SET @QUEST_OBJ_THREE := 405017; -- Take the teleporter to the Frozen Throne

SET @GATE_ENTRY := 171039;
SET @SPELL_TELEPORT_ACHERUS := 333607; -- [DNT] Teleport: Acherus
SET @GATE_SUMMON_SPELL := 333609;

SET @GATE_POS_X := -8483.441406;
SET @GATE_POS_Y := 384.078461;
SET @GATE_POS_Z := 115.857712;
SET @GATE_POS_O := 2.28637;

SET @DARION_SW_ENTRY := 176554; -- Darion at stormwind
SET @DARION_EBON_HOLD_ENTRY := 169070; -- Darion at icecrown citadel, after the 1st teleporter


SET @SCENE_CREDIT := 173227; -- [DNT] Credit: Abduction Scene

SET @SCENE_ONE := 2651;

SET @SPELL_SHADOW_TELEPORT := 333617;
SET @SPELL_TELEPORT_FROZEN_THRONE := 328796; -- ([DNT] Teleport: Frozen Throne)
SET @SPELL_TELEPORT_ICECROWN_LOWER := 332997; -- ([DNT] Teleport: Icecrown Lower)

-- @RESET_CONTROLLER 168670 "Reset Controller"
-- @ICC_EFFECT       116633 "Effect"
-- @ICC_EFFECT_2     116633 "

SET @RITUALIST      := 169093; -- Ebon Blade Ritualist

SET @GENN_ENTRY     := 169071; -- Genn Greymane
SET @TYRANDE_ENTRY  := 169072; -- Tyrande Whisperwind
SET @LTT_ENTRY      := 169073; -- Lor'themar Theron
SET @CALIA_ENTRY    := 169075; -- Calia Menethil
SET @BOLVAR_ENTRY   := 169076; -- highlord-bolvar-fordragon

SET @SHARD_OF_DOM_5 := 169095; -- Shard of Domination
SET @SHARD_OF_DOM_2 := 169098; -- Shard of Domination
SET @SHARD_OF_DOM_3 := 169100; -- Shard of Domination
SET @SHARD_OF_DOM   := 169101; -- Shard of Domination
SET @SHARD_OF_DOM_4 := 169109; -- Shard of Domination

SET @ROKHAN         := 170758; -- Rokhan <Darkspear Chieftain>
SET @ARC_THALYSSRA	:= 170759; -- First Arcanist Thalyssra
SET @TRADE_PRINCE   := 170760; -- Trade Prince Gazlowe
SET @GELBIN_MEKK    := 170761; -- Gelbin Mekkatorque <High Tinker, King of Gnomes>
SET @ALLERIA_WIND   := 170762; -- Alleria Windrunner
SET @MURADIN        := 170763; -- Muradin Bronzebeard


-- ------------------------- Part 0: Preperations

UPDATE `creature_template` SET `AIName` = "SmartAI" where `entry` IN (@DARION_SW_ENTRY, @DARION_EBON_HOLD_ENTRY);

-- Area Phase
DELETE FROM `phase_area` WHERE `AreaId` = 10355 AND `PhaseId` = 15699;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`) VALUES (10355, 15699);

-- ------------------------- Part 1: Summon personal spawns

-- Add areatrigger template (box definition)
DELETE FROM `areatrigger_template` WHERE `Id` = @ATT_START AND `IsServerSide` = 1;
INSERT INTO `areatrigger_template` (`Id`, `IsServerSide`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `ScriptName`, `VerifiedBuild`) VALUES
(@ATT_START, 1, 1, 0, 100, 100, 100, 0, 0, 0, 'SmartAreaTriggerAI', 0);

-- Add areatrigger (serverside, position)
DELETE FROM `areatrigger` WHERE `SpawnId` = @AT_START;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerId`, `IsServerSide`, `MapId`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `Comment`) VALUES
(@AT_START, @ATT_START, 1, 0,  -8490.584961, 393.610077, 115.806328, 2.16309632679, 1, 0, 0, 'Chilling Summon Quest - Personal Summon SW'); -- alliance

-- Smart scripts: summon personal spawns
DELETE FROM `smart_scripts` WHERE `entryorguid` = @AT_START AND `source_type` = 12;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@AT_START, 12, 0, 1, 46, 0, 100, 0, 0, 0, 0, 0, 0, 12, @INQ_ENTRY,       8, 0, 0, 3, 0, 8, 0, 0, 0, -8491.144531, 390.496735,  115.821030,  2.255547, "On areatriggerserver - summon high inquisitor, personal spawn"),
(@AT_START, 12, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 0, 12, @DARION_SW_ENTRY, 8, 0, 0, 3, 0, 8, 0, 0, 0, -8490.584961, 393.610077,  115.806328,  2.255547, "On link - summon darion, personal spawn");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceGroup` IN (1, 3) AND `SourceEntry` = @AT_START AND `SourceId` = 12;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22, 1, @AT_START, 12, 1, 47, 0, @QUEST,         10,   0, 0, 0, '', "Script 1: Allow smart script only if the player has the chillin summon quest as completed or in progress (not rewarded)"),
(22, 1, @AT_START, 12, 1, 29, 0, @INQ_ENTRY,     110, 0, 1, 0, '', "Script 1: AND summon once - we are not near high inquistor Whitemane. We use distance higher than areatrigger to make sure we only trigger this once");

-- Waypoints: walking to gate
DELETE FROM `waypoints` WHERE `entry` = @WP_START+0;
INSERT INTO `waypoints` (`entry`, `pointId`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(@WP_START+0, 1, -8485.73, 386.469, 115.89768, 'SL Darion Stormwind');

-- -------------- Smart scripts: Talk when quest is given to player
DELETE FROM `smart_scripts` WHERE `entryorguid` = @QUEST AND `source_type` = 5;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@QUEST, 5, 0, 1, 47, 0, 100, 0, 0, 0, 0, 0, 0, 143, @CONVT_START+0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On quest pushed - start talking");

DELETE FROM `quest_template_addon` WHERE `ID` = @QUEST;
INSERT INTO `quest_template_addon` (`ID`, `ScriptName`) VALUES (@QUEST, 'SmartQuest');

-- Smart scripts: Talk when player is near (40 yards)
DELETE FROM `smart_scripts` WHERE `entryorguid` = @DARION_SW_ENTRY AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@DARION_SW_ENTRY, 0, 0, 3, 10, 0, 100, 1, 1, 40, 0, 0, 1,  143, @CONVT_START+1,           1, 0, 0, 0, 0,  7 /* invoker */, 0, 0, 0, 0, 0, 0, 0, "On near darion - start talking"),
(@DARION_SW_ENTRY, 0, 1, 3, 10, 0, 100, 1, 1, 40, 0, 0, 1,   53,              0, @WP_START+0, 0, 0, 0, 0,  1 /* self */, 0, 0, 1, 0, 0, 0, 0, "On near darion - make darion waypoint"), -- also start waypoint IF objective 1 is already complete
(@DARION_SW_ENTRY, 0, 2, 3, 58, 0, 100, 0, 0, @WP_START+0, 0, 0, 0, 11, @GATE_SUMMON_SPELL, 3, 0x0007FFFF, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, "On waypoint reached - Summon the gate, personal spawn");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceGroup` = 2 AND `SourceEntry` = @DARION_SW_ENTRY AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22, 2, @DARION_SW_ENTRY, 0, 1, 48, 0, @QUEST_OBJ_ONE, 0, 0, 0, 0, '', "Script 2: Only start waypoint if objective 1 is already complete");

-- Conversation 
DELETE FROM `conversation_template` WHERE `Id` IN (@CONVT_START+0,@CONVT_START+1);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `LastLineEndTime`, `TextureKitId`, `VerifiedBuild`) VALUES
(@CONVT_START+0, 40253, 17819, 0, 37474),
(@CONVT_START+1, 40277, 17628, 0, 37474);

DELETE FROM `conversation_line_template` WHERE `Id` IN (40253, 40254, 40277, 40278);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Flags`, `VerifiedBuild`) VALUES
(40253, 0,    82, 0, 0, 37474),
(40254, 6725, 82, 0, 0, 37474),
(40277, 0,    0,  0, 0, 37474),
(40278, 8343, 0,  0, 0, 37474);

DELETE FROM `conversation_actor_template` WHERE `Id` IN (@CONVAT_START+0);
INSERT INTO `conversation_actor_template` (`Id`, `CreatureId`, `CreatureModelId`, `VerifiedBuild`) VALUES
(@CONVAT_START+0, 165918, 27153, 0);

DELETE FROM `conversation_actors` WHERE `ConversationId` IN (@CONVT_START+0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `VerifiedBuild`) VALUES
(@CONVT_START+0, @CONVAT_START+0, 0, 0, 0);

-- ------------------------- Part 2: Allow player to interact and complete 1st objective

-- Allow interaction on high inquisitor
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = @INQ_ENTRY;

-- Gossip
DELETE FROM `gossip_menu` WHERE `MenuId` = @GOSSIP;
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES (@GOSSIP, 1, -1);

DELETE FROM `gossip_menu_option` WHERE `MenuId` = @GOSSIP;
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionText`, `OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES
(@GOSSIP, 0, "Tell me what happened.", 1, 1, -1);

-- conditions: only allow interaction if player has quest but didn't take
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = @GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference` ,`ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, @GOSSIP, 0, 0, 0, 47, 0, @QUEST        , 10, 0, 0, 0, '', "Script 1: Display gossip only if quest is taken");


-- SAI: Start scene on gossip option
DELETE FROM `smart_scripts` WHERE `entryorguid` = @INQ_ENTRY AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@INQ_ENTRY, 0, 0, 1, 62, 0, 100, 0, @GOSSIP, 0, 0, 0, 72,  0,             0, 0, 0, 0, 0, 7, 0, 0, 0,  0, 0, 0, 0, "On gossip action 0 from menu selected - None: Close gossip"),
(@INQ_ENTRY, 0, 1, 2, 61, 0, 100, 0, 0,       0, 0, 0, 129, @SCENE_ONE,    0, 0, 0, 0, 0, 7, 0, 0, 0,  0, 0, 0, 0, "On link - play scene"),
(@INQ_ENTRY, 0, 2, 3, 61, 0, 100, 0, 0,       0, 0, 0, 33,  @SCENE_CREDIT, 0, 0, 0, 0, 0, 7, 0, 0, 0,  0, 0, 0, 0, "On link - Loot recipient: Give kill credit [DNT] Credit: Abduction Scene");

-- SAI: On scene complete, make darion start waypoint
DELETE FROM `smart_scripts` WHERE `entryorguid` = @SCENE_ONE AND `source_type` = 10;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@SCENE_ONE, 10, 0, 1, 81, 0, 100, 0, 0, 0, 0, 0, 53, 0, @WP_START+0, 0, 0, 0, 0, 11, @DARION_SW_ENTRY, 40, 1, 0, 0, 0, 0, "On scene end - make darion waypoint");

-- ------------------------- Part 3: Gate
-- Allow interaction on gate creature
-- select npcflag from creature_template where `entry` IN (171039);
UPDATE `creature_template` SET `npcflag` = `npcflag` | 0x01000000 WHERE `entry` = @GATE_ENTRY;

-- add spell click for gate
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = @GATE_ENTRY;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES (@GATE_ENTRY, @SPELL_TELEPORT_ACHERUS, 3 ,0);

-- Gate teleport spell target position
DELETE FROM `spell_target_position` WHERE `id` = @SPELL_TELEPORT_ACHERUS;
INSERT INTO `spell_target_position` (`id`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`) VALUES
(@SPELL_TELEPORT_ACHERUS, 0, 2147, -642.88, 2208.25, 550.71); 


-- ------------------------- Part 4.b: Darion talk in The Ebon Hold (Personal Phase, 15699)

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+21;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, @RITUALIST, 2147, 10355, 10359, '0', 15699, 0, 0, 0, 521.4132080078125, -2142.526123046875, 840.94024658203125, 2.277762174606323242, 120, 0, 0, 7477, 1807, 0, 0, 0, 0, 37474) -- 169093 (Area: The Frozen Throne - Difficulty: 0) -- (Auras: 329476 - [DNT] Ritual Stance)
,(@CGUID+1, @BOLVAR_ENTRY, 2147, 10355, 10359, '0', 15699, 0, 0, 0, 500.711822509765625, -2127.21875, 840.9403076171875, 0.647212028503417968, 120, 0, 0, 4486200, 0, 0, 0, 0, 0, 37474) -- 169076 (Area: The Frozen Throne - Difficulty: 0) (Auras: 328827 - [DNT] Bolvar Stand) -- (Auras: 328827 - [DNT] Bolvar Stand)
,(@CGUID+2, @MURADIN, 2147, 10355, 10359, '0', 15699, 0, 0, 0, 513.11114501953125, -2120.697998046875, 840.94024658203125, 3.947999954223632812, 120, 0, 0, 747700, 1807, 0, 0, 0, 0, 37474) -- 170763 (Area: The Frozen Throne - Difficulty: 0)
,(@CGUID+3, @RITUALIST, 2147, 10355, 10359, '0', 15699, 0, 0, 0, 485.69964599609375, -2142.557373046875, 840.94024658203125, 0.758436858654022216, 120, 0, 0, 7477, 1807, 0, 0, 0, 0, 37474) -- 169093 (Area: The Frozen Throne - Difficulty: 0)
,(@CGUID+4, @LTT_ENTRY, 2147, 10355, 10359, '0', 15699, 0, 0, 0, 510.515625, -2126.47216796875, 840.94024658203125, 2.715476274490356445, 120, 0, 0, 3738500, 18070, 0, 0, 0, 0, 37474) -- 169073 (Area: The Frozen Throne - Difficulty: 0)
,(@CGUID+5, @ROKHAN, 2147, 10355, 10359, '0', 15699, 0, 0, 0, 512.47222900390625, -2129.229248046875, 840.94024658203125, 2.74652862548828125, 120, 0, 0, 2289500, 0, 0, 0, 0, 0, 37474) -- 170758 (Area: The Frozen Throne - Difficulty: 0)
,(@CGUID+6, @GENN_ENTRY, 2147, 10355, 10359, '0', 15699, 0, 0, 0, 507.85589599609375, -2119.361083984375, 840.9403076171875, 3.925928831100463867, 120, 0, 0, 3738500, 90350, 0, 0, 0, 0, 37474) -- Genn Greymane (Area: The Frozen Throne - Difficulty: 0)
,(@CGUID+7, @TRADE_PRINCE, 2147, 10355, 10359, '0', 15699, 0, 0, 0, 509.614593505859375, -2131.90625, 840.94024658203125, 1.969117283821105957, 120, 0, 0, 373850, 0, 0, 0, 0, 0, 37474) -- Trade Prince Gazlowe (Area: The Frozen Throne - Difficulty: 0)
,(@CGUID+8, @TYRANDE_ENTRY, 2147, 10355, 10359, '0', 15699, 0, 0, 0, 510.4288330078125, -2121.135498046875, 840.94024658203125, 3.416774988174438476, 120, 0, 0, 3738500, 1807, 0, 0, 0, 0, 37474) -- 169072 (Area: The Frozen Throne - Difficulty: 0) -- (Auras: 329026 - [DNT] Maw Dissolve)
,(@CGUID+9, @CALIA_ENTRY, 2147, 10355, 10359, '0', 15699, 0, 0, 0, 509.138885498046875, -2128.366455078125, 840.94024658203125, 2.512369155883789062, 120, 0, 0, 598200, 4393, 0, 0, 0, 0, 37474) -- Calia Menethil (Area: The Frozen Throne - Difficulty: 0)
,(@CGUID+10, @ARC_THALYSSRA, 2147, 10355, 10359, '0', 15699, 0, 0, 0, 514.41668701171875, -2126.5869140625, 840.94024658203125, 2.824522972106933593, 120, 0, 0, 373850, 1807, 0, 0, 0, 0, 37474) -- 170759 (Area: The Frozen Throne - Difficulty: 0)
,(@CGUID+11, @SHARD_OF_DOM, 2147, 10355, 10359, '0', 15699, 0, 0, 0, 505.279510498046875, -2123.951416015625, 843.758544921875, 5.532551288604736328, 120, 0, 0, 7477, 0, 0, 0, 0, 0, 37474) -- 169101 (Area: The Frozen Throne - Difficulty: 0) (Auras: 328877 - [DNT] Shard of Domination 04) -- (Auras: 328877 - [DNT] Shard of Domination 04)
,(@CGUID+12, @RITUALIST, 2147, 10355, 10359, '0', 15699, 0, 0, 0, 485.9288330078125, -2107.092041015625, 840.94024658203125, 5.513477325439453125, 120, 0, 0, 7477, 1807, 0, 0, 0, 0, 37474) -- 169093 (Area: The Frozen Throne - Difficulty: 0) -- (Auras: 329476 - [DNT] Ritual Stance)
,(@CGUID+13, @DARION_EBON_HOLD_ENTRY, 2147, 10355, 10359, '0', 15699, 0, 0, 0, 529.71875, -2119.82470703125, 840.94024658203125, 3.1006927490234375, 120, 0, 0, 186925, 45175, 0, 0, 0, 0, 37474) -- Highlord Darion Mograine (Area: The Frozen Throne - Difficulty: 0) -- (Auras: 329026 - [DNT] Maw Dissolve)
,(@CGUID+14, @SHARD_OF_DOM_2, 2147, 10355, 10359, '0', 15699, 0, 0, 0, 504.092010498046875, -2125.015625, 843.06640625, 0.042546126991510391, 120, 0, 0, 7477, 0, 0, 0, 0, 0, 37474) -- 169098 (Area: The Frozen Throne - Difficulty: 0) (Auras: 328874 - [DNT] Shard of Domination 02)
,(@CGUID+15, @GELBIN_MEKK, 2147, 10355, 10359, '0', 15699, 0, 0, 0, 507.35589599609375, -2116.201416015625, 840.9403076171875, 3.971146106719970703, 120, 0, 0, 3738500, 0, 0, 0, 0, 0, 37474) -- 170761 (Area: The Frozen Throne - Difficulty: 0)
,(@CGUID+16, @ALLERIA_WIND, 2147, 10355, 10359, '0', 15699, 0, 0, 0, 510.8125, -2118.217041015625, 840.94024658203125, 4.40771341323852539, 120, 0, 0, 747700, 1500, 0, 0, 0, 0, 37474) -- 170762 (Area: The Frozen Throne - Difficulty: 0)
,(@CGUID+17, @SHARD_OF_DOM_4, 2147, 10355, 10359, '0', 15699, 0, 0, 0, 504.5625, -2124.2587890625, 843.166259765625, 0, 120, 0, 0, 7477, 0, 0, 0, 0, 0, 37474) -- 169109 (Area: The Frozen Throne - Difficulty: 0) (Auras: 328892 - [DNT] Shard of Domination Main) 
,(@CGUID+18, @RITUALIST, 2147, 10355, 10359, '0', 15699, 0, 0, 0, 521.4757080078125, -2106.760498046875, 840.94024658203125, 3.89200139045715332, 120, 0, 0, 7477, 1807, 0, 0, 0, 0, 37474) -- 169093 (Area: The Frozen Throne - Difficulty: 0) --  (Auras: 329476 - [DNT] Ritual Stance)
,(@CGUID+19, @SHARD_OF_DOM_5, 2147, 10355, 10359, '0', 15699, 0, 0, 0, 505.0694580078125, -2124.65625, 842.34271240234375, 0.042546126991510391, 120, 0, 0, 7477, 0, 0, 0, 0, 0, 37474) -- 169095 (Area: The Frozen Throne - Difficulty: 0) (Auras: 328866 - [DNT] Shard of Domination 01)
,(@CGUID+20, @SHARD_OF_DOM_3, 2147, 10355, 10359, '0', 15699, 0, 0, 0, 504.348968505859375, -2124.229248046875, 844.4725341796875, 0.042546126991510391, 120, 0, 0, 7477, 0, 0, 0, 0, 0, 37474) -- 169100 (Area: The Frozen Throne - Difficulty: 0) (Auras: 328876 - [DNT] Shard of Domination 03)
,(@CGUID+21, 168670, 2147, 10355, 10359, '0', 15699, 0, 0, 0, 529.7100830078125, -2124.560791015625, 840.94024658203125, 0, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 37474) -- 168670 (Area: The Frozen Throne - Difficulty: 0) (Auras: 328164 - [DNT] Reset Ping Aura)
;





-- ,(@CGUID+21, @ICC_EFFECT, 2147, 10355, 10359, '0', 15699, 0, 0, 0, 488.223968505859375, -2109.45654296875, 840.94024658203125, 5.489903926849365234, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 37474) -- 116633 (Area: The Frozen Throne - Difficulty: 0)
-- ,(@CGUID+23, @ICC_EFFECT, 2147, 10355, 10359, '0', 15699, 0, 0, 0, 504.635406494140625, -2124.26904296875, 840.9403076171875, 0, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 37474) -- 116633 (Area: The Frozen Throne - Difficulty: 0) (Auras: 328888 - [DNT] Shard Base FX)
-- ,(@CGUID+24, @ICC_EFFECT, 2147, 10355, 10359, '0', 15699, 0, 0, 0, 518.90277099609375, -2109.135498046875, 840.94024658203125, 3.958663702011108398, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 37474) -- 116633 (Area: The Frozen Throne - Difficulty: 0) (Auras: )
-- ,(@CGUID+25, @ICC_EFFECT, 2147, 10355, 10359, '0', 15699, 0, 0, 0, 488.453125, -2139.979248046875, 840.94024658203125, 0.77697831392288208, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 37474) -- 116633 (Area: The Frozen Throne - Difficulty: 0)
-- ,(@CGUID+26, @ICC_EFFECT, 2147, 10355, 10359, '0', 15699, 0, 0, 0, 519.01739501953125, -2139.838623046875, 840.94024658203125, 2.353929758071899414, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 37474) -- 116633 (Area: The Frozen Throne - Difficulty: 0) (Auras: )

-- Phases: '15748 - 15699 - 15743 - 15746 - 15747'

-- ------------------------- Part 4: Darion talk in The Ebon Hold



/*
-- Summon darion as pesronal spawn when near the ebon hold
-- add areatrigger definition
DELETE FROM `areatrigger_template` WHERE `Id` = @ATT_START+1 AND `IsServerSide` = 1;
INSERT INTO `areatrigger_template` (`Id`, `IsServerSide`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `ScriptName`, `VerifiedBuild`) VALUES
(@ATT_START+1, 1, 1, 0, 20, 20, 20, 0, 0, 0, 'SmartAreaTriggerAI', 0);
-- Add areatrigger (serverside, position)
DELETE FROM `areatrigger` WHERE `SpawnId` = @AT_START+1;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerId`, `IsServerSide`, `MapId`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `Comment`) VALUES
(@AT_START+1, @ATT_START+1, 1, 2147, -642.88, 2208.25, 550.71, 0, 1, 0, 0, 'Chilling Summon Quest - Personal Summon Darion - Ebon Hold');
-- Waypoitns for darion to walk
DELETE FROM `waypoints` WHERE `entry` in (@WP_START+1, @WP_START+2, @WP_START+3);
INSERT INTO `waypoints` (`entry`, `pointId`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(@WP_START+1, 1, -637.0997, 2206.1636, 550.77936, 'SL Ebon Hold #1-1'),
(@WP_START+1, 2, -628.3497, 2206.6636, 550.77936, 'SL Ebon Hold #1-2'),
(@WP_START+1, 3, -625.5997, 2206.6636, 550.77936, 'SL Ebon Hold #1-3'),
(@WP_START+1, 4, -603.5170, 2207.7400, 550.67940, 'SL Ebon Hold #1-4'),
(@WP_START+2, 1, -599.09186, 2208.0654, 550.8266, 'SL Ebon Hold #2-1'),
(@WP_START+2, 2, -598.84186, 2208.0654, 550.8266, 'SL Ebon Hold #2-2'),
(@WP_START+2, 3, -598.09186, 2208.3154, 551.0766, 'SL Ebon Hold #2-3'),
(@WP_START+2, 4, -595.84186, 2208.3154, 550.0766, 'SL Ebon Hold #2-4'),
(@WP_START+2, 5, -592.59186, 2208.3154, 549.3266, 'SL Ebon Hold #2-5'),
(@WP_START+2, 6, -588.34186, 2208.5654, 547.8266, 'SL Ebon Hold #2-6'),
(@WP_START+2, 7, -587.34186, 2208.5654, 547.5766, 'SL Ebon Hold #2-7'),
(@WP_START+2, 8, -583.34186, 2208.5654, 546.5766, 'SL Ebon Hold #2-8'),
(@WP_START+2, 9, -582.84186, 2208.5654, 546.3266, 'SL Ebon Hold #2-9'),
(@WP_START+2, 10, -578.34186, 2208.8154, 544.8266, 'SL Ebon Hold #2-10'),
(@WP_START+2, 11, -576.84186, 2208.8154, 544.5766, 'SL Ebon Hold #2-11'),
(@WP_START+2, 12, -575.09186, 2208.8154, 543.8266, 'SL Ebon Hold #2-12'),
(@WP_START+2, 13, -574.34186, 2208.8154, 543.8266, 'SL Ebon Hold #2-13'),
(@WP_START+2, 14, -574.09186, 2208.8154, 543.5766, 'SL Ebon Hold #2-14'),
(@WP_START+2, 15, -571.59186, 2209.0654, 542.8266, 'SL Ebon Hold #2-15'),
(@WP_START+2, 16, -568.34186, 2209.0654, 541.8266, 'SL Ebon Hold #2-16'),
(@WP_START+2, 17, -567.84186, 2209.0654, 541.8266, 'SL Ebon Hold #2-17'),
(@WP_START+2, 18, -565.59186, 2209.3154, 540.8266, 'SL Ebon Hold #2-18'),
(@WP_START+2, 19, -565.09186, 2209.3154, 540.5766, 'SL Ebon Hold #2-19'),
(@WP_START+2, 20, -562.16670, 2209.3906, 539.4738, 'SL Ebon Hold #2-20'),
(@WP_START+3, 1, -562.16670, 2209.5212, 540.54694, 'SL Ebon Hold #3-1'),
(@WP_START+3, 2, -561.8701, 2209.5212, 539.79694, 'SL Ebon Hold #3-2'),
(@WP_START+3, 3, -560.3701, 2209.7712, 539.79694, 'SL Ebon Hold #3-3'),
(@WP_START+3, 4, -559.8701, 2210.0212, 540.04694, 'SL Ebon Hold #3-4'),
(@WP_START+3, 5, -559.6201, 2210.0212, 539.79694, 'SL Ebon Hold #3-5'),
(@WP_START+3, 6, -558.6201, 2210.0212, 539.79694, 'SL Ebon Hold #3-6'),
(@WP_START+3, 7, -557.3701, 2210.2712, 539.79694, 'SL Ebon Hold #3-7'),
(@WP_START+3, 8, -549.5226, 2211.2935, 539.49854, 'SL Ebon Hold #3-8');
-- Smart scripts: summon personal spawns
DELETE FROM `smart_scripts` WHERE `entryorguid` = @AT_START+1 AND `source_type` = 12;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@AT_START+1, 12, 0, 1, 46, 0, 100, 0, 0, 0, 0, 0, 0, 12, @DARION_EBON_HOLD_ENTRY, 8, 0, 0, 3, 0, 8, 0, 0, 0, -642.6823, 2205.587, 550.87933, 6.180687427520751953, "On areatriggerserver - summondarion, personal spawn");
-- Smart scripts: On darion spawn
DELETE FROM `smart_scripts` WHERE `entryorguid` = @DARION_EBON_HOLD_ENTRY AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@DARION_EBON_HOLD_ENTRY, 0, 0, 1, 11, 0, 100, 0, 1, 2147, 0, 0, 0, 11,  @SPELL_SHADOW_TELEPORT, 2,           0xFFFFFFFF, 0,      0, 0,  1, 0, 0, 0, 0, 0, 0, 0, "On respawn - cast shadow teleport"),
(@DARION_EBON_HOLD_ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0,    0, 0, 0, 53,  0,                      @WP_START+1, 0,          @QUEST, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, "On link - start waypoint"),
(@DARION_EBON_HOLD_ENTRY, 0, 2, 7, 61, 0, 100, 0, 0, 0,    0, 0, 0, 143, @CONVT_START+2,         1,           0,          0,      0, 0, 23, 0, 0, 0, 0, 0, 0, 0, "On link - start talking"),
(@DARION_EBON_HOLD_ENTRY, 0, 3, 7, 58, 0, 100, 0, 0, @WP_START+1, 0, 0, 0, 53, 0, @WP_START+2, 0, @QUEST, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On waypoint #1 end reached - start waypoint #2"), -- todo: start waypoint #2 on conversation ended instead
(@DARION_EBON_HOLD_ENTRY, 0, 4, 7, 58, 0, 100, 0, 0, @WP_START+2, 0, 0, 0, 53, 0, @WP_START+3, 0, @QUEST, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On waypoint #2 end reached - start waypoint #3"),
(@DARION_EBON_HOLD_ENTRY, 0, 5, 6, 58, 0, 100, 0, 0, @WP_START+3, 0, 0, 0, 11, @SPELL_SHADOW_TELEPORT, 2, 0xFFFFFFFF, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On waypoint #3 end reached - cast shadow teleport"),*/
-- (@DARION_EBON_HOLD_ENTRY, 0, 6, 7, 61 /* link */, 0, 100, 0, 0, 0, 0, 0, 0, 41 /* despawn */, 0, 0, 0, 0, 0, 0, 1 /* target: self */, 0, 0, 0, 0, 0, 0, 0, "On link -- despawn");

-- Conditions: only summon personal spawn if not summoned already
/*
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceGroup` IN (1, 3) AND `SourceEntry` = @AT_START+1 AND `SourceId` = 12;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22, 1, @AT_START+1, 12, 1, 29, 0, @DARION_EBON_HOLD_ENTRY, 110, 0, 1, 0, '', "Script 1: AND summon once - we are not near darion. We use distance higher than areatrigger to make sure we only trigger this once");
-- Conversation
DELETE FROM `conversation_template` WHERE `Id` IN (@CONVT_START+2);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `LastLineEndTime`, `TextureKitId`, `VerifiedBuild`) VALUES
(@CONVT_START+2, 37489, 39617, 0, 37474);
DELETE FROM `conversation_line_template` WHERE `Id` IN (37489, 37490, 37491, 39251, 37492);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Flags`, `VerifiedBuild`) VALUES
(37489, 0, 0, 0, 0, 37474),
(37490, 11444, 0, 0, 0, 37474),
(37491, 18404, 0, 0, 0, 37474),
(39251, 27939, 0, 0, 0, 37474),
(37492, 33094, 0, 0, 0, 37474);
-- ------------------------- Part 5: Scourge Transporter - from Deathbringer's Rise to The Frozen Throne
-- Add areatrigger template (box definition)
DELETE FROM `areatrigger_template` WHERE `Id` = @ATT_START+2 AND `IsServerSide` = 1;
INSERT INTO `areatrigger_template` (`Id`, `IsServerSide`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `ScriptName`, `VerifiedBuild`) VALUES
(@ATT_START+2, 1, 1, 0, 3.6, 3.442, 2, 0, 0, 0, '', 0);
-- Add areatrigger (serverside, position)
DELETE FROM `areatrigger` WHERE `SpawnId` = @AT_START+2;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerId`, `IsServerSide`, `MapId`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `Comment`) VALUES
(@AT_START+2, @ATT_START+2, 1, 2147, -548.971923828125, 2211.219970703125, 539.2769775390625, 0, 1, 0, 0, 'Deathbringer\'s Rise - Teleport to The Frozen Throne');
-- Add area trigger action to cast the teleport spell
DELETE FROM areatrigger_template_actions WHERE `AreaTriggerId` = @AT_START+2 AND `IsServerSide` = 1;
INSERT INTO areatrigger_template_actions (`AreaTriggerId`, `IsServerSide`, `ActionType`, `ActionParam`, `TargetType`) VALUES
(@AT_START+2, 1, 0, @SPELL_TELEPORT_FROZEN_THRONE, 5);
-- Teleporter spell target position
DELETE FROM `spell_target_position` WHERE `id` = @SPELL_TELEPORT_FROZEN_THRONE;
INSERT INTO `spell_target_position` (`id`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`) VALUES
(@SPELL_TELEPORT_FROZEN_THRONE, 0, 2147, 559.020, -2124.869, 840.857); 
-- ------------------------- Part 6: Deathbringer's Rise fall-teleport area trigger
-- Add areatrigger template (box definition)
DELETE FROM `areatrigger_template` WHERE `Id` = @ATT_START+3 AND `IsServerSide` = 1;
INSERT INTO `areatrigger_template` (`Id`, `IsServerSide`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `ScriptName`, `VerifiedBuild`) VALUES
(@ATT_START+3, 1, 1, 0, 1000, 1000, 20, 0, 0, 0, 'SmartAreaTriggerAI', 0);
  
-- Add areatrigger (serverside, position)
DELETE FROM `areatrigger` WHERE `SpawnId` = @AT_START+3;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerId`, `IsServerSide`, `MapId`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `Comment`) VALUES
(@AT_START+3, @ATT_START+3, 1, 2147, -584.556702, 2211.174805, 516.24445, 0, 1, 0, 0, 'Deathbringer\'s Rise - Falling Teleporter'); -- alliance
 
-- Add area trigger action to cast the teleport spell
DELETE FROM areatrigger_template_actions WHERE `AreaTriggerId` = @AT_START+3 AND `IsServerSide` = 1;
INSERT INTO areatrigger_template_actions (`AreaTriggerId`, `IsServerSide`, `ActionType`, `ActionParam`, `TargetType`) VALUES
(@AT_START+3, 1, 0, @SPELL_TELEPORT_ACHERUS, 5);
-- ------------------------- Part 7: The Frozen Throne
-- Add areatrigger template (box definition)
DELETE FROM `areatrigger_template` WHERE `Id` IN (@ATT_START+4, @ATT_START+5) AND `IsServerSide` = 1;
INSERT INTO `areatrigger_template` (`Id`, `IsServerSide`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `ScriptName`, `VerifiedBuild`) VALUES
(@ATT_START+4, 1, 1, 0, 50, 50, 50, 0, 0, 0, 'SmartAreaTriggerAI', 0),
(@ATT_START+5, 1, 0, 0, 25, 25, 0,  0, 0, 0, 'SmartAreaTriggerAI', 0);
-- Add areatrigger (serverside, position)
DELETE FROM `areatrigger` WHERE `SpawnId` IN (@AT_START+4, @AT_START+5, @AT_START+6);
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerId`, `IsServerSide`, `MapId`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `Comment`) VALUES
(@AT_START+4, @ATT_START+3, 1, 2147, 506.200, -2123.782, 816.4809, 0, 1, 0, 0, 'SL The Frozen Throne - Falling Teleporter'),
(@AT_START+5, @ATT_START+4, 1, 2147, 559.020, -2124.869, 840.857, 0, 1, 0, 0, 'SL The Frozen Throne - Summon personal spawns');
-- TODO after we have the back-teleporter position (@AT_START+6, @ATT_START+2, 1, 2147, x, y, z, 0, 1, 0, 0, 'SL The Frozen Throne - Back Teleporter (to Deathbringer\'s rise)');
DELETE FROM `smart_scripts` WHERE `entryorguid` = @AT_START+5 AND `source_type` = 12;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@AT_START+5, 12, 0, 1, 46, 0, 100, 0, 0, 0, 0, 0, 12, @BOLVAR_ENTRY,  8, 0, 0, 3, 0, 8, 0, 0, 0, 500.71182, -2127.2188, 840.9403, 0.647, "On areatriggerserver - summon high inquisitor, personal spawn"),
(@AT_START+5, 12, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 12, @GENN_ENTRY,    8, 0, 0, 3, 0, 8, 0, 0, 0, 507.8559, -2119.361, 840.9403, 3.925928, "On link - summon Genn Greymane, personal spawn"),
(@AT_START+5, 12, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 12, @TYRANDE_ENTRY, 8, 0, 0, 3, 0, 8, 0, 0, 0, 510.42883, -2121.1355, 840.94025, 3.416774, "On link - summon Tyrande Whisperwind, personal spawn"),
(@AT_START+5, 12, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 12, @LTT_ENTRY,     8, 0, 0, 3, 0, 8, 0, 0, 0, 510.51562, -2126.4722, 840.94025, 2.71547, "On link - summon Lor'themar Theron, personal spawn"),
(@AT_START+5, 12, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 12, @CALIA_ENTRY,   8, 0, 0, 3, 0, 8, 0, 0, 0, 509.1389, -2128.3665, 840.94025, 2.512369, "On link - summon Calia Menethil, personal spawn");
-- Add area trigger action to cast the teleport spell
DELETE FROM areatrigger_template_actions WHERE `AreaTriggerId` IN (@AT_START+3, @AT_START+6) AND `IsServerSide` = 1;
INSERT INTO areatrigger_template_actions (`AreaTriggerId`, `IsServerSide`, `ActionType`, `ActionParam`, `TargetType`) VALUES
(@AT_START+4, 1, 0, @SPELL_TELEPORT_FROZEN_THRONE, 5), -- on falling - go to frozen throne
(@AT_START+6, 1, 0, @SPELL_TELEPORT_ICECROWN_LOWER, 5); -- on back teleporter
-- Teleporter spell target position
DELETE FROM `spell_target_position` WHERE `id` = @SPELL_TELEPORT_FROZEN_THRONE;
INSERT INTO `spell_target_position` (`id`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`) VALUES
(@SPELL_TELEPORT_ICECROWN_LOWER, 0, 2147, -555.72, 2211.21, 539.34); 
-- ------------------------- Part 8: The frozen throne - talk
UPDATE `creature_template` SET `AIName` = "SmartAI" where `entry` IN (@LTT_ENTRY);
-- Smart scripts: Talk when player is near LTT_ENTRY (25 yards)
DELETE FROM `smart_scripts` WHERE `entryorguid` = @LTT_ENTRY AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
*/ -- (@LTT_ENTRY, 0, 0, 1, 10, 0, 100, 1, 1, 25, 0, 0, 1, 143, @CONVT_START+3, 1 /*dynamic actor*/, 0, 0, 0, 0,  7, 0,                 0, 0, 0, 0, 0, 0, "On near darion - start talking"),

-- Conversation 198459 
/*
DELETE FROM `conversation_template` WHERE `Id` IN (@CONVT_START+2);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `LastLineEndTime`, `TextureKitId`, `VerifiedBuild`) VALUES
(@CONVT_START+3, 37351, 73480, 0, 37474);
DELETE FROM `conversation_line_template` WHERE `Id` IN (37351, 37352, 37507, 37353, 37354, 37516, 37355, 38344, 38345, 38346, 38347,
38348, 38349, 38350, 37508, 37356, 37357, 38351, 38352, 38353, 37509, 38354, 38355, 38356, 37510, 37511, 37512, 37358);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Flags`, `VerifiedBuild`) VALUES
(37351, 0, 0, 0, 0, 37474),		-- LTT
(37352, 10481, 0, 0, 0, 37474), -- LTT
(37507, 20074, 0, 1, 0, 37474), -- Whisperwind
(37353, 28571, 0, 1, 1, 37474), -- Whsperwind (empty text)
(37354, 28571, 0, 2, 1, 37474), -- Genn Greymane
(37516, 39843, 0, 0, 1, 37474), -- LTT (empty text)
(37355, 39843, 0, 3, 1, 37474),
(38344, 47108, 0, 0, 1, 37474),
(38345, 47108, 0, 4, 1, 37474),
(38346, 47108, 0, 5, 1, 37474),
(38347, 47108, 0, 6, 1, 37474),
(38348, 47108, 0, 2, 1, 37474),
(38349, 47108, 0, 7, 1, 37474),
(38350, 47108, 0, 8, 1, 37474),
(37508, 47108, 0, 9, 1, 37474),
(37356, 47108, 0, 1, 1, 37474),
(37357, 55711, 0, 10, 0, 37474),
(38351, 65221, 0, 0, 1, 37474),
(38352, 65221, 0, 4, 1, 37474),
(38353, 65221, 0, 6, 1, 37474),
(37509, 65221, 0, 5, 1, 37474),
(38354, 65221, 0, 2, 1, 37474),
(38355, 65221, 0, 7, 1, 37474),
(38356, 65221, 0, 8, 1, 37474),
(37510, 65221, 0, 9, 1, 37474),
(37511, 65221, 0, 3, 1, 37474),
(37512, 65221, 0, 1, 1, 37474),
(37358, 65221, 0, 10, 0, 37474);
DELETE FROM `conversation_actor_template` WHERE `Id` IN (@CONVAT_START+1);
INSERT INTO `conversation_actor_template` (`Id`, `CreatureId`, `CreatureModelId`, `VerifiedBuild`) VALUES
(@CONVAT_START+1, 165918, 27153, 0);
DELETE FROM `conversation_actors` WHERE `ConversationId` IN (@CONVT_START+4);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `VerifiedBuild`) VALUES
(@CONVT_START+4, @CONVAT_START+0, 0, 0, 0);
*/

/* Actors:
[0] = LTT
[1] = Tyrande
[2] = Genn Greymane
[3] = Calia Menethil
[4] = Darkspear Chieftain -- 170758
-[5] MoverGUID: Full: 0x2042810C60A6C1800032AE0000381BBE Creature/0 R4256/S12974 Map: 2147 Entry: 170758 Low: 3677118
-[5] Position: X: 512.4722 Y: -2129.2292 Z: 840.94025
-[5] Orientation: 2.74652862548828125
[5] = First Arcanist Thalyssra -- 170759
-[23] MoverGUID: Full: 0x2042810C60A6C1C00032AE0000381BBE Creature/0 R4256/S12974 Map: 2147 Entry: 170759 Low: 3677118
-[23] Position: X: 514.4167 Y: -2126.587 Z: 840.94025
-[23] Orientation: 2.824522972106933593
[6] = Trade Prince Gazlowe -- 170760
-[24] MoverGUID: Full: 0x2042810C60A6C2000032AE0000381BBD Creature/0 R4256/S12974 Map: 2147 Entry: 170760 Low: 3677117
-[24] Position: X: 509.6146 Y: -2131.9062 Z: 840.94025
-[24] Orientation: 1.969117283821105957
[7] = Gelbin Mekkatorque -- 170761
-[6] MoverGUID: Full: 0x2042810C60A6C2400032AE0000381BBE Creature/0 R4256/S12974 Map: 2147 Entry: 170761 Low: 3677118
-[6] Position: X: 507.3559 Y: -2116.2014 Z: 840.9403
-[6] Orientation: 3.971146106719970703
[8] = Alleria Windrunner -- 170762
-[24] MoverGUID: Full: 0x2042810C60A6C2800032AE0000381BBE Creature/0 R4256/S12974 Map: 2147 Entry: 170762 Low: 3677118
-[24] Position: X: 510.8125 Y: -2118.217 Z: 840.94025
-[24] Orientation: 4.40771341323852539
[9] = Muradin Bronzebeard -- 170763
-[7] MoverGUID: Full: 0x2042810C60A6C2C00032AE0000381BBE Creature/0 R4256/S12974 Map: 2147 Entry: 170763 Low: 3677118
-[7] Position: X: 513.11115 Y: -2120.698 Z: 840.94025
-[7] Orientation: 3.947999954223632812
[10] = BOLVAR_ENTRY
*/


-- Analysis:

/*
ServerToClient: SMSG_PHASE_SHIFT_CHANGE (0x2578) Length: 68 ConnIdx: 1 Time: 02/25/2021 23:50:43.469 Number: 12280
Client: Full: 0x083998000000000000000000068630B4 Player/0 R3686/S0 Map: Eastern Kingdoms Low: 109457588
PhaseShiftFlags: 144
PhaseShiftCount: 5
PersonalGUID: Full: 0x083998000000000000000000068630B4 Player/0 R3686/S0 Map: Eastern Kingdoms Low: 109457588
[0] PhaseFlags: 2
[0] Id: 15699
[1] PhaseFlags: 1
[1] Id: 15743
[2] PhaseFlags: 1
[2] Id: 15746
[3] PhaseFlags: 1
[3] Id: 15747
[4] PhaseFlags: 1
[4] Id: 15748
        PhasingHandler::InheritPhaseShift(summon, summoner);
		
ServerToClient: SMSG_MOVE_TELEPORT (0x2E04) Length: 31 ConnIdx: 1 Time: 02/25/2021 23:50:43.469 Number: 12284
.go xyz 559.83 -2124.31 840.86 2147
ServerToClient: SMSG_MOVE_TELEPORT (0x2E04) Length: 31 ConnIdx: 1 Time: 02/25/2021 23:50:49.375 Number: 12454
.go xyz -555.72 2211.21 539.34 2147
+		[114951]	(114951, {creatures={ size=20 } gameobjects={ size=0 } })	std::pair<unsigned int const ,CellObjectGuids>
+		[114439]	(114439, {creatures={ size=2 } gameobjects={ size=0 } })	std::pair<unsigned int const ,CellObjectGuids>
+		cellCoord	{x_coord=263 y_coord=224 }	CoordPair<512>
[2147, 15699] -> [114951]
cellCoord.GetId() == 114951
114944
Loading creature loot templates...
>> Loaded 328691 creature loot templates in 1464 ms
Loading Quest POI
>> Loaded 93326 quest POI definitions in 1750 ms
Table `quest_mail_sender` has data for quest 22817 but such quest does not exist
Table `quest_mail_sender` has data for quest 22818 but such quest does not exist
Table `quest_objectives` has data for quest 30238 but such quest does not exist
>> Loaded 37314 quests definitions in 3705 ms
Loading Gameobject Data...
>> Loaded 80036 gameobjects in 2047 ms
>> Loaded 153716 creature definitions in 6710 ms
>> Loaded 223922 creature template models in 1131 ms
Loading Items...
>> Loaded 125653 item templates in 14096 ms
>> Localization strings loaded in 21072 ms
>> Loaded 30207 Quest Template locale strings in 6649 ms
>> Loaded 25354 Quest Objectives locale strings in 1160 ms
>> Loaded 132195 creature locale strings in 11928 ms
Initialize query data... ??
*/