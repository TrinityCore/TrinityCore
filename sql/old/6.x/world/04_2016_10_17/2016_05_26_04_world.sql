-- Thirst Unending 6.x
-- Arcane Torrent Monk    129597
-- Arcane Torrent Paladin 155145
-- Arcane Torrent Warrior 69179
-- Arcane Torrent Hunter  80483

SET @WYRM := 15274;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@WYRM AND `source_type`=0 and `id` in (4,5,6,7);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@WYRM,0,4,0,8,0,100,1,69179,0,0,0,11,61314,0,0,0,0,0,7,0,0,0,0,0,0,0,"Mana Wyrm - On Spellhit 'Arcane Torrent' - Cast 'Quest Credit 8346' (No Repeat)"),
(@WYRM,0,5,0,8,0,100,1,80483,0,0,0,11,61314,0,0,0,0,0,7,0,0,0,0,0,0,0,"Mana Wyrm - On Spellhit 'Arcane Torrent' - Cast 'Quest Credit 8346' (No Repeat)"),
(@WYRM,0,6,0,8,0,100,1,129597,0,0,0,11,61314,0,0,0,0,0,7,0,0,0,0,0,0,0,"Mana Wyrm - On Spellhit 'Arcane Torrent' - Cast 'Quest Credit 8346' (No Repeat)"),
(@WYRM,0,7,0,8,0,100,1,155145,0,0,0,11,61314,0,0,0,0,0,7,0,0,0,0,0,0,0,"Mana Wyrm - On Spellhit 'Arcane Torrent' - Cast 'Quest Credit 8346' (No Repeat)");
