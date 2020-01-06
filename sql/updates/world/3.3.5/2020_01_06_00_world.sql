-- 
UPDATE `creature` SET `spawntimesecs`=30 WHERE `guid`=84498;
DELETE FROM `creature_addon` WHERE `guid` IN (84507,84498);
INSERT INTO `creature_addon` (`guid`, `bytes2`) VALUE
(84507,0), (84498,1);

DELETE FROM `gameobject` WHERE `guid`=9302;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(9302, 183852, 530, 3519, 3956, 1, 1, -3105.043, 4957.401, -100.8201, 3.351047, 0, 0, -0.9945211, 0.1045355, 120, 255, 0, 15595); -- 183852 (Area: 3956 - Difficulty: 0)

DELETE FROM `creature` WHERE `guid` IN (44468,84497);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(44468, 19677, 530, 3519, 3956, 1, 1, 0, 0, -3101.862, 4931.368, -87.81017, 2.303835, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595); -- 19677 (Area: 3956 - Difficulty: 0)

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (19673,19676);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-84507,19676,19673) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1967600,1967300,1967301,1967601) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-84507,0,0,0,1,0,100,0,2000,2000,6000,9000,11,34432,0,0,0,0,0,19,19677,0,0,0,0,0,0,"Consortium Engineer - Ooc - Cast 'Ribbon of Souls'"),
(19676,0,0,0,1,0,100,0,2000,2000,120000,120000,80,1967600,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Kaftiz - Ooc - Action list"),
(1967600,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Kaftiz - Ooc - Action list"),
(1967600,9,1,0,0,0,100,0,7000,7000,0,0,1,0,0,0,0,0,0,10,84500,19672,0,0,0,0,0,"Captain Kaftiz - Action list - Say text"),
(1967600,9,2,0,0,0,100,0,7000,7000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Kaftiz - Action list - Say text"),
(1967600,9,3,0,0,0,100,0,5000,5000,0,0,1,0,0,0,0,0,0,10,84498,19673,0,0,0,0,0,"Captain Kaftiz - Action list - Say text"),
(1967600,9,4,0,0,0,100,0,1000,1000,0,0,45,1,1,0,0,0,0,10,84498,19673,0,0,0,0,0,"Captain Kaftiz - Action list - Set data"),
(19676,0,1,0,38,0,100,0,1,1,10000,10000,80,1967601,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Kaftiz - Ooc - Action list"),
(1967601,9,5,0,0,0,100,0,2000,2000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Kaftiz - Action list - Say text"),
(1967601,9,6,0,0,0,100,0,2000,2000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Kaftiz - Action list - Say text"),
(19673,0,0,0,38,0,100,1,1,1,0,0,69,1,0,0,0,0,0,8,0,0,0,-3076.0187, 4942.9399, -101.0475, 0.060653,"Consortium Engineer - on data set - Move to pos"),
(19673,0,1,0,34,0,100,1,8,1,0,0,87,1967300,1967301,0,0,0,0,1,0,0,0,0,0,0,0,"Consortium Engineer - Movement inform - Random Action list"),
(1967300,9,0,0,0,0,100,0,0,0,0,0,51,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Kaftiz - Action list - Kill Self"),
(1967300,9,1,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,19676,0,0,0,0,0,0,"Captain Kaftiz - Action list - Set data"),
(1967301,9,0,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Kaftiz - Action list - Say text"),
(1967301,9,1,0,0,0,100,0,3000,3000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Kaftiz - Action list - Say text"),
(1967301,9,2,0,0,0,100,0,1000,1000,0,0,51,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Kaftiz - Action list - Kill Self"),
(1967301,9,3,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,19676,0,0,0,0,0,0,"Captain Kaftiz - Action list - Set data");

DELETE FROM `creature_template_movement` WHERE `CreatureId`= 19677;
INSERT INTO `creature_template_movement` (`CreatureId`,`Ground`,`Swim`,`Flight`,`Rooted`) VALUES
(19677, 0, 0, 1, 0);

DELETE FROM `creature_text` WHERE `CreatureID` IN (19673,19676,19672);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(19676,0,0, "Is that damned thing safe to go through yet?", 12, 0, 100, 1, 0, 0, 17201, '"Captain" Kaftiz'),
(19676,0,1, "Is it done yet? What is taking so damned long?", 12, 0, 100, 1, 0, 0, 17202, '"Captain" Kaftiz'),
(19676,0,2, "You know, we could easily replace you with goblins. Is that what you want???", 12, 0, 100, 1, 0, 0, 17203, '"Captain" Kaftiz'),
(19676,0,3, "I can't believe you imbeciles went to school for this! Does anybody here know what they're doing?", 12, 0, 100, 1, 0, 0, 17204, '"Captain" Kaftiz'),
(19672,0,0, "It is if I'm not the one that's going to be sent in to test it... Otherwise,, no.", 12, 0, 100, 0, 0, 0, 17194, 'Consortium Engineer'),
(19672,0,1, "What does that mean anyway? Ready? Can it ever be ready?", 12, 0, 100, 0, 0, 0, 17195, 'Consortium Engineer'),
(19672,0,2, "I'm giving her all that I've got,, captain. I don't think she can take much more of this!", 12, 0, 100, 0, 0, 0, 17196, 'Consortium Engineer'),
(19672,0,3, "I can't bang on this device any faster,, captain! My wrapping is already beginning to unravel!", 12, 0, 100, 0, 0, 0, 17197, 'Consortium Engineer'),
(19672,0,4, "Will you stop asking that?", 12, 0, 100, 0, 0, 0, 17198, 'Consortium Engineer'),
(19672,0,5, "Why don't you pick up a hammer and start banging on these structures instead of asking us if it's done every 5 minutes?", 12, 0, 100, 0, 0, 0, 17199, 'Consortium Engineer'),
(19672,0,6, "I've had just about enough of your incessant whining,, captain. What are you even a captain of? I mean, the nerve!", 12, 0, 100, 0, 0, 0, 17200, 'Consortium Engineer'),
(19676,1,0, "Alright, it looks safe. Get in there, engineer!", 12, 0, 100, 1, 0, 0, 17210, '"Captain" Kaftiz'),
(19673,0,0,"I don't get paid enough for this nonsense.", 12, 0, 100, 0, 0, 0, 17205, 'Consortium Engineer'),
(19673,0,1,"Here goes nothing!", 12, 0, 100, 0, 0, 0, 17206, 'Consortium Engineer'),
(19673,0,2,"This is gonna leave a mark...", 12, 0, 100, 0, 0, 0, 17207, 'Consortium Engineer'),
(19673,0,3,"If I make it through, I expect a pay raise.", 12, 0, 100, 0, 0, 0, 17208, 'Consortium Engineer'),
(19673,1,0,"%s runs his hands across his body to make sure everything is intact.", 16, 0, 100, 0, 0, 0, 17211, 'Consortium Engineer'),
(19673,2,0,"I made it! I made it!", 12, 0, 100, 0, 0, 0, 17209, 'Consortium Engineer'),
(19676,2,0, "%s shrugs.", 16, 0, 100, 0, 0, 0, 17212, '"Captain" Kaftiz'),
(19676,2,1, "%s shakes his head in disapproval.", 16, 0, 100, 0, 0, 0, 17213, '"Captain" Kaftiz'),
(19676,3,0, "Oh well,, back to the drawing board.", 12, 0, 100, 1, 0, 0, 17214, '"Captain" Kaftiz'),
(19676,3,1, "I didn't like him much anyway. Too much talk,, not enough 'do.'", 12, 0, 100, 1, 0, 0, 17215, '"Captain" Kaftiz'),
(19676,3,2, "Damnit. How are we ever going to get through their security measures?", 12, 0, 100, 1, 0, 0, 17216, '"Captain" Kaftiz'),
(19676,3,3, "Nice going you incompetent morons! Another one of our engineers vaporized!", 12, 0, 100, 1, 0, 0, 17217, '"Captain" Kaftiz'),
(19676,3,4, "Thankfully,, there's a steady stream of these fools chomping at the bit to get in here.", 12, 0, 100, 1, 0, 0, 17218, '"Captain" Kaftiz');
