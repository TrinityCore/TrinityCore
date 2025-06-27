-- 
UPDATE `npc_text` SET `Text0_0`="You ever tried on Synthebrew Goggles? They're surprisingly uncomfortable!", `BroadcastTextID0`=23836 WHERE `ID`=12181;
UPDATE `npc_text` SET `Text0_0`="I'll tell ya, the only proper way to hunt is when yer good an' goggled!", `BroadcastTextID0`=23782 WHERE `ID`=12165;
UPDATE `gossip_menu_option` SET `OptionText`="What are Synthebrew Goggles?" , `OptionBroadcastTextID`=35222, `BoxMoney`=0, `BoxText`="", `BoxBroadcastTextID`=0, `ActionMenuID`=10603 WHERE `MenuID`=9006;
UPDATE `gossip_menu_option` SET `OptionText`="What are Synthebrew Goggles?" , `OptionBroadcastTextID`=35222 WHERE `MenuID`=9016;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 15 AND `SourceGroup` IN (9016,9006);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15, 9016,0, 0,0, 2,0, 46735,1,0, 1,0,0, '', 'Show gossip menu option 9016 if the player doesnt have the item 46735'),
(15, 9006,0, 0,0, 2,0, 46735,1,0, 1,0,0, '', 'Show gossip menu option 9016 if the player doesnt have the item 46735');
