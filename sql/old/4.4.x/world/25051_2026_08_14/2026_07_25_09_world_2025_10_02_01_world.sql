-- Template
DELETE FROM `smart_scripts` WHERE `entryorguid`= 34981;
UPDATE `creature_template` SET `AIName`= '', `ScriptName`= 'npc_frightened_citizen' WHERE `entry` IN (34981, 35836);

-- Rampaging Worgen fixups
UPDATE `creature_template` SET `flags_extra` = `flags_extra` | 2 WHERE `entry`= 34884;

-- SpellScriptName
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_gilneas_knocking');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(67869, 'spell_gilneas_knocking');

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` IN (34981, 35836);
INSERT INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(34981, 0, 0, 'What in the world?  Let''s get out of here!', 12, 0, 100, 1, 0, 0, 35235, 'Frightened Citizen to Player'),
(34981, 0, 1, 'Let''s go!', 12, 0, 100, 1, 0, 0, 35236, 'Frightened Citizen to Player'),
(34981, 0, 2, 'No time to waste!', 12, 0, 100, 1, 0, 0, 35237, 'Frightened Citizen to Player'),
(34981, 0, 3, 'Worgen!  Worgen everywhere!', 12, 0, 100, 1, 0, 0, 35238, 'Frightened Citizen to Player'),
(34981, 0, 4, 'Flee!  They''re everywhere!', 12, 0, 100, 1, 0, 0, 35240, 'Frightened Citizen to Player'),
(34981, 0, 5, 'This place isn''t safe.  Let''s leave!', 12, 0, 100, 1, 0, 0, 35239, 'Frightened Citizen to Player'),
(34981, 0, 6, 'Protect me, please!', 12, 0, 100, 1, 0, 0, 35234, 'Frightened Citizen to Player'),
(35836, 0, 0, 'It''s coming right for me!!', 12, 0, 100, 1, 0, 0, 36037, 'Frightened Citizen to Player'),
(35836, 0, 1, 'Help me, please!', 12, 0, 100, 1, 0, 0, 36038, 'Frightened Citizen to Player'),
(35836, 0, 2, 'There''s one after me!', 12, 0, 100, 1, 0, 0, 36039, 'Frightened Citizen to Player'),
(35836, 0, 3, 'Help!', 12, 0, 100, 1, 0, 0, 36040, 'Frightened Citizen to Player'),
(35836, 0, 4, 'I don''t want to die!', 12, 0, 100, 1, 0, 0, 36041, 'Frightened Citizen to Player');
