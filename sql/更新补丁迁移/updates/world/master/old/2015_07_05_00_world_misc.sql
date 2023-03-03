delete from gameobject_template where entry = 216666;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `data24`, `data25`, `data26`, `data27`, `data28`, `data29`, `data30`, `data31`, `unkInt32`, `AIName`, `ScriptName`, `WorldEffectID`, `SpellVisualID`, `WDBVerified`) VALUES 
(216666, 11, 13729, 'Doodad_MerrygoRound_transport001', '', '', '', 0, 40, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 16357);

delete from gameobject where id = 216666;
INSERT INTO `gameobject` (`id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`) VALUES 
(216666, 974, 5861, 5870, 1, 1, -4031.01, 6352.32, 13.0719, 4.40818, 0, 0, 0, 0, 0, 0, 0, 0);

/* delete from creature_transport where transport_entry = 216666;
INSERT INTO `creature_transport` (`guid`, `transport_entry`, `npc_entry`, `TransOffsetX`, `TransOffsetY`, `TransOffsetZ`, `TransOffsetO`, `emote`) VALUES 
(1, 216666, 68233, -4036.49, 6347.15, 14.2733, 2.32829, 0),
(2, 216666, 68238, -4038.05, 6354.25, 14.2733, 1.30653, 0),
(3, 216666, 68239, -4029.15, 6344.86, 14.2733, 3.38044, 0),
(4, 216666, 68232, -4032.81, 6359.51, 14.2733, 0.19533, 0),
(5, 216666, 68231, -4025.27, 6357.47, 14.2733, 5.51876, 0),
(6, 216666, 68238, -4023.84, 6350.24, 14.2733, 4.41405, 0); */