-- 
-- Hezrul Bloodmark
DELETE FROM `smart_scripts` WHERE `entryorguid`=9117 AND `source_type`=0 AND `id`>0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=911701 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=911700 AND `source_type`=9 AND `id`=6;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(9117,0,1,0,25,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"J.D. Collie - on reset - set event phase 1"),
(9117,0,2,0,19,0,100,0,4321,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"J.D. Collie - on reset - set event phase 0"),
(9117,0,3,0,1,1,100,0,5000,10000,90000,120000,80,911701,0,0,0,0,0,1,0,0,0,0,0,0,0,"J.D. Collie - Out of Combat - Action list"),
(911701,9,0,0,0,1,100,0,1000,1000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"J.D. Collie - Action list - Say Line"),
(911701,9,1,0,0,1,100,0,5000,5000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"J.D. Collie - Action list - Say Line"),
(911701,9,2,0,0,1,100,0,0,0,0,0,11,32990,0,0,0,0,0,1,0,0,0,0,0,0,0,"J.D. Collie - Action list - Say Line"),
(911701,9,3,0,0,1,100,0,4000,4000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"J.D. Collie - Action list - Say Line"),
(911701,9,4,0,0,1,100,0,4000,4000,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"J.D. Collie - Action list - Say Line"),
(911701,9,5,0,0,1,100,0,4000,4000,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"J.D. Collie - Action list - Say Line"),
(911700,9,6,0,0,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"J.D. Collie - Action list - Set eventphase 1");

DELETE FROM `creature_text` WHERE `CreatureID`=9117 AND `GroupID`>2;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(9117,3,0,"Ahh... My experiments never seem to work out right. Maybe I should go back downstream.",12,0,100,0,0,0,4843,0,"J.D. Collie"),
(9117,4,0,"%s begins to combine different colored crystals together.",16,0,100,0,0,0,4846,0,"J.D. Collie"),
(9117,5,0,"I think...I think it's working!",12,0,100,0,0,0,4847,0,"J.D. Collie"),
(9117,6,0,"OW! That's not right!",12,0,100,0,0,0,4852,0,"J.D. Collie"),
(9117,7,0,"Oh well... Maybe next time.",12,0,100,0,0,0,4853,0,"J.D. Collie");
