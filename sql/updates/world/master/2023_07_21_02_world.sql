-- Finding the lost expedition Quest Alliance and Horde

-- Areatrigger

SET @ID := 24; 
SET @SPAWNID := 25; 

-- Create new serverside areatrigger for entering Exile's Reach Abandoned Camp for follower spawn
DELETE FROM `areatrigger` WHERE `SpawnId`=@SPAWNID;
INSERT INTO `areatrigger` (`SpawnId`,`AreaTriggerId`,`IsServerSide`,`MapId`,`PosX`,`PosY`,`PosZ`,`Orientation`,`PhaseUseFlags`,`PhaseId`,`PhaseGroup`,`Shape`,`ShapeData0`,`ShapeData1`,`ShapeData2`,`ShapeData3`,`ShapeData4`,`ShapeData5`,`ShapeData6`,`ShapeData7`,`ScriptName`,`Comment`) VALUES
(@SPAWNID,@ID,1,2175,-299,-2500,20,0,0,0,0,1,2,50,30,2,50,30,0,0,'areatrigger_find_the_lost_expedition_follower','Exiles Reach - Lost Camp Missing follower check');
-- Add new serverside areatrigger for Exile's Reach Abandoned Camp to template
DELETE FROM `areatrigger_template` WHERE `Id`=@ID;
INSERT INTO `areatrigger_template` (`Id`,`IsServerSide`,`Type`,`Flags`,`Data0`,`Data1`,`Data2`,`Data3`,`Data4`,`Data5`,`Data6`,`Data7`,`VerifiedBuild`) VALUES
(@ID,1,1,0,2,50,30,2,50,30,0,0,0);

-- Misc

DELETE FROM `creature_equip_template` WHERE `CreatureID` IN (165359,166805);
INSERT INTO `creature_equip_template` (`CreatureID`,`ID`,`ItemID1`,`AppearanceModID1`,`ItemVisual1`,`ItemID2`,`AppearanceModID2`,`ItemVisual2`,`ItemID3`,`AppearanceModID3`,`ItemVisual3`,`VerifiedBuild`) VALUES
(165359,1,163887,0,0,163891,0,0,0,0,0,50000),
(166805,1,165616,0,0,0,0,0,0,0,0,50000);

DELETE FROM `creature_summoned_data` WHERE `CreatureID` IN (165359);
INSERT INTO `creature_summoned_data` (`CreatureID`,`CreatureIDVisibleToSummoner`,`GroundMountDisplayID`,`FlyingMountDisplayID`) VALUES
(165359,153168,NULL,NULL);

UPDATE `creature` SET `StringId`="alaria_camp" WHERE `guid`=1051209;
UPDATE `creature` SET `StringId`="wonza_camp" WHERE `guid`=1051211;

-- Scripting

UPDATE `creature_template` SET `ScriptName`="npc_kee_la_beach_standing" WHERE `entry` IN (151088);
UPDATE `creature_template` SET `ScriptName`="npc_bjorn_stouthands_beach_standing" WHERE `entry` IN (151089);
UPDATE `creature_template` SET `ScriptName`="npc_austin_huxworth_beach_standing" WHERE `entry` IN (154170);
UPDATE `creature_template` SET `ScriptName`="npc_garrick_summoned_beach" WHERE `entry` IN (165359);
UPDATE `creature_template` SET `ScriptName`="npc_grimaxe_summoned_beach" WHERE `entry` IN (166805);
UPDATE `areatrigger` SET `ScriptName`='areatrigger_find_the_lost_expedition' WHERE `SpawnId`=23;

DELETE FROM `spell_script_names` WHERE `spell_id` IN (305596,325076);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(305596,'spell_summon_survivor_beach'),
(325076,'spell_summon_survivor_beach');

-- Questing

DELETE FROM `creature_queststarter` WHERE `id`=156626 AND `quest` IN (54952);
DELETE FROM `creature_queststarter` WHERE `id`=166782 AND `quest` IN (59931);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(156626, 54952, 45745), -- Alliance
(166782, 59931, 46455); -- Horde

DELETE FROM `creature_questender` WHERE `id`=156607 AND `quest` IN (54952);
DELETE FROM `creature_questender` WHERE `id`=166854 AND `quest` IN (59931);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(156607, 54952, 45745), -- Alliance
(166854, 59931, 46455); -- Horde

