-- Fix quest 14107: The Fate Of The Fallen
-- Add SmartAI for Fallen Hero's Spirit

SET @ENTRY := 32149;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE creature_id = @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, 8, 0, 100, 1, 66719, 0, 0, 0, 80, @ENTRY*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fallen Hero''s Spirit - On Spellhit Blessing of Peace - Run script'),
(@ENTRY*100, 9, 0, 0, 0, 0, 100, 0, 100, 100, 0, 0, 66, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Fallen Hero''s Spirit - Script - Turn to Invoker'),
(@ENTRY*100, 9, 1, 0, 0, 0, 100, 0, 100, 100, 0, 0, 33, 35055, 0, 0, 0, 0, 0, 16, 0, 0, 0, 0, 0, 0, 0, 'Fallen Hero''s Spirit - Script - Give Quest Credit'),
(@ENTRY*100, 9, 2, 0, 0, 0, 100, 0, 100, 100, 0, 0, 2, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fallen Hero''s Spirit - Script - Set Faction'),
(@ENTRY*100, 9, 3, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fallen Hero''s Spirit - Script - Say 0'),
(@ENTRY*100, 9, 4, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Fallen Hero''s Spirit - Script - Despawn');

-- Creature text for Fallen Hero's Spirit
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY, 0, 0, 'It was awful... I dreamt I was fighting against my friends.', 12, 0, 100, 1, 0, 0, 'Fallen Hero''s Spirit'),
(@ENTRY, 0, 1, 'I''m so tired. Just let me rest for a moment.',               12, 0, 100, 1, 0, 0, 'Fallen Hero''s Spirit'),
(@ENTRY, 0, 2, 'I can''t hear the screams anymore. Is this the end?',         12, 0, 100, 1, 0, 0, 'Fallen Hero''s Spirit'),
(@ENTRY, 0, 3, 'At last... now I can rest.',                                  12, 0, 100, 1, 0, 0, 'Fallen Hero''s Spirit'),
(@ENTRY, 0, 4, 'My nightmare, is it finally over?',                           12, 0, 100, 1, 0, 0, 'Fallen Hero''s Spirit');
