-- 
UPDATE `smart_scripts` SET `event_type`=4, `event_chance`=80, `event_param2`=0, `event_param3`=0, `event_param4`=0, `comment`="Deranged Explorer - On Aggro - Say Line 0" WHERE `entryorguid`=23967 AND `source_type`=0 AND `id`=1;

DELETE FROM `creature_text` WHERE `CreatureID`=23967;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(23967, 0, 0, "Ahahaha! I must find the secrets!", 12, 7, 100, 0, 0, 0, 22495, 0, "Deranged Explorer"),
(23967, 0, 1, "I don't want to know anymore. Make me forget!", 12, 7, 100, 0, 0, 0, 22496, 0, "Deranged Explorer"),
(23967, 0, 2, "When one studies and digs, one reveals the truth.", 12, 7, 100, 0, 0, 0, 22497, 0, "Deranged Explorer"),
(23967, 0, 3, "We're safe; IT will never reach us here!", 12, 7, 100, 0, 0, 0, 22498, 0, "Deranged Explorer"),
(23967, 0, 4, "The end is nigh! That Which Must Not Be Named is almost free!", 12, 7, 100, 0, 0, 0, 22499, 0, "Deranged Explorer"),
(23967, 0, 5, "IT's coming! HIDE!", 12, 7, 100, 0, 0, 0, 22500, 0, "Deranged Explorer"),
(23967, 0, 6, "If only there were more time!", 12, 7, 100, 0, 0, 0, 22501, 0, "Deranged Explorer"),
(23967, 0, 7, "Forgive me oh great one. I did not mean to learn the truth!", 12, 7, 100, 0, 0, 0, 22502, 0, "Deranged Explorer"),
(23967, 0, 8, "The truth shall set you free. Like us, you will be with IT forever!", 12, 7, 100, 0, 0, 0, 22503, 0, "Deranged Explorer"),
(23967, 0, 9, "Now that you know the truth, I can't let you leave!", 12, 7, 100, 0, 0, 0, 22504, 0, "Deranged Explorer"),
(23967, 0, 10, "It'll all be over soon. Soon you will be in the embrace of That Which Must Not Be Named!", 12, 7, 100, 0, 0, 0, 22505, 0, "Deranged Explorer"),
(23967, 0, 11, "Intruder! You were sent to destroy us!", 12, 7, 100, 0, 0, 0, 22506, 0, "Deranged Explorer"),
(23967, 0, 12, "You cannot leave... IT mustn't find us!", 12, 7, 100, 0, 0, 0, 22507, 0, "Deranged Explorer"),
(23967, 0, 13, "If you're here, then IT might be close behind!", 12, 7, 100, 0, 0, 0, 22508, 0, "Deranged Explorer"),
(23967, 0, 14, "I will put an end to your life before you realize the horrible truth!", 12, 7, 100, 0, 0, 0, 22509, 0, "Deranged Explorer"),
(23967, 0, 15, "Now you'll have to join us... permanently!", 12, 7, 100, 0, 0, 0, 22510, 0, "Deranged Explorer");
