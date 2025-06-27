-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (16114,16115,16113,16256,16116,16134,16135);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(16114,0,0,"Your message did reach us, Commander, but by no means is our involvement here sanctioned by the Grand Crusader.",12,0,100,1,0,0,12047,0,"Scarlet Commander Marjhan"),
(16114,1,0,"The heathens will be forced to react. Orcs, bull-men...",12,0,100,1,0,0,12052,0,"Scarlet Commander Marjhan"),
(16114,2,0,"Whatever. The revolting, unkempt Horde filth...",12,0,100,5,0,0,12054,0,"Scarlet Commander Marjhan"),
(16114,3,0,"Too little, too late. The dam has broken. We are a bump in the road at best.",12,0,100,274,0,0,12056,0,"Scarlet Commander Marjhan"),
(16114,4,0,"There is always... Ashbringer.",12,0,100,1,0,0,12058,0,"Scarlet Commander Marjhan"),
(16114,5,0,"Thank you, Jessica.",12,0,100,2,0,0,12143,0,"Scarlet Commander Marjhan"),
(16114,6,0,"And might I add, that dress is lovely! You must tell me where you got it from.",12,0,100,1,0,0,12144,0,"Scarlet Commander Marjhan"),
(16115,0,0,"Your leader takes residence at the doorstep to Naxxramas. Do you think he does not feel the pressure?",12,0,100,6,0,0,12048,0,"Commander Eligor Dawnbringer"),
(16115,1,0,"%s lowers the sound of his voice to a whisper.",16,0,100,0,0,0,12049,0,"Commander Eligor Dawnbringer"),
(16115,2,0,"Even demons are capable of fear...",12,0,100,0,0,0,12050,0,"Commander Eligor Dawnbringer"),
(16115,3,0,"Scourge activity in the Plaguelands has increased ten-fold. We are receiving reports of Scourge attacks from as far away as Kalimdor! Now how do you suppose this has happened? How have the wretched undead done that which was previously thought impossible? Is nowhere safe?",12,0,100,1,0,0,12051,0,"Commander Eligor Dawnbringer"),
(16115,4,0,"Tauren.",12,0,100,0,0,0,12053,0,"Commander Eligor Dawnbringer"),
(16115,5,0,"You lack tact, Commander. This is not surprising. However, you are right in that the Horde will be forced to act. But not just the Horde. They already come - heroes from across the world.",12,0,100,1,0,0,12055,0,"Commander Eligor Dawnbringer"),
(16115,6,0,"So why are you here? What are we to do if there is no hope?",12,0,100,6,0,0,12057,0,"Commander Eligor Dawnbringer"),
(16115,7,0,"So this is what you have come for? To try and claim that which is the reason for the Dawn's existence and the Crusade's downfall? You open old wounds with your words, Commander!",12,0,100,6,0,0,12062,0,"Commander Eligor Dawnbringer"),
(16115,8,0,"The Ashbringer is dead and there will never be another like him. The lesser Mograine is a far cry from the man his father was. You know this, Commander! It was, after all, your own leadership that was responsible for the death of the Scarlet Highlord Mograine.",12,0,100,5,0,0,12063,0,"Commander Eligor Dawnbringer"),
(16115,9,0,"It was your leadership that manipulated a grieving child to try and recover the sword. A child that has grown into a man with nothing but vengeance and hatred in his heart! And for what? You are no closer to the sword now than you were five years ago.",12,0,100,25,0,0,12065,0,"Commander Eligor Dawnbringer"),
(16115,10,0,"Yet you think that recovering Ashbringer will somehow turn the tide of battle? Let me let you in on a little secret, Commander: The power of the Ashbringer came from the man who would wield it... I was there, Commander. I watched him burn legions of undead in righteous fire before he would even unsheathe the blade. Alas, your grasp on history is ... lacking.",12,0,100,1,0,0,12066,0,"Commander Eligor Dawnbringer"),
(16115,11,0,"Now be silent and note where you are, lest I inform Lord Fordring and his knights that you are no longer here on amicable terms. I am certain he would take great pleasure in seeing to your 'atonement.'",12,0,100,5,0,0,12067,0,"Commander Eligor Dawnbringer"),
(16115,12,0,"The fish is exquisite, Jessica.",12,0,100,1,0,0,12138,0,"Commander Eligor Dawnbringer"),
(16115,13,0,"My compliments to the chef!",12,0,100,1,0,0,12137,0,"Commander Eligor Dawnbringer"),
(16115,14,0,"Delicious!",12,0,100,0,0,0,12139,0,"Commander Eligor Dawnbringer"),
(16256,0,0,"Ok, you had the fish platter, Commander. Enjoy!",12,0,100,1,0,0,12132,0,"Jessica Chambers"),
(16256,1,0,"Father, you had the bowl of fruit? Right?",12,0,100,6,0,0,12133,0,"Jessica Chambers"),
(16256,2,0,"And for the ladies, roast baby boar. Enjoy!",12,0,100,1,0,0,12134,0,"Jessica Chambers"),
(16256,3,0,"Please let me know if you need anything else!",12,0,100,1,0,0,12135,0,"Jessica Chambers"),
(16113,0,0,"Thank you, Mrs. Chambers.",12,0,100,1,0,0,12140,0,"Father Inigo Montoy"),
(16113,1,0,"Is this a mango? Stupendous!",12,0,100,4,0,0,12141,0,"Father Inigo Montoy"),
(16113,2,0,"You've really outdone yourself this time, Mrs. Chambers. Not a spot of mold to be found!",12,0,100,1,0,0,12142,0,"Father Inigo Montoy"),
(16116,0,0,"Oh, quite succulent. Many thanks, Mrs. Chambers.",12,0,100,2,0,0,12147,0,"Archmage Angela Dosantos"),
(16116,1,0,"The boar is superb!",12,0,100,4,0,0,12146,0,"Archmage Angela Dosantos"),
(16116,2,0,"Indeed... lovely dress, Jessica.",12,0,100,273,0,0,12145,0,"Archmage Angela Dosantos"),
(16134,0,0,"Watch, druid. The earth still breathes. It yearns to be cleansed.",12,0,100,1,0,0,11946,0,"Rimblat Earthshatter"),
(16135,0,0,"That is wonderous, Rimblat! Even this foul, sundered earth is not beyond healing.",12,0,100,273,0,0,11945,0,"Rayne");

