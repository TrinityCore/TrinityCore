-- Template Updates
-- Theralion
UPDATE `creature_template` SET `ScriptName`= 'boss_theralion', `difficulty_entry_1`= 49903, `difficulty_entry_2`= 49904, `difficulty_entry_3`= 49905 WHERE `entry`= 45993;
UPDATE `creature_template` SET `minlevel`= 88, `maxlevel`= 88, `DamageModifier`= 80, `flags_extra`= 1 | 512, `mechanic_immune_mask`= 617299839, `exp`= 3, `faction`= 2146, `unit_flags`= 32832, `unit_flags2`= 134219776 WHERE `entry` IN (45993, 49903, 49904, 49905);
UPDATE `creature_template` SET `mingold`= 1100000, `maxgold`= 1200000 WHERE `entry` IN (45993, 49904);
UPDATE `creature_template` SET `mingold`= 2450000, `maxgold`= 2550000 WHERE `entry` IN (49903, 49905);
-- Valiona
UPDATE `creature_template` SET `ScriptName`= 'boss_valiona', `difficulty_entry_1`= 49897, `difficulty_entry_2`= 49898, `difficulty_entry_3`= 49899 WHERE `entry`= 45992;
UPDATE `creature_template` SET `minlevel`= 88, `maxlevel`= 88, `DamageModifier`= 80, `flags_extra`= 1 | 512, `mechanic_immune_mask`= 617299839, `exp`= 3, `faction`= 2146, `unit_flags`= 32832, `unit_flags2`= 134219776 WHERE `entry` IN (45992, 49897, 49898, 49899);
UPDATE `creature_template` SET `mingold`= 1100000, `maxgold`= 1200000 WHERE `entry` IN (45992, 49898);
UPDATE `creature_template` SET `mingold`= 2450000, `maxgold`= 2550000 WHERE `entry` IN (49897, 49899);
-- Valiona (Fire Dummy)
UPDATE `creature_template` SET `flags_extra`= 128 WHERE `entry`= 46147;
-- Theralion Flight Target Stalker
UPDATE `creature_template` SET `InhabitType`= 4, `flags_extra`= 128 WHERE `entry`= 46364;
-- Convective Flames
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= 128, `InhabitType`= 13 WHERE `entry`= 46588;
-- Dazzling Destruction Stalker
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= 128, `InhabitType`= 13 WHERE `entry`= 46374;
-- Fabolous Flames
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= 128, `InhabitType`= 13 WHERE `entry`= 46448;
-- Unstable Twilight
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= 128, `ScriptName`= 'npc_theralion_and_valiona_unstable_twilight' WHERE `entry`= 46304;
-- Collapsing Twilight Portal
UPDATE `creature_template` SET `npcflag`= 16777216, `InhabitType`= 4, `unit_flags2`= 2099200, `flags_extra`= 128 WHERE `entry`= 46301;
-- Twilight Sentry
UPDATE `creature_template` SET `ScriptName`= 'npc_theralion_and_valiona_twilight_sentry', `difficulty_entry_3`= 51627 WHERE `entry`= 50008;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `exp`= 3, `faction`= 16, `mechanic_immune_mask`= 617299839, `flags_extra`= 1073741824 WHERE `entry` IN (50008, 51627);
-- Twilight Rift
UPDATE `creature_template` SET `unit_flags`= 33554432, `InhabitType`= 5, `flags_extra`= 128 WHERE `entry`= 50014;

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (46374, 46448, 50014);
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(46448, '86506'),
(50014, '93010');

DELETE FROM `creature_template_addon` WHERE `entry`= 46301;
INSERT INTO `creature_template_addon` (`entry`, `bytes1`) VALUES
(46301, 50331648);

-- Areatriggers
DELETE FROM `areatrigger_scripts` WHERE `entry`= 6442;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(6442, 'at_theralion_and_valiona_intro');

