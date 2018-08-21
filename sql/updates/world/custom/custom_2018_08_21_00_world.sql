-- Template Updates
-- Ozumat
UPDATE `creature_template` SET `InhabitType`= 4, `ScriptName`= 'boss_ozumat', `mechanic_immune_mask`= 617299839 WHERE `entry`= 44566;
UPDATE `creature_template` SET `minlevel`= 87, `maxlevel`= 87, `InhabitType`= 4, `VehicleId`= 1438, `mechanic_immune_mask`= 617299839, `flags_extra`= 1 WHERE `entry`= 49097;
-- Neptulon
UPDATE `creature_template` SET `difficulty_entry_1`= 49094, `ScriptName`= 'npc_ozumat_neptulon' WHERE `entry`= 40792;
UPDATE `creature_template` SET `minlevel`= 86, `maxlevel`= 86, `exp`= 3, `gossip_menu_id`= 11469, `faction`= 2263, `npcflag`= 1, `unit_flags`= 32768 WHERE `entry`= 49094;
-- Ozumat Combat Trigger
UPDATE `creature_template` SET `unit_flags`= 34080768, `InhabitType`= 12, `flags_extra`= 128 WHERE `entry` IN (44864, 49099);
-- Ozumat Add Spawner
UPDATE `creature_template` SET `unit_flags`= 33554432, `InhabitType`= 4, `flags_extra`= 128 WHERE `entry`= 44656;
-- Deep Murloc Invader
UPDATE `creature_template` SET `exp`= 3, `difficulty_entry_1`= 49068, `InhabitType`= 1, `flags_extra`= 512, `DamageModifier`= 4, `BaseVariance`= 0.5 WHERE `entry`= 44658;
UPDATE `creature_template` SET `minlevel`= 86, `maxlevel`= 86, `exp`= 3, `faction`= 1771, `InhabitType`= 1, `flags_extra`= 512, `DamageModifier`= 8, `BaseVariance`= 0.5 WHERE `entry`= 49068;
-- Vicious Mindlasher
UPDATE `creature_template` SET  `difficulty_entry_1`= 49107, `unit_class`= 2, `InhabitType`= 1, `flags_extra`= 512, `ScriptName`= 'npc_ozumat_vicious_mindlasher' WHERE `entry`= 44715;
UPDATE `creature_template` SET `minlevel`= 86, `maxlevel`= 86, `exp`= 3, `faction`= 1771, `unit_class`= 2, `InhabitType`= 1, `flags_extra`= 512 WHERE `entry`= 49107;
-- Unyielding Behemoth
UPDATE `creature_template` SET `difficulty_entry_1`= 49104, `InhabitType`= 1, `flags_extra`= 512 | 0x40000000, `VehicleId`= 1066, `DamageModifier`= 15, `BaseVariance`= 0.5, `mechanic_immune_mask`= 617299839, `ScriptName`= 'npc_ozumat_unyielding_behemoth' WHERE `entry`= 44648;
UPDATE `creature_template` SET `minlevel`= 86, `maxlevel`= 86, `exp`= 3, `faction`= 1771, `InhabitType`= 1, `flags_extra`= 512 | 0x40000000, `VehicleId`= 1066, `DamageModifier`= 30, `BaseVariance`= 0.5,`mechanic_immune_mask`= 617299839 WHERE `entry`= 49104;
-- Unyielding Behemoth (Hand Visual)
UPDATE `creature_template` SET `unit_flags`= 33554496, `flags_extra`= 128 WHERE `entry`= 44950;
-- Unyielding Behemoth (Leap Vehicle)
UPDATE `creature_template` SET `unit_flags`= 33554496, `unit_flags2`= 2099200, `InhabitType`= 4, `flags_extra`= 128, `VehicleId`= 1065 WHERE `entry`= 44949;
-- Faceless Sapper
UPDATE `creature_template` SET `difficulty_entry_1`= 49073, `InhabitType`= 1, `flags_extra`= 512 | 0x40000000, `mechanic_immune_mask`= 617299839  WHERE `entry`= 44752;
UPDATE `creature_template` SET `minlevel`= 86, `maxlevel`= 86, `exp`= 3, `faction`= 1771, `unit_flags2`= 32, `InhabitType`= 1, `flags_extra`= 512 | 0x40000000, `mechanic_immune_mask`= 617299839 WHERE `entry`= 49073;
-- Blight Beast
UPDATE `creature_template` SET `difficulty_entry_1`= 49061, `InhabitType`= 1, `flags_extra`= 512, `speed_run`= 0.57142, `DamageModifier`= 15, `BaseVariance`= 0.5 WHERE `entry`= 44841;
UPDATE `creature_template` SET `minlevel`= 86, `maxlevel`= 86, `exp`= 3, `faction`= 1771, `InhabitType`= 1, `flags_extra`= 512, `speed_run`= 0.57142, `DamageModifier`= 30, `BaseVariance`= 0.5  WHERE `entry`= 49061;
-- Blight of Ozumat
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= 128 WHERE `entry` IN (44801, 49062);
-- Blight of Ozumat 2
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= 128 WHERE `entry` IN (44834, 49063);

