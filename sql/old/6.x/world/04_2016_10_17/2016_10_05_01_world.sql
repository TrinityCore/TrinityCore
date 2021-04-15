DELETE FROM `npc_text` WHERE `ID` IN (28102 /*28102*/, 29485 /*29485*/, 29003 /*29003*/, 30171 /*30171*/, 30512 /*30512*/, 29001 /*29001*/, 28313 /*28313*/, 28901 /*28901*/, 29909 /*29909*/, 29892 /*29892*/, 29890 /*29890*/, 29891 /*29891*/, 30330 /*30330*/, 30210 /*30210*/);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(28102, 1, 0, 0, 0, 0, 0, 0, 0, 103914, 0, 0, 0, 0, 0, 0, 0, 22624), -- 28102
(29485, 1, 0, 0, 0, 0, 0, 0, 0, 114327, 0, 0, 0, 0, 0, 0, 0, 22624), -- 29485
(29003, 1, 0, 0, 0, 0, 0, 0, 0, 109769, 0, 0, 0, 0, 0, 0, 0, 22624), -- 29003
(30171, 1, 0, 0, 0, 0, 0, 0, 0, 121009, 0, 0, 0, 0, 0, 0, 0, 22624), -- 30171
(30512, 1, 0, 0, 0, 0, 0, 0, 0, 122451, 0, 0, 0, 0, 0, 0, 0, 22624), -- 30512
(29001, 1, 0, 0, 0, 0, 0, 0, 0, 109361, 0, 0, 0, 0, 0, 0, 0, 22624), -- 29001
(28313, 1, 0, 0, 0, 0, 0, 0, 0, 105074, 0, 0, 0, 0, 0, 0, 0, 22624), -- 28313
(28901, 1, 0, 0, 0, 0, 0, 0, 0, 108945, 0, 0, 0, 0, 0, 0, 0, 22624), -- 28901
(29909, 1, 0, 0, 0, 0, 0, 0, 0, 119386, 0, 0, 0, 0, 0, 0, 0, 22624), -- 29909
(29892, 1, 0, 0, 0, 0, 0, 0, 0, 119170, 0, 0, 0, 0, 0, 0, 0, 22624), -- 29892
(29890, 1, 0, 0, 0, 0, 0, 0, 0, 119169, 0, 0, 0, 0, 0, 0, 0, 22624), -- 29890
(29891, 1, 0, 0, 0, 0, 0, 0, 0, 119171, 0, 0, 0, 0, 0, 0, 0, 22624), -- 29891
(30330, 1, 1, 1, 1, 1, 0, 0, 0, 121781, 121782, 121783, 121784, 121785, 0, 0, 0, 22624), -- 30330
(30210, 1, 0, 0, 0, 0, 0, 0, 0, 121106, 0, 0, 0, 0, 0, 0, 0, 22624); -- 30210

DELETE FROM `gameobject_template` WHERE `entry` IN (259057 /*Fist of Ra-den Appearance*/, 258927 /*Fist of Ra-den Appearance*/, 252404 /*Felwort*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `VerifiedBuild`) VALUES
(259057, 5, 37934, 'Fist of Ra-den Appearance', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 22624), -- Fist of Ra-den Appearance
(258927, 5, 37924, 'Fist of Ra-den Appearance', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 22624), -- Fist of Ra-den Appearance
(252404, 50, 32112, 'Felwort', '', '', '', 1.2, 29, 62242, 0, 0, 800, 800, 15, 0, 0, 0, 0, 0, 100, 1, 193384, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 98, 22624); -- Felwort

UPDATE `gameobject_template` SET `VerifiedBuild`=22624 WHERE `entry`=252003; -- Portal
UPDATE `gameobject_template` SET `VerifiedBuild`=22624 WHERE `entry`=252006; -- Portal
UPDATE `gameobject_template` SET `VerifiedBuild`=22624 WHERE `entry`=251751; -- Treasure Chest
