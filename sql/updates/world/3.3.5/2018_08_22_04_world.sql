-- 
UPDATE `creature` SET `MovementType`=0, `spawndist`=0 WHERE `id` IN (27401,27403);
DELETE FROM `creature_template_addon` WHERE `entry`=27401;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (27401,0,0,0,1,233 , '');
