-- Usually creature_template changes MUST GO to TDB
-- creature_template spell1-spell8 are in the exceptions

-- Unrelenting Trainee
UPDATE `creature_template` SET `spell1` = 55604, `spell8` = 27892 WHERE `entry` = 16124;
UPDATE `creature_template` SET `spell1` = 55645, `spell2` = 0, `spell8` = 27892 where `entry` = 29987;

-- Unrelenting Death Knight
UPDATE `creature_template` SET `spell1` = 27825, `spell8` = 27928 WHERE `entry` IN (16125, 29985);

-- Unrelenting Rider
UPDATE `creature_template` SET `spell1` = 27831, `spell2` = 55606, `spell8` = 27935 where `entry` = 16126;
UPDATE `creature_template` SET `spell1` = 55638, `spell2` = 55608, `spell8` = 27935 where `entry` = 29986;
