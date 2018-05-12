-- Template Updates
-- Theralion
UPDATE `creature_template` SET `ScriptName`= 'boss_theralion', `flags_extra`= 512 WHERE `entry`= 45993;
UPDATE `creature_template` SET `DamageModifier`= 80, `flags_extra`= 512 WHERE `entry` IN (45993);
-- Valiona
UPDATE `creature_template` SET `ScriptName`= 'boss_valiona', `flags_extra`= 512 WHERE `entry`= 45992;
UPDATE `creature_template` SET `DamageModifier`= 80, `flags_extra`= 512 WHERE `entry` IN (45992);
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

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (46374, 46448);
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(46374, '86383'),
(46448, '86506');

-- Areatriggers
DELETE FROM `areatrigger_scripts` WHERE `entry`= 6442;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(6442, 'at_theralion_and_valiona_intro');

-- Correct Phasing for Theralion and Valiona
UPDATE `creature` SET `PhaseId`= 0, `PhaseGroup`= 525 WHERE `id` IN (45992, 45993);

-- Creature Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (43324, 45992, 45993);
-- Cho'Gall
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(43324, 0, 0, 'Valiona, Theralion, put them in their place.', 14, 0, 100, 0, 0, 22063, 47518, 'Cho''gall - Theralion and Valiona Intro'),
(43324, 1, 0, '(Come closer, closer.  Let us see your faces. All will be humbled before his power.)', 14, 0, 100, 0, 0, 22064, 47538, 'Cho''gall - Theralion and Valiona Death'),
-- Valiona
(45992, 0, 0, 'Do as the master commands, Theralion! Kill them!', 14, 0, 100, 0, 0, 21894, 47523, 'Valiona - Intro 1'),
(45992, 1, 0, 'You are worthless, Theralion!', 14, 0, 100, 0, 0, 21895, 47524, 'Valiona - Intro 2'),
(45992, 2, 0, '|TInterface\\Icons\\spell_fire_twilightnova.blp:20|t%s casts |cFFFF0000|Hspell:86788|h[Blackout]|h|r!', 41, 0, 100, 0, 0, 0, 47624, 'Valiona'),
(45992, 3, 0, '|TInterface\\Icons\\spell_fire_twilightfire.blp:20|t%s takes a |cFFFF0000|Hspell:86059|h[Deep Breath]|h|r!', 41, 0, 100, 0, 0, 21898, 46712, 'Valiona to Breath Flight Target Stalker'),
(45992, 4, 0, 'Theralion, I will engulf the hallway. Cover their escape!', 14, 0, 100, 0, 0, 21898, 47961, 'Valiona to Breath Flight Target Stalker'),
(45992, 5, 0, 'At least... Theralion dies with me...', 14, 0, 100, 0, 0, 21897, 47960, 'Valiona to Player'),
-- Theralion
(45993, 0, 0, 'The master was clearly speaking to you, Valiona. I am far too busy to attack ANYONE.', 14, 0, 100, 0, 0, 20300, 47521, 'Theralion - Intro 1'),
(45993, 1, 0, 'How dare you call me worthless! You will see why I am mother''s favored child!', 14, 0, 100, 0, 0, 20301, 47522, 'Theralion - Intro 2'),
(45993, 2, 0, 'You are not the boss of me, Valiona! I will engulf as I please!', 14, 0, 100, 0, 0, 20304, 47911, 'Theralion to Theralion Flight Target Stalker'),
(45993, 3, 0, '|TInterface\\Icons\\spell_fire_twilightpyroblast.blp:20|t%s begins to cast |cFF00EEFF|Hspell:86408|h[Dazzling Destruction]|h|r!', 41, 0, 100, 0, 0, 0, 46714, 'Theralion to Theralion Flight Target Stalker'),
(45993, 4, 0, '|TInterface\\Icons\\spell_holy_consumemagic.blp:20|t%s begins to cast |cFF00EEFF|Hspell:86622|h[Engulfing Magic]|h|r!', 41, 0, 100, 0, 0, 0, 46713, 'Theralion'),
(45993, 5, 0, 'WRITHE IN AGONY!', 14, 0, 100, 0, 0, 20306, 47913, 'Theralion to Valiona');

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_valiona_blackout_dummy',
'spell_valiona_blackout',
'spell_valiona_devouring_flames_targeting',
'spell_valiona_devouring_flames',
'spell_valiona_twilight_meteorite_targeting',
'spell_theralion_dazzling_destruction_targeting',
'spell_theralion_dazzling_destruction_dummy',
'spell_theralion_dazzling_destruction',
'spell_theralion_dazzling_destruction_twilight_realm',
'spell_theralion_twilight_shift',
'spell_theralion_fabulous_flames_targeting',
'spell_theralion_engulfing_magic_targeting',
'spell_theralion_engulfing_magic');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(86673, 'spell_valiona_blackout_dummy'),
(86788, 'spell_valiona_blackout'),
(92876, 'spell_valiona_blackout'),
(92877, 'spell_valiona_blackout'),
(92878, 'spell_valiona_blackout'),
(86832, 'spell_valiona_devouring_flames_targeting'),
(86844, 'spell_valiona_devouring_flames'),
(92872, 'spell_valiona_devouring_flames'),
(92873, 'spell_valiona_devouring_flames'),
(92874, 'spell_valiona_devouring_flames'),
(88518, 'spell_valiona_twilight_meteorite_targeting'),
(86380, 'spell_theralion_dazzling_destruction_targeting'),
(92923, 'spell_theralion_dazzling_destruction_targeting'),
(92924, 'spell_theralion_dazzling_destruction_targeting'),
(92925, 'spell_theralion_dazzling_destruction_targeting'),
(86408, 'spell_theralion_dazzling_destruction_dummy'),
(86406, 'spell_theralion_dazzling_destruction'),
(92926, 'spell_theralion_dazzling_destruction'),
(92927, 'spell_theralion_dazzling_destruction'),
(92928, 'spell_theralion_dazzling_destruction'),
(93063, 'spell_theralion_dazzling_destruction_twilight_realm'),
(88436, 'spell_theralion_twilight_shift'),
(92892, 'spell_theralion_twilight_shift'),
(92893, 'spell_theralion_twilight_shift'),
(92894, 'spell_theralion_twilight_shift'),
(86495, 'spell_theralion_fabulous_flames_targeting'),
(86607, 'spell_theralion_engulfing_magic_targeting'),
(92912, 'spell_theralion_engulfing_magic_targeting'),
(92913, 'spell_theralion_engulfing_magic_targeting'),
(92914, 'spell_theralion_engulfing_magic_targeting'),
(86622, 'spell_theralion_engulfing_magic'),
(95639, 'spell_theralion_engulfing_magic'),
(95640, 'spell_theralion_engulfing_magic'),
(95641, 'spell_theralion_engulfing_magic');

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (90346, 90345, 86840, 86379, 86408, 86406, 92926, 92927, 92928) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 90346, 0, 0, 31, 0, 3, 45992, 0, 0, 0, '', 'Share Health - Target Valiona'),
(13, 1, 90345, 0, 0, 31, 0, 3, 45993, 0, 0, 0, '', 'Share Health - Target Theralion'),
(13, 1, 86840, 0, 0, 31, 0, 3, 46588, 0, 0, 0, '', 'Devouring Flames - Target Convective Flames'),
(13, 1, 86379, 0, 0, 31, 0, 3, 46364, 0, 0, 0, '', 'Dazzling Destruction - Target Theralion Flight Target Stalker'),
(13, 1, 86408, 0, 0, 31, 0, 3, 46374, 0, 0, 0, '', 'Dazzling Destruction - Target Dazzling Destruction Stalker'),
(13, 2, 86406, 0, 0, 31, 0, 3, 46374, 0, 0, 0, '', 'Dazzling Destruction - Target Dazzling Destruction Stalker'),
(13, 2, 92926, 0, 0, 31, 0, 3, 46374, 0, 0, 0, '', 'Dazzling Destruction - Target Dazzling Destruction Stalker'),
(13, 2, 92927, 0, 0, 31, 0, 3, 46374, 0, 0, 0, '', 'Dazzling Destruction - Target Dazzling Destruction Stalker'),
(13, 2, 92928, 0, 0, 31, 0, 3, 46374, 0, 0, 0, '', 'Dazzling Destruction - Target Dazzling Destruction Stalker');

-- Spell Procs
DELETE FROM `spell_proc` WHERE `SpellId`= -86622;
INSERT INTO `spell_proc` (`SpellId`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`) VALUES
(-86622, 0x00055554, 1 | 2, 2, 0, 32);
