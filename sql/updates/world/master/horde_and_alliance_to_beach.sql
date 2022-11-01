-- Creature fixups
UPDATE `creature_template` SET `npcflag`=2 WHERE `entry`=166827;
UPDATE `creature` SET `equipment_id`=1 WHERE `guid`=1050189;
UPDATE `creature` SET `PhaseId`=15287 WHERE `id`=166827;
UPDATE `creature` SET `spawntimesecs`=120 WHERE `map`=2369 AND `spawntimesecs`=7200;
UPDATE `creature` SET `curhealth`=1 WHERE `map`=2369;

-- Scripting
SET @ENTRY := 166824;
SET @SCRIPT := @ENTRY * 100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SCRIPT AND `source_type`=9;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,80,@SCRIPT,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warlord Breka Grimaxe - Just Summoned - Load script"),
(@SCRIPT,9,0,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warlord Breka Grimaxe - Script - Say 0"),
(@SCRIPT,9,1,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warlord Breka Grimaxe - Script - Set Run off"),
(@SCRIPT,9,2,0,0,0,100,0,0,0,0,0,69,0,1,0,0,0,0,8,0,0,0,-10.602051,8.918945,8.779607,0,"Warlord Breka Grimaxe - Script - Move to position"),
(@SCRIPT,9,3,0,0,0,100,0,3000,3000,0,0,5,66,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warlord Breka Grimaxe - Script - Emote Salute"),
(@SCRIPT,9,4,0,0,0,100,0,3000,3000,0,0,53,1,@SCRIPT,0,0,0,0,1,0,0,0,0,0,0,0,"Warlord Breka Grimaxe - Script - Load path");

DELETE FROM `creature_text` WHERE `CreatureID`=@ENTRY;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ENTRY, 0, 0, 'Throg will spar with you for now. I must speak to the crew about the rain.', 12, 0, 100, 0, 0, 156952, 199040, 0, 'Warlord Breka Grimaxe');

DELETE FROM `waypoints` WHERE `entry`=@SCRIPT;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`point_comment`) VALUES
(@SCRIPT,1,2.480713,9.498291,9.528435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,2,3.480713,9.748291,9.778435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,3,3.730713,9.998291,10.028435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,4,5.230713,12.248291,10.778435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,5,6.730713,11.748291,12.278435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,6,9.230713,10.748291,14.778435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,7,12.480713,9.498291,17.778435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,8,13.730713,9.498291,18.528435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,9,14.480713,9.248291,18.778435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,10,15.480713,8.998291,18.778435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,11,15.480713,6.748291,18.778435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,12,15.730713,5.748291,18.778435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,13,15.230713,5.498291,18.778435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,14,15.230713,5.248291,18.778435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,15,15.980713,4.248291,19.528435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,16,18.480713,3.248291,22.028435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,17,23.480713,2.248291,26.278435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,18,24.480713,0.24829102,26.528435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,19,25.730713,-1.751709,27.278435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,20,28.730713,-6.001709,27.278435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,21,29.730713,-5.751709,27.528435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,22,32.730713,-7.501709,30.278435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,23,35.480713,-6.751709,33.528435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,24,35.980713,-6.501709,33.778435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,25,38.730713,-5.501709,34.528435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,26,39.980713,-5.001709,35.028435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,27,40.980713,-4.751709,36.028435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,28,44.480713,-4.001709,39.778435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,29,45.563477,-3.4223633,39.777264,3.1642,0,'Warlord Breka Grimaxe'),
(@SCRIPT,30,45.563477,-3.4223633,39.777264,NULL,0,'Warlord Breka Grimaxe');

-- Spawn Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=32 AND `SourceGroup`=5 AND `SourceEntry`=166824 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(32,5,166824,0,0,47,0,59926,64,0,0,0,0,'','Spawn of creature with entry 166824 requires Quest 59926 rewarded');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=32 AND `SourceGroup`=5 AND `SourceEntry`=166573 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(32,5,166573,0,0,47,0,59926,11,0,0,0,0,'','Spawn of creature with entry 166573 requires Quest 59926 not rewarded');

-- Spell
DELETE FROM `spell_script_names` WHERE `spell_id`=325108;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(325108,'spell_summon_throg_combat_training');

DELETE FROM `spell_script_names` WHERE `spell_id`=305425;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(305425,'spell_alliance_spell_ship_crash_teleport');

DELETE FROM `spell_script_names` WHERE `spell_id`=325131;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(325131,'spell_horde_spell_ship_crash_teleport');

DELETE FROM `spell_target_position` WHERE `ID`=325131;
INSERT INTO `spell_target_position` (`ID`,`EffectIndex`,`MapID`,`PositionX`,`PositionY`,`PositionZ`,`VerifiedBuild`) VALUES
(325131,3,2175,-462.4,-2619.8,0.4,45745);

DELETE FROM `spell_target_position` WHERE `ID`=305425;
INSERT INTO `spell_target_position` (`ID`,`EffectIndex`,`MapID`,`PositionX`,`PositionY`,`PositionZ`,`VerifiedBuild`) VALUES
(305425,4,2175,-462.4,-2619.8,0.4,45745);

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=-305445;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(-305445,344889,0,'Knocked Down (DNT) removal triggers Knocked Down (DNT)');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=-290901;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(-290901,290903,0,'Removing aura Attention! cast DEBUG - Look Right');

DELETE FROM `spell_area` WHERE `spell`=346797;
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_end`,`aura_spell`,`racemask`,`gender`,`flags`,`quest_start_status`,`quest_end_status`) VALUES
(346797,10453,58208,0,305425,0,2,1,64,0);

DELETE FROM `spell_area` WHERE `spell`=346799;
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_end`,`aura_spell`,`racemask`,`gender`,`flags`,`quest_start_status`,`quest_end_status`) VALUES
(346799,10453,59928,0,325131,0,2,1,64,0);

