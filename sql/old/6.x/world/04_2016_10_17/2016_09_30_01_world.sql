DELETE FROM `npc_text` WHERE `ID` IN (27750 /*27750*/, 29907 /*29907*/, 27479 /*27479*/, 27473 /*27473*/, 27475 /*27475*/, 27476 /*27476*/, 27448 /*27448*/);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(27750, 1, 0, 0, 0, 0, 0, 0, 0, 101573, 0, 0, 0, 0, 0, 0, 0, 22624), -- 27750
(29907, 1, 0, 0, 0, 0, 0, 0, 0, 119370, 0, 0, 0, 0, 0, 0, 0, 22624), -- 29907
(27479, 1, 0, 0, 0, 0, 0, 0, 0, 100036, 0, 0, 0, 0, 0, 0, 0, 22624), -- 27479
(27473, 1, 0, 0, 0, 0, 0, 0, 0, 100026, 0, 0, 0, 0, 0, 0, 0, 22624), -- 27473
(27475, 1, 0, 0, 0, 0, 0, 0, 0, 100030, 0, 0, 0, 0, 0, 0, 0, 22624), -- 27475
(27476, 1, 0, 0, 0, 0, 0, 0, 0, 100031, 0, 0, 0, 0, 0, 0, 0, 22624), -- 27476
(27448, 1, 0, 0, 0, 0, 0, 0, 0, 99951, 0, 0, 0, 0, 0, 0, 0, 22624); -- 27448

UPDATE `npc_text` SET `VerifiedBuild`=22624 WHERE `ID`=13303; -- 13303
