-- Patch 1.10.2 (2006-05-02): This ability will no longer stack with [Arcane Power].
-- If you gain both at the same time, Arcane Power will take precedence.

-- If you have Power Infusion Aura and cast Arcane Power, Power Infusion should be replaced by Arcane Power.
-- But if you have Arcane Power and try to cast Power Infusion, you should get msg "A more powerful spell is active"
-- Arcane Power and Power Infusion don't have the same effect, so stack_rule 4 (SPELL_GROUP_STACK_RULE_EXCLUSIVE_HIGHEST) isn't valid.
-- So, I put stack_rule 1 (SPELL_GROUP_STACK_RULE_EXCLUSIVE) for prevent stack the two auras.
-- And SpellScript for get error msg when you cast Power Infusion when target have Arcane Power Aura.

SET @GROUP_ID := 1122; -- Change with the proper ID if this is in use
DELETE FROM `spell_group` WHERE `id`=@GROUP_ID AND `spell_id` IN (10060,12042);
INSERT INTO `spell_group` (`id`,`spell_id`) VALUES
(@GROUP_ID,10060), -- Priest - Power Infusion
(@GROUP_ID,12042); -- Mage - Arcane Power

DELETE FROM `spell_group_stack_rules` WHERE `group_id`=@GROUP_ID;
INSERT INTO `spell_group_stack_rules` (`group_id`,`stack_rule`) VALUES
(@GROUP_ID,1);

DELETE FROM `spell_script_names` WHERE `spell_id`=10060 AND `ScriptName`='spell_pri_power_infusion';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(10060,'spell_pri_power_infusion');
