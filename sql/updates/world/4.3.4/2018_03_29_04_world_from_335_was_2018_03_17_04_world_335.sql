/*
-- Takar the Seer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6244;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6244 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=624400 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6244,0,0,0,19,0,100,0,1738,0,0,0,80,624400,0,0,0,0,0,1,0,0,0,0,0,0,0,"Takar the Seer - On Quest 'Heartswood' Taken - Run Script"),
(624400,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Takar the Seer - On Script - Remove Npc Flag Questgiver"),
(624400,9,1,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Takar the Seer - On Script - Say Line 0"),
(624400,9,2,0,0,0,100,0,7000,7000,0,0,11,7794,0,0,0,0,0,1,0,0,0,0,0,0,0,"Takar the Seer - On Script - Cast 'Teleport'"),
(624400,9,3,0,0,0,100,0,1000,1000,0,0,12,6245,3,51000,0,0,0,8,0,0,0,-2246.8,-2369.11,91.6667,0.623109,"Takar the Seer - On Script - Summon Creature 'Anathera'"),
(624400,9,4,0,0,0,100,0,0,0,0,0,12,6246,3,51000,0,0,0,8,0,0,0,-2248.94,-2371.09,91.6667,3.65082,"Takar the Seer - On Script - Summon Creature 'Latherion'"),
(624400,9,5,0,0,0,100,0,2000,2000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Takar the Seer - On Script - Say Line 1"),
(624400,9,6,0,0,0,100,0,7000,7000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Takar the Seer - On Script - Say Line 2"),
(624400,9,7,0,0,0,100,0,8000,8000,0,0,90,7,0,0,0,0,0,19,6245,0,0,0,0,0,0,"Takar the Seer - On Script - Set Flag Standstate 'Dead' (Anathera)"),
(624400,9,8,0,0,0,100,0,1000,1000,0,0,45,1,1,0,0,0,0,19,6246,0,0,0,0,0,0,"Takar the Seer - On Script - Set Data to Latherion"),
(624400,9,9,0,0,0,100,0,6000,6000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Takar the Seer - On Script - Say Line 3"),
(624400,9,10,0,0,0,100,0,9000,9000,0,0,91,8,0,0,0,0,0,19,6246,0,0,0,0,0,0,"Takar the Seer - On Script - Remove Flag Standstate 'Kneel' (Latherion)"),
(624400,9,11,0,0,0,100,0,0,0,0,0,90,7,0,0,0,0,0,19,6246,0,0,0,0,0,0,"Takar the Seer - On Script - Set Flag Standstate 'Dead' (Latherion)"),
(624400,9,12,0,0,0,100,0,3000,3000,0,0,1,1,0,0,0,0,0,19,6246,0,0,0,0,0,0,"Takar the Seer - On Script - Say Line 1 (Latherion)"),
(624400,9,13,0,0,0,100,0,10000,10000,0,0,1,0,0,0,0,0,0,19,6245,0,0,0,0,0,0,"Takar the Seer - On Script - Say Line 0 (Anathera)"),
(624400,9,14,0,0,0,100,0,5000,5000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Takar the Seer - On Script - Say Line 4"),
(624400,9,15,0,0,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Takar the Seer - On Script - Add Npc Flag Questgiver");

-- Anathera
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6245;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6245 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6245,0,0,0,11,0,100,0,0,0,0,0,17,333,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anathera - On Respawn - Set Emote State 333");

-- Latherion
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=6246;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6246 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=624600 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6246,0,0,0,11,0,100,0,0,0,0,0,17,333,0,0,0,0,0,1,0,0,0,0,0,0,0,"Latherion - On Respawn - Set Emote State 333"),
(6246,0,1,0,38,0,100,0,1,1,0,0,80,624600,0,0,0,0,0,1,0,0,0,0,0,0,0,"Latherion - On Data Set - Run Script"),
(624600,9,0,0,0,0,100,0,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Latherion - On Script - Set Emote State 0"),
(624600,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.623109,"Latherion - On Script - Set Orientation"),
(624600,9,2,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Latherion - On Script - Say Line 0"),
(624600,9,3,0,0,0,100,0,3000,3000,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Latherion - On Script - Set Flag Standstate 'Kneel'");

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (6244,6245,6246);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(6244,0,0,"A thousand years ago, the immortal elves, demigods of the forest and dragons fought against the Legion on the slopes of Hyjal.",12,7,100,1,0,0,2310,0,"Takar the Seer"),
(6244,1,0,"Anathera and Latherion fought back to back where the battle was thickest. Two lovers determined to survive the war together.",12,7,100,1,0,0,2311,0,"Takar the Seer"),
(6244,2,0,"But it was not to be. As their foes pressed close, Anathera's armor was pierced by a demon's tainted blade. In the thick of battle, there would be nothing to save her.",12,7,100,1,0,0,2312,0,"Takar the Seer"),
(6244,3,0,"Ignoring the battle that raged about him, Latherion dropped his guard to cradle his love in her dying moments. But the demons gave him no quarter, and quickly laid him low.",12,7,100,1,0,0,2314,0,"Takar the Seer"),
(6244,4,0,"Where the two lovers fell, a tree would bloom. The elves call it the heartswood. It will surely serve your ends.",12,7,100,1,0,0,2317,0,"Takar the Seer"),
(6245,0,0,"So this... this is how it ends, my love...",12,7,100,0,0,0,2316,0,"Anathera"),
(6246,0,0,"Anathera!",12,7,100,15,0,0,2313,0,"Latherion"),
(6246,1,0,"Anathera... I cannot bear to face the rest of eternity without you by my side... If you are taken from me, then let this be the day I also return to the earth...",12,7,100,0,0,0,2315,0,"Latherion");
*/
