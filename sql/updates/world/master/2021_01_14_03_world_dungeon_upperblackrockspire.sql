-- instance
REPLACE INTO `instance_template` (`map`, `parent`, `script`, `allowMount`, `insideResurrection`) VALUES ('1358', '0', 'instance_upper_blackrock_spire', '0', '0');
REPLACE INTO `access_requirement` (`mapId`, `difficulty`, `level_min`, `level_max`, `item`, `item2`, `quest_done_A`, `quest_done_H`, `completed_achievement`, `quest_failed_text`, `comment`) VALUES ('1358', '0', '0', '0', '0', '0', '0', '0', '0', NULL, 'UpperBlackrockSpire');

-- commander tharbek
update creature_template set scriptname='boss_commander_tharbek' where entry=79912;
update creature_template set scriptname='npc_ironbarb_skyreaver' where entry=80098;
update creature_template set scriptname='npc_imbued_iron_axe_stalker' where entry=80307;

-- kyrak
update creature_template set scriptname='npc_drakonid_monstrosity' where entry=82556;
update creature_template set scriptname='boss_kyrak' where entry=76021;

-- orebender gorashan
update creature_template set scriptname='boss_orebender_gorashan' where entry=76413;
update creature_template set scriptname='npc_gorashan_power_rune' where entry=76417;
update creature_template set scriptname='npc_rune_glow' where entry=76396;

replace into spell_script_names values (154294,'spell_gorashan_power_conduit');
replace into spell_script_names values (154435,'spell_lodestone_spike');
replace into spell_script_names values (154345,'spell_electric_pulse');

-- ragewing untamed
update creature_template set scriptname='boss_ragewing_untamed' where entry=76585;

replace into spell_script_names values (155070,'spell_fire_storm');

-- warlord zaela
update creature_template set scriptname='boss_warlord_zaela' where entry=77120;
update creature_template set scriptname='npc_emberscale_ironflight' where entry in (82428,83479);
update creature_template set scriptname='npc_emberscale_matron' where entry=82480;