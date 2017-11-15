-- 
UPDATE `quest_details` SET `EmoteDelay1`=500, `EmoteDelay2`=1000 WHERE `ID`=12593;
UPDATE `smart_scripts` SET `action_type`=11, `action_param1`=58204, `target_type`=7, `comment`="The Lich King - On Quest 'In service of The Lich King' Taken - Cast 'LK Intro VO'" WHERE `entryorguid`=25462 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2546200 AND `source_type`=9;
