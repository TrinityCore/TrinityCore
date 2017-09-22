-- 
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2662600, 2662601) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2662600, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Scourge Reanimator - On Script - Set Immune to PC+NPC"),
(2662600, 9, 1, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Scourge Reanimator - On Script - Say Line 0"),
(2662600, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 1, 2662600, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Scourge Reanimator - On Script - Start Waypoint"),
(2662601, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Scourge Reanimator - On Script - Say Line 1"),
(2662601, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 56502, 26620, 0, 0, 0, 0, 0, "Scourge Reanimator - On Script - Set Data 1 1"),
(2662601, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 56503, 26620, 0, 0, 0, 0, 0, "Scourge Reanimator - On Script - Set Data 1 1"),
(2662601, 9, 3, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 11, 48597, 0, 0, 0, 0, 0, 10, 56503, 26620, 0, 0, 0, 0, 0, "Scourge Reanimator - On Script - Cast 'Raise Dead'"),
(2662601, 9, 4, 0, 0, 0, 100, 0, 1500, 1500, 0, 0, 12, 26635, 3, 600000, 0, 0, 0, 8, 0, 0, 0, -536.831, -578.793, 1.91333, 1.77444, "Scourge Reanimator - On Script - Summon Creature 'Risen Drakkari Warrior'"),
(2662601, 9, 5, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 11, 48597, 0, 0, 0, 0, 0, 10, 56502, 26620, 0, 0, 0, 0, 0, "Scourge Reanimator - On Script - Cast 'Raise Dead'"),
(2662601, 9, 6, 0, 0, 0, 100, 0, 1500, 1500, 0, 0, 12, 26635, 3, 600000, 0, 0, 0, 8, 0, 0, 0, -543.122, -582.083, 1.02542, 2.12067, "Scourge Reanimator - On Script - Summon Creature 'Risen Drakkari Warrior'"),
(2662601, 9, 7, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Scourge Reanimator - On Script - Say Line 2"),
(2662601, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 47506, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Scourge Reanimator - On Script - Cast 'Teleport'"),
(2662601, 9, 9, 0, 0, 0, 100, 0, 1500, 1500, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Scourge Reanimator - On Script - Despawn Instant");

UPDATE `creature` SET `unit_flags`=768 WHERE `guid` IN (56502, 56503);
UPDATE `smart_scripts` SET `action_param1`=2 WHERE `entryorguid`=26635 AND `source_type`=0 AND `id`=2;
-- Drakkari Guardian SAI
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-56502, -56503) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-56502,0,0,0,1,0,100,1,7000,7000,0,0,69,0,0,0,0,0,0,8,0,0,0,-543.121582,-582.083313,1.025425,2.120673,"Drakkari Guardian - Out of Combat - Move To Position (No Repeat)"),
(-56502,0,1,0,38,0,100,0,1,1,0,0,11,35357,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Guardian - On Data Set 1 1 - Cast feign death"),
(-56502,0,2,0,8,0,100,1,48597,0,0,0,41,2000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Guardian - On Spell Hit - Despawn"), 
(-56502,0,3,0,8,0,100,1,48597,0,0,0,75,29147,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Guardian - On Spell Hit - Add bore visual aura"),
(-56503,0,0,0,1,0,100,1,7000,7000,0,0,69,0,0,0,0,0,0,8,0,0,0,-536.830505,-578.793091,1.913330,1.774444,"Drakkari Guardian - Out of Combat - Move To Position (No Repeat)"),
(-56503,0,1,0,38,0,100,0,1,1,0,0,11,35357,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Guardian - On Data Set 1 1 - Cast feign death"),
(-56503,0,2,0,8,0,100,1,48597,0,0,0,41,2000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Guardian - On Spell Hit - Despawn"),
(-56503,0,3,0,8,0,100,1,48597,0,0,0,75,29147,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Guardian - On Spell Hit - Add bore visual aura");
