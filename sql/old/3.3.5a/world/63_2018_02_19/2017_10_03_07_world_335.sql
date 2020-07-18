-- 
UPDATE `npc_text` SET `BroadcastTextID0`=0 WHERE `ID`=3753;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup` IN (3223, 3183, 3228, 3184, 7385);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 3223, 3978, 0, 0, 8, 0, 5230, 0, 0, 1, 0, 0, "", "Gossip text requires quest 'Return to the Bulwark' NOT rewarded"),
(14, 3223, 3979, 0, 0, 8, 0, 5230, 0, 0, 0, 0, 0, "", "Gossip text requires quest 'Return to the Bulwark' rewarded"),
(14, 3183, 3939, 0, 0, 8, 0, 5230, 0, 0, 1, 0, 0, "", "Gossip text requires quest 'Return to the Bulwark' NOT rewarded"),
(14, 3183, 4040, 0, 0, 8, 0, 5230, 0, 0, 0, 0, 0, "", "Gossip text requires quest 'Return to the Bulwark' rewarded"),
(14, 3228, 3984, 0, 0, 8, 0, 5217, 0, 0, 1, 0, 0, "", "Gossip text requires quest 'Return to Chillwind Camp' NOT rewarded"),
(14, 3228, 3985, 0, 0, 8, 0, 5217, 0, 0, 0, 0, 0, "", "Gossip text requires quest 'Return to Chillwind Camp' rewarded"),
(14, 3184, 3940, 0, 0, 8, 0, 5217, 0, 0, 1, 0, 0, "", "Gossip text requires quest 'Return to Chillwind Camp' NOT rewarded"),
(14, 3184, 4039, 0, 0, 8, 0, 5217, 0, 0, 0, 0, 0, "", "Gossip text requires quest 'Return to Chillwind Camp' rewarded"),
(14, 7385, 8846, 0, 0, 47, 0, 9474, 65, 0, 0, 0, 0, "", "Gossip text requires quest 'The Mark of the Lightbringer' rewarded or not taken"),
(14, 7385, 8964, 0, 0, 47, 0, 9474, 10, 0, 0, 0, 0, "", "Gossip text requires quest 'The Mark of the Lightbringer' taken or completed");
