DELETE FROM `gameobject_scripts` WHERE `id`=15351;
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=161460;
DELETE FROM `smart_scripts` WHERE `entryorguid`=161460 AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(161460,1,0,1,70,0,100,0,2,0,0,0,9,0,0,0,0,0,0,14,15639,161461,0,0,0,0,0, 'Shadowforge Lock - On Activate - Open the Giant Door Mechanism'),
(161460,1,1,2,61,0,100,0,0,0,0,0,9,0,0,0,0,0,0,14,15576,157923,0,0,0,0,0, 'Shadowforge Lock - On Activate - Close the Giant Doors'),
(161460,1,2,3,61,0,100,0,0,0,0,0,9,0,0,0,0,0,0,14,15640,161462,0,0,0,0,0, 'Shadowforge Lock - On Activate - Remove the great invisible wall'),
(161460,1,3,0,61,0,100,0,0,0,0,0,9,0,0,0,0,0,0,14,15352,161516,0,0,0,0,0, 'Shadowforge Lock - On Activate - Remove the invisible wall on top');
