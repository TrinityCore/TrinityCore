SET @CGUID := 10005843;
SET @OGUID := 10001485;

SET @NPCTEXTID := 600093;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+7;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 236058, 2127, 10416, 15535, '0', 0, 0, 0, 0, 1976.6788330078125, 24.13368034362792968, 40.43767166137695312, 5.0189056396484375, 120, 0, 0, 0, 0, NULL, NULL, NULL, 58867), -- Watcher Du'una (Area: Flotsam Shoal - Difficulty: 0) CreateObject1
(@CGUID+1, 236055, 2127, 10416, 15535, '0', 0, 0, 0, 0, 1973.0103759765625, 22.65625, 39.8443450927734375, 1.453652381896972656, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58867), -- Chief Officer Hammerflange (Area: Flotsam Shoal - Difficulty: 0) CreateObject1
(@CGUID+2, 231541, 2127, 10416, 15535, '0', 0, 0, 0, 0, 1969.185791015625, 4.791666507720947265, 38.74623870849609375, 0.233228996396064758, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58867), -- Sky-Captain Cableclamp (Area: Flotsam Shoal - Difficulty: 0) CreateObject1
(@CGUID+3, 236060, 2127, 10416, 15535, '0', 0, 0, 0, 1, 1965.3367919921875, 19.36111068725585937, 39.92839813232421875, 3.113439798355102539, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58867), -- Crewman Cutpipe (Area: Flotsam Shoal - Difficulty: 0) CreateObject1
(@CGUID+4, 231538, 2127, 10416, 15535, '0', 0, 0, 0, 0, 1968.439208984375, 0.710069477558135986, 40.02445220947265625, 3.736377477645874023, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58867), -- Fergus Gearchum (Area: Flotsam Shoal - Difficulty: 0) CreateObject1
(@CGUID+5, 236061, 2127, 10416, 15535, '0', 0, 0, 0, 1, 1985.1163330078125, -2.64236116409301757, 41.58314895629882812, 5.41950082778930664, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58867), -- Crewman Spinshaft (Area: Flotsam Shoal - Difficulty: 0) CreateObject1
(@CGUID+6, 236056, 2127, 10416, 15535, '0', 0, 0, 0, 0, 1970.685791015625, 0.592013895511627197, 39.2296600341796875, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58867), -- Navigator Hatch (Area: Flotsam Shoal - Difficulty: 0) CreateObject1
(@CGUID+7, 236059, 2127, 10416, 15535, '0', 0, 0, 0, 1, 1981.6944580078125, -13.8628473281860351, 42.85834503173828125, 2.438271999359130859, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58867); -- Crewman Boltshine (Area: Flotsam Shoal - Difficulty: 0) CreateObject1
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+7;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 0, 14533, 0, 0, 0, ''), -- Watcher Du'una
(@CGUID+1, 0, 0, 0, 0, 0, 1, 0, 875, 0, 0, 0, 0, ''), -- Chief Officer Hammerflange
(@CGUID+3, 0, 0, 0, 0, 0, 1, 0, 875, 0, 0, 0, 0, ''), -- Crewman Cutpipe
(@CGUID+4, 0, 0, 0, 0, 0, 1, 0, 0, 24607, 0, 0, 0, ''), -- Fergus Gearchum
(@CGUID+7, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 0, ''); -- Crewman Boltshine

UPDATE `creature` SET `StringId` = 'SirenIsle' WHERE `guid` = @CGUID+2;

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+1;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 475937, 2127, 10416, 15535, '0', 0, 0, 1967.4478759765625, 5.63368082046508789, 56.5910797119140625, 1.963491797447204589, 0, 0, 0.831468582153320312, 0.555571734905242919, 120, 255, 1, 58867), -- Zeppelin (Area: Flotsam Shoal - Difficulty: 0) CreateObject1
(@OGUID+1, 505475, 2127, 10416, 15535, '0', 0, 0, 2012.1805419921875, 20.39756965637207031, -0.08512230217456817, 1.957344532012939453, 0.212971210479736328, 0.375732421875, 0.739471435546875, 0.51638197898864746, 120, 255, 1, 58867); -- Zeppelin Rope (Area: Flotsam Shoal - Difficulty: 0) CreateObject1

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+1;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+1, 0, 0, 0, 1, 14604, 0); -- Zeppelin Rope

-- Template Addon
DELETE FROM `gameobject_template_addon` WHERE `entry` IN (505475, 475937);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(505475, 0, 0x40000, 14604, 0), -- Zeppelin Rope
(475937, 0, 0x100020, 0, 0); -- Zeppelin

