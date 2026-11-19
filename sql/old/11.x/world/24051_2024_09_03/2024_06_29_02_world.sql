-- Instance
DELETE FROM `instance_template` WHERE `map`=1862;
INSERT INTO `instance_template` (`map`, `parent`, `script`) VALUES
(1862, 0, 'instance_waycrest_manor');

-- Creature
DELETE FROM `creature` WHERE `guid`=7001260;

UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=500, `StaticFlags1`=805306624, `VerifiedBuild`=55165 WHERE (`Entry`=131824 AND `DifficultyID`=0); -- 131824 (Sister Solena) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=500, `StaticFlags1`=805306624, `VerifiedBuild`=55165 WHERE (`Entry`=131825 AND `DifficultyID`=0); -- 131825 (Sister Briar) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=500, `StaticFlags1`=805306624, `VerifiedBuild`=55165 WHERE (`Entry`=131823 AND `DifficultyID`=0); -- 131823 (Sister Malady) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=500, `VerifiedBuild`=55165 WHERE (`Entry`=132361 AND `DifficultyID`=0); -- 132361 (Focusing Iris) - 

UPDATE `creature_template` SET `ScriptName` = 'boss_sister_briar' WHERE `entry` = 131825;
UPDATE `creature_template` SET `ScriptName` = 'boss_sister_malady' WHERE `entry` = 131823;
UPDATE `creature_template` SET `ScriptName` = 'boss_sister_solena' WHERE `entry` = 131824;

