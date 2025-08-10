-- 
DELETE FROM `page_text` WHERE `ID` IN (8148 /*8148*/, 8398 /*8398*/, 8399 /*8399*/);
INSERT INTO `page_text` (`ID`, `Text`, `NextPageID`, `PlayerConditionID`, `Flags`, `VerifiedBuild`) VALUES
(8148, 'The Stonewright is untouchable. Not even our own stoneborn forces would dare raise a talon against her. \n\nWhat is worse is that she is one of the first venthyr, like myself and the Curator. She was not made from a soul, but willed into being by Denathrius himself. \n\nNo sinstone, no mortal trappings, or past deeds will bend her to our will.  If she is unwilling to provide us her medallion, we stand very little chance of recovering it.', 0, 0, 0, 43345), -- 8148
(8398, 'Item List:\n\n3 vombata saddle adjustments for Varoun\n\n7 tools for Banit\'s stock \n\n15 new staves for the guards \n\nAssorted dishes and seating for Anap\'s caravan \n\n(These new travellers seem to have decided it is an inn of sorts. Which would be fine if they did not make a such a mess.)', 0, 0, 0, 43345), -- 8398
(8399, 'After a thorough examination of the Raptora in the area, I do not believe they are fit to bear travelers across Zereth Mortis without unacceptable levels of training. \n\nTherefore, these strange devices scattered throughout will have to do. It is a shame the Exile took up residence near the westernmost one. Elder Kreth may be unhappy about us making use of these, but I have convinced him it is better than disturbing sacred ground and possibly disrupting the wildlife and Automa wherever we pass.\n\n-Wayfinder Ros', 0, 0, 0, 43345); -- 8399

UPDATE `page_text` SET `VerifiedBuild`=43345 WHERE `ID` IN (8128, 8141, 8135, 8143, 8133, 8137, 8387, 8380, 8390, 8336, 8397, 8396);
UPDATE `page_text` SET `VerifiedBuild`=43340 WHERE `ID` IN (4899, 8143);
UPDATE `page_text` SET `VerifiedBuild`=43206 WHERE `ID` IN (8128, 8143);
UPDATE `page_text` SET `VerifiedBuild`=42698 WHERE `ID` IN (8389, 8432, 8431, 8430, 8429, 8428, 8427, 8426, 8425, 8421, 8420, 8419, 8418, 8417, 8416, 8388, 8390);
UPDATE `page_text` SET `VerifiedBuild`=42560 WHERE `ID`=8390;
UPDATE `page_text` SET `VerifiedBuild`=42538 WHERE `ID` IN (8540, 8552, 8539, 8551, 8538, 8550, 8537, 8549, 8536, 8548, 8535, 8547, 8534, 8546, 8533, 8545, 8532, 8544, 8412, 8543, 8375, 8542, 8411, 8541, 8553, 8436, 8435, 8434, 8433, 8424, 8423, 8422, 8415, 8414, 8413, 8388);
UPDATE `page_text` SET `VerifiedBuild`=42488 WHERE `ID` IN (8388, 8540, 8552, 8539, 8551, 8538, 8550, 8537, 8549, 8536, 8548, 8535, 8547, 8534, 8546, 8533, 8545, 8532, 8544, 8412, 8543, 8375, 8542, 8411, 8541, 8553);

