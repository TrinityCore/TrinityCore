SET @maxid := (SELECT MAX(`entry`) FROM `creature_template`);
UPDATE `quest_template` SET `RequiredNpcOrGo1`=-RequiredNpcOrGo1 WHERE `RequiredNpcOrGo1` > @maxid;
UPDATE `quest_template` SET `RequiredNpcOrGo2`=-RequiredNpcOrGo2 WHERE `RequiredNpcOrGo2` > @maxid;
UPDATE `quest_template` SET `RequiredNpcOrGo3`=-RequiredNpcOrGo3 WHERE `RequiredNpcOrGo3` > @maxid;
UPDATE `quest_template` SET `RequiredNpcOrGo4`=-RequiredNpcOrGo4 WHERE `RequiredNpcOrGo4` > @maxid;
