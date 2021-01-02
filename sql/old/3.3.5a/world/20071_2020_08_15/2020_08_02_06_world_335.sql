--
UPDATE `npc_text` SET `BroadcastTextID0` = 2503, `lang0` = 7 WHERE `ID` = 539;
UPDATE `npc_text` SET `BroadcastTextID0` = 2524 WHERE `ID` = 559;
UPDATE `npc_text` SET `BroadcastTextID0` = 2528, `lang0` = 1 WHERE `ID` = 563;
UPDATE `npc_text` SET `BroadcastTextID0` = 2821, `lang0` = 7 WHERE `ID` = 820;
UPDATE `npc_text` SET `BroadcastTextID0` = 2941, `lang0` = 7 WHERE `ID` = 918;
UPDATE `npc_text` SET `BroadcastTextID0` = 3368 WHERE `ID` = 1231;
UPDATE `npc_text` SET `BroadcastTextID0` = 3371 WHERE `ID` = 1232;
UPDATE `npc_text` SET `BroadcastTextID0` = 3385 WHERE `ID` = 1238;
UPDATE `npc_text` SET `BroadcastTextID0` = 3386 WHERE `ID` = 1239;
UPDATE `npc_text` SET `BroadcastTextID0` = 3410 WHERE `ID` = 1257;
UPDATE `npc_text` SET `BroadcastTextID0` = 3412 WHERE `ID` = 1259;
UPDATE `npc_text` SET `BroadcastTextID0` = 3425, `lang0` = 1 WHERE `ID` = 1272;
UPDATE `npc_text` SET `BroadcastTextID0` = 3458, `lang0` = 1 WHERE `ID` = 1300;
UPDATE `npc_text` SET `BroadcastTextID0` = 3459, `lang0` = 1 WHERE `ID` = 1301;
UPDATE `npc_text` SET `BroadcastTextID0` = 4584 WHERE `ID` = 2193;
UPDATE `npc_text` SET `BroadcastTextID0` = 4857, `lang0` = 1 WHERE `ID` = 2593;
UPDATE `npc_text` SET `BroadcastTextID0` = 4858 WHERE `ID` = 2594;
UPDATE `npc_text` SET `BroadcastTextID0` = 4878 WHERE `ID` = 2599;
UPDATE `npc_text` SET `BroadcastTextID0` = 5077 WHERE `ID` = 2760;
UPDATE `npc_text` SET `BroadcastTextID0` = 5089 WHERE `ID` = 2766;
UPDATE `npc_text` SET `BroadcastTextID0` = 5113 WHERE `ID` = 2793;
UPDATE `npc_text` SET `BroadcastTextID0` = 5240 WHERE `ID` = 2848;
UPDATE `npc_text` SET `BroadcastTextID0` = 7647 WHERE `ID` = 3061;
UPDATE `npc_text` SET `BroadcastTextID0` = 5888 WHERE `ID` = 3541;
UPDATE `npc_text` SET `BroadcastTextID0` = 5901 WHERE `ID` = 3542;
UPDATE `npc_text` SET `BroadcastTextID0` = 5907, `lang0` = 1 WHERE `ID` = 3543;
UPDATE `npc_text` SET `BroadcastTextID0` = 5935 WHERE `ID` = 3550;
UPDATE `npc_text` SET `BroadcastTextID0` = 6479 WHERE `ID` = 3939;
UPDATE `npc_text` SET `BroadcastTextID0` = 6502 WHERE `ID` = 3961;
UPDATE `npc_text` SET `BroadcastTextID0` = 6602 WHERE `ID` = 4035;
UPDATE `npc_text` SET `BroadcastTextID0` = 6617 WHERE `ID` = 4036;
UPDATE `npc_text` SET `BroadcastTextID0` = 6630, `lang0` = 1 WHERE `ID` = 4037;
UPDATE `npc_text` SET `BroadcastTextID0` = 6700 WHERE `ID` = 4069;
UPDATE `npc_text` SET `BroadcastTextID0` = 6705 WHERE `ID` = 4070;
UPDATE `npc_text` SET `BroadcastTextID0` = 6718, `lang0` = 1 WHERE `ID` = 4072;
UPDATE `npc_text` SET `BroadcastTextID0` = 6788, `lang0` = 1 WHERE `ID` = 4097;
UPDATE `npc_text` SET `BroadcastTextID0` = 6906 WHERE `ID` = 4259;
UPDATE `npc_text` SET `BroadcastTextID0` = 7158, `lang0` = 7 WHERE `ID` = 4435;
UPDATE `npc_text` SET `BroadcastTextID0` = 7165 WHERE `ID` = 4437;
UPDATE `npc_text` SET `BroadcastTextID0` = 7163, `lang0` = 1 WHERE `ID` = 4439;
UPDATE `npc_text` SET `BroadcastTextID0` = 7162 WHERE `ID` = 4441;
UPDATE `npc_text` SET `BroadcastTextID0` = 7492, `lang0` = 7 WHERE `ID` = 4835;
UPDATE `npc_text` SET `BroadcastTextID0` = 7493, `lang0` = 7 WHERE `ID` = 4837;
UPDATE `npc_text` SET `BroadcastTextID0` = 7647 WHERE `ID` = 4997;
UPDATE `npc_text` SET `BroadcastTextID0` = 7652 WHERE `ID` = 5001;
UPDATE `npc_text` SET `BroadcastTextID0` = 7660 WHERE `ID` = 5006;
UPDATE `npc_text` SET `BroadcastTextID0` = 8189 WHERE `ID` = 5565;
UPDATE `npc_text` SET `BroadcastTextID0` = 8322 WHERE `ID` = 5739;
UPDATE `npc_text` SET `BroadcastTextID0` = 8364 WHERE `ID` = 5813;
-- Elissa Dumas
UPDATE `npc_text` SET `BroadcastTextID0` = 8440, `lang0` = 7 WHERE `ID` = 5873;
UPDATE `npc_text` SET `BroadcastTextID0` = 8441, `lang0` = 7 WHERE `ID` = 5874;

