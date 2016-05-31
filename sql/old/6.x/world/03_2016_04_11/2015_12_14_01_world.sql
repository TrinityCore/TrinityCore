-- 
SET @Guid:=250893;
DELETE FROM `creature` WHERE `id`=44857 AND `guid` BETWEEN @guid+0 AND @guid+5;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseid`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`) VALUES
(@guid+0, 44857, 530, 1, 0, 0, 0, 10365.6, -6388.26, 38.6156, 4.55531, 300, 0, 0, 650, 0, 0),
(@guid+1, 44857, 530, 1, 0, 0, 0, 10375.3, -6432.24, 38.6156, 1.46608, 300, 0, 0, 650, 0, 0),
(@guid+2, 44857, 530, 1, 0, 0, 0, 10358.7, -6417.56, 38.6155, 1.13446, 300, 0, 0, 650, 0, 0),
(@guid+3, 44857, 530, 1, 0, 0, 0, 10337, -6413.31, 38.6156, 0.349066, 300, 0, 0, 650, 0, 0),
(@guid+4, 44857, 530, 1, 0, 0, 0, 10365.4, -6411.05, 38.6155, 0.715585, 300, 0, 0, 650, 0, 0),
(@guid+5, 44857, 530, 1, 0, 0, 0, 10341.4, -6396.64, 38.6156, 5.77704, 300, 0, 0, 650, 0, 0);

DELETE FROM `creature_template_addon` WHERE `entry` = 44857;
INSERT INTO `creature_template_addon` (`entry`,`bytes1`) VALUES (44857, 8);

UPDATE `creature_template` SET `RegenHealth`=0 WHERE `Entry` IN (44857, 44795);
UPDATE `creature` SET `curhealth`=650 WHERE `id`=44795;