-- Template
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=236060; -- Crewman Cutpipe
UPDATE `creature_template` SET `faction`=35, `npcflag`=281474976710657, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x40000000 WHERE `entry`=231538; -- Fergus Gearchum
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=236061; -- Crewman Spinshaft
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=236056; -- Navigator Hatch
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=236059; -- Crewman Boltshine

-- Difficulty
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `StaticFlags3`=0x2000000, `VerifiedBuild`=58867 WHERE (`Entry`=236058 AND `DifficultyID`=0); -- 236058 (Watcher Du'una) - CanSwim - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3004, `StaticFlags1`=0x10000000, `VerifiedBuild`=58867 WHERE (`Entry`=236060 AND `DifficultyID`=0); -- 236060 (Crewman Cutpipe) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3004, `StaticFlags1`=0x30000100, `VerifiedBuild`=58867 WHERE (`Entry`=231538 AND `DifficultyID`=0); -- 231538 (Fergus Gearchum) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3004, `StaticFlags1`=0x10000000, `VerifiedBuild`=58867 WHERE (`Entry`=236061 AND `DifficultyID`=0); -- 236061 (Crewman Spinshaft) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3004, `StaticFlags1`=0x10000000, `VerifiedBuild`=58867 WHERE (`Entry`=236056 AND `DifficultyID`=0); -- 236056 (Navigator Hatch) - CanSwim

-- Spelltarget
DELETE FROM `spell_target_position` WHERE (`ID`=470798 AND `EffectIndex`=0 AND `OrderIndex`=0) OR (`ID`=470860 AND `EffectIndex`=0 AND `OrderIndex`=0);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `OrderIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(470798, 0, 0, 2552, 3225.10009765625, -3053.22998046875, 341.269989013671875, 58867), -- Spell: 470798 ([DNT] Teleport) Effect 0: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(470860, 0, 0, 2127, 1970.1700439453125, 19.70000076293945312, 39.68999862670898437, 58867); -- Spell: 470860 ([DNT] Teleport) Effect 0: 252 (SPELL_EFFECT_TELEPORT_UNITS)

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=231538 AND `MenuID`=37715) OR (`CreatureID`=231541 AND `MenuID`=37170);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(231538, 37715, 58867), -- Fergus Gearchum
(231541, 37170, 58867); -- Sky-Captain Cableclamp

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+2;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 279726, 0, 0, 0, 0, 0, 0, 0, 58867), -- 231538 (Fergus Gearchum)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 279722, 0, 0, 0, 0, 0, 0, 0, 58867), -- 231538 (Fergus Gearchum)
(@NPCTEXTID+2, 1, 0, 0, 0, 0, 0, 0, 0, 276953, 0, 0, 0, 0, 0, 0, 0, 58867); -- 231541 (Sky-Captain Cableclamp)

DELETE FROM `gossip_menu` WHERE (`MenuID`=37740 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=37715 AND `TextID`=@NPCTEXTID+1) OR (`MenuID`=37170 AND `TextID`=@NPCTEXTID+2);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(37740, @NPCTEXTID+0, 58867), -- 231538 (Fergus Gearchum)
(37715, @NPCTEXTID+1, 58867), -- 231538 (Fergus Gearchum)
(37170, @NPCTEXTID+2, 58867); -- 231541 (Sky-Captain Cableclamp)

DELETE FROM `gossip_menu_option` WHERE (`OptionID`=1 AND `MenuID`=37170) OR (`OptionID`=0 AND `MenuID` IN (37170,37715,37716));
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(37170, 131547, 1, 0, 'What do you know about the Siren Isle?', 0, 0, 0, 37716, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 58867),
(37170, 125349, 0, 0, 'Take me back to the Dornogal.', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 58867),
(37715, 131549, 0, 0, 'What do you know about the Siren Isle?', 0, 0, 0, 37740, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 58867),
(37716, 131548, 0, 0, 'I want to talk about something else.', 0, 0, 0, 37170, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 58867);

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 14) AND (`SourceGroup` IN (37170));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(14, 37170, 0, 0, 0, 58, 1, 0, 0, 0, 'SirenIsle', 0, 'WorldObject providing gossip has StringID SirenIsle');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 14) AND (`SourceGroup` IN (37173));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(14, 37173, 0, 0, 0, 58, 1, 0, 0, 0, 'SirenIsle', 1, 'WorldObject providing gossip has not StringID SirenIsle');

-- Sky-Captain Cableclamp smart ai
SET @ENTRY := 231541;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 62, 0, 100, 0, 37170, 0, 0, 0, 0, 85, 470798, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 37170 selected - Gossip player: Cast spell 470798 on self', ''),
(@ENTRY, 0, 1, 0, 62, 0, 100, 0, 37173, 0, 0, 0, 0, 85, 470860, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 37173 selected - Gossip player: Cast spell 470860 on self', '');
