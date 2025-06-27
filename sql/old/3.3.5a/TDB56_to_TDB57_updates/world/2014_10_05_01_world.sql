--
SET @Linda :=32687;
SET @Alec :=32692;

UPDATE creature_template SET `AIName`='SmartAI' WHERE entry IN (@Linda, @Alec);

DELETE FROM `smart_scripts` WHERE `entryorguid` = @Linda AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Linda*100 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Linda*100+1 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Linda, 0, 0, 0, 10, 0, 100, 0, 1, 10, 300000, 300000, 87, @Linda*100, @Linda*100+1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Linda - OOC_LOS - RANDOM_TIMED_ACTIONLIST'),
(@Linda*100,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Linda - RANDOM_TIMED_ACTIONLIST -  talk'),
(@Linda*100+1,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,19,@Alec,5,0,0,0,0,0,'Linda - RANDOM_TIMED_ACTIONLIST -  talk');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=1 AND `SourceEntry`=@Linda;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,@Linda,0,5,1090,128,0,0,'','event require Kirin Tor Exalted');


DELETE FROM creature_text WHERE entry IN (@Linda, @Alec);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(@Linda, 0, 0, 'There goes the finest $c I have the honor of knowing.', 12, 0, 100, 0, 0, 0, 'Linda Ann Kastinglow', 32866), 
(@Linda, 0, 1, '$n, you''re an inspiration.', 12, 0, 100, 0, 0, 0, 'Linda Ann Kastinglow', 32867), 
(@Linda, 0, 2, 'A fine example of a $g man:woman;, that $n.', 12, 0, 100, 0, 0, 0, 'Linda Ann Kastinglow', 32868), 
(@Linda, 0, 3, 'You couldn''t ask for a finer person than $n, I say.', 12, 0, 100, 0, 0, 0, 'Linda Ann Kastinglow', 32869), 
(@Linda, 0, 4, '$n, wonderful to see you. Wonderful.', 12, 0, 100, 0, 0, 0, 'Linda Ann Kastinglow', 32870),  
(@Linda, 0, 5, '$n! Ah, fantastic to see you out and about. Busy as always, hm?', 12, 0, 100, 0, 0, 0, 'Linda Ann Kastinglow', 32871),

(@Alec, 0, 0, 'There goes the finest $c I have the honor of knowing.', 12, 0, 100, 0, 0, 0, 'Arcanist Alec', 32866), 
(@Alec, 0, 1, '$n, you''re an inspiration.', 12, 0, 100, 0, 0, 0, 'Arcanist Alec', 32867), 
(@Alec, 0, 2, 'A fine example of a $g man:woman;, that $n.', 12, 0, 100, 0, 0, 0, 'Arcanist Alec', 32868), 
(@Alec, 0, 3, 'You couldn''t ask for a finer person than $n, I say.', 12, 0, 100, 0, 0, 0, 'Arcanist Alec', 32869), 
(@Alec, 0, 4, '$n, wonderful to see you. Wonderful.', 12, 0, 100, 0, 0, 0, 'Arcanist Alec', 32870),  
(@Alec, 0, 5, '$n! Ah, fantastic to see you out and about. Busy as always, hm?', 12, 0, 100, 0, 0, 0, 'Arcanist Alec', 32871);
