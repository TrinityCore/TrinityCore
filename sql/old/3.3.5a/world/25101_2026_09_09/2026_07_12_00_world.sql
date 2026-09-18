--
SET @SPAWN_GROUP_ID := 365; -- 3

-- Greyheart Spellbinder
UPDATE `creature` SET `position_x` = 385.15833, `position_y` = -441.5967, `position_z` = 29.61213, `orientation` = 2.8100555, `spawntimesecs` = 604800, `VerifiedBuild` = 15595 WHERE `guid` = 93770 AND `id` = 21806;
UPDATE `creature` SET `position_x` = 373.21924, `position_y` = -429.14777, `position_z` = 29.606419, `orientation` = 5.049488, `spawntimesecs` = 604800, `VerifiedBuild` = 15595 WHERE `guid` = 93771 AND `id` = 21806;
UPDATE `creature` SET `position_x` = 369.2343, `position_y` = -446.47256, `position_z` = 29.602036, `orientation` = 0.82057405, `spawntimesecs` = 604800, `VerifiedBuild` = 15595 WHERE `guid` = 93772 AND `id` = 21806;

DELETE FROM `creature_formations` WHERE `leaderGUID` = 93770;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(93770,93770,0,0,3,0,0),
(93770,93771,0,0,3,0,0),
(93770,93772,0,0,3,0,0);

UPDATE `spawn_group` SET `groupId` = @SPAWN_GROUP_ID+0 WHERE `spawnId` = 93770 AND `spawnType` = 0;
UPDATE `spawn_group` SET `groupId` = @SPAWN_GROUP_ID+1 WHERE `spawnId` = 93771 AND `spawnType` = 0;
UPDATE `spawn_group` SET `groupId` = @SPAWN_GROUP_ID+2 WHERE `spawnId` = 93772 AND `spawnType` = 0;

DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN @SPAWN_GROUP_ID+0 AND @SPAWN_GROUP_ID+2;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWN_GROUP_ID+0,"Serpentshrine Cavern - Greyheart Spellbinder 000",4),
(@SPAWN_GROUP_ID+1,"Serpentshrine Cavern - Greyheart Spellbinder 001",4),
(@SPAWN_GROUP_ID+2,"Serpentshrine Cavern - Greyheart Spellbinder 002",4);

UPDATE `conditions` SET `ConditionValue2` = 21215, `Comment` = "Group 0: Spell 'Green Beam' (Effect 0) targets creature 'Leotheras the Blind'" WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 37626;

UPDATE `creature_model_info` SET `BoundingRadius` = 1.5 WHERE `DisplayID` = 20638;

UPDATE `creature_template` SET `speed_walk` = 1.6, `speed_run` = 1.71429, `unit_flags` = 32832 WHERE `entry` = 21806;

-- Shadow of Leotheras
UPDATE `creature_model_info` SET `BoundingRadius` = 4.5, `CombatReach` = 4.5 WHERE `DisplayID` = 20568;

UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 2.14286, `BaseAttackTime` = 1800, `unit_flags` = 33587264, `ScriptName` = 'npc_shadow_of_leotheras' WHERE `entry` = 21875;

DELETE FROM `creature_text` WHERE `CreatureID` = 21875;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(21875,0,0,"At last I am liberated. It has been too long since I have tasted true freedom!",14,0,100,0,0,11309,19502,0,"Shadow of Leotheras SAY_DEMON_FREE");

-- Leotheras the Blind
UPDATE `creature` SET `position_x` = 376.54285, `position_y` = -438.6309, `position_z` = 29.608301, `orientation` = 2.6703537, `VerifiedBuild` = 15595 WHERE `id` = 21215;

UPDATE `creature_model_info` SET `BoundingRadius` = 0.86174995, `CombatReach` = 3.375 WHERE `DisplayID` = 20514;

UPDATE `creature_template` SET `speed_run` = 2.14286, `BaseAttackTime` = 1800, `unit_flags` = 32832 WHERE `entry` = 21215;

