UPDATE `creature_template` SET `ScriptName`= '' WHERE `entry`= 47305;

DELETE FROM `creature_text` WHERE `CreatureID`= 43873;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(43873, 0, 0, 'The wind abruptly shifts direction at %s'' command!', 41, 0, 100, 0, 0, 0, 47549, 'Altairus - Announce Call the Wind'),
(43873, 1, 0, '%s senses $n''s cowardice and unleashes a blast of lightning!', 16, 0, 100, 0, 0, 0, 47548, 'Altairus - Announce Lightning Blast');

DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_call_the_wind',
'spell_upwind_of_altairus',
'spell_call_the_wind_channel',
'spell_chilling_breath',
'spell_altairus_call_the_wind',
'spell_altairus_upwind_of_altairus',
'spell_altairus_call_the_wind_channel',
'spell_altairus_chilling_breath',
'spell_altairus_safe_area');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(88276, 'spell_altairus_call_the_wind'),
(88282, 'spell_altairus_upwind_of_altairus'),
(88772, 'spell_altairus_call_the_wind_channel'),
(88322, 'spell_altairus_chilling_breath'),
(88350, 'spell_altairus_safe_area');
