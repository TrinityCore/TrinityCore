delete from spell_trigger where spell_id in (146068, 146189);
INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `spell_cooldown`, `option`, `target`, `caster`, `targetaura`, `bp0`, `bp1`, `bp2`, `effectmask`, `aura`, `chance`, `group`, `procFlags`, `procEx`, `check_spell_id`, `addptype`, `schoolMask`, `dummyId`, `dummyEffect`, `comment`) VALUES 
(146068, 146081, 0, 20, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 'OO: Blade of the Hundred Steps'),
(146189, 146190, 0, 9, 0, 0, 0, 150, 0, 0, 1, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 'OO: Eminence');