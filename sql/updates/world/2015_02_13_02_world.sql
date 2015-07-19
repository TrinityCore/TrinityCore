--
DELETE FROM `areatrigger_scripts` WHERE `ScriptName` IN ('at_twiggy_flathead','at_madrigosa','at_eye_of_eternity_improvised_floor');

UPDATE `gameobject_template` SET `ScriptName`='' WHERE `ScriptName` IN ('go_defias_cannon','go_door_lever_dm','go_kael_orb','go_movie_orb');

UPDATE `item_template` SET `ScriptName`='' WHERE `ScriptName`='internalitemhandler';

UPDATE `creature_template` SET `ScriptName`='' WHERE `ScriptName` IN ('do_nothing','npc_aran_blizzard','npc_bladespire_ogre','npc_blaze','npc_crystalline_tangler','npc_demon_fire','npc_flame_crash','npc_generic_harpoon_cannon','npc_homunculus','npc_invis_legion_teleporter','npc_magnetic_core','npc_mindless_skeleton','npc_nether_vapor','npc_novos_minion','npc_sliver','npc_thuzadin_acolyte','npc_tracy_proudwell','npc_vereth_the_cunning','npc_void_zone','npc_yauj_brood');

DELETE FROM `spell_script_names` WHERE `scriptname` IN ('spell_ex_463', 'spell_ex_5581', 'spell_ex_66244', 'spell_ex_absorb_aura', 'spell_mimiron_flame_suppressant');

UPDATE `smart_scripts` SET `link`=0 WHERE  `entryorguid`=37120 AND `source_type`=0 AND `id`=3 AND `link`=7;

