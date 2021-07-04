-- Unliving Swine SAI
SET @ENTRY := 25600;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,5000,8000,12000,11,50303,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unliving Swine - In Combat - Cast 'Swine Flu'");

-- En'kilah Necrolord SAI
SET @ENTRY := 25609;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,30000,30000,11,50324,0,0,0,0,0,1,0,0,0,0,0,0,0,"En'kilah Necrolord - In Combat - Cast 'Bone Armor'"),
(@ENTRY,0,1,0,0,0,100,0,2000,5000,6000,9000,11,50323,0,0,0,0,0,2,0,0,0,0,0,0,0,"En'kilah Necrolord - In Combat - Cast 'Sharpened Bone'");

-- Bane SAI
SET @ENTRY := 25655;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,5000,15000,20000,11,50332,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bane - In Combat - Cast 'Fool's Bane'");

-- Kvaldir Mist Lord SAI
SET @ENTRY := 25496;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,10000,15000,11,49922,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kvaldir Mist Lord - In Combat - Cast 'Wave Crash'");

-- Kel'Thuzad SAI
SET @ENTRY := 25465;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,3000,6000,27000,29000,11,50312,32,0,0,0,0,1,0,0,0,0,0,0,0,"Kel'Thuzad - Out of Combat - Cast 'Unholy Frenzy'"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,4,8818,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kel'Thuzad - Out of Combat - Play Sound 8818"),
(@ENTRY,0,2,0,1,0,100,0,0,0,2000,10000,11,50319,0,0,0,0,0,21,70,0,0,0,0,0,0,"Kel'Thuzad - Out of Combat - Cast 'Soul Flay'");

