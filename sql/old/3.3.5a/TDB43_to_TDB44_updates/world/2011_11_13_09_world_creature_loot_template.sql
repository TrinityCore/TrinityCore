-- None of the creatures should drop Scarlet Cannonball
DELETE FROM `creature_loot_template` WHERE `item`=12973;
