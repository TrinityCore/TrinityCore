delete from spell_linked_spell where spell_trigger in (-93520, 93520);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `caster`, `target`, `hastalent`, `hastalent2`, `chance`, `cooldown`, `type2`, `hitmask`, `learnspell`, `removeMask`, `comment`) VALUES 
(-93520, -93566, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Remove Pistol Barrage'),
(93520, 93566, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Apply Pistol Barrage');

delete from spell_target_filter where spellId = 93564;
INSERT INTO `spell_target_filter` (`spellId`, `targetId`, `option`, `param1`, `param2`, `param3`, `aura`, `chance`, `effectMask`, `resizeType`, `count`, `maxcount`, `addcount`, `addcaster`, `comments`) VALUES 
(93564, 60, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, -1, 'Pistol Barrage');

delete from spell_script_names where spell_id = 93520;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (93520, 'spell_pistol_barrage');

update creature_template set exp = 3, ScriptName = 'npc_bloodthirsty_ghoul' where entry = 50561;