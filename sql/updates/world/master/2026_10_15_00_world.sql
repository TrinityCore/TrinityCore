-- A Choice of Allies (50239): its prerequisite The Call for Allies (49929) is deprecated and has no quest starter
UPDATE `quest_template_addon` SET `PrevQuestID` = 0 WHERE `ID` = 50239;

-- Void Elf banner in the Stormwind embassy spawned active, so "Learn about the Void Elves" could not be completed
UPDATE `gameobject` SET `state` = 1 WHERE `guid` = 6000625;
