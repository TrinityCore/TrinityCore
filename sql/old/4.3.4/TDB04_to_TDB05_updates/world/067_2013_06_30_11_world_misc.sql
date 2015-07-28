-- Add SAI support for Silas Darkmoon
SET @SILAS := 14823;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@SILAS;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@SILAS;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@SILAS,0,0,0,1,0,100,0,60000,60000,60000,60000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Silas Darkmoon - OOC - Say 0');

-- Text for Silas Darkmoon
DELETE FROM `creature_text` WHERE `entry` IN (@SILAS);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@SILAS,0,0,'Everyone enjoying themselves so far?  That''s great!  Welcome to the Darkmoon Faire, the greatest show on all of Azeroth!  Make sure that you speak with Yebb and his friends here while you''re taking in Neblegear''s Darkmoon Zoo Bizarre.',12,0,100,0,0,0,'Silas Darkmoon'),
(@SILAS,0,1,'We''re back and better than ever!  It''s the Darkmoon Faire friend, and it''s your lucky day! Sparing no expense, we''ve gathered wonders and treats from around the world for your delight.  Whether you''re young or old, rich or poor, the Darkmoon Faire has it all!  Be sure to turn in your Darkmoon Faire Prize Tickets to Gelvas Grimegate, and choose from several exotic and wondrous prizes!',12,0,100,0,0,0,'Silas Darkmoon'),
(@SILAS,0,2,'Come one, come all.  Welcome to the Darkmoon Faire!  Don''t be shy.  Step right up to Lhara and buy yourself an exotic artifact from far off lands.  If you''re one of the lucky few who have found Darkmoon Cards, have a word with Professor Paleo.  Hungry?  Thirsty?  You''re in luck!  Refreshments are available right here from Sylannia and Stamp.  I recommend the Darkmoon Special Reserve to wash down some Red Hot Wings.  And if the future is what you seek, then run, don''t walk, to speak with Sayge.',12,0,100,0,0,0,'Silas Darkmoon'),
(@SILAS,0,3,'Welcome one and all to the Darkmoon Faire, the greatest event in all the world!  We have it all... delicious food, strong drink, exotic artifacts, fortunes read, amazing prizes and excitement without end!  Don''t forget to turn in your Darkmoon Faire Prize Tickets to Gelvas Grimegate!  All it takes is five or more and you''re on your way to the most wondrous prizes on all of Azeroth.  Everybody is a winner!',12,0,100,0,0,0,'Silas Darkmoon');

UPDATE `waypoint_data` SET `action`=0 WHERE `id`=1376660;
DELETE FROM `db_script_string` WHERE `entry` BETWEEN 2000000004 AND 2000000007;
DELETE FROM `waypoint_scripts` WHERE `dataint` BETWEEN 2000000004 AND 2000000007;
