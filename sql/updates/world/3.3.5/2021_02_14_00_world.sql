--
DELETE FROM `smart_scripts` WHERE `entryorguid` = 27006 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27006,0,0,0,4,0,100,0,0,0,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Bonesunder - On Aggro - Say Line 0"),
(27006,0,1,0,0,0,100,0,3000,3000,20000,20000,0,11,52080,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bonesunder - In Combat - Cast 'Bone Crack'"),
-- Pretty sure it's HandleAfterCast
(27006,0,2,0,31,0,100,0,52080,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bonesunder - On Target Spellhit 'Bone Crack' - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID` = 27006;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(27006,0,0,"You dare invade Magnataur lands?  Bonesunder gladly smash you and take your limbs as payment!",14,0,100,0,0,0,26665,0,"Bonesunder"),
(27006,1,0,"Bonesunder begins to cast Crack Bone!",16,0,100,0,0,0,28605,0,"Bonesunder");
