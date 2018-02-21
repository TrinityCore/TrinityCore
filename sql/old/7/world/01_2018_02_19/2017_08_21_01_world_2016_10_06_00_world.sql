--
UPDATE `creature_template` SET `AIName`="", `flags_extra`=0 WHERE `entry`=2667;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid`= 2667 AND `source_type`=0;
DELETE FROM `creature_template_addon` WHERE `entry`=2667;
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(2667, "3825");
