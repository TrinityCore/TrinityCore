SET @CGUID := 5000327;
SET @OGUID := 5000055;

SET @TRIGGER_SPAWN_ID := 50;
SET @TRIGGER_ID := 50;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+5;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `StringID`, `VerifiedBuild`) VALUES
(@CGUID+0, 83670, 1265, 7025, 7041, '0', 3670, 0, 0, 0, 3976.389892578125, -2900.079833984375, 64.0878143310546875, 0, 120, 0, 0, 4000, 0, 0, NULL, NULL, NULL, NULL, 'west_orb', 51754), -- Blood Ritual Orb (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+1, 83670, 1265, 7025, 7041, '0', 3670, 0, 0, 0, 3982.326416015625, -2936.484375, 65.94042205810546875, 0, 120, 0, 0, 4000, 0, 0, NULL, NULL, NULL, NULL, 'middle_orb', 51754), -- Blood Ritual Orb (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+2, 83670, 1265, 7025, 7039, '0', 3670, 0, 0, 0, 3984.259521484375, -2948.079833984375, 95.44586181640625, 0, 120, 0, 0, 4000, 0, 0, NULL, NULL, NULL, NULL, '', 51754), -- Blood Ritual Orb (Area: The Bleeding Altar - Difficulty: 0) CreateObject1
(@CGUID+3, 81895, 1265, 7025, 7041, '0', 3670, 0, 0, 1, 3979.263916015625, -2918.310791015625, 60.87252426147460937, 1.824910879135131835, 120, 0, 0, 4000, 0, 0, NULL, NULL, NULL, NULL, '', 51754), -- Bleeding Hollow Bloodchosen (Area: Heartblood - Difficulty: 0) CreateObject1 (Auras: 164870 - Ritual of Blood)
(@CGUID+4, 81926, 1265, 7025, 7041, '0', 0, 0, 0, 0, 3979.822998046875, -2921.005126953125, 60.87251663208007812, 1.738257527351379394, 120, 0, 0, 4000, 0, 0, NULL, NULL, NULL, NULL, '', 51754), -- Kilrogg Deadeye (Area: Heartblood - Difficulty: 0) CreateObject1
(@CGUID+5, 78560, 1265, 7025, 7129, '0', 3414, 0, 0, 1, 4191.4990234375, -2786.998291015625, 26.83084297180175781, 0.145585432648658752, 120, 0, 0, 640000, 9573, 0, NULL, NULL, NULL, NULL, '', 51972); -- Archmage Khadgar (Area: Tar'thog Bridge - Difficulty: 0) CreateObject1

DELETE FROM `creature_summoned_data` WHERE `CreatureID`=80087;
INSERT INTO `creature_summoned_data` (`CreatureID`, `CreatureIDVisibleToSummoner`, `GroundMountDisplayID`, `FlyingMountDisplayID`) VALUES
(80087, 78556, NULL, NULL);

DELETE FROM `creature_equip_template` WHERE `CreatureID`=80087 AND `ID`=1;
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(80087, 1, 57012, 0, 0, 0, 0, 0, 0, 0, 0, 44730);

DELETE FROM `creature_template_addon` WHERE `entry` IN (81926 /*81926 (Kilrogg Deadeye)*/, 81895 /*81895 (Bleeding Hollow Bloodchosen) - Ritual of Blood*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(81895, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '164870'), -- 81895 (Bleeding Hollow Bloodchosen) - Ritual of Blood
(81926, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- 81926 (Kilrogg Deadeye)

UPDATE `creature_template` SET `unit_flags2`=18432 WHERE `entry`=78556; -- Ariok
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `ScriptName`='npc_altar_altercation_ariok' WHERE `entry`=80087; -- Liberated Frostwolf Prisoner
UPDATE `creature_template` SET `unit_flags3`=16777216, `ScriptName`='npc_altar_altercation_blood_ritual_orb' WHERE `entry`=83670; -- Blood Ritual Orb
UPDATE `creature_template` SET `unit_flags3`=16777216 WHERE `entry`=81926; -- Kilrogg Deadeye

DELETE FROM `creature_template_movement` WHERE `CreatureId`IN (83670, 81926);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(83670, 0, 0, 1, 1, 0, 0, NULL),
(81926, 0, 0, 1, 0, 0, 0, NULL);

-- Gameobject
DELETE FROM `gameobject` WHERE `guid` = @OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 231137, 1265, 7025, 7039, '0', 3480, 0, 4138.080078125, -2788.486083984375, 28.71277809143066406, 1.736601948738098144, 0, 0, 0.763232231140136718, 0.646124243736267089, 120, 255, 1, 51972); -- Tar'thog Bridge (Area: The Bleeding Altar - Difficulty: 0) CreateObject1

DELETE FROM `gameobject_addon` WHERE `guid` = @OGUID+0;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 0, 1, 0, 0); -- Tar'thog Bridge

UPDATE `gameobject_template_addon` SET `flags`=1048608 WHERE `entry`=231137; -- Tar'thog Bridge

-- Phasing
DELETE FROM `phase_name` WHERE `ID` = 3670;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(3670, 'Cosmetic - Blood Ritual');

DELETE FROM `phase_area` WHERE `PhaseId` IN (3480, 3670, 3414) AND `AreaId` IN (7025, 7039, 7041, 7129, 7040);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7025, 3480, 'Bridge still intact'),
(7039, 3670, 'Blood Ritual at The Bleeding Altar'),
(7041, 3670, 'Blood Ritual at The Bleeding Altar'),
(7129, 3414, 'See Khadgar at Tar\'thog Bridge'),
(7040, 3414, 'See Khadgar at Tar\'thog Bridge');

-- Gossip
UPDATE `creature_template_gossip` SET `VerifiedBuild`=51536 WHERE (`CreatureID`=78556 AND `MenuID`=16641);
UPDATE `gossip_menu` SET `VerifiedBuild`=51536 WHERE (`MenuID`=16641 AND `TextID`=24170);
UPDATE `gossip_menu_option` SET `GossipOptionID`=43152, `VerifiedBuild`=51536 WHERE (`MenuID`=16641 AND `OptionID`=0);

DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=78558 AND `MenuID`=16693) OR (`CreatureID`=78559 AND `MenuID`=16376);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(78558, 16693, 52485), -- Archmage Khadgar
(78559, 16376, 52485); -- Archmage Khadgar

-- Conditions
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 14) AND (`SourceGroup` IN (16376));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES 
(14, 16376, 0, 0, 0, 47, 0, 34423, 8, 0, 0, 'Player for which gossip text is shown has quest 34423 in progress');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=3265 AND `ConditionValue1` IN (35297, 34423, 273677);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 3265, 0, 0, 0, 47, 0, 35297, 2 | 64, 0, 0, 0, 0, '', 'Apply Phase 3265 if Quest 35297 is complete | rewarded'),
(26, 3265, 0, 0, 0, 47, 0, 34423, 2 | 64, 0, 1, 0, 0, '', 'Apply Phase 3265 if Quest 34423 is not complete | rewarded'),
(26, 3265, 0, 0, 0, 48, 0, 273677, 0, 1, 1, 0, 0, '', 'Apply Phase 3265 if Questobjective 273677 is not completed');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=16641;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 16641, 0, 0, 0, 47, 0, 34423, 8, 0, 0, 0, 0, '', 'Gossip Option 16641 - Show Option 0 if Quest 34423 is in progress'),
(15, 16641, 0, 0, 0, 48, 0, 273075, 0, 1, 1, 0, 0, '', 'Gossip Option 16641 - Show Option 0 if Questobjective 273075 is not completed');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=3655;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 3655, 0, 0, 0, 47, 0, 35297, 2 | 64, 0, 0, 0, 0, '', 'Apply Phase 3655 if Quest 35297 is complete | rewarded'),
(26, 3655, 0, 0, 0, 47, 0, 34423, 2 | 64, 0, 1, 0, 0, '', 'Apply Phase 3655 if Quest 34423 is not complete | rewarded'),
(26, 3655, 0, 0, 0, 48, 0, 273075, 0, 1, 1, 0, 0, '', 'Apply Phase 3655 if Questobjective 273075 is not completed');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=3670;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 3670, 0, 0, 0, 47, 0, 34423, 2 | 64, 0, 1, 0, 0, '', 'Apply Phase 3670 if Quest 34423 is not complete | rewarded'),
(26, 3670, 0, 0, 0, 48, 0, 273678, 0, 3, 1, 0, 0, '', 'Apply Phase 3670 if Questobjective 273678 is not completed');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=3414;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 3414, 0, 0, 0, 47, 0, 34423, 2 | 8 | 64, 0, 0, 0, 0, '', 'Apply Phase 3414 if Quest 34423 is complete | in progress | rewarded'),
(26, 3414, 0, 0, 0, 48, 0, 273678, 0, 3, 0, 0, 0, '', 'Apply Phase 3414 if Questobjective 273678 is completed');

-- These phases were handled before
-- Phases 3394 and 3395 are so weird (they are applied/removed more than once but different npcs)
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=3394 AND `ConditionValue1`=161625;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 3394, 0, 0, 0, 1, 0, 161625, 0, 0, 1, 0, 0, '', 'Apply Phase 3394 if player has no aura 161625');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=3395 AND `ConditionValue1`=161625;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 3395, 0, 0, 0, 1, 0, 161625, 0, 0, 1, 0, 0, '', 'Apply Phase 3395 if player has no aura 161625');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=3910 AND `ConditionValue1` IN (34423, 273677);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 3910, 0, 0, 0, 47, 0, 34423, 2 | 64, 0, 1, 0, 0, '', 'Apply Phase 3910 if Quest 34423 is not complete | rewarded'),
(26, 3910, 0, 0, 0, 48, 0, 273677, 0, 1, 1, 0, 0, '', 'Apply Phase 3910 if Questobjective 273677 is not completed');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=3911 AND `ConditionValue1` IN (34423, 273677);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 3911, 0, 0, 0, 47, 0, 34423, 2 | 64, 0, 1, 0, 0, '', 'Apply Phase 3911 if Quest 34423 is not complete | rewarded'),
(26, 3911, 0, 0, 0, 48, 0, 273677, 0, 1, 1, 0, 0, '', 'Apply Phase 3911 if Questobjective 273677 is not completed');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=4010 AND `ConditionValue1` IN (34423, 273677);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 4010, 0, 0, 0, 47, 0, 34423, 2 | 64, 0, 1, 0, 0, '', 'Apply Phase 4010 if Quest 34423 is not complete | rewarded'),
(26, 4010, 0, 0, 0, 48, 0, 273677, 0, 1, 1, 0, 0, '', 'Apply Phase 4010 if Questobjective 273677 is not completed');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=4011 AND `ConditionValue1` IN (34423, 273677);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 4011, 0, 0, 0, 47, 0, 34423, 2 | 64, 0, 1, 0, 0, '', 'Apply Phase 4011 if Quest 34423 is not complete | rewarded'),
(26, 4011, 0, 0, 0, 48, 0, 273677, 0, 1, 1, 0, 0, '', 'Apply Phase 4011 if Questobjective 273677 is not completed');

-- Quest objectives
DELETE FROM `quest_objectives_completion_effect` WHERE `ObjectiveID`IN (273075, 273678);
INSERT INTO `quest_objectives_completion_effect` (`ObjectiveID`, `GameEventID`, `SpellID`, `ConversationID`, `UpdatePhaseShift`, `UpdateZoneAuras`) VALUES
(273075, NULL, NULL, NULL, 1, 1),
(273678, NULL, 161771, NULL, 1, 1);

-- Quest
DELETE FROM `quest_template_addon` WHERE `ID`=34423;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(34423, 0, 0, 0, 34422, 34425, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 'quest_altar_altercation');

-- Spellclick
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=83670;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(83670, 167955, 3, 0);

-- SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=78556; -- Ariok
DELETE FROM `smart_scripts` WHERE `entryorguid`=78556 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(78556, 0, 0, 1, 62, 0, 100, 0, 16641, 0, 0, 0, 0, '', 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 'Ariok - On Gossip Option 0 Selected - Close Gossip'),
(78556, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 85, 159278, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 'Ariok - On Gossip Option 0 Selected - Invoker Cast \'Speak with Ariok Credit\'');

-- Text
DELETE FROM `creature_text` WHERE `CreatureID` IN (80087, 81926);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(80087, 0, 0, 'You and I against an entire clan? Sounds like my kind of fight.', 12, 0, 100, 396, 0, 46156, 83856, 0, 'Ariok to Player'),
(80087, 1, 0, 'The Bleeding Hollow orcs use savage blood magic to transform their warriors into hulking berserkers.', 12, 0, 100, 396, 0, 46157, 83884, 0, 'Ariok to Player'),
(80087, 2, 0, 'With any luck, we will escape before they can complete their transformation ritual.', 12, 0, 100, 396, 0, 46158, 83888, 0, 'Ariok to Player'),
(80087, 3, 0, 'Here we stand, cowards! Come... FIGHT US!', 14, 0, 100, 375, 0, 46159, 83857, 0, 'Ariok to Player'),
(80087, 4, 0, 'They seem focused on their ritual. Maybe destroying those blood orbs will get their attention.', 12, 0, 100, 0, 0, 46160, 85454, 0, 'Ariok to Player'),
(80087, 5, 0, 'It looks like Khadgar and the rest are on the move. Our work is nearly done, champion!', 12, 0, 100, 0, 0, 46162, 83861, 0, 'Ariok to Player'),
(80087, 6, 0, 'Look!', 12, 0, 100, 0, 0, 46163, 83873, 0, 'Ariok to Player'),
(81926, 0, 0, 'I can see you...', 15, 0, 100, 0, 0, 45923, 83858, 0, 'Kilrogg Deadeye to Player'),
(81926, 1, 0, 'I\'m coming for you, intruders...', 15, 0, 100, 0, 0, 45924, 83860, 0, 'Kilrogg Deadeye to Player');

-- Spell
DELETE FROM `spell_script_names` WHERE `spell_id` IN (161618, 167955, 164979);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(161618,'spell_altar_altercation_summon_ariok'),
(167955,'spell_altar_altercation_destroying'),
(164979,'spell_trigger_ariok_altar_altercation');

DELETE FROM `spell_target_position` WHERE `ID`=161618 AND `EffectIndex`=0;
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(161618, 0, 1265, 3842.37, -2787.32, 94.3774, 51536);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=164979;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 164979, 0, 0, 51, 0, 5, 80087, 0, 0, 0, 0, '', 'Spell \'Trigger Ariok \' can only hit Ariok');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=2 AND `SourceEntry`=167955;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 2, 167955, 0, 0, 51, 0, 5, 83670, 0, 0, 0, 0, '', 'Spell \'Destroying \' can only hit Blood Ritual Orb');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=2 AND `SourceEntry`=170044;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 2, 170044, 0, 0, 51, 0, 5, 81895, 0, 0, 0, 0, '', 'Spell \'Blood Ritual Orb Beam \' can only hit Bleeding Hollow Bloodchosen');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 17) AND (`SourceEntry` IN (161625));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES 
(17, 0, 161625, 0, 0, 48, 0, 273075, 0, 1, 0, 'Caster of the spell has quest objective 273075 == 1 (but hasn\'t rewarded quest yet)');

DELETE FROM `spell_area` WHERE `spell` IN(164877, 161625);
INSERT INTO `spell_area` (`area`, `spell`, `quest_start`, `quest_start_status`, `quest_end`, `quest_end_status`, `flags`, `aura_spell`, `racemask`, `gender`) VALUES
(7039, 161625, 34423, 8, 0, 0, 3, 0, 0, 2), -- Altar Altercation: Summon Aura @ The Bleeding Altar
(7041, 161625, 34423, 8, 0, 0, 3, 0, 0, 2), -- Altar Altercation: Summon Aura @ Heartblood
(7039, 164877, 0, 0, 0, 0, 3, 0, 0, 2), -- Eye of Kilrogg @ The Bleeding Altar
(7041, 164877, 0, 0, 0, 0, 3, 0, 0, 2); -- Eye of Kilrogg @ Heartblood

-- Scene
UPDATE `scene_template` SET `ScriptName` = 'scene_bleeding_hollow_kilrogg_reveal' WHERE `SceneId`=694;

-- Areatrigger
DELETE FROM `areatrigger` WHERE `SpawnId` BETWEEN @TRIGGER_SPAWN_ID+0 AND @TRIGGER_SPAWN_ID+3;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerId`, `IsServerSide`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `SpellForVisuals`, `ScriptName`, `Comment`, `VerifiedBuild`) VALUES
(@TRIGGER_SPAWN_ID+0, @TRIGGER_ID+0, 1, 1265, '0', 3982.48, -2936.61, 62.6424, 1.72932, 0, 0, 0, 0, 70, 70, 0, 0, 0, 0, 0, 0, NULL, 'at_altar_altercation_reach_altar', NULL, 0),
(@TRIGGER_SPAWN_ID+1, @TRIGGER_ID+1, 1, 1265, '0', 4187.81, -2779.99, 26.9349, 3.31491, 0, 0, 0, 1, 20, 20, 10, 20, 20, 10, 0, 0, NULL, '', NULL, 0),
(@TRIGGER_SPAWN_ID+2, @TRIGGER_ID+2, 1, 1265, '0', 4046.79, -2940.89, 62.1408, 1.66231, 0, 0, 0, 1, 30, 20, 10, 30, 20, 10, 0, 0, NULL, 'at_altar_altercation_kilrogg_talk', NULL, 0),
(@TRIGGER_SPAWN_ID+3, @TRIGGER_ID+2, 1, 1265, '0', 3921.71, -2962.14, 62.3053, 1.66231, 0, 0, 0, 1, 30, 20, 10, 30, 20, 10, 0, 0, NULL, 'at_altar_altercation_kilrogg_talk', NULL, 0);

DELETE FROM `areatrigger_template` WHERE `Id` BETWEEN @TRIGGER_ID+0 AND @TRIGGER_ID+2;
INSERT INTO `areatrigger_template` (`Id`, `IsServerSide`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `VerifiedBuild`) VALUES
(@TRIGGER_ID+0, 1, 0, 0, 70, 70, 0, 0, 0, 0, 0, 0, 0),
(@TRIGGER_ID+1, 1, 1, 0, 20, 20, 10, 20, 20, 10, 0, 0, 0),
(@TRIGGER_ID+2, 1, 1, 0, 30, 20, 10, 30, 20, 10, 0, 0, 0);

DELETE FROM `areatrigger_template_actions` WHERE `AreaTriggerId` BETWEEN @TRIGGER_ID+0 AND @TRIGGER_ID+2;
INSERT INTO `areatrigger_template_actions` (`AreaTriggerId`, `IsServerSide`, `ActionType`, `ActionParam`, `TargetType`) VALUES
(@TRIGGER_ID+1, 1, 0, 169070, 5);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=28 AND `SourceGroup`=@TRIGGER_ID+1 AND `SourceEntry`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(28, @TRIGGER_ID+1, 1, 0, 0, 47, 0, 34423, 8, 0, 0, 0, 0, '', 'Only trigger areatrigger when quest 34423 is taken'),
(28, @TRIGGER_ID+1, 1, 0, 0, 48, 0, 274409, 0, 0, 0, 0, 0, '', 'Only trigger areatrigger when has quest objective 274409 active');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=28 AND `SourceGroup`=@TRIGGER_ID+2 AND `SourceEntry`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(28, @TRIGGER_ID+2, 1, 0, 0, 47, 0, 34423, 8, 0, 0, 0, 0, '', 'Only trigger areatrigger when quest 34423 is taken'),
(28, @TRIGGER_ID+2, 1, 0, 0, 48, 0, 273678, 0, 3, 1, 0, 0, '', 'Only trigger areatrigger when progress of quest objective 273678 not == 3');

-- Serverside spells
DELETE FROM `serverside_spell` WHERE `Id`IN (164979, 167547) AND `DifficultyID`=0;
INSERT INTO `serverside_spell` (`Id`, `DifficultyID`, `CategoryId`, `Dispel`, `Mechanic`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `AttributesEx11`, `AttributesEx12`, `AttributesEx13`, `AttributesEx14`, `Stances`, `StancesNot`, `Targets`, `TargetCreatureType`, `RequiresSpellFocus`, `FacingCasterFlags`, `CasterAuraState`, `TargetAuraState`, `ExcludeCasterAuraState`, `ExcludeTargetAuraState`, `CasterAuraSpell`, `TargetAuraSpell`, `ExcludeCasterAuraSpell`, `ExcludeTargetAuraSpell`, `CasterAuraType`, `TargetAuraType`, `ExcludeCasterAuraType`, `ExcludeTargetAuraType`, `CastingTimeIndex`, `RecoveryTime`, `CategoryRecoveryTime`, `StartRecoveryCategory`, `StartRecoveryTime`, `InterruptFlags`, `AuraInterruptFlags1`, `AuraInterruptFlags2`, `ChannelInterruptFlags1`, `ChannelInterruptFlags2`, `ProcFlags`, `ProcFlags2`, `ProcChance`, `ProcCharges`, `ProcCooldown`, `ProcBasePPM`, `MaxLevel`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `Speed`, `LaunchDelay`, `StackAmount`, `EquippedItemClass`, `EquippedItemSubClassMask`, `EquippedItemInventoryTypeMask`, `ContentTuningId`, `SpellName`, `ConeAngle`, `ConeWidth`, `MaxTargetLevel`, `MaxAffectedTargets`, `SpellFamilyName`, `SpellFamilyFlags1`, `SpellFamilyFlags2`, `SpellFamilyFlags3`, `SpellFamilyFlags4`, `DmgClass`, `PreventionType`, `AreaGroupId`, `SchoolMask`, `ChargeCategoryId`) VALUES
(164979, 0, 0, 0, 0, (0x29800180), (0x00000420), (0x10484005), (0x10130200), (0x00800080), (0x00060008), (0x00001200), 0, 0, (0x00010000), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, 0, 'Trigger Ariok', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(167547, 0, 0, 0, 0, (0x29800180), (0x00000420), (0x10484005), (0x10130200), (0x00800080), (0x00060008), (0x00001200), 0, 0, (0x00010000), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, 0, 'Altar Altercation: Cancel Auras', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);

DELETE FROM `serverside_spell_effect` WHERE `SpellID` IN (164979, 167547);
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(164979, 0, 0, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 33, 0, 0, 0, 0, 0, 22, 7),
(167547, 0, 0, 164, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 161625, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(167547, 1, 0, 164, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 161637, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(167547, 2, 0, 164, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 161771, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(167547, 3, 0, 64, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 82238, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);
