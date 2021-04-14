-- Chill of the Throne removal
DELETE FROM `spell_area` WHERE `spell`=69127;
-- Gameobjects loot drop updates
UPDATE `gameobject_loot_template` SET `ChanceOrQuestChance`=-100 WHERE `entry`=27848 AND `item`=50443;
UPDATE `gameobject_loot_template` SET `ChanceOrQuestChance`=-100 WHERE `entry`=39770 AND `item`=69907;
UPDATE `gameobject_loot_template` SET `ChanceOrQuestChance`=-100 WHERE `entry`=40281 AND `item`=72160;