-- Scarlet Commander Marjhan
UPDATE `npc_text` SET `BroadcastTextID0`=11944 WHERE `ID`=8354;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=16114;
DELETE FROM `smart_scripts` WHERE `entryorguid`=16114 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1611400 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(16114,0,0,0,1,0,100,0,5000,5000,480000,480000,80,1611400,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Commander Marjhan - Out of Combat - Run Script"),
(16114,0,1,0,38,0,100,0,1,1,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Commander Marjhan - On Data 1 1 Set - Set Event Phase 1"),
(16114,0,2,0,38,0,100,0,2,2,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Commander Marjhan - On Data 2 2 Set - Set Event Phase 0"),
(16114,0,3,0,1,1,100,0,1000,3000,3000,5000,5,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Commander Marjhan - Out of Combat - Play Emote 'Eat'"),
(1611400,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Commander Marjhan - On Script - Say Line 0"),
(1611400,9,1,0,0,0,100,0,6000,6000,0,0,1,0,0,0,0,0,0,19,16115,0,0,0,0,0,0,"Scarlet Commander Marjhan - On Script - Say Line 0 (Commander Eligor Dawnbringer)"),
(1611400,9,2,0,0,0,100,0,6000,6000,0,0,1,1,0,0,0,0,0,19,16115,0,0,0,0,0,0,"Scarlet Commander Marjhan - On Script - Say Line 1 (Commander Eligor Dawnbringer)"),
(1611400,9,3,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,19,16115,0,0,0,0,0,0,"Scarlet Commander Marjhan - On Script - Say Line 2 (Commander Eligor Dawnbringer)"),
(1611400,9,4,0,0,0,100,0,5000,5000,0,0,1,3,0,0,0,0,0,19,16115,0,0,0,0,0,0,"Scarlet Commander Marjhan - On Script - Say Line 3 (Commander Eligor Dawnbringer)"),
(1611400,9,5,0,0,0,100,0,15000,15000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Commander Marjhan - On Script - Say Line 1"),
(1611400,9,6,0,0,0,100,0,4000,4000,0,0,1,4,0,0,0,0,0,19,16115,0,0,0,0,0,0,"Scarlet Commander Marjhan - On Script - Say Line 4 (Commander Eligor Dawnbringer)"),
(1611400,9,7,0,0,0,100,0,2000,2000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Commander Marjhan - On Script - Say Line 2"),
(1611400,9,8,0,0,0,100,0,4000,4000,0,0,1,5,0,0,0,0,0,19,16115,0,0,0,0,0,0,"Scarlet Commander Marjhan - On Script - Say Line 5 (Commander Eligor Dawnbringer)"),
(1611400,9,9,0,0,0,100,0,10000,10000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Commander Marjhan - On Script - Say Line 2"),
(1611400,9,10,0,0,0,100,0,5000,5000,0,0,1,6,0,0,0,0,0,19,16115,0,0,0,0,0,0,"Scarlet Commander Marjhan - On Script - Say Line 6 (Commander Eligor Dawnbringer)"),
(1611400,9,11,0,0,0,100,0,5000,5000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Commander Marjhan - On Script - Say Line 4"),
(1611400,9,12,0,0,0,100,0,4000,4000,0,0,91,5,0,0,0,0,0,19,16115,0,0,0,0,0,0,"Scarlet Commander Marjhan - On Script - Remove Flag Standstate 'Sit' (Commander Eligor Dawnbringer)"),
(1611400,9,13,0,0,0,100,0,2000,2000,0,0,1,7,0,0,0,0,0,19,16115,0,0,0,0,0,0,"Scarlet Commander Marjhan - On Script - Say Line 7 (Commander Eligor Dawnbringer)"),
(1611400,9,14,0,0,0,100,0,10000,10000,0,0,1,8,0,0,0,0,0,19,16115,0,0,0,0,0,0,"Scarlet Commander Marjhan - On Script - Say Line 8 (Commander Eligor Dawnbringer)"),
(1611400,9,15,0,0,0,100,0,14000,14000,0,0,1,9,0,0,0,0,0,19,16115,0,0,0,0,0,0,"Scarlet Commander Marjhan - On Script - Say Line 9 (Commander Eligor Dawnbringer)"),
(1611400,9,16,0,0,0,100,0,13000,13000,0,0,1,10,0,0,0,0,0,19,16115,0,0,0,0,0,0,"Scarlet Commander Marjhan - On Script - Say Line 10 (Commander Eligor Dawnbringer)"),
(1611400,9,17,0,0,0,100,0,20000,20000,0,0,1,11,0,0,0,0,0,19,16115,0,0,0,0,0,0,"Scarlet Commander Marjhan - On Script - Say Line 11 (Commander Eligor Dawnbringer)"),
(1611400,9,18,0,0,0,100,0,10000,10000,0,0,90,5,0,0,0,0,0,19,16115,0,0,0,0,0,0,"Scarlet Commander Marjhan - On Script - Add Flag Standstate 'Sit' (Commander Eligor Dawnbringer)"),
(1611400,9,19,0,0,0,100,0,120000,120000,0,0,45,1,1,0,0,0,0,19,16256,0,0,0,0,0,0,"Scarlet Commander Marjhan - On Script - Set Data to Jessica Chambers");

-- Jessica Chambers
DELETE FROM `smart_scripts` WHERE `entryorguid`=16256 AND `source_type`=0 AND `id` IN (2,3,4,5);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1625600,1625601) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(16256,0,2,0,38,0,100,0,1,1,0,0,53,0,16256,0,0,0,0,1,0,0,0,0,0,0,0,"Jessica Chambers - On Data Set - Start Waypoint"),
(16256,0,3,0,40,0,100,0,1,16256,0,0,80,1625600,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jessica Chambers - On Waypoint 1 Reached - Run Script"),
(16256,0,4,0,40,0,100,0,5,16256,0,0,80,1625601,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jessica Chambers - On Waypoint 5 Reached - Run Script"),
(16256,0,5,0,40,0,100,0,8,16256,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.16421,"Jessica Chambers - On Waypoint 8 Reached - Set Orientation"),
(1625600,9,0,0,0,0,100,0,0,0,0,0,54,34000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jessica Chambers - On Script - Pause Waypoint"),
(1625600,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.6761,"Jessica Chambers - On Script - Set Orientation"),
(1625600,9,3,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jessica Chambers - On Script - Say Line 0"),
(1625600,9,4,0,0,0,100,0,0,0,0,0,50,181143,120,0,0,0,0,8,0,0,0,2298.4,-5341.18,91.8703,5.28751,"Jessica Chambers - On Script - Summon Gameobject 'Fish of the Day'"),
(1625600,9,5,0,0,0,100,0,4000,4000,0,0,5,7,0,0,0,0,0,19,16115,0,0,0,0,0,0,"Jessica Chambers - On Script - Play Emote 'Eat' (Commander Eligor Dawnbringer)"),
(1625600,9,6,0,0,0,100,0,4000,4000,0,0,1,12,0,0,0,0,0,19,16115,0,0,0,0,0,0,"Jessica Chambers - On Script - Say Line 12 (Commander Eligor Dawnbringer)"),
(1625600,9,7,0,0,0,100,0,4000,4000,0,0,1,13,0,0,0,0,0,19,16115,0,0,0,0,0,0,"Jessica Chambers - On Script - Say Line 13 (Commander Eligor Dawnbringer)"),
(1625600,9,8,0,0,0,100,0,4000,4000,0,0,45,1,1,0,0,0,0,19,16115,0,0,0,0,0,0,"Jessica Chambers - On Script - Set Data 1 1 (Commander Eligor Dawnbringer)"),
(1625600,9,9,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.23882,"Jessica Chambers - On Script - Set Orientation"),
(1625600,9,10,0,0,0,100,0,1000,1000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jessica Chambers - On Script - Say Line 1"),
(1625600,9,11,0,0,0,100,0,0,0,0,0,50,181144,103,0,0,0,0,8,0,0,0,2298.24,-5339.52,91.8803,0.683735,"Jessica Chambers - On Script - Summon Gameobject 'Bowl of Fruit'"),
(1625600,9,12,0,0,0,100,0,4000,4000,0,0,1,0,0,0,0,0,0,19,16113,0,0,0,0,0,0,"Jessica Chambers - On Script - Say Line 0 (Father Inigo Montoy)"),
(1625600,9,13,0,0,0,100,0,4000,4000,0,0,5,7,0,0,0,0,0,19,16113,0,0,0,0,0,0,"Jessica Chambers - On Script - Play Emote 'Eat' (Father Inigo Montoy)"),
(1625600,9,14,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,19,16113,0,0,0,0,0,0,"Jessica Chambers - On Script - Say Line 1 (Father Inigo Montoy)"),
(1625600,9,15,0,0,0,100,0,4000,4000,0,0,45,1,1,0,0,0,0,19,16113,0,0,0,0,0,0,"Jessica Chambers - On Script - Set Data 1 1 (Father Inigo Montoy)"),
(1625601,9,0,0,0,0,100,0,0,0,0,0,54,32000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jessica Chambers - On Script - Pause Waypoint"),
(1625601,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,6.14871,"Jessica Chambers - On Script - Set Orientation"),
(1625601,9,3,0,0,0,100,0,1000,1000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jessica Chambers - On Script - Say Line 2"),
(1625601,9,4,0,0,0,100,0,0,0,0,0,50,181145,79,0,0,0,0,8,0,0,0,2296.58,-5338.5,91.8859,2.16942,"Jessica Chambers - On Script - Summon Gameobject 'Roast Boar Platter'"),
(1625601,9,5,0,0,0,100,0,0,0,0,0,50,181145,79,0,0,0,0,8,0,0,0,2296.69,-5340.52,91.8701,3.80698,"Jessica Chambers - On Script - Summon Gameobject 'Roast Boar Platter'"),
(1625601,9,6,0,0,0,100,0,4000,4000,0,0,1,5,0,0,0,0,0,19,16114,0,0,0,0,0,0,"Jessica Chambers - On Script - Say Line 5 (Scarlet Commander Marjhan)"),
(1625601,9,7,0,0,0,100,0,0,0,0,0,5,7,0,0,0,0,0,19,16116,0,0,0,0,0,0,"Jessica Chambers - On Script - Play Emote 'Eat' (Archmage Angela Dosantos)"),
(1625601,9,8,0,0,0,100,0,3000,3000,0,0,1,0,0,0,0,0,0,19,16116,0,0,0,0,0,0,"Jessica Chambers - On Script - Say Line 0 (Archmage Angela Dosantos)"),
(1625601,9,9,0,0,0,100,0,3000,3000,0,0,45,1,1,0,0,0,0,19,16116,0,0,0,0,0,0,"Jessica Chambers - On Script - Set Data 1 1 (Archmage Angela Dosantos)"),
(1625601,9,10,0,0,0,100,0,2000,2000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jessica Chambers - On Script - Say Line 3"),
(1625601,9,11,0,0,0,100,0,0,0,0,0,5,7,0,0,0,0,0,19,16114,0,0,0,0,0,0,"Jessica Chambers - On Script - Play Emote 'Eat' (Scarlet Commander Marjhan)"),
(1625601,9,12,0,0,0,100,0,5000,5000,0,0,1,6,0,0,0,0,0,19,16114,0,0,0,0,0,0,"Jessica Chambers - On Script - Say Line 6 (Scarlet Commander Marjhan)"),
(1625601,9,13,0,0,0,100,0,6000,6000,0,0,1,2,0,0,0,0,0,19,16116,0,0,0,0,0,0,"Jessica Chambers - On Script - Say Line 2 (Archmage Angela Dosantos)"),
(1625601,9,14,0,0,0,100,0,4000,4000,0,0,45,1,1,0,0,0,0,19,16114,0,0,0,0,0,0,"Jessica Chambers - On Script - Set Data 1 1 (Scarlet Commander Marjhan)"),
(1625601,9,15,0,0,0,100,0,20000,20000,0,0,1,14,0,0,0,0,0,19,16115,0,0,0,0,0,0,"Jessica Chambers - On Script - Say Line 14 (Commander Eligor Dawnbringer)"),
(1625601,9,16,0,0,0,100,0,8000,8000,0,0,1,1,0,0,0,0,0,19,16116,0,0,0,0,0,0,"Jessica Chambers - On Script - Say Line 1 (Archmage Angela Dosantos)"),
(1625601,9,17,0,0,0,100,0,9000,9000,0,0,1,2,0,0,0,0,0,19,16113,0,0,0,0,0,0,"Jessica Chambers - On Script - Say Line 2 (Father Inigo Montoy)"),
(1625601,9,18,0,0,0,100,0,10000,10000,0,0,45,2,2,0,0,0,0,19,16116,0,0,0,0,0,0,"Jessica Chambers - On Script - Set Data 2 2 (Archmage Angela Dosantos)"),
(1625601,9,19,0,0,0,100,0,0,0,0,0,45,2,2,0,0,0,0,19,16115,0,0,0,0,0,0,"Jessica Chambers - On Script - Set Data 2 2 (Commander Eligor Dawnbringer)"),
(1625601,9,20,0,0,0,100,0,0,0,0,0,45,2,2,0,0,0,0,19,16113,0,0,0,0,0,0,"Jessica Chambers - On Script - Set Data 2 2 (Father Inigo Montoy)"),
(1625601,9,21,0,0,0,100,0,0,0,0,0,45,2,2,0,0,0,0,19,16114,0,0,0,0,0,0,"Jessica Chambers - On Script - Set Data 2 2 (Scarlet Commander Marjhan)");

DELETE FROM `waypoints` WHERE `entry`=16256;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(16256,1,2300.27,-5340.53,90.8799,""),
(16256,2,2300.8,-5337.74,90.8799,""),
(16256,3,2298.02,-5334.07,90.8799,""),
(16256,4,2293.54,-5335.07,90.8799,""),
(16256,5,2294.49,-5339.1,90.8803,""),
(16256,6,2293.89,-5341.91,90.8803,""),
(16256,7,2295.97,-5344.84,90.8803,""),
(16256,8,2300.9,-5345.09,90.8799,"");

-- Commander Eligor Dawnbringer
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=16115;
DELETE FROM `smart_scripts` WHERE `entryorguid`=16115 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(16115,0,0,0,38,0,100,0,1,1,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Eligor Dawnbringer - On Data 1 1 Set - Set Event Phase 1"),
(16115,0,1,0,38,0,100,0,2,2,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Eligor Dawnbringer - On Data 2 2 Set - Set Event Phase 0"),
(16115,0,2,0,1,1,100,0,1000,3000,3000,5000,5,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Eligor Dawnbringer - Out of Combat - Play Emote 'Eat'");

-- Father Inigo Montoy
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=16113;
DELETE FROM `smart_scripts` WHERE `entryorguid`=16113 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(16113,0,0,0,38,0,100,0,1,1,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Father Inigo Montoy - On Data 1 1 Set - Set Event Phase 1"),
(16113,0,1,0,38,0,100,0,2,2,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Father Inigo Montoy - On Data 2 2 Set - Set Event Phase 0"),
(16113,0,2,0,1,1,100,0,1000,3000,3000,5000,5,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Father Inigo Montoy - Out of Combat - Play Emote 'Eat'");

-- Archmage Angela Dosantos
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=16116;
DELETE FROM `smart_scripts` WHERE `entryorguid`=16116 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(16116,0,0,0,38,0,100,0,1,1,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Angela Dosantos - On Data 1 1 Set - Set Event Phase 1"),
(16116,0,1,0,38,0,100,0,2,2,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Angela Dosantos - On Data 2 2 Set - Set Event Phase 0"),
(16116,0,2,0,1,1,100,0,1000,3000,3000,5000,5,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Angela Dosantos - Out of Combat - Play Emote 'Eat'");

-- Rimblat Earthshatter
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=16134;
DELETE FROM `smart_scripts` WHERE `entryorguid`=16134 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1613400 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(16134,0,0,0,1,0,100,0,1000,15000,150000,180000,80,1613400,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rimblat Earthshatter - Out of Combat - Run Script"),
(1613400,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rimblat Earthshatter - On Script - Say Line 0"),
(1613400,9,1,0,0,0,100,0,6000,6000,0,0,1,0,0,0,0,0,0,19,16135,0,0,0,0,0,0,"Rimblat Earthshatter - On Script - Say Line 0 (Rayne)");
