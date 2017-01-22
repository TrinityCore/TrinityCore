-- 
UPDATE `creature` SET `spawndist`=0, `MovementType`=0, `unit_flags`=`unit_flags`|536870912|32770, `dynamicflags`=32 WHERE  `guid`=116778;

DELETE FROM `creature_addon` WHERE `guid` IN (113320, 116778);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(113320,0,0,0,1,233, ''),
(116778,0,0,7,1,0, '29266');
