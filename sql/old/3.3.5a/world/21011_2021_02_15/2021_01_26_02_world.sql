-- Fire
UPDATE `creature_template` SET `spell_school_immune_mask` = 4 WHERE `entry` IN (19551);

-- Arcane
UPDATE `creature_template` SET `spell_school_immune_mask` = 64 WHERE `entry` IN (15691);

-- All
UPDATE `creature_template` SET `spell_school_immune_mask` = 127 WHERE `entry` IN (11439,23111,20481,21538);

-- Magic, except holy
UPDATE `creature_template` SET `spell_school_immune_mask` = 124 WHERE `entry` IN (15275);

-- Physical
UPDATE `creature_template` SET `spell_school_immune_mask` = 1 WHERE `entry` IN (15276);
