INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('57755', 'spell_warr_heroic_throw');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('134967', 'spell_warr_heroic_throw_glyph');

INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `caster`, `target`, `comment`) VALUES ('5384', '-51755', '10', '10', 'Camouflage Remove');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `caster`, `comment`) VALUES ('1462', '-51755', '10', 'Camouflage Remove');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `caster`, `comment`) VALUES ('6197', '-51755', '10', 'Camouflage Remove');

INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `target`, `comment`) VALUES ('120694', '82716', '5', 'Dire Beast Focus Driver');
UPDATE `spell_trigger` SET `caster`='4' WHERE (`spell_id`='120694') AND (`spell_trigger`='82716') AND (`option`='0') AND (`effectmask`='7') AND (`aura`='0') AND (`check_spell_id`='0');

INSERT INTO `spell_target_filter` (`spellId`, `targetId`, `option`, `addcaster`, `comments`) VALUES ('81280', '30', '16', '-1', 'Blood Burst');