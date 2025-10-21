--
DELETE FROM `smart_scripts` WHERE `entryorguid` = 25728 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(25728,0,0,0,0,0,100,0,5000,12000,22000,26000,0,11,50416,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Coldarra Wyrmkin - In Combat - Cast 'Frostbite Weapon'"),
(25728,0,1,0,83,0,100,0,50416,0,0,0,0,71,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Coldarra Wyrmkin - On Spell Cast 'Frostbite Weapon' - Change Equipment"),
(25728,0,2,0,8,0,100,0,36294,0,0,0,0,71,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Coldarra Wyrmkin - On Spellhit 'Trigger 000' - Change Equipment"),
(25728,0,3,0,7,0,100,0,0,0,0,0,0,71,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Coldarra Wyrmkin - On Evade - Change Equipment");

--
UPDATE `creature_text` SET `Emote` = 6 WHERE `CreatureID` = 32641;
UPDATE `creature_text` SET `Emote` = 1 WHERE `CreatureID` = 32642;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (32641,32642) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3264100,3264200) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(32641,0,0,0,90,0,100,0,61424,0,0,0,0,80,3264100,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Drix Blackwrench - On Aura 'Traveler's Tundra Mammoth' Removed - Run Script"),

(3264100,9,0,0,0,0,100,0,1000,1000,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Drix Blackwrench - On Script - Set Orientation Owner"),
(3264100,9,1,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Drix Blackwrench - On Script - Say Line 0"),
(3264100,9,2,0,0,0,100,0,1000,1000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Drix Blackwrench - On Script - Despawn"),

(32642,0,0,0,90,0,100,0,61424,0,0,0,0,80,3264200,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mojodishu - On Aura 'Traveler's Tundra Mammoth' Removed - Run Script"),

(3264200,9,0,0,0,0,100,0,1000,1000,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Mojodishu - On Script - Set Orientation Owner"),
(3264200,9,1,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Mojodishu - On Script - Say Line 0"),
(3264200,9,2,0,0,0,100,0,1000,1000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mojodishu - On Script - Despawn");

--
UPDATE `creature_text` SET `Emote` = 6 WHERE `CreatureID` = 32638;
UPDATE `creature_text` SET `Emote` = 3 WHERE `CreatureID` = 32639;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (32638,32639) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3263800,3263900) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(32638,0,0,0,90,0,100,0,61424,0,0,0,0,80,3263800,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hakmud of Argus - On Aura 'Traveler's Tundra Mammoth' Removed - Run Script"),

(3263800,9,0,0,0,0,100,0,1000,1000,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Hakmud of Argus - On Script - Set Orientation Owner"),
(3263800,9,1,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Hakmud of Argus - On Script - Say Line 0"),
(3263800,9,2,0,0,0,100,0,1000,1000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hakmud of Argus - On Script - Despawn"),

(32639,0,0,0,90,0,100,0,61424,0,0,0,0,80,3263900,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Gnimo - On Aura 'Traveler's Tundra Mammoth' Removed - Run Script"),

(3263900,9,0,0,0,0,100,0,1000,1000,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Gnimo - On Script - Set Orientation Owner"),
(3263900,9,1,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Gnimo - On Script - Say Line 0"),
(3263900,9,2,0,0,0,100,0,1000,1000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Gnimo - On Script - Despawn");

--
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (35008,35602) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(35008,0,0,0,60,0,100,0,0,10000,10000,15000,0,11,12544,32,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sawemba - On Update - Cast 'Frost Armor'"),
(35008,0,1,0,0,0,100,0,0,0,3000,4000,0,11,12466,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Sawemba - In Combat - Cast 'Fireball'"),
(35008,0,2,0,0,0,100,0,5000,10000,5000,10000,0,11,12737,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Sawemba - In Combat - Cast 'Frostbolt'"),
(35008,0,3,0,0,0,100,0,5000,10000,10000,15000,0,11,14145,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Sawemba - In Combat - Cast 'Fire Blast'"),
(35008,0,4,0,0,0,100,0,10000,15000,15000,20000,0,11,12738,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Sawemba - In Combat - Cast 'Amplify Damage'"),
-- Just copied from 35008, we don't know what spells this one uses, he's unnattackable any way, should he be attackable?
(35602,0,0,0,60,0,100,0,0,10000,10000,15000,0,11,12544,32,0,0,0,0,1,0,0,0,0,0,0,0,0,"Magister Savarin - On Update - Cast 'Frost Armor'"),
(35602,0,1,0,0,0,100,0,0,0,3000,4000,0,11,12466,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Magister Savarin - In Combat - Cast 'Fireball'"),
(35602,0,2,0,0,0,100,0,5000,10000,5000,10000,0,11,12737,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Magister Savarin - In Combat - Cast 'Frostbolt'"),
(35602,0,3,0,0,0,100,0,5000,10000,10000,15000,0,11,14145,0,0,0,0,0,5,0,0,0,0,0,0,0,0,"Magister Savarin - In Combat - Cast 'Fire Blast'"),
(35602,0,4,0,0,0,100,0,10000,15000,15000,20000,0,11,12738,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Magister Savarin - In Combat - Cast 'Amplify Damage'");

--
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (29690,29733) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(29690,0,0,0,60,0,100,0,0,10000,10000,15000,0,11,12550,32,0,0,0,0,1,0,0,0,0,0,0,0,0,"Chief Rageclaw - On Update - Cast 'Lightning Shield'"),

(29733,0,0,0,60,0,100,0,0,10000,10000,15000,0,11,12550,32,0,0,0,0,1,0,0,0,0,0,0,0,0,"Elder Shaman Moky - On Update - Cast 'Lightning Shield'");

-- Quest 12111
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (26482,26615) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2648200,2661500) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26482,0,0,0,8,0,100,0,47628,0,0,0,0,80,2648200,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Arctic Grizzly - On Spellhit 'Wildlife Inoculation' - Run Script"),

(2648200,9,0,0,0,0,100,0,0,0,0,0,0,11,47675,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Arctic Grizzly - On Script - Cast 'Recently Inoculated'"),
(2648200,9,1,0,0,0,100,0,0,0,0,0,0,11,47665,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Arctic Grizzly - On Script - Cast 'Arctic Grizzly Credit'"),

(26615,0,0,0,8,0,100,0,47628,0,0,0,0,80,2661500,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Snowfall Elk - On Spellhit 'Wildlife Inoculation' - Run Script"),
(26615,0,1,0,0,0,100,0,5000,10000,5000,10000,0,11,15976,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Snowfall Elk - In Combat - Cast 'Puncture'"),

(2661500,9,0,0,0,0,100,0,0,0,0,0,0,11,47675,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Snowfall Elk - On Script - Cast 'Recently Inoculated'"),
(2661500,9,1,0,0,0,100,0,0,0,0,0,0,11,47664,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Snowfall Elk - On Script - Cast 'Arctic Grizzly Credit'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` IN (26482,26615) AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,26482,0,0,1,1,47675,0,0,1,0,0,"","Group 0: Execute SAI (Action 0) if creature does not have aura 'Recently Inoculated'"),
(22,1,26615,0,0,1,1,47675,0,0,1,0,0,"","Group 0: Execute SAI (Action 0) if creature does not have aura 'Recently Inoculated'");

--
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (19945,19985) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(19945,0,0,0,60,0,100,0,0,10000,10000,15000,0,11,12550,32,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lashh'an Windwalker - On Update - Cast 'Lightning Shield'"),
(19945,0,1,0,0,0,100,0,0,0,3000,4000,0,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Lashh'an Windwalker - In Combat CMC - Cast 'Lightning Bolt'"),

(19985,0,0,0,60,0,100,0,0,10000,10000,15000,0,11,12550,32,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ruuan'ok Cloudgazer - On Update - Cast 'Lightning Shield'"),
(19985,0,1,0,0,0,100,0,0,0,3000,4000,0,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Ruuan'ok Cloudgazer - In Combat CMC - Cast 'Lightning Bolt'");

--
UPDATE `smart_scripts` SET `event_type` = 60 , `event_param1` = 0 , `event_param2` = 10000 , `event_param3` = 10000, `event_param4` = 15000, `action_param2` = 32, `comment` = "Cryo-Engineer Sha'heen - On Update - Cast 'Vir'aani Concentration'" WHERE `entryorguid` = 19671 AND `source_type` = 0 AND `id` = 4;

--
DELETE FROM `smart_scripts` WHERE `entryorguid` = 8409 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8409,0,0,0,60,0,100,0,0,10000,10000,15000,0,11,12544,32,0,0,0,0,1,0,0,0,0,0,0,0,0,"Caravan Master Tset - On Update - Cast 'Frost Armor'"),
(8409,0,1,0,0,0,100,0,0,0,3000,5000,0,11,9672,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Caravan Master Tset - In Combat CMC - Cast 'Frostbolt'"),
(8409,0,2,0,0,0,100,0,5000,10000,10000,15000,0,11,11831,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Caravan Master Tset - In Combat - Cast 'Frost Nova'");

--
DELETE FROM `smart_scripts` WHERE `entryorguid` = 9397 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(9397,0,0,0,60,0,100,0,0,10000,10000,15000,0,11,12550,32,0,0,0,0,1,0,0,0,0,0,0,0,0,"Living Storm - On Update - Cast 'Lightning Shield'");

--
UPDATE `creature_addon` SET `auras` = '48356' WHERE `guid` IN (129253,129254,129256,129261,129262);
UPDATE `creature_template_addon` SET `auras` = '48356' WHERE `entry` = 28608;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (28608,28609,28611) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(28608,0,0,0,4,0,30,0,0,0,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Scarlet Medic - On Aggro - Say Line 0"),
(28608,0,1,0,60,0,100,0,0,10000,10000,15000,0,11,13864,32,0,0,0,0,1,0,0,0,0,0,0,0,0,"Scarlet Medic - On Update - Cast 'Power Word: Fortitude'"),
(28608,0,2,0,0,0,100,0,0,0,3400,4800,0,11,15498,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Scarlet Medic - In Combat CMC - Cast 'Holy Smite'"),

(28609,0,0,0,4,0,30,0,0,0,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Scarlet Infantryman - On Aggro - Say Line 0"),
(28609,0,1,0,0,0,100,0,5000,10000,5000,10000,0,11,25710,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Scarlet Infantryman - In Combat - Cast 'Heroic Strike'"),
(28609,0,2,0,0,0,100,0,5000,15000,5000,15000,0,11,53399,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Scarlet Infantryman - In Combat - Cast 'Sweeping Slam'"),

(28611,0,0,0,4,0,30,0,0,0,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Scarlet Captain - On Aggro - Say Line 0"),
(28611,0,1,0,0,0,100,0,5000,10000,5000,10000,0,11,52221,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Scarlet Captain - In Combat - Cast 'Heroic Strike'");

--
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1769 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1769,0,0,0,60,0,100,0,0,10000,10000,15000,0,11,12544,32,0,0,0,0,1,0,0,0,0,0,0,0,0,"Moonrage Whitescalp - On Update - Cast 'Frost Armor'");

--
DELETE FROM `smart_scripts` WHERE `entryorguid` = 24917 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24917,0,0,0,60,0,100,0,0,10000,10000,15000,0,11,35319,32,0,0,0,0,1,0,0,0,0,0,0,0,0,"Phase Wyrm - On Update - Cast 'Electric Skin'");

--
UPDATE `creature_addon` SET `auras` = '21862' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 23680);
UPDATE `creature_template_addon` SET `auras` = '21862' WHERE `entry` = 23680;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 23680 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23680,0,0,0,0,0,100,0,5000,10000,10000,15000,0,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Plagued Proto-Dragon - In Combat - Cast 'Thrash'"),
(23680,0,1,0,0,0,100,0,5000,10000,10000,20000,0,11,9573,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Plagued Proto-Dragon - In Combat - Cast 'Flame Breath'");

--
UPDATE `smart_scripts` SET `event_type` = 60, `event_param1` = 0, `event_param2` = 10000, `event_param3` = 10000, `event_param4` = 15000, `action_param2` = 32, `comment` = "Gor'drek - On Update - Cast 'Lightning Shield'" WHERE `entryorguid` = 21117 AND `source_type` = 0 AND `id` = 0;

--
UPDATE `creature_template` SET `AIName` = '' WHERE `entry` = 28181;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 28181 AND `source_type` = 0;

DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 28181);
UPDATE `creature_template_addon` SET `SheathState` = 1, `auras` = '50795' WHERE `entry` = 28181;

--
DELETE FROM `smart_scripts` WHERE `entryorguid` = 23590 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23590,0,0,0,60,0,100,0,0,10000,10000,15000,0,11,12544,32,0,0,0,0,1,0,0,0,0,0,0,0,0,"Defias Conjuror - On Update - Cast 'Frost Armor'"),
(23590,0,1,0,0,0,100,0,0,0,3400,4800,0,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Defias Conjuror - In Combat CMC - Cast 'Fireball'"),
(23590,0,2,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Defias Conjuror - Between 0-15% Health - Flee For Assist (No Repeat)");

--
DELETE FROM `smart_scripts` WHERE `entryorguid` = 20673 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(20673,0,0,0,60,0,100,0,0,10000,10000,15000,0,11,19514,32,0,0,0,0,1,0,0,0,0,0,0,0,0,"Swiftwing Shredder - On Update - Cast 'Lightning Shield'"),
(20673,0,1,0,0,0,100,0,0,0,3400,4800,0,11,36594,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Swiftwing Shredder - In Combat CMC - Cast 'Lightning Breath'");

--
UPDATE `npc_spellclick_spells` SET `spell_id` = 63125, `cast_flags` = 1 WHERE `npc_entry` = 33498;

UPDATE `creature` SET `orientation` = 5.585053443908691406, `spawntimesecs` = 30 WHERE `id` = 33498; -- Sniff

DELETE FROM `smart_scripts` WHERE `entryorguid` = 33498 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
-- Spellclick flag stuff should be trickier here, not sure how exactly it's done, we just keep on aura applied \ removed variant in case
-- spellclick wasn't done but flag was added
(33498,0,0,0,89,0,100,0,63124,0,0,0,0,82,16777216,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Maloric - On Aura 'Incapacitate Maloric' Applied - Add Npc Flag Spellclick"),
(33498,0,1,0,90,0,100,0,63124,0,0,0,0,83,16777216,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Maloric - On Aura 'Incapacitate Maloric' Removed - Remove Npc Flag Spellclick"),
(33498,0,2,0,8,0,100,0,63125,0,0,0,0,11,63126,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Maloric - On Spellhit 'Search Maloric' - Cast 'Search Maloric'"),
(33498,0,3,0,8,0,100,0,63125,0,0,0,0,83,16777216,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Maloric - On Spellhit 'Search Maloric' - Remove Npc Flag Spellclick");

--
DELETE FROM `smart_scripts` WHERE `entryorguid` = 5822 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5822,0,0,0,25,0,100,0,0,0,0,0,0,11,12746,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Felweaver Scornn - On Reset - Cast 'Summon Voidwalker'"),
(5822,0,1,0,60,0,100,0,0,10000,10000,15000,0,11,20798,32,0,0,0,0,1,0,0,0,0,0,0,0,0,"Felweaver Scornn - On Update - Cast 'Demon Skin'"),
(5822,0,2,0,0,0,100,0,0,0,3400,4600,0,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Felweaver Scornn - In Combat CMC - Cast 'Shadow Bolt'");

--
DELETE FROM `smart_scripts` WHERE `entryorguid` = 17713 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17713,0,0,0,60,0,100,0,0,10000,10000,15000,0,11,12544,32,0,0,0,0,1,0,0,0,0,0,0,0,0,"Bloodcursed Naga - On Update - Cast 'Frost Armor'"),
(17713,0,1,0,0,0,100,0,0,0,3400,4800,0,11,20792,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Bloodcursed Naga - In Combat CMC - Cast 'Frostbolt'");
