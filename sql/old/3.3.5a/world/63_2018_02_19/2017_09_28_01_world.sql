-- 
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (25464, 25467, 25468);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (25464, 25467, 25468) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=25470 AND `source_type`=0 AND `id` BETWEEN 2 AND 6;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2546700 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(25464, 0, 0, 1, 4, 0, 100, 0, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Bloodspore Moth - On Aggro - Store target"),
(25464, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 100, 1, 0, 0, 0, 0, 0, 19, 25470, 20, 0, 0, 0, 0, 0, "Bloodspore Moth - On Aggro - Send target to (Bloodspore Firestarter"),
(25464, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 100, 1, 0, 0, 0, 0, 0, 19, 25467, 20, 0, 0, 0, 0, 0, "Bloodspore Moth - On Aggro - Send target to (Bloodspore Harvester"),
(25464, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 25470, 20, 0, 0, 0, 0, 0, "Bloodspore Moth - On Aggro - Set Data 1 1 (Bloodspore Firestarter"),
(25464, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 25467, 20, 0, 0, 0, 0, 0, "Bloodspore Moth - On Aggro - Set Data 1 1 (Bloodspore Harvester"),
(25464, 0, 5, 0, 0, 0, 100, 0, 10000, 15000, 20000, 30000, 11, 45610, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Bloodspore Moth - In Combat - Cast Spell 'Pollen'"),
(25464, 0, 6, 0, 0, 0, 100, 0, 20000, 30000, 20000, 30000, 11, 32914, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Bloodspore Moth - In Combat - Cast Spell 'Wing Buffet'"),
(25467, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Bloodspore Harvester - On Reset - Set Event Phase 1"),
(25467, 0, 1, 2, 4, 1, 30, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Bloodspore Harvester - On Aggro - Say Line 0 (Phase 1)"),
(25467, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Bloodspore Harvester - On Aggro - Set Event Phase 2"),
(25467, 0, 3, 0, 0, 0, 100, 0, 10000, 20000, 10000, 20000, 11, 50380, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Bloodspore Harvester - In Combat - Cast Spell 'Bloodspore Haze'"),
(25467, 0, 4, 5, 38, 1, 100, 0, 1, 1, 0, 0, 80, 2546700, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Bloodspore Harvester - On Data 1 1 Set - Run Script (Phase 1)"),
(25467, 0, 5, 0, 61, 1, 100, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Bloodspore Harvester - On Data 1 1 Set - Set Event Phase 2 (Phase 1)"),
(25468, 0, 0, 0, 0, 0, 100, 0, 10000, 20000, 20000, 30000, 11, 50402, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Bloodspore Roaster - In Combat - Cast Spell 'Roast'"),
(25470, 0, 2, 0, 25, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Bloodspore Firestarter - On Reset - Set Event Phase 1"),
(25470, 0, 3, 4, 4, 1, 30, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Bloodspore Firestarter - On Aggro - Say Line 0 (Phase 1)"),
(25470, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Bloodspore Firestarter - On Aggro - Set Event Phase 2"),
(25470, 0, 5, 6, 38, 1, 100, 0, 1, 1, 0, 0, 80, 2546700, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Bloodspore Firestarter - On Data 1 1 Set - Run Script"),
(25470, 0, 6, 0, 61, 1, 100, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Bloodspore Firestarter - On Data 1 1 Set - Set Event Phase 2 (Phase 1)"),
(2546700, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 22, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Bloodspore Harvester/Firestarter - On Script - Set Event Phase 3"),
(2546700, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Bloodspore Harvester/Firestarter - On Script - Say Line 1"),
(2546700, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 49, 0, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, "Bloodspore Harvester/Firestarter - On Script - Start attack");

DELETE FROM `creature_text` WHERE `CreatureID` IN (25467, 25470);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(25467, 0, 0, "No hurt the lifegiver!", 12, 0, 100, 0, 0, 0, 24689, 0, "Bloodspore Harvester"),
(25467, 0, 1, "No touch spores!", 12, 0, 100, 0, 0, 0, 24690, 0, "Bloodspore Harvester"),
(25467, 1, 0, "Protect the lifegiver!", 14, 0, 100, 0, 0, 0, 24695, 0, "Bloodspore Harvester"),
(25470, 0, 0, "No hurt the lifegiver!", 12, 0, 100, 0, 0, 0, 24689, 0, "Bloodspore Firestarter"),
(25470, 1, 0, "Protect the lifegiver!", 14, 0, 100, 0, 0, 0, 24695, 0, "Bloodspore Firestarter");
