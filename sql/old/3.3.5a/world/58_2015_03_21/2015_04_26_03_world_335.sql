--
DELETE FROM `gossip_menu` WHERE `Entry`=2944 AND `text_id` IN (3656, 3658);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (2944, 3656), (2944, 3658);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=2944;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `ErrorTextId`,`ScriptName`,`Comment`, `NegativeCondition`) VALUES
(14,2944,3656,0,8,878,0,0,0,'','Show gossip menu text if Tribes at War is not rewarded', 1),
(14,2944,3658,0,8,878,0,0,0,'','Show gossip menu text if Tribes at War rewarded', 0),
(14,2944,3670,0,8,906,0,0,0,'','Show gossip menu text if Betrayal from Within is rewarded', 0);
