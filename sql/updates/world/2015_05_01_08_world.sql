SET @GUID         :=5625; -- 1 GOB guid set by TC
SET @cover        := 164819;
SET @Portrait     :=164825;
SET @Assemblage   :=8905;
SET @ReliCoffer   :=174564;
SET @ReliCoffer2  :=174563;
SET @ReliCoffer3  :=174562;
SET @ReliCoffer4  :=174561;
SET @ReliCoffer5  :=174560;
SET @ReliCoffer6  :=174559;
SET @ReliCoffer7  :=174554;
SET @ReliCoffer8  :=174555;
SET @ReliCoffer9  :=174556;
SET @ReliCoffer10 :=174557;
SET @ReliCoffer11 :=174566;
SET @ReliCoffer12 :=174558;
SET @DOOM         :=9476;
SET @Secret       :=174553; 
SET @Dark         :=174565;

DELETE FROM `gameobject` WHERE `guid` IN (@GUID);
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(@GUID,165554,230,1,1, 802.907, -356.401, -48.9423,0,0,0,-0.382683, 0.92388, 7200, 100, 1);

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@Assemblage, @DOOM);
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry` IN (@cover, @Dark, @Portrait, @ReliCoffer, @ReliCoffer2, @ReliCoffer3, @ReliCoffer4, @ReliCoffer5, @ReliCoffer6, @ReliCoffer7, @ReliCoffer8, @ReliCoffer9, @ReliCoffer10, @ReliCoffer11, @ReliCoffer12, @Secret);

DELETE FROM `smart_scripts` WHERE `entryorguid`=@Assemblage AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=-46610 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Assemblage*100 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Assemblage*100+1 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@DOOM AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@cover, @Dark, @Secret, @ReliCoffer, @ReliCoffer2, @ReliCoffer3, @ReliCoffer4, @ReliCoffer5, @ReliCoffer6, @ReliCoffer7, @ReliCoffer8, @ReliCoffer9, @ReliCoffer10, @ReliCoffer11, @ReliCoffer12) AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@cover, 1, 0, 0, 64, 0, 100, 0, 0, 0, 0, 0, 106, 16, 0, 0, 0, 0, 0, 20, @Portrait, 5, 0, 0, 0, 0, 0, 'Cover - On gossip hello - Remove flags'),
(@ReliCoffer, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, @Assemblage, 30, 0, 0, 0, 0, 0, 'ReliCoffer - On State 2 - Set data'), 
(@ReliCoffer, 1, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 106, 16, 0, 0, 0, 0, 0, 20, 160836, 10, 0, 0, 0, 0, 0, 'ReliCoffer - On State 2 - Remove flags'), 
(@ReliCoffer2, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, @Assemblage, 30, 0, 0, 0, 0, 0, 'ReliCoffer - On State 2  - Set data'),
(@ReliCoffer2, 1, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 106, 16, 0, 0, 0, 0, 0, 20, 160836, 10, 0, 0, 0, 0, 0, 'ReliCoffer - On State 2 - Remove flags'), 
(@ReliCoffer3, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, @Assemblage, 30, 0, 0, 0, 0, 0, 'ReliCoffer - On State 2  - Set data'),
(@ReliCoffer3, 1, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 106, 16, 0, 0, 0, 0, 0, 20, 160836, 10, 0, 0, 0, 0, 0, 'ReliCoffer - On State 2 - Remove flags'), 
(@ReliCoffer4, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, @Assemblage, 30, 0, 0, 0, 0, 0, 'ReliCoffer - On State 2  - Set data'),
(@ReliCoffer4, 1, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 106, 16, 0, 0, 0, 0, 0, 20, 160836, 10, 0, 0, 0, 0, 0, 'ReliCoffer - On State 2 - Remove flags'), 
(@ReliCoffer5, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, @Assemblage, 30, 0, 0, 0, 0, 0, 'ReliCoffer - On State 2  - Set data'),
(@ReliCoffer5, 1, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 106, 16, 0, 0, 0, 0, 0, 20, 160836, 10, 0, 0, 0, 0, 0, 'ReliCoffer - On State 2 - Remove flags'), 
(@ReliCoffer6, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, @Assemblage, 30, 0, 0, 0, 0, 0, 'ReliCoffer - On State 2  - Set data'),
(@ReliCoffer6, 1, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 106, 16, 0, 0, 0, 0, 0, 20, 160836, 10, 0, 0, 0, 0, 0, 'ReliCoffer - On State 2 - Remove flags'), 
(@ReliCoffer7, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, @Assemblage, 30, 0, 0, 0, 0, 0, 'ReliCoffer - On State 2  - Set data'),
(@ReliCoffer7, 1, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 106, 16, 0, 0, 0, 0, 0, 20, 160836, 10, 0, 0, 0, 0, 0, 'ReliCoffer - On State 2 - Remove flags'), 
(@ReliCoffer8, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, @Assemblage, 30, 0, 0, 0, 0, 0, 'ReliCoffer - On State 2  - Set data'),
(@ReliCoffer8, 1, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 106, 16, 0, 0, 0, 0, 0, 20, 160836, 10, 0, 0, 0, 0, 0, 'ReliCoffer - On State 2 - Remove flags'), 
(@ReliCoffer9, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, @Assemblage, 30, 0, 0, 0, 0, 0, 'ReliCoffer - On State 2  - Set data'),
(@ReliCoffer9, 1, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 106, 16, 0, 0, 0, 0, 0, 20, 160836, 10, 0, 0, 0, 0, 0, 'ReliCoffer - On State 2 - Remove flags'), 
(@ReliCoffer10, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, @Assemblage, 30, 0, 0, 0, 0, 0, 'ReliCoffer - On State 2  - Set data'),
(@ReliCoffer10, 1, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 106, 16, 0, 0, 0, 0, 0, 20, 160836, 10, 0, 0, 0, 0, 0, 'ReliCoffer - On State 2 - Remove flags'), 
(@ReliCoffer11, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, @Assemblage, 30, 0, 0, 0, 0, 0, 'ReliCoffer - On State 2  - Set data'),
(@ReliCoffer11, 1, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 106, 16, 0, 0, 0, 0, 0, 20, 160836, 10, 0, 0, 0, 0, 0, 'ReliCoffer - On State 2 - Remove flags'), 
(@ReliCoffer12, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, @Assemblage, 30, 0, 0, 0, 0, 0, 'ReliCoffer - On State 2  - Set data'),
(@ReliCoffer12, 1, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 106, 16, 0, 0, 0, 0, 0, 20, 160836, 10, 0, 0, 0, 0, 0, 'ReliCoffer - On State 2 - Remove flags'), 
(@Assemblage, 0, 0, 0, 38, 0, 100, 0, 0, 1, 0, 0, 63, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Assemblage - On data set - Increment Counter 1'), -- the counter nbr 1 is incremented here
(@Assemblage, 0, 1, 2, 11, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Assemblage - On Respawn - Set passif'),
(@Assemblage, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 18, 33554432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Assemblage - On Respawn - Add unit_flag'),
(@Assemblage, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Assemblage - On Respawn - SET PHASE EVENT 0'),
(@Assemblage, 0, 4, 0, 77, 0, 100, 1, 1, 12, 0, 0, 80, @Assemblage*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Assemblage - On counter1=12 - Actionlist'),  -- event triggred when the counter 1= 12
(@Assemblage*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 19, 33554432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Assemblage - Actionlist - Remmove unit flag'),
(@Assemblage*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Assemblage - Actionlist - react agressif'),
(@Assemblage*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Assemblage - Actionlist - SET PHASE EVENT 0'),
(@Assemblage, 0, 5, 0, 0, 0, 100, 0, 4000, 4000, 8000, 8000, 11, 15621, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Assemblage - IC - Cast'),
(@Secret, 1, 0, 0, 70, 0, 100, 0, 2, 0, 0, 0, 106, 16, 0, 0, 0, 0, 0, 20, 161495, 10, 0, 0, 0, 0, 0, 'Secret - On State 2  - Remove flags'),
(@Dark, 1, 0, 0, 70, 0, 100, 0, 2, 0, 0, 0, 106, 16, 0, 0, 0, 0, 0, 20, 160845, 10, 0, 0, 0, 0, 0, '@Dark - On State 2  - Remove flags'),
(-46610, 0, 0, 0, 38, 0, 100, 0, 0, 1, 0, 0, 63, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Assemblage - On data set - Increment Counter1'), -- the counter nbr 1 is incremented here
(-46610, 0, 1, 2, 11, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Assemblage - On Respawn - Set passif'),
(-46610, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 18, 33554432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Assemblage - On Respawn - Add unit_flag'),
(-46610, 0, 4, 0, 77, 0, 100, 1, 1, 12, 0, 0, 80, @Assemblage*100+1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Assemblage - On counter1=12 - Actionlist'), -- event triggred when the counter 1= 12
(@Assemblage*100+1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 19, 33554432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Assemblage - Actionlist - Remmove unit flag'),
(@Assemblage*100+1, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Assemblage - Actionlist - react agressif'),
(@Assemblage*100+1, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, @DOOM, 7, 0, 0, 0, 0, 8, 0, 0, 0, 813.737915, -347.550354, -50.578030, 0.670515, 'Assemblage - Actionlist - Summon'),
(@Assemblage*100+1, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Assemblage - Actionlist - SET PHASE EVENT 0'),
(-46610, 0, 5, 0, 0, 0, 100, 0, 4000, 4000, 8000, 8000, 11, 15621, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Assemblage - IC - Cast'),
(@DOOM, 0, 0, 0, 0, 0, 100, 0, 4000, 4000, 8000, 8000, 11, 11971, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'DOOM - IC - Cast'),
(@DOOM, 0, 1, 0, 0, 0, 100, 0, 10000, 10000, 14000, 14000, 11, 15504, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'DOOM - IC - Cast'),
(@DOOM, 0, 2, 0, 6, 0, 100, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 20, 174553, 70, 0, 0, 0, 0, 0, 'DOOM - On death - Activate gob'),
(@DOOM, 0, 3, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'DOOM - On aggro - Talk');

DELETE FROM `creature_text` WHERE `entry`IN (@DOOM);   
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextID`) VALUES
(@DOOM,0,0,"What are you doing?  Intruders!!",14,0,100,0,0,0,'Watchman Doomgrip', 4962);
