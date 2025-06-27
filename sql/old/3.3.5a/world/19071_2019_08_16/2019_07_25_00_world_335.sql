--
SET @GROUP_ID := 1123; -- Change with the proper ID if this is in use
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