-- Injured Warsong Shaman SAI
SET @ENTRY := 27108;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,1,47962,0,0,0,85,47967,1,0,0,0,0,7,0,0,0,0,0,0,0,"Injured Warsong Shaman - On Spell hit - Cast Killcredit on Invoker"),
(@ENTRY,0,1,0,61,0,100,513,47962,0,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Injured Warsong Shaman - On Spell hit - Despawn after 1sec"),
(@ENTRY,0,2,0,0,0,100,0,0,2000,6000,14000,11,25025,0,0,0,0,0,2,0,0,0,0,0,0,0,"Injured Warsong Shaman - In Combat - Cast 'Earth Shock'"),
(@ENTRY,0,3,0,0,0,100,0,3000,5000,8000,12000,11,16033,0,0,0,0,0,2,0,0,0,0,0,0,0,"Injured Warsong Shaman - In Combat - Cast 'Chain Lightning'");

-- Injured Warsong Mage SAI
SET @ENTRY := 27107;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,1,47962,0,0,0,85,47967,1,0,0,0,0,7,0,0,0,0,0,0,0,"Injured Warsong Mage - On Spell hit - Cast Killcredit on Invoker"),
(@ENTRY,0,1,0,61,0,100,513,47962,0,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Injured Warsong Mage - On Spell hit - Despawn after 1sec"),
(@ENTRY,0,2,0,0,0,100,0,0,2000,1000,7000,11,34933,0,0,0,0,0,2,0,0,0,0,0,0,0,"Injured Warsong Mage - In Combat - Cast 'Arcane Explosion'"),
(@ENTRY,0,3,0,0,0,100,0,3000,7000,10000,30000,11,17274,0,0,0,0,0,2,0,0,0,0,0,0,0,"Injured Warsong Mage - In Combat - Cast 'Pyroblast'"),
(@ENTRY,0,4,0,0,0,100,0,8000,12000,20000,30000,11,46195,0,0,0,0,0,2,0,0,0,0,0,0,0,"Injured Warsong Mage - In Combat - Cast 'Blizzard'");

-- Injured Warsong Warrior SAI
SET @ENTRY := 27106;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,2,8,0,100,1,47962,0,0,0,85,47967,1,0,0,0,0,7,0,0,0,0,0,0,0,"Injured Warsong Warrior - On Spellhit 'Rescue Injured Soldier' - Invoker Cast 'Soldier Rescued' (No Repeat)"),
(@ENTRY,0,1,0,61,0,100,513,47962,0,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Injured Warsong Warrior - On Spellhit 'Rescue Injured Soldier' - Despawn Instant (No Repeat)"),
(@ENTRY,0,2,1,61,0,100,0,47962,0,0,0,85,47975,0,0,0,0,0,7,0,0,0,0,0,0,0,"Injured Warsong Warrior - On Spellhit 'Rescue Injured Soldier' - Invoker Cast 'Warlord's Bulwark' (No Repeat)"),
(@ENTRY,0,3,0,0,0,100,0,0,3000,7000,14000,11,39047,0,0,0,0,0,2,0,0,0,0,0,0,0,"Injured Warsong Warrior - In Combat - Cast 'Cleave'"),
(@ENTRY,0,4,0,0,0,100,0,3000,6000,7000,14000,11,45026,0,0,0,0,0,2,0,0,0,0,0,0,0,"Injured Warsong Warrior - In Combat - Cast 'Heroic Strike'");

-- Injured Warsong Engineer SAI
SET @ENTRY := 27110;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,2,8,0,100,1,47962,0,0,0,85,47967,1,0,0,0,0,7,0,0,0,0,0,0,0,"Injured Warsong Engineer - On Spellhit 'Rescue Injured Soldier' - Invoker Cast 'Soldier Rescued' (No Repeat)"),
(@ENTRY,0,1,0,61,0,100,513,47962,0,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Injured Warsong Engineer - On Spellhit 'Rescue Injured Soldier' - Despawn Instant (No Repeat)"),
(@ENTRY,0,2,1,61,0,100,0,47962,0,0,0,85,47969,0,0,0,0,0,7,0,0,0,0,0,0,0,"Injured Warsong Engineer - On Spellhit 'Rescue Injured Soldier' - Invoker Cast 'Tune Up!' (No Repeat)"),
(@ENTRY,0,3,0,0,0,100,0,0,3000,7000,14000,11,44273,0,0,0,0,0,2,0,0,0,0,0,0,0,"Injured Warsong Engineer - In Combat - Cast 'Goblin Dragon Gun'"),
(@ENTRY,0,4,0,0,0,100,0,4000,7000,12000,15000,11,22742,0,0,0,0,0,2,0,0,0,0,0,0,0,"Injured Warsong Engineer - In Combat - Cast 'Super Shrink Ray'");

-- Rockfang SAI
SET @ENTRY := 25774;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,0,0,0,0,0,11,46221,2,0,0,0,0,7,0,0,0,0,0,0,0,"Rockfang - On Just Died - Cast 'Animal Blood'"),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,6000,9000,11,32918,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rockfang - In Combat - Cast 'Chilling Howl'");

