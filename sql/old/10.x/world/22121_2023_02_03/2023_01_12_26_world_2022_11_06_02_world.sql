-- guessed values from yt videos
UPDATE `creature` SET `spawntimesecs`=120 WHERE `id` IN(34907, 34947);
DELETE FROM `creature_text` WHERE `creatureid` IN(34907, 34947);
INSERT INTO `creature_text` (`creatureid`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(34907, 0, 0, 'I shall draw your soul into the mist!', 12, 0, 100, 0, 0, 0, 24846, 'Kvaldir Harpooner'),
(34907, 0, 1, 'YAAARRRGH!', 12, 0, 100, 0, 0, 0, 24847, 'Kvaldir Harpooner'),
(34907, 0, 2, 'Be consumed by the mist!', 12, 0, 100, 0, 0, 0, 24848, 'Kvaldir Harpooner'),
(34907, 0, 3, 'Look what''s lost its way...', 12, 0, 100, 0, 0, 0, 24849, 'Kvaldir Harpooner'),
(34907, 0, 4, 'I will heave your carcass into the ocean myself!', 12, 0, 100, 0, 0, 0, 24850, 'Kvaldir Harpooner'),
(34907, 0, 5, 'You''re not even fit to be fed to Leviroth.', 12, 0, 100, 0, 0, 0, 24851, 'Kvaldir Harpooner'),
(34907, 0, 6, 'You''ve strayed too far from your comfortable soil, $N.', 12, 0, 100, 0, 0, 0, 24852, 'Kvaldir Harpooner'),
(34947, 0, 0, 'I shall draw your soul into the mist!', 12, 0, 100, 0, 0, 0, 24846, 'Kvaldir Berserker'),
(34947, 0, 1, 'YAAARRRGH!', 12, 0, 100, 0, 0, 0, 24847, 'Kvaldir Berserker'),
(34947, 0, 2, 'Be consumed by the mist!', 12, 0, 100, 0, 0, 0, 24848, 'Kvaldir Berserker'),
(34947, 0, 3, 'Look what''s lost its way...', 12, 0, 100, 0, 0, 0, 24849, 'Kvaldir Berserker'),
(34947, 0, 4, 'I will heave your carcass into the ocean myself!', 12, 0, 100, 0, 0, 0, 24850, 'Kvaldir Berserker'),
(34947, 0, 5, 'You''re not even fit to be fed to Leviroth.', 12, 0, 100, 0, 0, 0, 24851, 'Kvaldir Berserker'),
(34947, 0, 6, 'You''ve strayed too far from your comfortable soil, $N.', 12, 0, 100, 0, 0, 0, 24852, 'Kvaldir Berserker');

-- Kvaldir Harpooner
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 34907;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 34907 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(34907, 0, 0, 0, 1, 0, 100, 0, 0, 0, 10000, 10000, 49, 0, 0, 0, 0, 0, 0, 11, 35098, 30, 0, 0, 0, 0, 0, 'Kvaldir Harpooner - Out Of Combat - Attack Start'),
(34907, 0, 1, 0, 1, 0, 100, 0, 0, 0, 10000, 10000, 49, 0, 0, 0, 0, 0, 0, 11, 35070, 30, 0, 0, 0, 0, 0, 'Kvaldir Harpooner - Out Of Combat - Attack Start'),
(34907, 0, 2, 0, 0, 0, 100, 0, 0, 0, 2300, 3900, 11, 66489, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Kvaldir Harpooner - In Combat - Cast Spear Throw'),
(34907, 0, 3, 0, 0, 0, 20, 1, 5000, 5000, 0, 0, 1, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Kvaldir Harpooner - In Combat - Say Line 0');

-- Kvaldir Berserker
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 34947;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 34947 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(34947, 0, 0, 0, 1, 0, 100, 0, 0, 0, 10000, 10000, 49, 0, 0, 0, 0, 0, 0, 11, 35098, 30, 0, 0, 0, 0, 0, 'Kvaldir Harpooner - Out Of Combat - Attack Start'),
(34947, 0, 1, 0, 1, 0, 100, 0, 0, 0, 10000, 10000, 49, 0, 0, 0, 0, 0, 0, 11, 35070, 30, 0, 0, 0, 0, 0, 'Kvaldir Harpooner - Out Of Combat - Attack Start'),
(34947, 0, 2, 0, 0, 0, 100, 0, 1000, 1000, 8000, 11000, 11, 38557, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Kvaldir Berserker - In Combat - Cast Throw'),
(34947, 0, 3, 0, 9, 0, 100, 0, 0, 5, 5000, 7000, 11, 43410, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Kvaldir Berserker - Within 0-5 Range - Cast Chop'),
(34947, 0, 4, 0, 2, 0, 100, 1, 0, 30, 40000, 40000, 11, 3019, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Kvaldir Berserker - Between 0-30% Health - Cast Frenzy'),
(34947, 0, 5, 0, 0, 0, 20, 1, 5000, 5000, 0, 0, 1, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Kvaldir Berserker - In Combat - Say Line 0');
