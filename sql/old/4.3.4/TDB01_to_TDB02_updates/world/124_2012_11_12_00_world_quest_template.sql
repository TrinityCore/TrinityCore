-- Set chaining for Doomguard minion quests
UPDATE `quest_template` SET `PrevQuestId`=7581 WHERE `Id`=7582; -- Complete The Prison's Bindings before The Prison's Casing
UPDATE `quest_template` SET `PrevQuestId`=7582 WHERE `Id`=7583; -- Complete The Prison's Casing before Suppression
