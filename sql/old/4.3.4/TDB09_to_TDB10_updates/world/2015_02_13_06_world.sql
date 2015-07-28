--
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=34935;
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`,`user_type`) VALUES
(34935,43671,1,0); -- Horde Gunship Cannon - Ride Vehicle

SET @NPC_VISION_RAVEN_GOD           := 21861;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@NPC_VISION_RAVEN_GOD) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@NPC_VISION_RAVEN_GOD,0,0,1,38,0,100,0,1,1,0,0,11,39426,0,0,0,0,0,21,20,0,0,0.0,0.0,0.0,0.0,"Vision of Raven God - On Data Set 4 - Cast credit"),
(@NPC_VISION_RAVEN_GOD,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,21,20,0,0,0.0,0.0,0.0,0.0,"Vision of Raven God - Link - Say 0"),
(@NPC_VISION_RAVEN_GOD,0,2,3,38,0,100,0,1,2,0,0,11,39428,0,0,0,0,0,21,20,0,0,0.0,0.0,0.0,0.0,"Vision of Raven God - On Data Set 4 - Cast credit"),
(@NPC_VISION_RAVEN_GOD,0,3,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,21,20,0,0,0.0,0.0,0.0,0.0,"Vision of Raven God - Link - Say 1"),
(@NPC_VISION_RAVEN_GOD,0,4,5,38,0,100,0,1,3,0,0,11,39430,0,0,0,0,0,21,20,0,0,0.0,0.0,0.0,0.0,"Vision of Raven God - On Data Set 4 - Cast credit"),
(@NPC_VISION_RAVEN_GOD,0,5,0,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,21,20,0,0,0.0,0.0,0.0,0.0,"Vision of Raven God - Link - Say 2"),
(@NPC_VISION_RAVEN_GOD,0,6,7,38,0,100,0,1,4,0,0,11,39431,0,0,0,0,0,21,20,0,0,0.0,0.0,0.0,0.0,"Vision of Raven God - On Data Set 4 - Cast credit"),
(@NPC_VISION_RAVEN_GOD,0,7,0,61,0,100,0,0,0,0,0,1,3,0,0,0,0,0,21,20,0,0,0.0,0.0,0.0,0.0,"Vision of Raven God - Link - Say 3");

SET @ENTRY := 24290;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,0,43404,0,0,0,11,43419,0,0,0,0,0,7,0,0,0,0,0,0,0,"New Agamand Plague Tank Bunny - On Spellhit 'Mission: Plague This!: Orehammer's Precision Bombs Dummy' - Quest Credit 'Mission: Plague This!'");

UPDATE `smart_scripts` SET `action_param1`=25068 WHERE  `entryorguid`=24999 AND `source_type`=0 AND `id`=2 AND `link`=0;
