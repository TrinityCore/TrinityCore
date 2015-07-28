-- Add Dark Assassin's Pendant to the loot template of Dark Assassin
-- Drop chance: Guaranteed - http://eu.battle.net/wow/en/item/62033
UPDATE `creature_template` SET `lootid`=46202 WHERE `entry`=46202;
DELETE FROM `creature_loot_template` WHERE `entry`=46202 and `item`=62033;
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(46202,62033,-100,1,0,1,1);

-- Add Fresh Gryphon Carcass to the loot template of Untamed Gryphon
-- Drop chance: Guaranteed - http://eu.battle.net/wow/en/item/62915
UPDATE `creature_template` SET `lootid`=46158 WHERE `entry`=46158;
DELETE FROM `creature_loot_template` WHERE `entry`=46158 and `item`=62915;
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(46158,62915,-100,1,0,1,1);

-- Add The Elementium Axe to the loot template of Blindeye the Guardian
-- Drop chance: Guaranteed - http://eu.battle.net/wow/en/item/62230
UPDATE `creature_template` SET `lootid`=46399 WHERE `entry`=46399;
DELETE FROM `creature_loot_template` WHERE `entry`=46399 and `item`=62230;
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(46399,62230,-100,1,0,1,1);

-- Add Magmalord Falthazar's Head to the loot template of Magmalord Falthazar
-- Drop chance: Guaranteed - http://eu.battle.net/wow/en/item/63286
UPDATE `creature_template` SET `lootid`=48015 WHERE `entry`=48015;
DELETE FROM `creature_loot_template` WHERE `entry`=48015 and `item`=63286;
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(48015,63286,-100,1,0,1,1);

-- Add Bahrum's Pants to the loot template of Gorosh the Pant Stealer
-- Drop chance: Guaranteed - http://eu.battle.net/wow/en/item/63374
UPDATE `creature_template` SET `lootid`=48102 WHERE `entry`=48102;
DELETE FROM `creature_loot_template` WHERE `entry`=48102 and `item`=63374;
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(48102,63374,-100,1,0,1,1);

-- Add Pristine Owl Feather to the loot template of Tawny Owl
-- Drop chance: Guaranteed - http://eu.battle.net/wow/en/item/64317
UPDATE `creature_template` SET `lootid`=46162 WHERE `entry`=46162;
DELETE FROM `creature_loot_template` WHERE `entry`=46162 and `item`=64317;
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(46162,64317,-100,1,0,1,1);
