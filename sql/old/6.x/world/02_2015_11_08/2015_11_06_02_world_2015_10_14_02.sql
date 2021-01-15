--
DELETE FROM `creature_addon` WHERE `guid` IN (56606,56607);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(56606,566050,0,0,1,0, ''),
(56607,566050,0,0,1,0, '');
