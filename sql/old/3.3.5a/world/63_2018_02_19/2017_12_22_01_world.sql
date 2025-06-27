-- Aponi Brightmane & Tahu Sagewind
DELETE FROM `creature_text` WHERE `CreatureID` IN (34526,34528);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(34526,0,0,"Talk to me, Tahu. Something. Anything! I'm going stir-crazy.",12,0,100,0,0,0,34762,0,"Aponi Brightmane"),
(34526,1,0,"Not much.",12,0,100,0,0,0,34763,0,"Aponi Brightmane"),
(34526,2,0,"Like Mu'sha.",12,0,100,0,0,0,34764,0,"Aponi Brightmane"),
(34526,3,0,"Where are you going with this?",12,0,100,6,0,0,34765,0,"Aponi Brightmane"),
(34526,4,0,"I hear the \"but\" in your voice...",12,0,100,0,0,0,34766,0,"Aponi Brightmane"),
(34526,5,0,"Do you think his teachings are wrong?",12,0,100,6,0,0,34767,0,"Aponi Brightmane"),
(34526,6,0,"So are you going to bring this up to the elder?",12,0,100,0,0,0,34768,0,"Aponi Brightmane"),
(34526,7,0,"I suppose so. It's not silly, though, what you said.",12,0,100,1,0,0,34769,0,"Aponi Brightmane"),
(34526,8,0,"I see that thoughtful frown, Tahu.",12,0,100,0,0,0,34770,0,"Aponi Brightmane"),
(34526,9,0,"But something is on your mind, right?",12,0,100,6,0,0,34771,0,"Aponi Brightmane"),
(34526,10,0,"What about it?",12,0,100,0,0,0,34772,0,"Aponi Brightmane"),
(34526,11,0,"There's a phrase... \"It's always darkest before the dawn.\" The dawn will come, though, Tahu. The sun will rise. The balance will shift back to where it should be.",12,0,100,1,0,0,34773,0,"Aponi Brightmane"),
(34526,12,0,"%s smiles and gestures to the north.",16,0,100,25,0,0,34774,0,"Aponi Brightmane"),
(34526,13,0,"Even on the glacier itself, the sun manages to peek through the gloom. I have hope, Tahu. I think we'll make it through this, no matter how dire it looks.",12,0,100,1,0,0,34775,0,"Aponi Brightmane"),
(34526,14,0,"But I'd still rather be there on the front lines helping it happen rather than trying to placate myself with belief. We can't just sit around and hope it happens.",12,0,100,0,0,0,34776,0,"Aponi Brightmane"),
(34526,15,0,"And through that hope, strengthen our side in the fight?",12,0,100,0,0,0,34777,0,"Aponi Brightmane"),
(34528,0,0,"%s laughs softly.",16,0,100,0,0,0,34745,0,"Tahu Sagewind"),
(34528,1,0,"All right, Aponi. I've enough on my mind to share. Have you ever spoken to the elves of Moonglade?",12,0,100,1,0,0,34746,0,"Tahu Sagewind"),
(34528,2,0,"The elves speak of a moon goddess, did you know? They put great stock in the light given by the moon.",12,0,100,0,0,0,34747,0,"Tahu Sagewind"),
(34528,3,0,"Just like her. The parallels I've heard are interesting. And it's no secret all druids, Shu'halo and elf alike, can call upon Mu'sha's light.",12,0,100,273,0,0,34748,0,"Tahu Sagewind"),
(34528,4,0,"I wonder. Hamuul has guided us well, and I've learned so much from him. The legends say that our people were druids when time began...",12,0,100,1,0,0,34749,0,"Tahu Sagewind"),
(34528,5,0,"...but what Hamuul teaches is what the elves know. The night elves. They put such stock in their moon goddess, as creatures of the night.",12,0,100,0,0,0,34750,0,"Tahu Sagewind"),
(34528,6,0,"No! No, nothing like that. He is an elder for good reason, sister. Mu'sha is one of the Earthmother's eyes, and she watches over us. That isn't sinister.",12,0,100,274,0,0,34751,0,"Tahu Sagewind"),
(34528,7,0,"But we're nothing if not people who strive for balance. Our warriors fight only when there is need. Our hunters take only what the tribes require to live, and use all they can when they do. The shaman stand as guide and mediator to the elemental spirits.",12,0,100,0,0,0,34753,0,"Tahu Sagewind"),
(34528,8,0,"And while we, as druids, are guardians of nature, I wonder if we've overlooked a key aspect of balance in all things.",12,0,100,1,0,0,34754,0,"Tahu Sagewind"),
(34528,9,0,"No, no. No need for him to trouble about a student's idle philosophizing while he entertains a friend.",12,0,100,274,0,0,34755,0,"Tahu Sagewind"),
(34528,10,0,"Well, it isn't exactly a new thought, sister.",12,0,100,6,0,0,34756,0,"Tahu Sagewind"),
(34528,11,0,"Sorry, sister. It's nothing to worry about.",12,0,100,0,0,0,34778,0,"Tahu Sagewind"),
(34528,12,0,"I'm thinking about the front to the north. The one you're so eager to return to.",12,0,100,1,0,0,34779,0,"Tahu Sagewind"),
(34528,13,0,"I know I'm counseling patience, Aponi, but I don't like remaining here any more than you do. Times are bleak, and failing to act only makes me worry that my idle hand may have been the one to turn the tide.",12,0,100,0,0,0,34780,0,"Tahu Sagewind"),
(34528,14,0,"Still... there is balance in all things, even death. I simply hate the concept that such destruction and darkness might be necessary.",12,0,100,1,0,0,34781,0,"Tahu Sagewind"),
(34528,15,0,"I know, sister. I know. We'll return to fighting one day. For now, though, maybe it's best to spread the word to others... give them the hope you have.",12,0,100,1,0,0,34783,0,"Tahu Sagewind"),
(34528,16,0,"That's the idea.",12,0,100,273,0,0,34784,0,"Tahu Sagewind");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=34526;
DELETE FROM `smart_scripts` WHERE `entryorguid`=34526 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3452600,3452601) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(34526,0,0,0,20,1,100,0,13986,0,0,0,87,3452600,3452601,0,0,0,0,1,0,0,0,0,0,0,0,"Aponi Brightmane - On Quest 'An Injured Colleague' Finished - Run Random Script"),
(34526,0,1,0,11,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aponi Brightmane - On Respawn - Set Event Phase 1"),
(3452600,9,0,0,0,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aponi Brightmane - On Script - Set Event Phase 0"),
(3452600,9,1,0,0,0,100,0,3000,3000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aponi Brightmane - On Script - Say Line 0"),
(3452600,9,2,0,0,0,100,0,3000,3000,0,0,1,0,0,0,0,0,0,19,34528,0,0,0,0,0,0,"Aponi Brightmane - On Script - Say Line 0 (Tahu Sagewind)"),
(3452600,9,3,0,0,0,100,0,2000,2000,0,0,1,1,0,0,0,0,0,19,34528,0,0,0,0,0,0,"Aponi Brightmane - On Script - Say Line 1 (Tahu Sagewind)"),
(3452600,9,4,0,0,0,100,0,5500,5500,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aponi Brightmane - On Script - Say Line 1"),
(3452600,9,5,0,0,0,100,0,2000,2000,0,0,1,2,0,0,0,0,0,19,34528,0,0,0,0,0,0,"Aponi Brightmane - On Script - Say Line 2 (Tahu Sagewind)"),
(3452600,9,6,0,0,0,100,0,3000,3000,0,0,86,65630,0,19,34548,0,0,1,0,0,0,0,0,0,0,"Aponi Brightmane - On Script - Cross Cast 'Starfall State Visual'"),
(3452600,9,7,0,0,0,100,0,3000,3000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aponi Brightmane - On Script - Say Line 2"),
(3452600,9,8,0,0,0,100,0,2000,2000,0,0,1,3,0,0,0,0,0,19,34528,0,0,0,0,0,0,"Aponi Brightmane - On Script - Say Line 3 (Tahu Sagewind)"),
(3452600,9,9,0,0,0,100,0,7000,7000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aponi Brightmane - On Script - Say Line 3"),
(3452600,9,10,0,0,0,100,0,3000,3000,0,0,1,4,0,0,0,0,0,19,34528,0,0,0,0,0,0,"Aponi Brightmane - On Script - Say Line 4 (Tahu Sagewind)"),
(3452600,9,11,0,0,0,100,0,7000,7000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aponi Brightmane - On Script - Say Line 4"),
(3452600,9,12,0,0,0,100,0,3000,3000,0,0,1,5,0,0,0,0,0,19,34528,0,0,0,0,0,0,"Aponi Brightmane - On Script - Say Line 5 (Tahu Sagewind)"),
(3452600,9,13,0,0,0,100,0,7000,7000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aponi Brightmane - On Script - Say Line 5"),
(3452600,9,14,0,0,0,100,0,4000,4000,0,0,1,6,0,0,0,0,0,19,34528,0,0,0,0,0,0,"Aponi Brightmane - On Script - Say Line 6 (Tahu Sagewind)"),
(3452600,9,15,0,0,0,100,0,8000,8000,0,0,1,7,0,0,0,0,0,19,34528,0,0,0,0,0,0,"Aponi Brightmane - On Script - Say Line 7 (Tahu Sagewind)"),
(3452600,9,16,0,0,0,100,0,13000,13000,0,0,1,8,0,0,0,0,0,19,34528,0,0,0,0,0,0,"Aponi Brightmane - On Script - Say Line 8 (Tahu Sagewind)"),
(3452600,9,17,0,0,0,100,0,2500,2500,0,0,28,0,0,0,0,0,0,19,34548,0,0,0,0,0,0,"Aponi Brightmane - On Script - Remove All Auras"),
(3452600,9,18,0,0,0,100,0,500,500,0,0,86,65632,0,19,34548,0,0,1,0,0,0,0,0,0,0,"Aponi Brightmane - On Script - Cross Cast 'Eclipse Visual'"),
(3452600,9,19,0,0,0,100,0,3000,3000,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aponi Brightmane - On Script - Say Line 6"),
(3452600,9,20,0,0,0,100,0,4000,4000,0,0,1,9,0,0,0,0,0,19,34528,0,0,0,0,0,0,"Aponi Brightmane - On Script - Say Line 9 (Tahu Sagewind)"),
(3452600,9,21,0,0,0,100,0,5500,5500,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aponi Brightmane - On Script - Say Line 7"),
(3452600,9,22,0,0,0,100,0,4000,4000,0,0,1,10,0,0,0,0,0,19,34528,0,0,0,0,0,0,"Aponi Brightmane - On Script - Say Line 10 (Tahu Sagewind)"),
(3452600,9,23,0,0,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aponi Brightmane - On Script - Set Event Phase 1"),
(3452601,9,0,0,0,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aponi Brightmane - On Script - Set Event Phase 0"),
(3452601,9,1,0,0,0,100,0,3000,3000,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aponi Brightmane - On Script - Say Line 8"),
(3452601,9,2,0,0,0,100,0,3000,3000,0,0,1,11,0,0,0,0,0,19,34528,0,0,0,0,0,0,"Aponi Brightmane - On Script - Say Line 11 (Tahu Sagewind)"),
(3452601,9,3,0,0,0,100,0,3500,3500,0,0,1,9,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aponi Brightmane - On Script - Say Line 9"),
(3452601,9,4,0,0,0,100,0,3500,3500,0,0,1,12,0,0,0,0,0,19,34528,0,0,0,0,0,0,"Aponi Brightmane - On Script - Say Line 12 (Tahu Sagewind)"),
(3452601,9,5,0,0,0,100,0,5000,5000,0,0,1,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aponi Brightmane - On Script - Say Line 10"),
(3452601,9,6,0,0,0,100,0,2000,2000,0,0,1,13,0,0,0,0,0,19,34528,0,0,0,0,0,0,"Aponi Brightmane - On Script - Say Line 13 (Tahu Sagewind)"),
(3452601,9,7,0,0,0,100,0,11000,11000,0,0,1,14,0,0,0,0,0,19,34528,0,0,0,0,0,0,"Aponi Brightmane - On Script - Say Line 14 (Tahu Sagewind)"),
(3452601,9,8,0,0,0,100,0,7000,7000,0,0,1,11,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aponi Brightmane - On Script - Say Line 11"),
(3452601,9,9,0,0,0,100,0,4000,4000,0,0,86,65631,0,19,34548,0,0,1,0,0,0,0,0,0,0,"Aponi Brightmane - On Script - Cross Cast 'Sunny'"),
(3452601,9,10,0,0,0,100,0,5000,5000,0,0,1,12,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aponi Brightmane - On Script - Say Line 12"),
(3452601,9,11,0,0,0,100,0,2000,2000,0,0,1,13,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aponi Brightmane - On Script - Say Line 13"),
(3452601,9,12,0,0,0,100,0,8000,8000,0,0,1,14,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aponi Brightmane - On Script - Say Line 14"),
(3452601,9,13,0,0,0,100,0,8500,8500,0,0,1,15,0,0,0,0,0,19,34528,0,0,0,0,0,0,"Aponi Brightmane - On Script - Say Line 15 (Tahu Sagewind)"),
(3452601,9,14,0,0,0,100,0,8000,8000,0,0,1,15,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aponi Brightmane - On Script - Say Line 15"),
(3452601,9,15,0,0,0,100,0,4000,4000,0,0,1,16,0,0,0,0,0,19,34528,0,0,0,0,0,0,"Aponi Brightmane - On Script - Say Line 16 (Tahu Sagewind)"),
(3452601,9,16,0,0,0,100,0,0,0,0,0,28,0,0,0,0,0,0,19,34548,0,0,0,0,0,0,"Aponi Brightmane - On Script - Remove All Auras"),
(3452601,9,17,0,0,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aponi Brightmane - On Script - Set Event Phase 1");

-- Add missing spawns
SET @GUID1 := 16806;
SET @GUID2 := 17553;
DELETE FROM `creature` WHERE `guid` IN (@GUID1, @GUID2);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(@GUID1,34548,1,0,0,1,1,0,0,-1047.73,-287.61,159.03,5.93684,300,0,0,42,0,0,0,33554432,0,"",0), -- Invisible Spell Target - Tahu
(@GUID2,34528,1,0,0,1,1,0,1,-1045.84,-288.282,159.03,2.8312,300,0,0,3137,2117,0,0,0,0,"",0); -- Tahu Sagewind