-- Gammothra the Tormentor SAI
SET @ENTRY := 25789;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,512,46012,0,0,0,36,25790,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gammothra the Tormentor - On Spellhit 'Bloodspore Poison' - Update Template To 'Weakened Gammothra'"),
(@ENTRY,0,1,0,0,0,100,0,0,1000,10000,12000,11,50413,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gammothra the Tormentor - In Combat - Cast 'Magnataur Charge'"),
(@ENTRY,0,2,0,0,0,100,0,3000,5000,6000,10000,11,50410,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gammothra the Tormentor - In Combat - Cast 'Tusk Strike'");

-- Ragnar Drakkarlund SAI
SET @ENTRY := 26451;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,8000,10000,11,41056,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ragnar Drakkarlund - In Combat - Cast 'Whirlwind'");

-- Crypt Crawler SAI
SET @ENTRY := 25227;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,2000,3000,11,31600,64,0,0,0,0,2,0,0,0,0,0,0,0,"Crypt Crawler - IC  - Cast 'Crypt Scarabs' CMC");


DELETE FROM `creature_text` WHERE `CreatureID` = 25514; -- Rocknar
INSERT INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(25514,0,0,' Frozen and destroyed. This is all your fleshy corpse is good for.',12,0,100,0,0,0,24727,0,'Rocknar'),
(25514,0,1,' You are not welcome here. Die!',12,0,100,0,0,0,24728,0,'Rocknar'),
(25514,0,2,' Your presence unbalances the land. You must be removed!',12,0,100,0,0,0,24729,0,'Rocknar');

-- Rocknar SAI
SET @ENTRY := 25514;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,11,42617,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rocknar - On Reset - Cast 'Vertex Color Lt. Blue'"),
(@ENTRY,0,1,0,21,0,100,1,0,0,0,0,11,45776,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rocknar - On Reached Home - Cast 'Ice Block' (No Repeat)"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rocknar - On Aggro - Say Line 0"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,28,45776,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rocknar - On Aggro - Remove Aura 'Ice Block'"),
(@ENTRY,0,4,0,0,0,100,0,0,3000,8000,10000,11,50094,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rocknar - In Combat - Cast 'Ice Spike'"),
(@ENTRY,0,5,0,11,0,100,1,0,0,0,0,11,45776,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rocknar - On Respawn - Cast 'Ice Block' (No Repeat)"),
(@ENTRY,0,6,0,0,0,100,0,4000,7000,14000,16000,11,22693,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rocknar - In Combat - Cast 'Harden Skin'");

DELETE FROM `creature_text` WHERE `CreatureID` = 26185; -- Lurid
INSERT INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(26185,0,0,' You worship death, little man?  Death is here!',12,0,100,35,0,0,25347,0,'Lurid'),
(26185,0,1,' Master... you want... I kill puny priest?  Make painful, yes?',12,0,100,35,0,0,25345,0,'Lurid'),
(26185,0,2,' Yes, weakling... beg Lurid for life!',12,0,100,35,0,0,25346,0,'Lurid'),
(26185,1,0,' You Arthas lapdog?  You die!',12,0,100,0,0,0,25835,0,'Lurid'),
(26185,1,1,' Time to kill!',12,0,100,0,0,0,17565,0,'Lurid'),
(26185,1,2,' Lurid could get used... to working with you.',12,0,100,0,0,0,25837,0,'Lurid'),
(26185,1,3,' It\'s about time!  Lurid was getting bored.',12,0,100,0,0,0,25834,0,'Lurid'),
(26185,1,4,' This not... end well for you!',12,0,100,0,0,0,25836,0,'Lurid');

-- Lurid SAI
SET @ENTRY := 26185;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,30000,70000,170000,200000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lurid - Out of Combat - Say Line 0"),
(@ENTRY,0,1,0,25,0,100,0,0,0,0,0,8,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lurid - On Reset - Set Reactstate Defensive"),
(@ENTRY,0,2,0,4,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lurid - On Aggro - Say Line 1");

-- High Deathpriest Isidorus texts
DELETE FROM `creature_text` WHERE `CreatureID` = 26171;
INSERT INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(26171,0,0,' Please... all our orders come from Naxxanar... me and my men are kept in the dark!',12,0,100,0,0,0,25353,0,'High Deathpriest Isidorus'),
(26171,0,1,' Mercy!  You were once with us!  DO you not remember?',12,0,100,0,0,0,25355,0,'High Deathpriest Isidorus'),
(26171,0,2,' I beg you, death knight!  Keep your minion away from me!  I\'ll do anything!',12,0,100,0,0,0,25354,0,'High Deathpriest Isidorus');

-- High Deathpriest Isidorus SAI
SET @ENTRY := 26171;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,30000,50000,170000,200000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Deathpriest Isidorus - Out of Combat - Say Line 0");

-- Ziggurat Defender SAI
SET @ENTRY := 26202;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,1000,5000,11,50306,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ziggurat Defender - In Combat - Cast 'Thrash Kick'");

-- spell condition for 'Borean Tundra - Quest - Thassarian Flay'
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND  `SourceGroup`=1 AND `SourceEntry`=46685;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES 
(13, 1, 46685, 0, 0, 31, 0, 3, 26173, 0, 0, 0, 0, '', "Spell 'Thassarian Flay' only targets NPC Tanathal");

-- Fleeing Cultist texts
DELETE FROM `creature_text` WHERE `CreatureID` = 26189; 
INSERT INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(26189,0,0,' The ziggurat\'s lost!  Flee to the temple!',12,0,100,0,0,0,25350,0,'Fleeing Cultist'),
(26189,0,1,' The death knight... he\'s mad!',12,0,100,0,0,0,25349,0,'Fleeing Cultist'),
(26189,0,2,' Arthas save us - we\'re doomed!',12,0,100,0,0,0,25348,0,'Fleeing Cultist');

-- Fleeing Cultist SAI
SET @ENTRY := 26189;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,33,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fleeing Cultist - On Respawn - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID` = 26170 AND `groupid` = 7; -- Thassarian
INSERT INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(26170,7,0,' Speak, Lich!  Undeath won\'t save you from what I\'ll put you through!',12,0,100,0,4000,0,25321,0,'Thassarian');

-- Bloodspore Moth
UPDATE `creature_template` SET `InhabitType` = 7 WHERE `entry` = 25464;

-- Bloodmage Laurith SAI
SET @ENTRY := 25381;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,8,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodmage Laurith - On Reset - Set Reactstate Defensive");

-- Primal Mighthorn SAI
SET @ENTRY := 25380;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,11721,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Primal Mighthorn - On Quest Accept (Gammothra the Tormentor) - Say Line 1"),
(@ENTRY,0,1,0,25,0,100,0,0,0,0,0,8,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Primal Mighthorn - On Reset - Set Reactstate Defensive");

-- Bloodspore Firestarter
UPDATE `creature` SET `position_x`= 2560.157, `position_y`= 5832.141, `position_z`= 141.855 WHERE `guid`= 107529;

-- Primal Mighthorn, Bloodmage Laurith
UPDATE `creature` SET `orientation`= 0.3736162 WHERE `guid`= 132640;
UPDATE `creature` SET `orientation`= 2.397409 WHERE `guid`= 132641;
DELETE FROM `creature_formations` WHERE `leaderGUID`= 132640;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
(132640, 132640, 0, 0, 3, 0, 0),
(132640, 132641, 0, 0, 3, 0, 0);

-- Bloodspore Moth, Bloodspore Harvester, Bloodspore Firestarter
DELETE FROM `creature` WHERE `guid` IN (132708, 107116, 107253, 107560);
DELETE FROM `creature_addon` WHERE `guid` IN (132708,107116,107253,107560);

-- Den Vermin
UPDATE `creature` SET `spawntimesecs`= 300, `spawndist`= 5, `MovementType`= 1 WHERE `guid` IN (133116,133117,133118,133121);
UPDATE `creature` SET `position_x`= 2649.587, `position_y`= 5904.689, `position_z`=  4.274 WHERE `guid`= 133116;
UPDATE `creature` SET `position_x`= 2559.874, `position_y`= 5871.110, `position_z`= 27.613 WHERE `guid`= 133117;
UPDATE `creature` SET `position_x`= 2592.794, `position_y`= 5867.375, `position_z`= -9.839 WHERE `guid`= 133118;
UPDATE `creature` SET `position_x`= 2564.476, `position_y`= 5890.039, `position_z`= -8.713 WHERE `guid`= 133121;

-- Bloodspore Harvester, Bloodspore Roaster
UPDATE `creature` SET `unit_flags`= 768 WHERE `guid` IN (132720, 132721, 132722, 132723, 132724);
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 0 WHERE `guid` IN (107309, 107322, 107360, 107386, 107387);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9472 AND `SourceEntry`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,9472,0,0,0,8,0,11733,0,0,0,0,'','Surristrasz - Show Gossip Option 0 if Quest 11733 is rewarded');
