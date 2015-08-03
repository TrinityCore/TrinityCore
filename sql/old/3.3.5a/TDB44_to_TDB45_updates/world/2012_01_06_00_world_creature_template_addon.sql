-- Give Sai'kkal Invisibility aura to Sai'kkal
DELETE FROM `creature_template_addon` WHERE `entry`=22932;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(22932,0,0,0,0,'39680');
