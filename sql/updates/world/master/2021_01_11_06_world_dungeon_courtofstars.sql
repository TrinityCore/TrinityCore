-- talixae flamewreath
update creature_template set scriptname='boss_talixae_flamewreath' where entry=104217;
update creature_template set scriptname='npc_talixae_guards' where entry in (104273,104274,104275);

-- patrol captain gerdo
update creature_template set scriptname='boss_patrol_captain_gerdo' where entry=104215;
update creature_template set scriptname='npc_captain_gerdo_vigilant_duskwatch' where entry=104918;
update creature_template set scriptname='npc_signal_lantern' where entry=105729;
update creature_template set scriptname='npc_duskwatch_sentry' where entry=104251;
update creature_template set scriptname='npc_gerdo_arcane_beacon' where entry=104245;
update creature_template set scriptname='npc_gerdo_streetsweeper' where entry=110403;

replace into spell_script_names values (207278,'spell_patrol_arcane_lockdown');

-- advisor melandrus
update creature_template set scriptname='boss_advisor_melandrus' where entry=104218;
update creature_template set scriptname='npc_advisor_enveloping_winds' where entry=112687;
update creature_template set scriptname='npc_image_of_advisor_melandrus' where entry=105754;
update creature_template set scriptname='npc_suspicious_noble' where entry=107435;

replace into spell_script_names values (213304,'spell_righteous_indignation');