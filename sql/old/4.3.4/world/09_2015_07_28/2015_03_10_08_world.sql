-- Add missing gossip for entry 7766
DELETE FROM `gossip_menu` WHERE `entry`=1761;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (1761,2393),(1761,2394);
UPDATE `creature_template` SET `gossip_menu_id`=1761 WHERE entry=7766;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=1761;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `NegativeCondition`, `ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,1761,2394,0,9,434,0,0,0,0,'','Show gossip menu text if quest 434 is taken');
