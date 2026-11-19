--
DELETE FROM `creature_loot_template` WHERE `Reference` = 0 AND `Item` IN (33567,33568,38557,38558,44128);
UPDATE `creature_template` SET `lootid` = 0 WHERE `entry` IN (28340,28341);
UPDATE `creature_template` SET `skinloot` = 70205 WHERE `entry` IN (31591,31592,31599,31604,31605,31606,31607,31608,31609,31610,31611,31612,31615,31616,31617);
