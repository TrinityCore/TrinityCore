--
DELETE FROM smart_scripts WHERE entryorguid in (25001,25002,24999) AND event_type=6;
UPDATE `smart_scripts` SET `id`=1 WHERE  `entryorguid`=25001 AND `id`=0 AND `action_param1` =12744;
DELETE FROM smart_scripts WHERE entryorguid in (25001) AND `id`>0;

INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25001,0,0,0,11,0,100,0,0,0,0,0,11,45227,0,0,0,0,0,1,0,0,0,0,0,0,0,'Abyssal Flamewalker - On spawn - Cast Abyssal Meteor Fall');