-- Correct Phasing for Theralion, Valiona and Valiona's Deep Breath flame stalkers
UPDATE `creature` SET `PhaseId`= 0, `PhaseGroup`= 525 WHERE `id` IN (45992, 45993, 46147);
UPDATE `creature` SET `PhaseId`= 290, `PhaseGroup`= 0 WHERE `guid`= 254002;
UPDATE `creature_addon` SET `auras`= '' WHERE `guid` IN (254002, 254169);
-- Correct Phasing for Dragon Sibling doors
UPDATE `gameobject` SET `PhaseId`= 0, `PhaseGroup`= 525 WHERE `guid` IN (211097, 211096);

-- Creature Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (43324, 45992, 45993);
-- Cho'Gall
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(43324, 0, 0, 'Valiona, Theralion, put them in their place.', 14, 0, 100, 0, 0, 22063, 47518, 2, 'Cho''gall - Theralion and Valiona Intro'),
(43324, 1, 0, '(Come closer, closer.  Let us see your faces. All will be humbled before his power.)', 14, 0, 100, 0, 0, 22064, 47538, 2, 'Cho''gall - Theralion and Valiona Death'),
-- Valiona
(45992, 0, 0, 'Do as the master commands, Theralion! Kill them!', 14, 0, 100, 0, 0, 21894, 47523, 2, 'Valiona - Intro 1'),
(45992, 1, 0, 'You are worthless, Theralion!', 14, 0, 100, 0, 0, 21895, 47524, 2, 'Valiona - Intro 2'),
(45992, 2, 0, '|TInterface\\Icons\\spell_fire_twilightnova.blp:20|t%s casts |cFFFF0000|Hspell:86788|h[Blackout]|h|r!', 41, 0, 100, 0, 0, 0, 47624, 2, 'Valiona'),
(45992, 3, 0, '|TInterface\\Icons\\spell_fire_twilightfire.blp:20|t%s takes a |cFFFF0000|Hspell:86059|h[Deep Breath]|h|r!', 41, 0, 100, 0, 0, 0, 46712, 2, 'Valiona to Breath Flight Target Stalker'),
(45992, 4, 0, 'Theralion, I will engulf the hallway. Cover their escape!', 14, 0, 100, 0, 0, 21898, 47961, 2, 'Valiona to Breath Flight Target Stalker'),
(45992, 5, 0, 'Enter Twilight!', 14, 0, 100, 0, 0, 21899, 47962, 2, 'Valiona to Player'),
(45992, 6, 0, 'Breathe your dying breath!', 14, 0, 100, 0, 0, 21896, 47959, 2, 'Valiona to Player'),
(45992, 7, 0, 'At least... Theralion dies with me...', 14, 0, 100, 0, 0, 21897, 47960, 2, 'Valiona to Player'),
-- Theralion
(45993, 0, 0, 'The master was clearly speaking to you, Valiona. I am far too busy to attack ANYONE.', 14, 0, 100, 0, 0, 20300, 47521, 2, 'Theralion - Intro 1'),
(45993, 1, 0, 'How dare you call me worthless! You will see why I am mother''s favored child!', 14, 0, 100, 0, 0, 20301, 47522, 2, 'Theralion - Intro 2'),
(45993, 2, 0, 'You are not the boss of me, Valiona! I will engulf as I please!', 14, 0, 100, 0, 0, 20304, 47911, 2, 'Theralion to Theralion Flight Target Stalker'),
(45993, 2, 1, 'There is no escape from the fury of the twilight flight!', 14, 0, 100, 0, 0, 20305, 47912, 2, 'Theralion to Theralion Flight Target Stalker'),
(45993, 3, 0, '|TInterface\\Icons\\spell_fire_twilightpyroblast.blp:20|t%s begins to cast |cFF00EEFF|Hspell:86408|h[Dazzling Destruction]|h|r!', 41, 0, 100, 0, 0, 0, 46714, 2, 'Theralion to Theralion Flight Target Stalker'),
(45993, 4, 0, '|TInterface\\Icons\\spell_holy_consumemagic.blp:20|t%s begins to cast |cFF00EEFF|Hspell:86622|h[Engulfing Magic]|h|r!', 41, 0, 100, 0, 0, 0, 46713, 2, 'Theralion'),
(45993, 5, 0, 'WRITHE IN AGONY!', 14, 0, 100, 0, 0, 20306, 47913, 2, 'Theralion to Valiona'),
(45993, 6, 0, 'Bare your soul to me, mortal.', 14, 0, 100, 0, 0, 20302, 47908, 2, 'Theralion to Valiona'),
(45993, 7, 0, 'I knew I should have stayed out of this...', 14, 0, 100, 0, 0, 20303, 47910, 2, 'Theralion to Valiona');

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_valiona_blackout_dummy',
'spell_valiona_blackout',
'spell_valiona_devouring_flames',
'spell_valiona_twilight_meteorite_targeting',
'spell_theralion_dazzling_destruction_dummy',
'spell_theralion_dazzling_destruction',
'spell_theralion_dazzling_destruction_twilight_realm',
'spell_theralion_fabulous_flames_targeting',
'spell_theralion_engulfing_magic_targeting',
'spell_theralion_engulfing_magic',
'spell_valiona_strafe',
'spell_theralion_and_valiona_twilight_shift',
'spell_theralion_and_valiona_twilight_shift_phase',
'spell_theralion_and_valiona_shifting_reality',
'spell_valiona_summon_twilight_portal',
'spell_theralion_and_valiona_collapsing_twilight_portal',
'spell_theralion_and_valiona_twilight_shift_spellclick',
'spell_valiona_summon_twilight_sentry',
'spell_theralion_and_valiona_twilight_shift_phase_ally',
'spell_valiona_twilight_flame_twilight_realm',
'spell_valiona_twilight_flames',
'spell_valiona_devouring_flames_targeting');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(86673, 'spell_valiona_blackout_dummy'),
(86788, 'spell_valiona_blackout'),
(92876, 'spell_valiona_blackout'),
(92877, 'spell_valiona_blackout'),
(92878, 'spell_valiona_blackout'),
(86844, 'spell_valiona_devouring_flames'),
(92872, 'spell_valiona_devouring_flames'),
(92873, 'spell_valiona_devouring_flames'),
(92874, 'spell_valiona_devouring_flames'),
(88518, 'spell_valiona_twilight_meteorite_targeting'),
(86408, 'spell_theralion_dazzling_destruction_dummy'),
(86406, 'spell_theralion_dazzling_destruction'),
(92926, 'spell_theralion_dazzling_destruction'),
(92927, 'spell_theralion_dazzling_destruction'),
(92928, 'spell_theralion_dazzling_destruction'),
(93063, 'spell_theralion_dazzling_destruction_twilight_realm'),
(88436, 'spell_theralion_and_valiona_twilight_shift_phase'),
(92892, 'spell_theralion_and_valiona_twilight_shift_phase'),
(92893, 'spell_theralion_and_valiona_twilight_shift_phase'),
(92894, 'spell_theralion_and_valiona_twilight_shift_phase'),
(86202, 'spell_theralion_and_valiona_twilight_shift_phase'),
(92889, 'spell_theralion_and_valiona_twilight_shift_phase'),
(92890, 'spell_theralion_and_valiona_twilight_shift_phase'),
(92891, 'spell_theralion_and_valiona_twilight_shift_phase'),
(86495, 'spell_theralion_fabulous_flames_targeting'),
(86607, 'spell_theralion_engulfing_magic_targeting'),
(92912, 'spell_theralion_engulfing_magic_targeting'),
(92913, 'spell_theralion_engulfing_magic_targeting'),
(92914, 'spell_theralion_engulfing_magic_targeting'),
(86622, 'spell_theralion_engulfing_magic'),
(95639, 'spell_theralion_engulfing_magic'),
(95640, 'spell_theralion_engulfing_magic'),
(95641, 'spell_theralion_engulfing_magic'),
(93051, 'spell_theralion_and_valiona_twilight_shift'),
(93055, 'spell_theralion_and_valiona_shifting_reality'),
(86287, 'spell_valiona_summon_twilight_portal'),
(86291, 'spell_theralion_and_valiona_collapsing_twilight_portal'),
(86293, 'spell_theralion_and_valiona_twilight_shift_spellclick'),
(93029, 'spell_valiona_summon_twilight_sentry'),
(93064, 'spell_theralion_and_valiona_twilight_shift_phase_ally'),
(86136, 'spell_valiona_strafe'),
(86138, 'spell_valiona_strafe'),
(86139, 'spell_valiona_strafe'),
(86144, 'spell_valiona_strafe'),
(86228, 'spell_valiona_twilight_flame_twilight_realm'),
(92867, 'spell_valiona_twilight_flame_twilight_realm'),
(86199, 'spell_valiona_twilight_flames'),
(92868, 'spell_valiona_twilight_flames'),
(92869, 'spell_valiona_twilight_flames'),
(92870, 'spell_valiona_twilight_flames'),
(86832, 'spell_valiona_devouring_flames_targeting');

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (90346, 90345, 86840, 86379, 86408, 86406, 92926, 92927, 92928, 86144, 86139, 86136, 86138, 88816, 88815) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 90346, 0, 0, 31, 0, 3, 45992, 0, 0, 0, '', 'Share Health - Target Valiona'),
(13, 1, 90345, 0, 0, 31, 0, 3, 45993, 0, 0, 0, '', 'Share Health - Target Theralion'),
(13, 1, 86840, 0, 0, 31, 0, 3, 46588, 0, 0, 0, '', 'Devouring Flames - Target Convective Flames'),
(13, 1, 86379, 0, 0, 31, 0, 3, 46364, 0, 0, 0, '', 'Dazzling Destruction - Target Theralion Flight Target Stalker'),
(13, 1, 86408, 0, 0, 31, 0, 3, 46374, 0, 0, 0, '', 'Dazzling Destruction - Target Dazzling Destruction Stalker'),
(13, 2, 86406, 0, 0, 31, 0, 3, 46374, 0, 0, 0, '', 'Dazzling Destruction - Target Dazzling Destruction Stalker'),
(13, 2, 92926, 0, 0, 31, 0, 3, 46374, 0, 0, 0, '', 'Dazzling Destruction - Target Dazzling Destruction Stalker'),
(13, 2, 92927, 0, 0, 31, 0, 3, 46374, 0, 0, 0, '', 'Dazzling Destruction - Target Dazzling Destruction Stalker'),
(13, 2, 92928, 0, 0, 31, 0, 3, 46374, 0, 0, 0, '', 'Dazzling Destruction - Target Dazzling Destruction Stalker'),
(13, 1, 86144, 0, 0, 31, 0, 3, 46147, 0, 0, 0, '', 'Strafe - Target Valiona Stalker'),
(13, 1, 86139, 0, 0, 31, 0, 3, 46147, 0, 0, 0, '', 'Trigger Top Strafe - Target Valiona Stalker'),
(13, 1, 86136, 0, 0, 31, 0, 3, 46147, 0, 0, 0, '', 'Trigger Bottom Strafe - Target Valiona Stalker'),
(13, 1, 86138, 0, 0, 31, 0, 3, 46147, 0, 0, 0, '', 'Trigger Middle Strafe - Target Valiona Stalker'),
(13, 1, 88816, 0, 0, 31, 0, 3, 45992, 0, 0, 0, '', 'Trigger Action - Target Valiona'),
(13, 1, 88815, 0, 0, 31, 0, 3, 45993, 0, 0, 0, '', 'Trigger Action - Target Theralion');

