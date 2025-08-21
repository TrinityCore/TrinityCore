SET @CGUID := 7001526;
SET @OGUID := 7000371;

-- Creature
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 130419, 1643, 8721, 9032, '0', 9115, 0, 0, 1, -85.265625, 2082.897705078125, 47.02935409545898437, 2.436548471450805664, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59888); -- Cyril White (Area: Fallhaven - Difficulty: 0) CreateObject1 (Auras: 246908 - Cursed)

DELETE FROM `creature_addon` WHERE `guid` = @CGUID+0;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 0, 13492, 0, 0, 0, '246908'); -- Cyril White - 246908 - Cursed

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+1;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 272196, 1643, 8721, 9032, '0', 9097, 0, -76.7743072509765625, 2100.5244140625, 46.76264190673828125, 4.663055896759033203, 0, 0, -0.72433185577392578, 0.689451456069946289, 120, 255, 1, 59888), -- Cursed Effigy (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+1, 278585, 1643, 8721, 9032, '0', 9870, 0, -76.7743072509765625, 2100.5244140625, 46.76264190673828125, 4.663055896759033203, 0, 0, -0.72433185577392578, 0.689451456069946289, 120, 255, 1, 59888); -- Cursed Effigy (Area: Fallhaven - Difficulty: 0) CreateObject1

-- Template Addon
DELETE FROM `gameobject_template_addon` WHERE `entry` = 278585; -- Cursed Effigy
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(278585, 0, 0x4, 0, 0); -- Cursed Effigy

UPDATE `gameobject_template_addon` SET `flags`=0x40020 WHERE `entry`=272196; -- Cursed Effigy

-- Template
UPDATE `creature_template` SET `unit_flags2`=0x800 WHERE `entry`=130419; -- Cyril White

UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=59888 WHERE `entry` IN (278585, 272196); -- Cursed Effigy

-- Difficulty
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=59888 WHERE (`Entry`=130419 AND `DifficultyID`=0); -- 130419 (Cyril White) - CanSwim - CannotTurn

-- Spawntracking
UPDATE `spawn_tracking_template` SET `PhaseId`=9115, `VerifiedBuild`=59888 WHERE `SpawnTrackingId`=1351778; -- Map: 1643 (Kul Tiras) - Phase: 9115

-- Phasing
DELETE FROM `phase_name` WHERE `ID` IN (9115,9097,9870);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(9115, 'Cosmetic - See Cyril White cursed'),
(9097, 'Cosmetic - See Cursed Effigy before tried to get destroyed'),
(9870, 'Cosmetic - See Cursed Effigy after tried to get destroyed');

DELETE FROM `phase_area` WHERE `PhaseId` IN (9115,9097,9870);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(8721, 9115, 'See Cyril White cursed'),
(8721, 9097, 'See Cursed Effigy before tried to get destroyed'),
(8721, 9870, 'See Cursed Effigy after tried to get destroyed');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (9097,9870) AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 9097, 0, 0, 0, 47, 0, 48622, 2|64, 0, 1, 'Apply Phase 9097 if Quest 48622 is not complete | rewarded'),
(26, 9870, 0, 0, 0, 47, 0, 48622, 2|64, 0, 0, 'Apply Phase 9870 if Quest 48622 is complete | rewarded');

-- Playercondition
DELETE FROM conditions WHERE SourceTypeOrReferenceId=34 AND SourceEntry = 64255;
INSERT INTO conditions (SourceTypeOrReferenceId, SourceGroup, SourceEntry, SourceId, ElseGroup, ConditionTypeOrReference, ConditionTarget, ConditionValue1, ConditionValue2, ConditionValue3, ConditionStringValue1, NegativeCondition, ErrorType, ErrorTextId, ScriptName, Comment) VALUES
(34, 0, 64255, 0, 0, 47, 0, 48622, 8, 0, '', 0, 0, 0, '', 'Satisfy player condition if quest 48622 is taken'),
(34, 0, 64255, 0, 0, 48, 0, 292653, 0, 1, '', 0, 0, 0, '', 'Satisfy player condition if questobjecitve 292653 is rewarded'),
(34, 0, 64255, 0, 0, 48, 0, 295018, 0, 1, '', 0, 0, 0, '', 'Satisfy player condition if questobjective 295018 is rewarded');

