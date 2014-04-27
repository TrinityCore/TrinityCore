--
UPDATE `gossip_menu_option` SET `option_id`=5, `npc_option_npcflag`=16 WHERE `menu_id`=9578;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=9578;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,9578,12926,0,0,15,0,128,0,0,0,0,0,'','Show gossip text if player is a Mage'),
(15,9578,0,0,0,15,0,128,0,0,0,0,0,'','Show gossip option if player is a Mage');
