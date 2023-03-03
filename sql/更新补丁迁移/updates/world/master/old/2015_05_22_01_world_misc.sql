update gameobject_template set data1 = 15 where entry = 207356;
update gameobject_template set data1 = 5 where entry = 207357;

delete from spell_trigger_dummy where spell_id in (92649, 92712);
INSERT INTO `spell_trigger_dummy` (`spell_id`, `spell_trigger`, `option`, `target`, `caster`, `targetaura`, `bp0`, `bp1`, `bp2`, `effectmask`, `aura`, `chance`, `group`, `check_spell_id`, `comment`) VALUES 
(92649, 92645, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 'Cauldron of Battle'),
(92712, 92652, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 'Big Cauldron of Battle');