-- Template Addons
DELETE FROM `creature_template_addon` WHERE `entry` IN (44841, 44801, 49062, 44834, 49063);
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(44841, '83665'),
(44801, '83525'),
(49062, '83525'),
(44834, '83607'),
(49063, '83607');

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_ozumat_charge_to_window',
'spell_ozumat_jump_to_ground',
'spell_ozumat_shadow_blast',
'spell_ozumat_shadow_blast_missile',
'spell_ozumat_blight_of_ozumat',
'spell_ozumat_purify');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(83240, 'spell_ozumat_charge_to_window'),
(83241, 'spell_ozumat_jump_to_ground'),
(83653, 'spell_ozumat_charge_to_window'),
(83652, 'spell_ozumat_jump_to_ground'),
(83929, 'spell_ozumat_shadow_blast'),
(83931, 'spell_ozumat_shadow_blast_missile'),
(83518, 'spell_ozumat_blight_of_ozumat'),
(76953, 'spell_ozumat_purify');

-- Gossips
DELETE FROM `gossip_menu_option` WHERE (`MenuID`=11469 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionType`, `OptionNpcFlag`, `OptionBroadcastTextId`) VALUES
(11469, 0, 0, 'We are ready!', 1, 1, 41133);

-- Spellclicks
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (44648, 49104);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(44648, 46598, 1, 1),
(49104, 46598, 1, 1);

-- Vehicle Accessories
DELETE FROM `vehicle_template_accessory` WHERE `entry` IN (44648, 49104);
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(44648, 44950, 0, 1, 'Unyielding Behemoth - Hand Visual', 8, 0),
(49104, 44950, 0, 1, 'Unyielding Behemoth - Hand Visual', 8, 0);

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID`= 40792;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(40792, 0, 0, 'Ahh - my fearless assistants, I assume.', 14, 0, 100, 0, 0, 19469, 44263, 'Neptulon - Intro 1'),
(40792, 1, 0, 'You may yet regret your presence here.', 14, 0, 100, 0, 0, 19470, 44264, 'Neptulon - Intro 2'),
(40792, 2, 0, 'As I purify these waters, the servants of filth will surely be stirred. Beware!', 14, 0, 100, 0, 0, 19471, 44265, 'Neptulon - Purify Waters 1'),
(40792, 3, 0, 'Patience, guests. The waters are nearly cleansed.', 14, 0, 100, 0, 0, 19475, 44269, 'Neptulon - Purify Waters 2'),
(40792, 4, 0, 'The beast has returned! It must not pollute my waters!', 14, 0, 100, 0, 0, 19476, 44270, 'Neptulon to Player'),
(40792, 5, 0, 'Augh... Their filthiness stains me!', 14, 0, 100, 0, 0, 19472, 44266, 'Neptulon to Player'),
(40792, 6, 0, 'My waters are cleansed! Drink in their power!', 14, 0, 100, 0, 0, 19478, 44272, 'Neptulon to Player'),
(40792, 7, 0, 'Behold the power of pure water!', 14, 0, 100, 0, 0, 19477, 44271, 'Neptulon to Player'),
(40792, 8, 0, 'Ozumat is vulnerable, strike now!', 41, 0, 100, 0, 0, 19477, 50863, 'Neptulon to Player');

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (76953, 83360, 83441, 83240, 83241, 83437, 83977, 83463, 83648, 83653, 83652, 83606, 84037, 94171, 94170) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 76953, 0, 0, 31, 0, 3, 36171, 0, 0, 0, '', 'Purify - Target World Trigger'),
(13, 1, 83360, 0, 0, 31, 0, 3, 44656, 0, 0, 0, '', 'Summon Murloc Add Trigger - Target Ozumat Add Spawner'),
(13, 1, 83441, 0, 0, 31, 0, 3, 44656, 0, 0, 0, '', 'Summon Caster Add Trigger - Target Ozumat Add Spawner'),
(13, 1, 83648, 0, 0, 31, 0, 3, 44656, 0, 0, 0, '', 'Summon Kite Add Trigger - Target Ozumat Add Spawner'),
(13, 1, 83437, 0, 0, 31, 0, 3, 44656, 0, 0, 0, '', 'Summon Öt Add Trigger - Target Ozumat Add Spawner'),
(13, 1, 83240, 0, 0, 31, 0, 3, 40792, 0, 0, 0, '', 'Charge to window - Target Neptulon'),
(13, 1, 83241, 0, 0, 31, 0, 3, 40792, 0, 0, 0, '', 'Jump to ground - Target Neptulon'),
(13, 1, 83653, 0, 0, 31, 0, 3, 40792, 0, 0, 0, '', 'Charge to window - Target Neptulon'),
(13, 1, 83652, 0, 0, 31, 0, 3, 40792, 0, 0, 0, '', 'Jump to ground - Target Neptulon'),
(13, 1, 83463, 0, 0, 31, 0, 3, 40792, 0, 0, 0, '', 'Entangling Grasp - Target Neptulon'),
(13, 1, 94170, 0, 0, 31, 0, 3, 40792, 0, 0, 0, '', 'Grab Neptulon - Target Neptulon'),
(13, 1, 83977, 0, 0, 31, 0, 3, 44950, 0, 0, 0, '', 'Shadow Blast - Target Unyielding Behemoth (Hand Visual)'),
(13, 1, 83606, 0, 0, 31, 0, 3, 36171, 254898, 0, 0, '', 'Purify - Target World Trigger'),
(13, 1, 84037, 0, 0, 31, 0, 3, 44566, 0, 0, 0, '', 'Pure Water - Target Ozumat'),
(13, 1, 94171, 0, 0, 31, 0, 3, 44566, 0, 0, 0, '', 'Grab Neptulon - Target Ozumat');

