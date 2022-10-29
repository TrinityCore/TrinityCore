-- Creature fixups
UPDATE `creature_template` SET `npcflag`=2 WHERE `entry`=166827;
UPDATE `creature` SET `equipment_id`=1 WHERE `guid`=1050189;
UPDATE `creature` SET `PhaseId`=15287 WHERE `id`=166827;
UPDATE `creature` SET `spawntimesecs`=120 WHERE `map`=2369 AND `spawntimesecs`=7200;
UPDATE `creature` SET `curhealth`=1 WHERE `map`=2369;

-- Spawn Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=32 AND `SourceGroup`=5 AND `SourceEntry`=166824 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(32,5,166824,0,0,47,0,59926,64,0,0,0,0,'','Spawn of creature with entry 166824 requires Quest 59926 rewarded');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=32 AND `SourceGroup`=5 AND `SourceEntry`=166573 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(32,5,166573,0,0,47,0,59926,11,0,0,0,0,'','Spawn of creature with entry 166573 requires Quest 59926 not rewarded');

-- Spell
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
