SET @NPCTEXTID := 530007;
DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+1;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 1, 0, 0, 0, 0, 0, 0, 242822, 242815, 0, 0, 0, 0, 0, 0, 57564), -- 205890 (Zidormi)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 284310, 0, 0, 0, 0, 0, 0, 0, 60192); -- 240309 (Wyrmrest Defender)
