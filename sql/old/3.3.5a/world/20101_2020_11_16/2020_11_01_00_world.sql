--
UPDATE `gameobject` SET `spawntimesecs` = 86400 WHERE `id` IN (184465);
UPDATE `gameobject` SET `spawntimesecs` = 0 WHERE `id` IN (184322,184449,184632,185015,184228,184227,184226,184225,183788);
UPDATE `gameobject` SET `state` = 1 WHERE `id` IN (184227,184228);
UPDATE `gameobject` SET `state` = 0 WHERE `id` IN (184449);
