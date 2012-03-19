-- Crusader Bridenbrad
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=30562; -- Remove EAI
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|32768,`ScriptName`='',`AIName`='' WHERE `entry`=30562;
UPDATE `creature_model_info` SET `bounding_radius`=0.306,`combat_reach`=1.5,`gender`=0 WHERE `modelid`=27123;
DELETE FROM `creature_template_addon` WHERE `entry`=30562;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(30562,0,65536,1,0, '57744 57626');
