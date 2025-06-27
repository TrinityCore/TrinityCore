--
UPDATE `spell_dbc` SET `ProcChance`=101, `Effect1`=6, `Effect2`=6, `Effect3`=6, `EffectImplicitTargetA1`=25, `EffectImplicitTargetA2`=25, `EffectImplicitTargetA3`=25, `EffectApplyAuraName1`=56, `EffectApplyAuraName2`=67, `EffectApplyAuraName3`=23, `EffectAmplitude3`=5000, `EffectMiscValue1`=15214, `DmgMultiplier1`=1, `DmgMultiplier2`=1, `DmgMultiplier3`=1 WHERE `Id`=42825;
DELETE  FROM `spell_target_position` WHERE `ID` IN (24831, 42826, 24730);
INSERT INTO `spell_target_position` (`ID`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`) VALUES
(24831, 0, -9569.6, -13.7809, 69.7455, 4.85433),
(42826, 530, -1742.25, 5457.4, -6.28635, 4.60653),
(24730, 1, -1327.66, 85.9815, 134.169, 3.42905);

UPDATE `gameobject_template_addon` SET `faction`=35 WHERE `entry` IN (180515,180452,186560);
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry` IN (180515, 180452,186560);
DELETE FROM  `smart_scripts` WHERE `entryorguid` IN (180515, 180452,186560) AND source_type=1;
DELETE FROM  `smart_scripts` WHERE `entryorguid` IN (18051500, 18045200,18656000) AND source_type=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(180515,1,0,0,64,0,100,0,1,0,0,0,80,18051500,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blastenheimer 5000 Ultra Cannon - On gossip hello  - action list"),
(18051500,9,0,0,0,0,100,0,0,0,0,0,105,16,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blastenheimer 5000 Ultra Cannon - action list  - Add not selectable flag"),
(18051500,9,1,0,0,0,100,0,0,0,0,0,11,24754,0,0,0,0,0,7,0,0,0,0,0,0,0,"Blastenheimer 5000 Ultra Cannon - action list  - Cast freez"),
(18051500,9,2,0,0,0,100,0,500,500,0,0,11,24831,0,0,0,0,0,7,0,0,0,0,0,0,0,"Blastenheimer 5000 Ultra Cannon - action list  - Cast teleport"),
(18051500,9,3,0,0,0,100,0,2500,2500,0,0,93,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blastenheimer 5000 Ultra Cannon - action list  - Anim Progress"),
(18051500,9,4,0,0,0,100,0,2000,2000,0,0,28,24754,0,0,0,0,0,7,0,0,0,0,0,0,0,"Blastenheimer 5000 Ultra Cannon - action list  - Remove aura"),
(18051500,9,5,0,0,0,100,0,0,0,0,0,86,24742,0,19,15218,0,0,7,0,0,0,0,0,0,0,"Blastenheimer 5000 Ultra Cannon - action list  - cast Magic Wings"),
(18051500,9,6,0,0,0,100,0,2000,2000,0,0,106,16,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blastenheimer 5000 Ultra Cannon - action list  - Remove not selectable flag"),
(180452,1,0,0,64,0,100,0,1,0,0,0,80,18045200,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blastenheimer 5000 Ultra Cannon - On gossip hello  - action list"),
(18045200,9,0,0,0,0,100,0,0,0,0,0,105,16,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blastenheimer 5000 Ultra Cannon - action list  - Add not selectable flag"),
(18045200,9,1,0,0,0,100,0,0,0,0,0,11,24754,0,0,0,0,0,7,0,0,0,0,0,0,0,"Blastenheimer 5000 Ultra Cannon - action list  - Cast freez"),
(18045200,9,2,0,0,0,100,0,500,500,0,0,11,24730,0,0,0,0,0,7,0,0,0,0,0,0,0,"Blastenheimer 5000 Ultra Cannon - action list  - Cast teleport"),
(18045200,9,3,0,0,0,100,0,2500,2500,0,0,93,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blastenheimer 5000 Ultra Cannon - action list  - Anim Progress"),
(18045200,9,4,0,0,0,100,0,2000,2000,0,0,28,24754,0,0,0,0,0,7,0,0,0,0,0,0,0,"Blastenheimer 5000 Ultra Cannon - action list  - Remove aura"),
(18045200,9,5,0,0,0,100,0,0,0,0,0,86,24742,0,19,15218,0,0,7,0,0,0,0,0,0,0,"Blastenheimer 5000 Ultra Cannon - action list  - cast Magic Wings"),
(18045200,9,6,0,0,0,100,0,2000,2000,0,0,106,16,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blastenheimer 5000 Ultra Cannon - action list  - Remove not selectable flag"),
(186560,1,0,0,64,0,100,0,1,0,0,0,80,18656000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blastenheimer 5000 Ultra Cannon - On gossip hello  - action list"),
(18656000,9,0,0,0,0,100,0,0,0,0,0,105,16,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blastenheimer 5000 Ultra Cannon - action list  - Add not selectable flag"),
(18656000,9,1,0,0,0,100,0,0,0,0,0,11,24754,0,0,0,0,0,7,0,0,0,0,0,0,0,"Blastenheimer 5000 Ultra Cannon - action list  - Cast freez"),
(18656000,9,2,0,0,0,100,0,500,500,0,0,11,42826,0,0,0,0,0,7,0,0,0,0,0,0,0,"Blastenheimer 5000 Ultra Cannon - action list  - Cast teleport"),
(18656000,9,3,0,0,0,100,0,2500,2500,0,0,93,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blastenheimer 5000 Ultra Cannon - action list  - Anim Progress"),
(18656000,9,4,0,0,0,100,0,2000,2000,0,0,28,24754,0,0,0,0,0,7,0,0,0,0,0,0,0,"Blastenheimer 5000 Ultra Cannon - action list  - Remove aura"),
(18656000,9,5,0,0,0,100,0,0,0,0,0,86,42867,0,19,15218,0,0,7,0,0,0,0,0,0,0,"Blastenheimer 5000 Ultra Cannon - action list  - cast Magic Wings"),
(18656000,9,6,0,0,0,100,0,2000,2000,0,0,106,16,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blastenheimer 5000 Ultra Cannon - action list  - Remove not selectable flag");

UPDATE `gameobject` SET `position_x`= -9569.683, `position_y`=-13.00521, `position_z`=63.47144, `orientation`=-1.361356, `rotation2`=-0.6293201, `rotation3`=0.7771462 WHERE `id`=180515;
UPDATE `creature` SET `position_x`= -9568.316, `position_y`= -7.846191, `position_z`= 63.09657, `orientation`= 1.797689 WHERE `guid`=52415;
UPDATE `gameobject` SET `position_x`= -9566.781, `position_y`= -2.013184, `position_z`=61.75726, `orientation`=-1.34390, `rotation2`=-0.62251, `rotation3`=0.7826088 WHERE `guid`=12633;
UPDATE `gameobject` SET `position_x`= -9572.567, `position_y`= -13.68077, `position_z`=63.43542, `orientation`=1.675514, `rotation2`=0.743144, `rotation3`=0.6691315 WHERE `guid`=12607;
UPDATE `gameobject` SET `position_x`= -9566.685, `position_y`= -12.59956, `position_z`=63.26569, `orientation`=1.850049, `rotation2`=0.798635, `rotation3`=0.6018150 WHERE `guid`=12621;

DELETE FROM `creature` WHERE `guid` IN (111084,111094);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(111084, 15218, 0, 0, 0, 1, 1, 0, 0, -9570.283, -9.950684, 63.51959, 6.126106, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 12340), 
(111094, 15218, 530, 0, 0, 1, 1, 0, 0, -1742.180, 5457.9300, -12.3448, 1.413720, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 12340);
