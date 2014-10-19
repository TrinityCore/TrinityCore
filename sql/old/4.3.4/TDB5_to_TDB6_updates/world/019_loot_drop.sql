-- Garrick's Head (182) and Garrick Padfoot (103) were removed in 4.0.3a along with quest "Bounty on Garrick Padfoot" (6)
-- http://www.wowpedia.org/Quest:Bounty_on_Garrick_Padfoot
DELETE FROM `creature_loot_template` WHERE `entry`=103;
DELETE FROM `pickpocketing_loot_template` WHERE `entry`=103;
UPDATE `creature_template` SET `lootid`=0, `pickpocketloot`=0 WHERE `entry`=103;