-- Scenes
UPDATE `scene_template` SET `ScriptName`='scene_alliance_and_horde_ship' WHERE `SceneId`=2486;

DELETE FROM `scene_template` WHERE `SceneId`=2487;
INSERT INTO `scene_template` (`SceneId`,`Flags`,`ScriptPackageID`,`Encrypted`,`ScriptName`) VALUES
(2487,16,2708,0,'scene_alliance_and_horde_crash');

DELETE FROM `scene_template` WHERE `SceneId`=2334;
INSERT INTO `scene_template` (`SceneId`,`Flags`,`ScriptPackageID`,`Encrypted`,`ScriptName`) VALUES
(2334,16,2708,0,'scene_alliance_and_horde_crash');

-- Conversationa
DELETE FROM `conversation_actors` WHERE `ConversationId`=10768;
INSERT INTO `conversation_actors` (`ConversationId`,`ConversationActorId`,`ConversationActorGuid`,`Idx`,`CreatureId`,`CreatureDisplayInfoId`,`NoActorObject`,`ActivePlayerObject`,`VerifiedBuild`) VALUES
(10768,73720,1050145,0,156280,92690,0,0,45745),
(10768,75916,1050189,1,166573,91669,0,0,45745);

DELETE FROM `conversation_line_template` WHERE `Id`=35650;
INSERT INTO `conversation_line_template` (`Id`,`UiCameraID`,`ActorIdx`,`Flags`,`VerifiedBuild`) VALUES 
(35650,0,1,0,45745);

DELETE FROM `conversation_template` WHERE `Id`=10768 AND `FirstLineId`=35650;
INSERT INTO `conversation_template` (`Id`,`FirstLineId`,`TextureKitId`,`ScriptName`,`VerifiedBuild`) VALUES
(10768,35650,0,'',45745);

DELETE FROM `conversation_actors` WHERE `ConversationId`=12818;
INSERT INTO `conversation_actors` (`ConversationId`,`ConversationActorId`,`ConversationActorGuid`,`Idx`,`CreatureId`,`CreatureDisplayInfoId`,`NoActorObject`,`ActivePlayerObject`,`VerifiedBuild`) VALUES
(12818,73720,1050145,0,156280,92690,0,0,45745),
(12818,75916,1050189,1,166573,91669,0,0,45745);

DELETE FROM `conversation_line_template` WHERE `Id`=36093;
INSERT INTO `conversation_line_template` (`Id`,`UiCameraID`,`ActorIdx`,`Flags`,`VerifiedBuild`) VALUES 
(36093,0,1,0,45745);

DELETE FROM `conversation_template` WHERE `Id`=12818;
INSERT INTO `conversation_template` (`Id`,`FirstLineId`,`TextureKitId`,`ScriptName`,`VerifiedBuild`) VALUES
(12818,36093,0,'',45745);

