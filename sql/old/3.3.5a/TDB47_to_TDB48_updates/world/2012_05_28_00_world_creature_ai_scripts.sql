-- Fix recent DB errors
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=27135; -- Attunement To Dalaran Kill Credit
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=32400; -- Tukemuth

-- Fix recent DB errors (credits to Vincent-Michael)
DELETE FROM `creature_addon` WHERE `guid` = 2593;
DELETE FROM `creature_template_addon` WHERE `entry` = 2676;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(2676,0,0,0,4097,0,NULL);
