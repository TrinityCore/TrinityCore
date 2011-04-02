-- Set Correct Requirements for quest: Once More Unto The Breach, Hero (13104/13105)
UPDATE `quest_template` SET `SkillOrClassMask`=-32 WHERE `entry`= 13105; -- Death Knight only
UPDATE `quest_template` SET `SkillOrClassMask`=-1503 WHERE `entry`= 13105; -- Other Classes
