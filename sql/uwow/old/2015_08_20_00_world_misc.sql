delete from spell_aura_dummy where spellId = 5246;
insert into `spell_aura_dummy` (`spellId`, `spellDummyId`, `option`, `target`, `caster`, `targetaura`, `aura`, `removeAura`, `effectDummy`, `effectmask`, `chance`, `attr`, `attrValue`, `custombp`, `specId`, `comment`) values('5246','63327','4','0','0','0','0','0','0','10','0','0','0','0','0','Устрашающий крик');
delete from spell_aura_dummy where spellId = 8122;
insert into `spell_aura_dummy` (`spellId`, `spellDummyId`, `option`, `target`, `caster`, `targetaura`, `aura`, `removeAura`, `effectDummy`, `effectmask`, `chance`, `attr`, `attrValue`, `custombp`, `specId`, `comment`) values('8122','55676','4','0','0','0','0','0','0','2','0','0','0','0','0','Символ ментального крика');
insert into `spell_aura_dummy` (`spellId`, `spellDummyId`, `option`, `target`, `caster`, `targetaura`, `aura`, `removeAura`, `effectDummy`, `effectmask`, `chance`, `attr`, `attrValue`, `custombp`, `specId`, `comment`) values('113792','55676','4','0','0','2','0','0','0','2','0','0','0','0','0','Сверхъестественный ужас');

INSERT INTO `spell_proc_check` (`entry`, `entry2`, `entry3`, `checkspell`, `hastalent`, `chance`, `target`, `effectmask`, `powertype`, `dmgclass`, `specId`, `spellAttr0`, `targetTypeMask`, `mechanicMask`, `fromlevel`, `perchp`, `spelltypeMask`, `combopoints`, `deathstateMask`, `hasDuration`, `comment`) VALUES('109186','0','0','63544','0','15','0','7','-1','-1','-258','0','0','0','0','0','0','0','0','0','Свет и тьма');
INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `spell_cooldown`, `option`, `target`, `caster`, `targetaura`, `bp0`, `bp1`, `bp2`, `effectmask`, `aura`, `chance`, `group`, `procFlags`, `procEx`, `check_spell_id`, `addptype`, `schoolMask`, `dummyId`, `dummyEffect`, `comment`) VALUES('109186','114255','0','13','0','0','0','0','0','0','7','63544','0','0','0','0','0','-1','0','0','0','Свет и Тьма тригер Пробуждение Света');

INSERT IGNORE INTO `spell_proc_check` (`entry`, `entry2`, `entry3`, `checkspell`, `hastalent`, `chance`, `target`, `effectmask`, `powertype`, `dmgclass`, `specId`, `spellAttr0`, `targetTypeMask`, `mechanicMask`, `fromlevel`, `perchp`, `spelltypeMask`, `combopoints`, `deathstateMask`, `hasDuration`, `comment`) VALUES
('77486','0','0','129197','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Mastery: Shadowy Recall'),
('77486','0','0','15407','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Mastery: Shadowy Recall'),
('77486','0','0','589','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Mastery: Shadowy Recall'),
('77486','0','0','34914','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Mastery: Shadowy Recall'),
('77486','0','0','2944','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Mastery: Shadowy Recall'),
('77486','0','0','49821','0','0','0','7','-1','-1','0','0','0','0','0','0','0','0','0','0','Mastery: Shadowy Recall');

INSERT IGNORE INTO `spell_trigger` (`spell_id`, `spell_trigger`, `spell_cooldown`, `option`, `target`, `caster`, `targetaura`, `bp0`, `bp1`, `bp2`, `effectmask`, `aura`, `chance`, `group`, `procFlags`, `procEx`, `check_spell_id`, `addptype`, `schoolMask`, `dummyId`, `dummyEffect`, `comment`) VALUES
('77486','124468','0','20','0','0','0','0','0','0','7','0','200','0','0','0','129197','-1','0','0','0','Mastery: Shadowy Recall'),
('77486','124468','0','20','0','0','0','0','0','0','7','0','200','0','0','0','15407','-1','0','0','0','Mastery: Shadowy Recall'),
('77486','124464','0','20','0','0','0','0','0','0','7','0','200','0','0','0','589','-1','0','0','0','Mastery: Shadowy Recall'),
('77486','124465','0','20','0','0','0','0','0','0','7','0','200','0','0','0','34914','-1','0','0','0','Mastery: Shadowy Recall'),
('77486','124467','0','20','0','0','0','0','0','0','7','0','200','0','0','0','2944','-1','0','0','0','Mastery: Shadowy Recall'),
('77486','124469','0','20','0','0','0','0','0','0','7','0','200','0','0','0','49821','-1','0','0','0','Mastery: Shadowy Recall');
insert into `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `SpellFamilyMask3`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`, `effectmask`) values('77486','0','0','0','0','0','0','327680','3','0','0','0','7');

insert into `spell_script_names` (`spell_id`, `ScriptName`) values('124467','spell_pri_devouring_plague_mastery');

delete from spell_proc_event where entry = 78203;
insert into `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `SpellFamilyMask3`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`, `effectmask`) values('78203','0','0','0','0','0','0','327680','2','0','0','0','7');

ALTER TABLE `areatrigger_data`
  ADD COLUMN `MorphCurveID` INT(11) DEFAULT 0  NOT NULL AFTER `ElapsedTime`,
  ADD COLUMN `FacingCurveID` INT(11) DEFAULT 0  NOT NULL AFTER `MorphCurveID`,
  ADD COLUMN `ScaleCurveID` INT(11) DEFAULT 0  NOT NULL AFTER `FacingCurveID`,
  ADD COLUMN `HasFollowsTerrain` INT(11) DEFAULT 0  NOT NULL AFTER `ScaleCurveID`,
  ADD COLUMN `HasAttached` INT(11) DEFAULT 0  NOT NULL AFTER `HasFollowsTerrain`,
  ADD COLUMN `HasAbsoluteOrientation` INT(11) DEFAULT 0  NOT NULL AFTER `HasAttached`,
  ADD COLUMN `HasDynamicShape` INT(11) DEFAULT 0  NOT NULL AFTER `HasAbsoluteOrientation`,
  ADD COLUMN `HasFaceMovementDir` INT(11) DEFAULT 0  NOT NULL AFTER `HasDynamicShape`;

delete from areatrigger_data where entry in (1204,1265);
insert into `areatrigger_data` (`entry`, `spellId`, `customEntry`, `customVisualId`, `Radius`, `RadiusTarget`, `Height`, `HeightTarget`, `Float4`, `Float5`, `isMoving`, `moveType`, `speed`, `activationDelay`, `updateDelay`, `maxCount`, `hitType`, `MoveCurveID`, `ElapsedTime`, `MorphCurveID`, `FacingCurveID`, `ScaleCurveID`, `HasFollowsTerrain`, `HasAttached`, `HasAbsoluteOrientation`, `HasDynamicShape`, `HasFaceMovementDir`, `windX`, `windY`, `windZ`, `windSpeed`, `windType`, `polygon`, `comment`) values
('1204','145286','5099','34079','1','2.5','0','0','0','0','1','2','8.62','0','0','0','0','397','608','404','396','0','0','0','0','1','0','0','0','0','0','0','0','Бушующий шторм'),
('1265','146991','5231','33504','4.5','4.5','4','4','5','5','1','1','15','0','0','0','16','416','394','0','0','0','0','0','0','0','0','0','0','0','0','0','0','Пламя Галакронда');
