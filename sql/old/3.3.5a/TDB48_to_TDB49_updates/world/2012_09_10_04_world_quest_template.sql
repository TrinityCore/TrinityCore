-- Fix some quest requirements
UPDATE `quest_template` SET `PrevQuestId`=3906 WHERE `Id` IN (3907,7201); -- Disharmony of Fire and The Last Element are available only, if Disharmony of Flame is completed
