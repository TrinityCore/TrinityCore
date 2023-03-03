delete from spell_linked_spell where spell_effect in (146120, 146128, -146128, -146120, -147923, -146122, -146127, -147925);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `caster`, `target`, `hastalent`, `hastalent2`, `chance`, `cooldown`, `type2`, `hitmask`, `learnspell`, `comment`) VALUES 
(-23920, -146120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Remove visual effect'),
(-23920, -146122, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Remove visual effect'),
(-23920, -147923, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Remove visual effect'),
(-871, -146128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Remove visual effect'),
(-871, -146127, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Remove visual effect'),
(-871, -147925, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Remove visual effect');

delete from spell_script_names where ScriptName = 'spell_warr_shield_visual';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(871, 'spell_warr_shield_visual'),
(23920, 'spell_warr_shield_visual');