-- give Frozo the Renowned his carpet back
DELETE FROM `creature_addon` WHERE `guid`= 202846;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`aiAnimKit`,`movementAnimKit`,`meleeAnimKit`,`auras`) VALUES
(202846,0,31837,0,257,0,0,0,0,'70878 75387');
--
