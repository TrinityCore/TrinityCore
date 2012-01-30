--
-- Damage scaling from stats fixes (ap, spd and other) for YTDb and TDB
-- 

-- Enchants
DELETE FROM `spell_bonus_data` WHERE `entry` IN (6297, 13897, 20004, 28005, 20006, 44525); 
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES
(6297,0,0,0,0,'Enchant - Fiery Blaze'),
(13897,0,0,0,0,'Enchant - Fiery Weapon'),
(20004,0,0,0,0,'Enchant - Lifestealing'),
(28005,0,0,0,0,'Enchant - Battlemaster'),
(20006,0,0,0,0,'Enchant - Unholy Weapon'),
(44525,0,0,0,0,'Enchant - Icebreaker');
UPDATE `spell_bonus_data` SET `comments`='Enchant - Deathfrost' WHERE `entry`=46579;

-- Items
DELETE FROM `spell_bonus_data` WHERE `entry` IN (7712, 7714, 10577, 16614, 18798, 27655, 28788, 55756);     
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES
(7712,0,0,0,0,'Item - Blazefury Medallion & Fiery Retributor (Fire Strike)'),
(7714,0,0,0,0,'Item - Fiery Plate Gauntlets (Fire Strike)'),
(10577,0,0,0,0,'Item - Gauntlets of the Sea (Heal)'),
(16614,0,0,0,0,'Item - Storm Gauntlets (Lightning Strike)'),
(18798,0,0,0,0,'Item - Freezing Band (Freeze)'),
(27655,0,0,0,0,'Item - Heart of Wyrmthalak (Flame Lash)'),
(28788,0,0,0,0,'Item - Paladin T3 (8)'),
(55756,0,0,0,0,'Item - Brunnhildar weapons (Chilling Blow)');

-- Consumables
DELETE FROM `spell_bonus_data` WHERE `entry` IN (28715, 38616, 43731, 43733);
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES
(28715,0,0,0,0,'Consumable - Flamecap (Flamecap Fire)'),
(38616,0,0,0,0,'Poison - Bloodboil Poison'),
(43731,0,0,0,0,'Consumable - Stormchops (Lightning Zap)'),
(43733,0,0,0,0,'Consumable - Stormchops (Lightning Zap)');

-- Paladin spells
-- Seals of the Pure fix
DELETE FROM spell_bonus_data WHERE entry IN (25742);
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES
('25742','0','0','0','0','Paladin - Seal of Righteousness Dummy Proc');
-- Divine Storm heal effect fix
DELETE FROM `spell_bonus_data` WHERE `entry` IN ('54172');
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES
('54172','0','0','0','0','Paladin - Divine Storm');
DELETE FROM `spell_dbc` WHERE `Id` IN ('199997');
INSERT INTO `spell_dbc` (`Id`, `Dispel`, `Mechanic`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `Stances`, `StancesNot`, `Targets`, `CastingTimeIndex`, `AuraInterruptFlags`, `ProcFlags`, `ProcChance`, `ProcCharges`, `MaxLevel`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `StackAmount`, `EquippedItemClass`, `EquippedItemSubClassMask`, `EquippedItemInventoryTypeMask`, `Effect1`, `Effect2`, `Effect3`, `EffectDieSides1`, `EffectDieSides2`, `EffectDieSides3`, `EffectRealPointsPerLevel1`, `EffectRealPointsPerLevel2`, `EffectRealPointsPerLevel3`, `EffectBasePoints1`, `EffectBasePoints2`, `EffectBasePoints3`, `EffectMechanic1`, `EffectMechanic2`, `EffectMechanic3`, `EffectImplicitTargetA1`, `EffectImplicitTargetA2`, `EffectImplicitTargetA3`, `EffectImplicitTargetB1`, `EffectImplicitTargetB2`, `EffectImplicitTargetB3`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectRadiusIndex3`, `EffectApplyAuraName1`, `EffectApplyAuraName2`, `EffectApplyAuraName3`, `EffectAmplitude1`, `EffectAmplitude2`, `EffectAmplitude3`, `EffectMultipleValue1`, `EffectMultipleValue2`, `EffectMultipleValue3`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectMiscValue3`, `EffectMiscValueB1`, `EffectMiscValueB2`, `EffectMiscValueB3`, `EffectTriggerSpell1`, `EffectTriggerSpell2`, `EffectTriggerSpell3`, `EffectSpellClassMaskA1`, `EffectSpellClassMaskA2`, `EffectSpellClassMaskA3`, `EffectSpellClassMaskB1`, `EffectSpellClassMaskB2`, `EffectSpellClassMaskB3`, `EffectSpellClassMaskC1`, `EffectSpellClassMaskC2`, `EffectSpellClassMaskC3`, `MaxTargetLevel`, `SpellFamilyName`, `SpellFamilyFlags1`, `SpellFamilyFlags2`, `SpellFamilyFlags3`, `MaxAffectedTargets`, `DmgClass`, `PreventionType`, `DmgMultiplier1`, `DmgMultiplier2`, `DmgMultiplier3`, `AreaGroupId`, `SchoolMask`, `Comment`) VALUES
('199997','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','0','0','0','0','0','1','0','-1','0','0','6','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','0','0','0','0','0','4','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','10','0','0','0','0','0','0','0','0','0','0','0','Divine Storm Helper (SERVERSIDE)');
DELETE FROM `spell_proc_event` WHERE `entry` IN ('199997');
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
('199997','0','10','0','131072','0','16','0','0','100','0');
-- Heart of the Crusader
DELETE FROM `spell_proc_event` WHERE `entry` IN (20335,20336,20337);
INSERT INTO `spell_proc_event` VALUES
(20335, 0, 10, 8388608, 0, 8, 256, 0, 0, 100, 0),
(20336, 0, 10, 8388608, 0, 8, 256, 0, 0, 100, 0),
(20337, 0, 10, 8388608, 0, 8, 256, 0, 0, 100, 0);

