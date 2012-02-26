UPDATE `creature_template` SET `ScriptName`='npc_exhausted_vrykul' WHERE `entry`='30146';
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000560 AND -1000555;
INSERT INTO `script_texts` (`entry`,`content_default`,`sound`,`type`,`language`,`emote`,`comment`) VALUES
(-1000555,'Back... to work...',0,0,0,0,'exhausted vrykul SAY_RAND_WORK1'),
(-1000556,'You treat us worse than animals!',0,0,0,0,'exhausted vrykul SAY_RAND_WORK2'),
(-1000557,'We will have revenge...some day.',0,0,0,0,'exhausted vrykul SAY_RAND_WORK3'),
(-1000558,'Curse you! You will not treat me like a beast!',0,0,0,0,'exhausted vrykul SAY_RAND_ATTACK1'),
(-1000559,'I\'d rather die fighting than live like a slave.',0,0,0,0,'exhausted vrykul SAY_RAND_ATTACK2'),
(-1000560,'Enough! I will teach you some manners, wench!',0,0,0,0,'exhausted vrykul SAY_RAND_ATTACK3');