-- Nerub'ar broodkeep
DELETE FROM `areatrigger_scripts` WHERE `entry` IN (5611,5612);
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(5611, 'at_icc_nerubar_broodkeeper'),
(5612, 'at_icc_nerubar_broodkeeper');

DELETE FROM `smart_scripts` WHERE `entryorguid`=36725;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_icc_nerubar_broodkeeper' WHERE `entry`=36725;
UPDATE `creature_template` SET `flags_extra`=512 WHERE `entry` IN (36725,38058);
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry` IN (36725,38058);
UPDATE `creature_template_movement` SET `Flight`=0, `Ground`=1 WHERE `CreatureId` IN (36725,38058);
