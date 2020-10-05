--
UPDATE `creature` SET `spawntimesecs` = 86400 WHERE `spawntimesecs` = 43200 AND `map` BETWEEN 555 AND 558;
UPDATE `creature` SET `spawntimesecs` = 7200 WHERE `spawntimesecs` = 10800 AND `map` BETWEEN 555 AND 558;
UPDATE `creature` SET `spawntimesecs` = 300 WHERE `id` IN (18793,18891,21159,18726,18766,18778);