-- Grand Necrolord Antiok SAI
SET @ENTRY := 28006;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7000,7000,18000,18000,11,32863,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grand Necrolord Antiok - In Combat - Cast 'Seed of Corruption'"),
(@ENTRY,0,1,0,0,0,100,0,1100,1100,20000,20000,11,50455,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grand Necrolord Antiok - In Combat - Cast 'Shadow Bolt'"),
(@ENTRY,0,2,0,1,0,100,0,10000,10000,40000,40000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grand Necrolord Antiok - Out of Combat - Say Line 1"),
(@ENTRY,0,3,0,2,0,100,1,0,25,0,0,11,50497,1,0,0,0,0,2,0,0,0,0,0,0,0,"Grand Necrolord Antiok - Between 0-25% Health - Cast 'Scream of Chaos' (No Repeat)"),
(@ENTRY,0,4,0,6,0,100,0,0,0,0,0,11,50472,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grand Necrolord Antiok - On Just Died - Cast 'Drop Scythe of Antiok'"),
(@ENTRY,0,5,6,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grand Necrolord Antiok - On Aggro - Say Line 0"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,11,55984,1,0,0,0,0,2,0,0,0,0,0,0,0,"Grand Necrolord Antiok - On Aggro - Cast 'Shadow Bolt'"),
(@ENTRY,0,7,8,4,0,100,0,0,0,0,0,51,0,0,0,0,0,0,19,27996,20,0,0,0,0,0,"Grand Necrolord Antiok - On Aggro - Kill Target"),
(@ENTRY,0,8,0,61,0,100,0,0,0,0,0,28,50494,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grand Necrolord Antiok - On Aggro - Remove Aura 'Shroud of Lightning'");

UPDATE `smart_scripts` SET `link`=0 WHERE  `entryorguid`=27987 AND `source_type`=0 AND `id`=0 AND `link`=1;
UPDATE `smart_scripts` SET `link`=11 WHERE  `entryorguid`=27788 AND `source_type`=0 AND `id`=2 AND `link`=12;
UPDATE `smart_scripts` SET `link`=0 WHERE  `entryorguid`=26701 AND `source_type`=0 AND `id`=0 AND `link`=1;
UPDATE `smart_scripts` SET `link`=0 WHERE  `entryorguid`=24035 AND `source_type`=0 AND `id`=0 AND `link`=1;

-- Ara Technician SAI
SET @ENTRY := 20438;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,38,0,100,0,4,4,0,0,8,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ara Technician - On Data Set 4 4 - Set Reactstate Defensive"),
(@ENTRY,0,1,0,61,0,100,0,4,4,0,0,87,2043900,2043901,0,0,0,0,1,0,0,0,0,0,0,0,"Ara Technician - On Data Set 4 4 - Run Random Script"),
(@ENTRY,0,2,0,1,1,100,1,12000,12000,0,0,45,1,1,0,0,0,0,20,184312,0,0,0,0,0,0,"Ara Technician - Out of Combat - Set Data 1 1 (Phase 1) (No Repeat)"),
(@ENTRY,0,3,4,40,0,100,0,1,0,0,0,11,35176,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ara Technician - On Waypoint 1 Reached - Cast 'Interrupt Shutdown'"),
(@ENTRY,0,4,0,61,0,100,0,1,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ara Technician - On Waypoint 1 Reached - Set Event Phase 1"),
(@ENTRY,0,5,6,4,0,100,0,1,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ara Technician - On Aggro - Set Event Phase 0"),
(@ENTRY,0,6,7,61,0,100,0,1,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ara Technician - On Aggro - Set Reactstate Aggressive"),
(@ENTRY,0,7,8,61,0,100,0,1,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ara Technician - On Aggro - Start Attacking"),
(@ENTRY,0,8,0,61,0,100,0,1,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ara Technician - On Aggro - Enable Combat Movement"),
(@ENTRY,0,9,0,7,0,100,0,0,0,0,0,45,1,1,0,0,0,0,20,184312,0,0,0,0,0,0,"Ara Technician - On Evade - Set Data 1 1");

-- Audrid SAI
SET @ENTRY := 18903;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,53,0,18903,1,0,0,0,1,0,0,0,0,0,0,0,"Audrid - On Respawn - Start Waypoint"),
(@ENTRY,0,1,11,40,0,100,0,4,18903,0,0,54,60000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Audrid - On Waypoint 4 Reached - Pause Waypoint"),
(@ENTRY,0,2,12,40,0,100,0,9,18903,0,0,54,60000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Audrid - On Waypoint 9 Reached - Pause Waypoint"),
(@ENTRY,0,3,13,40,0,100,0,11,18903,0,0,54,60000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Audrid - On Waypoint 11 Reached - Pause Waypoint"),
(@ENTRY,0,4,14,40,0,100,0,12,18903,0,0,54,60000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Audrid - On Waypoint 12 Reached - Pause Waypoint"),
(@ENTRY,0,5,15,40,0,100,0,13,18903,0,0,54,60000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Audrid - On Waypoint 13 Reached - Pause Waypoint"),
(@ENTRY,0,6,16,40,0,100,0,14,18903,0,0,54,60000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Audrid - On Waypoint 14 Reached - Pause Waypoint"),
(@ENTRY,0,7,17,40,0,100,0,17,18903,0,0,54,60000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Audrid - On Waypoint 17 Reached - Pause Waypoint"),
(@ENTRY,0,8,18,40,0,100,0,22,18903,0,0,54,60000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Audrid - On Waypoint 22 Reached - Pause Waypoint"),
(@ENTRY,0,9,19,40,0,100,0,25,18903,0,0,54,60000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Audrid - On Waypoint 25 Reached - Pause Waypoint"),
(@ENTRY,0,10,20,40,0,100,0,28,18903,0,0,54,60000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Audrid - On Waypoint 28 Reached - Pause Waypoint"),
(@ENTRY,0,11,21,61,0,100,0,4,18903,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Audrid - On Waypoint 4 Reached - Run Script"),
(@ENTRY,0,12,22,61,0,100,0,9,18903,0,0,80,@ENTRY*100+01,2,0,0,0,0,1,0,0,0,0,0,0,0,"Audrid - On Waypoint 9 Reached - Run Script"),
(@ENTRY,0,13,22,61,0,100,0,11,18903,0,0,80,@ENTRY*100+02,2,0,0,0,0,1,0,0,0,0,0,0,0,"Audrid - On Waypoint 11 Reached - Run Script"),
(@ENTRY,0,14,23,61,0,100,0,12,18903,0,0,80,@ENTRY*100+03,2,0,0,0,0,1,0,0,0,0,0,0,0,"Audrid - On Waypoint 12 Reached - Run Script"),
(@ENTRY,0,15,21,61,0,100,0,13,18903,0,0,80,@ENTRY*100+04,2,0,0,0,0,1,0,0,0,0,0,0,0,"Audrid - On Waypoint 13 Reached - Run Script"),
(@ENTRY,0,16,24,61,0,100,0,14,18903,0,0,80,@ENTRY*100+05,2,0,0,0,0,1,0,0,0,0,0,0,0,"Audrid - On Waypoint 14 Reached - Run Script"),
(@ENTRY,0,17,22,61,0,100,0,17,18903,0,0,80,@ENTRY*100+06,2,0,0,0,0,1,0,0,0,0,0,0,0,"Audrid - On Waypoint 17 Reached - Run Script"),
(@ENTRY,0,18,21,61,0,100,0,22,18903,0,0,80,@ENTRY*100+07,2,0,0,0,0,1,0,0,0,0,0,0,0,"Audrid - On Waypoint 22 Reached - Run Script"),
(@ENTRY,0,19,21,61,0,100,0,25,18903,0,0,80,@ENTRY*100+08,2,0,0,0,0,1,0,0,0,0,0,0,0,"Audrid - On Waypoint 25 Reached - Run Script"),
(@ENTRY,0,20,21,61,0,100,0,28,18903,0,0,80,@ENTRY*100+09,2,0,0,0,0,1,0,0,0,0,0,0,0,"Audrid - On Waypoint 28 Reached - Run Script"),
(@ENTRY,0,21,0,61,0,100,0,4,18903,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.5,"Audrid - On Waypoint 4 Reached - Set Orientation 1,5"),
(@ENTRY,0,22,0,61,0,100,0,9,18903,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3,"Audrid - On Waypoint 9 Reached - Set Orientation 3"),
(@ENTRY,0,23,0,61,0,100,0,12,18903,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.5,"Audrid - On Waypoint 12 Reached - Set Orientation 4,5"),
(@ENTRY,0,24,0,61,0,100,0,14,18903,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,6,"Audrid - On Waypoint 14 Reached - Set Orientation 6");

UPDATE `smart_scripts` SET `event_type`=61 WHERE  `entryorguid`=26670 AND `source_type`=0 AND `id`=19 AND `link`=20;
UPDATE `smart_scripts` SET `link`=20 WHERE  `entryorguid`=17892 AND `source_type`=0 AND `id`=19 AND `link`=0;
UPDATE `smart_scripts` SET `link`=7 WHERE  `entryorguid`=17892 AND `source_type`=0 AND `id`=6 AND `link`=0;
UPDATE `smart_scripts` SET `link`=0 WHERE  `entryorguid`=37952 AND `source_type`=0 AND `id`=1 AND `link`=2;
UPDATE `smart_scripts` SET `link`=0 WHERE  `entryorguid`=26787 AND `source_type`=0 AND `id`=0 AND `link`=1;

-- Mad Voidwalker SAI
SET @ENTRY := 15146;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,89,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mad Voidwalker - On Respawn - Start Random Movement"),
(@ENTRY,0,1,0,0,0,100,2,7000,9000,11000,13000,11,24614,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mad Voidwalker - In Combat - Cast 'Consuming Shadows' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,3000,4000,8000,8000,11,24616,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mad Voidwalker - In Combat - Cast 'Shadow Shock' (Normal Dungeon)"),
(@ENTRY,0,3,0,1,0,100,0,0,0,0,0,41,180000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mad Voidwalker - Out of Combat - Despawn In 180000 ms");

UPDATE `smart_scripts` SET `link`=9 WHERE  `entryorguid`=12236 AND `source_type`=0 AND `id`=8 AND `link`=0;
UPDATE `smart_scripts` SET `link`=9 WHERE  `entryorguid`=13196 AND `source_type`=0 AND `id`=8 AND `link`=0;

-- Scarlet Curate SAI
SET @ENTRY := 9450;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,40,3400,4800,11,25054,64,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Curate - Within 0-40 Range - Cast 'Holy Smite'"),
(@ENTRY,0,1,0,15,0,100,1,0,0,30,0,11,17201,1,0,0,0,0,7,0,0,0,0,0,0,0,"Scarlet Curate - On Friendly Crowd Controlled - Cast 'Dispel Magic' (No Repeat)"),
(@ENTRY,0,2,0,74,0,100,0,0,40,25000,35000,11,17201,1,0,0,0,0,9,0,0,0,0,0,0,0,"Scarlet Curate - On Friendly Between 0-40% Health - Cast 'Dispel Magic'"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Curate - Between 0-15% Health - Flee For Assist (No Repeat)");

UPDATE `smart_scripts` SET `link`=25 WHERE  `entryorguid`=4880 AND `source_type`=0 AND `id`=24 AND `link`=26;
UPDATE `smart_scripts` SET `link`=22, `event_type`=61 WHERE  `entryorguid`=4880 AND `source_type`=0 AND `id`=21 AND `link`=0;
UPDATE `smart_scripts` SET `link`=16 WHERE  `entryorguid`=31279 AND `source_type`=0 AND `id`=15 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=1535 AND `source_type`=0 AND `id`=0 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=2719 AND `source_type`=0 AND `id`=0 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=5, `action_param1`=1 WHERE  `entryorguid`=4484 AND `source_type`=0 AND `id`=24 AND `link`=25;
UPDATE `smart_scripts` SET `action_type`=5, `action_param1`=1 WHERE  `entryorguid`=13601 AND `source_type`=0 AND `id`=2 AND `link`=0;

-- Short John Mithril SAI
SET @ENTRY := 14508;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,68,0,100,0,16,0,0,0,53,0,14508,0,0,0,0,1,0,0,0,0,0,0,0,"Short John Mithril - On Game Event 16 Started - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,0,1,14508,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Short John Mithril - On Waypoint 1 Reached - Say Line 0"),
(@ENTRY,0,2,3,40,0,100,0,16,14508,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Short John Mithril - On Waypoint 16 Reached - Say Line 1"),
(@ENTRY,0,3,0,61,0,100,0,16,14508,0,0,11,23176,0,0,0,0,0,1,0,0,0,0,0,0,0,"Short John Mithril - On Waypoint 16 Reached - Cast 'Summon Pirate Booty (DND)'"),
(@ENTRY,0,4,0,40,0,100,0,33,14508,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.41568,"Short John Mithril - On Waypoint 33 Reached - Set Orientation 4,41568");

UPDATE `smart_scripts` SET `action_type`=5, `action_param1`=1 WHERE  `entryorguid`=15324 AND `source_type`=0 AND `id`=3 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=5, `action_param1`=1 WHERE  `entryorguid`=15526 AND `source_type`=0 AND `id`=2 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=5, `action_param1`=1 WHERE  `entryorguid`=17397 AND `source_type`=0 AND `id`=0 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=5, `action_param1`=1 WHERE  `entryorguid`=18554 AND `source_type`=0 AND `id`=9 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=5, `action_param1`=1 WHERE  `entryorguid`=18554 AND `source_type`=0 AND `id`=13 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=5, `action_param1`=1 WHERE  `entryorguid`=18554 AND `source_type`=0 AND `id`=14 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=5, `action_param1`=1 WHERE  `entryorguid`=18938 AND `source_type`=0 AND `id`=2 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=5 WHERE  `entryorguid`=19354 AND `source_type`=0 AND `id`=4 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=5, `action_param1`=1 WHERE  `entryorguid`=23669 AND `source_type`=0 AND `id`=3 AND `link`=0;
UPDATE `smart_scripts` SET `action_type`=5, `action_param1`=1 WHERE  `entryorguid`=24198 AND `source_type`=0 AND `id`=3 AND `link`=4;
UPDATE `smart_scripts` SET `action_type`=11, `action_param1`=55036 WHERE  `entryorguid`=29903 AND `source_type`=0 AND `id`=6 AND `link`=7;
UPDATE `smart_scripts` SET `action_type`=11, `action_param1`=58190 WHERE  `entryorguid`=30894 AND `source_type`=0 AND `id`=2 AND `link`=3;
UPDATE `smart_scripts` SET `action_type`=5, `action_param1`=1 WHERE  `entryorguid`=30945 AND `source_type`=0 AND `id`=9 AND `link`=0;

UPDATE `creature_template_addon` SET`auras`="" WHERE`entry` IN (26608, 31306); -- vehicle auras appear only when the npc ride a vehicle or when he's mounted
UPDATE `creature_template` SET `npcflag`=16777216 WHERE `entry`=35427;
