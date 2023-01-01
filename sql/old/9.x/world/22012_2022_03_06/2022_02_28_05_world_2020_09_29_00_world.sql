-- Fix type of Emberstrife's emote, remove useless duration https://youtu.be/ruKkcLm8Qug?t=349
UPDATE `creature_text` SET `Type` = 16, `Duration` = 0, `comment` = "Emberstrife" WHERE `CreatureID` = 10321 AND `GroupID` = 0 AND `ID` = 0;
