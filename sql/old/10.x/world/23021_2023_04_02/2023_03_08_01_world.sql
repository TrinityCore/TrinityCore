SET @CGUID := 9003463;
SET @OGUID := 9000352;

SET @NPCTEXTID := 590048;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+18;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 198895, 2444, 13862, 14489, '0', 0, 0, 0, 0, 234.2135467529296875, -1059.779541015625, 870.8746337890625, 1.720772266387939453, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48317), -- Alregosa (Area: The Seat of the Aspects - Difficulty: 0) (Auras: 384436 - Channel: Read Floating Book (Dragon) (BlueFX) [DNT])
(@CGUID+1, 197766, 2444, 13862, 14489, '0', 0, 0, 0, 0, 241.4809112548828125, -1071.0052490234375, 911.65740966796875, 4.21468973159790039, 120, 0, 0, 33876, 0, 0, 0, 0, 0, 48317), -- Attentive Whelp (Area: The Seat of the Aspects - Difficulty: 0)
(@CGUID+2, 184168, 2444, 13862, 14489, '0', 0, 0, 0, 1, 300.37847900390625, -1058.78125, 871.3021240234375, 2.752871274948120117, 120, 0, 0, 1693785, 0, 0, 0, 0, 0, 48317), -- Scalesworn Guardian (Area: The Seat of the Aspects - Difficulty: 0) (Auras: )
(@CGUID+3, 193280, 2444, 13862, 14489, '0', 0, 0, 0, 0, 273.760406494140625, -1018.94622802734375, 870.8746337890625, 5.882435798645019531, 120, 0, 0, 338757, 0, 0, 0, 0, 0, 48317), -- Portal Bearer (Area: The Seat of the Aspects - Difficulty: 0) (Auras: 381337 - [DNT] Channel Arcane)
(@CGUID+4, 197766, 2444, 13862, 14489, '0', 0, 0, 0, 0, 243.564239501953125, -1070.3004150390625, 911.65740966796875, 4.007763862609863281, 120, 0, 0, 33876, 0, 0, 0, 0, 0, 48317), -- Attentive Whelp (Area: The Seat of the Aspects - Difficulty: 0)
(@CGUID+5, 184168, 2444, 13862, 14489, '0', 0, 0, 0, 1, 287.258697509765625, -1076.717041015625, 871.3028564453125, 2.435326576232910156, 120, 0, 0, 1693785, 0, 0, 0, 0, 0, 48317), -- Scalesworn Guardian (Area: The Seat of the Aspects - Difficulty: 0) (Auras: )
(@CGUID+6, 193015, 2444, 13862, 14489, '0', 0, 0, 0, 0, 309.657989501953125, -1044.4254150390625, 870.7960205078125, 2.976417064666748046, 120, 0, 0, 135503, 0, 0, 0, 0, 0, 48317), -- Unatos (Area: The Seat of the Aspects - Difficulty: 0)
(@CGUID+7, 198446, 2444, 13862, 14489, '0', 0, 0, 0, 0, 239.4583282470703125, -1075.1024169921875, 912.59490966796875, 0.856774091720581054, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48317), -- Storidormi (Area: The Seat of the Aspects - Difficulty: 0)
(@CGUID+8, 193280, 2444, 13862, 14489, '0', 0, 0, 0, 0, 283.4757080078125, -1025.93408203125, 870.8489990234375, 2.318567276000976562, 120, 0, 0, 338757, 0, 0, 0, 0, 0, 48317), -- Portal Bearer (Area: The Seat of the Aspects - Difficulty: 0) (Auras: 381337 - [DNT] Channel Arcane)
(@CGUID+9, 197766, 2444, 13862, 14489, '0', 0, 0, 0, 0, 244.0677032470703125, -1073.1336669921875, 911.80511474609375, 3.631802797317504882, 120, 0, 0, 33876, 0, 0, 0, 0, 0, 48317), -- Attentive Whelp (Area: The Seat of the Aspects - Difficulty: 0)
(@CGUID+10, 198447, 2444, 13862, 14489, '0', 0, 0, 0, 0, 238.5520782470703125, -1068.482666015625, 911.65740966796875, 4.739333152770996093, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48317), -- Whelp Minder (Area: The Seat of the Aspects - Difficulty: 0)
(@CGUID+11, 193282, 2444, 13862, 14489, '0', 0, 0, 0, 0, 250.2395782470703125, -1071.1666259765625, 870.8521728515625, 2.647563457489013671, 120, 0, 0, 338757, 0, 0, 0, 0, 0, 48317), -- Portal Bearer (Area: The Seat of the Aspects - Difficulty: 0) (Auras: 381337 - [DNT] Channel Arcane)
(@CGUID+12, 184168, 2444, 13862, 14489, '0', 0, 0, 0, 1, 248.3177032470703125, -1013.44622802734375, 871.16259765625, 5.437053203582763671, 120, 0, 0, 1693785, 0, 0, 0, 0, 0, 48317), -- Scalesworn Guardian (Area: The Seat of the Aspects - Difficulty: 0) (Auras: )
(@CGUID+13, 197766, 2444, 13862, 14489, '0', 0, 0, 0, 0, 241.4027862548828125, -1068.6944580078125, 911.65740966796875, 4.277214527130126953, 120, 0, 0, 33876, 0, 0, 0, 0, 0, 48317), -- Attentive Whelp (Area: The Seat of the Aspects - Difficulty: 0)
(@CGUID+14, 193282, 2444, 13862, 14489, '0', 0, 0, 0, 0, 240.3854217529296875, -1064.5225830078125, 870.87469482421875, 5.592447757720947265, 120, 0, 0, 338757, 0, 0, 0, 0, 0, 48317), -- Portal Bearer (Area: The Seat of the Aspects - Difficulty: 0) (Auras: 381337 - [DNT] Channel Arcane)
(@CGUID+15, 184168, 2444, 13862, 14489, '0', 0, 0, 0, 1, 226.61285400390625, -1042.2603759765625, 871.16259765625, 6.0945587158203125, 120, 0, 0, 1693785, 0, 0, 0, 0, 0, 48317), -- Scalesworn Guardian (Area: The Seat of the Aspects - Difficulty: 0) (Auras: )
(@CGUID+16, 184168, 2444, 13862, 14489, '0', 0, 0, 0, 1, 442.119781494140625, -1032.2847900390625, 892.9259033203125, 0.597674071788787841, 120, 0, 0, 1693785, 0, 0, 0, 0, 0, 48317), -- Scalesworn Guardian (Area: The Seat of the Aspects - Difficulty: 0) (Auras: )
(@CGUID+17, 184168, 2444, 13862, 14489, '0', 0, 0, 0, 1, 115.104156494140625, -1038.26220703125, 838.72430419921875, 5.169855594635009765, 120, 0, 0, 1693785, 0, 0, 0, 0, 0, 48317), -- Scalesworn Guardian (Area: The Seat of the Aspects - Difficulty: 0) (Auras: )
(@CGUID+18, 184168, 2444, 13862, 14489, '0', 0, 0, 0, 1, 107.4288177490234375, -1021.23089599609375, 838.66455078125, 3.345880508422851562, 120, 0, 0, 1693785, 0, 0, 0, 0, 0, 48317); -- Scalesworn Guardian (Area: The Seat of the Aspects - Difficulty: 0) (Auras: )
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+18;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+1, 0, 0, 0, 0, 0, 1, 0, 0, 18310, 0, 0, 0, ''), -- Attentive Whelp
(@CGUID+2, 0, 0, 0, 0, 0, 1, 1, 717, 0, 0, 0, 0, ''), -- Scalesworn Guardian
(@CGUID+4, 0, 0, 0, 0, 0, 1, 0, 0, 18310, 0, 0, 0, ''), -- Attentive Whelp
(@CGUID+5, 0, 0, 0, 0, 0, 1, 1, 714, 0, 0, 0, 0, ''), -- Scalesworn Guardian
(@CGUID+7, 0, 0, 0, 0, 0, 1, 1, 378, 0, 0, 0, 0, ''), -- Storidormi
(@CGUID+9, 0, 0, 0, 0, 0, 1, 0, 0, 18310, 0, 0, 0, ''), -- Attentive Whelp
(@CGUID+10, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Whelp Minder
(@CGUID+12, 0, 0, 0, 0, 0, 1, 1, 714, 0, 0, 0, 0, ''), -- Scalesworn Guardian
(@CGUID+13, 0, 0, 0, 0, 0, 1, 0, 0, 18310, 0, 0, 0, ''), -- Attentive Whelp
(@CGUID+15, 0, 0, 0, 0, 0, 1, 1, 717, 0, 0, 0, 0, ''), -- Scalesworn Guardian
(@CGUID+16, 0, 0, 0, 0, 0, 1, 1, 714, 0, 0, 0, 0, ''), -- Scalesworn Guardian
(@CGUID+17, 0, 0, 0, 0, 0, 1, 1, 714, 0, 0, 0, 0, ''), -- Scalesworn Guardian
(@CGUID+18, 0, 0, 0, 0, 0, 1, 1, 714, 0, 0, 0, 0, ''); -- Scalesworn Guardian

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+3;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 376417, 2444, 13862, 14489, '0', 0, 0, 245.4583282470703125, -1068.1180419921875, 870.78900146484375, 0.966586709022521972, 0, 0, 0.464697837829589843, 0.885469317436218261, 120, 255, 1, 48317), -- Portal to Stormwind (Area: The Seat of the Aspects - Difficulty: 0)
(@OGUID+1, 376418, 2444, 13862, 14489, '0', 0, 0, 278.9444580078125, -1021.5521240234375, 870.7882080078125, 0.966586709022521972, 0, 0, 0.464697837829589843, 0.885469317436218261, 120, 255, 1, 48317), -- Portal to Orgrimmar (Area: The Seat of the Aspects - Difficulty: 0)
(@OGUID+2, 378263, 2444, 13862, 14489, '0', 0, 0, 338.729156494140625, -1099.7083740234375, 894.79083251953125, 2.52008676528930664, 0, 0, 0.952103614807128906, 0.305775582790374755, 120, 255, 1, 48317), -- Teleport to Seat of the Aspects (Area: The Seat of the Aspects - Difficulty: 0)
(@OGUID+3, 380823, 2444, 13862, 14489, '0', 0, 0, 203.829864501953125, -1003.513916015625, 1436.8720703125, 5.665316581726074218, 0, 0, -0.30404376983642578, 0.952658057212829589, 120, 255, 1, 48317); -- Teleport to Bottom Floor (Area: The Seat of the Aspects - Difficulty: 0)
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+3;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 0, 1, 0, 3503), -- Portal to Stormwind
(@OGUID+1, 0, 0, 0, 1, 0, 3503), -- Portal to Orgrimmar
(@OGUID+2, 0, 0, 0, 1, 0, 5460), -- Teleport to Seat of the Aspects
(@OGUID+3, 0, 0, 0, 1, 0, 5460); -- Teleport to Bottom Floor

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (380823 /*Teleport to Bottom Floor*/, 378263 /*Teleport to Seat of the Aspects*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(380823, 0, 262176, 0, 5460), -- Teleport to Bottom Floor
(378263, 0, 262176, 0, 5460); -- Teleport to Seat of the Aspects

-- Creature Template
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=3277, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048, `unit_flags3`=8388608 WHERE `entry`=184170; -- Scalesworn Guardian
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=3276, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry` IN (193282, 193280); -- Portal Bearer
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=198447; -- Whelp Minder
UPDATE `creature_template` SET `gossip_menu_id`=30060, `minlevel`=70, `maxlevel`=70, `faction`=3276, `npcflag`=1, `BaseAttackTime`=1000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=198446; -- Storidormi
UPDATE `creature_template` SET `gossip_menu_id`=28544, `minlevel`=70, `maxlevel`=70, `faction`=35, `npcflag`=131, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=193015; -- Unatos
UPDATE `creature_template` SET `gossip_menu_id`=27947, `minlevel`=70, `maxlevel`=70, `faction`=3277, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048, `unit_flags3`=8388608 WHERE `entry`=184168; -- Scalesworn Guardian
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=197766; -- Attentive Whelp
UPDATE `creature_template` SET `gossip_menu_id`=30163, `minlevel`=70, `maxlevel`=70, `faction`=35, `npcflag`=49, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=34816 WHERE `entry`=198895; -- Alregosa

-- Equip Template
DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (184170,184168));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(184170, 1, 191420, 0, 0, 0, 0, 0, 0, 0, 0, 48317), -- Scalesworn Guardian
(184168, 1, 192518, 0, 0, 0, 0, 0, 0, 0, 0, 48317); -- Scalesworn Guardian

-- Scaling
DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (201499,201498,201501,201500,201492,199261));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(201499, 0, 0, 0, 2508, 48317),
(201498, 0, 0, 0, 2508, 48317),
(201501, 0, 0, 0, 2508, 48317),
(201500, 0, 0, 0, 2508, 48317),
(201492, 0, 0, 0, 2594, 48317),
(199261, 0, 0, 0, 2078, 48317);

-- Spell target pos. data
DELETE FROM `spell_target_position` WHERE (`EffectIndex`=0 AND `ID` IN (385242,381326));
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(385242, 0, 2444, 291.470001220703125, -1066.1099853515625, 871.54998779296875, 48317), -- Spell: 385242 ([DNT] Teleport FROM Seat of the Aspects) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(381326, 0, 2444, 238.3699951171875, -1028.219970703125, 1437.2900390625, 48317); -- Spell: 381326 ([DNT] Teleport to Seat of the Aspects) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)

-- Gossip
DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+3;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 232880, 0, 0, 0, 0, 0, 0, 0, 48317), -- 198895 (Alregosa)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 232472, 0, 0, 0, 0, 0, 0, 0, 48317), -- 198446 (Storidormi)
(@NPCTEXTID+2, 1, 0, 0, 0, 0, 0, 0, 0, 224161, 0, 0, 0, 0, 0, 0, 0, 48317), -- 193015 (Unatos)
(@NPCTEXTID+3, 1, 0, 0, 0, 0, 0, 0, 0, 232881, 0, 0, 0, 0, 0, 0, 0, 48317); -- 198895 (Alregosa)

DELETE FROM `gossip_menu` WHERE (`MenuID`=30163 AND `TextID`=@NPCTEXTID+3) OR (`MenuID`=30060 AND `TextID`=@NPCTEXTID+1) OR (`MenuID`=28544 AND `TextID`=@NPCTEXTID+2);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(30163, @NPCTEXTID+3, 48317), -- 198895 (Alregosa)
(30060, @NPCTEXTID+1, 48317), -- 198446 (Storidormi)
(28544, @NPCTEXTID+2, 48317); -- 193015 (Unatos)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=28544 AND `OptionID` IN (1,0)) OR (`MenuID`=30163 AND `OptionID`=0) OR (`MenuID`=30060 AND `OptionID` IN (0,2,1));
INSERT INTO `gossip_menu_option` (`GossipOptionID`, `MenuID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextId`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `Flags`, `OverrideIconID`, `GossipNpcOptionID`, `VerifiedBuild`) VALUES
(104165, 28544, 1, 1, 'I would like to browse the items you have for sale.', 0, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 48317),
(107565, 30163, 0, 3, 'Please teach me.', 8442, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 48317),
(107454, 30060, 0, 0, 'Tell me of the dracthyr\'s origins.', 0, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 48317),
(107452, 30060, 2, 0, 'Tell me of the Dawn of the Aspects.', 0, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 48317),
(107453, 30060, 1, 0, 'Tell me of Neltharion\'s downfall.', 0, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 48317),
(55557, 28544, 0, 53, 'Where do I stand with the Valdrakken Accord?', 0, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, 32484, 48317);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 30163 OR `SourceTypeOrReferenceId` = 14 AND `SourceGroup` = 30163;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 30163, 0, 0, 0, 15, 0, 128, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a mage'),
(14, 30163, @NPCTEXTID+0, 0, 0, 15, 0, 128, 0, 0, 0, 0, 0, '', 'Show gossip option if player is a mage');

-- Quest stuff
DELETE FROM `quest_request_items` WHERE `ID`=72406;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(72406, 0, 0, 0, 0, 'Welcome Valdrakken, $p.', 48317); -- Orientation: Valdrakken

DELETE FROM `creature_queststarter` WHERE (`id`=193015 AND `quest`=72406);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(193015, 72406, 48317); -- Orientation: Valdrakken offered Unatos

DELETE FROM `creature_questender` WHERE (`id`=193015 AND `quest`=72406);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(193015, 72406, 48317); -- Orientation: Valdrakken ended by Unatos

 -- Alregosa smart ai
SET @ENTRY := 198895;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 11, 384436, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On respawn - Self: Cast spell 384436 on Self');

 -- Portal Bearer smart ai
SET @ENTRY := 193280;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 11, 381337, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On respawn - Self: Cast spell 381337 on Self');

 -- Portal Bearer smart ai
SET @ENTRY := 193282;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 11, 381337, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On respawn - Self: Cast spell 381337 on Self');

-- Trainer Data
DELETE FROM `trainer` WHERE `Id`=1099;
INSERT INTO `trainer` (`Id`, `Type`, `Greeting`, `VerifiedBuild`) VALUES
(1099, 0, 'Welcome!', 48317);

DELETE FROM `trainer_spell` WHERE (`TrainerId`=1099 AND `SpellId` IN (395289,395277));
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqAbility1`, `ReqAbility2`, `ReqAbility3`, `ReqLevel`, `VerifiedBuild`) VALUES
(1099, 395289, 168000, 0, 0, 0, 0, 0, 68, 48317), -- No Faction found! MoneyCost not recalculated!
(1099, 395277, 168000, 0, 0, 0, 0, 0, 62, 48317); -- No Faction found! MoneyCost not recalculated!

DELETE FROM `creature_trainer` WHERE (`CreatureID`=198895 AND `MenuID`=30163 AND `OptionID`=0);
INSERT INTO `creature_trainer` (`CreatureID`, `TrainerID`, `MenuID`, `OptionID`) VALUES
(198895, 1099, 30163, 0);

-- Vendor Data
DELETE FROM `npc_vendor` WHERE (`entry`=193015 AND `item`=199763 AND `ExtendedCost`=7364 AND `type`=1) OR (`entry`=193015 AND `item`=199764 AND `ExtendedCost`=7364 AND `type`=1) OR (`entry`=193015 AND `item`=199765 AND `ExtendedCost`=7364 AND `type`=1) OR (`entry`=193015 AND `item`=199766 AND `ExtendedCost`=7364 AND `type`=1) OR (`entry`=193015 AND `item`=199736 AND `ExtendedCost`=7776 AND `type`=1) OR (`entry`=193015 AND `item`=199738 AND `ExtendedCost`=7791 AND `type`=1) OR (`entry`=193015 AND `item`=199739 AND `ExtendedCost`=7781 AND `type`=1) OR (`entry`=193015 AND `item`=200456 AND `ExtendedCost`=7779 AND `type`=1) OR (`entry`=193015 AND `item`=201795 AND `ExtendedCost`=7801 AND `type`=1) OR (`entry`=193015 AND `item`=201796 AND `ExtendedCost`=7801 AND `type`=1) OR (`entry`=193015 AND `item`=199820 AND `ExtendedCost`=7779 AND `type`=1) OR (`entry`=193015 AND `item`=199821 AND `ExtendedCost`=7779 AND `type`=1) OR (`entry`=193015 AND `item`=199823 AND `ExtendedCost`=7802 AND `type`=1) OR (`entry`=193015 AND `item`=199825 AND `ExtendedCost`=7801 AND `type`=1) OR (`entry`=193015 AND `item`=199700 AND `ExtendedCost`=7787 AND `type`=1) OR (`entry`=193015 AND `item`=199707 AND `ExtendedCost`=7801 AND `type`=1) OR (`entry`=193015 AND `item`=199806 AND `ExtendedCost`=7801 AND `type`=1) OR (`entry`=193015 AND `item`=199702 AND `ExtendedCost`=7787 AND `type`=1) OR (`entry`=193015 AND `item`=199705 AND `ExtendedCost`=7800 AND `type`=1) OR (`entry`=193015 AND `item`=199726 AND `ExtendedCost`=7801 AND `type`=1) OR (`entry`=193015 AND `item`=199728 AND `ExtendedCost`=7801 AND `type`=1) OR (`entry`=193015 AND `item`=199730 AND `ExtendedCost`=7801 AND `type`=1) OR (`entry`=193015 AND `item`=199732 AND `ExtendedCost`=7801 AND `type`=1) OR (`entry`=193015 AND `item`=199734 AND `ExtendedCost`=7803 AND `type`=1) OR (`entry`=193015 AND `item`=199670 AND `ExtendedCost`=7745 AND `type`=1) OR (`entry`=193015 AND `item`=199671 AND `ExtendedCost`=7743 AND `type`=1) OR (`entry`=193015 AND `item`=199672 AND `ExtendedCost`=7742 AND `type`=1) OR (`entry`=193015 AND `item`=199673 AND `ExtendedCost`=7741 AND `type`=1) OR (`entry`=193015 AND `item`=199674 AND `ExtendedCost`=7744 AND `type`=1) OR (`entry`=193015 AND `item`=199660 AND `ExtendedCost`=7745 AND `type`=1) OR (`entry`=193015 AND `item`=199661 AND `ExtendedCost`=7743 AND `type`=1) OR (`entry`=193015 AND `item`=199662 AND `ExtendedCost`=7742 AND `type`=1) OR (`entry`=193015 AND `item`=199663 AND `ExtendedCost`=7741 AND `type`=1) OR (`entry`=193015 AND `item`=199664 AND `ExtendedCost`=7744 AND `type`=1) OR (`entry`=193015 AND `item`=196962 AND `ExtendedCost`=7814 AND `type`=1) OR (`entry`=193015 AND `item`=197093 AND `ExtendedCost`=7814 AND `type`=1) OR (`entry`=193015 AND `item`=197350 AND `ExtendedCost`=7814 AND `type`=1) OR (`entry`=193015 AND `item`=197581 AND `ExtendedCost`=7814 AND `type`=1) OR (`entry`=193015 AND `item`=194320 AND `ExtendedCost`=7789 AND `type`=1) OR (`entry`=193015 AND `item`=198388 AND `ExtendedCost`=7788 AND `type`=1) OR (`entry`=193015 AND `item`=198389 AND `ExtendedCost`=7798 AND `type`=1) OR (`entry`=193015 AND `item`=199741 AND `ExtendedCost`=7788 AND `type`=1) OR (`entry`=193015 AND `item`=199742 AND `ExtendedCost`=7788 AND `type`=1) OR (`entry`=193015 AND `item`=199743 AND `ExtendedCost`=7778 AND `type`=1) OR (`entry`=193015 AND `item`=199744 AND `ExtendedCost`=7798 AND `type`=1) OR (`entry`=193015 AND `item`=199745 AND `ExtendedCost`=7782 AND `type`=1) OR (`entry`=193015 AND `item`=197145 AND `ExtendedCost`=7752 AND `type`=1) OR (`entry`=193015 AND `item`=197391 AND `ExtendedCost`=7752 AND `type`=1) OR (`entry`=193015 AND `item`=197613 AND `ExtendedCost`=7752 AND `type`=1) OR (`entry`=193015 AND `item`=199772 AND `ExtendedCost`=7799 AND `type`=1) OR (`entry`=193015 AND `item`=199773 AND `ExtendedCost`=7794 AND `type`=1) OR (`entry`=193015 AND `item`=199774 AND `ExtendedCost`=7799 AND `type`=1) OR (`entry`=193015 AND `item`=199775 AND `ExtendedCost`=7799 AND `type`=1) OR (`entry`=193015 AND `item`=199776 AND `ExtendedCost`=7793 AND `type`=1) OR (`entry`=193015 AND `item`=199757 AND `ExtendedCost`=7721 AND `type`=1) OR (`entry`=193015 AND `item`=199758 AND `ExtendedCost`=7721 AND `type`=1) OR (`entry`=193015 AND `item`=199680 AND `ExtendedCost`=7730 AND `type`=1) OR (`entry`=193015 AND `item`=199681 AND `ExtendedCost`=7730 AND `type`=1) OR (`entry`=193015 AND `item`=199682 AND `ExtendedCost`=7730 AND `type`=1) OR (`entry`=193015 AND `item`=199683 AND `ExtendedCost`=7730 AND `type`=1) OR (`entry`=193015 AND `item`=199684 AND `ExtendedCost`=7730 AND `type`=1) OR (`entry`=193015 AND `item`=199759 AND `ExtendedCost`=7364 AND `type`=1) OR (`entry`=193015 AND `item`=199760 AND `ExtendedCost`=7364 AND `type`=1) OR (`entry`=193015 AND `item`=199761 AND `ExtendedCost`=7364 AND `type`=1) OR (`entry`=193015 AND `item`=199762 AND `ExtendedCost`=7364 AND `type`=1) OR (`entry`=193015 AND `item`=199752 AND `ExtendedCost`=7766 AND `type`=1) OR (`entry`=193015 AND `item`=199753 AND `ExtendedCost`=7764 AND `type`=1) OR (`entry`=193015 AND `item`=199755 AND `ExtendedCost`=7767 AND `type`=1) OR (`entry`=193015 AND `item`=199754 AND `ExtendedCost`=7763 AND `type`=1) OR (`entry`=193015 AND `item`=199756 AND `ExtendedCost`=7765 AND `type`=1) OR (`entry`=193015 AND `item`=199647 AND `ExtendedCost`=7712 AND `type`=1) OR (`entry`=193015 AND `item`=199651 AND `ExtendedCost`=7712 AND `type`=1) OR (`entry`=193015 AND `item`=199652 AND `ExtendedCost`=7712 AND `type`=1) OR (`entry`=193015 AND `item`=200754 AND `ExtendedCost`=7709 AND `type`=1) OR (`entry`=193015 AND `item`=200752 AND `ExtendedCost`=7710 AND `type`=1) OR (`entry`=193015 AND `item`=200753 AND `ExtendedCost`=7717 AND `type`=1) OR (`entry`=193015 AND `item`=200751 AND `ExtendedCost`=7714 AND `type`=1) OR (`entry`=193015 AND `item`=200750 AND `ExtendedCost`=7713 AND `type`=1) OR (`entry`=193015 AND `item`=199648 AND `ExtendedCost`=7713 AND `type`=1) OR (`entry`=193015 AND `item`=194282 AND `ExtendedCost`=7374 AND `type`=1) OR (`entry`=193015 AND `item`=198912 AND `ExtendedCost`=7374 AND `type`=1) OR (`entry`=193015 AND `item`=194287 AND `ExtendedCost`=7374 AND `type`=1) OR (`entry`=193015 AND `item`=198941 AND `ExtendedCost`=7366 AND `type`=1) OR (`entry`=193015 AND `item`=194292 AND `ExtendedCost`=7372 AND `type`=1) OR (`entry`=193015 AND `item`=194290 AND `ExtendedCost`=7372 AND `type`=1) OR (`entry`=193015 AND `item`=194288 AND `ExtendedCost`=7372 AND `type`=1) OR (`entry`=193015 AND `item`=199244 AND `ExtendedCost`=7372 AND `type`=1) OR (`entry`=193015 AND `item`=199245 AND `ExtendedCost`=7372 AND `type`=1) OR (`entry`=193015 AND `item`=194495 AND `ExtendedCost`=7372 AND `type`=1) OR (`entry`=193015 AND `item`=194498 AND `ExtendedCost`=7372 AND `type`=1) OR (`entry`=193015 AND `item`=194500 AND `ExtendedCost`=7372 AND `type`=1) OR (`entry`=193015 AND `item`=198892 AND `ExtendedCost`=7356 AND `type`=1) OR (`entry`=193015 AND `item`=194279 AND `ExtendedCost`=7369 AND `type`=1) OR (`entry`=193015 AND `item`=194280 AND `ExtendedCost`=7369 AND `type`=1) OR (`entry`=193015 AND `item`=194479 AND `ExtendedCost`=7369 AND `type`=1) OR (`entry`=193015 AND `item`=194482 AND `ExtendedCost`=7369 AND `type`=1) OR (`entry`=193015 AND `item`=191545 AND `ExtendedCost`=7369 AND `type`=1) OR (`entry`=193015 AND `item`=199246 AND `ExtendedCost`=7358 AND `type`=1) OR (`entry`=193015 AND `item`=199817 AND `ExtendedCost`=7358 AND `type`=1) OR (`entry`=193015 AND `item`=199818 AND `ExtendedCost`=7358 AND `type`=1) OR (`entry`=193015 AND `item`=199767 AND `ExtendedCost`=7728 AND `type`=1) OR (`entry`=193015 AND `item`=199768 AND `ExtendedCost`=7724 AND `type`=1) OR (`entry`=193015 AND `item`=199769 AND `ExtendedCost`=7725 AND `type`=1) OR (`entry`=193015 AND `item`=199770 AND `ExtendedCost`=7726 AND `type`=1) OR (`entry`=193015 AND `item`=199771 AND `ExtendedCost`=7727 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(193015, 120, 199763, 0, 7364, 1, 100727, 0, 48317), -- Expedition Researcher's Hood
(193015, 119, 199764, 0, 7364, 1, 100727, 0, 48317), -- Expedition Mercenary's Helm
(193015, 118, 199765, 0, 7364, 1, 100727, 0, 48317), -- Field Scout's Helmet
(193015, 117, 199766, 0, 7364, 1, 100727, 0, 48317), -- Expedition Guard's Helm
(193015, 116, 199736, 0, 7776, 1, 100769, 0, 48317), -- Amber Dragonflame Blade
(193015, 115, 199738, 0, 7791, 1, 100769, 0, 48317), -- Ruby Dragonflame Blade
(193015, 114, 199739, 0, 7781, 1, 100769, 0, 48317), -- Emerald Dragonflame Blade
(193015, 113, 200456, 0, 7779, 1, 100769, 0, 48317), -- Valdrakken Armor Opener
(193015, 112, 201795, 0, 7801, 1, 100769, 0, 48317), -- Valdrakken Guard's Claw
(193015, 111, 201796, 0, 7801, 1, 100769, 0, 48317), -- Valdrakken Drakonid's Claw
(193015, 110, 199820, 0, 7779, 1, 100769, 0, 48317), -- Valdrakken Guard's Skullsplitter
(193015, 109, 199821, 0, 7779, 1, 100769, 0, 48317), -- Valdrakken Serrated Shortsword
(193015, 108, 199823, 0, 7802, 1, 100769, 0, 48317), -- Valdrakken Gatekeeper's Polearm
(193015, 107, 199825, 0, 7801, 1, 100769, 0, 48317), -- Valdrakken Belt Knife
(193015, 106, 199700, 0, 7787, 1, 100769, 0, 48317), -- Valdrakken Bladewing Decapitator
(193015, 105, 199707, 0, 7801, 1, 100769, 0, 48317), -- Valdrakken Wingguard Polearm
(193015, 104, 199806, 0, 7801, 1, 100769, 0, 48317), -- Valdrakken Drakeclaw Barrier
(193015, 103, 199702, 0, 7787, 1, 100769, 0, 48317), -- Valdrakken Guard's Barrier
(193015, 102, 199705, 0, 7800, 1, 100769, 0, 48317), -- Valdrakken Guard's Spear
(193015, 101, 199726, 0, 7801, 1, 100769, 0, 48317), -- Valdrakken Spellweaver's Scepter
(193015, 100, 199728, 0, 7801, 1, 100769, 0, 48317), -- Valdrakken Spellweaver's Stave
(193015, 99, 199730, 0, 7801, 1, 100769, 0, 48317), -- Valdrakken Bladewing Staff
(193015, 98, 199732, 0, 7801, 1, 100769, 0, 48317), -- Valdrakken Wing Glaive
(193015, 97, 199734, 0, 7803, 1, 100769, 0, 48317), -- Valdrakken Guard's Cutlass
(193015, 96, 199670, 0, 7745, 1, 100768, 0, 48317), -- Black Drakonid Shoulderplates
(193015, 95, 199671, 0, 7743, 1, 100768, 0, 48317), -- Cobalt Drakonid Shoulderplates
(193015, 94, 199672, 0, 7742, 1, 100768, 0, 48317), -- Bronze Drakonid Shoulderplates
(193015, 93, 199673, 0, 7741, 1, 100768, 0, 48317), -- Verdant Drakonid Shoulderplates
(193015, 92, 199674, 0, 7744, 1, 100768, 0, 48317), -- Crimson Drakonid Shoulderplates
(193015, 91, 199660, 0, 7745, 1, 100768, 0, 48317), -- Obsidian Jeweled Shoulderpads
(193015, 90, 199661, 0, 7743, 1, 100768, 0, 48317), -- Azure Jeweled Shoulderpads
(193015, 89, 199662, 0, 7742, 1, 100768, 0, 48317), -- Amber Jeweled Shoulderpads
(193015, 88, 199663, 0, 7741, 1, 100768, 0, 48317), -- Emerald Jeweled Shoulderpads
(193015, 87, 199664, 0, 7744, 1, 100768, 0, 48317), -- Ruby Jeweled Shoulderpads
(193015, 86, 196962, 0, 7814, 1, 100766, 0, 48317), -- Cliffside Wylderdrake: Silver and Purple Armor
(193015, 85, 197093, 0, 7814, 1, 100766, 0, 48317), -- Highland Drake: Silver and Purple Armor
(193015, 84, 197350, 0, 7814, 1, 100766, 0, 48317), -- Renewed Proto-Drake: Silver and Purple Armor
(193015, 83, 197581, 0, 7814, 1, 100766, 0, 48317), -- Windborne Velocidrake: Silver and Purple Armor
(193015, 82, 194320, 0, 7789, 1, 100765, 0, 48317), -- Reinforced Lavender Bottle
(193015, 81, 198388, 0, 7788, 1, 100765, 0, 48317), -- Swirling Draconian Concoction
(193015, 80, 198389, 0, 7798, 1, 100765, 0, 48317), -- Weighted Potion Cylinder
(193015, 79, 199741, 0, 7788, 1, 100765, 0, 48317), -- Compendium of Advanced Spells
(193015, 78, 199742, 0, 7788, 1, 100765, 0, 48317), -- A Mender's Mentality
(193015, 77, 199743, 0, 7778, 1, 100765, 0, 48317), -- Runic Symbols and their Meaning
(193015, 76, 199744, 0, 7798, 1, 100765, 0, 48317), -- Academy Student's Journal
(193015, 75, 199745, 0, 7782, 1, 100765, 0, 48317), -- Everflame Night Torch
(193015, 74, 197145, 0, 7752, 1, 100761, 0, 48317), -- Highland Drake: Bronze Scales
(193015, 73, 197391, 0, 7752, 1, 100761, 0, 48317), -- Renewed Proto-Drake: Bronze Scales
(193015, 72, 197613, 0, 7752, 1, 100761, 0, 48317), -- Windborne Velocidrake: Bronze Scales
(193015, 71, 199772, 0, 7799, 1, 0, 0, 48317), -- Titan Gatekeeper's Shield
(193015, 70, 199773, 0, 7794, 1, 0, 0, 48317), -- Titan Watcher's Scepter
(193015, 69, 199774, 0, 7799, 1, 0, 0, 48317), -- Ancient Titan Blunderbuss
(193015, 68, 199775, 0, 7799, 1, 0, 0, 48317), -- Titan Keeper's Gladius
(193015, 67, 199776, 0, 7793, 1, 0, 0, 48317), -- Titan Watcher's Broadsword
(193015, 66, 199757, 0, 7721, 1, 100758, 0, 48317), -- Magic Nibbler
(193015, 65, 199758, 0, 7721, 1, 100758, 0, 48317), -- Crimson Proto-Whelp
(193015, 64, 199680, 0, 7730, 1, 100757, 0, 48317), -- Obsidian Drakonid Helmet
(193015, 63, 199681, 0, 7730, 1, 100757, 0, 48317), -- Cobalt Drakonid Helmet
(193015, 62, 199682, 0, 7730, 1, 100757, 0, 48317), -- Bronze Drakonid Helmet
(193015, 61, 199683, 0, 7730, 1, 100757, 0, 48317), -- Verdant Drakonid Helmet
(193015, 60, 199684, 0, 7730, 1, 100757, 0, 48317), -- Crimson Drakonid Helmet
(193015, 59, 199759, 0, 7364, 1, 100721, 0, 48317), -- Valdrakken Plate Girdle
(193015, 58, 199760, 0, 7364, 1, 100721, 0, 48317), -- Valdrakken Spellweaver's Cord
(193015, 57, 199761, 0, 7364, 1, 100721, 0, 48317), -- Valdrakken Dragonspawn Waistguard
(193015, 56, 199762, 0, 7364, 1, 100721, 0, 48317), -- Valdrakken Guards Belt
(193015, 51, 199752, 0, 7766, 1, 100760, 0, 48317), -- Ensemble: Crimson Valdrakken Clothing
(193015, 50, 199753, 0, 7764, 1, 100760, 0, 48317), -- Ensemble: Black Valdrakken Clothing
(193015, 49, 199755, 0, 7767, 1, 100760, 0, 48317), -- Ensemble: Green Valdrakken Clothing
(193015, 48, 199754, 0, 7763, 1, 100760, 0, 48317), -- Ensemble: Azure Valdrakken Clothing
(193015, 47, 199756, 0, 7765, 1, 100760, 0, 48317), -- Ensemble: Bronze Valdrakken Clothing
(193015, 38, 199647, 0, 7712, 1, 0, 0, 48317), -- Dragon Garden Fork
(193015, 37, 199651, 0, 7712, 1, 0, 0, 48317), -- Dragon Garden Hoe
(193015, 36, 199652, 0, 7712, 1, 0, 0, 48317), -- Dragon Garden Rake
(193015, 32, 200754, 0, 7709, 1, 0, 0, 48317), -- Jeweled Gold Dragon Goblet
(193015, 31, 200752, 0, 7710, 1, 0, 0, 48317), -- Jeweled Silver Dragon Goblet
(193015, 30, 200753, 0, 7717, 1, 0, 0, 48317), -- Simple Gold Dragon Goblet
(193015, 29, 200751, 0, 7714, 1, 0, 0, 48317), -- Simple Silver Dragon Goblet
(193015, 28, 200750, 0, 7713, 1, 0, 0, 48317), -- Dragon Dinner Knife
(193015, 27, 199648, 0, 7713, 1, 0, 0, 48317), -- Dragon Dinner Fork
(193015, 26, 194282, 0, 7374, 1, 100733, 0, 48317), -- Pattern: Cushion of Time Travel
(193015, 25, 198912, 0, 7374, 1, 100733, 0, 48317), -- Technique: Illusion Parchment: Whirling Breeze
(193015, 24, 194287, 0, 7374, 1, 100728, 0, 48317), -- Pattern: Chronocloth Reagent Bag
(193015, 23, 198941, 0, 7366, 1, 100728, 0, 48317), -- Technique: Contract: Valdrakken Accord
(193015, 22, 194292, 0, 7372, 1, 100724, 0, 48317), -- Pattern: Master's Wildercloth Gardening Hat
(193015, 21, 194290, 0, 7372, 1, 100724, 0, 48317), -- Pattern: Master's Wildercloth Enchanter's Hat
(193015, 20, 194288, 0, 7372, 1, 100724, 0, 48317), -- Pattern: Master's Wildercloth Alchemist's Robe
(193015, 19, 199244, 0, 7372, 1, 100724, 0, 48317), -- Schematic: Khaz'gorite Delver's Helmet
(193015, 18, 199245, 0, 7372, 1, 100724, 0, 48317), -- Schematic: Lapidary's Khaz'gorite Clamps
(193015, 17, 194495, 0, 7372, 1, 100724, 0, 48317), -- Plans: Khaz'gorite Sickle
(193015, 16, 194498, 0, 7372, 1, 100724, 0, 48317), -- Plans: Khaz'gorite Needle Set
(193015, 15, 194500, 0, 7372, 1, 100724, 0, 48317), -- Plans: Khaz'gorite Leatherworker's Toolset
(193015, 14, 198892, 0, 7356, 1, 100720, 0, 48317), -- Technique: Cliffside Wylderdrake: Red Hair
(193015, 13, 194279, 0, 7369, 1, 100719, 0, 48317), -- Pattern: Azureweave Slippers
(193015, 12, 194280, 0, 7369, 1, 100719, 0, 48317), -- Pattern: Chronocloth Sash
(193015, 11, 194479, 0, 7369, 1, 100719, 0, 48317), -- Plans: Obsidian Seared Claymore
(193015, 10, 194482, 0, 7369, 1, 100719, 0, 48317), -- Plans: Obsidian Seared Invoker
(193015, 9, 191545, 0, 7369, 1, 100719, 0, 48317), -- Recipe: Sustaining Alchemist's Stone
(193015, 8, 199246, 0, 7358, 1, 100716, 0, 48317), -- Schematic: Tinker: Grounded Circuitry
(193015, 7, 199817, 0, 7358, 1, 100716, 0, 48317), -- Formula: Enchant Cloak - Homebound Speed
(193015, 6, 199818, 0, 7358, 1, 100716, 0, 48317), -- Formula: Enchant Boots - Watcher's Loam
(193015, 5, 199767, 0, 7728, 1, 100767, 0, 48317), -- Red Dragon Banner
(193015, 4, 199768, 0, 7724, 1, 100767, 0, 48317), -- Black Dragon Banner
(193015, 3, 199769, 0, 7725, 1, 100767, 0, 48317), -- Blue Dragon Banner
(193015, 2, 199770, 0, 7726, 1, 100767, 0, 48317), -- Bronze Dragon Banner
(193015, 1, 199771, 0, 7727, 1, 100767, 0, 48317); -- Green Dragon Banner
