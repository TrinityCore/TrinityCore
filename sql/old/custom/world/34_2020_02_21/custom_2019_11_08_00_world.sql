DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_warr_devastate';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(20243, 'spell_warr_devastate');

DELETE FROM `spell_bonus_data` WHERE `entry`= 53351;
INSERT INTO `spell_bonus_data` (`entry`, `ap_bonus`, `comments`) VALUES
(53351, 0.45, 'Hunter - Kill Shot');
