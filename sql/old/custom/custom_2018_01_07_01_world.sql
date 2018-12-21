-- DK Questline fixes
UPDATE `creature_questender` SET `id`= 25462 WHERE `quest`= 12636;

-- Add One-Handed maces to DK
DELETE FROM `playercreateinfo_skills` WHERE `classMask`= 32 AND `skill`= 54;
INSERT INTO `playercreateinfo_skills` (`classMask`, `raceMask`, `skill`, `comment`) VALUES
(32, 0, 54, 'Death Knight - Mace');

-- Grand Theft Palomino requires the Scarlet Harvest to be completed before
UPDATE `quest_template_addon` SET `PrevQuestID`= 12670 WHERE `ID`= 12680;

-- The Scarlet Apocalypse requires Scarlet Armies Approach to be completed before
UPDATE `quest_template_addon` SET `PrevQuestID`= 12757 WHERE `ID`= 12778;
