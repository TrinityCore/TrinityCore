UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=32820;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=32820;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(32820,0,0,0,6,0,100,0,0,0,0,0,11,62014,2,0,0,0,0,7,0,0,0,0,0,0,0,"Wild Turkey - On Just Died - Cast 'Turkey Tracker'");

DELETE FROM `creature_text` WHERE `entry`=32820;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(32820,0,0,'Turkey Hunter!',42,0,100,0,0,0,33163,0,'Wild Turkey'),
(32820,1,0,'Turkey Domination!',42,0,100,0,0,0,33164,0,'Wild Turkey'),
(32820,2,0,'Turkey Slaughter!',42,0,100,0,0,0,33165,0,'Wild Turkey'),
(32820,3,0,'TURKEY TRIUMPH!',42,0,100,0,0,0,33167,0,'Wild Turkey');

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_pilgrims_bounty_turkey_tracker';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(62014,'spell_pilgrims_bounty_turkey_tracker');
