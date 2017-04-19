-- Creature entry 20243, Scrapped Fel Reaver, Quest "It's a Fel Reaver, But with Heart"
SET @FEL := 20243; -- Scrapped Fel Reaver
SET @Zaxxis := 20287; -- Zaxxis Ambusher

DELETE FROM `creature_text` WHERE `entry` = @FEL;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@FEL,0,0,"The %s's mechanical heart begins to beat softly.",16,0,100,0,0,0,18271,0,"Scrapped Fel Reaver - Zapped Emote");

DELETE FROM `smart_scripts` WHERE `entryorguid` = @FEL AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@FEL,0, 0,1,  8, 0,100,0, 35282,     0,     0,     0, 19,    256,    0,      0, 0,0,0, 1,      0, 0,   0,       0,       0,      0,    0, "Scrapped Fel Reaver - On Spellhit 'Fel Zapper' - Remove Flags Immune To Players"),
(@FEL,0, 1,2, 61, 0,100,0,     0,     0,     0,     0,  1,      0, 1000,      0, 0,0,0, 1,      0, 0,   0,       0,       0,      0,    0, "Scrapped Fel Reaver - On Spellhit 'Fel Zapper' - Say Line 0"),
(@FEL,0, 2,0, 61, 0,100,0,     0,     0,     0,     0, 18, 131076,    0,      0, 0,0,0, 1,      0, 0,   0,       0,       0,      0,    0, "Scrapped Fel Reaver - On Spellhit 'Fel Zapper' - Set Flags Disable Movement & Pacified"),
(@FEL,0, 3,0,  0, 0,100,0,  2000,  2000, 30000, 30000, 12,@Zaxxis,    2, 180000, 1,0,0, 8,      0, 0,   0, 2547.08, 3982.24, 131.39, 2.01, "Scrapped Fel Reaver - In Combat - Summon Creature 'Zaxxis Ambusher'"),
(@FEL,0, 4,0,  0, 0,100,0, 17000, 17000, 45000, 45000, 12,@Zaxxis,    2, 180000, 1,0,0, 8,      0, 0,   0, 2537.70, 3975.96, 130.40, 1.58, "Scrapped Fel Reaver - In Combat - Summon Creature 'Zaxxis Ambusher'"),
(@FEL,0, 5,0,  0, 0,100,0, 32000, 32000, 45000, 45000, 12,@Zaxxis,    2, 180000, 1,0,0, 8,      0, 0,   0, 2506.46, 4008.93, 133.80, 6.19, "Scrapped Fel Reaver - In Combat - Summon Creature 'Zaxxis Ambusher'"),
(@FEL,0, 6,0,  0, 0,100,0, 60000, 60000, 45000, 45000, 12,@Zaxxis,    2, 180000, 1,0,0, 8,      0, 0,   0, 2537.30, 4027.11, 135.50, 4.30, "Scrapped Fel Reaver - In Combat - Summon Creature 'Zaxxis Ambusher'"),
(@FEL,0, 7,0,  6, 0,100,0,     0,     0,     0,     0, 51,      0,    0,      0, 0,0,0, 9,@Zaxxis, 0, 150,       0,       0,      0,    0, "Scrapped Fel Reaver - On Just Died - Kill Target"),
(@FEL,0, 8,0,  7, 0,100,0,     0,     0,     0,     0, 51,      0,    0,      0, 0,0,0, 9,@Zaxxis, 0, 150,       0,       0,      0,    0, "Scrapped Fel Reaver - On Evade - Kill Target"),
(@FEL,0, 9,0, 11, 0,100,0,     0,     0,     0,     0, 75,  39311,    0,      0, 0,0,0, 1,      0, 0,   0,       0,       0,      0,    0, "Scrapped Fel Reaver - On Respawn - Add Aura 'Scrapped Fel Reaver Transform'");

-- Creature entry 20287, Zaxxis Ambusher
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = @Zaxxis;

DELETE FROM `smart_scripts` WHERE `entryorguid` = @Zaxxis AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Zaxxis,0, 0,0, 54, 0,100,0, 0,0,0,0, 49, 0,0,0,0,0,0, 21, 85, 0,0,0,0,0,0, 'Zaxxis Ambusher - On Just Summoned - Start Attacking');
