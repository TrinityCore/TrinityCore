-- update Plague Slime & Marauding Geist to naxx25 trash lootid
UPDATE `creature_template` SET `lootid`=100005 WHERE `entry` IN(29575,30424);
--  update Plague Slime & Marauding Geist to naxx10 trash lootid
UPDATE `creature_template` SET `lootid`=100003 WHERE `entry` IN(16243,30083);
DELETE FROM `creature_loot_template` WHERE `entry` IN(30424,29575,16243,30083);
-- Remove scraps for naxx10 from creature creature_loot_template
DELETE FROM `creature_loot_template` WHERE `item` IN (22373,22374,22375,22376);
