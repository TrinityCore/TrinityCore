-- Re-sizing the Situation

-- Set by TC Devs
-- One new creature spawn
SET @GUID := 8000040;

-- Add missing Re-sized Boar
DELETE FROM `creature` WHERE `guid`=@GUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `ScriptName`, `StringId`, `VerifiedBuild`) VALUES
(@GUID,156595,2175,10424,10588,'0',0,13775,0,-1,0,0,116.44965,-2430.3699,90.571266,0.8442242,7200,0,0,1,0,0,NULL,NULL,NULL,NULL,'',NULL,52649);

UPDATE `creature_template` SET `ScriptName`="npc_lindie_springstock_q56034" WHERE `entry`=156749;
UPDATE `creature_template` SET `ScriptName`="npc_cork_fizzlepop_q59941" WHERE `entry`=167915;
UPDATE `creature_template` SET `ScriptName`="npc_re_sized_boar_q56034" WHERE `entry`=156736;

-- Henry Garrick & Shuja Grimaxe fix
UPDATE `creature_template_movement` SET `Ground`=1, `Swim`=1 WHERE `CreatureId` IN (156799,167126);

-- Quest data
DELETE FROM `creature_queststarter` WHERE `id`=149899 AND `quest`=56034;
DELETE FROM `creature_queststarter` WHERE `id`=167019 AND `quest`=59941;
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(149899, 56034, 52649), -- Re-sizing the Situation accept from Lindie Springstock
(167019, 59941, 52649); -- Re-sizing the Situation accept from Cork Fizzlepop

DELETE FROM `creature_questender` WHERE `id`=156280 AND `quest`=56034;
DELETE FROM `creature_questender` WHERE `id`=167021 AND `quest`=59941;
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(156280, 56034, 52649), -- Re-sizing the Situation turn in to Captain Garrick
(167021, 59941, 52649); -- Re-sizing the Situation turn in to Warlord Breka Grimaxe

DELETE FROM `quest_template_addon` WHERE `ID` IN (56034,59941);
INSERT INTO `quest_template_addon` (`ID`,`AllowableClasses`,`PrevQuestID`,`NextQuestID`,`ScriptName`) VALUES
(56034,0,55193,0,'quest_resizing_the_situation_alliance'), -- Re-sizing the Situation Alliance
(59941,0,59940,0,'quest_resizing_the_situation_horde'); -- Re-sizing the Situation Horde

DELETE FROM `spell_script_names` WHERE `spell_id` IN (305749,326635,305716,305724,305721,305742,325346,325345);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(305749,'spell_summon_guardian_q56034_q59941'),
(326635,'spell_summon_guardian_q56034_q59941'),
(305716,'spell_re_sizing_q56034'),
(305724,'spell_resizer_hit_one_two_q56034_q59941'),
(305721,'spell_resizer_hit_one_two_q56034_q59941'),
(305742,'spell_resizer_hit_three_q56034'),
(325346,'spell_re_sizing_q59941'),
(325345,'spell_re_sizing_aura_q59941');

-- Conversation
DELETE FROM `conversation_template` WHERE `Id` IN (12086);
INSERT INTO `conversation_template` (`Id`,`FirstLineId`,`TextureKitId`,`ScriptName`,`VerifiedBuild`) VALUES
(12086,29430,0,'',52649);

DELETE FROM `conversation_actors` WHERE `ConversationId` IN (12086);
INSERT INTO `conversation_actors` (`ConversationId`,`ConversationActorId`,`ConversationActorGuid`,`Idx`,`CreatureId`,`CreatureDisplayInfoId`,`NoActorObject`,`ActivePlayerObject`,`VerifiedBuild`) VALUES
(12086,0,0,0,0,0,0,1,52649), -- Player
(12086,71366,0,1,0,0,0,0,52649), -- Lindie Springstock
(12086,76343,0,2,0,0,0,0,52649); -- Cork Fizzlepop