DELETE FROM `creature_text` WHERE `CreatureID` = 21215;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(21215,0,0,"Be gone, trifling elf.  I am in control now!",14,0,100,0,0,11304,19595,0,"Leotheras SAY_DEMON_MORPH"),
(21215,1,0,"We all have our demons....",14,0,100,0,0,11305,19597,0,"Leotheras SAY_DEMON_INNER_DEMONS"),
(21215,2,0,"I have no equal!",14,0,100,0,0,11306,19993,0,"Leotheras SAY_DEMON_SLAY_1"),
(21215,2,1,"Perish, mortal!",14,0,100,0,0,11307,19994,0,"Leotheras SAY_DEMON_SLAY_2"),
(21215,2,2,"Yes... yes!",14,0,100,0,0,11308,19995,0,"Leotheras SAY_DEMON_SLAY_3"),
(21215,3,0,"Finally, my banishment ends!",14,0,100,0,0,11312,19596,0,"Leotheras SAY_NIGHT_ELF_AGGRO"),
(21215,4,0,"No... no! What have you done? I am the master! Do you hear me? I am... aaggh! Can't... contain him.",14,0,100,0,0,11313,19501,0,"Leotheras SAY_NIGHT_ELF_FINAL_FORM"),
(21215,5,0,"Kill, kill!",14,0,100,0,0,11314,19996,0,"Leotheras SAY_NIGHT_ELF_SLAY_1"),
(21215,5,1,"That's right, yes!",14,0,100,0,0,11315,19997,0,"Leotheras SAY_NIGHT_ELF_SLAY_2"),
(21215,5,2,"Who's the master now?",14,0,100,0,0,11316,19998,0,"Leotheras SAY_NIGHT_ELF_SLAY_3"),
(21215,6,0,"You cannot kill me, fools! I'll be back, I'll....",14,0,100,0,0,11317,19999,0,"Leotheras SAY_NIGHT_ELF_DEATH");

-- Leotheras the Blind (Transform)
UPDATE `creature_model_info` SET `BoundingRadius` = 4.5, `CombatReach` = 4.5 WHERE `DisplayID` = 20125;

-- Phantom Leotheras
UPDATE `creature_model_info` SET `BoundingRadius` = 4.5, `CombatReach` = 4.5 WHERE `DisplayID` = 20479;

UPDATE `creature_template` SET `speed_run` = 2.14286, `unit_flags` = 33587968 WHERE `entry` = 21812;

-- Spell scripts
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_gen_chaos_blast';
DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_leotheras_the_blind_whirlwind_init',
'spell_leotheras_the_blind_whirlwind_effect',
'spell_leotheras_the_blind_chaos_blast',
'spell_leotheras_the_blind_insidious_whisper',
'spell_leotheras_the_blind_summon_inner_demon',
'spell_leotheras_the_blind_clear_consuming_madness',
'spell_leotheras_the_blind_demon_link',
'spell_leotheras_the_blind_metamorphosis');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(37640, 'spell_leotheras_the_blind_whirlwind_init'),
(37641, 'spell_leotheras_the_blind_whirlwind_effect'),
(37674, 'spell_leotheras_the_blind_chaos_blast'),
(37676, 'spell_leotheras_the_blind_insidious_whisper'),
(37725, 'spell_leotheras_the_blind_summon_inner_demon'),
(37726, 'spell_leotheras_the_blind_summon_inner_demon'),
(37731, 'spell_leotheras_the_blind_summon_inner_demon'),
(37732, 'spell_leotheras_the_blind_summon_inner_demon'),
(37733, 'spell_leotheras_the_blind_summon_inner_demon'),
(37750, 'spell_leotheras_the_blind_clear_consuming_madness'),
(37716, 'spell_leotheras_the_blind_demon_link'),
(37673, 'spell_leotheras_the_blind_metamorphosis');

-- We are changing old effect Summon Demon to Summon
UPDATE `spell_dbc` SET `Effect1` = 28, `EffectMiscValueB1` = 64 WHERE `Id` IN (20493,24810,37026,37781);
