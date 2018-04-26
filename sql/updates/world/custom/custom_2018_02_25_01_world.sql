-- Add random movement to multiple creatures
UPDATE `creature` SET `MovementType`= 1, `spawndist`= 10 WHERE `ID` IN (113, 524, 822, 30, 40, 476, 1922, 525, 119, 118);
UPDATE `creature` SET `MovementType`= 1, `spawndist`= 5 WHERE `ID` IN (475, 735);

-- Add quest items for Quest 'A pie for Billy'
DELETE FROM `creature_loot_template` WHERE `Entry` IN (113, 524) AND `Item`= 60401;
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `MinCount`, `MaxCount`) VALUES
(113, 60401, 21, 1, 1, 1, 1),
(524, 60401, 11, 1, 1, 1, 1);
