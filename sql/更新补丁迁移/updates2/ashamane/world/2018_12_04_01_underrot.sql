DELETE FROM `areatrigger_template` WHERE `Id` IN (16966, 17014, 17026, 17135, 17928, 19287);
INSERT INTO `areatrigger_template` (`Id`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `VerifiedBuild`) VALUES
(16966, 4, 4, 1, 1, 3, 3, 0.3, 0.3, 28153),
(17014, 1, 4, 2.5, 2.5, 7.5, 2.5, 2.5, 7.5, 28153),
(17026, 0, 4, 1.35, 1.35, 0, 0, 0, 0, 28153),
(17135, 4, 4, 2.5, 2.5, 20, 20, 0.3, 0.3, 28153),
(17928, 0, 0, 5, 5, 0, 0, 0, 0, 28153),
(19287, 0, 2, 1, 5, 0, 0, 0, 0, 28153);

UPDATE `areatrigger_template` SET `VerifiedBuild`=28153 WHERE `Id`=3319;
UPDATE `areatrigger_template` SET `VerifiedBuild`=28153 WHERE `Id`=3983;
UPDATE `areatrigger_template` SET `VerifiedBuild`=28153 WHERE `Id`=7020;
UPDATE `areatrigger_template` SET `VerifiedBuild`=28153 WHERE `Id`=10665;
UPDATE `areatrigger_template` SET `VerifiedBuild`=28153 WHERE `Id`=10714;
UPDATE `areatrigger_template` SET `VerifiedBuild`=28153 WHERE `Id`=10727;
UPDATE `areatrigger_template` SET `VerifiedBuild`=28153 WHERE `Id`=11266;

DELETE FROM `spell_areatrigger` WHERE (`SpellMiscId`=12266 AND `AreaTriggerId`=16966) OR (`SpellMiscId`=12319 AND `AreaTriggerId`=17014) OR (`SpellMiscId`=12334 AND `AreaTriggerId`=17026) OR (`SpellMiscId`=12454 AND `AreaTriggerId`=17135) OR (`SpellMiscId`=13334 AND `AreaTriggerId`=17928) OR (`SpellMiscId`=14607 AND `AreaTriggerId`=19287);
INSERT INTO `spell_areatrigger` (`SpellMiscId`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `VerifiedBuild`) VALUES
(12266, 16966, 0, 0, 0, 0, 0, 0, 0, 28153), -- SpellId : 259727
(12319, 17014, 0, 0, 0, 0, 0, 0, 10000, 28153), -- SpellId : 260292
(12334, 17026, 0, 0, 0, 0, 0, 0, 12000, 28153), -- SpellId : 260411
(12454, 17135, 0, 0, 0, 0, 0, 0, 10000, 28153), -- SpellId : 261496
(13334, 17928, 0, 0, 0, 0, 338, 0, 180000, 28153), -- SpellId : 269836
(14607, 19287, 0, 0, 7186, 0, 31, 0, 30000, 28153); -- SpellId : 265668

UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=28153 WHERE (`SpellMiscId`=383 AND `AreaTriggerId`=3319); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=5000, `VerifiedBuild`=28153 WHERE (`SpellMiscId`=718 AND `AreaTriggerId`=3983); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=120000, `VerifiedBuild`=28153 WHERE (`SpellMiscId`=2442 AND `AreaTriggerId`=7020); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=20000, `VerifiedBuild`=28153 WHERE (`SpellMiscId`=5977 AND `AreaTriggerId`=10665); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=1000, `VerifiedBuild`=28153 WHERE (`SpellMiscId`=6027 AND `AreaTriggerId`=10714); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=28153 WHERE (`SpellMiscId`=6039 AND `AreaTriggerId`=10727); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=20000, `VerifiedBuild`=28153 WHERE (`SpellMiscId`=6710 AND `AreaTriggerId`=11266); -- SpellId : 0

