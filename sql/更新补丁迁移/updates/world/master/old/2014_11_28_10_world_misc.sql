INSERT INTO `spell_talent_linked_spell` (`spellid`, `spelllink`, `type`, `comment`) VALUES ('29838', '16491', '1', 'Второе дыхание');
INSERT INTO `spell_talent_linked_spell` (`spellid`, `spelllink`, `type`, `comment`) VALUES ('-29838', '-16491', '1', 'Второе дыхание');

DELETE FROM `spell_script_names` WHERE (`spell_id`='29838') AND (`ScriptName`='spell_warr_second_wind');