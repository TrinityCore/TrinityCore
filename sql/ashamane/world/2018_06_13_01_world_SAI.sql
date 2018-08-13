SET @SKITTERING := 111350;
SET @CREATURE := 111370;
SET @NIGHTMARE := 111398;
SET @POUNDER := 111405;
SET @DARK := 111413;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@SKITTERING;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@CREATURE;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@NIGHTMARE;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@POUNDER;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@DARK;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@SKITTERING;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@CREATURE;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@NIGHTMARE;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@POUNDER;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@DARK;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@SKITTERING,0,0,0,11,0,100,0,0,0,0,0,89,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Skittering Shadows - On Respawn - Move Random 8 yards'),
(@SKITTERING,0,1,0,11,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Skittering Shadows - On Respawn - Set React Passive'),
(@SKITTERING,0,2,0,4,0,100,0,0,0,0,0,41,0,0,0,0,0,0,11,111350,200,0,0,0,0,0,'Skittering Shadows - On Aggro - Despawn Creatures Skittering Shadows in 200 yards Instant'),
(@SKITTERING,0,3,0,4,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Skittering Shadows - On Aggro - Despawn Self Instant'),
(@CREATURE,0,0,0,0,0,100,64,7500,9000,6000,11000,11,222043,512,0,0,0,0,2,0,0,0,0,0,0,0,'Creature in the Shadows - In Combat - Cast Crushing Darkness'),
(@CREATURE,0,1,0,11,0,100,0,0,0,0,0,114,0,0,0,0,0,0,1,0,0,0,0,20,0,0,'Creature in the Shadows - On Respawn - Move Forward 20 yards'),
(@CREATURE,0,2,0,4,0,100,0,0,0,0,0,39,200,0,0,0,0,0,1,0,0,0,0,0,0,0,'Creature in the Shadows - On Aggro - Call for Help 200 yards'),
(@CREATURE,0,3,0,11,0,100,0,0,0,0,0,11,212461,2,0,0,0,0,1,0,0,0,0,0,0,0,'Creature in the Shadows - On Respawn - Cast Nightmare Dissolve In on Self'),
(@CREATURE,0,4,0,11,0,100,0,0,0,0,0,11,212563,2,0,0,0,0,1,0,0,0,0,0,0,0,'Creature in the Shadows - On Death - Cast Nightmare Dissolve In on Self'),
(@NIGHTMARE,0,0,0,0,0,100,64,3000,4000,15000,17000,11,222082,512,0,0,0,0,2,0,0,0,0,0,0,0,'Nightmare Amalgamation - In Combat - Cast Hateful Rebuke'),
(@NIGHTMARE,0,1,0,11,0,100,0,0,0,0,0,11,212461,2,0,0,0,0,1,0,0,0,0,0,0,0,'Nightmare Amalgamation - On Respawn - Cast Nightmare Dissolve In on Self'),
(@NIGHTMARE,0,2,0,11,0,100,0,0,0,0,0,11,212563,2,0,0,0,0,1,0,0,0,0,0,0,0,'Nightmare Amalgamation - On Death - Cast Nightmare Dissolve In on Self'),
(@POUNDER,0,1,0,11,0,100,0,0,0,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Shadow Pounder - On Respawn - Set Rooted On'),
(@POUNDER,0,2,0,0,0,100,0,1000,2000,2000,2500,11,222110,0,0,0,0,0,5,0,0,0,0,0,0,0,'Shadow Pounder - In Combat - Cast Nightmare Bolt on Random Target'),
(@POUNDER,0,3,0,11,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Shadow Pounder - On Respawn - Set React Passive'),
(@POUNDER,0,4,0,11,0,100,0,0,0,0,0,38,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Shadow Pounder - On Respawn - Zone Combat Pulse'),
(@DARK,0,1,0,1,0,100,0,500,1000,5000,6000,38,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dark Devourers - Out of Combat - Set In Combat With Zone');
