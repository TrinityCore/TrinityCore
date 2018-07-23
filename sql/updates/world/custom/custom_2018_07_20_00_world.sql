-- Template Updates
-- Cho'Gall
UPDATE `creature_template` SET `difficulty_entry_1`= 50131, `difficulty_entry_2`= 50132, `difficulty_entry_3`= 50133, `ScriptName`= 'boss_chogall' WHERE `entry`= 43324;
UPDATE `creature_template` SET `unit_class`= 2, `minlevel`= 88, `maxlevel`= 88, `exp`= 3, `faction`= 16, `movementId`= 144, `DamageModifier`= 35, `BaseVariance`= 0.5, `speed_run`= 1.42857, `BaseAttackTime`= 1500, `unit_flags`= 64, `unit_flags2`= 134219776,  `mechanic_immune_mask`= 617299839, `VehicleId`= 961, `flags_extra`= 1 | 536870912 WHERE `entry` IN (50131, 50132, 50133, 43324);
-- Fire Portal and Shadow Portal
UPDATE `creature_template` SET `unit_flags`= 33554432, `unit_flags2`= 2099200, `InhabitType`= 12, `flags_extra`= 128, `ScriptName`= 'npc_chogall_portal' WHERE `entry` IN (43393, 43603);
-- Fire Elemental
UPDATE `creature_template` SET `difficulty_entry_1`= 50194, `difficulty_entry_2`= 50195, `difficulty_entry_3`= 50196, `ScriptName`= 'npc_chogall_elemental' WHERE `entry`= 43406;
-- Shadow Lord
UPDATE `creature_template` SET `difficulty_entry_1`= 50197, `difficulty_entry_2`= 50198, `difficulty_entry_3`= 50199, `ScriptName`= 'npc_chogall_elemental' WHERE `entry`= 43592;
-- Fire Elemental and Shadow Lord
UPDATE `creature_template` SET `minlevel`= 87, `maxlevel`= 87, `exp`= 3, `faction`= 14, `mechanic_immune_mask`= 617299839, `flags_extra`= 536870912 | 1073741824 WHERE `entry` IN (50194, 50195, 50196, 50197,50198, 50199, 43406, 43592);
-- Fire Elemental and Shadow Lord(Heroic)
UPDATE `creature_template` SET `unit_flags`= 2097152 WHERE `entry` IN (50195, 50196, 50198, 50199);
-- Fire Elemental and Shadow Lord (Normal)
UPDATE `creature_template` SET `unit_flags`= 2181038080 WHERE `entry` IN (43406, 43592, 50194, 50197);
-- Blaze
UPDATE `creature_template` SET `unit_flags`= 33554432, `unit_flags2`= 2099200,`flags_extra`= 128 WHERE `entry`= 43585;
-- Corrupting Adherent
UPDATE `creature_template` SET `difficulty_entry_1`= 50184, `difficulty_entry_2`= 50185, `difficulty_entry_3`= 50186, `ScriptName`= 'npc_chogall_corrupting_adherent' WHERE `entry`= 43622;
UPDATE `creature_template` SET `minlevel`= 87, `maxlevel`= 87, `exp`= 3, `faction`= 16, `DamageModifier`= 60, `BaseVariance`= 0.5, `movementId`= 156, `mechanic_immune_mask`= 80297855, `flags_extra`= 536870912 WHERE `entry` IN (50184, 50185, 50186, 43622);
-- Blood of the Old God
UPDATE `creature_template` SET `difficulty_entry_1`= 50168, `difficulty_entry_2`= 50169, `difficulty_entry_3`= 50170, `ScriptName`= 'npc_chogall_blood_of_the_old_god' WHERE `entry`= 43707;
UPDATE `creature_template` SET `minlevel`= 87, `maxlevel`= 87, `exp`= 3, `faction`= 16, `DamageModifier`= 30, `BaseVariance`= 0.5, `movementId`= 106, `mechanic_immune_mask`= 65536 | 131072 | 512 | 16 | 1 | 2 | 32, `flags_extra`= 536870912 | 256 WHERE `entry` IN (50168, 50169, 50170, 43707);
-- Corruption
UPDATE `creature_template` SET `InhabitType`= 12, `unit_flags`= 33554432, `flags_extra`= 128 WHERE `entry`= 43999;
-- Malformation
UPDATE `creature_template` SET `unit_flags`= 33554432, `unit_flags2`= 2164736, `ScriptName`= 'npc_chogall_malformation' WHERE `entry`= 43888;
-- Darkened Creation (Dummy)
UPDATE `creature_template` SET `difficulty_entry_1`= 50187, `difficulty_entry_2`= 50188, `difficulty_entry_3`= 50189, `ScriptName`= 'npc_chogall_darkened_creation' WHERE `entry`= 44045;
UPDATE `creature_template` SET `minlevel`= 87, `maxlevel`= 87, `exp`= 3, `faction`= 14, `movementId`= 94, `unit_flags`= 33554432, `unit_flags2`= 2099200, `InhabitType`= 12, `flags_extra`= 128 | 1073741824, `mechanic_immune_mask`= 80297855 WHERE `entry` IN (44045, 50187, 50188, 50189);
-- Darkened Creation (Transform)
UPDATE `creature_template` SET `difficulty_entry_1`= 50190, `difficulty_entry_2`= 50191, `difficulty_entry_3`= 50192 WHERE `entry`= 44023;
UPDATE `creature_template` SET `minlevel`= 87, `maxlevel`= 87, `exp`= 3, `faction`= 14, `movementId`= 118, `InhabitType`= 12, `flags_extra`= 1073741824, `mechanic_immune_mask`= 80297855 WHERE `entry` IN (44023, 50190, 50191, 50192);
-- Spiked Tentacle (Trigger)
UPDATE `creature_template` SET `unit_flags`= 33554432, `unit_flags2`= 2099200, `InhabitType`= 12, `flags_extra`= 128  WHERE `entry`= 50265;
-- Spiked Tentacle
UPDATE `creature_template` SET `InhabitType`= 12, `DamageModifier`= 30, `BaseVariance`= 0.5, `flags_extra`= 1073741824, `mechanic_immune_mask`= 80297855, `ScriptName`= 'npc_chogall_spiked_tentacle' WHERE `entry`= 50264;

