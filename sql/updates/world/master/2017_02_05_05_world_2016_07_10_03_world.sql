--
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=5236 AND `id`=5;
UPDATE `smart_scripts` SET `event_param1`=1200, `comment`="Gordunni Shaman - Friendly Missing 1200 Health - Cast 'Healing Wave'" WHERE `source_type`=0 AND `entryorguid`=5236 AND `id`=4;

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=5240;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(5240,0,0,0,0,0,100,0,0,0,4000,4000,11,20298,64,0,0,0,0,2,0,0,0,0,0,0,0,"Gordunni Warlock - Combat CMC - Cast 'Shadow Bolt'"),
(5240,0,1,0,0,0,100,0,0,0,20000,25000,11,7289,65,0,0,0,0,2,0,0,0,0,0,0,0,"Gordunni Warlock - Combat CMC - Cast 'Shrink'");

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=5237;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(5237,0,0,0,0,0,100,0,0,0,4000,4000,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Gordunni Ogre Mage - Combat CMC - Cast 'Lightning Bolt'"),
(5237,0,1,0,2,0,100,1,0,30,0,0,11,6742,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gordunni Ogre Mage - Between 0-30% Health - Cast 'Bloodlust' (No Repeat)");
