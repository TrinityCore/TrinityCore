--
UPDATE `creature_template` SET `npcflag`=0 WHERE  `entry`=37523;
UPDATE `creature` SET `npcflag`=1 WHERE `guid` IN (121400, 121399);
