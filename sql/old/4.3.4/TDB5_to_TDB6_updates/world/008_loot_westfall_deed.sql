-- "Westfall Deed" has very low drop chances
-- http://eu.battle.net/wow/en/item/1972 / http://www.wowpedia.org/Westfall_Deed
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=5 WHERE `entry` IN
(116, -- Bandit
474,  -- Rogue Wizard
583,  -- Ambusher
880,  -- Erlan Drudgemoor
881,  -- Surena Caledon
6846, -- Dockmaster
6866, -- Bodyguard
6927) -- Dockworker
AND `item`=1972;
