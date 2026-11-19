-- Fix IC intro texts and TextRange
-- Highlord Tirion Fordring used broadcast text for his gossip menu; TextRange is wrong at least for type 12
UPDATE `creature_text` SET `BroadcastTextId` = 37027 WHERE `CreatureID` = 37119 AND `GroupID` = 0 AND `ID` = 0;
UPDATE `creature_text` SET `TextRange` = 2 WHERE `CreatureID` = 37119;
UPDATE `creature_text` SET `TextRange` = 2 WHERE `CreatureID` = 37187 AND `GroupID` BETWEEN 15 AND 18;
