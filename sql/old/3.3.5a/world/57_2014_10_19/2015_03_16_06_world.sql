-- 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=46104;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,46104,0,0,31,1,3,25835,0,0,0,0,'','Nesingwary Trapper can be killed by the Trapped!');

DELETE FROM `creature_text` WHERE `entry` IN (25835) ;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(25835, 0, 0, 'It''s a miracle! The beast skinned itself!', 12, 0, 100, 0, 0, 0, 'Nesingwary Trapper', 25029),
(25835, 0, 1, 'Jackpot!', 12, 0, 100, 0, 0, 0, 'Nesingwary Trapper', 25034),
(25835, 0, 2, 'Stupid beasts!', 12, 0, 100, 0, 0, 0, 'Nesingwary Trapper', 25030),
(25835, 0, 3, 'This is the last one that I need for the set of Nesingwary steak knives!', 12, 0, 100, 0, 0, 0, 'Nesingwary Trapper', 25031);
