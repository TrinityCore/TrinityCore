UPDATE `spell_trigger` SET `targetaura`='1' WHERE (`spell_id`='120267') AND (`spell_trigger`='132365') AND (`option`='24') AND (`effectmask`='7') AND (`aura`='115069') AND (`check_spell_id`='0');

INSERT INTO `spell_pet_auras` (`petEntry`, `spellId`, `option`, `target`, `comment`) VALUES ('54985', '84840', '5', '2', 'Сила Природы - Отмщение');
UPDATE `spell_trigger` SET `targetaura`='1' WHERE (`spell_id`='84840') AND (`spell_trigger`='132365') AND (`option`='24') AND (`effectmask`='7') AND (`aura`='5487') AND (`check_spell_id`='0');

INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `hastype`, `hitmask`, `comment`) VALUES ('5246', '-3', '9', '1', 'Intimidating Shout');
UPDATE `spell_linked_spell` SET `actiontype`='2' WHERE `spell_trigger`='5246' AND `spell_effect`='-3';