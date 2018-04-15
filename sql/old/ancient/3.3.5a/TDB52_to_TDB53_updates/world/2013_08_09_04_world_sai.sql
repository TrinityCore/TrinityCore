UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` =23162;

DELETE FROM `creature_ai_scripts` WHERE `creature_id` =23162;
DELETE FROM `smart_scripts` WHERE `entryorguid` =23162 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23162, 0, 0,1,11,0, 100, 0, 0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Vakkiz the Windrager - On Spawn - Say Emote'),
(23162, 0, 1,2,61,0, 100, 0, 0,0,0,0,19,33088,0,0,0,0,0,1,0,0,0,0,0,0,0,'Vakkiz the Windrager - Linked with Previous Event - Set Unit Flags'),
(23162, 0, 2,0,61,0, 100, 0, 0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Vakkiz the Windrager - Linked with Previous Event - Set Phase 1'),
(23162, 0, 3,0, 0,1, 100, 0, 6500,9500,8500,11500,11,40420,0,0,0,0,0,2,0,0,0,0,0,0,0,'Vakkiz the Windrager - IC - Cast Lightning Breath (Phase 1)'),
(23162, 0, 4,5, 2,1, 100, 0, 0,40,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Vakkiz the Windrager - On 40% HP - Say Emote'),
(23162, 0, 5,6,61,1, 100, 0, 0,0,0,0,3,0,21296,0,0,0,0,1,0,0,0,0,0,0,0,'Vakkiz the Windrager - Linked with Previous Event - Change Model'),
(23162, 0, 6,0,61,1, 100, 0, 0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Vakkiz the Windrager - Linked with Previous Event - Set Phase 2'),
(23162, 0, 7,0, 0,2, 100, 0, 3000,7000,5000,9000,11,40419,0,0,0,0,0,1,0,0,0,0,0,0,0,'Vakkiz the Windrager - IC - Cast Bone Spray (Phase 2)'),
(23162, 0, 8,9, 7,0, 100, 0, 0,0,0,0,19,33088,0,0,0,0,0,1,0,0,0,0,0,0,0,'Vakkiz the Windrager - On Evade - Set Unit Flags'),
(23162, 0, 9,10,61,0, 100, 0, 0,0,0,0,3,0,20837,0,0,0,0,1,0,0,0,0,0,0,0,'Vakkiz the Windrager - Linked with Previous Event - Set Model'),
(23162, 0,10,0,61,0, 100, 0, 0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Vakkiz the Windrager - Linked with Previous Event - Set Phase 1');

DELETE FROM `creature_text` WHERE `entry` =23162;
DELETE FROM `creature_ai_texts` WHERE `entry` IN (-234,-235);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(23162, 0, 0, 'Furious winds envelop Vakkiz as he writhes menacingly towards you.', 16, 0, 100, 0, 0, 0, 'Vakkiz the Windrager'),
(23162, 1, 0, '%s''s flesh shatters in an unearthly rage!', 16, 0, 100, 0, 0, 0, 'Vakkiz the Windrager');