DELETE FROM `conversation_actors` WHERE (`ConversationId`=9670 AND `Idx`=1) OR (`ConversationId`=9671 AND `Idx`=1) OR (`ConversationId`=9672 AND `Idx`=1) OR (`ConversationId`=9674 AND `Idx`=1);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorNearId`, `Idx`, `VerifiedBuild`) VALUES
(9670, 120649, 0, 1, 28153),
(9671, 120649, 0, 1, 28153),
(9672, 120649, 0, 1, 28153),
(9674, 120649, 0, 1, 28153);


DELETE FROM `conversation_actor_template` WHERE `Id` IN (119889, 120649);
INSERT INTO `conversation_actor_template` (`Id`, `CreatureId`, `CreatureModelId`, `VerifiedBuild`) VALUES
(119889, 0, 26353, 28153),
(120649, 0, 75898, 28153);


DELETE FROM `conversation_line_template` WHERE `Id` IN (22105, 22106, 22110, 22111, 22113, 22114, 22120, 22121);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Flags`, `VerifiedBuild`) VALUES
(22105, 0, 1243, 1, 0, 28153),
(22106, 5808, 1243, 1, 0, 28153),
(22110, 0, 1243, 1, 0, 28153),
(22111, 4591, 1243, 1, 0, 28153),
(22113, 0, 1243, 1, 0, 28153),
(22114, 4754, 1243, 1, 0, 28153),
(22120, 0, 1243, 1, 0, 28153),
(22121, 6001, 1243, 1, 0, 28153);


DELETE FROM `conversation_template` WHERE `Id` IN (9670, 9671, 9672, 9674);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `LastLineEndTime`, `VerifiedBuild`) VALUES
(9670, 22105, 11917, 28153),
(9671, 22110, 9999, 28153),
(9672, 22113, 9995, 28153),
(9674, 22120, 10928, 28153);


