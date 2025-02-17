-- I used 1124 and 1125 seems not used
SET @GROUPID1 := 1124;
SET @GROUPID2 := 1125;

DELETE FROM `spell_group` WHERE `id` IN (1083,1085) AND `spell_id`=-1073;
DELETE FROM `spell_group` WHERE `id`=@GROUPID1 AND `spell_id` IN (-1085,-1073);
DELETE FROM `spell_group` WHERE `id`=@GROUPID2 AND `spell_id` IN (-1083,-1073);
INSERT INTO `spell_group` (`id`,`spell_id`) VALUES
(@GROUPID1,-1085), -- Spirit Buffs
(@GROUPID1,-1073), -- Fel Intelligence
(@GROUPID2,-1083), -- Intellect Buffs
(@GROUPID2,-1073); -- Fel Intelligence

DELETE FROM `spell_group_stack_rules` WHERE `group_id` IN (@GROUPID1,@GROUPID2);
INSERT INTO `spell_group_stack_rules` (`group_id`,`stack_rule`) VALUES
(@GROUPID1,3),
(@GROUPID2,3);
