-- Update playerlevestats to fit retail values
-- some kind of initial intellect boost for all classes except Warriors, Hunters and Rogues
UPDATE `player_levelstats` SET `inte`=`inte`+12 WHERE `level` IN (1,2,3,4,5,6,7,8,9) AND `class` NOT IN (1,3,4);
UPDATE `player_levelstats` SET `inte`=`inte`+11 WHERE `level`=10 AND `class` NOT IN (1,3,4);
UPDATE `player_levelstats` SET `inte`=`inte`+10 WHERE `level`=11 AND `class` NOT IN (1,3,4);
UPDATE `player_levelstats` SET `inte`=`inte`+9  WHERE `level`=12 AND `class` NOT IN (1,3,4);
UPDATE `player_levelstats` SET `inte`=`inte`+8  WHERE `level`=13 AND `class` NOT IN (1,3,4);
UPDATE `player_levelstats` SET `inte`=`inte`+7  WHERE `level`=14 AND `class` NOT IN (1,3,4);
UPDATE `player_levelstats` SET `inte`=`inte`+6  WHERE `level`=15 AND `class` NOT IN (1,3,4);
UPDATE `player_levelstats` SET `inte`=`inte`+5  WHERE `level`=16 AND `class` NOT IN (1,3,4);
UPDATE `player_levelstats` SET `inte`=`inte`+4  WHERE `level`=17 AND `class` NOT IN (1,3,4);
UPDATE `player_levelstats` SET `inte`=`inte`+2  WHERE `level`=18 AND `class` NOT IN (1,3,4);
UPDATE `player_levelstats` SET `inte`=`inte`+1  WHERE `level`=19 AND `class` NOT IN (1,3,4);