-- Spell Procs
DELETE FROM `spell_proc` WHERE `SpellId` IN (86622, 95639, 95640, 95641, 93053);
INSERT INTO `spell_proc` (`SpellId`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Cooldown`) VALUES
(86622, 0x00055554, 1 | 2, 2, 0, 32, 0),
(95639, 0x00055554, 1 | 2, 2, 0, 32, 0),
(95640, 0x00055554, 1 | 2, 2, 0, 32, 0),
(95641, 0x00055554, 1 | 2, 2, 0, 32, 0),
(93053, 0x00000004, 0, 0, 0, 0, 20000);

-- Spellclick Entries
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`= 46301;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(46301, 86293, 3, 0),
(46301, 86296, 0, 0);

-- Currency Loot
DELETE FROM `creature_onkill_reward` WHERE `creature_id` IN (45992, 49897, 49898, 49899);
INSERT INTO `creature_onkill_reward` (`creature_id`, `CurrencyId1`, `CurrencyCount1`) VALUES
(45992, 396, 11500),
(49897, 396, 13500),
(49898, 396, 11500),
(49899, 396, 13500);

-- Loot
DELETE FROM `reference_loot_template` WHERE `Entry` IN (459920, 498980);
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
-- Valiona
-- Normal Mode
(459920, 59512, 0, 1, 1, 1, 1), -- Valiona's Medallion
(459920, 59515, 0, 1, 1, 1, 1), -- Vial of Stolen Memories
(459920, 59517, 0, 1, 1, 1, 1), -- Necklace of Strife
(459920, 59518, 0, 1, 1, 1, 1), -- Ring of Rivalry
(459920, 63531, 0, 1, 1, 1, 1), -- Daybreaker Helm
(459920, 63533, 0, 1, 1, 1, 1), -- Fang of Twilight
(459920, 59516, 0, 1, 1, 1, 1), -- Drape of the Twins
(459920, 59519, 0, 1, 1, 1, 1), -- Theralion's Mirror
(459920, 63532, 0, 1, 1, 1, 1), -- Dragonheart Piercer
(459920, 63534, 0, 1, 1, 1, 1), -- Helm of Eldritch Authority
(459920, 63535, 0, 1, 1, 1, 1), -- Waistguard of Hatred
(459920, 63536, 0, 1, 1, 1, 1), -- Blade of the Watching Hour
-- Heroic Mode
(498980, 65112, 0, 1, 1, 1, 1), -- Valiona's Medallion
(498980, 65109, 0, 1, 1, 1, 1), -- Vial of Stolen Memories
(498980, 65107, 0, 1, 1, 1, 1), -- Necklace of Strife
(498980, 65106, 0, 1, 1, 1, 1), -- Ring of Rivalry
(498980, 65096, 0, 1, 1, 1, 1), -- Daybreaker Helm
(498980, 65094, 0, 1, 1, 1, 1), -- Fang of Twilight
(498980, 65108, 0, 1, 1, 1, 1), -- Drape of the Twins
(498980, 65105, 0, 1, 1, 1, 1), -- Theralion's Mirror
(498980, 65095, 0, 1, 1, 1, 1), -- Dragonheart Piercer
(498980, 65093, 0, 1, 1, 1, 1), -- Helm of Eldritch Authority
(498980, 65092, 0, 1, 1, 1, 1), -- Waistguard of Hatred
(498980, 65091, 0, 1, 1, 1, 1); -- Blade of the Watching Hour

-- Valiona
DELETE FROM `creature_loot_template` WHERE `entry` IN (45992, 49897, 49898, 49899);
UPDATE `creature_template` SET `lootid`= `entry` WHERE `entry` IN (45992, 49897, 49898, 49899);
-- Theralion
DELETE FROM `creature_loot_template` WHERE `entry` IN (45993, 49903, 49904, 49905);
UPDATE `creature_template` SET `lootid`= `entry` WHERE `entry` IN (45993, 49903, 49904, 49905);

INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `Reference`, `MaxCount`) VALUES
-- Valiona
-- 10 Player Normal
(45992, 459920, 100, 1, 459920, 1),
-- 25 Player Normal
(49897, 459920, 100, 1, 459920, 3),
-- 10 Player Heroic
(49898, 498980, 100, 1, 498980, 1),
-- 25 Player Heroic
(49899, 498980, 100, 1, 498980, 3),
-- Theralion
-- 10 Player Normal
(45993, 459920, 100, 1, 459920, 1),
-- 25 Player Normal
(49903, 459920, 100, 1, 459920, 3),
-- 10 Player Heroic
(49904, 498980, 100, 1, 498980, 1),
-- 25 Player Heroic
(49905, 498980, 100, 1, 498980, 3);
