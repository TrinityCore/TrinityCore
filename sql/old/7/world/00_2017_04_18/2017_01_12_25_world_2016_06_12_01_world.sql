-- 
-- Add missing Emote & Say lines for NPC entry 20098(Jane), 20100(Jessel) and 20244(Nova)
SET @Jane   := 20098;
SET @Jessel := 20100;
SET @Nova   := 20244;

-- Set random movement around a new set spawndist for Nova
UPDATE `creature` SET `position_x`= 10512.0615,`position_y`= -6499.652,`position_z`= 3.6119,`orientation`= 0.855017,`spawndist`= 8,`MovementType`= 1 WHERE `id`= @Nova;
UPDATE `creature` SET `position_x`= 10512.0615,`position_y`= -6499.652,`position_z`= 3.6119,`orientation`= 0.855017,`spawndist`= 8,`MovementType`= 1 WHERE `id`= 20246;
UPDATE `creature` SET `MovementType`=1, `spawndist`=8 WHERE `id` IN (20098,20247,20246);

DELETE FROM `creature_text` WHERE `entry`= @Jane   AND `groupid`= 1 AND `id`= 0;
DELETE FROM `creature_text` WHERE `entry`= @Jessel AND `groupid`= 2 AND `id`= 0;
DELETE FROM `creature_text` WHERE `entry`= @Nova   AND `groupid` IN (0,1) AND `id` IN (0,1,2,3);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@Jessel,2,0,'%s wakes up, startled.',                                 16,10,100,0,0,0,17595,0,'Jessel'),
(@Jane,  1,0,'%s resumes playing on the beach.',                       16,10,100,0,0,0,17599,0,'Jane'),
(@Nova,  1,0,'I think I can see the Sunwell from here!',               12,10,100,1,0,0,17918,0,'Nova'),
(@Nova,  1,1,'Can you really hear the ocean from one of these shells?',12,10,100,1,0,0,17919,0,'Nova'),
(@Nova,  1,2,'Oooh! Look, a shiny one!',                               12,10,100,1,0,0,17920,0,'Nova'),
(@Nova,  1,3,'Jane will love this one!',                               12,10,100,1,0,0,17921,0,'Nova'),
(@Nova,  0,0,'%s picks up a sea shell.',                               16,10,100,0,0,0,17922,0,'Nova'),
(@Nova,  0,1,'%s holds a sea shell up to her ear.',                    16,10,100,0,0,0,17923,0,'Nova'),
(@Nova,  0,2,'%s shakes the dirt loose from the shell.',               16,10,100,0,0,0,17924,0,'Nova');

-- Add SmartAI script lines for Jane, Jessel and Nova
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`= @Nova;
DELETE FROM `smart_scripts` WHERE `entryorguid`= @Jane   AND `source_type`= 0;
DELETE FROM `smart_scripts` WHERE `entryorguid`= @Jessel AND `source_type`= 0;
DELETE FROM `smart_scripts` WHERE `entryorguid`= @Jessel*100 AND `source_type`= 9;
DELETE FROM `smart_scripts` WHERE `entryorguid`= @Nova   AND `source_type`= 0 AND `id` IN (0,1);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Nova,  0,0,0,1,0,100,0, 10000, 10000, 25000, 60000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Nova - Out Of Combat - Say Line'),
(@Nova,  0,1,0,1,0,100,0, 11000, 11000, 25000, 60000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Nova - Out Of Combat - Say Line'),
(20100, 0, 0, 0, 1, 0, 100, 0, 0, 0, 300000, 300000, 80, 2010000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Jessel - Ooc - Action list"),
(2010000, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 50917, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Jessel - Action list - Cast sleep aura"),
(2010000, 9, 1, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 28, 50917, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Jessel - Action list - rrmove sleep aura"),
(2010000, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Jessel - Action list - Say Line 2"),
(2010000, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 90, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Jessel - Action list - Set bytes 1"),
(2010000, 9, 4, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Jessel - Action list - Say Line 0"),
(2010000, 9, 5, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, @Jane, 50, 0, 0, 0, 0, 0, "Jessel - Action list - Say Line 0"),
(2010000, 9, 6, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Jessel - Action list - Say Line 1"),
(2010000, 9, 7, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, @Jane, 50, 0, 0, 0, 0, 0, "Jessel - Action list - Say Line 1"),
(2010000, 9, 8, 6, 0, 0, 100, 0, 3000, 3000, 0, 0, 91, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Jessel - Action list - remove bytes 1"),
(2010000, 9, 9, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 50917, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Jessel - Action list - Cast sleep");
