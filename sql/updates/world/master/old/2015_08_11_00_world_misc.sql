ALTER TABLE `spell_proc_check` ADD COLUMN `hasDuration` INT(3) DEFAULT 0  NOT NULL AFTER `deathstateMask`;

delete from spell_proc_check where entry = 77606;
insert into `spell_proc_check` (`entry`, `entry2`, `entry3`, `checkspell`, `hastalent`, `chance`, `target`, `effectmask`, `powertype`, `dmgclass`, `specId`, `spellAttr0`, `targetTypeMask`, `mechanicMask`, `fromlevel`, `perchp`, `spelltypeMask`, `combopoints`, `deathstateMask`, `hasDuration`, `comment`) values('77606','0','0','0','0','0','1','7','0','-1','0','-16','16','0','0','0','0','0','0','1','0');
delete from spell_proc_event where entry = 77606;
insert into `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `SpellFamilyMask3`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`, `effectmask`) values('77616','0','0','0','0','0','0','87040','65536','0','0','0','7');
insert into `spell_script_names` (`spell_id`, `ScriptName`) values('108686','spell_warl_immolate');
insert into `spell_script_names` (`spell_id`, `ScriptName`) values('114654','spell_warl_incinerate');
insert into `spell_script_names` (`spell_id`, `ScriptName`) values('108685','spell_warl_incinerate');

delete from spell_linked_spell where spell_trigger = 603 or spell_effect = -603;

delete from spell_script_names where spell_id = 108685 and ScriptName = 'spell_warl_burning_embers';
delete from spell_script_names where spell_id = 114654 and ScriptName = 'spell_warl_burning_embers';
insert into `spell_script_names` (`spell_id`, `ScriptName`) values('114654','spell_warl_burning_embers_aoe');
insert into `spell_script_names` (`spell_id`, `ScriptName`) values('108685','spell_warl_burning_embers_aoe');
insert into `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `damage_bonus`, `heal_bonus`, `comments`) values('103990','-1','0.334','-1','-1','0','0','Warlock - Drain Life');

insert into `spell_script_names` (`spell_id`, `ScriptName`) values('103990','spell_warl_drain_life');

insert into `spell_script_names` (`spell_id`, `ScriptName`) values('115236','spell_warl_void_shield');
insert into `spell_script_names` (`spell_id`, `ScriptName`) values('115240','spell_warl_void_shield_damage');

update creature_template set spell1 = 115236 where entry IN (58960);

replace into `spell_proc_check` (`entry`, `entry2`, `entry3`, `checkspell`, `hastalent`, `chance`, `target`, `effectmask`, `powertype`, `dmgclass`, `specId`, `spellAttr0`, `targetTypeMask`, `mechanicMask`, `fromlevel`, `perchp`, `spelltypeMask`, `combopoints`, `deathstateMask`, `hasDuration`, `comment`) values('58070','0','0','0','103958','0','0','7','-1','-1','266','0','0','0','0','0','0','0','0','0','Символ вбирания души');
replace into `spell_proc_check` (`entry`, `entry2`, `entry3`, `checkspell`, `hastalent`, `chance`, `target`, `effectmask`, `powertype`, `dmgclass`, `specId`, `spellAttr0`, `targetTypeMask`, `mechanicMask`, `fromlevel`, `perchp`, `spelltypeMask`, `combopoints`, `deathstateMask`, `hasDuration`, `comment`) values('58070','0','0','0','114168','0','0','7','-1','-1','266','0','0','0','0','0','0','0','0','0','Символ вбирания души');
replace into `spell_proc_check` (`entry`, `entry2`, `entry3`, `checkspell`, `hastalent`, `chance`, `target`, `effectmask`, `powertype`, `dmgclass`, `specId`, `spellAttr0`, `targetTypeMask`, `mechanicMask`, `fromlevel`, `perchp`, `spelltypeMask`, `combopoints`, `deathstateMask`, `hasDuration`, `comment`) values('58070','0','0','1120','0','0','1','7','-1','-1','265','0','0','0','0','0','0','0','0','0','Символ вбирания души');
replace into `spell_proc_check` (`entry`, `entry2`, `entry3`, `checkspell`, `hastalent`, `chance`, `target`, `effectmask`, `powertype`, `dmgclass`, `specId`, `spellAttr0`, `targetTypeMask`, `mechanicMask`, `fromlevel`, `perchp`, `spelltypeMask`, `combopoints`, `deathstateMask`, `hasDuration`, `comment`) values('58070','0','0','116858','0','0','1','7','-1','-1','267','0','0','0','0','0','0','0','0','0','Символ вбирания души');

insert into `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `SpellFamilyMask3`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`, `effectmask`) values('144909','16','0','0','0','0','0','0','0','0','0','0','7');
