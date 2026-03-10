DELETE FROM `world_safe_locs` WHERE `ID` IN (100099, 100100, 100101, 100102);
UPDATE `battleground_template` SET `AllianceStartLoc` = 5816, `HordeStartLoc` = 5817 WHERE `ID` = 844;
UPDATE `battleground_template` SET `AllianceStartLoc` = 6616, `HordeStartLoc` = 6617 WHERE `ID` = 903;

UPDATE `gameobject` SET `spawntimesecs` = 360 WHERE `guid` IN (167081, 167082);
