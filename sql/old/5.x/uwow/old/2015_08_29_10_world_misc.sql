DELETE FROM `spell_proc_event` WHERE (`entry`='108281') AND (`effectmask`='7');
DELETE FROM `spell_trigger` WHERE `spell_id` IN (108281);
INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `option`, `bp0`, `effectmask`, `procFlags`, `comment`) VALUES ('108281', '114911', '9', '40', '1', '65536', 'Ancestral Guidance');
INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `option`, `bp0`, `effectmask`, `procFlags`, `comment`) VALUES ('108281', '114911', '9', '60', '2', '16384', 'Ancestral Guidance');