-- Druid spells
UPDATE `spell_bonus_data` SET `direct_bonus` = 0, `dot_bonus` = 0 WHERE `entry` IN (779,1822,60089);
DELETE FROM `spell_bonus_data` WHERE `entry` IN (1079,9007,22568);
INSERT INTO `spell_bonus_data` VALUES
(1079,0,0,-1,-1,'Druid - Rip'),
(9007,0,0,-1,-1,'Druid - Pounce Bleed'),
(22568,0,0,-1,-1,'Druid - Ferocious Bite');
-- Lifebloom final bloom fix
UPDATE `spell_bonus_data` SET `direct_bonus`=0.3857 WHERE `entry`=33778 ;
UPDATE `spell_bonus_data` SET `dot_bonus`=0.0653 WHERE `entry` IN (48450, 48451, 48628);

-- Hunter spells
UPDATE `spell_bonus_data` SET `direct_bonus` = 0, `dot_bonus` = 0 WHERE `entry` IN (3044,3674,53352,13812,13797,1978,42243);
UPDATE `spell_bonus_data` SET `ap_dot_bonus` = 0.1 WHERE `entry` = 13812;
DELETE FROM `spell_bonus_data` WHERE `entry` IN (24131,53353);
INSERT INTO `spell_bonus_data` VALUES
(24131,0,0,-1,-1,'Hunter - Wyvern Sting (triggered)'),
(53353,0,0,-1,-1,'Hunter - Chimera Shot (Serpent)');
DELETE FROM `spell_ranks` WHERE `first_spell_id` = 24131;
INSERT INTO `spell_ranks` VALUES
(24131,24131,1),
(24131,24134,2),
(24131,24135,3),
(24131,27069,4),
(24131,49009,5),
(24131,49010,6);
-- Fix Explosive shot from spd scaling
DELETE FROM `spell_bonus_data` WHERE `entry`='53352';
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES
( '53352','0','0','0.14','0','Hunter - Explosive Shot (triggered)');

-- Rogue spells
UPDATE `spell_bonus_data` SET `direct_bonus` = 0, `dot_bonus` = 0 WHERE `entry` IN (2818,2819,11353,11354,25349,26968,27187,57969,57970);
-- Envenom fix
DELETE FROM `spell_bonus_data` WHERE `entry` IN ('32645');

-- Shaman spells
-- Fixed spell bonus coefficient for spell Healing Stream Totem.
DELETE FROM `spell_bonus_data` WHERE `entry` IN (52042,5672);
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`,`ap_bonus`, `ap_dot_bonus`, `comments`) VALUES
('5672','0.0827','-1','-1','-1','Shaman - Healing Stream Totem Rank 1');

-- Warrior spells
REPLACE INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES 
(23922,0,0,0,0,'Warrior - Shield Slam');
