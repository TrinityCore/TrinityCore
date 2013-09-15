SET @MATT2          := 32404;  -- Matthias Lehner
SET @PLSP_FC        := 58989;  -- Prodigal Leader Force Cast
SET @L_CAPTAIN      := 32414;  -- Lordaeron Captain
SET @L_FOOTSOLDIER  := 31254;  -- Lordaeron Footsoldier 

DELETE FROM `smart_scripts` WHERE `entryorguid`=@MATT2 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@MATT2,0,0,0,19,0,100,0,13395,0,0,0,11,@PLSP_FC,0,0,0,0,0,7,0,0,0,0,0,0,0,'On Quest accept - Cast spell - Cast Invoker'),
(@MATT2,0,1,0,19,0,100,0,13236,0,0,0,11,@PLSP_FC,0,0,0,0,0,7,0,0,0,0,0,0,0,'On Quest accept - Cast spell - Cast  Invoker'),
(@MATT2,0,2,3,62,0,100,0,10226,0,0,0,11,@PLSP_FC,0,0,0,0,0,7,0,0,0,0,0,0,0,'On Gossip Select - Cast spell - Cast Invoker'),
(@MATT2,0,3,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'On Gossip Select - Close Gossip - Invoker');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=10226;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,10226,0,0,0,9,0,13395,0,0,0,0,0,'','Show Gossip Menu Option only when quest is active'),
(15,10226,0,0,1,9,0,13236,0,0,0,0,0,'','Show Gossip Menu Option only when quest is active');
