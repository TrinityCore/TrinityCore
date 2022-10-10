DELETE FROM `areatrigger_actions` WHERE `entry` = '1257';
INSERT INTO `areatrigger_actions` (`entry`, `id`, `moment`, `actionType`, `targetFlags`, `spellId`, `maxCharges`, `aura`, `hasspell`, `chargeRecoveryTime`, `scale`, `hitMaxCount`, `amount`, `comment`) values('1257','0','1','0','2','146703','0','-146703','0','0','0','0','0','OO:Lingering Corruption for npc');
INSERT INTO `areatrigger_actions` (`entry`, `id`, `moment`, `actionType`, `targetFlags`, `spellId`, `maxCharges`, `aura`, `hasspell`, `chargeRecoveryTime`, `scale`, `hitMaxCount`, `amount`, `comment`) values('1257','1','34','1','2','146703','0','146703','0','0','0','0','0','OO:Lingering Corruption remove for npc');
INSERT INTO `areatrigger_actions` (`entry`, `id`, `moment`, `actionType`, `targetFlags`, `spellId`, `maxCharges`, `aura`, `hasspell`, `chargeRecoveryTime`, `scale`, `hitMaxCount`, `amount`, `comment`) values('1257','3','1','0','8','146703','0','-146703','0','0','0','0','0','OO:Lingering Corruption for player');
INSERT INTO `areatrigger_actions` (`entry`, `id`, `moment`, `actionType`, `targetFlags`, `spellId`, `maxCharges`, `aura`, `hasspell`, `chargeRecoveryTime`, `scale`, `hitMaxCount`, `amount`, `comment`) values('1257','4','34','1','8','146703','0','146703','0','0','0','0','0','OO:Lingering Corruption remove for players');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) values('144514','spell_lingering_corruption');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) values('146703','spell_bottomless_pit');


