-- By Dasio
UPDATE `smart_scripts` SET `action_param2`=2, `action_param3`=0 WHERE `entryorguid`=4961 AND `id` IN (1,2) AND `source_type`=0;

-- By tREAK
SET @NPC_STEFAN :=28518;
SET @SPELL_PUSH_ENSORCELED_CHOKER :=53810;

DELETE FROM `smart_scripts` WHERE `entryorguid`=28518 AND `source_type`=0 AND `id` IN (1,2,4);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC_STEFAN,0,1,2,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Stefan Vadu - On gossip select - Say line'),
(@NPC_STEFAN,0,2,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Stefan Vadu - On gossip select - Close gossip'),
(@NPC_STEFAN,0,4,2,62,0,100,0,9709,1,0,0,85,@SPELL_PUSH_ENSORCELED_CHOKER,0,0,0,0,0,7,0,0,0,0,0,0,0,'Stefan Vadu - On gossip select - Invoker Spellcast');
