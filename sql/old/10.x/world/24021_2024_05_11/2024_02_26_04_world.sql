-- Unneeded Row (Burning Blade Medallion)
DELETE FROM `quest_template_addon` WHERE `ID`=25132;
-- Lazy Peons and Vile Familiars Exclusive Group
UPDATE `quest_template_addon` SET `ExclusiveGroup`=-25131 WHERE `ID` IN (25131,37446);
UPDATE `quest_template_addon` SET `NextQuestID`=25132 WHERE `ID` IN (25131,37446);
