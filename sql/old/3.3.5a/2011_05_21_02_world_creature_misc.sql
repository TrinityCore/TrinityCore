UPDATE `creature_template` SET `unit_flags`=`unit_flags`&~0x02000100 WHERE `entry` IN (37007,38031);

DELETE FROM `creature_template_addon` WHERE `entry` IN (37007,38031);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(37007,0,0x0000000,0,0,'70733'),
(38031,0,0x0000000,0,0,'70733');
