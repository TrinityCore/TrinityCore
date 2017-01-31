UPDATE `creature_template` SET `faction_A`=1914,`faction_H`=1914,`unit_flags`=33024 WHERE `entry`=26452;

DELETE FROM `creature_template_addon` WHERE `entry`=26452;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(26452,0,0,0,1,383,'');
