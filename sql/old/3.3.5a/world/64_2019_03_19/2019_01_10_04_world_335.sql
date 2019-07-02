-- 
DELETE FROM `creature` WHERE `guid` IN (48306);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`,`spawndist`, `MovementType`) VALUES
(48306, 11285, 0, 1, 1, 0, 0, 1194.061, -2310.092, 57.172, 2.902832, 600, 0, 0);

UPDATE `creature_template` SET `npcflag`=`npcflag`|1, `gossip_menu_id`=3361 WHERE `entry`=11285;
DELETE FROM `creature_template_addon` WHERE `entry`=11285;
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `auras`) VALUES (11285, 1, "17622");

DELETE FROM `gossip_menu` WHERE `MenuID` IN (3361);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`) VALUES (3361,4117);
