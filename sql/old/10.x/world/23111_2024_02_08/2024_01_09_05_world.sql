-- Set by TC Devs
-- New areatrigger
SET @ID := 58; -- One required
SET @SPAWNID := 58; -- One required
SET @CREATEPROPID := 46; -- One required

-- Briar Patch

-- Create new serverside areatrigger for leaving Quillboar Briarpatch conversation "Used Phase 13878 Not sure if right phase"
DELETE FROM `areatrigger` WHERE `SpawnId`=@SPAWNID;
INSERT INTO `areatrigger` (`SpawnId`,`AreaTriggerCreatePropertiesId`,`IsCustom`,`MapId`,`PosX`,`PosY`,`PosZ`,`Orientation`,`PhaseUseFlags`,`PhaseId`,`PhaseGroup`,`ScriptName`,`Comment`) VALUES
(@SPAWNID,@CREATEPROPID,1,2175,71.47106,-2463.159,87.024765,0.79634166,0,0,0,'at_briarpatch_to_plains','Exiles Reach - Down with Quilboar quest complete');

DELETE FROM `areatrigger_create_properties` WHERE `Id`=@CREATEPROPID AND `IsCustom`=1;
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(@CREATEPROPID, 1, @ID, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1,4,60,30,4,60,30,0,0, '', 0);

-- Add new serverside areatrigger for leaving Quillboar Brarpatch to template
DELETE FROM `areatrigger_template` WHERE `Id`=@ID AND `IsCustom`=1;
INSERT INTO `areatrigger_template` (`Id`,`IsCustom`,`Flags`,`VerifiedBuild`) VALUES
(@ID,1,1,0);

UPDATE `creature` SET `spawntimesecs`=120 WHERE `id` IN (151091,150237,150238,156676);
UPDATE `creature` SET `PhaseId`=15276 WHERE `guid` IN (1051256,1051265);
UPDATE `creature` SET `StringId`='briarpatch_bunny_alliance' WHERE `guid` IN (1051256);
DELETE FROM `creature` WHERE `Id` IN (167008,154301);

UPDATE `creature_template` SET `flags_extra`=128 WHERE `entry`=155371;
UPDATE `creature_template` SET `ScriptName`="npc_geolord_grekog" WHERE `entry`=151091;
UPDATE `creature_template` SET `ScriptName`="npc_cork_fizzlepop_briarpatch" WHERE `entry`=167008;
UPDATE `creature_template` SET `ScriptName`="npc_lindie_springstock_briarpatch" WHERE `entry`=154301;
UPDATE `creature_template` SET `ScriptName`="npc_quilboar_warrior" WHERE `entry`=150237;
UPDATE `creature_template` SET `ScriptName`="npc_quilboar_geomancer" WHERE `entry`=150238;
UPDATE `creature_template` SET `ScriptName`="npc_ogre_overseer" WHERE `entry`=156676;
UPDATE `creature_template` SET `ScriptName`="npc_captain_garrick" WHERE `entry`=156280;

UPDATE `creature_template_movement` SET `Ground`=1, `Flight`=0 WHERE `CreatureId` IN (167008,154301);

DELETE FROM `creature_template_movement` WHERE `CreatureId`=155371;
INSERT INTO `creature_template_movement` (`CreatureId`,`Ground`,`Swim`,`Flight`,`Rooted`,`Chase`,`Random`,`InteractionPauseTimer`) VALUES
(155371,0,0,1,1,0,0,0);

DELETE FROM `phase_area` WHERE `AreaId`=10424 AND `PhaseId` IN (15314,15276);
INSERT INTO `phase_area` (`AreaId`,`PhaseId`,`Comment`) VALUES
(10424,15314, 'Cosmetic - NPE - Cork Fizzlepop before quest 59938 complete'),
(10424,15276, 'Cosmetic - NPE - Lindie Springstock before quest 55186 complete');

