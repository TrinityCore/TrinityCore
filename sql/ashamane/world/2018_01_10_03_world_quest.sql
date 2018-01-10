-- The Future of Gnomeregan

SET @CGUID = 33;

DELETE FROM `quest_template_addon` WHERE `ID` IN (31135, 41217);
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
('31135','0','512','0','27674','31137','0','0','0','0','0','0','0','0','0','0','0','monk quest'),
('41217','0','4','0','27674','41218','0','0','0','0','0','0','0','0','0','0','0','hunter quest');

DELETE FROM `creature` WHERE `id` IN (63238, 103614);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 63238, 0, 1, 5495, 1, 0, 0, 0, 0, -5166.229, 464.4757, 390.5133, 5.212526, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25549),
(@CGUID+1, 103614, 0, 1, 5495, 1, 0, 0, 0, 0, -5117.266, 430.6424, 402.9908, 3.33525, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25549);

DELETE FROM `creature_template_addon` WHERE `entry` IN (63238, 103614);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(63238, 0, 0, 0, 1, 0, 0, 0, 0, ''),
(103614, 0, 0, 0, 2, 0, 0, 0, 0, '');

DELETE FROM `creature_equip_template` WHERE `CreatureID` = 103614;
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(103614, 1, 0, 0, 0, 0, 0, 0, 58975, 0, 0);


UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20, `faction`=875, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=103614;
UPDATE `creature_template` SET `npcflag`=3, `unit_flags`=32768, `unit_flags2`=34816 WHERE `entry`=63238;
