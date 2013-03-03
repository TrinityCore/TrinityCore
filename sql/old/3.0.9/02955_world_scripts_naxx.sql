INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(-28169, 28206,  0, 'Mutating Injection - Mutagen Explosion'),
(-28169, 28240,  0, 'Mutating Injection - Poison Cloud');

UPDATE creature_template SET spell1 = 28158, spell2 = 54362, flags_extra = 128 WHERE entry = 16363;

UPDATE creature_template SET scriptname = 'boss_grobbulus' WHERE entry = 15931;
