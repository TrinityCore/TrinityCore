-- ====================
-- NPC Loot Issue Fixes (White Junk `item`s) - Drop Rates WAY Too High (Totally Screwed Very High Drop % For No Good Reason - Bad Query messed things up long time ago)
-- ====================
-- Warrior's Boots
UPDATE `creature_loot_template` SET `Chance`=0.03 WHERE `item`=2967 AND `entry` IN (3199,3244,3265);
-- Spellbinder Gloves
UPDATE `creature_loot_template` SET `Chance`=0.03 WHERE `item`=2972 AND `entry` IN (2190,11319);
-- Veteran Bracers
UPDATE `creature_loot_template` SET `Chance`=0.03 WHERE `item`=3213 AND `entry` IN (2069,3118,3269,4263,11323);
-- Spellbinder Cloak
UPDATE `creature_loot_template` SET `Chance`=0.03 WHERE `item`=4683 AND `entry` IN (3244);
-- Hunting Cloak
UPDATE `creature_loot_template` SET `Chance`=0.03 WHERE `item`=4689 AND `entry` IN (3265);
-- Disciple's Cloak
UPDATE `creature_loot_template` SET `Chance`=0.03 WHERE `item`=6514 AND `entry` IN (2957,3100,3123,3196,3244,3268);
-- Soldier's Cloak
UPDATE `creature_loot_template` SET `Chance`=0.03 WHERE `item`=6549 AND `entry` IN (2324,3632);
