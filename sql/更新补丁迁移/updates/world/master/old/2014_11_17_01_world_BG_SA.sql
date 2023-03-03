update gameobject_template set data5 = 18000 where entry in (190722,190723,190724,190726,190727);
update gameobject_template set data5 = 15000 where entry = 192549;

delete from spell_radius where spell_id = 60206;
INSERT INTO `spell_radius` (`spell_id`, `effectradius0`, `effectradius1`, `effectradius2`, `effectradius3`, `effectradius4`, `comments`) VALUES 
(60206, 0, 0, 8, 0, 0, '5 yard - Spell From Battleground Demolisher');

delete from spell_linked_spell where spell_effect = '-52415';
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `caster`, `target`, `hastalent`, `hastalent2`, `chance`, `cooldown`, `type2`, `hitmask`, `learnspell`, `comment`) VALUES 
(52410, -52415, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Carrying Seaforium - Remove2');