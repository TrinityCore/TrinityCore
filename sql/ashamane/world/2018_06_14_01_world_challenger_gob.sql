DELETE FROM `gameobject_template` WHERE `entry` IN (269852 /*269852*/, 239408 /*239408*/, 211988 /*211988*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `VerifiedBuild`) VALUES
(269852, 3, 33268, 'Challenger''s Cache', '', '', '', 2.5, 1634, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 110, 0, 0, 0, 0, 1961, 0, 1, 0, 0, 73091, 0, 5, 110, 26654), -- 269852
(239408, 0, 11638, 'Challenge Mode - Start Door (Line 2.5) [DNT]', '', '', '', 2.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26654), -- 239408
(211988, 0, 11638, 'Challenge Mode - Start Door (Line 1.0)', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26654); -- 211988

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (269852 /*269852*/, 211988 /*211988*/, 239408 /*239408*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`) VALUES
(269852, 94, 16416), -- 269852
(211988, 1375, 35), -- 211988
(239408, 1375, 35); -- 239408
