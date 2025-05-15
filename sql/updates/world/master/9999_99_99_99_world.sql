# move script from alex to boulder
UPDATE `creature_template` SET `ScriptName`='npc_redridge_huge_boulder' WHERE `entry` = 43196; -- Huge Boulder
UPDATE `creature_template` SET `ScriptName`='' WHERE `entry` = 653; -- Bridge Worker Alex

UPDATE `creature_template` SET `unit_flags2`=0x800 WHERE `entry`=43094; -- Canyon Ettin
UPDATE `creature_template` SET `faction`=35, `unit_flags`=0x40, `VehicleId`=938, `ScriptName`='npc_redridge_subdued_canyon_ettin' WHERE `entry`=43197; -- Subdued Canyon Ettin
UPDATE `creature_template` SET `unit_flags3`=0x1000000 WHERE `entry`=43196; -- Huge Boulder

DELETE FROM `creature_template_addon` WHERE `entry` IN (43197 /*43197 (Subdued Canyon Ettin) - Detect: Quest Invis Zone 1*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(43197, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '81299'); -- 43197 (Subdued Canyon Ettin) - Detect: Quest Invis Zone 1

UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x0, `VerifiedBuild`=60822 WHERE (`Entry`=341 AND `DifficultyID`=0); -- 341 (Foreman Oslow) -
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x0, `VerifiedBuild`=60822 WHERE (`Entry`=648 AND `DifficultyID`=0); -- 648 (Bridge Worker Trent) -
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x0, `VerifiedBuild`=60822 WHERE (`Entry`=649 AND `DifficultyID`=0); -- 649 (Bridge Worker Dmitri) -
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x0, `VerifiedBuild`=60822 WHERE (`Entry`=650 AND `DifficultyID`=0); -- 650 (Bridge Worker Jess) -
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x0, `VerifiedBuild`=60822 WHERE (`Entry`=651 AND `DifficultyID`=0); -- 651 (Bridge Worker Daniel) -
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x0, `VerifiedBuild`=60822 WHERE (`Entry`=652 AND `DifficultyID`=0); -- 652 (Bridge Worker Matthew) -
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x0, `VerifiedBuild`=60822 WHERE (`Entry`=653 AND `DifficultyID`=0); -- 653 (Bridge Worker Alex) -
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x0, `VerifiedBuild`=60822 WHERE (`Entry`=43094 AND `DifficultyID`=0); -- 43094 (Canyon Ettin) -
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x0, `VerifiedBuild`=60822 WHERE (`Entry`=43197 AND `DifficultyID`=0); -- 43197 (Subdued Canyon Ettin) -

DELETE FROM `spell_script_names` WHERE `spell_id` IN (80704, 80702, 80739, 80707);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(80704, 'spell_redridge_control_ettin'),
(80702, 'spell_redridge_control_ettin_2'),
(80739, 'spell_redridge_lift_huge_boulder'),
(80707, 'spell_gen_despawn_target');

# exit location for thrown boulder
DELETE FROM `vehicle_seat_addon` WHERE `SeatEntry` = 8161;
INSERT INTO `vehicle_seat_addon` (`SeatEntry`, `SeatOrientation`, `ExitParamX`, `ExitParamY`, `ExitParamZ`, `ExitParamO`, `ExitParamValue`) VALUES
(8161, 0, -9310.855, -2366.367, 67.17842, 0, 2);

DELETE FROM `creature_text` WHERE `CreatureID` = 43197;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(43197, 0, 0, 'ROCK NOT SO HEAVY! PUNY HUMIES!', 12, 0, 100, 0, 0, 0, 43218, 0, 'Subdued Canyon Ettin to Huge Boulder'),
(43197, 1, 0, 'Where trow? TROW ON BRIDGE??', 12, 0, 100, 0, 0, 0, 43220, 0, 'Subdued Canyon Ettin to Huge Boulder'),
(43197, 2, 0, 'OK! Me trow in water!', 12, 0, 100, 0, 0, 0, 43222, 0, 'Subdued Canyon Ettin to Huge Boulder'),
(43197, 3, 0, 'BYE, BYE, DADDY!', 14, 0, 100, 0, 0, 0, 43226, 0, 'Subdued Canyon Ettin to Huge Boulder');
