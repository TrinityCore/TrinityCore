SET @CGUID := 9004529;
SET @OGUID := 9003985;
SET @WORLD_SAFE_LOC_ID := 100103;
SET @SPAWN_GROUP := 1274;

DELETE FROM `world_safe_locs` WHERE `ID` BETWEEN @WORLD_SAFE_LOC_ID+0 AND @WORLD_SAFE_LOC_ID+1;
INSERT INTO `world_safe_locs` (`ID`, `MapID`, `LocX`, `LocY`, `LocZ`, `Facing`, `Comment`) VALUES
(@WORLD_SAFE_LOC_ID+0, 2563, -591.04865, 4226.06, 382.116, DEGREES(5.6160145), 'Nokhudon Proving Grounds - Purple Team'),
(@WORLD_SAFE_LOC_ID+1, 2563, -475.53995, 4131.1865, 381.69434, DEGREES(2.3969803), 'Nokhudon Proving Grounds - Gold Team');

DELETE FROM `battleground_scripts` WHERE `MapId` = 2563 AND `BattlemasterListId` = 0;
INSERT INTO `battleground_scripts` (`MapId`, `BattlemasterListId`, `ScriptName`) VALUES
(2563, 0, 'arena_nokhudon_proving_grounds');

DELETE FROM `battleground_template` WHERE `ID` = 1088;
INSERT INTO `battleground_template` (`ID`, `AllianceStartLoc`, `HordeStartLoc`, `StartMaxDist`, `Weight`, `Comment`) VALUES
(1088, @WORLD_SAFE_LOC_ID+0, @WORLD_SAFE_LOC_ID+1, 0, 1, 'Nokhudon Proving Grounds');

DELETE FROM `conversation_actors` WHERE (`Idx`=0 AND `ConversationId` IN (20101,20102));
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(20101, 88583, @CGUID+25, 0, 0, 0, 0, 0, 63305), -- Full: 0x2042394060C00F80002F720000582878 Creature/0 R4238/S12146 Map: 2563 (Nokhudon Proving Grounds) Entry: 196670 (Malicia) Low: 5777528
(20102, 88583, @CGUID+25, 0, 0, 0, 0, 0, 63305); -- Full: 0x2042394060C00F80002F720000582878 Creature/0 R4238/S12146 Map: 2563 (Nokhudon Proving Grounds) Entry: 196670 (Malicia) Low: 5777528

DELETE FROM `conversation_line_template` WHERE `Id` IN (51743, 51744, 21375, 21374, 21373);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(51743, 0, 0, 0, 0, 63305),
(51744, 0, 0, 0, 0, 63305),
(21375, 0, 0, 0, 0, 63305),
(21374, 0, 0, 0, 0, 63305),
(21373, 0, 0, 0, 0, 63305);

DELETE FROM `conversation_template` WHERE `Id` IN (20101, 20102);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(20101, 51743, 0, 63305),
(20102, 51744, 0, 63305);

