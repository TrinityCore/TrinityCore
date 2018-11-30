-- Fallenroot Shadowstalker
DELETE FROM `smart_scripts` WHERE `entryorguid`=4798 AND `source_type`=0 AND `id`>0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4798,0,1,0,25,0,100,0,0,0,0,0,11,5916,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fallenroot Shadowstalker - On Reset - Cast Stealth"),
(4798,0,2,0,4,0,30,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fallenroot Shadowstalker - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=4798;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(4798,0,0,"We are quite safe from your pitiful band!",12,8,100,0,0,0,2410,0,"Fallenroot Shadowstalker"),
(4798,0,1,"I shall rip your guts out!",12,8,100,0,0,0,2411,0,"Fallenroot Shadowstalker"),
(4798,0,2,"Your eyes will make pretty baubbles!",12,8,100,0,0,0,2412,0,"Fallenroot Shadowstalker");

-- Fallenroot Hellcaller
DELETE FROM `smart_scripts` WHERE `entryorguid`=4799 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4799,0,2,0,4,0,30,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fallenroot Hellcaller - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=4799;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(4799,0,0,"We are quite safe from your pitiful band!",12,8,100,0,0,0,2410,0,"Fallenroot Hellcaller"),
(4799,0,1,"I shall rip your guts out!",12,8,100,0,0,0,2411,0,"Fallenroot Hellcaller"),
(4799,0,2,"Your eyes will make pretty baubbles!",12,8,100,0,0,0,2412,0,"Fallenroot Hellcaller");

-- Twilight Reaver
DELETE FROM `smart_scripts` WHERE `entryorguid`=4810 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4810,0,2,0,4,0,30,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Reaver - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=4810;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(4810,0,0,"Aku'mai demands more sacrifices, now you must die!",12,0,100,0,0,0,2406,0,"Twilight Reaver"),
(4810,0,1,"Intruders!  The Hammer shall fall upon you.",12,0,100,0,0,0,2407,0,"Twilight Reaver"),
(4810,0,2,"The Old Gods will be restored.  You will not be allowed to interfere!",12,0,100,0,0,0,2408,0,"Twilight Reaver"),
(4810,0,3,"Your blood shall be the catalyst for the Old Gods' return!",12,0,100,0,0,0,2409,0,"Twilight Reaver");

-- Twilight Aquamancer
DELETE FROM `smart_scripts` WHERE `entryorguid`=4811 AND `source_type`=0 AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4811,0,3,0,4,0,30,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Aquamancer - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=4811;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(4811,0,0,"Aku'mai demands more sacrifices, now you must die!",12,0,100,0,0,0,2406,0,"Twilight Aquamancer"),
(4811,0,1,"Intruders!  The Hammer shall fall upon you.",12,0,100,0,0,0,2407,0,"Twilight Aquamancer"),
(4811,0,2,"The Old Gods will be restored.  You will not be allowed to interfere!",12,0,100,0,0,0,2408,0,"Twilight Aquamancer"),
(4811,0,3,"Your blood shall be the catalyst for the Old Gods' return!",12,0,100,0,0,0,2409,0,"Twilight Aquamancer");

-- Twilight Loreseeker
DELETE FROM `smart_scripts` WHERE `entryorguid`=4812 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4812,0,2,0,4,0,30,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Loreseeker - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=4812;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(4812,0,0,"Aku'mai demands more sacrifices, now you must die!",12,0,100,0,0,0,2406,0,"Twilight Loreseeker"),
(4812,0,1,"Intruders!  The Hammer shall fall upon you.",12,0,100,0,0,0,2407,0,"Twilight Loreseeker"),
(4812,0,2,"The Old Gods will be restored.  You will not be allowed to interfere!",12,0,100,0,0,0,2408,0,"Twilight Loreseeker"),
(4812,0,3,"Your blood shall be the catalyst for the Old Gods' return!",12,0,100,0,0,0,2409,0,"Twilight Loreseeker");

-- Twilight Acolyte
DELETE FROM `smart_scripts` WHERE `entryorguid`=4809 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4809,0,2,0,4,0,30,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Acolyte - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=4809;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(4809,0,0,"Aku'mai demands more sacrifices, now you must die!",12,0,100,0,0,0,2406,0,"Twilight Acolyte"),
(4809,0,1,"Intruders!  The Hammer shall fall upon you.",12,0,100,0,0,0,2407,0,"Twilight Acolyte"),
(4809,0,2,"The Old Gods will be restored.  You will not be allowed to interfere!",12,0,100,0,0,0,2408,0,"Twilight Acolyte"),
(4809,0,3,"Your blood shall be the catalyst for the Old Gods' return!",12,0,100,0,0,0,2409,0,"Twilight Acolyte");

-- Twilight Shadowmage
DELETE FROM `smart_scripts` WHERE `entryorguid`=4813 AND `source_type`=0 AND `id`=4;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4813,0,4,0,4,0,30,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Shadowmage - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=4813;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(4813,0,0,"Aku'mai demands more sacrifices, now you must die!",12,0,100,0,0,0,2406,0,"Twilight Shadowmage"),
(4813,0,1,"Intruders!  The Hammer shall fall upon you.",12,0,100,0,0,0,2407,0,"Twilight Shadowmage"),
(4813,0,2,"The Old Gods will be restored.  You will not be allowed to interfere!",12,0,100,0,0,0,2408,0,"Twilight Shadowmage"),
(4813,0,3,"Your blood shall be the catalyst for the Old Gods' return!",12,0,100,0,0,0,2409,0,"Twilight Shadowmage");

-- Twilight Elementalist
DELETE FROM `smart_scripts` WHERE `entryorguid`=4814 AND `source_type`=0 AND `id`=4;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4814,0,4,0,4,0,30,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Elementalist - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=4814;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(4814,0,0,"Aku'mai demands more sacrifices, now you must die!",12,0,100,0,0,0,2406,0,"Twilight Elementalist"),
(4814,0,1,"Intruders!  The Hammer shall fall upon you.",12,0,100,0,0,0,2407,0,"Twilight Elementalist"),
(4814,0,2,"The Old Gods will be restored.  You will not be allowed to interfere!",12,0,100,0,0,0,2408,0,"Twilight Elementalist"),
(4814,0,3,"Your blood shall be the catalyst for the Old Gods' return!",12,0,100,0,0,0,2409,0,"Twilight Elementalist");

-- Fix spawn position for one creature
UPDATE `creature` SET `position_x`=-809.037, `position_y`=-57.5216, `position_z`=-41.7495 WHERE `guid`=27411;