-- Summon Groups
DELETE FROM `creature_summon_groups` WHERE `summonerId`=131824;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`, `Comment`) VALUES
(131824, 0, 0, 132361, -574.691, -151.559, 235.268, 4.71697, 8, 0, 'Heartsbane Triad - Group 0 - Focusing Iris');

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (131823, 131824, 131825);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
-- SAY AGGRO
(131823, 0, 0, 'I\'ll carve screams from your flesh!', 14, 0, 100, 0, 0, 97511, 144939, 0, 'Sister Malady to Player'),
(131824, 0, 0, 'You have no power here!', 14, 0, 100, 0, 0, 97519, 144931, 0, 'Sister Solena to Player'),
(131825, 0, 0, 'Such supple bones!', 14, 0, 100, 0, 0, 97503, 144951, 0, 'Sister Briar to Player'),
-- SAY_CLAIM_THE_IRIS
(131823, 1, 0, 'You\'ve had your turn!', 14, 0, 100, 0, 0, 97515, 144944, 0, 'Sister Malady'),
(131824, 1, 0, 'Give me the iris, you fool! Only I can focus its power!', 14, 0, 100, 0, 0, 97523, 144935, 0, 'Sister Solena'),
(131825, 1, 0, 'Release the iris to me, sister!', 14, 0, 100, 0, 0, 97509, 144962, 0, 'Sister Briar'),
-- SAY_SLAY
(131823, 3, 0, 'Such lovely agony!', 14, 0, 50, 0, 0, 97513, 144941, 0, 'Sister Malady'),
(131823, 3, 1, 'Your torment is far from over.', 14, 0, 50, 0, 0, 97514, 144942, 0, 'Sister Malady'),
(131824, 3, 0, 'Such a fragile soul!', 14, 0, 50, 0, 0, 97520, 144932, 0, 'Sister Solena'),
(131824, 3, 1, 'Your souls belong to me... forever.', 14, 0, 50, 0, 0, 97522, 144934, 0, 'Sister Solena'),
(131825, 3, 0, 'I love the sound of snapping limbs.', 14, 0, 50, 0, 0, 97504, 144955, 0, 'Sister Briar'),
(131825, 3, 1, 'Your skulls will make lovely ornaments.', 14, 0, 50, 0, 0, 97506, 144958, 0, 'Sister Briar'),
-- SAY_DEATH
(131823, 4, 0, 'My body cracks... but my curse... shall linger...', 14, 0, 100, 0, 0, 97512, 144940, 0, 'Sister Malady to Player'),
(131824, 4, 0, 'Death will not silence me...', 14, 0, 100, 0, 0, 97521, 144933, 0, 'Sister Solena to Player'),
(131825, 4, 0, 'My roots will sprout again...', 14, 0, 100, 0, 0, 97509, 144956, 0, 'Sister Briar to Player'),
-- SAY_DIRE_RITUAL_ALERT
(131823, 5, 0, '|TInterface\ICONS\SPELL_SHADOW_ANTISHADOW:20|t %s begins to cast |cFFFF0404|Hspell:260773|h[Dire Ritual]|h|r!', 41, 0, 100, 0, 0, 97526, 151946, 0, 'Sister Malady'),
(131824, 5, 0, '|TInterface\ICONS\SPELL_SHADOW_ANTISHADOW:20|t %s begins to cast |cFFFF0404|Hspell:260773|h[Dire Ritual]|h|r!', 41, 0, 100, 0, 0, 97526, 151946, 0, 'Sister Solena'),
(131825, 5, 0, '|TInterface\ICONS\SPELL_SHADOW_ANTISHADOW:20|t %s begins to cast |cFFFF0404|Hspell:260773|h[Dire Ritual]|h|r!', 41, 0, 100, 0, 0, 97526, 151946, 0, 'Sister Briar'),
-- SAY_DIRE_RITUAL
(131823, 6, 0, 'Rotted flesh and screams so dire, making music like a choir!', 14, 0, 100, 0, 0, 97517, 144946, 0, 'Sister Malady'),
(131824, 6, 0, 'Blackened soul, the pitch of night, lay to waste all those in sight!', 14, 0, 100, 0, 0, 97526, 144938, 0, 'Sister Solena'),
(131825, 6, 0, 'Powers high and spirits low, grant my thistles room to grow!', 14, 0, 100, 0, 0, 97515, 144944, 0, 'Sister Briar'),
-- Sister Malady
(131823, 2, 0, 'Your destruction is at hand!', 14, 0, 50, 0, 0, 97516, 144945, 0, 'Sister Malady'),
(131823, 2, 1, 'You bear the black mark!', 14, 0, 50, 0, 0, 97518, 144959, 0, 'Sister Malady'),
-- Sister Solena
(131824, 2, 0, 'Dance, puppet! Dance!', 14, 0, 50, 0, 0, 97524, 144936, 0, 'Sister Solena'),
(131824, 2, 1, 'You belong to me now!', 14, 0, 50, 0, 0, 97525, 144937, 0, 'Sister Solena'),
-- Sister Briar
(131825, 2, 0, 'My thorns will rip you to shreds!', 14, 0, 50, 0, 0, 97508, 144961, 0, 'Sister Briar to Player'),
(131825, 2, 1, 'The more you struggle, the more you\'ll bleed!', 14, 0, 50, 0, 0, 97507, 144960, 0, 'Sister Briar to Player');

-- Areatrigger
DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=0 AND `Id` IN (13196, 13179, 13177));
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(13196, 0, 17807, 0, 4, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 200, 200, 0, 0, 0, 0, 0, 0, 'at_heartsbane_triad_aura_of_thorns', 52485), -- Spell: 268122 (Aura of Thorns)
(13179, 0, 17791, 0, 4, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 200, 200, 0, 0, 0, 0, 0, 0, 'at_heartsbane_triad_aura_of_dread', 52485), -- Spell: 268088 (Aura of Dread)
(13177, 0, 17789, 0, 4, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 200, 200, 0, 0, 0, 0, 0, 0, 'at_heartsbane_triad_aura_of_apathy', 52485); -- Spell: 268077 (Aura of Apathy)

DELETE FROM `areatrigger_template` WHERE (`IsCustom`=0 AND `Id` IN (17807, 17791, 17789));
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES
(17807, 0, 0, 52485),
(17791, 0, 0, 52485),
(17789, 0, 0, 52485);

-- Spells
DELETE FROM `spell_script_names` WHERE `spell_id` IN (260741, 260852, 260854, 260907, 260923, 260703, 260773, 268077, 268088, 268085, 268122);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(260741, 'spell_heartsbane_triad_jagged_nettles'),
(260852, 'spell_heartsbane_triad_claim_the_iris'),
(260854, 'spell_heartsbane_triad_drop_the_iris'),
(260907, 'spell_heartsbane_triad_soul_manipulation_selector'),
(260923, 'spell_heartsbane_triad_soul_manipulation_periodic'),
(260703, 'spell_heartsbane_triad_unstable_runic_mark'),
(260773, 'spell_heartsbane_triad_dire_ritual'),
(268077, 'spell_heartsbane_triad_aura_of_apathy'),
(268088, 'spell_heartsbane_triad_aura_of_dread'),
(268085, 'spell_heartsbane_triad_aura_of_dread_movement_check'),
(268122, 'spell_heartsbane_triad_aura_of_thorns');
