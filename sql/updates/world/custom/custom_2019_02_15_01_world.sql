UPDATE `creature_template` SET `flags_extra`= 1073741824 WHERE `entry` IN (52613, 52601, 52614, 52607, 52957, 52959, 52963);
UPDATE `creature_template` SET `lootid`= 0 WHERE `entry` IN (52973, 52969, 52961, 52971, 52975);
DELETE FROM `spell_group` WHERE `spell_id` IN (30808, 53138, 58180);
