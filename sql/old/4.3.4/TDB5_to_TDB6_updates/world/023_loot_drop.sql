-- Old Vicejaw (12432) was removed in 4.0.3a
-- http://www.wowpedia.org/Old_Vicejaw
DELETE FROM `creature_loot_template` WHERE `entry`=12432;
UPDATE `creature_template` SET `lootid`=0 WHERE `entry`=12432;
