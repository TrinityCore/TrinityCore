DELETE FROM spell_pet_auras WHERE petEntry IN (54569) and spellId IN (124416);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('119053', 'spell_monk_transcendence_clone_visual');

DELETE FROM spell_target_filter WHERE spellId IN (80265);
insert into `spell_target_filter` (`spellId`, `targetId`, `option`, `param1`, `param2`, `param3`, `aura`, `chance`, `effectMask`, `resizeType`, `count`, `maxcount`, `addcount`, `addcaster`, `comments`) values
('80265','7','3','0','16','0','0','0','7','0','1','0','0','2','Зелье иллюзии'),
('80265','7','4','0','0','0','0','0','7','0','0','0','0','2','Зелье иллюзии');

insert into `spell_proc_check` (`entry`, `entry2`, `entry3`, `checkspell`, `hastalent`, `chance`, `target`, `effectmask`, `powertype`, `dmgclass`, `specId`, `spellAttr0`, `targetTypeMask`, `mechanicMask`, `fromlevel`, `perchp`, `spelltypeMask`, `combopoints`, `deathstateMask`, `hasDuration`, `comment`) values
('114015','0','0','-121471','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Предчувствие');

insert into `spell_proc_event` (`entry`, `procFlags`) values
('2823','4194580'),
('3408','8388884'),
('5761','8388884'),
('8679','4194580'),
('108211','8388884'),
('108215','8388884'),
('129410','4194580'),
('129412','4194580'),
('129413','8388884'),
('145421','4194580');

DELETE FROM spell_proc_event WHERE entry IN (56636);
insert into `spell_proc_event` (`entry`, `procEx`) values('56636','19');

DELETE FROM spell_script_names WHERE ScriptName IN ('spell_warr_t16_dps_2p');

insert into `spell_trigger` (`spell_id`, `spell_trigger`, `option`, `targetaura`, `aura`, `comment`) values(
'144436','144438','20','2','86346','Item - Warrior T16 DPS 2P Bonus');

DELETE FROM spell_proc_check WHERE entry IN (20154, 31801, 44448);
INSERT INTO `spell_proc_check` (`entry`, `entry2`, `entry3`, `checkspell`, `hastalent`, `chance`, `target`, `effectmask`, `powertype`, `dmgclass`, `specId`, `spellAttr0`, `targetTypeMask`, `mechanicMask`, `fromlevel`, `perchp`, `spelltypeMask`, `combopoints`, `deathstateMask`, `hasDuration`, `comment`) VALUES
('20154','20164','20165','0','0','0','0','7','-1','-1','0','0','0','0','0','0','-4','0','0','0','Печать праведности'),
('31801','0','0','-24275','0','0','0','1','-1','-1','0','0','0','0','0','0','0','0','0','0','Печать правды'),
('31801','0','0','0','0','0','0','4','-1','-1','0','0','0','0','0','0','-4','0','0','0','Печать правды'),
('44448','0','0','0','0','0','0','7','-1','-1','0','0','0','0','0','0','-4','0','0','0','Ясность мысли Огненная глыба');

DELETE FROM spell_trigger WHERE spell_id IN (31801);
INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `option`, `bp0`, `effectmask`, `comment`) VALUES
('31801','31803','20','0','4','Paladin - Seal of Truth - Dot Aura'),
('31801','42463','1','12','1','Paladin - Seal of Truth - Weapon Dmg');
