-- Shadowmourne quest chain fix by nelegalno

-- Limit quests to Warrior, Paladin and Death Knight classes
UPDATE `quest_template` SET `RequiredClasses` = 35 WHERE `Id` IN (24545, 24743, 24547, 24749, 24756, 24757, 24548, 24748);

-- Quest relations
UPDATE `quest_template` SET `NextQuestId` = 24743 WHERE `Id` = 24545; -- The Sacred and the Corrupt
UPDATE `quest_template` SET `NextQuestId` = 24547 WHERE `Id` = 24743; -- Shadow's Edge
UPDATE `quest_template` SET `NextQuestId` = 24749 WHERE `Id` = 24547; -- A Feast of Souls
UPDATE `quest_template` SET `NextQuestId` = 24756 WHERE `Id` = 24749; -- Unholy Infusion
UPDATE `quest_template` SET `NextQuestId` = 24757 WHERE `Id` = 24756; -- Blood Infusion
UPDATE `quest_template` SET `NextQuestId` = 24548 WHERE `Id` = 24757; -- Frost Infusion
UPDATE `quest_template` SET `NextQuestId` = 24549 WHERE `Id` = 24548; -- The Splintered Throne
UPDATE `quest_template` SET `NextQuestId` = 24748 WHERE `Id` = 24549; -- Shadowmourne... to The Lich King's Last Stand
