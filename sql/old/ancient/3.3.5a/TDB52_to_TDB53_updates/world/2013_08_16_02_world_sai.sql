-- Digging Through Bones (10922)
SET @LETOLL       := 22458;
SET @RESEARCHER   := 22464;
SET @B_SIFTER     := 22466;
SET @SG_TRIGGER   := 22457;
SET @RESEARCHER1  := 78837;

-- Faulty spawn, it needs to be spawned by a script.
DELETE FROM `creature` WHERE `guid`=85488;

DELETE FROM `creature_text` WHERE `entry`=@LETOLL;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@LETOLL,0,0,"'Aright, listen up! Form a circle around me and move out!",12,0,100,0,0,0,''),
(@LETOLL,1,0,"Aright, $R, just keep us safe from harm while we work. We'll pay you when we return.",12,0,100,0,0,0,''),
(@LETOLL,2,0,"The dig site is just north of here.",12,0,100,0,0,0,''),
(@LETOLL,3,0,"We're here! Start diggin'!",12,0,100,0,0,0,''),
(@LETOLL,4,0,"I think there's somethin' buried here, beneath the sand!",12,0,100,396,0,0,''),
(@LETOLL,5,0,"Almost got it!",12,0,100,396,0,0,''),
(@LETOLL,6,0,"By Brann's brittle bananas! What is it?! It... It looks like a drum.",12,0,100,396,0,0,''),
(@LETOLL,7,0,"Have ye gone mad? You expect me to leave behind a drum without first beatin' on it? Not this son of Ironforge! No sir!",12,0,100,0,0,0,''),
(@LETOLL,8,0,"Shut yer yaps! I'm gonna bang on this drum and that's that!",12,0,100,0,0,0,''),
(@LETOLL,9,0,"IN YOUR FACE! I told you there was somethin' here!",12,0,100,0,0,0,''),
(@LETOLL,10,0,"Don't just stand there! Help him out!",12,0,100,0,0,0,''),
(@LETOLL,11,0,"You've been a tremendous help, $R! Let's get out of here before more of those things show up! I'll let Dwarfowitz know you did the job asked of ya' admirably.",12,0,100,0,0,0,'');

DELETE FROM `creature_text` WHERE `entry`=@RESEARCHER;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@RESEARCHER,0,0,"Wow... a drum.",12,0,100,0,0,0,''),
(@RESEARCHER,1,0,"This discovery will surely rock the foundation of modern archaeology.",12,0,100,0,0,0,''),
(@RESEARCHER,2,0,"Yea, great. Can we leave now? This desert is giving me hives.",12,0,100,0,0,0,''),
(@RESEARCHER,3,0,"This reminds me of that one time where you made us search Silithus for evidence of sand gnomes.",12,0,100,0,0,0,''),
(@RESEARCHER,4,0,"Or that time when you told us that you'd discovered the cure for the plague of the 20th century. What is that even? 20th century?",12,0,100,0,0,0,''),
(@RESEARCHER,5,0,"I don't think it can top the one time where he told us that he'd heard that Arthas's cousin's skeleton was frozen beneath a glacier in Winterspring. I'll never forgive you for that one, Letoll. I mean honestly... Arthas's cousin?",12,0,100,0,0,0,''),
(@RESEARCHER,6,0,"I dunno. It can't possibly beat the time he tried to convince us that we're all actually a figment of some being's imagination and that they only use us for their own personal amusement. That went over well during dinner with the family.",12,0,100,0,0,0,''),
(@RESEARCHER,7,0,"Say, do you guys hear that?",12,0,100,0,0,0,'');

