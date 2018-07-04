-- Muffinus Chromebrew <Hunter Trainer> & Sculpin <Muffinus's Pet>
DELETE FROM `creature` WHERE `guid` IN (452575,452576);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(452575, 103614, 0, 0, 0, 1, 1, 169, 0, 0, -5117.266, 430.6424, 402.9908, 3.33525, 120, 0, 0, 0, 0, 0, 0, 0, 0, 24015),
(452576, 103617, 0, 0, 0, 1, 1, 169, 0, 0, -5116.958, 429.1945, 402.9924, 3.001636, 120, 0, 0, 0, 0, 0, 0, 0, 0, 24015);
-- Add addons
DELETE FROM `creature_template_addon` WHERE `entry` IN (103614,103617);
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(103614,0,0,0,2,214, ''),(103617,0,0,0,257,0, '');

-- Fixup Muffinus Chromebrew <Hunter Trainer>
UPDATE `creature_template` SET `npcflag`=3 WHERE `entry`=103614;
DELETE FROM `creature_equip_template` WHERE `CreatureID`=103614;
INSERT INTO `creature_equip_template` (`CreatureID`,`ID`,`ItemID3`,`VerifiedBuild`) VALUES (103614,1,58975,24015);
-- Xi, Friend to the Small SAI
SET @ENTRY := 63238;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,4000,5000,4000,5000,10,507,508,509,0,0,0,1,0,0,0,0,0,0,0,"Xi, Friend to the Small - OOC - Random Emote");
-- Add addons
DELETE FROM `creature_template_addon` WHERE `entry` IN (63238,63239,63241,63242);
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(63238,0,0,0,1,510, ''),(63239,0,0,0,1,510, ''),(63241,0,0,0,1,510, ''),(63242,0,0,0,1,510, '');

DELETE FROM `disables` WHERE `sourceType`=1 AND `entry` IN (24640,24752,24760,24766,24772,24778,26198,26200,26204,26207,26274,31138,31162);
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,24640,0,'','', 'Deprecated quest: The Arts of a Warrior'),
(1,24752,0,'','', 'Deprecated quest: The Arts of a Mage'),
(1,24760,0,'','', 'Deprecated quest: The Arts of a Shaman'),
(1,24766,0,'','', 'Deprecated quest: The Arts of a Druid'),
(1,24772,0,'','', 'Deprecated quest: The Arts of a Rogue'),
(1,24778,0,'','', 'Deprecated quest: The Arts of a Hunter'),
(1,26198,0,'','', 'Deprecated quest: The Arts of a Mage'),
(1,26200,0,'','', 'Deprecated quest: The Arts of a Priest'),
(1,26204,0,'','', 'Deprecated quest: The Arts of a Warrior'),
(1,26207,0,'','', 'Deprecated quest: The Arts of a Rogue'),
(1,26274,0,'','', 'Deprecated quest: The Arts of a Warlock'),
(1,31138,0,'','', 'Deprecated quest: The Arts of a Monk'),
(1,31162,0,'','', 'Deprecated quest: The Arts of a Monk');
