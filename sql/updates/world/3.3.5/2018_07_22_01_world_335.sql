-- 
-- Thaurissan Relic
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=153556;
DELETE FROM `smart_scripts` WHERE `entryorguid`=153556 AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=15355600 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(153556,1,0,0,70,0,100,1,2,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Thaurissan Relic - On Gameobject State Changed - Store Targetlist"),
(153556,1,1,0,70,0,100,1,2,0,0,0,80,15355600,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thaurissan Relic - On Gameobject State Changed - Run Script"),
(15355600,9,0,0,0,0,100,0,0,0,0,0,12,8887,3,5000,0,0,0,1,0,0,0,0,0,0,0,"Thaurissan Relic - On Script - Summon Creature 'A tormented voice'"),
(15355600,9,1,0,0,0,100,0,0,0,0,0,100,1,0,0,0,0,0,19,8887,0,0,0,0,0,0,"Thaurissan Relic - On Script - Send Targetlist"),
(15355600,9,2,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,8887,0,0,0,0,0,0,"Thaurissan Relic - On Script - Set Data");

-- A tormented voice
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8887;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8887 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8887,0,0,0,38,0,100,0,1,1,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"A tormented voice - On Data Set - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=8887;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(8887,0,0,"Leave this place. <The relic emits a white hot arc of flame. A memory has been gained: A lone Dark Iron dwarf is surrounded by seven corpses, kneeling before a monolith of flame.>",15,0,100,0,0,0,4594,0,"A tormented voice"),
(8887,0,1,"You will perish here. <Your mind fills with visions of chaos and destruction.>",15,0,100,0,0,0,4595,0,"A tormented voice"),
(8887,0,2,"Do not taint these ruins, mortal. <You are engulfed in a blinding flash of light. A creature composed entirely of flame is the only thing you can remember seeing.>",15,0,100,0,0,0,4596,0,"A tormented voice"),
(8887,0,3,"Help us, outsider. <The relic crumbles to dust. A vision of eight Dark Iron dwarves performing some sort of ritual fills your head.>",15,0,100,0,0,0,4597,0,"A tormented voice"),
(8887,0,4,"He cannot be defeated. <The relic burns to nothing. The memories it held are now your own. This city was destroyed by a being not of this world.>",15,0,100,0,0,0,4598,0,"A tormented voice"),
(8887,0,5,"Your existence is acknowledged. <The relic turns to dust. Your head throbs with newfound wisdom. Something evil lurks in the heart of the mountain.>",15,0,100,0,0,0,4599,0,"A tormented voice"),
(8887,0,6,"Defiler... you will be punished for this incursion. <A symbol of flame radiates from the relic before it crumbles to the earth.>",15,0,100,0,0,0,4600,0,"A tormented voice");
