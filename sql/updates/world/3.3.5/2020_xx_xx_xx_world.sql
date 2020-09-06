-- Nerub'ar broodkeep start event
DELETE FROM `areatrigger_scripts` WHERE `entry` IN (5611,5612);
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(5611, 'at_icc_nerubar_broodkeeper'),
(5612, 'at_icc_nerubar_broodkeeper');