-- EventScript
DELETE FROM `event_script_names` WHERE `Id` = 61418;
INSERT INTO `event_script_names` (`Id`, `ScriptName`) VALUES
(61418, 'SmartEventTrigger');

SET @ENTRY := 61418;
DELETE FROM `smart_scripts` WHERE `source_type` = 3 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 3, 0, 0, 87, 0, 100, 0, 0, 0, 0, 0, 0, 85, 258077, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On SendEvent - Self: Cast spell 258077 on self', '');

-- Gossip
UPDATE `gossip_menu_option` SET `GossipOptionID`=48151, `VerifiedBuild`=59888 WHERE (`MenuID`=21990 AND `OptionID`=2);
UPDATE `gossip_menu_option` SET `GossipOptionID`=48319, `ActionMenuID`=21872, `VerifiedBuild`=59888 WHERE (`MenuID`=21873 AND `OptionID`=0);
UPDATE `gossip_menu_option` SET `GossipOptionID`=48149, `VerifiedBuild`=59888 WHERE (`MenuID`=21990 AND `OptionID`=0);
UPDATE `gossip_menu_option` SET `GossipOptionID`=47502, `VerifiedBuild`=59888 WHERE (`MenuID`=21307 AND `OptionID`=0);

-- SpellClick
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 130483;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(130483, 258292, 1, 0);

-- Quest
DELETE FROM `quest_details` WHERE `ID`=48622;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(48622, 0, 0, 0, 0, 0, 0, 0, 0, 59888); -- The Vanishing Lord

DELETE FROM `creature_queststarter` WHERE (`id`=121235 AND `quest`=48622);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(121235, 48622, 59888); -- The Vanishing Lord offered by Taelia

