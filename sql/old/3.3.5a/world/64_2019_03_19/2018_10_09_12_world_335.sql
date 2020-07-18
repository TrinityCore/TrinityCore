-- Soft Dirt Mound
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=160840;
DELETE FROM `smart_scripts` WHERE `entryorguid`=160840 AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(160840,1,0,0,70,0,100,0,2,0,0,0,50,160839,50,0,0,0,0,1,0,0,0,0,0,0,0,"Soft Dirt Mound - On Gameobject State Changed - Summon Gameobject 'Gor'tesh's Lopped Off Head'");

-- Firegut Ogre
DELETE FROM `smart_scripts` WHERE `entryorguid`=7033 AND `source_type`=0 AND `id` IN (2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7033,0,2,0,23,0,50,0,13488,1,10000,20000,1,1,0,0,0,0,0,18,300,0,0,0,0,0,0,"Firegut Ogre - On Has Aura 'Firegut Fear Storm' - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID`=7033 AND `GroupID`=1;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(7033,1,0,"GOR'TESH DEAD?!?!",14,0,100,0,0,0,4707,0,"Firegut Ogre"),
(7033,1,1,"RUN! RUN FOR HILLS!",14,0,100,0,0,0,4708,0,"Firegut Ogre"),
(7033,1,2,"WHO KILL GOR'TESH!?!? WHO DO THIS?!",14,0,100,0,0,0,4709,0,"Firegut Ogre"),
(7033,1,3,"$n KILL! $G He:She; kill you now! RUN! RUN!",14,0,100,0,0,0,4711,0,"Firegut Ogre"),
(7033,1,4,"Run for hills! Wait! We already in hills!",14,0,100,0,0,0,4712,0,"Firegut Ogre");

-- Firegut Ogre Mage
DELETE FROM `smart_scripts` WHERE `entryorguid`=7034 AND `source_type`=0 AND `id` IN (3);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7034,0,3,0,23,0,50,0,13488,1,10000,20000,1,1,0,0,0,0,0,18,300,0,0,0,0,0,0,"Firegut Ogre Mage - On Has Aura 'Firegut Fear Storm' - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID`=7034 AND `GroupID`=1;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(7034,1,0,"GOR'TESH DEAD?!?!",14,0,100,0,0,0,4707,0,"Firegut Ogre Mage"),
(7034,1,1,"RUN! RUN FOR HILLS!",14,0,100,0,0,0,4708,0,"Firegut Ogre Mage"),
(7034,1,2,"WHO KILL GOR'TESH!?!? WHO DO THIS?!",14,0,100,0,0,0,4709,0,"Firegut Ogre Mage"),
(7034,1,3,"$n KILL! $G He:She; kill you now! RUN! RUN!",14,0,100,0,0,0,4711,0,"Firegut Ogre Mage"),
(7034,1,4,"Run for hills! Wait! We already in hills!",14,0,100,0,0,0,4712,0,"Firegut Ogre Mage");

-- Firegut Brute
DELETE FROM `smart_scripts` WHERE `entryorguid`=7035 AND `source_type`=0 AND `id` IN (3);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7035,0,3,0,23,0,50,0,13488,1,10000,20000,1,1,0,0,0,0,0,18,300,0,0,0,0,0,0,"Firegut Brute - On Has Aura 'Firegut Fear Storm' - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID`=7035 AND `GroupID`=1;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(7035,1,0,"GOR'TESH DEAD?!?!",14,0,100,0,0,0,4707,0,"Firegut Brute"),
(7035,1,1,"RUN! RUN FOR HILLS!",14,0,100,0,0,0,4708,0,"Firegut Brute"),
(7035,1,2,"WHO KILL GOR'TESH!?!? WHO DO THIS?!",14,0,100,0,0,0,4709,0,"Firegut Brute"),
(7035,1,3,"$n KILL! $G He:She; kill you now! RUN! RUN!",14,0,100,0,0,0,4711,0,"Firegut Brute"),
(7035,1,4,"Run for hills! Wait! We already in hills!",14,0,100,0,0,0,4712,0,"Firegut Brute");

-- Spell "Firegut Fear Storm"
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=13488;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,3,13488,0,0,31,0,3,7033,0,0,0,0,"","Spell 'Firegut Fear Storm' can only hit Firegut Ogres"),
(13,3,13488,0,1,31,0,3,7034,0,0,0,0,"","Spell 'Firegut Fear Storm' can only hit Firegut Ogres"),
(13,3,13488,0,2,31,0,3,7035,0,0,0,0,"","Spell 'Firegut Fear Storm' can only hit Firegut Ogres");
