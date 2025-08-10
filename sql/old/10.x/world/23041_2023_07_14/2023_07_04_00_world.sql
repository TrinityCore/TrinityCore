SET @ATID := 23;
SET @ATIDSPAWN := 24;

-- Creature
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_master_mathias_shaw_human_heritage_lions_pride_inn_basement' WHERE `entry` = 198896;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_vanessa_vancleef_human_heritage_lions_pride_inn_basement' WHERE `entry` = 198883;

DELETE FROM `creature_template_addon` WHERE `entry` IN (198883 /*198883 (Vanessa VanCleef) - Stealth*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(198883, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '228928'); -- 198883 (Vanessa VanCleef) - Stealth

-- Delete SAI Script
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = 198896;

-- ScriptNames
DELETE FROM `spell_script_names` WHERE `spell_id` = 228928;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(228928, 'spell_stealth_vanessa_human_heritage');

-- Quest objective completion effect
DELETE FROM `quest_objectives_completion_effect` WHERE `ObjectiveID` = 431933;
INSERT INTO `quest_objectives_completion_effect` (`ObjectiveID`, `GameEventID`, `SpellID`, `ConversationID`, `UpdatePhaseShift`, `UpdateZoneAuras`) VALUES
(431933, NULL, NULL, NULL, 1, 0);

-- Serverside AT
DELETE FROM `areatrigger_template` WHERE `Id` = @ATID+0 AND `IsServerSide` = 1;
INSERT INTO `areatrigger_template` (`Id`, `IsServerSide`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `VerifiedBuild`) VALUES
(@ATID+0, 1, 1, 0, 18, 18, 12, 18, 18, 12, 0, 0, 0);

DELETE FROM `areatrigger` WHERE `SpawnId` = @ATIDSPAWN AND `IsServerSide` = 1;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerId`, `IsServerSide`, `MapId`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `Comment`) VALUES
(@ATIDSPAWN, @ATID, 1, 0, -9470.4521, -2.2114, 49.7938, 1.438999, 0, 19932, 0, 1, 18, 18, 12, 18, 18, 12, 0, 0, 'at_human_heritage_lions_pride_inn_basement_enter', 'Lions Pride Inn Basement Human Heritage');

-- Conversation
DELETE FROM `conversation_template` WHERE `Id` IN (20342, 20340);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(20342, 52461, 0, 49801),
(20340, 52459, 0, 49801);

UPDATE `conversation_template` SET `ScriptName` = 'conversation_an_unlikely_informant' WHERE `ID` = 20342;

DELETE FROM `conversation_actors` WHERE (`ConversationId`=20342 AND `Idx` IN (1,0)) OR (`ConversationId`=20340 AND `Idx` IN (1,0));
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(20342, 89180, 0, 1, 0, 0, 0, 0, 49801), -- Full: 0x2042400000C238C00078CF00007923CF Creature/0 R4240/S30927 Map: 0 (Eastern Kingdoms) Entry: 198883 (Vanessa VanCleef) Low: 7939023
(20342, 89175, 0, 0, 0, 0, 0, 0, 49801), -- Full: 0x2042400000C23C000078CF00007B66EE Creature/0 R4240/S30927 Map: 0 (Eastern Kingdoms) Entry: 198896 (Master Mathias Shaw) Low: 8087278
(20340, 89175, 9003909, 1, 0, 0, 0, 0, 49801), -- Full: 0x2042400000C23C000078CF00007923CF Creature/0 R4240/S30927 Map: 0 (Eastern Kingdoms) Entry: 198896 (Master Mathias Shaw) Low: 7939023
(20340, 0, 0, 0, 0, 0, 0, 1, 49801); -- Full: 0x0800040000000000FFFFFFFFFFFFFFFF Player/0 R1/S16777215 Map: 0 (Eastern Kingdoms) Low: 1099511627775

DELETE FROM `conversation_line_template` WHERE `Id` IN (52469, 52468, 52466, 52465, 52464, 53702, 52462, 52461, 52458, 52459);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(52469, 0, 1, 0, 0, 49801),
(52468, 0, 0, 0, 0, 49801),
(52466, 0, 0, 0, 0, 49801),
(52465, 0, 1, 0, 0, 49801),
(52464, 0, 0, 0, 0, 49801),
(53702, 0, 1, 0, 0, 49801),
(52462, 0, 0, 0, 0, 49801),
(52461, 0, 0, 0, 2, 49801),
(52458, 0, 1, 0, 0, 49801),
(52459, 0, 0, 0, 0, 49801);
