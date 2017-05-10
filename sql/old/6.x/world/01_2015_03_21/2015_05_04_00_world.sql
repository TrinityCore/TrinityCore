ALTER TABLE `creature` CHANGE `npcflag` `npcflag` bigint(20) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `creature_template` CHANGE `npcflag` `npcflag` bigint(20) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `game_event_npcflag` CHANGE `npcflag` `npcflag` bigint(20) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `gossip_menu_option` CHANGE `npc_option_npcflag` `npc_option_npcflag` bigint(20) unsigned NOT NULL DEFAULT '0';

UPDATE `trinity_string` SET `content_default`='Player selected NPC\nDB GUID: %u, current %s.\nFaction: %u.\nnpcFlags: 0x%llX.\nEntry: %u.\nDisplayID: %u (Native: %u).' WHERE entry=539;
UPDATE `trinity_string` SET `content_default`='%s, faction is %u, flags is 0x%X, npcflag is 0x%llX, dynflag is 0x%X.' WHERE entry=128;
UPDATE `trinity_string` SET `content_default`='You changed %s Faction to %u, flags to 0x%X, npcflag to 0x%llX, dyflag to 0x%X.' WHERE entry=130;