DELETE FROM `quest_request_items` WHERE `ID`=59932;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(59932, 0, 0, 0, 0, 'Please... I be needin\'... food...', 50401); -- Cooking Meat

-- Pathing

-- Pathing for Kee-La 151088 "Finding the Lost Expedition"
SET @PATH := ((1052012 * 10) + 1) << 3;
DELETE FROM `waypoint_data` WHERE `id` IN (@PATH);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-425.92883,-2603.427,0.48476708,NULL,0,1,0,100,0),
(@PATH,2,-415.217,-2603.8403,0.7445327,NULL,0,1,0,100,0),
(@PATH,3,-404.86633,-2599.4375,1.6478806,NULL,0,1,0,100,0),
(@PATH,4,-395.08508,-2594.441,3.153698,NULL,0,1,0,100,0);

-- Pathing for Bjorn Stouthands 151089 "Finding the Lost Expedition"
SET @PATH := ((1052013 * 10) + 1) << 3;
DELETE FROM `waypoint_data` WHERE `id` IN (@PATH);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-398.3889,-2596.2883,2.3895378,NULL,0,1,0,100,0),
(@PATH,2,-391.7795,-2592.915,3.9566765,NULL,0,1,0,100,0);

-- Pathing for Austin Huxworth 154170 "Finding the Lost Expedition"
SET @PATH := ((1052014 * 10) + 1) << 3;
DELETE FROM `waypoint_data` WHERE `id` IN (@PATH);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-409.20898,-2599.4922,1.2894821,NULL,0,1,0,100,0),
(@PATH,2,-397.875,-2595.2622,2.6358757,NULL,0,1,0,100,0);

-- Pathing for Bo quest "Finding the Lost Expedition"
SET @PATH := ((1052021 * 10) + 1) << 3;
DELETE FROM `waypoint_data` WHERE `id` IN (@PATH);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-415.217,-2603.8403,0.7445327,NULL,0,1,0,100,0),
(@PATH,2,-404.86633,-2599.4375,1.6478806,NULL,0,1,0,100,0),
(@PATH,3,-395.08508,-2594.441,3.153698,NULL,0,1,0,100,0);

-- Pathing for Mithdran Dawntracker "Finding the Lost Expedition"
SET @PATH := ((1052022 * 10) + 1) << 3;
DELETE FROM `waypoint_data` WHERE `id` IN (@PATH);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-422.13196,-2598.1216,0.28313446,NULL,0,1,0,100,0),
(@PATH,2,-409.20898,-2599.4922,1.2894821,NULL,0,1,0,100,0),
(@PATH,3,-397.875,-2595.2622,2.6358757,NULL,0,1,0,100,0);

-- Pathing for Lana Jordan "Finding the Lost Expedition"
SET @PATH := ((1052023 * 10) + 1) << 3;
DELETE FROM `waypoint_data` WHERE `id` IN (@PATH);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-407.13715,-2599.2344,1.3998337,NULL,0,1,0,100,0),
(@PATH,2,-398.3889,-2596.2883,2.3895378,NULL,0,1,0,100,0),
(@PATH,3,-391.7795,-2592.915,3.9566765,NULL,0,1,0,100,0);

-- Cooking Meat Quest Alliance and Horde

-- Creature scripts

UPDATE `creature_template` SET `AIName`='', `ScriptName`="npc_captain_garrick_abandoned_camp" WHERE `entry` IN (156651);
UPDATE `creature_template` SET `AIName`='', `ScriptName`="npc_warlord_grimaxe_abandoned_camp" WHERE `entry` IN (166906);

UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` IN(175030, 175031);
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` IN(175030, 175031);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(175030, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 128, 14432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Won''sa - On respawn - Plays Anim with ID 14432 - Self'),
(175031, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 128, 14432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Alaria - On respawn - Plays Anim with ID 14432 - Self');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` IN(175030, 175031) AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, 175030, 0, 0, 57, 1, 0, 0, 0, 0, 'Object is personal object'),
(22, 1, 175031, 0, 0, 57, 1, 0, 0, 0, 0, 'Object is personal object');

-- Creature String Ids

UPDATE `creature` SET `StringId`="garrick_camp" WHERE `guid`=1051210;
UPDATE `creature` SET `StringId`="grimaxe_camp" WHERE `guid`=1051212;
UPDATE `creature` SET `StringId`="alaria_standing_abandoned_camp" WHERE `guid`=1051266;
UPDATE `creature` SET `StringId`="wonza_standing_abandoned_camp" WHERE `guid`=1051269;

-- Questing

DELETE FROM `creature_queststarter` WHERE `id`=156651 AND `quest` IN (55174);
DELETE FROM `creature_queststarter` WHERE `id`=166906 AND `quest` IN (59932);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(156651, 55174, 50000), -- Alliance
(166906, 59932, 50000); -- Horde

DELETE FROM `creature_questender` WHERE `id`=156607 AND `quest` IN (55174);
DELETE FROM `creature_questender` WHERE `id`=166854 AND `quest` IN (59932);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(156607, 55174, 50000), -- Alliance
(166854, 59932, 50000); -- Horde

DELETE FROM `quest_template_addon` WHERE `ID` IN (54952,59931);
INSERT INTO `quest_template_addon` (`ID`,`NextQuestID`,`ScriptName`) VALUES
(54952,55174,'quest_finding_the_lost_expedition_alliance'), -- Alliance
(59931,59932,'quest_finding_the_lost_expedition_horde'); -- Horde

DELETE FROM `quest_template_addon` WHERE `ID` IN (55174,59932);
INSERT INTO `quest_template_addon` (`ID`,`ScriptName`) VALUES
(55174,'quest_cooking_meat_alliance'), -- Alliance
(59932,'quest_cooking_meat_horde'); -- Horde

-- Conversations

DELETE FROM `conversation_actors` WHERE `ConversationId` IN (11696,12863,14439,14611);
INSERT INTO `conversation_actors` (`ConversationId`,`ConversationActorId`,`ConversationActorGuid`,`Idx`,`CreatureId`,`CreatureDisplayInfoId`,`NoActorObject`,`ActivePlayerObject`,`VerifiedBuild`) VALUES
(11696,71297,1051209,0,0,0,0,0,50000), -- Alliance
(11696,71309,1051210,1,0,0,0,0,50000), -- Alliance
(12863,71297,1051209,0,0,0,0,0,50000), -- Alliance
(12863,71309,1051210,1,0,0,0,0,50000), -- Alliance
(14439,76284,1051211,0,0,0,0,0,50000), -- Horde
(14439,75956,1051212,1,0,0,0,0,50000), -- Horde
(14611,76284,1051211,0,0,0,0,0,50000), -- Horde
(14611,75956,1051212,1,0,0,0,0,50000); -- Horde

UPDATE `conversation_actors` SET `ConversationActorGuid`=1051209 WHERE `ConversationId`=12058 AND `ConversationActorId`=71297; -- CONVERSATION_LINE_ESCORT_SURVIVOR_CAMP Alaria
UPDATE `conversation_actors` SET `ConversationActorGuid`=1051209 WHERE `ConversationId`=12058 AND `ConversationActorId`=76284; -- CONVERSATION_LINE_ESCORT_SURVIVOR_CAMP Wonza

DELETE FROM `conversation_line_template` WHERE `Id` IN (28241,28242,29333,31623,34646,36157,36158,36159,36595,36596);
INSERT INTO `conversation_line_template` (`Id`,`UiCameraID`,`ActorIdx`,`Flags`,`VerifiedBuild`) VALUES
(28241,0,0,0,50000), -- Alliance
(28242,0,1,0,50000), -- Alliance
(29333,0,1,0,50000), -- Alliance
(31623,0,0,0,50000), -- Alliance
(34646,0,1,0,50000), -- Alliance
(36157,0,0,0,50000), -- Horde
(36158,0,1,0,50000), -- Horde
(36159,0,1,0,50000), -- Horde
(36595,0,0,0,50000), -- Horde
(36596,0,1,0,50000); -- Horde

DELETE FROM `conversation_template` WHERE `Id` IN (11696,12863,14439,14611);
INSERT INTO `conversation_template` (`Id`,`FirstLineId`,`TextureKitId`,`ScriptName`,`VerifiedBuild`) VALUES
(11696,28241,0,'',50000), -- Alliance
(12863,31623,0,'',50000), -- Alliance
(14439,36157,0,'',50000), -- Horde
(14611,36595,0,'',50000); -- Horde
