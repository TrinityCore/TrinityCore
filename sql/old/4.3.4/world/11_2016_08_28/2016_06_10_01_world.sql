--
DELETE FROM `gameobject_template` WHERE `entry` = 208120;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `unkInt32`, `AIName`, `ScriptName`, `VerifiedBuild`) VALUES
(208120, 2, 6404, 'Candy Bucket', '', 'Examining', '', 0, 0, 1, 0, 16256, 0, 0, 0, 0, 24124, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', '19034');

UPDATE `creature_template` SET `npcflag`=`npcflag`|2 WHERE `entry`= 3101;
