-- Battle to Undercity should be turned in to Bragor Bloodfirst
DELETE FROM `creature_involvedrelation` WHERE `quest` IN (14351,550);
DELETE FROM `creature_questrelation` WHERE `quest` IN (14351,550);
INSERT INTO `creature_involvedrelation` (`id`,`quest`) VALUES (36273,14351);