DELETE FROM `gossip_menu` WHERE `MenuID` = 4821 AND `TextID` = 5874;
INSERT INTO `gossip_menu` (`MenuID`,`TextID`) VALUES
(4821,5874);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 14 AND `SourceGroup` = 4821;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,4821,5873,0,0,15,0,128,0,0,1,0,0,"","Group 0: Show gossip text 5873 if player is not a mage"),
(14,4821,5874,0,0,15,0,128,0,0,0,0,0,"","Group 0: Show gossip text 5874 if player is a mage");
-- Larimaine Purdue, both texts are used but without conditions
UPDATE `npc_text` SET `BroadcastTextID0` = 8443, `lang0` = 7 WHERE `ID` = 5875;
UPDATE `npc_text` SET `BroadcastTextID0` = 8444, `lang0` = 7 WHERE `ID` = 5876;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 14 AND `SourceGroup` = 4822;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,4822,5875,0,0,15,0,128,0,0,1,0,0,"","Group 0: Show gossip text 5875 if player is not a mage"),
(14,4822,5876,0,0,15,0,128,0,0,0,0,0,"","Group 0: Show gossip text 5876 if player is a mage");
-- Milstaff Stormeye, conditions already added
UPDATE `npc_text` SET `BroadcastTextID0` = 8445, `lang0` = 7 WHERE `ID` = 5877;
UPDATE `npc_text` SET `BroadcastTextID0` = 8446, `lang0` = 7 WHERE `ID` = 5878;
-- Narinth, Lunaraa, why too low ids are used in TBC? Who used them previously?
-- Why only male text is available in npc_text?
-- There's no other texts with proper language and male or female or only female text
-- Risky.
UPDATE `npc_text` SET `BroadcastTextID0` = 8447, `lang0` = 0 WHERE `ID` = 5879;
UPDATE `npc_text` SET `BroadcastTextID0` = 8448, `lang0` = 0 WHERE `ID` = 5880;

DELETE FROM `gossip_menu` WHERE `MenuID` = 4824 AND `TextID` = 5880;
INSERT INTO `gossip_menu` (`MenuID`,`TextID`) VALUES
(4824,5880);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 14 AND `SourceGroup` = 4824;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,4824,5879,0,0,15,0,128,0,0,1,0,0,"","Group 0: Show gossip text 5879 if player is not a mage"),
(14,4824,5880,0,0,15,0,128,0,0,0,0,0,"","Group 0: Show gossip text 5880 if player is a mage");
-- Birgitte Cranston, ids and language are already correct, only text is missing
UPDATE `npc_text` SET `BroadcastTextID0` = 8453, `lang0` = 1 WHERE `ID` = 5881;
UPDATE `npc_text` SET `BroadcastTextID0` = 8449, `lang0` = 1 WHERE `ID` = 5882;