DELETE FROM `gameobject_template_addon` WHERE `entry`=379282;
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(379282, 1375, 0x20, 0, 0); -- Arena Door

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+25;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 197021, 2563, 14436, 14436, '0', '0', 0, 0, 0, -516.84552001953125, 4217.75244140625, 411.653839111328125, 4.585444927215576171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Combatant Observers (Area: Nokhudon Proving Grounds - Difficulty: 0) CreateObject1
(@CGUID+1, 197021, 2563, 14436, 14436, '0', '0', 0, 0, 0, -544.99652099609375, 4233.54345703125, 412.907470703125, 4.454012870788574218, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Combatant Observers (Area: Nokhudon Proving Grounds - Difficulty: 0) CreateObject1
(@CGUID+2, 197021, 2563, 14436, 14436, '0', '0', 0, 0, 0, -540.23089599609375, 4234.35400390625, 413.33526611328125, 4.739606380462646484, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Combatant Observers (Area: Nokhudon Proving Grounds - Difficulty: 0) CreateObject1
(@CGUID+3, 197021, 2563, 14436, 14436, '0', '0', 0, 0, 0, -515.3992919921875, 4222.30712890625, 413.114410400390625, 3.938925981521606445, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Combatant Observers (Area: Nokhudon Proving Grounds - Difficulty: 0) CreateObject1
(@CGUID+4, 197021, 2563, 14436, 14436, '0', '0', 0, 0, 0, -521.4288330078125, 4223.7880859375, 412.141632080078125, 4.116581916809082031, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Combatant Observers (Area: Nokhudon Proving Grounds - Difficulty: 0) CreateObject1
(@CGUID+5, 197021, 2563, 14436, 14436, '0', '0', 0, 0, 0, -549.81597900390625, 4232.26220703125, 412.218017578125, 4.739606380462646484, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Combatant Observers (Area: Nokhudon Proving Grounds - Difficulty: 0) CreateObject1
(@CGUID+6, 197021, 2563, 14436, 14436, '0', '0', 0, 0, 0, -524.24481201171875, 4228.33349609375, 412.783782958984375, 3.996626138687133789, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Combatant Observers (Area: Nokhudon Proving Grounds - Difficulty: 0) CreateObject1
(@CGUID+7, 197021, 2563, 14436, 14436, '0', '0', 0, 0, 0, -500.208343505859375, 4225.02099609375, 413.283935546875, 4.996204376220703125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Combatant Observers (Area: Nokhudon Proving Grounds - Difficulty: 0) CreateObject1
(@CGUID+8, 197245, 2563, 14436, 14436, '0', '0', 0, 0, 0, -521.15625, 4216.90478515625, 410.611083984375, 4.535685539245605468, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Meenor (Area: Nokhudon Proving Grounds - Difficulty: 0) CreateObject1
(@CGUID+9, 197021, 2563, 14436, 14436, '0', '0', 0, 0, 0, -509.401031494140625, 4219.05126953125, 411.67694091796875, 4.383775711059570312, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Combatant Observers (Area: Nokhudon Proving Grounds - Difficulty: 0) CreateObject1
(@CGUID+10, 197021, 2563, 14436, 14436, '0', '0', 0, 0, 0, -502.118072509765625, 4220.85498046875, 412.223388671875, 5.136957645416259765, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Combatant Observers (Area: Nokhudon Proving Grounds - Difficulty: 0) CreateObject1
(@CGUID+11, 197021, 2563, 14436, 14436, '0', '0', 0, 0, 0, -536.66668701171875, 4234.837890625, 413.575714111328125, 4.348513126373291015, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Combatant Observers (Area: Nokhudon Proving Grounds - Difficulty: 0) CreateObject1
(@CGUID+12, 196986, 2563, 14436, 14436, '0', '0', 0, 0, 0, -464.77105712890625, 4196.78857421875, 443.492919921875, 0.190508812665939331, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Nokhud Vulture (Area: Nokhudon Proving Grounds - Difficulty: 0) CreateObject1
(@CGUID+13, 196986, 2563, 14436, 14436, '0', '0', 0, 0, 0, -533.030029296875, 4255.65869140625, 459.373077392578125, 1.438202381134033203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Nokhud Vulture (Area: Nokhudon Proving Grounds - Difficulty: 0) CreateObject1
(@CGUID+14, 196986, 2563, 14436, 14436, '0', '0', 0, 0, 0, -553.37652587890625, 4198.7861328125, 443.492919921875, 1.128515005111694335, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Nokhud Vulture (Area: Nokhudon Proving Grounds - Difficulty: 0) CreateObject1
(@CGUID+15, 196470, 2563, 14436, 14436, '0', '0', 0, 0, 0, -555.94793701171875, 4126.5087890625, 381.65057373046875, 0.837407588958740234, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Nokhud Combatant (Area: Nokhudon Proving Grounds - Difficulty: 0) CreateObject1
(@CGUID+16, 196470, 2563, 14436, 14436, '0', '0', 0, 0, 0, -547.1319580078125, 4117.54248046875, 381.678131103515625, 0.837407588958740234, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Nokhud Combatant (Area: Nokhudon Proving Grounds - Difficulty: 0) CreateObject1
(@CGUID+17, 196470, 2563, 14436, 14436, '0', '0', 0, 0, 0, -554.140625, 4105.923828125, 383.053131103515625, 0.837407588958740234, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Nokhud Combatant (Area: Nokhudon Proving Grounds - Difficulty: 0) CreateObject1
(@CGUID+18, 196986, 2563, 14436, 14436, '0', '0', 0, 0, 0, -534.19000244140625, 4150.16943359375, 443.492919921875, 1.166725397109985351, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Nokhud Vulture (Area: Nokhudon Proving Grounds - Difficulty: 0) CreateObject1
(@CGUID+19, 196470, 2563, 14436, 14436, '0', '0', 0, 0, 0, -542.22918701171875, 4113.1474609375, 382.2135009765625, 0.837407588958740234, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Nokhud Combatant (Area: Nokhudon Proving Grounds - Difficulty: 0) CreateObject1
(@CGUID+20, 197290, 2563, 14436, 14436, '0', '0', 0, 0, 0, -555.3038330078125, 4228.72412109375, 411.27679443359375, 5.241607666015625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Arudien Sandalwood (Area: Nokhudon Proving Grounds - Difficulty: 0) CreateObject1
(@CGUID+21, 196470, 2563, 14436, 14436, '0', '0', 0, 0, 0, -553.14239501953125, 4098.9833984375, 383.6409912109375, 0.837407588958740234, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Nokhud Combatant (Area: Nokhudon Proving Grounds - Difficulty: 0) CreateObject1
(@CGUID+22, 196470, 2563, 14436, 14436, '0', '0', 0, 0, 0, -547.59722900390625, 4102.5224609375, 385.33984375, 0.837407588958740234, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Nokhud Combatant (Area: Nokhudon Proving Grounds - Difficulty: 0) CreateObject1
(@CGUID+23, 196470, 2563, 14436, 14436, '0', '0', 0, 0, 0, -573.5538330078125, 4120.93505859375, 381.678131103515625, 0.837407588958740234, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Nokhud Combatant (Area: Nokhudon Proving Grounds - Difficulty: 0) CreateObject1
(@CGUID+24, 196470, 2563, 14436, 14436, '0', '0', 0, 0, 0, -563.2586669921875, 4128.56103515625, 381.65057373046875, 0.837407588958740234, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Nokhud Combatant (Area: Nokhudon Proving Grounds - Difficulty: 0) CreateObject1
(@CGUID+25, 196670, 2563, 14436, 14436, '0', '0', 0, 0, 0, -601.13714599609375, 4145.87744140625, 394.360321044921875, 0.411279410123825073, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305); -- Malicia (Area: Nokhudon Proving Grounds - Difficulty: 0) CreateObject1 (Auras: )

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+6;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 379282, 2563, 14436, 14436, '0', '0', 0, -483.23089599609375, 4134.76220703125, 381.383941650390625, 2.442239999771118164, 0, 0, 0.939483642578125, 0.342593759298324584, 7200, 255, 1, 63305), -- Arena Door (Area: Nokhudon Proving Grounds - Difficulty: 0) CreateObject1
(@OGUID+1, 381620, 2563, 14436, 14436, '0', '0', 0, -651.515625, 4105.353515625, 386.51214599609375, 2.652894020080566406, 0, 0, 0.970294952392578125, 0.241925001144409179, 7200, 255, 1, 63305), -- 10CT_Centaur_FoodRack02_meat.M2 (Area: Nokhudon Proving Grounds - Difficulty: 0) CreateObject1
(@OGUID+2, 381619, 2563, 14436, 14436, '0', '0', 0, -677.72222900390625, 4285.220703125, 401.207672119140625, 3.769911527633666992, 0, 0, -0.95105648040771484, 0.309017121791839599, 7200, 255, 1, 63305), -- Campfire (Area: Nokhudon Proving Grounds - Difficulty: 0) CreateObject1
(@OGUID+3, 381618, 2563, 14436, 14436, '0', '0', 0, -419.352447509765625, 4194.9150390625, 387.279205322265625, 0.261798173189163208, 0, 0, 0.130525588989257812, 0.991444945335388183, 7200, 255, 1, 63305), -- Campfire (Area: Nokhudon Proving Grounds - Difficulty: 0) CreateObject1
(@OGUID+4, 379282, 2563, 14436, 14436, '0', '0', 0, -585.78643798828125, 4220.5224609375, 381.53326416015625, 5.580377578735351562, 0, 0, -0.34421634674072265, 0.938890337944030761, 7200, 255, 1, 63305), -- Arena Door (Area: Nokhudon Proving Grounds - Difficulty: 0) CreateObject1
(@OGUID+5, 184663, 2563, 14436, 14436, '0', '0', 0, -583.763916015625, 4170.548828125, 380.34564208984375, 0, 0, 0, 0, 1, 360, 255, 1, 63305), -- Shadow Sight (Area: Nokhudon Proving Grounds - Difficulty: 0) CreateObject2
(@OGUID+6, 184664, 2563, 14436, 14436, '0', '0', 0, -487.916656494140625, 4191.6103515625, 380.926422119140625, 3.471065282821655273, 0, 0, -0.98646163940429687, 0.163992181420326232, 360, 255, 1, 63305); -- Shadow Sight (Area: Nokhudon Proving Grounds - Difficulty: 0) CreateObject2
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+6;

DELETE FROM `creature_template_addon` WHERE `entry` IN (196470 /*196470 (Nokhud Combatant)*/, 196986 /*196986 (Nokhud Vulture)*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(196470, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 196470 (Nokhud Combatant)
(196986, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- 196986 (Nokhud Vulture)

UPDATE `creature_template_difficulty` SET `ContentTuningID`=2437, `VerifiedBuild`=63305 WHERE (`Entry`=196670 AND `DifficultyID`=0); -- 196670 (Malicia) -
UPDATE `creature_template_difficulty` SET `ContentTuningID`=969, `VerifiedBuild`=63305 WHERE (`Entry`=197290 AND `DifficultyID`=0); -- 197290 (Arudien Sandalwood) -
UPDATE `creature_template_difficulty` SET `ContentTuningID`=969, `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=196470 AND `DifficultyID`=0); -- 196470 (Nokhud Combatant) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=969, `StaticFlags1`=0x30000000, `VerifiedBuild`=63305 WHERE (`Entry`=196986 AND `DifficultyID`=0); -- 196986 (Nokhud Vulture) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=969, `VerifiedBuild`=63305 WHERE (`Entry`=197245 AND `DifficultyID`=0); -- 197245 (Meenor) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=969, `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=197021 AND `DifficultyID`=0); -- 197021 (Combatant Observers) - CanSwim

UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x2000000, `unit_flags2`=0x4000800 WHERE `entry`=196670; -- Malicia
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x4000800 WHERE `entry`=197290; -- Arudien Sandalwood
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x2000040, `unit_flags2`=0x800 WHERE `entry`=196470; -- Nokhud Combatant
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x2000000, `unit_flags2`=0x800 WHERE `entry`=196986; -- Nokhud Vulture
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x4000800 WHERE `entry`=197245; -- Meenor
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x2000000, `unit_flags2`=0x800 WHERE `entry`=197021; -- Combatant Observers

UPDATE `creature_template` SET `ScriptName`= 'npc_nokhudon_proving_grounds_nokhud_combatant' WHERE `entry`=196470; -- Nokhud Combatant

DELETE FROM `spawn_group_template` WHERE `groupId` = @SPAWN_GROUP;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWN_GROUP, 'Nokhudon Proving Grounds - Shadow sight', 0x20);

DELETE FROM `spawn_group` WHERE `groupId` = @SPAWN_GROUP;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWN_GROUP, 1, @OGUID+5),
(@SPAWN_GROUP, 1, @OGUID+6);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 33 AND `SourceEntry` = @SPAWN_GROUP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `SourceGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ScriptName`) VALUES
(33, @SPAWN_GROUP, 0, 0, 0, 'condition_is_shadow_sight_enabled');

DELETE FROM `creature_text` WHERE `CreatureID` IN (196670);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(196670, 0, 0, 'Let the best team win! Oh, who am I kidding--give me a good show.', 12, 0, 100, 0, 0, 200426, 223427, 3, 'Malicia'),
(196670, 1, 0, 'It\'s time for the show! Don\'t disappoint me.', 12, 0, 100, 0, 0, 200422, 223429, 3, 'Malicia'),
(196670, 2, 0, 'So close! This just means more entertainment for me.', 12, 0, 100, 0, 0, 200427, 223428, 3, 'Malicia to Player');

DELETE FROM `spell_proc` WHERE `SpellId` IN (388970);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(388970,0x00,0,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0,0,0,0); -- Nokhudon Proving Grounds Reaction Trigger

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_nokhudon_proving_grounds_reaction_trigger', 'spell_nokhudon_proving_grounds_trigger_low_health');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(388969, 'spell_nokhudon_proving_grounds_trigger_low_health'),
(388970, 'spell_nokhudon_proving_grounds_reaction_trigger');

SET @MOVERGUID := @CGUID+13;
SET @ENTRY := 196986;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8687, 'Nokhud Vulture - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -533.00854, 4255.81, 459.37305, NULL, 0),
(@PATH, 1, -525.09393, 4268.9126, 459.37305, NULL, 0),
(@PATH, 2, -510.2326, 4272.5806, 459.37305, NULL, 0),
(@PATH, 3, -497.13022, 4264.666, 459.37305, NULL, 0),
(@PATH, 4, -493.4619, 4249.8047, 459.37305, NULL, 0),
(@PATH, 5, -501.3766, 4236.702, 459.37305, NULL, 0),
(@PATH, 6, -516.23785, 4233.034, 459.37305, NULL, 0),
(@PATH, 7, -529.3403, 4240.9487, 459.37305, NULL, 0);

UPDATE `creature` SET `position_x`=-533.00854, `position_y`=4255.81, `position_z`=459.37305, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

SET @MOVERGUID := @CGUID+12;
SET @ENTRY := 196986;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.6715, 'Nokhud Vulture - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -466.12238, 4196.493, 443.49292, NULL, 0),
(@PATH, 1, -454.4281, 4197.0044, 443.49292, NULL, 0),
(@PATH, 2, -443.42847, 4193.001, 443.49292, NULL, 0),
(@PATH, 3, -434.79803, 4185.0933, 443.49292, NULL, 0),
(@PATH, 4, -429.85074, 4174.485, 443.49292, NULL, 0),
(@PATH, 5, -429.33975, 4162.7905, 443.49292, NULL, 0),
(@PATH, 6, -433.34283, 4151.791, 443.49292, NULL, 0),
(@PATH, 7, -441.2506, 4143.1606, 443.49292, NULL, 0),
(@PATH, 8, -451.85916, 4138.2134, 443.49292, NULL, 0),
(@PATH, 9, -463.5534, 4137.702, 443.49292, NULL, 0),
(@PATH, 10, -474.55307, 4141.705, 443.49292, NULL, 0),
(@PATH, 11, -483.18347, 4149.6133, 443.49292, NULL, 0),
(@PATH, 12, -488.13077, 4160.2217, 443.49292, NULL, 0),
(@PATH, 13, -488.64175, 4171.916, 443.49292, NULL, 0),
(@PATH, 14, -484.63867, 4182.9155, 443.49292, NULL, 0),
(@PATH, 15, -476.7309, 4191.546, 443.49292, NULL, 0);

UPDATE `creature` SET `position_x`=-466.12238, `position_y`=4196.493, `position_z`=443.49292, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

SET @MOVERGUID := @CGUID+14;
SET @ENTRY := 196986;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.6714, 'Nokhud Vulture - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -553.9386, 4197.5195, 443.49292, NULL, 0),
(@PATH, 1, -547.4354, 4207.2524, 443.49292, NULL, 0),
(@PATH, 2, -537.70276, 4213.7554, 443.49292, NULL, 0),
(@PATH, 3, -526.2222, 4216.039, 443.49292, NULL, 0),
(@PATH, 4, -514.7417, 4213.7554, 443.49292, NULL, 0),
(@PATH, 5, -505.00903, 4207.2524, 443.49292, NULL, 0),
(@PATH, 6, -498.50586, 4197.5195, 443.49292, NULL, 0),
(@PATH, 7, -496.22223, 4186.039, 443.49292, NULL, 0),
(@PATH, 8, -498.50586, 4174.5586, 443.49292, NULL, 0),
(@PATH, 9, -505.00903, 4164.8257, 443.49292, NULL, 0),
(@PATH, 10, -514.7417, 4158.3228, 443.49292, NULL, 0),
(@PATH, 11, -526.2222, 4156.039, 443.49292, NULL, 0),
(@PATH, 12, -537.70276, 4158.3228, 443.49292, NULL, 0),
(@PATH, 13, -547.4354, 4164.8257, 443.49292, NULL, 0),
(@PATH, 14, -553.9386, 4174.5586, 443.49292, NULL, 0),
(@PATH, 15, -556.2222, 4186.039, 443.49292, NULL, 0);

UPDATE `creature` SET `position_x`=-553.9386, `position_y`=4197.5195, `position_z`=443.49292, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

SET @MOVERGUID := @CGUID+18;
SET @ENTRY := 196986;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.6714, 'Nokhud Vulture - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -534.3119, 4149.88, 443.49292, NULL, 0),
(@PATH, 1, -527.8087, 4159.613, 443.49292, NULL, 0),
(@PATH, 2, -518.07605, 4166.1157, 443.49292, NULL, 0),
(@PATH, 3, -506.59552, 4168.3994, 443.49292, NULL, 0),
(@PATH, 4, -495.11502, 4166.1157, 443.49292, NULL, 0),
(@PATH, 5, -485.38232, 4159.613, 443.49292, NULL, 0),
(@PATH, 6, -478.87915, 4149.88, 443.49292, NULL, 0),
(@PATH, 7, -476.59552, 4138.3994, 443.49292, NULL, 0),
(@PATH, 8, -478.87915, 4126.919, 443.49292, NULL, 0),
(@PATH, 9, -485.38232, 4117.186, 443.49292, NULL, 0),
(@PATH, 10, -495.11502, 4110.683, 443.49292, NULL, 0),
(@PATH, 11, -506.59552, 4108.3994, 443.49292, NULL, 0),
(@PATH, 12, -518.07605, 4110.683, 443.49292, NULL, 0),
(@PATH, 13, -527.8087, 4117.186, 443.49292, NULL, 0),
(@PATH, 14, -534.3119, 4126.919, 443.49292, NULL, 0),
(@PATH, 15, -536.5955, 4138.3994, 443.49292, NULL, 0);

UPDATE `creature` SET `position_x`=-534.3119, `position_y`=4149.88, `position_z`=443.49292, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