DELETE FROM `waypoints` WHERE `entry` IN (@LETOLL,@RESEARCHER,@LETOLL*100);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@LETOLL,1,-3728.1,5385.5,-3.41,''),
(@LETOLL,2,-3735.9,5392.8,-4.8,''),
(@LETOLL,3,-3729.7,5381,-4.9,''),
(@LETOLL,4,-3704.6, 5372.74, -9.33,''),
(@LETOLL,5,-3704.8,5374.7,-8.9,''),
(@LETOLL,6,-3623.2,5403.2,-11.5,''),
(@LETOLL,7,-3554.6,5455.2,-11.3,''),
(@LETOLL,8,-3557.7,5468.9,-8.1,''),
(@LETOLL,9,-3548.9,5458.3,-12.3,''),
(@RESEARCHER,1,-3725.1,5381.9,-4.4,''),
(@RESEARCHER,2,-3735.7,5390.7,-5.7,''),
(@RESEARCHER,3,-3728.4,5384.1,-3.4,''),
(@RESEARCHER,4,-3703.1,5371.4,-10.1,''),
(@RESEARCHER,5,-3619.6,5400.8,-12.1,''),
(@RESEARCHER,6,-3554.2,5451.1,-11.8,''),
(@RESEARCHER,7,-3563.1,5462.8,-6.5,''),
(@RESEARCHER,8,-3551.1,5454,-11.9,'');


