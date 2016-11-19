-- Adds a script for Naxxramas Anub corpse scarab summoning spell 29105 28864
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_anubrekhan_summon_corpse_scarabs';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(28864, 'spell_anubrekhan_summon_corpse_scarabs'),
(29105, 'spell_anubrekhan_summon_corpse_scarabs');
