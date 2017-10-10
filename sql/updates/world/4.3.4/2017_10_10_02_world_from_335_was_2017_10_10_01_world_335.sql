/*
-- Spitelash Screamer
UPDATE `creature_template` SET `AIName`="SmartAI", `ScriptName`="" WHERE `entry`=6193;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6193 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6193,0,0,0,8,0,100,1,118,0,0,0,80,619300,2,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Screamer - On Spellhit 'Polymorph' - Run Script"),
(6193,0,1,0,8,0,100,1,12824,0,0,0,80,619300,2,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Screamer - On Spellhit 'Polymorph' - Run Script"),
(6193,0,2,0,8,0,100,1,12825,0,0,0,80,619300,2,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Screamer - On Spellhit 'Polymorph' - Run Script"),
(6193,0,3,0,8,0,100,1,12826,0,0,0,80,619300,2,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Screamer - On Spellhit 'Polymorph' - Run Script"),
(6193,0,4,0,0,0,100,0,7000,9000,12000,15000,11,3589,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Screamer - In Combat - Cast Deafening Screech"),
(6193,0,5,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Screamer - Between 0-15% Health - Flee For Assist (No Repeat)");

DELETE FROM `smart_scripts` WHERE `entryorguid`=619300 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(619300,9,0,0,0,0,100,0,4000,4000,0,0,11,28406,2,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Screamer - On Script - Cast Polymorph Backfire"),
(619300,9,1,0,0,0,100,0,0,0,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Screamer - On Script - root"),
(619300,9,2,0,0,0,100,0,0,0,0,0,3,0,11686,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Screamer - On Script - morph"),
(619300,9,3,0,0,0,100,0,0,0,0,0,11,60034,64,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Screamer - On Script - Cast smoke"),
(619300,9,4,0,0,0,100,0,1000,1000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Screamer - On Script - Despawn");
-- Spitelash Warrior
UPDATE `creature_template` SET `AIName`="SmartAI", `ScriptName`="" WHERE `entry`=6190;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6190 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6190,0,0,0,8,0,100,1,118,0,0,0,80,619300,2,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Warrior - On Spellhit 'Polymorph' - Run Script"),
(6190,0,1,0,8,0,100,1,12824,0,0,0,80,619300,2,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Warrior - On Spellhit 'Polymorph' - Run Script"),
(6190,0,2,0,8,0,100,1,12825,0,0,0,80,619300,2,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Warrior - On Spellhit 'Polymorph' - Run Script"),
(6190,0,3,0,8,0,100,1,12826,0,0,0,80,619300,2,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Warrior - On Spellhit 'Polymorph' - Run Script"),
(6190,0,4,0,0,0,100,0,6000,9000,11000,15000,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spitelash Warrior - In Combat - Cast Disarm");

-- Spitelash Serpent Guard
UPDATE `creature_template` SET `AIName`="SmartAI", `ScriptName`="" WHERE `entry`=6194;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6194 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6194,0,0,0,8,0,100,1,118,0,0,0,80,619300,2,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Serpent Guard - On Spellhit 'Polymorph' - Run Script"),
(6194,0,1,0,8,0,100,1,12824,0,0,0,80,619300,2,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Serpent Guard - On Spellhit 'Polymorph' - Run Script"),
(6194,0,2,0,8,0,100,1,12825,0,0,0,80,619300,2,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Serpent Guard - On Spellhit 'Polymorph' - Run Script"),
(6194,0,3,0,8,0,100,1,12826,0,0,0,80,619300,2,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Serpent Guard - On Spellhit 'Polymorph' - Run Script"),
(6194,0,4,0,0,0,100,0,6000,8000,9000,13000,11,25710,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spitelash Serpent Guard - In Combat - Cast Heroic Strike"),
(6194,0,5,0,13,0,100,0,20000,30000,0,0,11,34783,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Serpent Guard - Target Casting - Cast Spell Reflection");

-- Spitelash Siren
UPDATE `creature_template` SET `AIName`="SmartAI", `ScriptName`="" WHERE `entry`=6195;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6195 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6195,0,0,0,8,0,100,1,118,0,0,0,80,619300,2,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Siren - On Spellhit 'Polymorph' - Run Script"),
(6195,0,1,0,8,0,100,1,12824,0,0,0,80,619300,2,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Siren - On Spellhit 'Polymorph' - Run Script"),
(6195,0,2,0,8,0,100,1,12825,0,0,0,80,619300,2,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Siren - On Spellhit 'Polymorph' - Run Script"),
(6195,0,3,0,8,0,100,1,12826,0,0,0,80,619300,2,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Siren - On Spellhit 'Polymorph' - Run Script"),
(6195,0,4,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Spitelash Siren - In Combat - Cast Shoot"),
(6195,0,5,0,0,0,100,0,3000,5000,12000,16000,11,12551,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spitelash Siren - In Combat - Cast Frost Shot"),
(6195,0,6,0,9,0,100,0,0,8,13000,15000,11,11831,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Siren - Within 0-8 Range - Cast Frost Nova"),
(6195,0,7,0,14,0,100,0,1200,40,12000,17000,11,11640,0,0,0,0,0,7,0,0,0,0,0,0,0,"Spitelash Siren - Friendly At 1200 Health - Cast Renew"),
(6195,0,8,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Siren - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Spitelash Myrmidon
UPDATE `creature_template` SET `AIName`="SmartAI", `ScriptName`="" WHERE `entry`=6196;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6196 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6196,0,0,0,8,0,100,1,118,0,0,0,80,619300,2,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Myrmidon - On Spellhit 'Polymorph' - Run Script"),
(6196,0,1,0,8,0,100,1,12824,0,0,0,80,619300,2,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Myrmidon - On Spellhit 'Polymorph' - Run Script"),
(6196,0,2,0,8,0,100,1,12825,0,0,0,80,619300,2,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Myrmidon - On Spellhit 'Polymorph' - Run Script"),
(6196,0,3,0,8,0,100,1,12826,0,0,0,80,619300,2,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Myrmidon - On Spellhit 'Polymorph' - Run Script"),
(6196,0,4,0,0,0,100,0,5000,7000,6000,9000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spitelash Myrmidon - In Combat - Cast Strike");

-- Spitelash Battlemaster
UPDATE `creature_template` SET `AIName`="SmartAI", `ScriptName`="" WHERE `entry`=7885;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7885 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7885,0,0,0,8,0,100,1,118,0,0,0,80,619300,2,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Battlemaster - On Spellhit 'Polymorph' - Run Script"),
(7885,0,1,0,8,0,100,1,12824,0,0,0,80,619300,2,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Battlemaster - On Spellhit 'Polymorph' - Run Script"),
(7885,0,2,0,8,0,100,1,12825,0,0,0,80,619300,2,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Battlemaster - On Spellhit 'Polymorph' - Run Script"),
(7885,0,3,0,8,0,100,1,12826,0,0,0,80,619300,2,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Battlemaster - On Spellhit 'Polymorph' - Run Script"),
(7885,0,4,0,9,0,100,1,5,30,0,0,11,22120,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spitelash Battlemaster - Within 5-30 Range - Cast Charge (No Repeat)");

-- Spitelash Enchantress
UPDATE `creature_template` SET `AIName`="SmartAI", `ScriptName`="" WHERE `entry`=7886;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7886 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7886,0,0,0,8,0,100,1,118,0,0,0,80,619300,2,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Enchantress - On Spellhit 'Polymorph' - Run Script"),
(7886,0,1,0,8,0,100,1,12824,0,0,0,80,619300,2,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Enchantress - On Spellhit 'Polymorph' - Run Script"),
(7886,0,2,0,8,0,100,1,12825,0,0,0,80,619300,2,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Enchantress - On Spellhit 'Polymorph' - Run Script"),
(7886,0,3,0,8,0,100,1,12826,0,0,0,80,619300,2,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Enchantress - On Spellhit 'Polymorph' - Run Script"),
(7886,0,4,0,0,0,100,0,0,0,2400,3800,11,15791,64,0,0,0,0,2,0,0,0,0,0,0,0,"Spitelash Enchantress - In Combat - Cast Arcane Missiles"),
(7886,0,5,0,0,0,100,0,5000,9000,18000,24000,11,3443,2,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Enchantress - In Combat - Cast Enchanted Quickness"),
(7886,0,6,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Enchantress - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Polymorph Clone
UPDATE `creature_template` SET `AIName`="SmartAI", `ScriptName`="" WHERE `entry`=16479;
DELETE FROM `smart_scripts` WHERE `entryorguid`=16479 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(16479,0,0,1,1,0,100,1,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Polymorph Clone - OOC - React passif"),
(16479,0,1,0,61,0,100,1,0,0,0,0,89,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Polymorph Clone - OOC - Random movements");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN (6193, 6194, 6190, 6195, 6196, 7885, 7886);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,1,6193,0,0,9,0,9364,0,0,0,0,0,"","Execute SAI only if player has quest 'Fragmented Magic'"),
(22,1,6194,0,0,9,0,9364,0,0,0,0,0,"","Execute SAI only if player has quest 'Fragmented Magic'"),
(22,1,6190,0,0,9,0,9364,0,0,0,0,0,"","Execute SAI only if player has quest 'Fragmented Magic'"),
(22,1,6195,0,0,9,0,9364,0,0,0,0,0,"","Execute SAI only if player has quest 'Fragmented Magic'"),
(22,1,6196,0,0,9,0,9364,0,0,0,0,0,"","Execute SAI only if player has quest 'Fragmented Magic'"),
(22,1,7885,0,0,9,0,9364,0,0,0,0,0,"","Execute SAI only if player has quest 'Fragmented Magic'"),
(22,1,7886,0,0,9,0,9364,0,0,0,0,0,"","Execute SAI only if player has quest 'Fragmented Magic'"),
(22,2,6193,0,0,9,0,9364,0,0,0,0,0,"","Execute SAI only if player has quest 'Fragmented Magic'"),
(22,2,6194,0,0,9,0,9364,0,0,0,0,0,"","Execute SAI only if player has quest 'Fragmented Magic'"),
(22,2,6190,0,0,9,0,9364,0,0,0,0,0,"","Execute SAI only if player has quest 'Fragmented Magic'"),
(22,2,6195,0,0,9,0,9364,0,0,0,0,0,"","Execute SAI only if player has quest 'Fragmented Magic'"),
(22,2,6196,0,0,9,0,9364,0,0,0,0,0,"","Execute SAI only if player has quest 'Fragmented Magic'"),
(22,2,7885,0,0,9,0,9364,0,0,0,0,0,"","Execute SAI only if player has quest 'Fragmented Magic'"),
(22,2,7886,0,0,9,0,9364,0,0,0,0,0,"","Execute SAI only if player has quest 'Fragmented Magic'"),
(22,3,6193,0,0,9,0,9364,0,0,0,0,0,"","Execute SAI only if player has quest 'Fragmented Magic'"),
(22,3,6194,0,0,9,0,9364,0,0,0,0,0,"","Execute SAI only if player has quest 'Fragmented Magic'"),
(22,3,6190,0,0,9,0,9364,0,0,0,0,0,"","Execute SAI only if player has quest 'Fragmented Magic'"),
(22,3,6195,0,0,9,0,9364,0,0,0,0,0,"","Execute SAI only if player has quest 'Fragmented Magic'"),
(22,3,6196,0,0,9,0,9364,0,0,0,0,0,"","Execute SAI only if player has quest 'Fragmented Magic'"),
(22,3,7885,0,0,9,0,9364,0,0,0,0,0,"","Execute SAI only if player has quest 'Fragmented Magic'"),
(22,3,7886,0,0,9,0,9364,0,0,0,0,0,"","Execute SAI only if player has quest 'Fragmented Magic'"),
(22,4,6193,0,0,9,0,9364,0,0,0,0,0,"","Execute SAI only if player has quest 'Fragmented Magic'"),
(22,4,6194,0,0,9,0,9364,0,0,0,0,0,"","Execute SAI only if player has quest 'Fragmented Magic'"),
(22,4,6190,0,0,9,0,9364,0,0,0,0,0,"","Execute SAI only if player has quest 'Fragmented Magic'"),
(22,4,6195,0,0,9,0,9364,0,0,0,0,0,"","Execute SAI only if player has quest 'Fragmented Magic'"),
(22,4,6196,0,0,9,0,9364,0,0,0,0,0,"","Execute SAI only if player has quest 'Fragmented Magic'"),
(22,4,7885,0,0,9,0,9364,0,0,0,0,0,"","Execute SAI only if player has quest 'Fragmented Magic'"),
(22,4,7886,0,0,9,0,9364,0,0,0,0,0,"","Execute SAI only if player has quest 'Fragmented Magic'");
*/
