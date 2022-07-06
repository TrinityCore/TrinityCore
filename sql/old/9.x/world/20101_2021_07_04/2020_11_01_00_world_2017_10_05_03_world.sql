-- Add waypoints and script of Lieutenant Tomathren and Ranger Valanna
SET @GUID_1 := 82035; -- Lieutenant Tomathren
SET @ENTRY_1 := 16217;
SET @ENTRY_1_A := @ENTRY_1 * 100;
SET @ENTRY_2 := 16219; -- Ranger Valanna
SET @PATHID := @GUID_1 * 10;

UPDATE `creature` SET `position_x`=7935.186, `position_y`=-7572.151, `position_z`=145.281, `orientation`=2.8516, `MovementType`=2 WHERE `guid`=@GUID_1;
DELETE FROM `creature_addon` WHERE `guid`=@GUID_1;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES (@GUID_1, @PATHID, 4098);
DELETE FROM `waypoint_data` WHERE `id`=@PATHID;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`) VALUES 
(@PATHID, 1, 7934.20, -7571.73, 145.426),
(@PATHID, 2, 7932.95, -7570.95, 145.614),
(@PATHID, 3, 7932.98, -7569.02, 145.620),
(@PATHID, 4, 7934.05, -7566.79, 145.608),
(@PATHID, 5, 7936.55, -7565.71, 145.534),
(@PATHID, 6, 7938.52, -7566.83, 145.492),
(@PATHID, 7, 7938.93, -7570.77, 144.967),
(@PATHID, 8, 7936.23, -7572.49, 145.117);

DELETE FROM `creature_text` WHERE `CreatureID` IN (@ENTRY_1, @ENTRY_2);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Probability`, `BroadcastTextId`, `comment`) VALUES
(@ENTRY_1, 0, 0, "Take that!", 12, 100, 12544, "Lieutenant Tomathren - Out of combat"),
(@ENTRY_1, 0, 1, "This isnt Silvermoon City! Where are we? Oh, I was confused there for a moment.", 12, 100, 12542, "Lieutenant Tomathren - Out of combat"),
(@ENTRY_1, 0, 2, "I tell you now, when we get back to Farstrider Enclave there will be a full accounting of your actions, Ranger Valanna! You alone were responsible for our losses and Im certain that the captain will see it my way.", 12, 100, 12543, "Lieutenant Tomathren - Out of combat"),
(@ENTRY_1, 0, 3, "Im sure to receive a commendation upon our return. We may have suffered a few losses, but overall I think we did quite nicely, dont you, Valanna?", 12, 100, 12545, "Lieutenant Tomathren - Out of combat"),
(@ENTRY_1, 0, 4, "Did I not yell at them? Pull back! Pull back and regroup with suppressing fire!!", 12, 100, 12541, "Lieutenant Tomathren - Out of combat"),
(@ENTRY_1, 0, 5, "They should have listened to me.  Then Id receive all of the accolades that are my due!", 12, 100, 12540, "Lieutenant Tomathren - Out of combat"),
(@ENTRY_2, 0, 0, "You have got to be the most incompetent officer I have ever met!", 12, 100, 22242, "Ranger Valanna - Out of combat"),
(@ENTRY_2, 0, 1, "Remind me once again why it is that I dont just leave?", 12, 100, 22241, "Ranger Valanna - Out of combat"),
(@ENTRY_2, 0, 2, "Uh huh.  Whatever you say.", 12, 100, 22238, "Ranger Valanna - Out of combat"),
(@ENTRY_2, 0, 3, "Idiot.", 12, 100, 22239, "Ranger Valanna - Out of combat"),
(@ENTRY_2, 0, 4, "Would you please shut up?!", 12, 100, 22240, "Ranger Valanna - Out of combat"),
(@ENTRY_2, 0, 5, "With all due respect, sir, stick it!", 12, 100, 22243, "Ranger Valanna - Out of combat");

-- Lieutenant Tomathren SAI + Actionlist
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY_1;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY_1) AND `source_type` IN (0);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1621700) AND `source_type` IN (9);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(16217, 0, 0, 0, 1, 0, 100, 0, 2000, 20000, 120000, 180000, 80, 1621700, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lieutenant Tomathren - Out Of Combat - Call Actionlist"),
(1621700, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lieutenant Tomathren - On Script - Talk 0"),
(1621700, 9, 1, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 16219, 0, 0, 0, 0, 0, 0, "Lieutenant Tomathren - On Script - Talk 0 (Ranger Valanna)");
