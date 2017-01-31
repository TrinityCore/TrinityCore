-- GM Freeze Spell Script
DELETE FROM `spell_script_names` WHERE `spell_id`=9454;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (9454, 'spell_gen_gm_freeze');

-- Update Command Help
UPDATE `command` SET `help`='Syntax: .freeze [#player] [#duration]
Freezes #player for #duration (seconds)
Freezes the selected player if no arguments are given.
Default duration: GM.FreezeAuraDuration (worldserver.conf)' WHERE `name`='freeze';

-- Add new string to show the duration on the freeze upon using .listfreeze
DELETE FROM `trinity_string` WHERE `entry`=5019;
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES
(5019, '| %s - Status: %d seconds left');

-- Update old string to show if the duration is permanent
UPDATE `trinity_string` SET `content_default`='| %s - Status: Permanently frozen' WHERE `entry`=5006;