DELETE FROM `phase_name` WHERE `ID` IN (15314,15276);
INSERT INTO `phase_name` (`ID`,`Name`) VALUES
(15276,'Cosmetic - NPE - Lindie Springstock before quest 55186 complete'),
(15314,'Cosmetic - NPE - Cork Fizzlepop before quest 59938 complete');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (15314,15276) AND `SourceEntry`=10424;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26,15314,10424,0,0,47,0,59938,9,0,0,0,0,'','Apply Phase 15314 if Quest 59938 (Down with the Quilboar) is not taken | in progress'),
(26,15314,10424,0,0,6,0,67,0,0,0,0,0,'','Apply Phase 15314 if team is Horde'),
(26,15276,10424,0,0,47,0,55186,9,0,0,0,0,'','Apply Phase 15276 if Quest 55186 (Down with the Quilboar) is not taken | in progress'),
(26,15276,10424,0,0,6,0,469,0,0,0,0,0,'','Apply Phase 15276 if team is Alliance');

-- Conversation data for Geolord Grek'og
DELETE FROM `conversation_actors` WHERE `ConversationId` IN (13712);
INSERT INTO `conversation_actors` (`ConversationId`,`ConversationActorId`,`ConversationActorGuid`,`Idx`,`CreatureId`,`CreatureDisplayInfoId`,`NoActorObject`,`ActivePlayerObject`,`VerifiedBuild`) VALUES
(13712,70670,1051258,0,0,0,0,0,52649), -- Geolord Grek'og
(13712,71238,0,1,0,0,0,0,52649), -- Lindie Springstock
(13712,75976,0,2,0,0,0,0,52649); -- Cork Fizzlepop

DELETE FROM `conversation_line_template` WHERE `Id` IN (34175,34176,36346);
INSERT INTO `conversation_line_template` (`Id`,`UiCameraID`,`ActorIdx`,`Flags`,`VerifiedBuild`) VALUES
(34175,0,0,0,52649),
(34176,0,1,0,52649),
(36346,0,2,0,52649);

DELETE FROM `conversation_template` WHERE `Id` IN (13712);
INSERT INTO `conversation_template` (`Id`,`FirstLineId`,`TextureKitId`,`Flags`,`ScriptName`,`VerifiedBuild`) VALUES
(13712,34175,0,0x04,'',52649);

-- Conversation entering plains
DELETE FROM `conversation_actors` WHERE `ConversationId` IN (12076,14514);
INSERT INTO `conversation_actors` (`ConversationId`,`ConversationActorId`,`ConversationActorGuid`,`Idx`,`CreatureId`,`CreatureDisplayInfoId`,`NoActorObject`,`ActivePlayerObject`,`VerifiedBuild`) VALUES
(12076,71328,8000019,0,0,0,0,0,52649), -- Lindie Springstock
(12076,71330,8000018,1,0,0,0,0,52649), -- Captain Garrick
(14514,75979,8000016,0,0,0,0,0,52649), -- Cork Fizzlepop
(14514,75977,8000015,1,0,0,0,0,52649); -- Warlord Breka Grimaxe

DELETE FROM `conversation_line_template` WHERE `Id` IN (29386,29387,29388,36347,36348,36349);
INSERT INTO `conversation_line_template` (`Id`,`UiCameraID`,`ActorIdx`,`Flags`,`VerifiedBuild`) VALUES
(29386,0,0,0,52649),
(29387,0,1,0,52649),
(29388,0,0,0,52649),
(36347,0,0,0,52649),
(36348,0,1,0,52649),
(36349,0,0,0,52649);

DELETE FROM `conversation_template` WHERE `Id` IN (12076,14514);
INSERT INTO `conversation_template` (`Id`,`FirstLineId`,`TextureKitId`,`ScriptName`,`VerifiedBuild`) VALUES
(12076,29386,0,'',52649),
(14514,36347,0,'',52649);

-- Quest data
DELETE FROM `creature_queststarter` WHERE `id`=154327 AND `quest` IN (55184,55186);
DELETE FROM `creature_queststarter` WHERE `id`=166996 AND `quest` IN (59938,59939);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(154327, 55186, 52649), -- Down with the Quilboar accept from Austin Huxworth
(154327, 55184, 52649), -- Forbidden Quilboar Necromancy accept from Austin Huxworth
(166996, 59938, 52649), -- Down with the Quilboar accept from Mithdran Dawntracker
(166996, 59939, 52649); -- Forbidden Quilboar Necromancy accept from Mithdran Dawntracker

