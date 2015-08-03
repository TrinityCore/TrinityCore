UPDATE `gameobject_template` SET `faction`=1732 WHERE `entry`=195139; -- Portal to Stormwind
UPDATE `gameobject_template` SET `faction`=1735 WHERE `entry`=195140; -- Portal to Orgrimmar

UPDATE `creature_template` SET `flags_extra`=`flags_extra`|128|2 WHERE `entry` IN (18967,18968,19230); -- Dark Assault - Alliance/Horde/Legion Portal - Invisible Stalker

DELETE FROM `gameobject` WHERE `id` IN (195139, 195140);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(164, 195140, 530, 1, 1, -161.3178, 965.4099, 54.29044, 0, 0, 0, 0, 0, 200, 0, 1), -- Portal to Orgrimmar
(170, 195139, 530, 1, 1, -337.4917, 962.6188, 54.28853, 0, 0, 0, 0, 0, 200, 0, 1); -- Portal to Stormwind
