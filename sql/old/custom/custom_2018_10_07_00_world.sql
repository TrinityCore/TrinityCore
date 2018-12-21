-- Update and remove some creatures in Deepholm
UPDATE `creature_template` SET `InhabitType`= 4 WHERE `entry` IN (42522, 43641, 45191, 44189, 44077);
DELETE FROM `creature` WHERE `guid` IN (350193, 350213, 350342, 351686, 351976, 351668, 351978, 351975, 351670);
DELETE FROM `creature_addon` WHERE `guid` IN (350193, 350213, 350342, 351686, 351976, 351668, 351978, 351975, 351670);

-- Fix some startup errors
UPDATE `quest_template_addon` SET `ProvidedItemCount`= 1 WHERE `ID` IN (25807, 25323);

-- Lord Godfrey loot
DELETE FROM `creature_loot_template` WHERE `Entry` IN (46964, 49712);
DELETE FROM `reference_loot_template` WHERE `Entry` IN (469640, 497120, 497121);
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
-- Heroic
(497120, 63465, 0, 1, 1, 1, 1),
(497120, 63463, 0, 1, 1, 1, 1),
(497120, 63459, 0, 1, 1, 1, 1),
(497120, 63462, 0, 1, 1, 1, 1),
(497120, 63458, 0, 1, 1, 1, 1),
(497120, 63457, 0, 1, 1, 1, 1),
(497120, 63464, 0, 1, 1, 1, 1),
(497120, 63460, 0, 1, 1, 1, 1),
(497120, 63456, 0, 1, 1, 1, 1),
(497120, 63461, 0, 1, 1, 1, 1),
-- Normal
(469640, 6641, 0, 1, 1, 1, 1),
(469640, 6318, 0, 1, 1, 1, 1),
(469640, 6220, 0, 1, 1, 1, 1),
(469640, 3748, 0, 1, 1, 1, 1);

INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `Reference`, `MaxCount`) VALUES
(49712, 497120, 100, 1, 497120, 2),
(49712, 52078, 100, 1, 0, 1), -- Chaos Orb
(46964, 469640, 100, 1, 469640, 1);

DELETE FROM `reference_loot_template` WHERE `entry`= 48815;
DELETE FROM `conditions` WHERE `SourceEntry`= 75697 AND `SourceTypeOrReferenceId`= 13;
