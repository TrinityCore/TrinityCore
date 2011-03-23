DELETE FROM `gameobject_template` WHERE `entry`=300149;
INSERT INTO gameobject_template
   (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `AIName`, `ScriptName`, `WDBVerified`)
VALUES
(300149,8,1287, 'TEMP Wrathscale Lair Fountain', '', '', '',0,0,1,0,0,0,0,0,0,223,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, '', '',1);

-- NEEDS VISUAL (apart form Ruins of Stardust, its MISSING!)
DELETE FROM `gameobject` WHERE `id`=300149
INSERT INTO gameobject
   (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`)
VALUES
(1160,300149,530,1,1,-2186.4,-12340.5,56.2888,5.31,0,0,0.121294,-0.992617,-300,0,1);