UPDATE `creature_template` SET `AIname`='SmartAI' WHERE `entry` IN (@LETOLL,@RESEARCHER,@B_SIFTER);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (@LETOLL,-@RESEARCHER1,@B_SIFTER);
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid` IN (@LETOLL*100+2,@LETOLL*100+1,@LETOLL*100,@RESEARCHER*100);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@LETOLL,0,0,1,19,0,100,0,10922,0,0,0,53,0,@LETOLL,0,0,0,0,1,0,0,0,0,0,0,0,'On quest accept - Start WP'),
(@LETOLL,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say line 0'),
(@LETOLL,0,2,3,40,0,100,0,1,@LETOLL,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,'On WP reached - Pause WP'),
(@LETOLL,0,3,10,61,0,100,0,0,0,0,0,80,@LETOLL*100,0,0,0,0,0,1,0,0,0,0,0,0,0,'On WP reached - Start Timed Event'),
(@LETOLL,0,4,5,40,0,100,0,8,@LETOLL,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0,'On WP reached - Set emote digging'),
(@LETOLL,0,5,0,61,0,100,0,0,0,0,0,45,0,2,0,0,0,0,10,78837,@RESEARCHER,0,0,0,0,0,'On Link - Set Data'),
(@LETOLL,0,6,7,40,0,100,0,9,@LETOLL,0,0,17,467,0,0,0,0,0,1,0,0,0,0,0,0,0,'On WP reached - Set emote digging'),
(@LETOLL,0,7,8,61,0,100,0,0,0,0,0,45,0,3,0,0,0,0,10,78837,@RESEARCHER,0,0,0,0,0,'On Link - Set Data'),
(@LETOLL,0,8,0,61,0,100,0,0,0,0,0,80,@LETOLL*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,'On WP reached - Start Timed Event'),
(@LETOLL,0,9,0,40,0,100,0,7,@LETOLL,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'On WP reached - Say line 3'),
(@LETOLL,0,10,0,61,0,100,0,0,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set npc flag'),
(@LETOLL,0,11,0,40,0,100,0,7,@LETOLL,0,0,54,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,'On WP reached - Pause WP'),
--
(-@RESEARCHER1,0,0,0,38,0,100,0,0,1,0,0,53,0,@RESEARCHER,0,0,0,0,1,0,0,0,0,0,0,0,'On Data - Start WP'),
(-@RESEARCHER1,0,1,2,40,0,100,0,6,@RESEARCHER,0,0,54,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,' On Data - Start WP'),
(-@RESEARCHER1,0,2,0,61,0,100,0,0,0,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Start digging'),
(-@RESEARCHER1,0,3,4,40,0,100,0,7,@RESEARCHER,0,0,54,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Pause WP'),
(-@RESEARCHER1,0,4,0,61,0,100,0,0,0,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0,'On link - Start digging'),
(-@RESEARCHER1,0,5,6,40,0,100,0,8,@RESEARCHER,0,0,54,35500,0,0,0,0,0,1,0,0,0,0,0,0,0,'On WP reached - Pause WP'),
(-@RESEARCHER1,0,6,0,61,0,100,0,0,0,0,0,80,@RESEARCHER*100,0,0,0,0,0,1,0,0,0,0,0,0,0,'ON WP reached - Start Timed Event'),
(-@RESEARCHER1,0,7,0,11,0,100,0,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'On Respawn - Set Emote State none'),
-- 
(@LETOLL*100,9,0,0,0,0,100,0,3000,3000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'On Script - Say line 1'),
(@LETOLL*100,9,1,0,0,0,100,0,7000,7000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'On Script - Say line 2'),
(@LETOLL*100,9,2,0,0,0,100,0,500,500,0,0,45,0,1,0,0,0,0,10,78837,@RESEARCHER,0,0,0,0,0,'On Script - Set Data'),
--
(@LETOLL*100+1,9,0,0,0,0,100,0,0,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,'On Script - Say line 4'),
(@LETOLL*100+1,9,1,0,0,0,100,0,2000,2000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,'On Script - Say line 5'),
(@LETOLL*100+1,9,2,0,0,0,100,0,5000,5000,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,'On Script - Say line 6'),
--
(@RESEARCHER*100,9,0,0,0,0,100,0,5000,5000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'On Script - Say line 0'),
(@RESEARCHER*100,9,1,0,0,0,100,0,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'On Script - Set emote state none'),
(@RESEARCHER*100,9,2,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'On Script - Say line 1'),
(@RESEARCHER*100,9,3,0,0,0,100,0,7000,7000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'On Script - Say line 2'),
--
(@LETOLL*100+1,9,3,0,0,0,100,0,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'On Script - Set emote state none'),
(@LETOLL*100+1,9,4,0,0,0,100,0,22000,22000,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,'On Script - Say line 7'),
--
(@RESEARCHER*100,9,4,0,0,0,100,0,12000,12000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'On Script - Say line 3'),
(@RESEARCHER*100,9,5,0,0,0,100,0,6000,6000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,'On Script - Say line 4'),
(@RESEARCHER*100,9,6,0,0,0,100,0,6000,6000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,'On Script - Say line 5'),
(@RESEARCHER*100,9,7,0,0,0,100,0,17000,17000,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,'On Script - Say line 6'),
--
(@LETOLL*100+1,9,5,0,0,0,100,0,34000,34000,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'On Script - Say line 8'),
--
(@RESEARCHER*100,9,8,0,0,0,100,0,6000,6000,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,'On Script - Say line 7'),
(@RESEARCHER*100,9,9,0,0,0,100,0,15000,15000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'On Script - Despawn'),
--
(@LETOLL*100+1,9,6,0,0,0,100,0,7000,7000,0,0,1,9,0,0,0,0,0,1,0,0,0,0,0,0,0,'On Script - Say line 9'),
(@LETOLL*100+1,9,7,0,0,0,100,0,500,500,0,0,12,@B_SIFTER,1,60000,0,0,0,8,0,0,0,-3550,5456.1,-12.3,0,'On Script - Summon worm'),
(@LETOLL*100+1,9,8,0,0,0,100,0,8000,8000,0,0,1,10,0,0,0,0,0,1,0,0,0,0,0,0,0,'On Script - Say line 10'),
(@LETOLL*100+1,9,9,0,0,0,100,0,8000,8000,0,0,1,11,0,0,0,0,0,1,0,0,0,0,0,0,0,'On Script - Say line 11'),
(@LETOLL*100+1,9,10,0,0,0,100,0,6000,6000,0,0,15,10922,0,0,0,0,0,18,20,0,0,0,0,0,0,'On Script - Give quest credit'),
(@LETOLL*100+1,9,11,0,0,0,100,0,3000,3000,0,0,81,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'On Script - Restore npcflags'),
(@LETOLL*100+1,9,12,0,0,0,100,0,1000,1000,0,0,78,0,0,0,0,0,0,1,0,0,0,0,0,0,0,' On Script - Stop Script'),
(@LETOLL*100+1,9,13,0,0,0,100,0,16000,16000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'On Script - Despawn'),
--
(@B_SIFTER,0,0,0,0,0,100,0,2000,6000,12000,17000,11,31747,0,0,0,0,0,2,0,0,0,0,0,0,0,'- IC - Cast Poison'),
(@B_SIFTER,0,1,0,0,0,100,0,5000,25000,35000,40000,11,32738,0,0,0,0,0,2,0,0,0,0,0,0,0,'- IC - Cast Bore');