DELETE FROM `gameobject_template_addon` WHERE `entry` IN (296384 /*Pyramid Web*/, 296385 /*Pyramid Door*/, 295356 /*Wall*/, 295354 /*Web*/, 295355 /*Web*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`) VALUES
(296384, 1375, 48), -- Pyramid Web
(296385, 1375, 48), -- Pyramid Door
(295356, 1375, 48), -- Wall
(295354, 1375, 48), -- Web
(295355, 1375, 48); -- Web


DELETE FROM `creature_template_addon` WHERE `entry` IN (140366 /*140366 (Princess Talanji)*/, 133007 /*133007 - Blood Barrier*/, 138538 /*138538 (Abyssal Reach) - Void Tentacle Cosmetic Base*/, 144306 /*144306 (Bloodsworn Defiler) - Mod Scale 175%*/, 134419 /*134419 (Titan Keeper Hezrel) - Shadow Visual State*/, 138740 /*138740 (Musashitake) - 8.0 Underrot Dungeon - Sporecaller Zancha -  Achievement Add Visual*/, 131383 /*131383 (Sporecaller Zancha)*/, 134284 /*134284 (Fallen Deathspeaker) - Deathspeaker Spawn*/, 138281 /*138281 (Faceless Corruptor)*/, 131817 /*131817 (Cragmaw the Infested) - Crawg Eating*/, 133836 /*133836 (Reanimated Guardian) - Bone Spirit Aura*/, 132137 /*132137 (Cosmetic Blood Tick) - Ride Vehicle Hardcoded, Mod Scale 90-100%*/, 138187 /*138187 (Grotesque Horror) - Submerged, Tentacle Base*/, 133912 /*133912 (Bloodsworn Defiler) - Mod Scale 175%*/, 133852 /*133852 (Living Rot)*/, 131318 /*131318 (Elder Leaxa)*/, 133835 /*133835 (Feral Bloodswarmer)*/, 133870 /*133870 (Diseased Lasher)*/, 133685 /*133685 (Befouled Spirit) - Ride Vehicle Hardcoded*/, 131436 /*131436 (Chosen Blood Matron)*/, 133663 /*133663 (Fanatical Headhunter) - Mod Scale +25%*/, 131492 /*131492 (Devout Blood Priest) - Mod Scale +25%*/, 135219 /*135219 (Befouled Spirit Stalker)*/, 131402 /*131402 (Underrot Tick)*/, 130909 /*130909 (Fetid Maggot)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(140366, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 140366 (Princess Talanji)
(133007, 0, 0, 0, 1, 0, 0, 0, 0, '269185'), -- 133007 - Blood Barrier
(138538, 0, 0, 0, 1, 0, 0, 0, 0, '277677'), -- 138538 (Abyssal Reach) - Void Tentacle Cosmetic Base
(144306, 0, 0, 0, 1, 0, 0, 0, 0, '222912'), -- 144306 (Bloodsworn Defiler) - Mod Scale 175%
(134419, 0, 0, 8, 1, 0, 0, 0, 0, '279551'), -- 134419 (Titan Keeper Hezrel) - Shadow Visual State
(138740, 0, 0, 0, 1, 0, 0, 0, 0, '272773'), -- 138740 (Musashitake) - 8.0 Underrot Dungeon - Sporecaller Zancha -  Achievement Add Visual
(131383, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 131383 (Sporecaller Zancha)
(134284, 0, 0, 0, 1, 0, 0, 0, 0, '263835'), -- 134284 (Fallen Deathspeaker) - Deathspeaker Spawn
(138281, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 138281 (Faceless Corruptor)
(131817, 0, 0, 0, 1, 0, 0, 0, 0, '279156'), -- 131817 (Cragmaw the Infested) - Crawg Eating
(133836, 0, 0, 0, 1, 0, 0, 0, 0, '271872'), -- 133836 (Reanimated Guardian) - Bone Spirit Aura
(132137, 0, 0, 0, 1, 0, 0, 0, 0, '46598 237007'), -- 132137 (Cosmetic Blood Tick) - Ride Vehicle Hardcoded, Mod Scale 90-100%
(138187, 0, 0, 0, 1, 0, 0, 0, 0, '177645 271955'), -- 138187 (Grotesque Horror) - Submerged, Tentacle Base
(133912, 0, 0, 0, 1, 0, 0, 0, 0, '222912'), -- 133912 (Bloodsworn Defiler) - Mod Scale 175%
(133852, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 133852 (Living Rot)
(131318, 0, 0, 0, 1, 0, 13325, 0, 0, ''), -- 131318 (Elder Leaxa)
(133835, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 133835 (Feral Bloodswarmer)
(133870, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 133870 (Diseased Lasher)
(133685, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- 133685 (Befouled Spirit) - Ride Vehicle Hardcoded
(131436, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 131436 (Chosen Blood Matron)
(133663, 0, 0, 0, 1, 0, 0, 0, 0, '236530'), -- 133663 (Fanatical Headhunter) - Mod Scale +25%
(131492, 0, 0, 0, 1, 0, 0, 0, 0, '236530'), -- 131492 (Devout Blood Priest) - Mod Scale +25%
(135219, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 135219 (Befouled Spirit Stalker)
(131402, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 131402 (Underrot Tick)
(130909, 0, 0, 0, 1, 0, 0, 0, 0, ''); -- 130909 (Fetid Maggot)

UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=63420; -- 63420 (SLG Generic MoP)

DELETE FROM `creature_template_scaling` WHERE `Entry` IN (130909, 131318, 131383, 131402, 131436, 131492, 131817, 133007, 133663, 133685, 133835, 133836, 133852, 133870, 133912, 134284, 138187, 138281, 138538, 144306);
INSERT INTO `creature_template_scaling` (`Entry`, `LevelScalingMin`, `LevelScalingMax`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `VerifiedBuild`) VALUES
(130909, 110, 120, 0, 0, 28153),
(131318, 110, 120, 2, 2, 28153),
(131383, 110, 120, 2, 2, 28153),
(131402, 110, 120, 0, 0, 28153),
(131436, 110, 120, 1, 1, 28153),
(131492, 110, 120, 0, 0, 28153),
(131817, 110, 120, 2, 2, 28153),
(133007, 110, 120, 2, 2, 28153),
(133663, 110, 120, 0, 0, 28153),
(133685, 110, 120, 1, 1, 28153),
(133835, 110, 120, 0, 0, 28153),
(133836, 110, 120, 0, 0, 28153),
(133852, 110, 120, 0, 0, 28153),
(133870, 110, 120, 0, 0, 28153),
(133912, 110, 120, 1, 1, 28153),
(134284, 110, 120, 0, 0, 28153),
(138187, 110, 120, 0, 0, 28153),
(138281, 110, 120, 1, 1, 28153),
(138538, 110, 120, 0, 0, 28153),
(144306, 110, 120, 1, 1, 28153);


DELETE FROM `creature_model_info` WHERE `DisplayID` IN (85815, 88121, 84808, 79182, 83311, 82394, 76653, 80852, 85816, 84145, 81808, 88361);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(85815, 0.4340275, 1.875, 0, 28153),
(88121, 0.7558168, 1.875, 0, 28153),
(84808, 2.291631, 5.625, 0, 28153),
(79182, 1.01514, 2.25, 0, 28153),
(83311, 0.465, 3.75, 0, 28153),
(82394, 1.260033, 2.7, 0, 28153),
(76653, 2.170667, 1, 0, 28153),
(80852, 5, 7.5, 0, 28153),
(85816, 1.830752, 4.05, 0, 28153),
(84145, 2.5, 5, 0, 28153),
(81808, 0.24, 0.24, 0, 28153),
(88361, 0.9375, 1.5625, 0, 28153);

UPDATE `creature_model_info` SET `BoundingRadius`=6.026552, `CombatReach`=8, `VerifiedBuild`=28153 WHERE `DisplayID`=86632;
UPDATE `creature_model_info` SET `BoundingRadius`=2.656178, `CombatReach`=1.5, `VerifiedBuild`=28153 WHERE `DisplayID`=76612;
UPDATE `creature_model_info` SET `VerifiedBuild`=28153 WHERE `DisplayID`=81377;
UPDATE `creature_model_info` SET `VerifiedBuild`=28153 WHERE `DisplayID`=76851;
UPDATE `creature_model_info` SET `BoundingRadius`=1.075765, `CombatReach`=3 WHERE `DisplayID`=83603;
UPDATE `creature_model_info` SET `BoundingRadius`=2.545106, `VerifiedBuild`=28153 WHERE `DisplayID`=79570;
UPDATE `creature_model_info` SET `VerifiedBuild`=28153 WHERE `DisplayID`=84376;
UPDATE `creature_model_info` SET `BoundingRadius`=3.307138, `CombatReach`=4.95, `VerifiedBuild`=28153 WHERE `DisplayID`=78855;
UPDATE `creature_model_info` SET `BoundingRadius`=0.125, `CombatReach`=0.125, `VerifiedBuild`=28153 WHERE `DisplayID`=80459;
UPDATE `creature_model_info` SET `BoundingRadius`=0.6912601, `CombatReach`=1.5, `VerifiedBuild`=28153 WHERE `DisplayID`=79499;
UPDATE `creature_model_info` SET `BoundingRadius`=0.35, `CombatReach`=1, `VerifiedBuild`=28153 WHERE `DisplayID`=80467;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3222358, `CombatReach`=0.15, `VerifiedBuild`=28153 WHERE `DisplayID`=80910;
UPDATE `creature_model_info` SET `VerifiedBuild`=28153 WHERE `DisplayID`=43156;
UPDATE `creature_model_info` SET `BoundingRadius`=0.6912601, `CombatReach`=1.5, `VerifiedBuild`=28153 WHERE `DisplayID`=79502;
UPDATE `creature_model_info` SET `BoundingRadius`=0.6912601, `CombatReach`=1.5, `VerifiedBuild`=28153 WHERE `DisplayID`=79501;
UPDATE `creature_model_info` SET `VerifiedBuild`=28153 WHERE `DisplayID`=81380;
UPDATE `creature_model_info` SET `BoundingRadius`=0.6912601, `CombatReach`=1.5, `VerifiedBuild`=28153 WHERE `DisplayID`=79500;
UPDATE `creature_model_info` SET `VerifiedBuild`=28153 WHERE `DisplayID`=75861;

DELETE FROM `creature_equip_template` WHERE (`CreatureID`=140366 AND `ID`=1) OR (`CreatureID`=138740 AND `ID`=1) OR (`CreatureID`=134284 AND `ID`=1) OR (`CreatureID`=133836 AND `ID`=1) OR (`CreatureID`=131318 AND `ID`=1) OR (`CreatureID`=133663 AND `ID`=1) OR (`CreatureID`=131492 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(140366, 1, 126524, 0, 0, 0, 0, 0, 0, 0, 0), -- Princess Talanji
(138740, 1, 3366, 0, 0, 0, 0, 0, 0, 0, 0), -- Musashitake
(134284, 1, 156985, 0, 0, 0, 0, 0, 0, 0, 0), -- Fallen Deathspeaker
(133836, 1, 156942, 0, 0, 0, 0, 0, 0, 0, 0), -- Reanimated Guardian
(131318, 1, 159652, 0, 0, 0, 0, 0, 0, 0, 0), -- Elder Leaxa
(133663, 1, 153589, 0, 0, 0, 0, 0, 0, 0, 0), -- Fanatical Headhunter
(131492, 1, 154977, 0, 0, 0, 0, 0, 0, 0, 0); -- Devout Blood Priest

-- INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
-- (131318, @GROUP_ID+0, @ID+, 'For de glory of G\'huun!', 14, 0, 100, 0, 0, 101028, 148173, 'Elder Leaxa to Player'),
-- (131318, @GROUP_ID+1, @ID+, 'Rot and wither!', 14, 0, 100, 0, 0, 101026, 148211, 'Elder Leaxa to Player'),
-- (131318, @GROUP_ID+2, @ID+, 'G\'huun be everywhere!', 14, 0, 100, 0, 0, 101025, 148212, 'Elder Leaxa'),
-- (131318, @GROUP_ID+3, @ID+, '|TINTERFACE\\ICONS\\INV_TikiMan2_Bloodtroll.blp:20|t Elder Leaxa begins to cast |cFFF00000|Hspell:264603|h[Blood Mirror]|h|r!', 41, 0, 100, 0, 0, 101025, 157334, 'Elder Leaxa'),
-- (131318, @GROUP_ID+4, @ID+, 'My blood for G\'huun...', 14, 0, 100, 0, 0, 101030, 148175, 'Elder Leaxa to Wild Sabertusk'),
-- (131383, @GROUP_ID+0, @ID+, 'Harvest!', 14, 0, 100, 0, 0, 109965, 143939, 'Sporecaller Zancha to Player'),
-- (131383, @GROUP_ID+1, @ID+, 'Corruption blooms!', 14, 0, 100, 0, 0, 109962, 143953, 'Sporecaller Zancha'),
-- (131383, @GROUP_ID+2, @ID+, 'Everything... decays...', 14, 0, 100, 0, 0, 109966, 143960, 'Sporecaller Zancha to Player'),
-- (133007, @GROUP_ID+0, @ID+, 'Devour! Consume! Spread!', 14, 0, 100, 0, 0, 102970, 151959, 'Unbound Abomination to Player'),
-- (133007, @GROUP_ID+1, @ID+, 'Infected!', 14, 0, 100, 0, 0, 102967, 151928, 'Unbound Abomination'),
-- (133007, @GROUP_ID+2, @ID+, 'Must... spread...', 14, 0, 100, 0, 0, 102966, 151930, 'Unbound Abomination to Blood Visage'),
-- (134419, @GROUP_ID+0, @ID+, 'Massive breach detected.', 14, 0, 100, 0, 0, 104792, 151963, 'Titan Keeper Hezrel to Faceless Corruptor'),
-- (134419, @GROUP_ID+1, @ID+, 'G\'huun containment failing. M.O.T.H.E.R. not responding.', 14, 0, 100, 0, 0, 104786, 151957, 'Titan Keeper Hezrel to Faceless Corruptor'),
-- (134419, @GROUP_ID+2, @ID+, 'Planetary infection imminent.', 14, 0, 100, 0, 0, 104793, 151971, 'Titan Keeper Hezrel to Player'),
-- (134419, @GROUP_ID+3, @ID+, 'Virulent specimen detected. Containment priority one.', 14, 0, 100, 0, 0, 104794, 151960, 'Titan Keeper Hezrel to Faceless Corruptor'),
-- (134419, @GROUP_ID+4, @ID+, '|TINTERFACE\\ICONS\\SPELL_HOLY_DIVINEPROVIDENCE:20|t Titan Keeper Hezrel begins to cast |cFFF00000|Hspell:269310|h[Cleansing Light]|h|r!', 41, 0, 100, 0, 0, 104788, 156522, 'Titan Keeper Hezrel'),
-- (134419, @GROUP_ID+5, @ID+, 'Cleansing area.', 14, 0, 100, 0, 0, 104788, 151937, 'Titan Keeper Hezrel'),
-- (134419, @GROUP_ID+6, @ID+, 'Purge protocols engaged.', 14, 0, 100, 0, 0, 104789, 151936, 'Titan Keeper Hezrel to Blood Visage'),
-- (134419, @GROUP_ID+7, @ID+, 'Contagion detected. Sanitize.', 14, 0, 100, 0, 0, 104790, 151941, 'Titan Keeper Hezrel to Blood Visage'),
-- (134419, @GROUP_ID+8, @ID+, 'Engaging final safeguard. Destroy virulent source.', 14, 0, 100, 0, 0, 104791, 151939, 'Titan Keeper Hezrel to Unbound Abomination');

INSERT IGNORE INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(135219, 133685, 0, 1, 'Befouled Spirit Stalker - Befouled Spirit', 6, 0), -- Befouled Spirit Stalker - Befouled Spirit
(131817, 132137, 7, 1, 'Cragmaw the Infested - Cosmetic Blood Tick', 6, 0), -- Cragmaw the Infested - Cosmetic Blood Tick
(131817, 132137, 6, 1, 'Cragmaw the Infested - Cosmetic Blood Tick', 6, 0), -- Cragmaw the Infested - Cosmetic Blood Tick
(131817, 132137, 5, 1, 'Cragmaw the Infested - Cosmetic Blood Tick', 6, 0), -- Cragmaw the Infested - Cosmetic Blood Tick
(131817, 132137, 4, 1, 'Cragmaw the Infested - Cosmetic Blood Tick', 6, 0), -- Cragmaw the Infested - Cosmetic Blood Tick
(131817, 132137, 3, 1, 'Cragmaw the Infested - Cosmetic Blood Tick', 6, 0), -- Cragmaw the Infested - Cosmetic Blood Tick
(131817, 132137, 1, 1, 'Cragmaw the Infested - Cosmetic Blood Tick', 6, 0), -- Cragmaw the Infested - Cosmetic Blood Tick
(131817, 132137, 0, 1, 'Cragmaw the Infested - Cosmetic Blood Tick', 6, 0), -- Cragmaw the Infested - Cosmetic Blood Tick
(131817, 132137, 2, 1, 'Cragmaw the Infested - Cosmetic Blood Tick', 6, 0); -- Cragmaw the Infested - Cosmetic Blood Tick

UPDATE `creature_template` SET `VerifiedBuild`=28153 WHERE `entry`=63420; -- SLG Generic MoP
UPDATE `creature_template` SET `VerifiedBuild`=28153 WHERE `entry`=60849; -- Jade Serpent Statue
UPDATE `creature_template` SET `VerifiedBuild`=28153 WHERE `entry`=76168; -- Ravager
UPDATE `creature_template` SET `VerifiedBuild`=28153 WHERE `entry`=69791; -- Fire Spirit
UPDATE `creature_template` SET `VerifiedBuild`=28153 WHERE `entry`=69792; -- Earth Spirit
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `unit_class`=2, `rank`=1, `type`=7, `type_flags`=2101320, `HealthModifier`=200, `ManaModifier`=50, `VerifiedBuild`=28153 WHERE `entry`=119889; -- Brann Bronzebeard
UPDATE `creature_template` SET `VerifiedBuild`=28153 WHERE `entry`=68553; -- SLG Generic MoP (Large AOI)
UPDATE `creature_template` SET `VerifiedBuild`=28153 WHERE `entry`=139630; -- Blight Recluse
UPDATE `creature_template` SET `VerifiedBuild`=28153 WHERE `entry`=130217; -- Nazmani Weevil
UPDATE `creature_template` SET `VerifiedBuild`=28153 WHERE `entry`=132618; -- Atal'zul Assassin
UPDATE `creature_template` SET `VerifiedBuild`=28153 WHERE `entry`=123135; -- Wild Sabertusk

DELETE FROM `creature_template_model` WHERE (`CreatureID`=140366 AND `CreatureDisplayID`=75898) OR (`CreatureID`=137103 AND `CreatureDisplayID`=84871) OR (`CreatureID`=138338 AND `CreatureDisplayID`=79985) OR (`CreatureID`=138538 AND `CreatureDisplayID`=76612) OR (`CreatureID`=131597 AND `CreatureDisplayID`=11686) OR (`CreatureID`=132051 AND `CreatureDisplayID`=82290) OR (`CreatureID`=132080 AND `CreatureDisplayID`=11686) OR (`CreatureID`=134701 AND `CreatureDisplayID`=82394) OR (`CreatureID`=132398 AND `CreatureDisplayID`=11686) OR (`CreatureID`=132398 AND `CreatureDisplayID`=169) OR (`CreatureID`=144306 AND `CreatureDisplayID`=79182) OR (`CreatureID`=134419 AND `CreatureDisplayID`=76851) OR (`CreatureID`=138740 AND `CreatureDisplayID`=83603) OR (`CreatureID`=131383 AND `CreatureDisplayID`=81977) OR (`CreatureID`=135178 AND `CreatureDisplayID`=11686) OR (`CreatureID`=135178 AND `CreatureDisplayID`=169) OR (`CreatureID`=120649 AND `CreatureDisplayID`=75898) OR (`CreatureID`=134284 AND `CreatureDisplayID`=85815) OR (`CreatureID`=138281 AND `CreatureDisplayID`=84376) OR (`CreatureID`=133836 AND `CreatureDisplayID`=88121) OR (`CreatureID`=131817 AND `CreatureDisplayID`=78855) OR (`CreatureID`=132137 AND `CreatureDisplayID`=80459) OR (`CreatureID`=133912 AND `CreatureDisplayID`=79182) OR (`CreatureID`=138187 AND `CreatureDisplayID`=84808) OR (`CreatureID`=133852 AND `CreatureDisplayID`=83311) OR (`CreatureID`=133870 AND `CreatureDisplayID`=80467) OR (`CreatureID`=131318 AND `CreatureDisplayID`=82394) OR (`CreatureID`=133835 AND `CreatureDisplayID`=76653) OR (`CreatureID`=133685 AND `CreatureDisplayID`=80852) OR (`CreatureID`=135219 AND `CreatureDisplayID`=84145) OR (`CreatureID`=131492 AND `CreatureDisplayID`=75861) OR (`CreatureID`=133663 AND `CreatureDisplayID`=79502) OR (`CreatureID`=133663 AND `CreatureDisplayID`=79501) OR (`CreatureID`=133663 AND `CreatureDisplayID`=79500) OR (`CreatureID`=133663 AND `CreatureDisplayID`=79499) OR (`CreatureID`=131436 AND `CreatureDisplayID`=85816) OR (`CreatureID`=131402 AND `CreatureDisplayID`=81808) OR (`CreatureID`=130909 AND `CreatureDisplayID`=88361);
INSERT INTO `creature_template_model` (`CreatureID`, `Idx`, `CreatureDisplayID`, `DisplayScale`, `Probability`, `VerifiedBuild`) VALUES
(140366, 0, 75898, 1, 1, 28153), -- Princess Talanji
(137103, 0, 84871, 1, 1, 28153), -- Blood Visage
(138338, 0, 79985, 1.4, 1, 28153), -- Reanimated Guardian
(138538, 0, 76612, 0.5, 1, 28153), -- Abyssal Reach
(131597, 0, 11686, 1, 1, 28153), -- Spore Pod
(132051, 0, 82290, 1.33, 1, 28153), -- Blood Tick
(132080, 0, 11686, 1, 1, 28153), -- Blood Tick Larva
(134701, 0, 82394, 1.5, 1, 28153), -- Blood Effigy
(132398, 1, 11686, 1, 1, 28153), -- Blood Wave Stalker
(132398, 0, 169, 1, 0, 28153), -- Blood Wave Stalker
(144306, 0, 79182, 1, 1, 28153), -- Bloodsworn Defiler
(134419, 0, 76851, 1, 1, 28153), -- Titan Keeper Hezrel
(138740, 0, 83603, 1, 1, 28153), -- Musashitake
(131383, 0, 81977, 1.25, 1, 28153), -- Sporecaller Zancha
(135178, 1, 11686, 1, 1, 28153), -- Rotten Bile
(135178, 0, 169, 1, 0, 28153), -- Rotten Bile
(120649, 0, 75898, 1, 1, 28153), -- Princess Talanji
(134284, 0, 85815, 1.25, 1, 28153), -- Fallen Deathspeaker
(138281, 0, 84376, 2, 1, 28153), -- Faceless Corruptor
(133836, 0, 88121, 1.25, 1, 28153), -- Reanimated Guardian
(131817, 0, 78855, 2.25, 1, 28153), -- Cragmaw the Infested
(132137, 0, 80459, 1.25, 1, 28153), -- Cosmetic Blood Tick
(133912, 0, 79182, 1, 1, 28153), -- Bloodsworn Defiler
(138187, 0, 84808, 1.5, 1, 28153), -- Grotesque Horror
(133852, 0, 83311, 1, 1, 28153), -- Living Rot
(133870, 0, 80467, 1, 1, 28153), -- Diseased Lasher
(131318, 0, 82394, 1.5, 1, 28153), -- Elder Leaxa
(133835, 0, 76653, 1, 1, 28153), -- Feral Bloodswarmer
(133685, 0, 80852, 5, 1, 28153), -- Befouled Spirit
(135219, 0, 84145, 5, 1, 28153), -- Befouled Spirit Stalker
(131492, 0, 75861, 1, 1, 28153), -- Devout Blood Priest
(133663, 3, 79502, 1, 1, 28153), -- Fanatical Headhunter
(133663, 2, 79501, 1, 1, 28153), -- Fanatical Headhunter
(133663, 1, 79500, 1, 1, 28153), -- Fanatical Headhunter
(133663, 0, 79499, 1, 1, 28153), -- Fanatical Headhunter
(131436, 0, 85816, 1.5, 1, 28153), -- Chosen Blood Matron
(131402, 0, 81808, 1.6, 1, 28153), -- Underrot Tick
(130909, 0, 88361, 2.5, 1, 28153); -- Fetid Maggot

UPDATE `creature_questitem` SET `VerifiedBuild`=28153 WHERE (`CreatureEntry`=132618 AND `Idx`=0); -- Atal'zul Assassin

DELETE FROM `gameobject_template` WHERE `entry` IN (296384 /*Pyramid Web*/, 296385 /*Pyramid Door*/, 295354 /*Web*/, 295355 /*Web*/, 295356 /*Wall*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `RequiredLevel`, `VerifiedBuild`) VALUES
(296384, 5, 51402, 'Pyramid Web', '', '', '', 2.692498, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Pyramid Web
(296385, 0, 6391, 'Pyramid Door', '', '', '', 3.309999, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Pyramid Door
(295354, 5, 51402, 'Web', '', '', '', 1.904399, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Web
(295355, 5, 51402, 'Web', '', '', '', 1.904399, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Web
(295356, 0, 6391, 'Wall', '', '', '', 2.36, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28153); -- Wall


