-- Horde
UPDATE `quest_template` SET `PrevQuestId`=24805 WHERE `Id`=24536; -- Uncommon Scents completed before starting Something Stinks
UPDATE `quest_template` SET `PrevQuestId`=24536 WHERE `Id`=24541; -- Something Stinks completed before starting Pilfering Perfume
UPDATE `quest_template` SET `PrevQuestId`=24541 WHERE `Id`=24850; -- Pilfering Perfume completed before starting Snivel's Sweetheart
UPDATE `quest_template` SET `PrevQuestId`=24850 WHERE `Id`=24851; -- Snivel's Sweetheart completed before starting Hot On The Trail
UPDATE `quest_template` SET `PrevQuestId`=24851 WHERE `Id`=24576; -- Hot On The Trail completed before starting A Friendly Chat...

UPDATE `quest_template` SET `PrevQuestId`=24576 WHERE `Id` IN (24638,24645,24647,24648,24649,24650,24651,24652); -- A Friendly Chat... completed before starting Crushing the Crown

-- Alliance
UPDATE `quest_template` SET `PrevQuestId`=24804 WHERE `Id`=24655; -- Uncommon Scents completed before starting Something Stinks
UPDATE `quest_template` SET `PrevQuestId`=24655 WHERE `Id`=24656; -- Something Stinks completed before starting Pilfering Perfume
UPDATE `quest_template` SET `PrevQuestId`=24656 WHERE `Id`=24848; -- Pilfering Perfume completed before starting Snivel's Sweetheart
UPDATE `quest_template` SET `PrevQuestId`=24848 WHERE `Id`=24849; -- Snivel's Sweetheart completed before starting Hot On The Trail
UPDATE `quest_template` SET `PrevQuestId`=24849 WHERE `Id`=24657; -- Hot On The Trail completed before starting A Friendly Chat...

UPDATE `quest_template` SET `PrevQuestId`=24657 WHERE `Id` IN (24658,24659,24660,24662,24663,24664,24665,24666); -- A Friendly Chat... completed before starting Crushing the Crown
