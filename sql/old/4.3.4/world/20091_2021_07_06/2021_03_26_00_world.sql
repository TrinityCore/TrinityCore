DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_deepholm_intro_teleport';

DELETE FROM `spell_area` WHERE `spell`= 84101;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES
(84101, 5042, 0, 0, 84073, 0, 2, 0x1, 64, 11);
