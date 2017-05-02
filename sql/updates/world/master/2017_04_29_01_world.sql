--
DELETE FROM `creature_addon` WHERE `guid`=280010;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (280010,280010,0,0,258,0, '');

UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=-9027.755,`position_y`=-91.86395,`position_z`=87.15546 WHERE `guid`=280023;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=-9024.755,`position_y`=-94.86395,`position_z`=87.15546 WHERE `guid`=280024;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=-9024.755,`position_y`=-91.86395,`position_z`=87.15546 WHERE `guid`=280025;
