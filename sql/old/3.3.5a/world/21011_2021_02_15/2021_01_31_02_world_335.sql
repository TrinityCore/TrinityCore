--
DELETE FROM `areatrigger_scripts` WHERE `entry`IN(4725,4724,4726);
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES 
(4725, 'SmartTrigger'),
(4724, 'SmartTrigger'),
(4726, 'SmartTrigger');

DELETE FROM `smart_scripts` WHERE `entryorguid`IN(4725,4724,4726) AND `source_type`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(4725, 2, 0, 0, 46, 0, 100, 0, 4725, 0, 0, 0, 0, 33, 23814, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Areatrigger - On Trigger - Quest Credit 'X Marks... Your Doom!'' (Zul'Aman - Eagle God Invisman)"),
(4726, 2, 0, 0, 46, 0, 100, 0, 4726, 0, 0, 0, 0, 33, 23815, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Areatrigger - On Trigger - Quest Credit 'X Marks... Your Doom!'' (Zul'Aman - Lynx God Invisman)"),
(4724, 2, 0, 0, 46, 0, 100, 0, 4724, 0, 0, 0, 0, 33, 23813, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Areatrigger - On Trigger - Quest Credit 'X Marks... Your Doom!' (Zul'Aman - Dragonhawk God Invisman)");

UPDATE `creature_template` SET `AIName`='' WHERE  `entry` IN(23814,23815,23813);

DELETE FROM `smart_scripts` WHERE  `entryorguid` IN(23814,23815,23813) AND `source_type`=0;
