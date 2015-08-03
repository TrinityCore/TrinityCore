-- gossip npc text 15321 - all before wrathgate event
DELETE FROM `gossip_menu` WHERE `entry`=10769 AND `text_id` IN(14931,14933);

INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES 
(10769, 14931), -- After Wrathgate event except undead
(10769, 14933); -- After Wrathgate event undead

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=10769;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(14, 10769, 15321, 0, 0, 8, 0, 12500, 0, 0, 1, 0, 0, '', 'Gossip text requires Return to Angrathar not completed'),
(14, 10769, 14931, 0, 0, 8, 0, 12500, 0, 0, 0, 0, 0, '', 'Gossip text requires Return to Angrathar completed'),
(14, 10769, 14931, 0, 0, 16, 0, 16, 0, 0, 1, 0, 0, '', 'Gossip text requires not undead player'),
(14, 10769, 14933, 0, 0, 8, 0, 12500, 0, 0, 0, 0, 0, '', 'Gossip text requires Return to Angrathar completed'),
(14, 10769, 14933, 0, 0, 16, 0, 16, 0, 0, 0, 0, 0, '', 'Gossip text requires undead player');
