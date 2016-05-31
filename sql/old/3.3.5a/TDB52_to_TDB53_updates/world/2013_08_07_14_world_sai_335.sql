UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=5353;

DELETE FROM `smart_scripts` WHERE `entryorguid`=5353 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5353, 0, 0, 1,62, 0, 100, 0, 1364, 0, 0, 0, 85, 12578, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Itharius - On Gossip Select - Cast Create Oathstone of Yseras Dragonflight'),
(5353, 0, 1, 0,61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Itharius - Linked with Previous Event - Close Gossip');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=1341;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,1341,1,0,0,2,0,10455,1,1,0,0,'','Itharius show gossip only if player has Chained Essence of Eranikus'),
(15,1341,1,0,0,2,0,10589,1,1,1,0,'','Itharius show gossip only if player Does not have Oathstone of Yseras Dragonflight'),
(15,1341,1,0,0,8,0,3374,0,0,1,0,'','Itharius show gossip only if player has not completed The Essence of Eranikus q3374'),
(15,1341,1,0,0,8,0,3373,0,0,0,0,'','Itharius show gossip only if player has completed The Essence of Eranikus q3373');
