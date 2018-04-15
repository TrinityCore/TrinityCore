UPDATE `creature` SET `orientation` = MOD(`orientation`, 2*PI()) WHERE `guid` IN (42160, 207528);
UPDATE `gameobject` SET `orientation` = MOD(`orientation`, 2*PI()) WHERE `guid` = 7607;
