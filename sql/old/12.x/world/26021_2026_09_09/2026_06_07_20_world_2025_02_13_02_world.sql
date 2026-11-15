-- Fix for Orb of Orahil chain, prevent hard locked

-- Remove prev quest requirements from quests "Shard of a Felhound" (4962) and "Shard of an Infernal" (4963)
UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE `ID` IN (4962,4963);

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry` IN (4962,4963);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19,0,4962,0,0,47,0,1799,74,0,0,0,0,"","Quest 'Shard of an Infernal' can only be taken if quest 'Fragments of the Orb of Orahil' is in progress, completed and rewarded"),
(19,0,4963,0,0,47,0,1799,74,0,0,0,0,"","Quest 'Shard of a Felhound' can only be taken if quest 'Fragments of the Orb of Orahil' is in progress, completed and rewarded");

-- Script updates
-- Spell visual more inline with what can be seen on live servers
UPDATE `smart_scripts` SET `action_param1`=16633, `comment`="Menara - On Script - Cast 'Create Item Visual'" WHERE `entryorguid`=626600 AND `id`=2;

-- Timers
UPDATE `smart_scripts` SET `event_param1`=7000, `event_param2`=7000 WHERE `entryorguid`=626600 AND `id`=3;

-- Comments
UPDATE `smart_scripts` SET `comment`="Menara Voidrender - On Script - Remove Npc Flag Questgiver+Gossip" WHERE `entryorguid`=626600 AND `id`=0;
UPDATE `smart_scripts` SET `comment`="Menara Voidrender - On Script - Say Line 1" WHERE `entryorguid`=626600 AND `id`=1;
UPDATE `smart_scripts` SET `comment`="Menara Voidrender - On Script - Say Line 2" WHERE `entryorguid`=626600 AND `id`=3;
UPDATE `smart_scripts` SET `comment`="Menara Voidrender - On Script - Complete Quest 'The Completed Orb of Noh'Orahil'" WHERE `entryorguid`=626600 AND `id`=4;
UPDATE `smart_scripts` SET `comment`="Menara Voidrender - On Script - Complete Quest 'The Completed Orb of Dar'Orahil'" WHERE `entryorguid`=626600 AND `id`=5;
UPDATE `smart_scripts` SET `comment`="Menara Voidrender - On Script - On Script - Add Npc Flag Questgiver+Gossip" WHERE `entryorguid`=626600 AND `id`=6;
