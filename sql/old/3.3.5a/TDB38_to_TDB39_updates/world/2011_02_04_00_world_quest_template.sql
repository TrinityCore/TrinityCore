-- Fix missing Previous Quest Requirement for They Grow Up So Fast
UPDATE `quest_template` SET `prevquestid`=13887 WHERE `entry`=13906;
