-- 
DELETE FROM `creature` WHERE `guid` IN (86655,86704);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`) VALUES
(86655, 34973, 530, 1, 1, 0, 1, 9844.6, -7566.67, 19.3376, 0.471239, 300, 0, 0, 3874500, 8908, 0),
(86704, 40413, 530, 1, 1, 0, 1, 9856.36, -7566.91, 19.2514, 2.73493, 300, 0, 0, 0, 0, 0);

UPDATE `creature_template` SET `npcflag`=1048577 WHERE `entry` IN (34973,40413);
UPDATE `creature_template` SET `minlevel`=81,`maxlevel`=81, `exp`=2, `DamageModifier`=7.5 WHERE `entry`=40413; -- 3.3.5 ONLY

DELETE FROM `battlemaster_entry` WHERE `entry` IN (34973,40413);
INSERT INTO `battlemaster_entry` (`entry`, `bg_template`) VALUES
(34973,32),
(40413,32);

DELETE FROM `gameobject_addon` WHERE `guid` IN (150377, 150378);
