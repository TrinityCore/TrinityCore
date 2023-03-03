UPDATE `spell_radius` SET `effectradius0`='8', `comments`='5 yards' WHERE (`spell_id`='82691') AND (`effectradius0`='134') AND (`effectradius1`='0') AND (`effectradius2`='0') AND (`effectradius3`='0') AND (`effectradius4`='0') AND (`comments`='6.5 yards');

UPDATE `creature_template` SET `ScriptName`='npc_static_target_for_spell' WHERE (`entry`='43499');
UPDATE `creature_template` SET `ScriptName`='npc_static_target_for_spell' WHERE (`entry`='44199');

UPDATE `spell_trigger` SET `spell_trigger`='63106' WHERE (`spell_id`='56218') AND (`spell_trigger`='-63106') AND (`option`='0') AND (`effectmask`='7') AND (`aura`='0') AND (`check_spell_id`='0');