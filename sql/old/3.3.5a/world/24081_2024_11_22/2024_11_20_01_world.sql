-- Death Knights shoud start with Journeyman Riding (150)
UPDATE `playercreateinfo_skills` SET `rank`=2 WHERE `raceMask`=0 AND `classMask`=32 AND `skill`=762;