-- Areatriggers
DELETE FROM `areatrigger_scripts` WHERE `entry`= 6646;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(6646, 'at_tott_neptulon_intro');

-- Delete Encounter Related Creatures
DELETE FROM `creature` WHERE `guid` IN (255404, 254949, 255407, 254956);
DELETE FROM `creature_addon` WHERE `guid` IN (255404, 254949, 255407, 254956);

-- Currency Loot
DELETE FROM `creature_onkill_reward` WHERE `creature_id`= 49097;
INSERT INTO `creature_onkill_reward` (`creature_id`, `CurrencyId1`, `CurrencyCount1`) VALUES
(49097, 395, 7000);

-- Loot
UPDATE `gameobject_template_addon`SET `flags`= 16, `mingold`= 19800, `maxgold`= 20000 WHERE `entry` IN (205216, 207973);

DELETE FROM `gameobject_loot_template` WHERE `Entry` IN (29711, 36142);
DELETE FROM `reference_loot_template` WHERE `Entry` IN (297110, 361420);
INSERT INTO `gameobject_loot_template` (`Entry`, `Chance`, `LootMode`, `Reference`, `MinCount`, `MaxCount`) VALUES
(29711, 100, 1, 448190, 2, 2);

INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `Reference`, `MinCount`, `MaxCount`) VALUES
(36142, 52078, 100, 1, 0, 1, 1), -- Chaos Orb
(36142, 361420, 100, 1, 361420, 2, 2);

INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(297110, 55252, 0, 1, 1, 1, 1),
(297110, 55259, 0, 1, 1, 1, 1),
(297110, 55258, 0, 1, 1, 1, 1),
(297110, 55254, 0, 1, 1, 1, 1),
(297110, 55253, 0, 1, 1, 1, 1),
(297110, 55255, 0, 1, 1, 1, 1),
(297110, 55249, 0, 1, 1, 1, 1),
(297110, 55250, 0, 1, 1, 1, 1),
(297110, 55251, 0, 1, 1, 1, 1),
(297110, 55256, 0, 1, 1, 1, 1);

INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(361420, 56284, 0, 1, 1, 1, 1),
(361420, 56289, 0, 1, 1, 1, 1),
(361420, 56288, 0, 1, 1, 1, 1),
(361420, 56291, 0, 1, 1, 1, 1),
(361420, 56281, 0, 1, 1, 1, 1),
(361420, 56286, 0, 1, 1, 1, 1),
(361420, 56283, 0, 1, 1, 1, 1),
(361420, 56282, 0, 1, 1, 1, 1),
(361420, 56285, 0, 1, 1, 1, 1),
(361420, 56290, 0, 1, 1, 1, 1);
