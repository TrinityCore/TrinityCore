-- 
UPDATE `creature_template` SET `npcflag`=129 WHERE `entry` IN (15350,15351);
DELETE FROM `creature_queststarter` WHERE `id` IN (15350,15351);
DELETE FROM `creature_questender` WHERE `id` IN (15350,15351);
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry` IN (8388,13475);
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,8388,0,'','','Deprecated quest: For Great Honor'),
(1,13475,0,'','','Deprecated quest: For Great Honor');
