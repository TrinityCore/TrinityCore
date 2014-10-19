-- Myralion Sunblaze
DELETE FROM `smart_scripts` WHERE `entryorguid`=36642 AND `source_type`=0;
INSERT INTO `smart_scripts`(`entryorguid`,`id`,`link`,`event_type`,`event_param1`,`action_type`,`action_param1`,`action_param2`,`target_type`,`comment`) VALUES 
(36642,0,1,20,24558,83,2,0,1,'Myralion Sunblaze - Remove gossip and quest giver flag on quest complete'),
(36642,1,0,61,0,53,0,36642,1,'Myralion Sunblaze - Start WP on quest complete'),
(36642,2,3,40,1,54,10000,0,1,'Myralion Sunblaze - Stop WP on point reached'), -- SMART_ACTION_WP_STOP would break the following SMART_EVENT_WAYPOINT_REACHED.
(36642,3,0,61,0,80,3664200,0,1,'Myralion Sunblaze - Start timed event on point reached'),
(36642,4,0,38,50,43,0,28889,1,'Myralion Sunblaze - Mount on data set'),
(36642,5,6,40,2,1,3,0,1,'Myralion Sunblaze - Say 3 event on home reached'),
(36642,6,7,61,0,66,0,0,1,'Myralion Sunblaze - restore orientation event on home reached'),
(36642,7,0,61,0,81,2,0,1,'Myralion Sunblaze - restore npc flags event on home reached');

-- Caladis Brightspear
DELETE FROM `smart_scripts` WHERE `entryorguid`=36624 AND `source_type`=0;
INSERT INTO `smart_scripts`(`entryorguid`,`id`,`link`,`event_type`,`event_param1`,`action_type`,`action_param1`,`action_param2`,`target_type`,`comment`) VALUES 
(36624,0,1,20,24454,83,2,0,1,'Caladis Brightspear - Remove gossip and quest giver flag on quest complete'),
(36624,1,0,61,0,53,0,36624,1,'Caladis Brightspear - Start WP on quest complete'),
(36624,2,3,40,1,54,10000,0,1,'Caladis Brightspear - Stop WP on point reached'), -- SMART_ACTION_WP_STOP would break the following SMART_EVENT_WAYPOINT_REACHED.
(36624,3,0,61,0,80,3662400,0,1,'Caladis Brightspear - Start timed event on point reached'),
(36624,4,0,38,50,43,0,28888,1,'Caladis Brightspear - Mount on data set'),
(36624,5,6,40,2,1,3,0,1,'Caladis Brightspear - Say 3 event on home reached'),
(36624,6,7,61,0,66,0,0,1,'Caladis Brightspear - restore orientation event on home reached'),
(36624,7,0,61,0,81,2,0,1,'Caladis Brightspear - restore npc flags event on home reached');
