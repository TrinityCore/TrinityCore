DELETE FROM `npc_text` WHERE `ID` IN (30502 /*30502*/, 27571 /*27571*/, 30293 /*30293*/, 30271 /*30271*/, 30270 /*30270*/, 28396 /*28396*/, 28245 /*28245*/, 28243 /*28243*/, 30259 /*30259*/);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(30502, 1, 0, 0, 0, 0, 0, 0, 0, 122417, 0, 0, 0, 0, 0, 0, 0, 22810), -- 30502
(27571, 1, 0, 0, 0, 0, 0, 0, 0, 100487, 0, 0, 0, 0, 0, 0, 0, 22810), -- 27571
(30293, 1, 0, 0, 0, 0, 0, 0, 0, 121622, 0, 0, 0, 0, 0, 0, 0, 22810), -- 30293
(30271, 1, 0, 0, 0, 0, 0, 0, 0, 121490, 0, 0, 0, 0, 0, 0, 0, 22810), -- 30271
(30270, 1, 0, 0, 0, 0, 0, 0, 0, 121487, 0, 0, 0, 0, 0, 0, 0, 22810), -- 30270
(28396, 1, 0, 0, 0, 0, 0, 0, 0, 105763, 0, 0, 0, 0, 0, 0, 0, 22810), -- 28396
(28245, 1, 1, 1, 1, 1, 1, 1, 1, 104662, 104663, 104664, 104665, 104666, 104667, 104668, 104669, 22810), -- 28245
(28243, 1, 0, 0, 0, 0, 0, 0, 0, 104606, 0, 0, 0, 0, 0, 0, 0, 22810), -- 28243
(30259, 1, 0, 0, 0, 0, 0, 0, 0, 121442, 0, 0, 0, 0, 0, 0, 0, 22810); -- 30259

UPDATE `npc_text` SET `VerifiedBuild`=22810 WHERE `ID`=5069; -- 5069
UPDATE `npc_text` SET `VerifiedBuild`=22810 WHERE `ID`=18354; -- 18354
UPDATE `npc_text` SET `VerifiedBuild`=22810 WHERE `ID`=10000; -- 10000
