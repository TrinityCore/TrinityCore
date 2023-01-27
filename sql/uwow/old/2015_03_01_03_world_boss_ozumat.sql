delete from spell_area where spell in (76133,76155);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
(76133, 5004, 0, 0, 0, 0, 2, 0, 64, 11),
(76155, 5004, 0, 0, 0, 0, 2, 0, 64, 11);

delete from creature where id = 44566;

update creature_template set ScriptName = 'npc_ozumat' where entry = 44566;
update creature_template set flags_extra = 130, ScriptName = 'npc_blight_of_ozumat_final' where entry = 44834;

delete from spell_linked_spell where spell_trigger in (-76133, 76133);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `caster`, `target`, `hastalent`, `hastalent2`, `chance`, `cooldown`, `type2`, `hitmask`, `learnspell`, `removeMask`, `comment`) VALUES 
(-76133, -76155, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Remove Tidal Surge'),
(76133, 76155, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Add Tidal Surge');