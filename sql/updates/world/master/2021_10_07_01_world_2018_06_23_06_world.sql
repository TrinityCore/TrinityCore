-- Captain Auric Sunchaser
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=18745;
DELETE FROM `smart_scripts` WHERE `entryorguid`=18745 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(18745,0,0,0,38,0,100,0,1,1,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.58753,"Captain Auric Sunchaser - On Data Set - Set Orientation"),
(18745,0,1,0,38,0,100,0,2,2,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.53786,"Captain Auric Sunchaser - On Data Set - Set Orientation");

-- Lieutenant Gravelhammer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=18713;
DELETE FROM `smart_scripts` WHERE `entryorguid`=18713 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1871300,1871301,1871302) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(18713,0,0,0,1,0,100,0,5000,15000,300000,900000,80,1871300,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lieutenant Gravelhammer - OOC - Run Script"),
(18713,0,1,0,40,0,100,0,4,18713,0,0,80,1871301,2,0,0,0,0,1,0,0,0,0,0,0,0,"Lieutenant Gravelhammer - On Waypoint 4 Reached - Run Script"),
(18713,0,2,0,40,0,100,0,7,18713,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.153880,"Lieutenant Gravelhammer - On Waypoint 7 Reached - Set Orientation"),
(1871300,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lieutenant Gravelhammer - On Script - Say Line 0"),
(1871300,9,1,0,0,0,100,0,11000,11000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lieutenant Gravelhammer - On Script - Say Line 1"),
(1871300,9,2,0,0,0,100,0,5000,5000,0,0,53,0,18713,0,0,0,0,1,0,0,0,0,0,0,0,"Lieutenant Gravelhammer - On Script - Start Waypoint"),
(1871301,9,0,0,0,0,100,0,0,0,0,0,54,35000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lieutenant Gravelhammer - On Script - Pause Waypoint"),
(1871301,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.259758,"Lieutenant Gravelhammer - On Script - Set Orientation"),
(1871301,9,2,0,0,0,100,0,200,200,0,0,45,1,1,0,0,0,0,19,18745,0,0,0,0,0,0,"Lieutenant Gravelhammer - On Script - Set Data to Captain Auric Sunchaser"),
(1871301,9,3,0,0,0,100,0,200,200,0,0,5,66,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lieutenant Gravelhammer - On Script - Play Emote 'Salute'"),
(1871301,9,4,0,0,0,100,0,3000,3000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lieutenant Gravelhammer - On Script - Say Line 2"),
(1871301,9,5,0,0,0,100,0,5000,5000,0,0,1,5,0,0,0,0,0,19,18745,0,0,0,0,0,0,"Lieutenant Gravelhammer - On Script - Say Line 5 (Captain Auric Sunchaser)"),
(1871301,9,6,0,0,0,100,0,6000,6000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lieutenant Gravelhammer - On Script - Say Line 3"),
(1871301,9,7,0,0,0,100,0,8000,8000,0,0,1,6,0,0,0,0,0,19,18745,0,0,0,0,0,0,"Lieutenant Gravelhammer - On Script - Say Line 6 (Captain Auric Sunchaser)"),
(1871301,9,8,0,0,0,100,0,8000,8000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lieutenant Gravelhammer - On Script - Say Line 4"),
(1871301,9,9,0,0,0,100,0,3000,3000,0,0,45,2,2,0,0,0,0,19,18745,0,0,0,0,0,0,"Lieutenant Gravelhammer - On Script - Set Data to Captain Auric Sunchaser");

DELETE FROM `creature_text` WHERE `CreatureID` IN (18713,18745);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(18713,0,0,"Rifling through the stacks of books and scrolls on the table, Lieutenant Gravelhammer begins to examine one in particular with interest.",16,0,100,0,0,0,15827,0,"Lieutenant Gravelhammer"),
(18713,1,0,"What?  What's this?!",12,7,100,5,0,0,15829,0,"Lieutenant Gravelhammer"),
(18713,1,1,"That is not even remotely imaginable!",12,7,100,5,0,0,15830,0,"Lieutenant Gravelhammer"),
(18713,1,2,"Looks like I picked a bad day to stop drinking.",12,7,100,5,0,0,15831,0,"Lieutenant Gravelhammer"),
(18713,1,3,"How did this get missed?!",12,7,100,5,0,0,15832,0,"Lieutenant Gravelhammer"),
(18713,2,0,"Cap'n, sir, we have a slight problem.",12,7,100,1,0,0,15833,0,"Lieutenant Gravelhammer"),
(18713,3,0,"As you say, sir.  It would appear that someone failed to mention to me that the druids at the Cenarion Thicket have been wiped out!",12,7,100,1,0,0,15838,0,"Lieutenant Gravelhammer"),
(18713,3,1,"Bad news.  We've been hit again.  They're gone, but the front sentry tower is on fire.",12,7,100,1,0,0,15839,0,"Lieutenant Gravelhammer"),
(18713,3,2,"One of our merchants has gone missing!",12,7,100,1,0,0,15840,0,"Lieutenant Gravelhammer"),
(18713,3,3,"That group that recently arrived from Honor Hold -- they're mercs!  They're starting to stir up trouble.  Maybe I should have a talk with them?",12,7,100,1,0,0,15842,0,"Lieutenant Gravelhammer"),
(18713,3,4,"One of our scouts is reporting that a shadowy group has moved into the ruins of Grangol'var Village.  Oops, this report is over a week old.",12,7,100,1,0,0,15843,0,"Lieutenant Gravelhammer"),
(18713,3,5,"We have reports from a scout in the field that one of the Cenarion druids has been taken captive up at Firewing Point.",12,7,100,1,0,0,15844,0,"Lieutenant Gravelhammer"),
(18713,4,0,"Aye, aye, sir.  Right away!",12,7,100,66,0,0,15853,0,"Lieutenant Gravelhammer"),
(18745,5,0,"At ease, lieutenant. Go on.",12,7,100,66,0,0,15834,0,"Captain Auric Sunchaser"),
(18745,5,1,"What is it now, Gravel?",12,7,100,6,0,0,15835,0,"Captain Auric Sunchaser"),
(18745,5,2,"What else could possibly go wrong?",12,7,100,6,0,0,15836,0,"Captain Auric Sunchaser"),
(18745,5,3,"Yes, lieutenant?  Report.",12,7,100,1,0,0,15837,0,"Captain Auric Sunchaser"),
(18745,6,0,"That's troubling news indeed.  See to it that it's taken care of immediately!",12,7,100,1,0,0,15849,0,"Captain Auric Sunchaser"),
(18745,6,1,"I don't have time for this, lieutenant.  Make sure that you handle it.",12,7,100,1,0,0,15850,0,"Captain Auric Sunchaser"),
(18745,6,2,"If we're to help with that in any way we'll need more people.  Call some of the scouts in to help with that.",12,7,100,1,0,0,15851,0,"Captain Auric Sunchaser"),
(18745,6,3,"Lieutenant, I want you to make that your top priority.  Notify anyone that you think can help.",12,7,100,1,0,0,15852,0,"Captain Auric Sunchaser");

-- WP
DELETE FROM `waypoints` WHERE `entry`=18713;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(18713,1,-3012.45019,3983.69726,3.10552,""),
(18713,2,-3011.6,3991.66,3.43526,""),
(18713,3,-3011.15,3993.25,4.07544,""),
(18713,4,-3010.1184,3994.7478,4.46475,""),
(18713,5,-3010.28,3994.08,4.46465,""),
(18713,6,-3012.069,3984.185,3.10552,""),
(18713,7,-3007.9,3978.22,3.10527,"");
