SET @CGUID := 2990006;
SET @NPCTEXTID := 530007;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 32780, 1, 15, 511, '0', '0', 0, 0, 0, -4746.63720703125, -3658.2431640625, 47.377960205078125, 1.074822545051574707, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 57564), -- Invisible Stalker (All Phases) (Area: Wyrmbog - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+1, 205890, 1, 15, 511, '0', '0', 0, 0, 0, -4746.63720703125, -3658.2431640625, 49.29133224487304687, 1.074822545051574707, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 57564); -- Zidormi (Area: Wyrmbog - Difficulty: 0) CreateObject1

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+1, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Zidormi

DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=205890 AND `MenuID`=31667);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(205890, 31667, 57564); -- Zidormi

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+0;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 1, 0, 0, 0, 0, 0, 0, 242822, 242815, 0, 0, 0, 0, 0, 0, 57564); -- 205890 (Zidormi)

DELETE FROM `gossip_menu` WHERE (`MenuID`=31667 AND `TextID`=@NPCTEXTID+0);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(31667, @NPCTEXTID+0, 57564); -- 205890 (Zidormi)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=31667 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(31667, 109857, 0, 0, 'Yes.', 33525, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, 412671, NULL, 57564); -- OptionBroadcastTextID: 33525 - 35395 - 39547 - 61999 - 62000 - 69412

UPDATE `creature_template_difficulty` SET `MinLevel`=80, `MaxLevel`=80, `StaticFlags1`=0x20000000, `VerifiedBuild`=57564 WHERE `Entry`=205890; -- 205890 (Zidormi) - Floating
DELETE FROM `creature_template_movement` WHERE `CreatureId`= 205890;
INSERT INTO `creature_template_movement` (`CreatureId`, `HoverInitiallyEnabled`) VALUES
(205890, 1);

UPDATE `creature_template` SET `npcflag`= 0x1 WHERE `entry`= 205890;

 -- Invisible Stalker (All Phases) smart ai
SET @ENTRY := 32780;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 0, 11, 50236, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On respawn - Self: Cast spell  50236 on Self', '');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 32780 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, 32780, 0, 0, 58, 1, 0, 0, 0, 'OnyxiasLairZidormiSpotlight', 0, 'Object has StringID OnyxiasLairZidormiSpotlight');

UPDATE `creature` SET `StringId`= 'OnyxiasLairZidormiSpotlight' WHERE `guid`= @CGUID+0;