DELETE FROM `conversation_line_template` WHERE `Id` IN (29430,29431,36373);
INSERT INTO `conversation_line_template` (`Id`,`UiCameraID`,`ActorIdx`,`Flags`,`VerifiedBuild`) VALUES
(29430,0,0,0,52649),
(29431,0,1,0,52649),
(36373,0,2,0,52649);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=29 AND `SourceEntry` IN (29431,36373);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(29,0,29431,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 29431 if team is Alliance'),
(29,0,36373,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36373 if team is horde');

-- Conversation
DELETE FROM `conversation_template` WHERE `Id` IN (12087);
INSERT INTO `conversation_template` (`Id`,`FirstLineId`,`TextureKitId`,`ScriptName`,`VerifiedBuild`) VALUES
(12087,29435,0,'',52649);

DELETE FROM `conversation_actors` WHERE `ConversationId` IN (12087);
INSERT INTO `conversation_actors` (`ConversationId`,`ConversationActorId`,`ConversationActorGuid`,`Idx`,`CreatureId`,`CreatureDisplayInfoId`,`NoActorObject`,`ActivePlayerObject`,`VerifiedBuild`) VALUES
(12087,0,0,0,0,0,0,1,52649), -- Player
(12087,71366,0,1,0,0,0,0,52649), -- Lindie Springstock
(12087,76343,0,2,0,0,0,0,52649); -- Cork Fizzlepop

DELETE FROM `conversation_line_template` WHERE `Id` IN (29435,29432,36374);
INSERT INTO `conversation_line_template` (`Id`,`UiCameraID`,`ActorIdx`,`Flags`,`VerifiedBuild`) VALUES
(29435,0,0,0,52649),
(29432,0,1,0,52649),
(36374,0,2,0,52649);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=29 AND `SourceEntry` IN (29432,36374);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(29,0,29432,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 29432 if team is Alliance'),
(29,0,36374,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36374 if team is horde');

-- Conversation
DELETE FROM `conversation_template` WHERE `Id` IN (12088);
INSERT INTO `conversation_template` (`Id`,`FirstLineId`,`TextureKitId`,`ScriptName`,`VerifiedBuild`) VALUES
(12088,29437,0,'',52649);

DELETE FROM `conversation_actors` WHERE `ConversationId` IN (12088);
INSERT INTO `conversation_actors` (`ConversationId`,`ConversationActorId`,`ConversationActorGuid`,`Idx`,`CreatureId`,`CreatureDisplayInfoId`,`NoActorObject`,`ActivePlayerObject`,`VerifiedBuild`) VALUES
(12088,0,0,0,0,0,0,1,52649), -- Player
(12088,71366,0,1,0,0,0,0,52649), -- Lindie Springstock
(12088,76343,0,2,0,0,0,0,52649); -- Cork Fizzlepop

DELETE FROM `conversation_line_template` WHERE `Id` IN (29437,29438,36398);
INSERT INTO `conversation_line_template` (`Id`,`UiCameraID`,`ActorIdx`,`Flags`,`VerifiedBuild`) VALUES
(29437,0,0,0,52649),
(29438,0,1,0,52649),
(36398,0,2,0,52649);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=29 AND `SourceEntry` IN (29438,36398);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(29,0,29438,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 29438 if team is Alliance'),
(29,0,36398,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36398 if team is horde');

-- Conversation
DELETE FROM `conversation_template` WHERE `Id` IN (12089);
INSERT INTO `conversation_template` (`Id`,`FirstLineId`,`TextureKitId`,`ScriptName`,`VerifiedBuild`) VALUES
(12089,29439,0,'',52649);

DELETE FROM `conversation_actors` WHERE `ConversationId` IN (12089);
INSERT INTO `conversation_actors` (`ConversationId`,`ConversationActorId`,`ConversationActorGuid`,`Idx`,`CreatureId`,`CreatureDisplayInfoId`,`NoActorObject`,`ActivePlayerObject`,`VerifiedBuild`) VALUES
(12089,0,0,0,0,0,0,1,52649), -- Player
(12089,71366,0,1,0,0,0,0,52649), -- Lindie Springstock
(12089,76343,0,2,0,0,0,0,52649); -- Cork Fizzlepop

DELETE FROM `conversation_line_template` WHERE `Id` IN (29439,29440,36399);
INSERT INTO `conversation_line_template` (`Id`,`UiCameraID`,`ActorIdx`,`Flags`,`VerifiedBuild`) VALUES
(29439,0,0,0,52649),
(29440,0,1,0,52649),
(36399,0,2,0,52649);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=29 AND `SourceEntry` IN (29440,36399);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(29,0,29440,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 29440 if team is Alliance'),
(29,0,36399,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36399 if team is Horde');

-- Phase Area
DELETE FROM `phase_area` WHERE `AreaId`=10588 AND `PhaseId` IN (13775);
INSERT INTO `phase_area` (`AreaId`,`PhaseId`,`Comment`) VALUES
(10588,13775, 'Cosmetic - NPE - See Re-sized Boar at Plains');

-- Phase Names
DELETE FROM `phase_name` WHERE `ID` IN (13775);
INSERT INTO `phase_name` (`ID`,`Name`) VALUES
(13775,'Cosmetic - NPE - See Re-sized Boar at Plains');

-- Phase Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (13775) AND `SourceEntry`=10588;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26,13775,10588, 0, 0, 47, 0, 56034, 66, 0, 0, 0, 0, '', 'See Re-sized Boar at Plains if quest Re-sizing the Situation is completed | rewarded Alliance.'),
(26,13775,10588, 0, 0, 1, 0, 305742, 0, 0, 1, 0, 0, '', 'See Re-sized Boar at Plains if player does not have aura Resizer Hit'),
(26,13775,10588, 0, 0, 1, 0, 173426, 1, 0, 1, 0, 0, '', 'See Re-sized Boar at Plains if player does not have aura Riding Giant Boar');

-- Phasing Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=13776 AND `ConditionValue1`=56034;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=15318 AND `ConditionValue1`=59941;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26,13776,0, 0, 0, 47, 0, 56034, 8, 0, 1, 0, 0, '', 'See Lindie Springstock at Plains if quest Re-sizing the Situation is not in progress Alliance.'),
(26,15318,0, 0, 0, 47, 0, 59941, 8, 0, 1, 0, 0, '', 'See Cork Fizzlepop at Plains if quest Re-sizing the Situation is not in progress Horde.');

-- Fix phasing
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=15316 AND `SourceEntry` IN (10424,10588) AND `ConditionValue1` IN (59938,59939);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (15315,15318) AND `SourceEntry` IN (10424,10588) AND `ConditionValue1` IN (59939);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=13780 AND `SourceEntry` IN (10424,10588) AND `ConditionValue1` IN (55184,55186);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (13779,13776) AND `SourceEntry` IN (10424,10588) AND `ConditionValue1` IN (55184);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26,15316,10588,0,0,47,0,59939,66,0,0,0,0,'','Apply Phase 15316 if Quest 59939 (Forbidden Quilboar Necromancy) is completed or rewarded'),
(26,15316,10588,0,1,47,0,59938,66,0,0,0,0,'','Apply Phase 15316 if Quest 59938 (Down with the Quilboar) is completed or rewarded'),
(26,15315,10588,0,0,47,0,59939,66,0,0,0,0,'','Apply Phase 15315 if Quest 59939 (Forbidden Quilboar Necromancy) is completed or rewarded'),
(26,15318,10588,0,0,47,0,59939,66,0,0,0,0,'','Apply Phase 15318 if Quest 59939 (Forbidden Quilboar Necromancy) is completed or rewarded'),
(26,13780,10588,0,0,47,0,55184,66,0,0,0,0,'','Apply Phase 13780 if Quest 55184 (Forbidden Quilboar Necromancy) is completed or rewarded'),
(26,13780,10588,0,1,47,0,55186,66,0,0,0,0,'','Apply Phase 13780 if Quest 55186 (Down with the Quilboar) is completed or rewarded'),
(26,13779,10588,0,0,47,0,55184,66,0,0,0,0,'','Apply Phase 13779 if Quest 55184 (Forbidden Quilboar Necromancy) is completed or rewarded'),
(26,13776,10588,0,0,47,0,55184,66,0,0,0,0,'','Apply Phase 13776 if Quest 55184 (Forbidden Quilboar Necromancy) is completed or rewarded');

DELETE FROM `phase_area` WHERE `AreaId` IN (10424,10588) AND `PhaseId` IN (15316,15315,15318,13780,13779,13776);
INSERT INTO `phase_area` (`AreaId`,`PhaseId`,`Comment`) VALUES
(10588,15316, 'Cosmetic - NPE - Mithdran Dawntracker at Darkmaul Plains'),
(10588,15315, 'Cosmetic - NPE - Warlord Breka Grimaxe at Darkmaul Plains'),
(10588,15318, 'Cosmetic - NPE - Cork Fizzlepop at Darkmaul Plains'),
(10588,13780, 'Cosmetic - NPE - Austin Huxworth at Darkmaul Plains'),
(10588,13779, 'Cosmetic - NPE - Captain Garrick at Darkmaul Plains'),
(10588,13776, 'Cosmetic - NPE - Lindie Springstock at Darkmaul Plains');