-- Template Addons
DELETE FROM `creature_template_addon` WHERE `entry` IN (43393, 43603, 43585, 43707, 43888, 50265, 50168, 50169, 50170);
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(43393, '81172'),
(43603, '81559'),
(43585, '81536'),
(43707, '81777'),
(50168, '81777'),
(50169, '81777'),
(50170, '81777'),
(43888, '82167'),
(50265, '93318');

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_chogall_absorb_elemental_reverse_cast',
'spell_chogall_absorb_elemental',
'spell_chogall_absorb_elemental_heroic',
'spell_chogall_elemental_power',
'spell_chogall_flaming_destruction_heroic',
'spell_chogall_empowered_shadows_heroic',
'spell_chogall_summon_corrupted_adherent',
'spell_chogall_fester_blood',
'spell_chogall_fester_blood_summon',
'spell_chogall_conversion',
'spell_chogall_worshipping',
'spell_chogall_consume_blood_of_the_old_god',
'spell_chogall_consume_blood_of_the_old_god_triggered',
'spell_chogall_corruption_significant',
'spell_chogall_corruption_normal',
'spell_chogall_corruption_normal_alternative',
'spell_chogall_corruption_of_the_old_god',
'spell_chogall_corruption_sickness',
'spell_chogall_corruption_malformation',
'spell_chogall_shadow_bolt',
'spell_chogall_debilitating_beam');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(81233, 'spell_chogall_absorb_elemental_reverse_cast'),
(81565, 'spell_chogall_absorb_elemental_reverse_cast'),
(81196, 'spell_chogall_absorb_elemental'),
(93241, 'spell_chogall_absorb_elemental'),
(93242, 'spell_chogall_absorb_elemental_heroic'),
(93243, 'spell_chogall_absorb_elemental_heroic'),
(81566, 'spell_chogall_absorb_elemental'),
(93238, 'spell_chogall_absorb_elemental'),
(93239, 'spell_chogall_absorb_elemental_heroic'),
(93240, 'spell_chogall_absorb_elemental_heroic'),
(93245, 'spell_chogall_elemental_power'),
(93301, 'spell_chogall_elemental_power'),
(93265, 'spell_chogall_flaming_destruction_heroic'),
(93266, 'spell_chogall_flaming_destruction_heroic'),
(93219, 'spell_chogall_empowered_shadows_heroic'),
(93220, 'spell_chogall_empowered_shadows_heroic'),
(81628, 'spell_chogall_summon_corrupted_adherent'),
(82299, 'spell_chogall_fester_blood'),
(82337, 'spell_chogall_fester_blood_summon'),
(93111, 'spell_chogall_fester_blood_summon'),
(93112, 'spell_chogall_fester_blood_summon'),
(93113, 'spell_chogall_fester_blood_summon'),
(91303, 'spell_chogall_conversion'),
(93203, 'spell_chogall_conversion'),
(93204, 'spell_chogall_conversion'),
(93205, 'spell_chogall_conversion'),
(91317, 'spell_chogall_worshipping'),
(93365, 'spell_chogall_worshipping'),
(93366, 'spell_chogall_worshipping'),
(93367, 'spell_chogall_worshipping'),
(82630, 'spell_chogall_consume_blood_of_the_old_god'),
(82659, 'spell_chogall_consume_blood_of_the_old_god_triggered'),
(81713, 'spell_chogall_corruption_significant'),
(93175, 'spell_chogall_corruption_significant'),
(93176, 'spell_chogall_corruption_significant'),
(93177, 'spell_chogall_corruption_significant'),
(82919, 'spell_chogall_corruption_normal'),
(93108, 'spell_chogall_corruption_normal'),
(93109, 'spell_chogall_corruption_normal'),
(93110, 'spell_chogall_corruption_normal'),
(81761, 'spell_chogall_corruption_normal'),
(93172, 'spell_chogall_corruption_normal'),
(93173, 'spell_chogall_corruption_normal'),
(93174, 'spell_chogall_corruption_normal'),
(81689, 'spell_chogall_corruption_normal'),
(93184, 'spell_chogall_corruption_normal'),
(93185, 'spell_chogall_corruption_normal'),
(93186, 'spell_chogall_corruption_normal'),
(81831, 'spell_chogall_corruption_normal'),
(93200, 'spell_chogall_corruption_normal'),
(93201, 'spell_chogall_corruption_normal'),
(93202, 'spell_chogall_corruption_normal'),
(81775, 'spell_chogall_corruption_normal_alternative'),
(93209, 'spell_chogall_corruption_normal_alternative'),
(93210, 'spell_chogall_corruption_normal_alternative'),
(93211, 'spell_chogall_corruption_normal_alternative'),
(81943, 'spell_chogall_corruption_normal_alternative'),
(93196, 'spell_chogall_corruption_normal_alternative'),
(93197, 'spell_chogall_corruption_normal_alternative'),
(93198, 'spell_chogall_corruption_normal_alternative'),
(82363, 'spell_chogall_corruption_of_the_old_god'),
(93169, 'spell_chogall_corruption_of_the_old_god'),
(93170, 'spell_chogall_corruption_of_the_old_god'),
(93171, 'spell_chogall_corruption_of_the_old_god'),
(82235, 'spell_chogall_corruption_sickness'),
(82125, 'spell_chogall_corruption_malformation'),
(82151, 'spell_chogall_shadow_bolt'),
(93193, 'spell_chogall_shadow_bolt'),
(93194, 'spell_chogall_shadow_bolt'),
(93195, 'spell_chogall_shadow_bolt'),
(93133, 'spell_chogall_debilitating_beam'),
(93134, 'spell_chogall_debilitating_beam');

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (81233, 81565, 81196, 93241, 93242, 93243, 81566, 93238, 93239, 93240, 81194, 93264, 93265, 93266, 81572, 93218, 93219, 93220, 82299, 91331, 93206, 93207, 93208, 82356, 82630, 82659, 82433) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 81233, 0, 0, 31, 0, 3, 43324, 0, 0, 0, '', 'Absorb Fire Reverse Cast - Target Cho''Gall'),
(13, 1, 81565, 0, 0, 31, 0, 3, 43324, 0, 0, 0, '', 'Absorb Shadow Reverse Cast - Target Cho''Gall'),
(13, 7, 81194, 0, 0, 31, 0, 3, 43324, 0, 0, 0, '', 'Flaming Destruction - Target Cho''Gall'),
(13, 7, 93264, 0, 0, 31, 0, 3, 43324, 0, 0, 0, '', 'Flaming Destruction - Target Cho''Gall'),
(13, 7, 93265, 0, 0, 31, 0, 3, 43324, 0, 0, 0, '', 'Flaming Destruction - Target Cho''Gall'),
(13, 7, 93266, 0, 0, 31, 0, 3, 43324, 0, 0, 0, '', 'Flaming Destruction - Target Cho''Gall'),
(13, 1, 81572, 0, 0, 31, 0, 3, 43324, 0, 0, 0, '', 'Empowered Shadows - Target Cho''Gall'),
(13, 1, 93218, 0, 0, 31, 0, 3, 43324, 0, 0, 0, '', 'Empowered Shadows - Target Cho''Gall'),
(13, 1, 93219, 0, 0, 31, 0, 3, 43324, 0, 0, 0, '', 'Empowered Shadows - Target Cho''Gall'),
(13, 1, 93220, 0, 0, 31, 0, 3, 43324, 0, 0, 0, '', 'Empowered Shadows - Target Cho''Gall'),
(13, 5, 81196, 0, 0, 31, 0, 3, 43406, 0, 0, 0, '', 'Absorb Fire - Target Fire Elemental'),
(13, 5, 93241, 0, 0, 31, 0, 3, 43406, 0, 0, 0, '', 'Absorb Fire - Target Fire Elemental'),
(13, 5, 93242, 0, 0, 31, 0, 3, 43406, 0, 0, 0, '', 'Absorb Fire - Target Fire Elemental'),
(13, 5, 93243, 0, 0, 31, 0, 3, 43406, 0, 0, 0, '', 'Absorb Fire - Target Fire Elemental'),
(13, 5, 81566, 0, 0, 31, 0, 3, 43592, 0, 0, 0, '', 'Absorb Shadow - Target Shadow Lord'),
(13, 5, 93238, 0, 0, 31, 0, 3, 43592, 0, 0, 0, '', 'Absorb Shadow - Target Shadow Lord'),
(13, 5, 93239, 0, 0, 31, 0, 3, 43592, 0, 0, 0, '', 'Absorb Shadow - Target Shadow Lord'),
(13, 5, 93240, 0, 0, 31, 0, 3, 43592, 0, 0, 0, '', 'Absorb Shadow - Target Shadow Lord'),
(13, 3, 82299, 0, 0, 31, 0, 3, 43622, 0, 0, 0, '', 'Fester Blood - Target Corrupting Adherent'),
(13, 3, 91331, 0, 0, 31, 0, 3, 43324, 0, 0, 0, '', 'Twisted Devotion - Target Cho''Gall'),
(13, 3, 93206, 0, 0, 31, 0, 3, 43324, 0, 0, 0, '', 'Twisted Devotion - Target Cho''Gall'),
(13, 3, 93207, 0, 0, 31, 0, 3, 43324, 0, 0, 0, '', 'Twisted Devotion - Target Cho''Gall'),
(13, 3, 93208, 0, 0, 31, 0, 3, 43324, 0, 0, 0, '', 'Twisted Devotion - Target Cho''Gall'),
(13, 1, 82356, 0, 0, 31, 0, 3, 43999, 0, 0, 0, '', 'Corruption of the Old God Visual - Target Corruption'),
(13, 7, 82630, 0, 0, 31, 0, 3, 43622, 0, 0, 0, '', 'Consume Blood of the Old God - Target Corrupting Adherent'),
(13, 1, 82659, 0, 0, 31, 0, 3, 43324, 0, 0, 0, '', 'Consume Blood of the Old God - Target Cho''Gall'),
(13, 1, 82433, 0, 0, 31, 0, 3, 43324, 0, 0, 0, '', 'Darkened Creations - Target Cho''Gall');

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID`= 43324;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(43324, 0, 0, 'Valiona, Theralion, put them in their place.', 14, 0, 100, 0, 0, 22063, 47518, 3, 'Cho''gall - Theralion and Valiona Intro'),
(43324, 1, 0, '(Come closer, closer.  Let us see your faces. All will be humbled before his power.)', 14, 0, 100, 0, 0, 22064, 47538, 3, 'Cho''gall - Theralion and Valiona Death'),
(43324, 2, 0, 'Welcome, mortals. (Frail little children). Few have laid eyes on this inner sanctum. (They reach out to touch the fire!)', 14, 0, 100, 0, 0, 22065, 47585, 3, 'Cho''gall - Ascendant Council 1'),
(43324, 3, 0, 'It is here the chosen realize their destiny. (One with eternity). And it is here that you will realize yours.(End of the flesh. End of the flesh)!', 14, 0, 100, 0, 0, 22066, 47587, 3, 'Cho''gall - Ascendant Council 2'),
(43324, 4, 0, 'Brothers of Twilight! The Hammer calls to you! (Fire water earth air). Leave your mortal shell behind. (Fire water earth air). Embrace your new forms for here and everafter! (Burn and drown and crush and suffocate). And use your gifts to destroy the unbelievers. (Burn and drown and crush and suffocate)!!', 14, 0, 100, 0, 0, 22067, 47588, 3, 'Cho''gall - Ascendant Council 3'),
(43324, 5, 0, 'Foolish mortals-(Usurper''s children!) nothing you have done- (Spawn of a lesser god!) I am TRYING to speak here. (Words, words, words. The Master wants murder.) ALL falls to chaos. ALL will be destroyed. (Chaos, chaos!) Your work here today changes nothing. (Chaos, chaos, all things end) No mortal may see what you have and live. Your end has come.', 14, 0, 100, 0, 0, 22068, 47591, 3, 'Cho''gall - Intro'),
(43324, 6, 0, 'Enough! (To His will all flesh succumbs. From His kingdom, chaos comes.) Yes - what he said.', 14, 0, 100, 0, 0, 22081, 47859, 3, 'Cho''gall - Aggro'),
(43324, 7, 0, 'Behold the might of the hammer!', 14, 0, 100, 0, 0, 22079, 47857, 3, 'Cho''gall - Absorb Fire Elemental 1'),
(43324, 7, 1, 'Give me your strength!', 14, 0, 100, 0, 0, 22078, 47856, 3, 'Cho''gall - Absorb Fire Elemental 1l'),
(43324, 8, 0, '(Stop. Hammertime!)', 14, 0, 100, 0, 0, 22080, 47858, 3, 'Cho''gall - Absorb Shadow Lorb'),
(43324, 9, 0, '|TInterface\\Icons\\ability_rogue_shadowdance.blp:20|t%s begins to summon |cFFFF0000Corrupted Adherents|r to aid him!\n', 41, 0, 100, 0, 0, 0, 44484, 3, 'Cho''gall - Announce Corrupting Adherents'),
(43324, 10, 0, '(*Snort*)', 14, 0, 100, 0, 0, 22083, 47861, 3, 'Cho''gall - Corrupting Adherents 1'),
(43324, 10, 1, '(Infinite suffering!)', 14, 0, 100, 0, 0, 22082, 47860, 3, 'Cho''gall - Corrupting Adherents 2'),
(43324, 10, 2, 'More. More!', 14, 0, 100, 0, 0, 22085, 47863, 3, 'Cho''gall - Corrupting Adherents 3'),
(43324, 10, 3, '(Come, brothers! Feast on hope!)', 14, 0, 100, 0, 0, 22086, 47864, 3, 'Cho''gall - Corrupting Adherents 4'),
(43324, 11, 0, 'Cho''gall beckons and casts |cFF006EFD|Hspell:91303|h[Conversion]|h|r!', 41, 0, 100, 0, 0, 0, 49084, 3, 'Cho''gall - Announce Conversion'),
(43324, 12, 0, '|TInterface\\Icons\\spell_shadow_shadetruesight.blp:20|t%s begins to cast |cFFFF0000|Hspell:82299|h[Fester Blood]|h|r!', 41, 0, 100, 0, 0, 0, 45715, 3, 'Cho''gall - Announce Fester Blood'),
(43324, 13, 0, 'Brother, it cannot be... (Destiny has come!) My strength... (Too proud! He speaks in blood! Listen!) My mind... (It is for His glory we serve!) What... is happening... (Gone is the dawn. Come shades of Twilight. Come madness, come havoc, come Infinite Night!)', 14, 0, 100, 0, 0, 22093, 47868, 3, 'Cho''gall - Phase 2'),
(43324, 14, 0, '|TInterface\\Icons\\spell_shadow_shadesofdarkness.blp:20|t%s begins to summon |cFFFF0000Darkened Creations|r to aid him!\n', 41, 0, 100, 0, 0, 0, 47897, 3, 'Cho''gall - Announce Darkened Creations'),
(43324, 15, 0, '(The claws of fate grasp the unbelievers!)', 14, 0, 100, 0, 0, 22094, 47899, 3, 'Cho''gall - Say Darkened Creations 1'),
(43324, 15, 1, '(The Master sees, the Master sees!)', 14, 0, 100, 0, 0, 22095, 47900, 3, 'Cho''gall - Say Darkened Creations 2'),
(43324, 15, 2, 'What madness have we wrought? (Not yet enough!)', 14, 0, 100, 0, 0, 22096, 47901, 3, 'Cho''gall - Say Darkened Creations 3'),
(43324, 15, 3, 'I...  can''t take much more... (Brother, it merely begins!)', 14, 0, 100, 0, 0, 22097, 47902, 3, 'Cho''gall - Say Darkened Creations 4'),
(43324, 15, 4, '(The Master''s eye sees all that was and all to be, or not!)', 14, 0, 100, 0, 0, 22098, 47903, 3, 'Cho''gall - Say Darkened Creations 5'),
(43324, 16, 0, '(Body and soul, to be swallowed whole!)', 14, 0, 100, 0, 0, 22088, 47882, 3, 'Cho''gall - Slay 1'),
(43324, 16, 1, 'Everyone succumbs in the end.', 14, 0, 100, 0, 0, 22089, 47883, 3, 'Cho''gall - Slay 1'),
(43324, 16, 2, '(Now they see the darkness! Their eyes are open!)', 14, 0, 100, 0, 0, 22090, 47884, 3, 'Cho''gall - Slay 1'),
(43324, 16, 3, 'Now the Master has them.', 14, 0, 100, 0, 0, 22091, 47885, 3, 'Cho''gall - Slay 2'),
(43324, 16, 4, '(Chaos, madness! Like a hug for your brain.)', 14, 0, 100, 0, 0, 22092, 47886, 3, 'Cho''gall - Slay 3'),
(43324, 16, 5, '(Blood for the master!)', 14, 0, 100, 0, 0, 22069, 47851, 3, 'Cho''gall - Slay 4'),
(43324, 16, 6, '(Finish it! Finish them all!)', 14, 0, 100, 0, 0, 22072, 47854, 3, 'Cho''gall - Slay 5'),
(43324, 17, 0, 'It is finished. (The fate of all.)', 14, 0, 100, 0, 0, 22101, 47892, 3, 'Cho''gall - Evade'),
(43324, 18, 0, 'Brother, we are shattered. (But the Master... I still hear... so angry... Master...?)', 14, 0, 100, 0, 0, 22099, 47893, 3, 'Cho''gall - Death Normal'),
(43324, 19, 0, 'Brother, we are shattered. Let her finish them. (The Master does not want them near her... Brother?  The Master seethes...)', 14, 0, 100, 0, 0, 22100, 47894, 3, 'Cho''gall - Death Heroic');

-- Achievement
DELETE FROM `achievement_criteria_data` WHERE `criteria_id`= 15673;
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(15673, 11, 0, 0, 'achievement_the_abyss_will_gaze_into_you');

-- Areatriggers
DELETE FROM `areatrigger_scripts` WHERE `entry` IN (6625, 6626, 6627, 6444);
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(6625, 'at_ascendant_council_intro_1'),
(6626, 'at_ascendant_council_intro_2'),
(6627, 'at_ascendant_council_intro_3'),
(6444, 'at_chogall_intro');

-- Spell Target Positions
UPDATE `spell_target_position` SET `Orientation`= 3.189992 WHERE `ID`= 82712;
UPDATE `spell_target_position` SET `Orientation`= 0.2274163 WHERE `ID`= 82713;

-- Gold Loot
-- 10 Player
UPDATE `creature_template` SET `mingold`= 2200000, `maxgold`= 2400000 WHERE `entry` IN (43324, 50132);
-- 25 Player
UPDATE `creature_template` SET `mingold`= 4900000, `maxgold`= 5100000 WHERE `entry` IN (50131, 50133);

-- Currency Loot
DELETE FROM `creature_onkill_reward` WHERE `creature_id` IN (50131, 50132, 50133, 43324);
INSERT INTO `creature_onkill_reward` (`creature_id`, `CurrencyId1`, `CurrencyCount1`) VALUES
(43324, 396, 11500),
(50131, 396, 13500),
(50132, 396, 11500),
(50133, 396, 13500);
