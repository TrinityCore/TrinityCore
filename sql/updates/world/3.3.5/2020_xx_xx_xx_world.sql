-- Nerub'ar broodkeep start event
DELETE FROM `areatrigger_scripts` WHERE `entry` IN (5611,5612);
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(5611, 'at_icc_nerubar_broodkeeper'),
(5612, 'at_icc_nerubar_broodkeeper');

-- Delete Nerub'ar Broodkeeper SmartAI
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 36725;

-- Update Nerub'ar Broodkeeper for script
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_nerubar_broodkeeper' WHERE `entry` = 36725;
