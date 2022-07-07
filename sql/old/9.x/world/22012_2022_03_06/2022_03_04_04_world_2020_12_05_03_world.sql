-- Remove Captain's Key from creature loot, contained in Pirate's Footlocker. Adjust chance of Pirate's Footlocker
DELETE FROM `creature_loot_template` WHERE `Item` = 9249 AND `Reference` = 0;
UPDATE `creature_loot_template` SET `Chance` = 10 WHERE `Item` = 9276 AND `Reference` = 0;
