-- Cleaning the database of unused/obsolete data
DELETE FROM `creature` WHERE `map` IN (449,450);
DELETE FROM `creature_loot_template` WHERE `entry` IN (16156,16157,16158,16368,16446,16448,16449,16451,16452);
UPDATE `creature_template` SET `lootid`=0 WHERE `entry` IN (16156,16157,16158,16368,16446,16448,16449,16451,16452);
