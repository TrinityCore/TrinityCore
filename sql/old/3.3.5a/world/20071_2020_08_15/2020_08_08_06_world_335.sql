-- Add BroadcastTextId to one of Molthor's texts & remove useless locales
UPDATE `creature_text` SET `Text` = "Begin the ritual, my servants.  We must banish the heart of Hakkar back into the void!", `BroadcastTextId` = 10474 WHERE `CreatureID` = 14875 AND `GroupID` = 0 AND `ID` = 0;
DELETE FROM `creature_text_locale` WHERE `CreatureID` = 14875;
