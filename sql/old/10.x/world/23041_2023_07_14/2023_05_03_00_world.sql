SET @CGUID := 9003523;

-- Creature
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 202656, 2444, 13862, 13862, '0', 20506, 0, 0, 1, 80.35416412353515625, -936.22918701171875, 836.95343017578125, 4.306043148040771484, 120, 0, 0, 2258380, 0, 0, 0, 0, 0, 49343); -- Mayla Highmountain (Area: Valdrakken - Difficulty: 0) CreateObject1

DELETE FROM `creature_template_addon` WHERE `entry` = 202656;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(202656, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- 202656 (Mayla Highmountain)

DELETE FROM `creature_equip_template` WHERE `ID`=1 AND `CreatureID` = 202656;
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(202656, 1, 34058, 0, 0, 0, 0, 0, 0, 0, 0, 49343); -- Mayla Highmountain

UPDATE `creature_template` SET `faction`=35, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=202656; -- Mayla Highmountain

-- Phasing
DELETE FROM `phase_name` WHERE `ID` = 20506;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(20506, 'Cosmetic - See Mayla Highmountain in Valdrakken');

DELETE FROM `phase_area` WHERE `AreaId` = 13862 AND `PhaseId` = 20506;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(13862, 20506, 'Cosmetic - See Mayla Highmountain in Valdrakken');

-- Conversation
DELETE FROM `conversation_actors` WHERE (`ConversationId`=20991 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(20991, 90419, (@CGUID+0), 0, 0, 0, 0, 0, 49343); -- Full: 0x203CDD3180C5E80000164900004BE13B Creature/0 R3895/S5705 Map: 2444 (10.0 Dragon Isles) Entry: 202656 (Mayla Highmountain) Low: 4972859

DELETE FROM `conversation_line_template` WHERE `Id` = 54866;
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `VerifiedBuild`) VALUES
(54866, 0, 0, 0, 49343);

DELETE FROM `conversation_template` WHERE `Id` = 20991;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(20991, 54866, 0, 49343);

-- SAI
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` = 202656;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 202656 AND `source_type` = 0;
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(202656, 0, 0, 0, 19, 0, 100, 0, 72591, 0, 0, 0, 0, '', 143, 20991, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Mayla - On Quest accept 72591 - Start Conversation 20991 - To Invoker');

-- Quest stuff
DELETE FROM `quest_details` WHERE `ID`=72591;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(72591, 1, 0, 0, 0, 0, 0, 0, 0, 49343); -- A Debt That Must Be Paid

DELETE FROM `creature_queststarter` WHERE (`id`=202656 AND `quest`=72591);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(202656, 72591, 49343); -- A Debt That Must Be Paid offered Mayla Highmountain

-- Model stuff
DELETE FROM `creature_model_info` WHERE `DisplayID` IN (110930, 111423, 112067, 112068);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(110930, 0.722000002861022949, 2, 0, 49343),
(111423, 0.388999998569488525, 1.5, 0, 49343),
(112067, 0.536199986934661865, 2.10000014305114746, 0, 49343),
(112068, 1.10000002384185791, 1.65000009536743164, 0, 49343);