DELETE FROM `gossip_menu` WHERE `MenuID` = 4825 AND `TextID` = 5882;
INSERT INTO `gossip_menu` (`MenuID`,`TextID`) VALUES
(4825,5882);
-- Thuul
UPDATE `npc_text` SET `BroadcastTextID0` = 8454, `lang0` = 1 WHERE `ID` = 5883;
UPDATE `npc_text` SET `BroadcastTextID0` = 8455, `lang0` = 1 WHERE `ID` = 5884;
-- Lexington Mortaim
UPDATE `npc_text` SET `BroadcastTextID0` = 8456, `lang0` = 1 WHERE `ID` = 5885;
UPDATE `npc_text` SET `BroadcastTextID0` = 8457, `lang0` = 1 WHERE `ID` = 5886;

DELETE FROM `gossip_menu` WHERE `MenuID` = 4827 AND `TextID` = 5886;
INSERT INTO `gossip_menu` (`MenuID`,`TextID`) VALUES
(4827,5886);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 14 AND `SourceGroup` = 4827;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,4827,5885,0,0,15,0,128,0,0,1,0,0,"","Group 0: Show gossip text 5885 if player is not a mage"),
(14,4827,5886,0,0,15,0,128,0,0,0,0,0,"","Group 0: Show gossip text 5886 if player is a mage");

UPDATE `npc_text` SET `BroadcastTextID0` = 8473 WHERE `ID` = 5918;
UPDATE `npc_text` SET `BroadcastTextID0` = 8802 WHERE `ID` = 6073;
UPDATE `npc_text` SET `BroadcastTextID0` = 8803 WHERE `ID` = 6217;
UPDATE `npc_text` SET `BroadcastTextID0` = 8804 WHERE `ID` = 6218;
UPDATE `npc_text` SET `BroadcastTextID0` = 8805 WHERE `ID` = 6219;
UPDATE `npc_text` SET `BroadcastTextID0` = 8806 WHERE `ID` = 6220;
UPDATE `npc_text` SET `BroadcastTextID0` = 8809 WHERE `ID` = 6223;
UPDATE `npc_text` SET `BroadcastTextID0` = 9132 WHERE `ID` = 6735;
UPDATE `npc_text` SET `BroadcastTextID0` = 9133 WHERE `ID` = 6736;
UPDATE `npc_text` SET `BroadcastTextID0` = 9131 WHERE `ID` = 6737;
UPDATE `npc_text` SET `BroadcastTextID0` = 9148 WHERE `ID` = 6755;
UPDATE `npc_text` SET `BroadcastTextID0` = 9153 WHERE `ID` = 6775;
UPDATE `npc_text` SET `BroadcastTextID0` = 9156 WHERE `ID` = 6777;
UPDATE `npc_text` SET `BroadcastTextID0` = 9210 WHERE `ID` = 6793;
UPDATE `npc_text` SET `BroadcastTextID0` = 9276 WHERE `ID` = 6826;
UPDATE `npc_text` SET `BroadcastTextID0` = 9531 WHERE `ID` = 6948;
UPDATE `npc_text` SET `BroadcastTextID0` = 9555 WHERE `ID` = 6959;

UPDATE `npc_text` SET `BroadcastTextID1` = 3369 WHERE `ID` = 1231;
UPDATE `npc_text` SET `BroadcastTextID1` = 3372 WHERE `ID` = 1232;
-- 6 similar texts, pff
UPDATE `npc_text` SET `BroadcastTextID0` = 3376 WHERE `ID` = 1235;
UPDATE `npc_text` SET `BroadcastTextID0` = 3379 WHERE `ID` = 1236;
UPDATE `npc_text` SET `BroadcastTextID0` = 3382 WHERE `ID` = 1237;
UPDATE `npc_text` SET `BroadcastTextID1` = 3377 WHERE `ID` = 1235;
UPDATE `npc_text` SET `BroadcastTextID1` = 3380 WHERE `ID` = 1236;
UPDATE `npc_text` SET `BroadcastTextID1` = 3383 WHERE `ID` = 1237;
UPDATE `npc_text` SET `BroadcastTextID2` = 3378 WHERE `ID` = 1235;
UPDATE `npc_text` SET `BroadcastTextID2` = 3381 WHERE `ID` = 1236;
UPDATE `npc_text` SET `BroadcastTextID2` = 3384 WHERE `ID` = 1237;

UPDATE `npc_text` a LEFT JOIN `broadcast_text` b ON a.`BroadcastTextID0` = b.`ID` SET a.`text0_1` = b.`Text1` WHERE a.`ID` IN (1272,2593,3543,3961,4037,4072,4097,4259,4437,4439,5001,5006,5879,5880);
