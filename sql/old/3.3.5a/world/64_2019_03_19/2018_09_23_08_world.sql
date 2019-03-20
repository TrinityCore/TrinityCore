-- 
DELETE FROM `gameobject` WHERE `guid` =6516;
INSERT INTO gameobject (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(6516, 191817, 530, 1, 1, 2969.68, 3752.76, 144.505, 1.9984, 0, 0, 0.841038, 0.540975, 180, 255, 1);
UPDATE `creature_template` SET `gossip_menu_id`=9781 WHERE `entry`=28708;
