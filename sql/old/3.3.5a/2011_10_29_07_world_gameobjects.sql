-- dummy spell focus gameobject
DELETE FROM `gameobject_template` WHERE `entry`=300245 AND `type`=8 AND `data0`=1636;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `AIName`, `ScriptName`, `WDBVerified`) VALUES
(300245, 8, 0, 'TEMP Forgemaster''s Anvil', '', '', '', 0, 0, 1, 0, 0, 0, 0, 0, 0, 1636, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 1);

-- untargetable flag if not in quest
UPDATE `gameobject_template` SET `flags`=`flags`|4 WHERE `entry`=201592; -- Infused Saronite Bars

-- spawn
DELETE FROM `gameobject` WHERE `id`=300245;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(207, 300245, 658, 3, 1, 727.988, -121.675, 515.259, 4.29381, 0, 0, 0.838588, -0.544766, 300, 0, 1),
(215, 300245, 658, 3, 1, 661.331, -121.89, 514.948, 1.34464, 0, 0, 0.622803, 0.782378, 300, 0, 1);
