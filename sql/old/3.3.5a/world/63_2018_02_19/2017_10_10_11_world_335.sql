-- Anchorite Avuun & Magtoor
DELETE FROM `creature_text` WHERE `CreatureID` IN (17127, 1776);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(17127,0,0,"Magtoor, thank you for allowing me to stay here with you.  I'm sure that there is much that we can learn from each other.  And I'm eager to learn all that I can of the Lost Ones to the east.",12,0,100,1,0,0,14065,0,"Anchorite Avuun"),
(17127,1,0,"Why do you traffic with the Horde?  Their foul ways are beneath you.",12,0,100,6,0,0,14075,0,"Anchorite Avuun"),
(17127,2,0,"I must find a way to put an end to the evil that Anchorite Avuun is committing against our lost brothers and sisters!",12,0,100,5,0,0,14085,0,"Anchorite Avuun"),
(17127,3,0,"Magtoor, I have faith that there is a way to bring the Lost Ones back from the brink.  By studying them, I will find a way to cure the fel energies that have consumed them.  And in so doing, I will be able to reverse the damage to the Broken as well.",12,0,100,1,0,0,14089,0,"Anchorite Avuun"),
(1776,0,0,"Of course, my friend.  You are welcome to stay with us for as long as you like.",12,0,100,1,0,0,14068,0,"Magtoor"),
(1776,1,0,"We have no choice.  If we fail to honor the presence of the Horde, then surely they will crush us from nearby Stonard!  I'm afraid that not even you and your friends would be able to stop them.",12,0,100,274,0,0,14081,0,"Magtoor"),
(1776,2,0,"Be careful, Avuun.  One of the merchants that I trade with in Stonard has heard her raving about some horrible disease she's trying to perfect.  They say it's for use against the draenei!",12,0,100,1,0,0,14087,0,"Magtoor"),
(1776,3,0,"Anchorite, we are honored that you are here, but I am curious as to what you truly believe you can accomplish?",12,0,100,6,0,0,14088,0,"Magtoor");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=17127;
DELETE FROM `smart_scripts` WHERE `entryorguid`=17127 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1712700, 1712701, 1712702, 1712703) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17127,0,0,0,4,0,100,0,0,0,0,0,11,1006,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anchorite Avuun - On Aggro - Cast Inner Fire"),
(17127,0,1,0,0,0,100,0,0,0,3400,4800,11,15498,64,0,0,0,0,2,0,0,0,0,0,0,0,"Anchorite Avuun - In Combat - Cast Holy Smite"),
(17127,0,2,0,2,0,100,0,0,50,15000,21000,11,12039,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anchorite Avuun - Between 0-50% Health - Cast Heal"),
(17127,0,3,0,1,0,100,0,1000,15000,120000,150000,87,1712700,1712701,1712702,1712703,0,0,1,0,0,0,0,0,0,0,"Anchorite Avuun - Out of Combat - Run Random Script"),
(1712700,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anchorite Avuun - On Script - Say Line 0"),
(1712700,9,1,0,0,0,100,0,10000,10000,0,0,1,0,0,0,0,0,0,19,1776,0,0,0,0,0,0,"Anchorite Avuun - On Script - Say Line 0 (Magtoor)"),
(1712701,9,0,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anchorite Avuun - On Script - Say Line 1"),
(1712701,9,1,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,19,1776,0,0,0,0,0,0,"Anchorite Avuun - On Script - Say Line 1 (Magtoor)"),
(1712702,9,0,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anchorite Avuun - On Script - Say Line 2"),
(1712702,9,1,0,0,0,100,0,8000,8000,0,0,1,2,0,0,0,0,0,19,1776,0,0,0,0,0,0,"Anchorite Avuun - On Script - Say Line 2 (Magtoor)"),
(1712703,9,0,0,0,0,100,0,0,0,0,0,1,3,0,0,0,0,0,19,1776,0,0,0,0,0,0,"Anchorite Avuun - On Script - Say Line 3 (Magtoor)"),
(1712703,9,1,0,0,0,100,0,8000,8000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anchorite Avuun - On Script - Say Line 3");

-- Anchorite Avuun --> Fix Gossip Text
DELETE FROM `gossip_menu` WHERE `MenuID`=7374 AND `TextID`=8814;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(7374,8814,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 14 AND `SourceGroup`= 7374;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,7374,8814,0,0,8,0,9448,0,0,0,0,0,"","Show Gossip Menu Text 8814 if Quest 'Mercy for the Cursed' is rewarded");
