DELETE FROM `creature_loot_template` WHERE `entry`=11671; -- Core Hounds
UPDATE `creature_template` SET `lootid`=0 WHERE `entry`=11671;

-- fixing previous sql (2011_11_07_02_world_misc.sql)
-- Removes save to instance flag from Hellfire Channeler
UPDATE `creature_template` SET `flags_extra`=`flags_extra` &~ 1 WHERE `entry`=17256;