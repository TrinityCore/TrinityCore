DELETE FROM `areatrigger_scripts` WHERE `entry` IN (5082,5083,5084);
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(5082,'SmartTrigger'),
(5083,'SmartTrigger'),
(5084,'SmartTrigger');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (5082,5083,5084) AND `source_type`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(5082,2,0,1,46,0,100,0,5082,0,0,0,45,1,1,0,0,0,0,10,126866,15214,0,0,0,0,0,"On Trigger - Set Data"),
(5083,2,0,1,46,0,100,0,5083,0,0,0,45,1,2,0,0,0,0,10,126866,15214,0,0,0,0,0,"On Trigger - Set Data"),
(5084,2,0,1,46,0,100,0,5084,0,0,0,45,1,3,0,0,0,0,10,126866,15214,0,0,0,0,0,"On Trigger - Set Data");

DELETE FROM `smart_scripts` WHERE `entryorguid` =-126866 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-126866,0,0,1,38,0,100,0,1,1,60000,60000,45,1,1,0,0,0,0,10,126860,28965,0,0,0,0,0,"Invisible Stalker - On Data Set - Set Data"),
(-126866,0,1,2,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,126848,28965,0,0,0,0,0,"Invisible Stalker - Linked with Previous Event - Set Data"),
(-126866,0,2,3,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,126851,28965,0,0,0,0,0,"Invisible Stalker - Linked with Previous Event - Set Data"),
(-126866,0,3,4,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,126836,28961,0,0,0,0,0,"Invisible Stalker - Linked with Previous Event - Set Data"),
(-126866,0,4,5,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,126847,28961,0,0,0,0,0,"Invisible Stalker - Linked with Previous Event - Set Data"),
(-126866,0,5,6,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,126846,28961,0,0,0,0,0,"Invisible Stalker - Linked with Previous Event - Set Data"),
(-126866,0,6,7,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,126844,28961,0,0,0,0,0,"Invisible Stalker - Linked with Previous Event - Set Data"),
(-126866,0,7,28,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,126845,28961,0,0,0,0,0,"Invisible Stalker - Linked with Previous Event - Set Data"),
(-126866,0,8,9,38,0,100,0,1,2,60000,60000,45,1,1,0,0,0,0,10,126837,28961,0,0,0,0,0,"Invisible Stalker - On Data Set - Set Data"),
(-126866,0,9,10,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,126852,28965,0,0,0,0,0,"Invisible Stalker - Linked with Previous Event - Set Data"),
(-126866,0,10,11,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,126861,28965,0,0,0,0,0,"Invisible Stalker - Linked with Previous Event - Set Data"),
(-126866,0,11,12,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,126838,28961,0,0,0,0,0,"Invisible Stalker - Linked with Previous Event - Set Data"),
(-126866,0,12,13,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,126843,28961,0,0,0,0,0,"Invisible Stalker - Linked with Previous Event - Set Data"),
(-126866,0,13,14,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,126841,28961,0,0,0,0,0,"Invisible Stalker - Linked with Previous Event - Set Data"),
(-126866,0,14,15,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,126849,28965,0,0,0,0,0,"Invisible Stalker - Linked with Previous Event - Set Data"),
(-126866,0,15,29,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,126862,28965,0,0,0,0,0,"Invisible Stalker - Linked with Previous Event - Set Data"),
(-126866,0,16,17,38,0,100,0,1,3,60000,60000,45,1,1,0,0,0,0,10,126857,28965,0,0,0,0,0,"Invisible Stalker - On Data Set - Set Data"),
(-126866,0,17,18,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,126855,28965,0,0,0,0,0,"Invisible Stalker - Linked with Previous Event - Set Data"),
(-126866,0,18,19,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,126859,28965,0,0,0,0,0,"Invisible Stalker - Linked with Previous Event - Set Data"),
(-126866,0,19,20,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,126854,28965,0,0,0,0,0,"Invisible Stalker - Linked with Previous Event - Set Data"),
(-126866,0,20,21,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,126853,28965,0,0,0,0,0,"Invisible Stalker - Linked with Previous Event - Set Data"),
(-126866,0,21,22,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,126858,28965,0,0,0,0,0,"Invisible Stalker - Linked with Previous Event - Set Data"),
(-126866,0,22,23,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,126856,28965,0,0,0,0,0,"Invisible Stalker - Linked with Previous Event - Set Data"),
(-126866,0,23,24,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,126850,28965,0,0,0,0,0,"Invisible Stalker - Linked with Previous Event - Set Data"),
(-126866,0,24,25,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,126835,28961,0,0,0,0,0,"Invisible Stalker - Linked with Previous Event - Set Data"),
(-126866,0,25,26,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,126840,28961,0,0,0,0,0,"Invisible Stalker - Linked with Previous Event - Set Data"),
(-126866,0,26,27,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,126839,28961,0,0,0,0,0,"Invisible Stalker - Linked with Previous Event - Set Data"),
(-126866,0,27,0,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,126842,28961,0,0,0,0,0,"Invisible Stalker - Linked with Previous Event - Set Data");

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (28961,28965) AND `id`>3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(28961, 0, 4, 0, 4, 0, 100, 0, 0, 0, 0, 0, 28, 16245, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Titanium Siegebreaker - On Aggro - Remove Freeze Animation'),
(28965, 0, 4, 0, 4, 0, 100, 0, 0, 0, 0, 0, 28, 16245, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Titanium Thunderer - On Aggro - Remove Freeze Animation'),
(28961, 0, 5, 8,38, 0, 35, 0, 1, 1, 0, 0, 19, 33555200, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Titanium Siegebreaker - On Data Set - Remove Unattackable Flags'),
(28965, 0, 5, 10,38, 0, 35, 0, 1, 1, 0, 0, 19, 33555200, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Titanium Thunderer - On Data Set - Remove Unattackable Flags'),
(28961, 0, 6, 0, 2, 0, 100, 1, 0, 20, 0, 0, 11, 19134, 2, 0, 0, 0, 0, 16, 0, 0, 0, 0, 0, 0, 0, 'Titanium Siegebreaker - On Death - Cast Frightening Shout'),
(28961, 0, 7, 0, 9, 0, 100, 0, 0, 5, 10000, 15000, 11, 52890, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Titanium Siegebreaker - On Range - Cast Penetrating Strike'),
(28965, 0, 6, 0,13, 0, 100, 3, 45000, 60000, 0, 0, 11, 52885, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Titanium Thunderer - On Target Casting - Cast Deadly Throw'),
(28965, 0, 7, 0,13, 0, 100, 5, 45000, 60000, 0, 0, 11, 59180, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Titanium Thunderer - On Target Casting - Cast Deadly Throw (Heroic)'),
(28965, 0, 8, 0,0, 0, 100, 2, 0, 5000, 7000, 15000, 11, 52904, 2, 0, 0, 0, 0,5, 0, 0, 0, 0, 0, 0, 0, 'Titanium Thunderer - IC - Cast Throw'),
(28965, 0, 9, 0,0, 0, 100, 4, 0, 5000, 7000, 15000, 11, 59179, 2, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Titanium Thunderer - IC - Cast Throw (Heroic)'),
(28961, 0, 8, 0,61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 80, 0, 0, 0, 0, 0, 0, 'Titanium Siegebreaker - Linked with Previous Event - Attack closest player'),
(28965, 0, 10, 0,61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21,80, 0, 0, 0, 0, 0, 0, 'Titanium Thunderer - Linked with Previous Event - Attack closest player');
