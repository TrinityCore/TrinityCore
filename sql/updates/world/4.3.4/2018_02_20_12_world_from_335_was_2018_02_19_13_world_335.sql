/*
-- Quest "Forsaken Diseases"
DELETE FROM `smart_scripts` WHERE `entryorguid`=384801 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(384801,9,0,0,0,0,100,0,0,0,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kayneth Stillwind - On Script - Set Rooted On"),
(384801,9,1,0,0,0,100,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kayneth Stillwind - On Script - Remove Questgiver+Gossip npcflag"),
(384801,9,2,0,0,0,100,0,1000,1000,0,0,11,6355,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kayneth Stillwind - On Script - Cast 'Drink Disease Bottle'"),
(384801,9,3,0,0,0,100,0,2500,2500,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Kayneth Stillwind - On Script - Say Line 1"),
(384801,9,4,0,0,0,100,0,0,0,0,0,17,64,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kayneth Stillwind - On Script - Set Emote State 64"),
(384801,9,5,0,0,0,100,0,4500,4500,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,"Kayneth Stillwind - On Script - Say Line 2"),
(384801,9,6,0,0,0,100,0,3000,3000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kayneth Stillwind - On Script - Set Emote State 0"),
(384801,9,7,0,0,0,100,0,1000,1000,0,0,1,3,0,0,0,0,0,7,0,0,0,0,0,0,0,"Kayneth Stillwind - On Script - Say Line 3"),
(384801,9,8,0,0,0,100,0,2000,2000,0,0,82,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kayneth Stillwind - On Script - Add Questgiver+Gossip npcflag"),
(384801,9,9,0,0,0,100,0,10000,10000,0,0,103,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kayneth Stillwind - On Script - Set Rooted Off");

-- Quest "Parts for Kravel"
UPDATE `creature_addon` SET `bytes1`=0 WHERE `guid`=21570;

DELETE FROM `smart_scripts` WHERE `entryorguid`=445200 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(445200,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kravel Koalbeard - On Script - Remove Npc Flag Questgiver"),
(445200,9,1,0,0,0,100,0,1000,1000,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kravel Koalbeard - On Script - Set Flag Standstate Kneel"),
(445200,9,2,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kravel Koalbeard - On Script - Say Line 0"),
(445200,9,3,0,0,0,100,0,1000,1000,0,0,50,19878,10,0,0,0,0,8,0,0,0,-6232.5,-3855.12,-58.75,3.97786,"Kravel Koalbeard - On Script - Summon Gameobject 'Parts Crate'"),
(445200,9,4,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kravel Koalbeard - On Script - Say Line 1"),
(445200,9,5,0,0,0,100,0,2000,2000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kravel Koalbeard - On Script - Say Line 2"),
(445200,9,6,0,0,0,100,0,2000,2000,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kravel Koalbeard - On Script - Remove Flag Standstate Kneel"),
(445200,9,7,0,0,0,100,0,2000,2000,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kravel Koalbeard - On Script - Add Npc Flag Questgiver");

-- Quest "Skull Rock"
UPDATE `smart_scripts` SET `action_param1`=4947, `comment`="Margoz - On Script - Cast 'Magic Backlash'" WHERE `entryorguid`=320800 AND `source_type`=9 AND `id`=4;
UPDATE `creature_text` SET `Sound`=6527 WHERE `CreatureID`=3208 AND `GroupID`=1;

-- Quest "Dark Storms"
UPDATE `creature_text` SET `Emote`=15 WHERE `CreatureID`=3142 AND `GroupID`=0;

-- Quest "Headhunting"
UPDATE `smart_scripts` SET `event_param1`=6000, `event_param2`=6000 WHERE `entryorguid`=249700 AND `source_type`=9 AND `id`=3;
UPDATE `smart_scripts` SET `event_param1`=8000, `event_param2`=8000 WHERE `entryorguid`=249700 AND `source_type`=9 AND `id`=4;

-- Quest "Bloodscalp Clan Heads"
DELETE FROM `smart_scripts` WHERE `entryorguid`=2076 AND `source_type`=1 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=207600 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2076,1,1,0,20,0,100,0,584,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Bubbling Cauldron - On Quest 'Bloodscalp Clan Heads' Finished - Store Targetlist"),
(207600,9,0,0,0,0,100,0,0,0,0,0,105,16,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bubbling Cauldron - On Script - Add Gameobject Flag"),
(207600,9,1,0,0,0,100,0,0,0,0,0,100,1,0,0,0,0,0,19,2519,0,0,0,0,0,0,"Bubbling Cauldron - On Script - Send Target"),
(207600,9,2,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,2519,0,0,0,0,0,0,"Bubbling Cauldron - On Script - Set Data"),
(207600,9,3,0,0,0,100,0,11000,11000,0,0,106,16,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bubbling Cauldron - On Script - Remove Gameobject Flag");

DELETE FROM `creature_text` WHERE `CreatureID`=2497 AND `GroupID` IN (3,4,5);
DELETE FROM `creature_text` WHERE `CreatureID`=2519 AND `GroupID` IN (5,6,7);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2519,5,0,"Ah, good $n.  Now let us see what tale these heads tell...",12,1,100,1,0,0,735,0,"Kin'weelay"),
(2519,6,0,"%s begins chanting...",16,0,100,0,0,0,736,0,"Kin'weelay"),
(2519,7,0,"There, $n.  You may now speak to the Bloodscalp chief and his witchdoctor.",12,1,100,1,0,0,740,0,"Kin'weelay");

DELETE FROM `smart_scripts` WHERE `entryorguid`=2497 AND `source_type`=0 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=249701 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2519 AND `source_type`=0 AND `id`=2;
DELETE FROM `smart_scripts` WHERE `entryorguid`=251902 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2519,0,2,0,38,0,100,0,1,1,0,0,80,251902,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kin'weelay - On Data Set - Run Script"),
(251902,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kin'weelay - On Script - Remove Npc Flag Questgiver"),
(251902,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.661932,"Kin'weelay - On Script - Set Orientation"),
(251902,9,2,0,0,0,100,0,0,0,0,0,1,5,0,0,0,0,0,12,1,0,0,0,0,0,0,"Kin'weelay - On Script - Say Line 5"),
(251902,9,3,0,0,0,100,0,4000,4000,0,0,1,6,0,0,0,0,0,12,1,0,0,0,0,0,0,"Kin'weelay - On Script - Say Line 6"),
(251902,9,4,0,0,0,100,0,0,0,0,0,11,3644,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kin'weelay - On Script - Cast 'Speak with Heads'"),
(251902,9,5,0,0,0,100,0,7000,7000,0,0,1,7,0,0,0,0,0,12,1,0,0,0,0,0,0,"Kin'weelay - On Script - Say Line 7"),
(251902,9,6,0,0,0,100,0,5000,5000,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kin'weelay - On Script - Add Npc Flag Questgiver"),
(251902,9,7,0,0,0,100,0,5000,5000,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kin'weelay - On Script - Set Orientation");
*/
