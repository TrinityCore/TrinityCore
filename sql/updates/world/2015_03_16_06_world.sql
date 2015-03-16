-- 
SET @GUID := 286259; -- Set by TC
DELETE FROM `creature` WHERE `guid`=@GUID;
INSERT INTO `creature` (`guid`, `id`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`) VALUES
(@GUID, 49425, 1, 1, 1962.828, 1417.599, 67.46286, 3.560472, 120);
DELETE FROM `creature_template_addon` WHERE `entry`=49425;
INSERT INTO `creature_template_addon` (`entry`, `bytes1`, `bytes2`, `auras`) VALUES
(49425, 65536, 0, "49415");
DELETE FROM `spell_area` WHERE spell=49417 AND AREA=154;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `racemask`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES
(49417, 154, 24970, 24971, 16, 1, 66, 11);
