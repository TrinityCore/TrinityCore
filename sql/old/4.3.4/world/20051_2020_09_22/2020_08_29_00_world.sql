-- Protector of the Innocent
DELETE FROM `spell_proc` WHERE `SpellId`= -20138;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask2`, `SpellPhaseMask`, `SpellTypeMask`) VALUES
(-20138, 10, 0x40000000 | 0x80000000 | 0x8000, 0x400 | 0x4000, 2, 2);

-- Tower of Radiance
DELETE FROM `spell_proc` WHERE `SpellId`= -84800;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask2`, `ProcFlags`, `SpellPhaseMask`, `SpellTypeMask`, `Chance`) VALUES
(-84800, 10, 0x40000000, 0x400, 0x4000, 2, 2, 100);

-- Blessed Life
DELETE FROM `spell_proc` WHERE `SpellId`= -31828;
INSERT INTO `spell_proc` (`SpellId`, `SpellTypeMask`, `Cooldown`, `AttributesMask`) VALUES
(-31828, 1, 8000, 0x20);

-- Spell Scripts
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_pal_protector_of_the_innocent',
'spell_pal_tower_of_radiance');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-20138, 'spell_pal_protector_of_the_innocent'),
(-84800, 'spell_pal_tower_of_radiance');

-- Serverside Spells
DELETE FROM `spell_dbc` WHERE `Id`= 32733;
INSERT INTO `spell_dbc` (`Id`, `CastingTimeIndex`, `DurationIndex`, `RangeIndex`, `AttributesEx`, `Comment`) VALUES
(32733, 1, 0, 0, 0x100, '((Serverside/Non-DB2) Holy Power Talent Marker (DND)');

DELETE FROM `spell_bonus_data` WHERE `entry`= 64801;
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `comments`) VALUES
(64801, 0, 'Druid - Rejuvenation (Gift of the Earthmother)');
