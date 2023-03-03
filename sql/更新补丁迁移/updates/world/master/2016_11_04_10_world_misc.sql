DELETE FROM `spell_aura_dummy` WHERE (`spellId`='107427') AND (`spellDummyId`='125154') AND (`option`='3') AND (`effectDummy`='0') AND (`effectmask`='7');

INSERT INTO `spell_learn_spell` (`entry`, `SpellID`) VALUES ('137022', '108561');
INSERT INTO `spell_learn_spell` (`entry`, `SpellID`) VALUES ('137022', '115697');
INSERT INTO `spell_learn_spell` (`entry`, `SpellID`) VALUES ('137022', '115689');
INSERT INTO `spell_learn_spell` (`entry`, `SpellID`) VALUES ('137022', '115694');
INSERT INTO `spell_learn_spell` (`entry`, `SpellID`) VALUES ('137022', '115696');

INSERT INTO `spell_aura_dummy` (`spellId`, `spellDummyId`, `caster`, `aura`, `effectmask`, `comment`) VALUES ('108561', '108561', '3', '125660', '1', 'Glyph of Jab');
INSERT INTO `spell_aura_dummy` (`spellId`, `spellDummyId`, `caster`, `aura`, `effectmask`, `comment`) VALUES ('115697', '115697', '3', '125660', '1', 'Glyph of Jab');
INSERT INTO `spell_aura_dummy` (`spellId`, `spellDummyId`, `caster`, `aura`, `effectmask`, `comment`) VALUES ('115689', '115689', '3', '125660', '1', 'Glyph of Jab');
INSERT INTO `spell_aura_dummy` (`spellId`, `spellDummyId`, `caster`, `aura`, `effectmask`, `comment`) VALUES ('115694', '115694', '3', '125660', '1', 'Glyph of Jab');
INSERT INTO `spell_aura_dummy` (`spellId`, `spellDummyId`, `caster`, `aura`, `effectmask`, `comment`) VALUES ('115696', '115696', '3', '125660', '1', 'Glyph of Jab');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('125660', 'spell_monk_glyph_of_jab');