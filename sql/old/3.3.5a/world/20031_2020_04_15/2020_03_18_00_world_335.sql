-- 
UPDATE `creature_template_locale` SET `Title`="" WHERE `entry`=37072;
DELETE FROM `creature_template_addon` WHERE `entry`=37072;
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `emote`) VALUES (37072,4097,233);