DELETE FROM `gameobject_questender` WHERE (`id`=278585 AND `quest`=48622);
INSERT INTO `gameobject_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(278585, 48622, 59888); -- The Vanishing Lord ended by Cursed Effigy

DELETE FROM `quest_template_addon` WHERE `ID` = 48622;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(48622, 0, 0, 0, 47961, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- The Vanishing Lord

DELETE FROM `quest_objectives_completion_effect` WHERE `ObjectiveID` = 336295;
INSERT INTO `quest_objectives_completion_effect` (`ObjectiveID`, `GameEventID`, `SpellID`, `ConversationID`, `UpdatePhaseShift`, `UpdateZoneAuras`) VALUES
(336295, NULL, NULL, NULL, 1, 0);

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 15) AND (`SourceGroup` IN (21873));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(15, 21873, 0, 0, 0, 47, 0, 48622, 8, 0, '', 0, 'Player for which gossip text is shown has The Vanishing Lord (48622) in state incomplete'),
(15, 21873, 0, 0, 0, 48, 0, 295018, 0, 1, '', 1, 'Player for which gossip text is shown hasn\'t quest objective 295018 < 1 or has rewarded the quest');

-- UiMap
DELETE FROM `ui_map_quest_line` WHERE (`UIMapId`=895 AND `QuestLineId` IN (624,621,613,603,5380,5374,615)) OR (`UIMapId`=1161 AND `QuestLineId` IN (624,621,5380,5374,615));
INSERT INTO `ui_map_quest_line` (`UIMapId`, `QuestLineId`, `VerifiedBuild`) VALUES
(895, 624, 59888),
(895, 621, 59888),
(895, 613, 59888),
(895, 603, 59888),
(895, 5380, 59888),
(895, 5374, 59888),
(895, 615, 59888),
(1161, 624, 59888),
(1161, 621, 59888),
(1161, 5380, 59888),
(1161, 5374, 59888),
(1161, 615, 59888);

-- Cyril White smart ai
SET @ENTRY := 130419;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 1, 62, 0, 100, 0, 21873, 0, 0, 0, 0, 85, 258198, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 21873 selected - Gossip player: Cast spell 258198 on self', ''),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 0, 85, 271850, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 21873 selected - Gossip player: Cast spell 271850 on self', ''),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 21873 selected - Gossip player: Close gossip', '');

-- Model
UPDATE `creature_model_info` SET `VerifiedBuild`=59888 WHERE `DisplayID` IN (80850, 80860, 80955, 2543, 86197, 81079, 81082, 78018, 77946, 81344, 36743, 77947, 77991, 77044, 80932, 77997, 79948, 81470, 81346, 78053, 78050, 78046, 78849, 78047, 21072, 81264, 81256, 77994, 77993, 40906, 44108, 36357, 4959, 36299, 36298, 70448, 42239, 78049, 51297, 70442, 51294, 82254, 42241, 70446, 81086, 70440, 134, 16357, 16356, 16358, 21342, 79951, 32546, 80619, 81397, 77902, 79477, 74697, 63972, 75372, 36595, 76516, 81953, 81951, 75699, 75374, 77488, 32187, 75377, 75701, 78151, 77464, 90154, 30244, 90152, 39109, 90153, 30263, 87053, 75368, 78241, 87370, 76548, 81084, 79970, 87379, 79969, 80990, 79887, 79971, 22469, 78846, 87393, 82550, 81152, 80767, 42408, 52580, 78633, 85441, 82955, 47166, 1939, 82957, 85664, 77591, 85437, 93452, 80744, 80745, 85550, 82813, 84085, 81748, 85548, 80858, 86025, 85547, 85493, 85440, 85549, 81743, 52582, 88298, 88199, 88152, 79381, 93454, 85044, 84263, 80264, 79065, 88321, 88192, 92705, 93451, 85045, 88495, 78967, 82795, 88263, 88283, 88193, 4626, 79064, 81207, 80182, 84551, 79067, 87891, 78806, 87030, 87689, 87925, 87924, 80846, 78993, 64814, 87687, 87928, 87910, 87909, 88079, 87686, 88073, 88044, 21936, 88074, 78962, 86849, 87688, 88043, 87926, 38626, 88080, 81372, 88081, 42744, 80177, 88072, 78963, 88075, 87685, 87684, 88070, 75330, 88190, 76547, 88191, 85246, 87017, 75340, 6302, 75339, 77039, 75329, 77489, 82538, 78479, 84084, 84529, 83862, 79313, 81366, 83892, 83893, 78478, 82543, 87050, 82539, 88621, 80178, 84284, 80180, 81168, 77054, 87583, 87584, 87375, 77698, 38804, 75365, 77955, 85719, 85720, 87814, 87824, 87820, 87833, 87823, 87818, 87831, 87825, 87822, 87817, 87826, 88065, 87821, 87690, 39631, 88318, 87819, 33519, 87790, 88317, 80753, 81363, 78632, 86640, 87791, 87792, 87793, 78472, 88493, 87780, 78928, 87630, 87769, 25073, 84139, 77940, 77532, 981, 76422, 78630, 87634, 84069, 77466, 87376, 87786, 78471, 85967, 93865, 77691, 81807, 82234, 84262, 82814, 87599, 80751, 83985, 83982, 1418, 165, 81312, 78223, 84166, 44575, 88548, 77936, 77523, 80754, 89604, 90788, 15275, 88690, 81313, 87614, 81345, 82026, 46710, 84174, 87832, 78480, 81302, 41325, 87611, 87422, 87549, 83812, 87602, 87834, 55344, 87782, 87829, 42178, 85228, 76890, 26353, 87830, 87827, 84091, 77055, 83532, 87698, 86715, 84092, 85797, 88528, 87805, 81802, 87796, 87806, 86443, 76552, 88262, 87807, 32790, 85758, 53108, 82024, 88050, 87788, 88547, 41667, 72253, 78193, 86168, 82148, 83531, 62093, 83533, 87810, 76549, 87804, 87601, 87581, 82950, 60256, 58202, 88594, 87803, 87811, 87800, 77041, 79380, 11686, 87801, 87815, 86471, 55345, 1141, 88611, 27681, 13069, 82995, 81321, 86763, 82693, 83093, 78631, 87565, 90165, 87761, 88610, 82025, 85767, 77851, 32778, 91067, 76222, 28047, 75719, 33719, 76515, 83521, 83664, 75855, 88837, 90161, 88502, 65, 81166, 88615, 88051, 86764, 87808, 77687, 88881, 81291, 82047, 78481, 88609, 83057, 79015, 87638, 41408, 88271, 88605, 32646, 79014, 32681, 34450, 89352, 88607, 84173, 87613, 84415, 88614, 86638, 87495, 76907, 86472, 61206, 85771, 32789, 80857, 78483, 80893, 90661, 86639, 5565, 61205, 88049, 88604, 88827, 87797, 86950, 89353, 88608, 24052, 88825, 78869, 27823, 88612, 38801, 86026, 89355, 84412, 88613, 87600, 88606, 89354);
UPDATE `creature_model_info` SET `BoundingRadius`=2.263009548187255859, `VerifiedBuild`=59888 WHERE `DisplayID`=79924;
UPDATE `creature_model_info` SET `BoundingRadius`=0.665383040904998779, `CombatReach`=0.800000011920928955, `VerifiedBuild`=59888 WHERE `DisplayID` IN (70722, 79614);
UPDATE `creature_model_info` SET `BoundingRadius`=1.299999952316284179, `CombatReach`=1.299999952316284179, `VerifiedBuild`=59888 WHERE `DisplayID`=80533;
UPDATE `creature_model_info` SET `BoundingRadius`=0.687500238418579101, `CombatReach`=1.440000057220458984, `VerifiedBuild`=59888 WHERE `DisplayID`=42656;
UPDATE `creature_model_info` SET `BoundingRadius`=0.579470038414001464, `VerifiedBuild`=59888 WHERE `DisplayID`=52600;
UPDATE `creature_model_info` SET `BoundingRadius`=1.339599251747131347, `CombatReach`=1.75, `VerifiedBuild`=59888 WHERE `DisplayID`=342;
UPDATE `creature_model_info` SET `BoundingRadius`=0.487930387258529663, `CombatReach`=0.625, `VerifiedBuild`=59888 WHERE `DisplayID`=80265;
UPDATE `creature_model_info` SET `BoundingRadius`=1.447181582450866699, `CombatReach`=0.699999988079071044, `VerifiedBuild`=59888 WHERE `DisplayID`=81217;
UPDATE `creature_model_info` SET `BoundingRadius`=1.876965761184692382, `CombatReach`=2, `VerifiedBuild`=59888 WHERE `DisplayID`=78242;
UPDATE `creature_model_info` SET `BoundingRadius`=2.123496532440185546, `CombatReach`=1.399999976158142089, `VerifiedBuild`=59888 WHERE `DisplayID`=72014;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=59888 WHERE `DisplayID`=85507;
UPDATE `creature_model_info` SET `BoundingRadius`=0.446400046348571777, `CombatReach`=1.80000007152557373, `VerifiedBuild`=59888 WHERE `DisplayID`=52574;
UPDATE `creature_model_info` SET `BoundingRadius`=0.800000011920928955, `VerifiedBuild`=59888 WHERE `DisplayID`=87182;
UPDATE `creature_model_info` SET `BoundingRadius`=2.085362434387207031, `VerifiedBuild`=59888 WHERE `DisplayID`=64329;
UPDATE `creature_model_info` SET `BoundingRadius`=2.666666507720947265, `VerifiedBuild`=59888 WHERE `DisplayID`=76046;
UPDATE `creature_model_info` SET `BoundingRadius`=0.830890595912933349, `CombatReach`=1, `VerifiedBuild`=59888 WHERE `DisplayID`=81194;
UPDATE `creature_model_info` SET `BoundingRadius`=0.228800013661384582, `CombatReach`=1.65000009536743164, `VerifiedBuild`=59888 WHERE `DisplayID`=87866;
UPDATE `creature_model_info` SET `BoundingRadius`=0.336600035429000854, `CombatReach`=1.65000009536743164, `VerifiedBuild`=59888 WHERE `DisplayID`=87860;
UPDATE `creature_model_info` SET `BoundingRadius`=0.954134941101074218, `VerifiedBuild`=59888 WHERE `DisplayID`=84812;
