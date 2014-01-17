-- Doors should be closed
UPDATE `gameobject` SET `state`=1 WHERE `guid` IN (150074, 150073, 150077);

-- Duplicated Gameobject
DELETE FROM `gameobject` WHERE `guid`=150081;

-- Fix loots
UPDATE `gameobject_loot_template` SET `ChanceOrQuestChance`=-100 WHERE `entry` IN (27310, 27239);
