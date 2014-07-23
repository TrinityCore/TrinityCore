--
UPDATE `creature_template` SET `ainame`='SmartAI' WHERE `entry` IN (24786,24797);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (24786,24797) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(24786, 0, 0, 1, 8, 0, 100, 0, 44454, 0, 0, 0, 29, 0, 0, 24797, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Reef Bull - On Spell Hit - Follow Invoker'),
(24786, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Reef Bull - Link - Store Target List'),
(24786, 0, 2, 3, 65, 0, 100, 0, 0, 0, 0, 0, 11, 52148, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Reef Bull - On Follow Complete - Cast 52148'),
(24786, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 29, 0, 0, 0, 0, 0, 0, 19, 24797, 10, 0, 0, 0, 0, 0, 'Reef Bull - Link With Event 1 - Follow Reef Cow'),
(24786, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 19, 24797, 10, 0, 0, 0, 0, 0, 'Reef Bull - Link With Event 2 - Set Data 0 1'),
(24786, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 15, 11472, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Reef Bull -Link With Event 3 - Give Quest Credit'),


(24797, 0, 0, 1, 38, 0, 100, 0, 0, 1, 0, 0, 11, 52148, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Reef Cow - On Data Set 0 1 - Cast 52148'),
(24797, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 24786, 0, 0, 0, 0, 0, 0, 'Reef Cow - Link With Event 0 - Set orientation'),
(24797, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 4200, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Reef Cow - Link With Event 2 - Despawn');

DELETE FROM `spell_scripts` WHERE `id`=21014;
INSERT INTO `spell_scripts` (`id`, `effIndex`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
(21014, 0, 0, 17, 34127, 1, 0, 0, 0, 0, 0);
