--  fix 1900+ errori di NPC_Trainer e sistema i profession trainer di Darnassus
UPDATE `creature_template` SET `npcflag`=81 WHERE `entry` IN (4160,4159,4211,4212,4213,6292,30715,52642,52640,52645,52636);
UPDATE `creature_template` SET `npcflag`=49 WHERE (`entry`=50504);