DELETE FROM `creature_questender` WHERE `id`=149899 AND `quest` IN (55186);
DELETE FROM `creature_questender` WHERE `id`=149915 AND `quest` IN (55184);
DELETE FROM `creature_questender` WHERE `id`=167019 AND `quest` IN (59938);
DELETE FROM `creature_questender` WHERE `id`=167020 AND `quest` IN (59939);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(149899, 55186, 52649), -- Down with the Quilboar turn in to Lindie Springstock
(149915, 55184, 52649), -- Forbidden Quilboar Necromancy turn in to Austin Huxworth
(167019, 59938, 52649), -- Down with the Quilboar turn in to Cork Fizzlepop
(167020, 59939, 52649); -- Forbidden Quilboar Necromancy turn in to Mithdran Dawntracker

-- Condition for source Quest available condition type Quest rewarded
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceGroup`=0 AND `SourceEntry` IN (55186,55184,59938,59939) AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 55186, 0, 0, 8, 0, 55173, 0, 0, 0, 0, 0, '', 'AND0 Quest Down with the Quilboar available if quest Northbound has been rewarded Alliance.'),
(19, 0, 55186, 0, 0, 15, 0, 4, 0, 0, 1, 0, 0, '', 'AND0 Quest Down with the Quilboar available if player is not a Hunter Alliance.'),
(19, 0, 55186, 0, 1, 8, 0, 59342, 0, 0, 0, 0, 0, '', 'OR1 Quest Down with the Quilboar available if quest Taming the Wilds has been rewarded Alliance.'),
(19, 0, 55184, 0, 0, 8, 0, 55173, 0, 0, 0, 0, 0, '', 'AND0 Quest Forbidden Quilboar Necromancy available if quest Northbound has been rewarded Alliance.'),
(19, 0, 55184, 0, 0, 15, 0, 4, 0, 0, 1, 0, 0, '', 'AND0 Quest Forbidden Quilboar Necromancy available if player is not a Hunter Alliance.'),
(19, 0, 55184, 0, 1, 8, 0, 59342, 0, 0, 0, 0, 0, '', 'OR1 Quest Forbidden Quilboar Necromancy available if quest Taming the Wilds has been rewarded Alliance.'),
(19, 0, 59938, 0, 0, 8, 0, 59935, 0, 0, 0, 0, 0, '', 'AND0 Quest Down with the Quilboar available if quest Northbound has been rewarded Horde.'),
(19, 0, 59938, 0, 0, 15, 0, 4, 0, 0, 1, 0, 0, '', 'AND0 Quest Down with the Quilboar available if player is not a Hunter Horde.'),
(19, 0, 59938, 0, 1, 8, 0, 59937, 0, 0, 0, 0, 0, '', 'OR1 Quest Down with the Quilboar available if quest Taming the Wilds has been rewarded Horde.'),
(19, 0, 59939, 0, 0, 8, 0, 59935, 0, 0, 0, 0, 0, '', 'AND0 Quest Forbidden Quilboar Necromancy available if quest Northbound has been rewarded Horde.'),
(19, 0, 59939, 0, 0, 15, 0, 4, 0, 0, 1, 0, 0, '', 'AND0 Quest Forbidden Quilboar Necromancy available if player is not a Hunter Horde.'),
(19, 0, 59939, 0, 1, 8, 0, 59937, 0, 0, 0, 0, 0, '', 'OR1 Quest Forbidden Quilboar Necromancy available if quest Taming the Wilds has been rewarded Horde.');

DELETE FROM `quest_template_addon` WHERE `ID` IN (55186,55184,59938,59939);
INSERT INTO `quest_template_addon` (`ID`,`AllowableClasses`,`PrevQuestID`,`NextQuestID`,`ScriptName`) VALUES
(55186,0,0,0,'quest_briarpatch_alliance'), -- Alliance
(55184,0,0,0,'quest_briarpatch_alliance'), -- Alliance
(59938,0,0,0,'quest_briarpatch_horde'), -- Horde
(59939,0,0,0,'quest_briarpatch_horde'); -- Horde

-- Spell data
DELETE FROM `spell_script_names` WHERE `spell_id` IN (298984,325309);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(298984,'spell_validated_quest_accept_briarpatch_alliance'),
(325309,'spell_validated_quest_accept_briarpatch_horde');

-- Conversation data
DELETE FROM `conversation_actors` WHERE `ConversationId` IN (12073,14513);
INSERT INTO `conversation_actors` (`ConversationId`,`ConversationActorId`,`ConversationActorGuid`,`Idx`,`CreatureId`,`CreatureDisplayInfoId`,`NoActorObject`,`ActivePlayerObject`,`VerifiedBuild`) VALUES
(12073,71326,0,0,0,0,0,0,45745), -- Austin Huxworth
(12073,71327,0,1,0,0,0,0,45745), -- Captain Garrick
(14513,76330,0,0,0,0,0,0,45745), -- Mithdran Dawntracker
(14513,76330,0,1,0,0,0,0,45745); -- Warlord Grimaxe

DELETE FROM `conversation_line_template` WHERE `Id` IN (29375,29376,34174,36343,36344,36345);
INSERT INTO `conversation_line_template` (`Id`,`UiCameraID`,`ActorIdx`,`Flags`,`VerifiedBuild`) VALUES
(29375,0,0,0,45745), -- Alliance
(29376,0,1,0,45745), -- Alliance
(34174,0,0,0,45745), -- Alliance
(36343,0,0,0,45745), -- Horde
(36344,0,1,0,45745), -- Horde
(36345,0,0,0,45745); -- Horde

DELETE FROM `conversation_template` WHERE `Id` IN (12073,14513);
INSERT INTO `conversation_template` (`Id`,`FirstLineId`,`TextureKitId`,`ScriptName`,`VerifiedBuild`) VALUES
(12073,29375,0,'',45745),
(14513,36343,0,'',45745);

-- Creature text for Exile's Reach Briarpatch
DELETE FROM `creature_text` WHERE `CreatureID` IN (150237,156676) AND `GroupID` IN (0,1);
DELETE FROM `creature_text` WHERE `CreatureID` IN (150238) AND `GroupID` IN (0,1,2);
DELETE FROM `creature_text` WHERE `CreatureID` IN (154301,167008) AND `GroupID` IN (0);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(150237, 0, 0, 'The geolord demands your demise!', 12, 0, 100, 0, 0, 150271, 176076, 0, 'Quilboar Warrior aggro'),
(150237, 0, 1, 'The ogres give us strength!', 12, 0, 100, 0, 0, 150276, 176074, 0, 'Quilboar Warrior aggro'),
(150237, 0, 2, 'Your blood will earn our reward!', 12, 0, 100, 0, 0, 150277, 176075, 0, 'Quilboar Warrior aggro'),
(150237, 0, 3, 'We serve the geolord!', 12, 0, 100, 0, 0, 150279, 176077, 0, 'Quilboar Warrior aggro'),
(150237, 0, 4, 'Witness our power!', 12, 0, 100, 0, 0, 150280, 176078, 0, 'Quilboar Warrior aggro'),
(150237, 0, 5, 'Death to the outsiders!', 12, 0, 100, 0, 0, 150281, 176079, 0, 'Quilboar Warrior aggro'),
(150237, 0, 6, 'Our thorns will strangle you!', 12, 0, 100, 0, 0, 150282, 176080, 0, 'Quilboar Warrior aggro'),
(150237, 0, 7, 'More sacrifices for the ritual!', 12, 0, 100, 0, 0, 150283, 176082, 0, 'Quilboar Warrior aggro'),
(150237, 1, 0, 'I return... to... the earth...', 12, 0, 100, 0, 0, 150284, 176083, 0, 'Quilboar Warrior death'),
(150237, 1, 1, 'Our tribe... will... survive...', 12, 0, 100, 0, 0, 150285, 176084, 0, 'Quilboar Warrior death'),
(150237, 1, 2, 'Ogres... will... kill you...', 12, 0, 100, 0, 0, 150286, 176085, 0, 'Quilboar Warrior death'),
(150237, 1, 3, 'The geolord... will not... lose...', 12, 0, 100, 0, 0, 150287, 176086, 0, 'Quilboar Warrior death'),
(150237, 1, 4, 'Thorns... take... you...', 12, 0, 100, 0, 0, 150288, 176088, 0, 'Quilboar Warrior death'),
(150238, 0, 0, 'The geolord demands your demise!', 12, 0, 100, 0, 0, 150271, 176076, 0, 'Quilboar Geomancer aggro'),
(150238, 0, 1, 'The ogres give us strength!', 12, 0, 100, 0, 0, 150276, 176074, 0, 'Quilboar Geomancer aggro'),
(150238, 0, 2, 'Your blood will earn our reward!', 12, 0, 100, 0, 0, 150277, 176075, 0, 'Quilboar Geomancer aggro'),
(150238, 0, 3, 'We serve the geolord!', 12, 0, 100, 0, 0, 150279, 176077, 0, 'Quilboar Geomancer aggro'),
(150238, 0, 4, 'Witness our power!', 12, 0, 100, 0, 0, 150280, 176078, 0, 'Quilboar Geomancer aggro'),
(150238, 0, 5, 'Death to the outsiders!', 12, 0, 100, 0, 0, 150281, 176079, 0, 'Quilboar Geomancer aggro'),
(150238, 0, 6, 'Our thorns will strangle you!', 12, 0, 100, 0, 0, 150282, 176080, 0, 'Quilboar Geomancer aggro'),
(150238, 0, 7, 'More sacrifices for the ritual!', 12, 0, 100, 0, 0, 150283, 176082, 0, 'Quilboar Geomancer aggro'),
(150238, 1, 0, 'I return... to... the earth...', 12, 0, 100, 0, 0, 150284, 176083, 0, 'Quilboar Geomancer death'),
(150238, 1, 1, 'Our tribe... will... survive...', 12, 0, 100, 0, 0, 150285, 176084, 0, 'Quilboar Geomancer death'),
(150238, 1, 2, 'Ogres... will... kill you...', 12, 0, 100, 0, 0, 150286, 176085, 0, 'Quilboar Geomancer death'),
(150238, 1, 3, 'The geolord... will not... lose...', 12, 0, 100, 0, 0, 150287, 176086, 0, 'Quilboar Geomancer death'),
(150238, 1, 4, 'Thorns... take... you...', 12, 0, 100, 0, 0, 150288, 176088, 0, 'Quilboar Geomancer death'),
(150238, 2, 0, '%s attempts to run away in fear!', 16, 0, 100, 0, 0, 0, 0, 0, 'Quilboar Geomancer flee'),
(156676, 0, 0, 'New sacrifice!', 12, 0, 100, 0, 0, 150269, 178950, 0, 'Ogre Overseer aggro'),
(156676, 1, 0, 'Sacrifice... for... ritual...', 12, 0, 100, 0, 0, 150271, 178951, 0, 'Ogre Overseer death'),
(154301, 0, 0, 'I knew the Alliance would rescue us! Let''s get out of here!', 12, 0, 100, 0, 0, 152861, 176943, 0, 'Lindie Springstock rescued'),
(167008, 0, 0, 'And that''s why I always bet on the Horde! Let''s scram!', 12, 0, 100, 0, 0, 156983, 196265, 0, 'Lindie Springstock rescued');

-- Spellscript
DELETE FROM `spell_script_names` WHERE `spell_id`=313265;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(313265, 'spell_quilboar_sleep_dnt');

-- Fix Ref loot "Thanks Meji"
UPDATE `reference_loot_template` SET `GroupId`=1 WHERE `Entry`=10100;

-- Fix previous commits

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (15315,15318,13779,13776) AND `SourceEntry` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26,15315,0,0,0,47,0,59938,66,0,0,0,0,'','Apply Phase 15315 if Quest 59938 (Down with the Quilboar) is completed or rewarded'),
(26,15318,0,0,0,47,0,59938,66,0,0,0,0,'','Apply Phase 15318 if Quest 59938 (Down with the Quilboar) is completed or rewarded'),
(26,13779,0,0,0,47,0,55186,66,0,0,0,0,'','Apply Phase 13779 if Quest 55186 (Down with the Quilboar) is completed or rewarded'),
(26,13776,0,0,0,47,0,55186,66,0,0,0,0,'','Apply Phase 13776 if Quest 55186 (Down with the Quilboar) is completed or rewarded');

-- Loot for Quilboar Warrior & Quilboar Geomancer
SET @ID := 150237;
UPDATE `creature_template_difficulty` SET `LootID`=@ID, GoldMin=4, GoldMax=20 WHERE `Entry` IN (@ID,@ID+1);
DELETE FROM `creature_loot_template` WHERE `Entry` IN (@ID);
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(@ID,771,0,20,0,1,0,1,1,'Quilboar Warrior/Geomancer - Chipped Boar Tusk'),
(@ID,174811,0,20,0,1,0,1,1,'Quilboar Warrior/Geomancer - Stitched Cloth Tunic'),
(@ID,174812,0,20,0,1,0,1,1,'Quilboar Warrior/Geomancer - Stitched Leather Tunic'),
(@ID,174813,0,20,0,1,0,1,1,'Quilboar Warrior/Geomancer - Linked Mail Hauberk'),
(@ID,174814,0,20,0,1,0,1,1,'Quilboar Warrior/Geomancer - Dented Chestplate'),
(@ID,0,10100,15,0,1,0,1,1,'Quilboar Warrior/Geomancer - Poor Quality Table Level 1 to 5');

-- Conditions for class loot
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=1 AND `SourceGroup`=@ID;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(1,@ID,174811,0,0,15,0,400,0,0,0,0,0,'','Item drops for cloth wearer'),
(1,@ID,174811,0,0,47,0,58882,64,0,1,0,0,'','Item drops if quest 58882 is not rewarded'),
(1,@ID,174812,0,0,15,0,3592,0,0,0,0,0,'','Item drops for leather wearer'),
(1,@ID,174812,0,0,47,0,58882,64,0,1,0,0,'','Item drops if quest 58882 is not rewarded'),
(1,@ID,174813,0,0,15,0,4168,0,0,0,0,0,'','Item drops for mail wearer'),
(1,@ID,174813,0,0,47,0,58882,64,0,1,0,0,'','Item drops if quest 58882 is not rewarded'),
(1,@ID,174814,0,0,15,0,35,0,0,0,0,0,'','Item drops for plate wearer'),
(1,@ID,174814,0,0,47,0,58882,64,0,1,0,0,'','Item drops if quest 58882 is not rewarded');

DELETE FROM `quest_template` WHERE `ID`=58882;
INSERT INTO `quest_template` (`ID`,`QuestType`,`RewardXPMultiplier`,`RewardMoneyMultiplier`,`RewardArtifactXPMultiplier`,`Flags`,`LogTitle`) VALUES
(58882,2,1,1,1,1024, '[Hidden Tracker] Quilboar Briarpatch Chestpiece Dropped');

-- fix due to accidental removal
DELETE FROM `quest_template` WHERE `ID`=58904;
INSERT INTO `quest_template` (`ID`, `QuestType`, `QuestPackageID`, `ContentTuningID`, `QuestSortID`, `QuestInfoID`, `SuggestedGroupNum`, `RewardNextQuest`, `RewardXPDifficulty`, `RewardXPMultiplier`, `RewardMoneyDifficulty`, `RewardMoneyMultiplier`, `RewardBonusMoney`, `RewardDisplaySpell1`, `RewardDisplaySpell2`, `RewardDisplaySpell3`, `RewardSpell`, `RewardHonor`, `RewardKillHonor`, `StartItem`, `RewardArtifactXPDifficulty`, `RewardArtifactXPMultiplier`, `RewardArtifactCategoryID`, `Flags`, `FlagsEx`, `FlagsEx2`, `RewardItem1`, `RewardAmount1`, `RewardItem2`, `RewardAmount2`, `RewardItem3`, `RewardAmount3`, `RewardItem4`, `RewardAmount4`, `ItemDrop1`, `ItemDropQuantity1`, `ItemDrop2`, `ItemDropQuantity2`, `ItemDrop3`, `ItemDropQuantity3`, `ItemDrop4`, `ItemDropQuantity4`, `RewardChoiceItemID1`, `RewardChoiceItemQuantity1`, `RewardChoiceItemDisplayID1`, `RewardChoiceItemID2`, `RewardChoiceItemQuantity2`, `RewardChoiceItemDisplayID2`, `RewardChoiceItemID3`, `RewardChoiceItemQuantity3`, `RewardChoiceItemDisplayID3`, `RewardChoiceItemID4`, `RewardChoiceItemQuantity4`, `RewardChoiceItemDisplayID4`, `RewardChoiceItemID5`, `RewardChoiceItemQuantity5`, `RewardChoiceItemDisplayID5`, `RewardChoiceItemID6`, `RewardChoiceItemQuantity6`, `RewardChoiceItemDisplayID6`, `POIContinent`, `POIx`, `POIy`, `POIPriority`, `RewardTitle`, `RewardArenaPoints`, `RewardSkillLineID`, `RewardNumSkillUps`, `PortraitGiver`, `PortraitGiverMount`, `PortraitGiverModelSceneID`, `PortraitTurnIn`, `RewardFactionID1`, `RewardFactionValue1`, `RewardFactionOverride1`, `RewardFactionCapIn1`, `RewardFactionID2`, `RewardFactionValue2`, `RewardFactionOverride2`, `RewardFactionCapIn2`, `RewardFactionID3`, `RewardFactionValue3`, `RewardFactionOverride3`, `RewardFactionCapIn3`, `RewardFactionID4`, `RewardFactionValue4`, `RewardFactionOverride4`, `RewardFactionCapIn4`, `RewardFactionID5`, `RewardFactionValue5`, `RewardFactionOverride5`, `RewardFactionCapIn5`, `RewardFactionFlags`, `RewardCurrencyID1`, `RewardCurrencyQty1`, `RewardCurrencyID2`, `RewardCurrencyQty2`, `RewardCurrencyID3`, `RewardCurrencyQty3`, `RewardCurrencyID4`, `RewardCurrencyQty4`, `AcceptedSoundKitID`, `CompleteSoundKitID`, `AreaGroupID`, `TimeAllowed`, `AllowableRaces`, `TreasurePickerID`, `Expansion`, `ManagedWorldStateID`, `QuestSessionBonus`, `LogTitle`, `LogDescription`, `QuestDescription`, `AreaDescription`, `PortraitGiverText`, `PortraitGiverName`, `PortraitTurnInText`, `PortraitTurnInName`, `QuestCompletionLog`, `VerifiedBuild`) VALUES 
(58904, 2, 0, 0, 10833, 255, 0, 0, 5, 1, 5, 1, 219400, 0, 0, 0, 0, 0, 0, 174867, 0, 1, 0, 34082816, 32768, 4096, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 7, 0, 0, 0, 7, 0, 0, 0, 7, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 890, 878, 0, 0, 18446744073709551615, 0, 7, 0, 0, 'Shards of Corruption', 'Collect $0oa Shards of Corruption.', '<You feel the pull of something dark and inhuman on your mind, it\'s writhing tendrils digging in, tugging at your sanity. You feel compelled to collect more shards... all of them.>', '', '', '', '', '', 'Locate the Idol of Iniquity.', 35435);

-- Loot for Geolord Grek'og
SET @ID := 151091;
UPDATE `creature_template_difficulty` SET `LootID`=@ID, GoldMin=4, GoldMax=20 WHERE `Entry` IN (@ID);
DELETE FROM `creature_loot_template` WHERE `Entry` IN (@ID);
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(@ID,771,0,100,0,1,0,1,1,'Geolord Grek''og - Chipped Boar Tusk');

UPDATE `creature_summoned_data` SET `DespawnOnQuestsRemoved`='59342,55186,55184' WHERE `CreatureID`=154327; -- Austin Huxworth
UPDATE `creature_summoned_data` SET `DespawnOnQuestsRemoved`='59937,59938,59939' WHERE `CreatureID`=166996; -- Mithdran Dawntracker

DELETE FROM `creature_summoned_data` WHERE `CreatureID` IN(156662, 166997);
INSERT INTO `creature_summoned_data` (`CreatureID`, `DespawnOnQuestsRemoved`) VALUES
(156662, '55186,55184'), -- Garrick
(166997, '59938,59939'); -- Grimaxe
