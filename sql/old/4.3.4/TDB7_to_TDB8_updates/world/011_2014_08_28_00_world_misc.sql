SET @ENTRY := 28511;

UPDATE `creature_template` SET `spell1`=51859,`spell2`=51904,`spell3`=52006,`spell4`=0,`spell5`=52694,`unit_flags`=16777224,`InhabitType`=5,`ScriptName`='npc_eye_of_acherus' WHERE `entry` = @ENTRY;

DELETE FROM `creature_template_addon` WHERE`entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(@ENTRY, 0, 0, 0x0, 0x1, 0, '51892');

DELETE FROM `waypoint_data` WHERE`id`=@ENTRY * 100;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@ENTRY * 100, 0, 2341.571, -5672.797, 538.3942, 0, 0, 1, 0, 100, 0),
(@ENTRY * 100, 1, 1957.396, -5844.105, 273.8667, 0, 0, 1, 0, 100, 0),
(@ENTRY * 100, 2, 1758.007, -5876.785, 166.8667, 0, 0, 1, 0, 100, 0);

DELETE FROM `creature_text` WHERE`entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(@ENTRY, 0, 0, 'The Eye of Acherus launches towards its destination.', 42, 0, 100, 0, 0, 0, 'Eye of Acherus'),
(@ENTRY, 1, 0, 'The Eye of Acherus is in your control.', 42, 0, 100, 0, 0, 0, 'Eye of Acherus');

DELETE FROM `spell_script_names` WHERE spell_id=52694;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(52694,'spell_q12641_recall_eye_of_acherus');
