-- 
UPDATE `creature_template` SET `unit_flags`=768, `RegenHealth`=0 WHERE `entry`=26335;
DELETE FROM `creature_template_addon` WHERE `entry`=26335;
INSERT INTO `creature_template_addon` (`entry`, `bytes1`, `bytes2`) VALUES (26335, 7, 1);
UPDATE `creature` SET `curhealth`=1 WHERE `id`=26335;
