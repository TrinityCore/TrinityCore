-- Tarren Mill Deathguard
DELETE FROM `smart_scripts` WHERE `entryorguid`=2405 AND `source_type`=0 AND `id` IN (1,2,3,4,5,6,7,8,9,10);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2405,0,1,0,0,0,100,0,0,0,2000,4000,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Tarren Mill Deathguard - In Combat - Cast 'Shoot'"),
(2405,0,2,0,9,0,100,0,0,5,11000,14000,11,12169,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tarren Mill Deathguard - Within 0-5 Range - Cast 'Shield Block'"),
(2405,0,3,0,0,0,100,0,5000,9000,8000,13000,11,12170,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tarren Mill Deathguard - In Combat - Cast 'Revenge'"),
(2405,0,4,0,22,0,100,0,101,5000,5000,0,80,6800,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tarren Mill Deathguard - On Received Emote 'Wave' - Run Script"),
(2405,0,5,0,22,0,100,0,78,5000,5000,0,80,6801,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tarren Mill Deathguard - On Received Emote 'Salute' - Run Script"),
(2405,0,6,0,22,0,100,0,58,5000,5000,0,80,6802,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tarren Mill Deathguard - On Received Emote 'Kiss' - Run Script"),
(2405,0,7,0,22,0,100,0,84,5000,5000,0,80,6803,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tarren Mill Deathguard - On Received Emote 'Shy' - Run Script"),
(2405,0,8,0,22,0,100,0,77,5000,5000,0,80,6804,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tarren Mill Deathguard - On Received Emote 'Rude' - Run Script"),
(2405,0,9,0,22,0,100,0,22,5000,5000,0,80,6804,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tarren Mill Deathguard - On Received Emote 'Chicken' - Run Script"),
(2405,0,10,0,22,0,100,0,17,5000,5000,0,80,6802,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tarren Mill Deathguard - On Received Emote 'Bow' - Run Script");

UPDATE `creature_text` SET `Language`=33 WHERE `CreatureID`=2405; -- Fix language for Tarren Mill Deathguard's aggro text

-- Hammerfall Guardian
DELETE FROM `smart_scripts` WHERE `entryorguid`=2621 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2621,0,0,0,0,0,100,0,0,0,2000,4000,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Hammerfall Guardian - In Combat - Cast 'Shoot'"),
(2621,0,1,0,9,0,100,0,0,5,11000,14000,11,12169,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hammerfall Guardian - Within 0-5 Range - Cast 'Shield Block'"),
(2621,0,2,0,0,0,100,0,5000,9000,8000,13000,11,12170,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hammerfall Guardian - In Combat - Cast 'Revenge'"),
(2621,0,3,0,22,0,100,0,101,5000,5000,0,80,6800,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hammerfall Guardian - On Received Emote 'Wave' - Run Script"),
(2621,0,4,0,22,0,100,0,78,5000,5000,0,80,6801,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hammerfall Guardian - On Received Emote 'Salute' - Run Script"),
(2621,0,5,0,22,0,100,0,58,5000,5000,0,80,6802,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hammerfall Guardian - On Received Emote 'Kiss' - Run Script"),
(2621,0,6,0,22,0,100,0,84,5000,5000,0,80,6803,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hammerfall Guardian - On Received Emote 'Shy' - Run Script"),
(2621,0,7,0,22,0,100,0,77,5000,5000,0,80,6804,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hammerfall Guardian - On Received Emote 'Rude' - Run Script"),
(2621,0,8,0,22,0,100,0,22,5000,5000,0,80,6804,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hammerfall Guardian - On Received Emote 'Chicken' - Run Script"),
(2621,0,9,0,22,0,100,0,17,5000,5000,0,80,6802,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hammerfall Guardian - On Received Emote 'Bow' - Run Script");

-- Skyguard Windcharger
DELETE FROM `smart_scripts` WHERE `entryorguid`=23257 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23257,0,1,0,9,0,100,0,0,20,12000,16000,11,12024,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skyguard Windcharger - Within 0-20 Range - Cast 'Net'");

-- Stormwind Marine
DELETE FROM `smart_scripts` WHERE `entryorguid`=20556 AND `source_type`=0 AND `id` IN (2,3,4,5,6,7,8,9);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(20556,0,2,0,0,0,100,0,0,0,2000,4000,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Stormwind Marine - In Combat - Cast 'Shoot'"),
(20556,0,3,0,22,0,100,0,101,5000,5000,0,80,6800,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind Marine - On Received Emote 'Wave' - Run Script"),
(20556,0,4,0,22,0,100,0,78,5000,5000,0,80,6801,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind Marine - On Received Emote 'Salute' - Run Script"),
(20556,0,5,0,22,0,100,0,58,5000,5000,0,80,6802,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind Marine - On Received Emote 'Kiss' - Run Script"),
(20556,0,6,0,22,0,100,0,84,5000,5000,0,80,6803,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind Marine - On Received Emote 'Shy' - Run Script"),
(20556,0,7,0,22,0,100,0,77,5000,5000,0,80,6804,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind Marine - On Received Emote 'Rude' - Run Script"),
(20556,0,8,0,22,0,100,0,22,5000,5000,0,80,6804,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind Marine - On Received Emote 'Chicken' - Run Script"),
(20556,0,9,0,22,0,100,0,17,5000,5000,0,80,6802,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind Marine - On Received Emote 'Bow' - Run Script");

UPDATE `creature_template` SET `npcflag`=0, `IconName`=NULL WHERE `entry`=20556; -- They don't give directions and don't have gossip text

-- Deathguard Elite
DELETE FROM `smart_scripts` WHERE `entryorguid`=7980 AND `source_type`=0 AND `id` IN (1,2,3,4,5,6,7,8,9,10);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7980,0,1,0,25,0,100,0,0,0,0,0,11,18950,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathguard Elite - On Reset - Cast 'Invisibility and Stealth Detection'"),
(7980,0,2,0,0,0,100,0,5000,7000,7000,10000,11,14516,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathguard Elite - In Combat - Cast 'Strike'"),
(7980,0,3,0,9,0,100,0,0,5,12000,16000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathguard Elite - Within 0-5 Range - Cast 'Hamstring'"),
(7980,0,4,0,22,0,100,0,101,5000,5000,0,80,6800,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathguard Elite - On Received Emote 'Wave' - Run Script"),
(7980,0,5,0,22,0,100,0,78,5000,5000,0,80,6801,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathguard Elite - On Received Emote 'Salute' - Run Script"),
(7980,0,6,0,22,0,100,0,58,5000,5000,0,80,6802,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathguard Elite - On Received Emote 'Kiss' - Run Script"),
(7980,0,7,0,22,0,100,0,84,5000,5000,0,80,6803,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathguard Elite - On Received Emote 'Shy' - Run Script"),
(7980,0,8,0,22,0,100,0,77,5000,5000,0,80,6804,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathguard Elite - On Received Emote 'Rude' - Run Script"),
(7980,0,9,0,22,0,100,0,22,5000,5000,0,80,6804,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathguard Elite - On Received Emote 'Chicken' - Run Script"),
(7980,0,10,0,22,0,100,0,17,5000,5000,0,80,6802,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathguard Elite - On Received Emote 'Bow' - Run Script");

-- Mounted Ironforge Mountaineer
DELETE FROM `smart_scripts` WHERE `entryorguid`=12996 AND `source_type`=0 AND `id` IN (2,3,4,5,6,7,8,9);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(12996,0,2,0,22,0,100,0,101,5000,5000,0,80,6800,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mounted Ironforge Mountaineer - On Received Emote 'Wave' - Run Script"),
(12996,0,3,0,22,0,100,0,78,5000,5000,0,80,6801,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mounted Ironforge Mountaineer - On Received Emote 'Salute' - Run Script"),
(12996,0,4,0,22,0,100,0,58,5000,5000,0,80,6802,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mounted Ironforge Mountaineer - On Received Emote 'Kiss' - Run Script"),
(12996,0,5,0,22,0,100,0,84,5000,5000,0,80,6803,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mounted Ironforge Mountaineer - On Received Emote 'Shy' - Run Script"),
(12996,0,6,0,22,0,100,0,77,5000,5000,0,80,6804,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mounted Ironforge Mountaineer - On Received Emote 'Rude' - Run Script"),
(12996,0,7,0,22,0,100,0,22,5000,5000,0,80,6804,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mounted Ironforge Mountaineer - On Received Emote 'Chicken' - Run Script"),
(12996,0,8,0,22,0,100,0,17,5000,5000,0,80,6802,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mounted Ironforge Mountaineer - On Received Emote 'Bow' - Run Script");

UPDATE `creature_template` SET `gossip_menu_id`=2121 WHERE `entry`=12996; -- Add gossip text

-- Scout Stronghand
DELETE FROM `smart_scripts` WHERE `entryorguid`=14375 AND `source_type`=0 AND `id` IN (1,2,3);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14375,0,1,0,9,0,100,0,0,30,8000,12000,11,14030,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scout Stronghand - Within 0-30 Range - Cast 'Hooked Net'"),
(14375,0,2,0,0,0,100,0,5000,7000,5000,9000,11,15572,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scout Stronghand - In Combat - Cast 'Sunder Armor'"),
(14375,0,3,0,0,0,100,0,0,0,2000,4000,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Scout Stronghand - In Combat - Cast 'Shoot'");

-- Expedition Warden
DELETE FROM `smart_scripts` WHERE `entryorguid`=17855 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17855,0,0,0,9,0,100,0,0,20,12000,16000,11,12024,0,0,0,0,0,2,0,0,0,0,0,0,0,"Expedition Warden - Within 0-20 Range - Cast 'Net'"),
(17855,0,1,0,0,0,100,0,0,0,2000,4000,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Expedition Warden - In Combat - Cast 'Shoot'"),
(17855,0,2,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Expedition Warden - On Aggro - Cast Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=17855;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(17855,0,0,"Taste blade, mongrel!",12,0,100,0,0,0,10950,0,"Expedition Warden"),
(17855,0,1,"Please tell me that you didn't just do what I think you just did. Please tell me that I'm not going to have to hurt you...",12,0,100,0,0,0,10951,0,"Expedition Warden"),
(17855,0,2,"As if we don't have enough problems, you go and create more!",12,0,100,0,0,0,10953,0,"Expedition Warden"),
(17855,0,3,"You dare spill blood on neutral ground? OUT! OUT, I SAY!",12,0,100,0,0,0,10948,0,"Expedition Warden"),
(17855,0,4,"We don't take kindly to miscreants, $r.",12,0,100,0,0,0,10949,0,"Expedition Warden"),
(17855,0,5,"Get a rope!",12,0,100,0,0,0,10952,0,"Expedition Warden"),
(17855,0,6,"Believe me when I tell you this: You're gonna wish you weren't born, sissy!",12,0,100,0,0,0,10954,0,"Expedition Warden"),
(17855,0,7,"Your actions shame us all, $c. I hurt inside as I beat you senseless.",12,0,100,0,0,0,10955,0,"Expedition Warden");

-- Scout Manslayer
DELETE FROM `smart_scripts` WHERE `entryorguid`=14376 AND `source_type`=0 AND `id` IN (1,2,3);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14376,0,1,0,9,0,100,0,0,30,8000,12000,11,14030,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scout Manslayer - Within 0-30 Range - Cast 'Hooked Net'"),
(14376,0,2,0,0,0,100,0,5000,7000,5000,9000,11,15572,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scout Manslayer - In Combat - Cast 'Sunder Armor'"),
(14376,0,3,0,0,0,100,0,0,0,2000,4000,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Scout Manslayer - In Combat - Cast 'Shoot'");

-- Scout Tharr
DELETE FROM `smart_scripts` WHERE `entryorguid`=14377 AND `source_type`=0 AND `id` IN (1,2,3);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14377,0,1,0,9,0,100,0,0,30,8000,12000,11,14030,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scout Tharr - Within 0-30 Range - Cast 'Hooked Net'"),
(14377,0,2,0,0,0,100,0,5000,7000,5000,9000,11,15572,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scout Tharr - In Combat - Cast 'Sunder Armor'"),
(14377,0,3,0,0,0,100,0,0,0,2000,4000,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Scout Tharr - In Combat - Cast 'Shoot'");

-- Cenarion Hold Infantry
DELETE FROM `smart_scripts` WHERE `entryorguid`=15184 AND `source_type`=0 AND `id`=4;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(15184,0,4,0,0,0,100,0,0,0,2000,4000,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Cenarion Hold Infantry - In Combat - Cast 'Shoot'");

UPDATE `creature_template` SET `flags_extra`=32768  WHERE `entry` IN (1756);
UPDATE `creature_template` SET `faction`=105 WHERE `entry` IN (3084);
