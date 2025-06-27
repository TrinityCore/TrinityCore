-- Quest "How Big a Threat? (Part 2)"
UPDATE `creature_text` SET `Emote`=6 WHERE `CreatureID`=3693 AND `GroupID`=0;
UPDATE `creature_text` SET `Emote`=5 WHERE `CreatureID`=3693 AND `GroupID`=1;
UPDATE `creature_text` SET `Emote`=1 WHERE `CreatureID`=3693 AND `GroupID` IN (2,4,5,6);

DELETE FROM `smart_scripts` WHERE `entryorguid`=369500 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(369500,9,0,0,0,0,100,0,0,0,0,0,54,40000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimclaw - On Script - Pause Waypoint for 40 seconds"),
(369500,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimclaw - On Script - Talk 0"),
(369500,9,2,0,0,0,100,0,3000,3000,0,0,1,1,0,0,0,0,0,19,3693,0,0,0,0,0,0,"Grimclaw - On Script - Talk 1 (Terenthis)"),
(369500,9,3,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimclaw - On Script - Talk 1"),
(369500,9,4,0,0,0,100,0,5000,5000,0,0,1,2,0,0,0,0,0,19,3693,0,0,0,0,0,0,"Grimclaw - On Script - Talk 2 (Terenthis)"),
(369500,9,5,0,0,0,100,0,4000,4000,0,0,1,3,0,0,0,0,0,19,3693,0,0,0,0,0,0,"Grimclaw - On Script - Talk 3 (Terenthis)"),
(369500,9,6,0,0,0,100,0,1000,1000,0,0,86,6238,0,19,3693,0,0,1,0,0,0,0,0,0,0,"Grimclaw - On Script - Cross Cast 'Speak with Animals'"),
(369500,9,7,0,0,0,100,0,2000,2000,0,0,1,4,0,0,0,0,0,19,3693,0,0,0,0,0,0,"Grimclaw - On Script - Talk 4 (Terenthis)"),
(369500,9,8,0,0,0,100,0,5000,5000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimclaw - On Script - Talk 2"),
(369500,9,9,0,0,0,100,0,5000,5000,0,0,1,5,0,0,0,0,0,19,3693,0,0,0,0,0,0,"Grimclaw - On Script - Talk 5 (Terenthis)"),
(369500,9,10,0,0,0,100,0,7000,7000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimclaw - On Script - Talk 3"),
(369500,9,11,0,0,0,100,0,5000,5000,0,0,1,6,0,0,0,0,0,19,3693,0,0,0,0,0,0,"Grimclaw - On Script - Talk 6 (Terenthis)"),
(369500,9,12,0,0,0,100,0,1000,1000,0,0,82,3,0,0,0,0,0,19,3693,0,0,0,0,0,0,"Grimclaw - On Script - Add Questgiver+Gossip npcflag (Terenthis)");

-- Quest "A Lost Master (Part 1)"
UPDATE `creature_text` SET `Emote`=1 WHERE `CreatureID`=3693 AND `GroupID` IN (8,9);
UPDATE `smart_scripts` SET `event_param1`=6000, `event_param2`=6000 WHERE `entryorguid`=369302 AND `source_type`=9 AND `id`=4;

-- Quest "A Lost Master (Part 2)"
DELETE FROM `smart_scripts` WHERE `entryorguid`=369303 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(369303,9,0,0,0,0,100,0,0,0,0,0,1,10,0,0,0,0,0,7,0,0,0,0,0,0,0,"Terenthis - On Script - Say Line 10"),
(369303,9,1,0,0,0,100,0,0,0,0,0,11,6236,0,0,0,0,0,7,0,0,0,0,0,0,0,"Terenthis - On Script - Cast 'Form of the Moonstalker'"),
(369303,9,2,0,0,0,100,0,2000,2000,0,0,1,11,0,0,0,0,0,7,0,0,0,0,0,0,0,"Terenthis - On Script - Say Line 11");

-- Quest "Escape Through Stealth" / "Escape Through Stealth"
UPDATE `creature_text` SET `Emote`=2 WHERE `CreatureID`=3694 AND `GroupID` IN (1,3);
UPDATE `creature_text` SET `Emote`=1 WHERE `CreatureID`=3694 AND `GroupID` IN (0,2);
UPDATE `creature_text` SET `Emote`=1 WHERE `CreatureID`=3693 AND `GroupID`=7;

-- Quest "Cave Mushrooms"
DELETE FROM `smart_scripts` WHERE `entryorguid`=3583 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=358300 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3583,0,0,0,19,0,100,0,947,0,0,0,80,358300,0,0,0,0,0,1,0,0,0,0,0,0,0,"Barithras Moonshade - On Quest 'Cave Mushrooms' Taken - Run Script"),
(358300,9,0,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Barithras Moonshade - On Quest 'Cave Mushrooms' Taken - Say Line 1"),
(358300,9,1,0,0,0,100,0,4000,4000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Barithras Moonshade - On Quest 'Cave Mushrooms' Taken - Say Line 0");

-- Quest "Goblin Invaders"
DELETE FROM `smart_scripts` WHERE `entryorguid`=404900 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(404900,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Seereth Stonebreak - On Script - Remove Npc Flag Questgiver"),
(404900,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Seereth Stonebreak - On Script - Say Line 0"),
(404900,9,2,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Seereth Stonebreak - On Script - Say Line 1"),
(404900,9,3,0,0,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Seereth Stonebreak - On Script - Add Npc Flag Questgiver");

-- Quest "Jin'Zil's Forest Magic"
UPDATE `creature_text` SET `Emote`=15 WHERE `CreatureID`=3995 AND `GroupID`=0;
UPDATE `creature_text` SET `Emote`=11 WHERE `CreatureID`=3995 AND `GroupID`=1;

DELETE FROM `waypoints` WHERE `entry` IN (3995,3681);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(3995,1,-270.459,-396.037,17.1122,""),
(3995,2,-270.305,-398.913,17.0809,""),
(3995,3,-272.921,-400.553,17.4664,""),
(3995,4,-277.705,-397.426,18.2977,""),
(3995,5,-277.037,-394.406,18.493,""),
(3995,6,-275.021,-393.218,17.9251,""),
(3995,7,-272.48,-394.084,17.2051,""),
(3681,1,-265.345,-393.202,16.9917,""),
(3681,2,-241.765,-376.753,17.8912,""),
(3681,3,-194.646,-335.997,10.0757,"");

DELETE FROM `smart_scripts` WHERE `entryorguid`=3995 AND `source_type`=0 AND `id` IN (1,2,3,4); -- Witch Doctor Jin'Zil
DELETE FROM `smart_scripts` WHERE `entryorguid`=399500 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3995,0,1,0,40,0,100,0,4,3995,0,0,54,8000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witch Doctor Jin'Zil - On Waypoint 4 Reached - Pause Waypoint"),
(3995,0,2,0,40,0,100,0,4,3995,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.406747,"Witch Doctor Jin'Zil - On Waypoint 4 Reached - Set Orientation"),
(3995,0,3,0,40,0,100,0,7,3995,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,6.19592,"Witch Doctor Jin'Zil - On Waypoint 7 Reached - Set Orientation"),
(3995,0,4,0,40,0,100,0,7,3995,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witch Doctor Jin'Zil - On Waypoint 7 Reached - Add Npc Flag Questgiver"),
(399500,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witch Doctor Jin'Zil - On Script - Remove Npc Flag Questgiver"),
(399500,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.0078,"Witch Doctor Jin'Zil - On Script - Set Orientation"),
(399500,9,2,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witch Doctor Jin'Zil - On Script - Say Line 0"),
(399500,9,3,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witch Doctor Jin'Zil - On Script - Say Line 1"),
(399500,9,4,0,0,0,100,0,0,0,0,0,86,6584,0,9,4072,0,30,1,0,0,0,0,0,0,0,"Witch Doctor Jin'Zil - On Script - Cross Cast 'Jin'Zil's Curse'"),
(399500,9,5,0,0,0,100,0,4000,4000,0,0,53,0,3995,0,0,0,0,1,0,0,0,0,0,0,0,"Witch Doctor Jin'Zil - On Script - Start Waypoint"),
(399500,9,6,0,0,0,100,0,6000,6000,0,0,51,0,0,0,0,0,0,9,4072,0,30,0,0,0,0,"Witch Doctor Jin'Zil - On Script - Kill Target"),
(399500,9,7,0,0,0,100,0,1000,1000,0,0,45,1,1,0,0,0,0,9,3681,0,30,0,0,0,0,"Witch Doctor Jin'Zil - On Script - Set Data"),
(399500,9,8,0,0,0,100,0,2000,2000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witch Doctor Jin'Zil - On Script - Say Line 2");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4072; -- Prisoner of Jin'Zil
DELETE FROM `smart_scripts` WHERE `entryorguid`=4072 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4072,0,0,0,6,0,100,0,0,0,0,0,12,3681,3,30000,0,0,0,1,0,0,0,0,0,0,0,"Prisoner of Jin'Zil - On Just Died - Summon Creature 'Wisp'"),
(4072,0,1,0,6,0,100,0,0,0,0,0,41,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Prisoner of Jin'Zil - On Just Died - Despawn In 5000 ms");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=3681; -- Wisp
DELETE FROM `smart_scripts` WHERE `entryorguid`=3681 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3681,0,0,0,38,0,100,0,1,1,0,0,53,1,3681,0,0,0,0,1,0,0,0,0,0,0,0,"Wisp - On Data Set - Start Waypoint"),
(3681,0,1,0,40,0,100,0,3,3681,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wisp - On Waypoint Reached - Despawn");
