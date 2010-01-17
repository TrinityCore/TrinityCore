-- Usually creature_template changes MUST GO to TDB
-- creature_template spell1-spell8 are in the exceptions
UPDATE `creature_template` SET `spell8` = 27892 WHERE `entry` IN (16124, 29987);
UPDATE `creature_template` SET `spell8` = 27928 WHERE `entry` IN (16125, 29985);
UPDATE `creature_template` SET `spell8` = 27935 WHERE `entry` IN (16126, 29986);
