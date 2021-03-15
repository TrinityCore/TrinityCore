-- temp fix unit class db errors
UPDATE `creature_template` SET `unit_class` = 1 WHERE `unit_class` = 0;