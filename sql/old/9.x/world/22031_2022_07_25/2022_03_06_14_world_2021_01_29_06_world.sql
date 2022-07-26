--
DELETE FROM `areatrigger_scripts` WHERE `entry`IN(5174,5175,5176);
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES 
(5174, 'SmartTrigger'),
(5175, 'SmartTrigger'),
(5176, 'SmartTrigger');

DELETE FROM `smart_scripts` WHERE `entryorguid`IN(5174,5175,5176) AND `source_type`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(5174, 2, 0, 0, 46, 0, 100, 0, 5174, 0, 0, 0, 0, 33, 29455, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Areatrigger - On Trigger - Quest Credit 'That's What Friends Are For...' (Gerk)"),
(5175, 2, 0, 0, 46, 0, 100, 0, 5175, 0, 0, 0, 0, 33, 29454, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Areatrigger - On Trigger - Quest Credit 'That's What Friends Are For...' (Burr)"),
(5176, 2, 0, 0, 46, 0, 100, 0, 5176, 0, 0, 0, 0, 33, 29468, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Areatrigger - On Trigger - Quest Credit 'That's What Friends Are For...' (Crusader Dargoth)");

UPDATE `creature_template` SET `AIName`='' WHERE  `entry` IN(29455,29454,29468);

DELETE FROM `smart_scripts` WHERE  `entryorguid` IN(29455,29454,29468) AND `source_type`=0;
