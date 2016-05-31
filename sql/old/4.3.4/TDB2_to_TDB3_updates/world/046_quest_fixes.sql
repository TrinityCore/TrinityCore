-- Quest #26707 A Deadly Vine - fix: Adding the Corpseweed
-- http://eu.battle.net/wow/en/item/60204 Drop Chance: Guaranteed
DELETE FROM `creature_loot_template` WHERE `entry` IN (43732, 45785) AND `item` = 60204;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(43732, 60204, -100, 1, 0, 1, 1), -- Corpseweed
(45785, 60204, -100, 1, 0, 1, 1); -- Carved One
UPDATE `creature_template` SET `lootid` = 43732 WHERE `entry` = 43732;
UPDATE `creature_template` SET `lootid` = 45785 WHERE `entry` = 45785;

-- Quest #26677 Ghoulish Effigy - fix: Adding the Ghoul Rib
-- http://eu.battle.net/wow/en/item/884 Drop Chances are High
DELETE FROM `creature_loot_template` WHERE `entry` IN (570, 1270) AND `item` = 884;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(570, 884, -75, 1, 0, 1, 1),  -- Brain Eater
(1270, 884, -90, 1, 0, 1, 1); -- Fetid Corpse
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=-75 WHERE `entry` IN (3, 210, 604, 948) and `item`=884;

-- Quest #26620 Seasoned Wolf Kabobs - fix: Adding the Wolf Skirt Steak
-- http://eu.battle.net/wow/en/item/60989 Drop Chance: Guaranteed
DELETE FROM `creature_loot_template` WHERE `entry` IN (521, 43704) AND `item` = 60989;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(521, 60989, -100, 1, 0, 1, 1),   -- Lupos
(43704, 60989, -100, 1, 0, 1, 1); -- Dire Wolf
UPDATE `creature_template` SET `lootid` = 43704 WHERE `entry` = 43704;

-- Quest #26623 Dusky Crab Cakes - fix: Adding the Dusky Lump
-- http://eu.battle.net/wow/en/item/60988 Drop Chance: High
DELETE FROM `creature_loot_template` WHERE `entry` = 217 AND `item` = 60988;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(217, 60988, -75, 1, 0, 1, 1); -- Venom Web Spider

-- Quest #26230 Feast or Famine - fix: Adding the Coyote Tail
-- http://eu.battle.net/wow/en/item/57787 Drop Chance: Guaranteed
DELETE FROM `creature_loot_template` WHERE `entry` IN (833, 834) AND `item` = 57787;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(833, 57787, -100, 1, 0, 1, 1), -- Coyote Packleader
(834, 57787, -100, 1, 0, 1, 1); -- Coyote

-- Quest #26347 Keeper of the Flame - fix: Adding the Chasm Ooze
-- http://eu.battle.net/wow/en/item/58204 Drop Chance: Guaranteed
DELETE FROM `creature_loot_template` WHERE `entry` = 42669 AND `item` = 58204;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(42669, 58204, -100, 1, 0, 1, 1); -- Chasm Slime
UPDATE `creature_template` SET `lootid` = 42669 WHERE `entry` = 42669;

-- Quest #26286 In Defense of Westfall - fix: Adding the Gnoll Attack Orders
-- http://eu.battle.net/wow/en/item/58111 Drop Chance: Medium
DELETE FROM `creature_loot_template` WHERE `entry` IN (124, 452, 501, 54371, 54372, 54373) AND `item` = 58111;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(124, 58111, -50, 1, 0, 1, 1),   -- Riverpaw Brute
(452, 58111, -50, 1, 0, 1, 1),   -- Riverpaw Bandit
(501, 58111, -50, 1, 0, 1, 1),   -- Riverpaw Herbalist
(54371, 58111, -50, 1, 0, 1, 1), -- Riverpaw Bandit
(54372, 58111, -50, 1, 0, 1, 1), -- Riverpaw Brute
(54373, 58111, -50, 1, 0, 1, 1); -- Riverpaw Herbalist
UPDATE `creature_template` SET `lootid` = 54371 WHERE `entry` = 54371;
UPDATE `creature_template` SET `lootid` = 54372 WHERE `entry` = 54372;
UPDATE `creature_template` SET `lootid` = 54373 WHERE `entry` = 54373;

-- Quest #26241 Westfall Stew - fix: Adding the Goretusk Flank
-- http://eu.battle.net/wow/en/item/57788 Drop Chance: Guaranteed
DELETE FROM `creature_loot_template` WHERE `entry` IN (157, 454, 42357) AND `item` = 57788;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(157, 57788, -100, 1, 0, 1, 1),   -- Goretusk
(454, 57788, -100, 1, 0, 1, 1),   -- Young Goretusk
(42357, 57788, -100, 1, 0, 1, 1); -- Hulking Goretusk
UPDATE `creature_template` SET `lootid`=42357 WHERE `entry`=42357;

-- Quest #26241 Westfall Stew - fix: Adding the Stringy Fleshripper Meat
-- http://eu.battle.net/wow/en/item/57786 Drop Chance: Guaranteed
DELETE FROM `creature_loot_template` WHERE `entry` IN (154, 199, 1109) AND `item` = 57786;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(154, 57786, -100, 1, 0, 1, 1),  -- Greater Fleshripper
(199, 57786, -100, 1, 0, 1, 1),  -- Young Fleshripper
(1109, 57786, -100, 1, 0, 1, 1); -- Fleshripper

-- Quest #25725 Fenbush Berries - fix: Adding the Handful of Fenberries
DELETE FROM `gameobject_loot_template` WHERE `entry` = 29571 AND `item` = 55233;
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(29571, 55233, -100, 1, 0, 1, 1);

-- Quest #412 Operation Recombobulation - fix: Adding the Gyromechanic Gear
-- http://eu.battle.net/wow/en/item/3084 Drop Chance: Guaranteed / High
DELETE FROM `creature_loot_template` WHERE `entry` IN (8503, 41146) AND `item` = 3084;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(8503, 3084, -75, 1, 0, 1, 1),   -- Gibblewilt
(41146, 3084, -100, 1, 0, 1, 1); -- Frostmane Scavenger
UPDATE `creature_template` SET `lootid` = 41146 WHERE `entry` = 41146;
