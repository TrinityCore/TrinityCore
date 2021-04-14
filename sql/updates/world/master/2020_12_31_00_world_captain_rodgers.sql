UPDATE `gossip_menu_option` SET `OptionText`='I am ready to depart.' WHERE (`MenuId`='66292') AND (`OptionIndex`='0');
UPDATE `creature_template` SET `ScriptName`='npc_captain_rodgers_66292' WHERE (`entry`='66292');
DELETE FROM smart_scripts WHERE entryorguid = 66292;
