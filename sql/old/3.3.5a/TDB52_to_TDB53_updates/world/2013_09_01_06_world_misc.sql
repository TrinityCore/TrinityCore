DELETE FROM `creature_addon` WHERE `auras` LIKE '%46598%'; -- no need to specify GUID, these are unique
DELETE FROM `creature_addon` WHERE `auras` LIKE '%43671%'; -- no need to specify GUID, these are unique
DELETE FROM `creature_addon` WHERE `guid`=85236;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(85236,0,22471,0,1,0,'63500 64718');
DELETE FROM `creature_addon` WHERE `guid` IN (132681,128620);