DELETE FROM `conversation_actors` WHERE `ConversationId`=12798;
INSERT INTO `conversation_actors` (`ConversationId`,`ConversationActorId`,`ConversationActorGuid`,`Idx`,`CreatureId`,`CreatureDisplayInfoId`,`NoActorObject`,`ActivePlayerObject`,`VerifiedBuild`) VALUES
(12798,73720,1050145,0,156280,92690,0,0,45745),
(12798,75916,1050189,1,166573,91669,0,0,45745);

DELETE FROM `conversation_line_template` WHERE `Id`=36096;
INSERT INTO `conversation_line_template` (`Id`,`UiCameraID`,`ActorIdx`,`Flags`,`VerifiedBuild`) VALUES 
(36096,0,1,0,45745);

DELETE FROM `conversation_template` WHERE `Id`=12798;
INSERT INTO `conversation_template` (`Id`,`FirstLineId`,`TextureKitId`,`ScriptName`,`VerifiedBuild`) VALUES
(12798,36096,0,'',45745);

-- quest
DELETE FROM `quest_template_addon` WHERE `ID`=59926;
INSERT INTO `quest_template_addon` (`ID`,`ScriptName`) VALUES
(59926,'quest_warming_up');

-- Summon data
DELETE FROM `creature_summoned_data` WHERE `CreatureID`=166814;
INSERT INTO `creature_summoned_data` (`CreatureID`,`CreatureIDVisibleToSummoner`,`GroundMountDisplayID`,`FlyingMountDisplayID`) VALUES
(166814,166815,NULL,NULL);

-- Creature script
UPDATE `creature_template` SET `ScriptName`='npc_horde_sparring_partner' WHERE `entry`=166814;

SET @ENTRY := 166814;
DELETE FROM `creature_text` WHERE `CreatureID`=@ENTRY;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ENTRY, 0, 0, 'I concede! Your strength will see our mission through.', 12, 0, 100, 4, 0, 156976, 195857, 0, 'Grunt Throg');

DELETE FROM `waypoint_data` WHERE `id`=10501870;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(10501870,1,-10.846191,11.937012,8.9623165,NULL,0,0,0,100,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=15284 AND `SourceEntry`=13377;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26,15284,13377,0,0,47,0,59927,67,0,0,0,0,'','Allow Phase 15284 if Quest 59927 in not taken, complete, or rewarded');

SET @PHASE := 15514;
SET @CGUID := XXXXX;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+10;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0,174971,2369,10424,13377,'0',@PHASE,0,-1,0,0,-17.644917,-6.061374,9.000128,0,120,0,0,1,0,0,0,0,0,45745), -- Spar Point Advertisement
(@CGUID+1,174971,2369,10424,13377,'0',@PHASE,0,-1,0,0,-16.248755,-2.245914,8.885136,0,120,0,0,1,0,0,0,0,0,45745), -- Spar Point Advertisement
(@CGUID+2,174971,2369,10424,13377,'0',@PHASE,0,-1,0,0,-4.609498,-7.722448,8.843941,0,120,0,0,1,0,0,0,0,0,45745), -- Spar Point Advertisement
(@CGUID+3,174971,2369,10424,13377,'0',@PHASE,0,-1,0,0,-17.633347,5.349984,8.993013,0,120,0,0,1,0,0,0,0,0,45745), -- Spar Point Advertisement
(@CGUID+4,174971,2369,10424,13377,'0',@PHASE,0,-1,0,0,-7.1927896,-1.4265188,9.105859,0,120,0,0,1,0,0,0,0,0,45745), -- Spar Point Advertisement
(@CGUID+5,174971,2369,10424,13377,'0',@PHASE,0,-1,0,0,-3.5559115,-6.8839636,8.878474,0,120,0,0,1,0,0,0,0,0,45745), -- Spar Point Advertisement
(@CGUID+6,174971,2369,10424,13377,'0',@PHASE,0,-1,0,0,-16.220743,-7.592815,8.926627,0,120,0,0,1,0,0,0,0,0,45745), -- Spar Point Advertisement
(@CGUID+7,174971,2369,10424,13377,'0',@PHASE,0,-1,0,0,-17.212137,0.9415215,8.992922,0,120,0,0,1,0,0,0,0,0,45745), -- Spar Point Advertisement
(@CGUID+8,174971,2369,10424,13377,'0',@PHASE,0,-1,0,0,-7.1881604,4.13693,8.805241,0,120,0,0,1,0,0,0,0,0,45745), -- Spar Point Advertisement
(@CGUID+9,174971,2369,10424,13377,'0',@PHASE,0,-1,0,0,-3.8145015,-9.154231,8.854396,0,120,0,0,1,0,0,0,0,0,45745), -- Spar Point Advertisement
(@CGUID+10,168039,2369,10424,13377,'0',@PHASE,0,-1,0,0,-10.630922,-11.896218,8.97435,1.7062142,120,0,0,1,0,0,0,0,0,45745); -- hBoat

