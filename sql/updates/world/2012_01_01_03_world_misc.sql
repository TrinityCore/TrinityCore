-- Add Drop-Off Point GO needed for Decoy! quest by nelegalno
-- TODO: Quest needs to be fully scripted, need to verify Number Two (15554) baseattacktime=120 value
-- Closes #4080

SET @ENTRY := xxxxxx; -- Set by TDB team
SET @GUID1 := xxxxxx; -- Set by TDB team

DELETE FROM `gameobject_template` WHERE (`entry`=@ENTRY);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `AIName`, `ScriptName`, `WDBVerified`) VALUES
(@ENTRY, 8, 299, 'Drop-Off Point', '', '', '', 0, 0, 1, 0, 0, 0, 0, 0, 0, 1348, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', -1);

DELETE FROM `gameobject` WHERE (`guid`=@GUID1);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@GUID1, @ENTRY, 1, 1, 1, 5086.19, -5116.32, 931.162, 4.78877, 0, 0, 0.679593, -0.733589, -150, 0, 1);
