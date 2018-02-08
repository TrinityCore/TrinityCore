/*
-- Quest "Set Them Ablaze!"
-- Squire Maltrake
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8509;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8509 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8509,0,0,0,20,0,100,0,3463,0,0,0,45,1,1,0,0,0,0,19,8479,0,0,0,0,0,0,"Squire Maltrake - On Quest 'Set Them Ablaze!' Finished - Set Data to Kalaran Windblade");

-- Kalaran Windblade
DELETE FROM `smart_scripts` WHERE `entryorguid`=8479 AND `source_type`=0 AND `id` IN (7,8);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8479,0,7,0,38,0,100,0,1,1,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kalaran Windblade - On Data Set - Despawn"),
(8479,0,8,0,38,0,100,0,1,1,0,0,12,8480,3,68000,0,0,0,1,0,0,0,0,0,0,0,"Kalaran Windblade - On Data Set - Summon Creature 'Kalaran the Deceiver'");

-- Kalaran the Deceiver
UPDATE `creature_template` SET `AIName`="SmartAI", `InhabitType`=7, `speed_run`=2 WHERE `entry`=8480;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8480 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=848000 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8480,0,0,0,54,0,100,0,0,0,0,0,80,848000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kalaran the Deceiver - Just Summoned - Run Script"),
(848000,9,0,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kalaran the Deceiver - On Script - Say Line 0"),
(848000,9,1,0,0,0,100,0,3000,3000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kalaran the Deceiver - On Script - Say Line 1"),
(848000,9,2,0,0,0,100,0,4000,4000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kalaran the Deceiver - On Script - Say Line 2"),
(848000,9,3,0,0,0,100,0,6000,6000,0,0,1,0,0,0,0,0,0,19,8509,0,0,0,0,0,0,"Kalaran the Deceiver - On Script - Say Line 0 (Squire Maltrake)"),
(848000,9,4,0,0,0,100,0,2000,2000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.65994,"Kalaran the Deceiver - On Script - Set Orientation"),
(848000,9,5,0,0,0,100,0,3000,3000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kalaran the Deceiver - On Script - Say Line 3"),
(848000,9,6,0,0,0,100,0,3000,3000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kalaran the Deceiver - On Script - Say Line 4"),
(848000,9,7,0,0,0,100,0,9000,9000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kalaran the Deceiver - On Script - Say Line 5"),
(848000,9,8,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,19,8509,0,0,0,0,0,0,"Kalaran the Deceiver - On Script - Say Line 1 (Squire Maltrake)"),
(848000,9,9,0,0,0,100,0,3000,3000,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kalaran the Deceiver - On Script - Say Line 6"),
(848000,9,10,0,0,0,100,0,4000,4000,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kalaran the Deceiver - On Script - Say Line 7"),
(848000,9,11,0,0,0,100,0,5000,5000,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kalaran the Deceiver - On Script - Say Line 8"),
(848000,9,12,0,0,0,100,0,6000,6000,0,0,69,0,0,0,0,0,0,8,0,0,0,-6879.3,-1187.34,293.384,0,"Kalaran the Deceiver - On Script - Move to Position");

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (8480, 8509);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(8480,0,0,"Glorious, indeed, Maltrake. It looks as if my plan worked perfectly. Wouldn't you say so, mortal?",12,0,100,0,0,0,4456,0,"Kalaran the Deceiver"),
(8480,1,0,"%s lets loose a reptilian laugh... at least you think it's a laugh.",16,0,100,0,0,0,4458,0,"Kalaran the Deceiver"),
(8480,2,0,"You would not have helped the legion of Blackrock had we just asked for your assistance, now would you?",12,0,100,0,0,0,4457,0,"Kalaran the Deceiver"),
(8480,3,0,"SILENCE FOOL!",12,0,100,0,0,0,4460,0,"Kalaran the Deceiver"),
(8480,4,0,"They will live, if only to see the fruits of their labor: the destruction and chaos that will surely ensue as the legion of Blackrock invade the gorge.",12,0,100,0,0,0,4461,0,"Kalaran the Deceiver"),
(8480,5,0,"I leave you now, mortals. Alive and with these trinkets. Maltrake! Present them with the trinkets!",12,0,100,0,0,0,4462,0,"Kalaran the Deceiver"),
(8480,6,0,"Oh yes, the molt - do not lose it. There are those of my kin in the Burning Steppes that would craft items that only the molt of the black Dragonflight could fortify.",12,0,100,0,0,0,4463,0,"Kalaran the Deceiver"),
(8480,7,0,"%s begins to flap his massive wings faster. He is preparing for flight.",16,0,100,0,0,0,4464,0,"Kalaran the Deceiver"),
(8480,8,0,"The legion of Blackrock comes, dwarflings! We shall scorch the earth and set fire to the heavens. None shall survive...",14,0,100,0,0,0,4465,0,"Kalaran the Deceiver"),
(8509,0,0,"What will we do with them, master? They are of no use to us anymore.",12,0,100,6,0,0,4459,0,"Squire Maltrake"),
(8509,1,0,"Right away, master!",12,0,100,2,0,0,4468,0,"Squire Maltrake");
*/