UPDATE `creature_template` SET `flags_extra`=128 WHERE `entry` IN (174971,168039);

UPDATE `creature_template` SET `faction`=35,`unit_flags`=33554432,`unit_flags2`=2048,`unit_flags3`=524320 WHERE `entry`=166814;

-- Summon data
DELETE FROM `creature_summoned_data` WHERE `CreatureID`=166814;
INSERT INTO `creature_summoned_data` (`CreatureID`,`CreatureIDVisibleToSummoner`,`GroundMountDisplayID`,`FlyingMountDisplayID`) VALUES
(166814,166815,NULL,NULL);

UPDATE `creature_template` SET `ScriptName`='npc_horde_sparring_partner' WHERE `entry`=166814;
UPDATE `conversation_template` SET `ScriptName`='conversation_horde_sparing_partner' WHERE `Id` IN (14422,14423,14424);

DELETE FROM `conversation_actors` WHERE `ConversationId`=14422 AND `ConversationActorId`=75920;
INSERT INTO `conversation_actors` (`ConversationId`,`ConversationActorId`,`ConversationActorGuid`,`Idx`,`CreatureId`,`CreatureDisplayInfoId`,`NoActorObject`,`ActivePlayerObject`,`VerifiedBuild`) VALUES
(14422,75920,0,1,166815,91670,0,0,45745);

DELETE FROM `conversation_line_template` WHERE `Id`=36100;
INSERT INTO `conversation_line_template` (`Id`,`UiCameraID`,`ActorIdx`,`Flags`,`VerifiedBuild`) VALUES 
(36100,0,1,0,45745);

DELETE FROM `conversation_template` WHERE `Id`=14422 AND `FirstLineId`=36099;
INSERT INTO `conversation_template` (`Id`,`FirstLineId`,`TextureKitId`,`ScriptName`,`VerifiedBuild`) VALUES
(14422,36099,0,'',45745);

DELETE FROM `conversation_actors` WHERE `ConversationId`=14423 AND `ConversationActorId`=75920;
INSERT INTO `conversation_actors` (`ConversationId`,`ConversationActorId`,`ConversationActorGuid`,`Idx`,`CreatureId`,`CreatureDisplayInfoId`,`NoActorObject`,`ActivePlayerObject`,`VerifiedBuild`) VALUES
(14423,75920,0,1,166815,91670,0,0,45745);

DELETE FROM `conversation_line_template` WHERE `Id`=36102;
INSERT INTO `conversation_line_template` (`Id`,`UiCameraID`,`ActorIdx`,`Flags`,`VerifiedBuild`) VALUES 
(36102,0,1,0,45745);

DELETE FROM `conversation_template` WHERE `Id`=14423 AND `FirstLineId`=36101;
INSERT INTO `conversation_template` (`Id`,`FirstLineId`,`TextureKitId`,`ScriptName`,`VerifiedBuild`) VALUES
(14423,36101,0,'',45745);

DELETE FROM `conversation_actors` WHERE `ConversationId`=14424 AND `ConversationActorId`=75920;
INSERT INTO `conversation_actors` (`ConversationId`,`ConversationActorId`,`ConversationActorGuid`,`Idx`,`CreatureId`,`CreatureDisplayInfoId`,`NoActorObject`,`ActivePlayerObject`,`VerifiedBuild`) VALUES
(14424,75920,0,1,166815,91670,0,0,45745);

DELETE FROM `conversation_line_template` WHERE `Id`=36104;
INSERT INTO `conversation_line_template` (`Id`,`UiCameraID`,`ActorIdx`,`Flags`,`VerifiedBuild`) VALUES 
(36104,0,1,0,45745);

DELETE FROM `conversation_template` WHERE `Id`=14424 AND `FirstLineId`=36103;
INSERT INTO `conversation_template` (`Id`,`FirstLineId`,`TextureKitId`,`ScriptName`,`VerifiedBuild`) VALUES
(14424,36103,0,'',45745);
