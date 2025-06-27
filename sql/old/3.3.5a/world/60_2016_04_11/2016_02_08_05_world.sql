-- diseases immunity tbc
UPDATE `creature_template` SET `mechanic_immune_mask` = `mechanic_immune_mask` &~ 2097152 WHERE `exp` = 1;
