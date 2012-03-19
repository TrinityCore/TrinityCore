DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (70346,72456,72868,72869);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,0,70346,0,18,1,37672,0,0, '', 'Slime Puddle - target Mutated Abomination'),
(13,0,72456,0,18,1,38285,0,0, '', 'Slime Puddle - target Mutated Abomination'),
(13,0,72868,0,18,1,37672,0,0, '', 'Slime Puddle - target Mutated Abomination'),
(13,0,72869,0,18,1,38285,0,0, '', 'Slime Puddle - target Mutated Abomination');

UPDATE `creature_template` SET `exp`=2,`spell1`=70360,`spell2`=70539 WHERE `entry`=37672;
UPDATE `creature_template` SET `exp`=2,`spell1`=72527,`spell2`=72457 WHERE `entry`=38605;
UPDATE `creature_template` SET `exp`=2,`spell1`=70360,`spell2`=72875 WHERE `entry`=38786;
UPDATE `creature_template` SET `exp`=2,`spell1`=72527,`spell2`=72876 WHERE `entry`=38787;

UPDATE `creature_template` SET `exp`=2,`spell1`=70360,`spell2`=70539 WHERE `entry`=38285;
UPDATE `creature_template` SET `exp`=2,`spell1`=72527,`spell2`=72457 WHERE `entry`=38788;
UPDATE `creature_template` SET `exp`=2,`spell1`=70360,`spell2`=72875 WHERE `entry`=38789;
UPDATE `creature_template` SET `exp`=2,`spell1`=72527,`spell2`=72876 WHERE `entry`=38790;
