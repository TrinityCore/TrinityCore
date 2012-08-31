-- Update loot ids for(Ymirjar Deathbringer,Ymirjar Flamebearer,Ymirjar Skycaller,Ymirjar Wrathbringer,Stonespine Gargoyle) - Same as other ICC 5man hc trash
UPDATE `creature_template` SET `lootid`=100001 WHERE `entry` IN (37641,37642,37643,37644,37622);
DELETE FROM `creature_loot_template` WHERE `entry` IN (37641,37642,37643,37644,37622);